//
//  matrix.hpp
//  assignment4
//
//  Created by 张嘉艺 on 2020/11/30.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Matrix{
private:
    int rows;
    int columns;
    float * data;
    
public:
    Matrix(const int r=0, const int c=0, const float * d=0);
    Matrix(const Matrix &m);
    ~Matrix();
    Matrix &operator=(const Matrix &m);
    Matrix operator*(const Matrix& other) const;
    vector<float>operator*(const vector<float>v) const;
    friend ostream & operator<<(ostream &os, const Matrix &other);
    friend vector<float>operator*(vector<float>v, const Matrix& other);
};

#endif /* matrix_hpp */
