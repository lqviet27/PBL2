
class Point{
    private:

    public:
        int xVal;
        int yVal;
    public:
        Point(int x,int y){
            this->xVal=x;
            this->yVal=y;
        }
        void TT(int);
        void Show();
};







































/*
! đa năng hóa hàm -> nạp chồng phương thức 
 ! void B(int *x) (1)
 ! void B(int &x) (2)
 ! void B(int x)  (3)
 ? trong 3 hàm trên thì cặp hàm nào là đa năng hóa hàm 
 * 1 vs 3 
 * 2 vs 3
*/