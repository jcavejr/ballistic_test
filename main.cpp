// this program is a simple simulation of a cannon ball

#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;

// x = x0 + v0*t + .5*a*t*t
double ComputePosition(double x0, double v0, double a, double t) {
    return x0 + v0*t + 0.5*a*t*t;
}

int main(void) {
    double x0 = 0.0;
    double y0 = 0.0;

    double speed = 0.0;
    cout << "Enter a speed:" << endl;
    cin >> speed;

    double theta = 0.0;
    cout << "Enter a launch angle (degrees):" << endl;
    cin >> theta;

    double pi = 4.0 * atan(1.0);

    double vx0 = speed * cos(theta*pi/180);
    double vy0 = speed * sin(theta*pi/180);

    double ax = 0;
    double ay = -9.81;

    double time = 0;
    double dt = 0.25;
    
    ofstream dab_file("trajectory.dab");
    //while (y >= 0 || time == 0) {
    while (time < 10.0) {
        double x = ComputePosition(x0, vx0, ax, time);
        double y = ComputePosition(y0, vy0, ay, time);
        dab_file << time << " " << x << " " << y << endl;
        time += dt;
    }
    return 0;
}
