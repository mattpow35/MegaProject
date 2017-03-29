//
//  FileController.cpp
//  MegaProject
//
//  Created by Powley, Matthew on 3/29/17.
//  Copyright © 2017 Powley, Matthew. All rights reserved.
//

#include "FileController.hpp"

DoubleList<Meme> FileController :: readMemeDataFromFileAsList(string filename)
{
    DoubleList<Meme> dataSource;
    string currentCSVLine;
    int rowCount = 0;
    
    ifstream dataFile(filename);
    
    if(dataFile.is_open())
    {
        while(!dataFile.eof())
        {
            getline(dataFile, currentCSVLine, '\r');
            stringstream parseCSV(currentCSVLine);
            
            string title, tempHipster, tempDank, tempMainstream;
            //Matching data types for structure
            double quotient;
            int dankness;
            bool isCommon;
            
            //Each part as a string in order of the CSV - then convert after using stod, stoi
            getline(parseCSV, title, ',');
            getline(parseCSV, tempHipster, ',');
            getline(parseCSV, tempDank, ',');
            getline(parseCSV, tempMainstream, ',');
            
            
            //Exclude first row headers
            if (rowCount != 0)
            {
                quotient = stod(tempHipster);
                dankness = stoi(tempDank);
                isCommon = stoi(tempMainstream);
                
                Meme temp(title);
                temp.setHipsterQuotient(quotient);
                temp.setDankness(dankness);
                temp.setMainstream(isCommon);
                
                dataSource.add(temp);
            }
            rowCount ++;
            //Remove this line!
            cout << currentCSVLine << endl;
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE" << endl;
    }
    
    return dataSource;
}

void FileController :: writeMemeDataStatistics(DoubleList<int> dataSource, string filename)
{
    
}
