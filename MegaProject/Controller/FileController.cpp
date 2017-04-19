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

void FileController :: writeMemeDataStatistics(DoubleList<Meme> dataSource, string filename)
{
    ofstream saveFile(filename);
    
    if(saveFile.is_open())
    {
        saveFile << "These are the contents of the list" << endl;
        for(int index = 0; index < dataSource.getSize(); index ++)
        {
            saveFile << "Meme Title: " << dataSource.getFromIndex(index).getTitle() << endl;
        }
    }
    else
    {
        cerr << "File unavailable" << endl;
    }
    saveFile.close();
    
}

BinarySearchTree<CrimeData> FileController :: readCrimeDataToBinarySearchTree(string filename)
{
    
    BinarySearchTree<CrimeData> crimeData;
    
    
    string currentCSVLine;
    
    int rowCount = 0;
    
    ifstream dataFile(filename);
    
    if(dataFile.is_open())
    {
        while(!dataFile.eof())
        {
            
            getline(dataFile, currentCSVLine, '\r');
            
            
            
            //Exclude first row headers
            if (rowCount != 0)
            {
                
                CrimeData rowData(currentCSVLine);
                
                crimeData.insert(rowData);
                
            }
            rowCount++;
        }
        dataFile.close();
    }
    
    else
    {
        cerr << "NO FILE" << endl;
    }
    return crimeData;
    
}

//AVLTree<CrimeData> FileController :: readCrimeDataToAVLTree(string filename)
//{
//    
//    AVLTree<CrimeData> crimeData;
//    
//    
//    string currentCSVLine;
//    
//    int rowCount = 0;
//    
//    ifstream dataFile(filename);
//    
//
//    if(dataFile.is_open())
//    {
//        while(!dataFile.eof())
//        {
//            
//            getline(dataFile, currentCSVLine, '\r');
//            
//            
//            //Exclude first row headers
//            
//            if (rowCount != 0)
//            {
//                
//                CrimeData rowData(currentCSVLine);
//                
//                crimeData.insert(rowData);
//                
//            }
//            rowCount++;
//        }
//        dataFile.close();
//    }
//    else
//    {
//        cerr << "NO FILE" << endl;
//    }
//    
//    return crimeData;
//    
//}






