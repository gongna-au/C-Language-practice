
//定义Point类和Line类，
//其中Line类是Point类的友元类，
//两个Point对象，分别表示起点和终点，根据程序框架补充必要的函数，并实现Line的len函数，计算线段的长度
#include <iostream>
#include<cmath>
using namespace std;

class Point {

    private:
        int x;
        int y;
    public:
        Point();
        Point(int a,int b);
    friend class Line;  

};
Point::Point(){
    x=0;
    y=0;
}
Point::Point(int a,int b){
    x=a;
    y=b;
}


class Line {
    private:
        Point sp;   // start point
        Point ep;   // end point

    public:
        Line(Point point1,Point point2);

        double len() const;  // 计算线段长度
};
Line::Line(Point point1,Point point2){
    sp=point1;
    ep=point2;
}
double Line::len()const{
    int temp1=abs(sp.x-ep.x);
    int temp2=abs(sp.y-ep.y);
    int temp3=temp1*temp1+temp2*temp2;
    double result= sqrt(temp3);

    return result;
}



int main() {
    Point p1(1, 1), p2(5, 6);
    Line li(p1, p2);
    cout << "Line len = " << li.len() << endl;
}