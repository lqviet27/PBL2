/*

#include<iostream> 
#include<iomanip>
using namespace std;

// void swap_(int &a,int &b){
//     int tmp = a;
//     a=b;
//     b=tmp;
// }

// void show (int x, int y=1, int z=2){
//     cout<<x<<y<<z;
// }

// int& A(){            //! A la dia chi ham(tuy vao trinh bien dich). 
//     int x =2 ;
//     return x;
// }           
int main(){
    // int x;
    // char y;
    // cout<< "input x : ";
    // cin>>x;
    // y=x;
    // cout<<x<<" "<<y<<endl;


    // double z = 12345.24;
    // cout << setiosflags(ios::showpoint) << setprecision(4);
    // cout<<z;

    // int x = 5;
    // cout<< "&x = " << &x << endl;
    // int &y = x;
    // cout << "&x = " << &x << " , &y = " << &y << endl;
    // y++;
    // cout << x << "," << y << endl;

    // int a=5,b=9;
    // swap_(a,b);
    // cout<<a<<" "<<b;

    // int x = 5;
    // const int y = 4;
    // const int &z = y;
    // const int &z = x;
    // cout << x << ", " << z << endl;
    // x = 10;
    // cout << x << ", "<< z << endl; 
    // cout int &z = 3;  //! bi loi 
    // cout << z << endl;


    // Show(); // loi
    // Show(1); //112
    // Show(1,2); //122
    // Show(1,2,3); //123
    // Show(1,,3); // loix

    // cout<<A()<<","<<A()<<endl; //! khi chay thi ham A() dau tien se chay sau do se giai phong khi do cai A() thu 2 se bi loix  

    // cout<<A(); //! 2 lan goi khac nhau nen se chay duoc
    // cout<<A();



    // int x = 10, y = 20;
    // int *p1, *p2;
    // p1 = &x; p2 = &y;
    // cout << "x= "<<x<<endl;
    // cout << "y= "<<y<<endl;
    // cout << "*p1= "<<*p1<<endl;
    // cout << "*p2= "<<*p2<<endl;
    // *p1 = 50; *p2 = 90;
    // cout << "x= "<<x<<endl;
    // cout << "y= "<<y<<endl;
    // cout << "*p1= "<<*p1<<endl;
    // cout << "*p2= "<<*p2<<endl;
    // *p1 = *p2;
    // cout << "x= "<<x<<endl;
    // cout << "y= "<<y<<endl;
    // cout << "*p1= "<<*p1<<endl;
    // cout << "*p2= "<<*p2<<endl;
    // return 0;


    // int x = 2, y = 3;   
    // const int* p = &x;
    // //(*p) = 3;
    // cout<<*p<<endl;
    // p = &y;
    // cout<<*p<<endl;

    // int *const p1 = &x;
    // *p1 = 10;
    // cout<<*p1<<endl;
    // //p1 = &y;



  


}


*/


#include<iostream>
#include<iomanip>
using namespace std;

 const int A()  {
	int x = 4;
	x++;
	return x;
}

int main() {
	int x = A();
	cout << x;
	
 }