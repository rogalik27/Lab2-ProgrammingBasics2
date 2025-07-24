#include <cmath>
#include <iostream>

using namespace std;

struct Point{
    Point(double x, double y, double z) : x(x), y(y), z(z) {}
    double x, y, z;
};

double getDistance(Point &a, Point &b) {
    return sqrt(pow(b.x-a.x,2)+pow(b.y-a.y,2)+pow(b.z-a.z,2));
}

int main() {
    Point a(0,0,0), b(1,5,3);
    
    cout << "Distance between points is: " << getDistance(a, b) << "\n";

    return 0;
}
