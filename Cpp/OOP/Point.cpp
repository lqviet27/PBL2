#include<iostream>
#include"Point.h"
using namespace std;

void Point::TT(int n){
    xVal+=n;
    yVal+=n;
}
void Point::Show(){
    cout<<"x: "<<xVal<<" "<<"y: "<<yVal<<endl;  
}