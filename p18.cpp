//
//  p18.cpp
//  
//
//  Created by Ryan Faulkner on 1/6/13.
//  Copyright (c) 2012 R.Faulkner. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

// Methods used to split a string into tokens
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while(std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    return split(s, delim, elems);
}

template<class T>
T** init_2D_array(T val, int dim_x, int dim_y) {
    
    T** a;
    int x,y;
    
    a = new T*[dim_x];
    
    for (x = 0 ; x < dim_x ; x++) {
        a[x] = new T[dim_y];
        for (y = 0 ; y < dim_y ; y++) a[x][y] = val;
    }
    return a;
}

// Reads input which defines the rows
int** readInput(std::string filename, int dim_x, int dim_y) {
    
    std::string line;
    std::ifstream myfile;
    myfile.open (filename.c_str());
    
    int** a;
    int x,y;
    
    // Initialize the new 2D array
    // a = init_2D_array<int>(0,x,y);
    a = new int*[dim_x];    
    for (x = 0 ; x < dim_x ; x++) {
        a[x] = new int[dim_y];
        for (y = 0 ; y < dim_y ; y++) a[x][y] = 0;
    }
    
    std::vector<std::string> tokens;
    int ix, iy = 0;
    
    // Read the file; Tokenize each line and set the array
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            ix = 0;
            getline (myfile,line);
            istringstream iss(line);
            
            std::vector<std::string> tokens = split(line, ' ');
            
            for(vector<string>::iterator it = tokens.begin(); it != tokens.end(); it++) {
                a[ix][iy] = atoi(((string)*it).c_str());
                ix++;
            }            
            iy++;
        }
        myfile.close();
    } else
        cout << "File not found: " << filename << endl;
    myfile.close();
    
    return a;
}

void print(int** a, int num_rows) {
    int x,y;
    for (y = 0; y < num_rows; y++) {
        for (x = 0; x <= y; x++)
            cout << a[x][y] << " ";
        cout << endl;
    }
}

int main() {
    
    int** rows; 
    int** sums;
    int x,y,num_rows = 15;
    std:string filename = "p18.txt";
    
    // initialize sums
    // sums = init_2D_array<int>(0,num_rows,num_rows);
    sums = new int*[num_rows];    
    for (x = 0; x < num_rows ; x++) {
        sums[x] = new int[num_rows];
        for (y = 0 ; y < num_rows ; y++) sums[x][y] = 0;
    }
    
    // Get the rows from file
    rows = readInput(filename, num_rows, num_rows);
    
    sums[0][0] = rows[0][0];
    for (y = 1; y < num_rows; y++) {        
        for (x = 0; x <= y; x++) {
            // Take the maximum at each step
            if (x == 0)                
                sums[0][y] = sums[0][y-1] + rows[0][y];
            else if (x == y)
                sums[x][x] = sums[x-1][y-1] + rows[x][x];
            else
                sums[x][y] = std::max(sums[x-1][y-1] + rows[x][y], sums[x][y-1] + rows[x][y]);               
        }        
    }
    
    cout << endl << "Row values:" << endl;
    print(rows, num_rows);
    
    cout << endl << "Sums:" << endl;
    print(sums, num_rows);
    
    return 0;
}