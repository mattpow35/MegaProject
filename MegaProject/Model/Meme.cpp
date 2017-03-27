//
//  Meme.cpp
//  MegaProject
//
//  Created by Powley, Matthew on 3/13/17.
//  Copyright © 2017 Powley, Matthew. All rights reserved.
//

#include "Meme.hpp"

Meme :: Meme()
{
    this->title = "Booooring";
    this->dankness = 0;
    this->hipsterQuotient = -.9999;
    this->isMainstream = true;
}

Meme :: Meme(string title)
{
    this->title = title;
    this->dankness = title.length();
    this->hipsterQuotient = 3.14;
    this->isMainstream = true;
}

string Meme :: getTitle()
{
    return title;
}

int Meme :: getDankness()
{
    return dankness;
}

double Meme :: getHipsterQuotient()
{
    return hipsterQuotient;
}

bool Meme :: getIsMainstream()
{
    return isMainstream;
}

void Meme :: setDankness(int dank)
{
    this->dankness = dank;
}

void Meme :: setTitle(string title)
{
    this->title = title;
}

void Meme :: setHipsterQuotient(double quotient)
{
    this->hipsterQuotient = quotient;
}

void Meme :: setMainstream(bool isMain)
{
    this->isMainstream = isMain;
}
