//
//  matrix.cpp
//  assignment4
//
//  Created by 张嘉艺 on 2020/11/30.
//

#include "matrix.hpp"

Matrix::Matrix(const int r, const int c, const float *d){
    rows=r;
    columns=c;
    if(r&&c&&d){
        data=new float[r*c];
        for(int i=0; i<r*c; i++){
            data[i]=d[i];
        }
    }
}

Matrix::Matrix(const Matrix &m){
    rows=m.rows;
    columns=m.columns;
    data=new float[rows*columns];
    for(int i=0; i<rows*columns; i++){
        data[i]=m.data[i];
    }
}

Matrix::~Matrix(){
    delete [] data;
}

Matrix & Matrix::operator=(const Matrix &m){
    if(this==&m){
        return *this;
    }
    delete [] data;
    rows=m.rows;
    columns=m.columns;
    data=new float[rows*columns];
    for(int i=0; i<rows*columns; i++){
        data[i]=m.data[i];
    }
    return *this;
}

Matrix Matrix::operator*(const Matrix & other) const{
    float * d;
    d=new float[rows*other.columns];
    for(int i=0; i<rows; i++){
        for(int j=0; j<other.columns; j++){
            d[i*rows+j]=0;
            for(int k=0; k<columns; k++){
                
                d[i*other.columns+j]+=data[i*columns+k]*other.data[k*other.columns+j];
            }
        }
    }
    return Matrix(rows, other.columns, d);
}

vector<float>Matrix::operator*(const vector<float>v) const{
    vector<float>result;
    for(int i=0; i<rows; i++){
        float r=0;
        for(int j=0; j<columns; j++){
            r+=data[i*columns+j]*v[j];
        }
        result.push_back(r);
    }
    return result;
}

vector<float>operator*(vector<float>v, const Matrix & other){
    vector<float>result;
    for(int i=0; i<other.columns; i++){
        result.push_back(0);
        for(int j=0; j<other.rows; j++){
            result[i]+=v[j]*other.data[j*other.columns+i];
        }
    }
    return result;
}

ostream & operator<<(ostream &os, const Matrix &other){
    for(int i=0; i<other.rows; i++){
        for(int j=0; j<other.columns; j++){
            os<<other.data[i*other.columns+j]<<" ";
        }
        os<<endl;
    }
    return os;
}
