#ifndef MAP_H
#define MAP_H

#include<iostream>
#include<cmath>
#include<ctime>
using std::cout;
using std::endl;

class Map {
    private:
        int m_rows;
        int m_cols;
        char** m_data; 
    
    public:
        Map(){
            m_rows = 10;
            m_cols = 10;
            buildMatrix();
        }
        Map(int rows, int cols){ //Setting rows and cols, then building matrix
            m_rows = rows;
            m_cols = cols;
            buildMatrix();
        }

        ~Map(){ //Manually calls delete matrix to avoid leaks
            deleteMatrix();
        }

        void buildMatrix(); //Creates a 2d matrix with rows rows, and cols cols
        void deleteMatrix(); //Deletes matrix to prevent leaks
        void fillMatrix(); //Temp to test the thing
        void printMatrix(); //Prints out the matrix

        //Terrain Generation
        void placeMountains();

        int getRows(){return m_rows;}
        int getCols(){return m_cols;}

};

#include "map.hpp"

#endif