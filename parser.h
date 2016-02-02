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

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <cstring>
#include <istream>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <sstream>

//mijn eigen buffer
#include "sequentialbuffer.h"

//verschillende soorten expressies
#include "plusoperation.h"
#include "literalnumber.h"
#include "minoperation.h"
#include "multoperation.h"
#include "divoperation.h"


using namespace std;
class Parser
{
private:
  char lookAhead;
  string sourceFile;
  SequentialBuffer* buffer;
  bool fromFile;
  void init();

public:
  bool getChar();

  void SetInputFromString(string input);
  void SetInputFromFile(string filename);

  bool IsFromFile();
  string GetSourceFile();

  //errorreports
  void Expected(string s);
  void Error(string s);

  //Get stuff
  char GetName();
  char GetNum();

  Expression* ParseExpression();
  Expression* parseDefine();
  Expression* parseProcedure(string name);

  //builtins
  Expression* parseAdd();
  Expression* parseMin();
  Expression* parseMult();
  Expression* parseDiv();
  Expression* parseNumber();

  void Emit();

  Parser();
  ~Parser();

};

#endif // PARSER_H
