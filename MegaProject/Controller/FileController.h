//
//  FileController.h
//  MegaProject
//
//  Created by Powley, Matthew on 3/29/17.
//  Copyright © 2017 Powley, Matthew. All rights reserved.
//

#ifndef FileController_h
#define FileController_h

#include "../Model/DoubleList.hpp"
#include "../Model/Meme.hpp"
//#include "../Model/CrimeData.hpp"
#include <string> // String Type
#include <fstream> //File operations
#include <iostream> //console access
#include <sstream> //String as Stream

using namespace std;

class FileController
{
private:
    DoubleList<Meme> memeList;
public:
    DoubleList<Meme> readMemeDataFromFileAsList(string filename);
    void writeMemeDataStatistics(DoubleList<int> source, string filename);
    
};

#endif /* FileController_h */
