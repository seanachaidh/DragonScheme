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

#ifndef SEQUENTIALBUFFER_H
#define SEQUENTIALBUFFER_H

#include <cstring>
#include <string>

using namespace std;
class SequentialBuffer
{
private:
  char* buffer;
  int current;
  int length;
public:
  SequentialBuffer(string initial);
  ~SequentialBuffer();

  bool End();
  int GetCurrent();
  int GetLength();

  char Next();
  char Peek();

};

#endif // SEQUENTIALBUFFER_H
