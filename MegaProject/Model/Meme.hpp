//
//  Meme.hpp
//  MegaProject
//
//  Created by Powley, Matthew on 3/13/17.
//  Copyright © 2017 Powley, Matthew. All rights reserved.
//

#ifndef Meme_hpp
#define Meme_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Meme
{
private:
    string title;
    int dankness;
    double hipsterQuotient;
    bool isMainstream;
public:
    Meme();
    Meme(string title);
    int getDankness();
    double getHipsterQuotient();
    bool getIsMainstream();
    string getTitle();
    void setTitle(string title);
    void setDankness(int dank);
    void setHipsterQuotient(double hipsterQuotient);
    void setMainstream(bool isMainstream);
};
#endif /* Meme_hpp */
