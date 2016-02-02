/*
 * DragonScheme. Believe in dragons
 * Copyright (C) 2016  Pieter Van Keymeulen (Seanachaidh) pvankeymeulen@seanachaidh.be
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "parser.h"

Parser::Parser()
{
  this->buffer = new SequentialBuffer("");
  this->fromFile = false;
  this->init();
}

Parser::~Parser()
{
  delete buffer;
}

void Parser::init()
{
  char retval = buffer->Next();
  lookAhead = retval;
}


void Parser::SetInputFromFile(string filename)
{
  /*
  ifstream f(filename.c_str());
  f.seekg(0, ios::end);
  int length = f.tellg();
  f.seekg(0, ios::begin);
  char* buffer = new char[length];

  f.read(buffer, length);

  this->buffer = buffer;
  this->fromFile = true;
  this->getChar();
  */
  //not yet implementend
}

void Parser::SetInputFromString(string input)
{
  this->fromFile = false;
  SequentialBuffer* buff = new SequentialBuffer(input);
  this->buffer = buff;
  this->getChar();
}

bool Parser::IsFromFile() {
  return fromFile;
}

string Parser::GetSourceFile()
{
  return sourceFile;
}


bool Parser::getChar()
{
  lookAhead = buffer->Next();
  if(lookAhead < 0){
    return false;
  } else {
    return true;
  }
}

void Parser::Error(string s)
{
  cerr << "Error: " << s << endl;
}

void Parser::Expected(string s)
{
  cerr << "Expected; " << s << endl;
}

char Parser::GetName()
{
  //wordt deze error wel goed afgehandeld?
  if(!isalpha(lookAhead)) {
    Expected("A character");
  }
  char tmp = this->lookAhead;
  getChar();
  return tmp;
}

char Parser::GetNum()
{
  if(!isdigit(lookAhead)) {
    Expected("A integer");
  }
  char tmp = this->lookAhead;
  getChar();
  return tmp;
}

void Parser::Emit()
{
  //deze functie is voorlopig nog niet gemaakt. Misschien dat dit expressieobjecten gaat
  //teruggeven

  cerr << "not yet implemented" << endl;

}

Expression* Parser::ParseExpression()
{
  string tmp = "";
  Expression* retval;

  if(lookAhead != '(') {
    Expected("Expected (");
    return NULL;
  }
  this->getChar();
  while(lookAhead != ' ') {
    tmp.append(&lookAhead);
    this->getChar();
  }

  if(tmp == "define") {
    retval = parseDefine();
  } else if (tmp  == "+") {
    retval = parseAdd();
  } else if (tmp == "-") {
    retval = parseMin();
  } else if (tmp == "*") {
    retval = parseMult();
  } else if(tmp == "/") {
    retval = parseDiv();
  } else {
    retval = parseProcedure(tmp);
  }
  //TODO Hier ben ik niet zo zeker van.
  this->getChar();
  return retval;
}

Expression* Parser::parseDefine()
{
  //not yet implemented
  return NULL;
}

Expression* Parser::parseAdd()
{
  PlusOperation* retval = new PlusOperation();
  //vorige karakter was een spatie
  //this->getChar();

  //as long as we are not at the end of the expression
  while(lookAhead != ')') {
    this->getChar();
    if(isdigit(lookAhead)) {
      retval->AddExpression(parseNumber());
    } else if(lookAhead == '(') {
      retval->AddExpression(ParseExpression());
    } else {
      Expected("number or expression");
    }
  }
  return retval;
}

Expression* Parser::parseMin()
{
  MinOperation* retval = new MinOperation();
  //vorige karakter was een spatie
  //this->getChar();

  //as long as we are not at the end of the expression
  while(lookAhead != ')') {
    this->getChar();
    if(isdigit(lookAhead)) {
      retval->AddExpression(parseNumber());
    } else if(lookAhead == '(') {
      retval->AddExpression(ParseExpression());
    } else {
      Expected("Number or expression");
    }
    //this->getChar();
  }
  return retval;
}

Expression* Parser::parseMult() {
    MultOperation* retval = new MultOperation();
    //Het vorige karakter was een spatie
    while(lookAhead != ')') {
        this->getChar();
        if(isdigit(lookAhead)){
            retval->AddExpression(parseNumber());
        } else if (lookAhead == '(') {
            retval->AddExpression(ParseExpression());
        } else {
            Expected("Number of expression");
        }
    }
    return retval;
}

Expression* Parser::parseDiv() {
    DivOperation* retval = new DivOperation();
    //Het vorige karakter was een spatie
    while(lookAhead != ')') {
        this->getChar();
        if(isdigit(lookAhead)) {
            retval->AddExpression(parseNumber());
        } else if(lookAhead == '(') {
            retval ->AddExpression(ParseExpression());
        } else {
            Expected("Number or expression");
        }
    }
    return retval;
}

Expression* Parser::parseProcedure(string name)
{
  this->Error("Not yet implemented");
  return NULL;
}

Expression* Parser::parseNumber()
{
  //vorige karakter was een nummer
  string strnum = "";

  //then check until end of number or end of expression
  while(lookAhead != ' ' && lookAhead != ')') {
    strnum.append(&lookAhead);
    this->getChar();
  }

  float tmp = atof(strnum.c_str());
  LiteralNumber* tmpnum = new LiteralNumber(tmp);
  return tmpnum;
}
