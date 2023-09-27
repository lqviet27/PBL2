#include<vector>
using namespace std;
class Point{
    private:
        int xVal;
        int yVal;
        static vector<Point> v;
        static int cnt ;
        bool flags = false;
    public:
        Point(int,int);
        ~Point();
        // void addPoint(const Point&);
        // void Show_point();
        void Show();
        void setFlags(bool);




};