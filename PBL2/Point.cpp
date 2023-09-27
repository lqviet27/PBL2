#include"Point.h"
#include<iostream>
using namespace std;

int Point::cnt = 0;
vector<Point> Point::v;
Point::Point(int x,int y):xVal(x),yVal(y){
    this->v.push_back(*this);
    cnt++;
}

Point::~Point(){

}

void Point::Show(){
    if(this->flags){
        for(int i=0;i<this->cnt;i++){
            cout<<"Point "<<i+1<<": "<<this->v[i].xVal<<" "<<this->v[i].yVal<<endl;
        }
    }else cout<<"ban khong co quyen de truy cap danh sach cac Point"<<endl;
}

void Point::setFlags(bool b){
    this->flags = b;
}