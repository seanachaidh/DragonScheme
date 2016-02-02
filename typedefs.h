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

/*
 * een bestand met standaard typedefs
 * Ik denk dat er een betere manier bestaat om dit te maken
 */

typedef enum t_valtype {
  TYPE_CHAR,
  TYPE_BOOL,
  TYPE_FLOAT
} ValType;

typedef union variant_t {
  char c;
  bool b;
  float f;
} SchemeVal;

typedef struct schemeval_t {
  SchemeVal val;
  ValType stype;
} SchemeVariant;
