//
//  main.cpp
//  assignment4
//
//  Created by 张嘉艺 on 2020/11/30.
//

#include <iostream>
#include "matrix.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    float *d1, *d2;
    d1=new float[6];
    d2=new float[6];
    d1[0]=1;
    d1[1]=2;
    d1[2]=3;
    d1[3]=4;
    d1[4]=5;
    d1[5]=6;
    d2[0]=1;
    d2[1]=2;
    d2[2]=3;
    d2[3]=4;
    d2[4]=5;
    d2[5]=6;
    Matrix m1(3, 2, d1);
    Matrix m2(2, 3, d1);
    Matrix m3(m1);
    Matrix m4=m1;
    Matrix r1=m1*m2;
    vector<float>v;
    v.push_back(1);
    v.push_back(2);
    vector<float>r2=m1*v;
    vector<float>r3=v*m2;
    cout<<m1<<endl;
    cout<<endl;
    cout<<m2<<endl;
    cout<<endl;
    cout<<m3<<endl;
    cout<<endl;
    cout<<m4<<endl;
    cout<<endl;
    cout<<r1<<endl;
    cout<<endl;
    for(int i=0; i<r2.size(); i++){
        cout<<r2[i]<<"\t"<<endl;
    }
                                    
    cout<<endl;
    cout<<endl;
    for(int i=0; i<r3.size(); i++){
        cout<<r3[i]<<"\t"<<endl;
    }
    cout<<endl;
    
    return 0;
}
