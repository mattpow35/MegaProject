//
//  FileController.hpp
//  MegaProject
//
//  Created by Powley, Matthew on 3/29/17.
//  Copyright © 2017 Powley, Matthew. All rights reserved.
//

#ifndef FileController_hpp
#define FileController_hpp

#include "DoubleList.hpp"
#include "Meme.hpp"
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
    void writeMemeDataStatistics(DoubleList<Meme> source, string filename);
    
};

#endif /* FileController_hpp */
