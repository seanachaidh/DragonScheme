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

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <iostream>
#include <vector>
#include <sstream>

#include "typedefs.h"
#include "interpretable.h"

using namespace std;
class Expression : public Interpretable
{
private:
  vector<Expression*> children;
  SchemeVariant val;
protected:
  bool evaluated;
public:
Expression();
~Expression();

void AddExpression(Expression* expr);
void SetValue(SchemeVal newval, ValType valtype);
void RemoveValue();

bool GetBooleanValue();
float GetFloatValue();
char GetCharValue();
SchemeVariant GetValue();
string ValueToString();

vector<SchemeVariant> GetValues();

virtual void interpret();
};

#endif // EXPRESSION_H
