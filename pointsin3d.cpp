#include <cmath>
#include <iostream>

using namespace std;

struct Point{
    double x, y, z;
};

double getDistance(Point a, Point b) {
double getDistance(Point &a, Point &b) {
    return sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2)+pow(b.z-a.z,2));
}

int main(){
    Point a, b;

    a.x = 0;
    a.y = 0;
    a.z = 0;

    b.x = 1;
    b.y = 5;
    b.z = 0;

    cout << "oa" << &a << endl;
    cout << "ob" << &b << endl;
    
    cout << "Distance between points is: " << getDistance(a, b) << "\n";

    return 0;
}
