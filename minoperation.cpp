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

#include "minoperation.h"
MinOperation::MinOperation()
{

}

MinOperation::~MinOperation()
{

}

void MinOperation::interpret()
{
  vector<SchemeVariant> vals;
  Expression::interpret();
  vals = Expression::GetValues();

  float result = vals[0].val.f;
  for(unsigned int i = 1; i < vals.size(); i++) {
    result -= vals[i].val.f;
  }
  SchemeVal tmp;
  tmp.f = result;
  this->SetValue(tmp, TYPE_FLOAT);
}
