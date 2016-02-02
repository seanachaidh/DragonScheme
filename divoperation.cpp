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

#include "divoperation.h"

DivOperation::DivOperation()
{
    //ctor
}

DivOperation::~DivOperation()
{
    //dtor
}

void DivOperation::interpret() {
    vector<SchemeVariant> vals;
    Expression::interpret();
    vals = Expression::GetValues();

    float result = vals[0].val.f;
    //We gaan het niet berekenen als het eerste getal al 0 is
    if(result == 0) {
        SchemeVal tmp;
        tmp.f = 0;
        this->SetValue(tmp, TYPE_FLOAT);
        return;
    }

    for(unsigned int i = 1; i < vals.size(); i++) {
        if(vals[i].val.f == 0) {
            /*
             * Ik weet niet hoe ik dit op een elegante manier zou kunnen afhandelen
             * voorlopig sluit ik de boel gewoon
             */
            cerr << "division by zero is forbidden. You dumb ass" << endl;
            exit(0);
        } else {
            result = result / vals[i].val.f;
        }
    }

    SchemeVal tmpval;
    tmpval.f = result;
    this->SetValue(tmpval, TYPE_FLOAT);

}
