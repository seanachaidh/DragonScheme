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

#include "expression.h"

Expression::Expression()
{
}

Expression::~Expression()
{

}

void Expression::interpret()
{
  for(unsigned int i = 0; i < children.size(); i++) {
    children[i]->interpret();
  }
}

void Expression::AddExpression(Expression* expr)
{
  children.push_back(expr);
}

void Expression::RemoveValue()
{
  this->evaluated = false;
}

void Expression::SetValue(SchemeVal newval, ValType valtype)
{
  this->evaluated = true;
  SchemeVariant var;
  var.stype = valtype;
  var.val = newval;
  this->val = var;
}

bool Expression::GetBooleanValue()
{
  bool retval;
  if(!evaluated) {
    retval = false;
  } else {
    retval = this->val.val.b;
  }
  return retval;
}

char Expression::GetCharValue()
{
  char retval;
  if(!evaluated) {
    retval = 0;
  } else {
    retval = val.val.c;
  }
  return retval;
}

float Expression::GetFloatValue()
{
  float retval;
  if(!evaluated) {
    retval = 0;
  } else {
    retval = val.val.f;
  }
  return retval;
}

vector< SchemeVariant > Expression::GetValues()
{
  vector<SchemeVariant> retval;
  for(unsigned int i = 0; i < children.size(); i++) {
    if(children[i]->evaluated) {
      retval.push_back(children[i]->val);
    }
  }
    return retval;
}

SchemeVariant Expression::GetValue() {
  return val;
}

string Expression::ValueToString()
{
  stringstream retval;
  switch(val.stype) {
    case TYPE_BOOL:
      retval << val.val.b;
      break;
    case TYPE_CHAR:
      retval << val.val.c;
      break;
    case TYPE_FLOAT:
      retval << val.val.f;
      break;
    default:
      retval << "this is impossible";
  }
  return retval.str();
}
