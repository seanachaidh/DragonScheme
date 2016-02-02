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

#include <iostream>
#include <string>
#include "parser.h"
#include "expression.h"

using namespace std;

int main(int argc, char **argv) {
  string toparse;
  //TODO ervoor zorgen dat ik hier geen lege string moet gebruiken

  cout << "Welkom bij mijn eigen scheme interpeter" << endl;
  cout << "Deze interpreter is een klein experiment van me en voorlopig nog onvolledig" << endl;
  cout << "Er ontbreken nog een heleboel features die ik er in de toekomst nog aan ga toevoegen" << endl;
  cout << "Veel plezier ermee, Seanachaidh" << endl;

  Parser * parser = new Parser();
  for(;;) {
    cout << ">> ";
    getline(cin, toparse);
    if(toparse == "exit")
      exit(0);
    parser->SetInputFromString(toparse);
    Expression* expr = parser->ParseExpression();
    expr->interpret();
    string tmpval = expr->ValueToString();
    cout << tmpval << endl;
  }
  return 0;
}
