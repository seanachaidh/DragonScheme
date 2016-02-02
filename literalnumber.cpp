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

#include "literalnumber.h"

LiteralNumber::LiteralNumber(float num)
{
  SchemeVal val;
  val.f = num;

  this->SetValue(val, TYPE_FLOAT);
  //A literal is always evaluated
  this->evaluated = true;
}

float LiteralNumber::GetNumber(void)
{
  float tmp = this->GetFloatValue();
  return tmp;
}

void LiteralNumber::SetNumber(float num)
{
  SchemeVal val;
  val.f = num;
  this->SetValue(val, TYPE_FLOAT);
  this->evaluated = true;
}
