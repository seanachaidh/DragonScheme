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

#include "sequentialbuffer.h"

SequentialBuffer::SequentialBuffer(string initial)
{
  char* tmp = new char[initial.length()];
  strcpy(tmp, initial.c_str());
  this->buffer = tmp;
  this->length = initial.length();
  this->current = 0;
}

SequentialBuffer::~SequentialBuffer()
{

}

bool SequentialBuffer::End()
{
  return current == (length - 1);
}

int SequentialBuffer::GetCurrent()
{
  return this->current;
}

int SequentialBuffer::GetLength()
{
  return this->length;
}

char SequentialBuffer::Peek()
{
  return buffer[current];
}

char SequentialBuffer::Next()
{
  if(!this->End()) {
    char tmp = buffer[current];
    current++;
    return tmp;
  } else {
    char tmp = buffer[current];
    return tmp;
  }
}
