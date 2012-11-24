//
//  p11.cpp
//
//  http://projecteuler.net/problem=11
//
//  Created by Ryan Faulkner on 11/19/12.
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

enum e_cardinality {
    diagonal_right = 0,
    diagonal_left = 1,
    horizontal = 2,
    vertical = 3
    };

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

class ArrayReader {

public:
    ArrayReader(int x, int y) { 
        this->dim_x = x; 
        this->dim_y = y; 
        a = new int*[x];
        for (int i = 0 ; i < x ; i++)
            a[i] = new int[y];
    }

    // Reads input which defines the grid
    void readInput(std::string filename) {
     
        std::string line;
        std::ifstream myfile;
        myfile.open (filename.c_str());
        
        std::vector<std::string> tokens;
        int ix, iy = 0;
        
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
    }
    
    // Computes the sum of a path of length `l` originating at (x,y) in direction 'c'
    int compute_path_sum(int x, int y, e_cardinality c, int l){
        
        int prod = 1;
        
        if (c == diagonal_right)
            if (x + l <= this->dim_x && y + l <= this->dim_y)
                for (int i = 0; i < l; i++) 
                    prod *= a[x+i][y+i];
        else if (c == diagonal_left)
            if (x - l + 1 >= 0 && y + l <= this->dim_y)
                for (int i = 0; i < l; i++)
                    prod *= a[x-i][y+i];
        else if (c == horizontal)
            if (x + l <= this->dim_x)
                for (int i = 0; i < l; i++)
                    prod *= a[x+i][y];
        else if (c == vertical)
            if (y + l <= this->dim_y)
                for (int i = 0; i < l; i++)
                    prod *= a[x][y+i];
        
        return prod;
    }
    
    // Gets the largest path in the grid of O(n^2) length l
    void get_largest_path_sum(int l) {
        
        int i=0,j=0,i_max,j_max,max = 0;
        e_cardinality dir_max;
        
        for (; i < this->dim_x; i++)
            for (j = 0; j < this->dim_y; j++) {
                // cout << i << " " << j << endl;
                if (compute_path_sum(i,j,diagonal_right,l) > max) {
                    max = compute_path_sum(i,j,diagonal_right,l); i_max = i; j_max = j; dir_max = diagonal_right; }
                if (compute_path_sum(i,j,diagonal_left,l) > max) {
                    max = compute_path_sum(i,j,diagonal_left,l); i_max = i; j_max = j; dir_max = diagonal_left; }
                if (compute_path_sum(i,j,horizontal,l) > max) {
                    max = compute_path_sum(i,j,horizontal,l); i_max = i; j_max = j; dir_max = horizontal; }
                if (compute_path_sum(i,j,vertical,l) > max) {
                    max = compute_path_sum(i,j,vertical,l); i_max = i; j_max = j; dir_max = vertical; }
                // cout << endl;
            }
        
        cout << "max coords: (" << i_max << " , " << j_max << ")" << endl;
        cout << "max prod: " << max << endl;
        this->print_path(i_max, j_max, dir_max, l);

    }
    
    // Prints sequentially the values in the max product path
    void print_path(int x, int y, e_cardinality c, int l) {
        if (c == diagonal_right)
            for (int i=0; i < l; i++)
                cout << a[x + i][y + i] << " ";
        else if (c == diagonal_left)
            for (int i=0; i < l; i++)
                cout << a[x - i][y+ i] << " ";
        else if (c == vertical)
            for (int i=0; i < l; i++)
                cout << a[x][y + i] << " ";
        else if (c == horizontal)
            for (int i=0; i < l; i++)
                cout << a[x + i][y] << " ";
        
        this->print_direction(c);
        cout << endl;
    }
    
    // Outputs direction
    void print_direction(e_cardinality d) {
        switch (d) {
            case diagonal_left:
                cout << "diagonal-left";
                break;
                
            case diagonal_right:
                cout << "diagonal-right";
                break;
                
            case horizontal:
                cout << "horizontal";
                break;
                
            case vertical:
                cout << "vertical";
                break;
                
            default:
                break;
        }
    }
    
private:
    int dim_x;
    int dim_y;
    int** a;
};

int main() {
    
    ArrayReader* ar = new ArrayReader(20,20);
    ar->readInput("/Users/rfaulkner/projects/project_euler/p11.txt");
    ar->get_largest_path_sum(4);
    
    return 0;
}

