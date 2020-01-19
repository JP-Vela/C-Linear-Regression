#include<iostream>
#include <array>
using namespace std;

double multipliedXX[8];
double multipliedXY[8];

double mean(double arr[]) {
    double mean = 0;
    double sum = 0;
    double length = 0;
    for(int  i = 0; i<(int)sizeof(arr[0]); i++){
        sum+=arr[i];

        length = i;
    }

    mean = sum/=(length+1);
    //cout<<mean;
    return mean;
}

void arrMultiplyXX(double x[], double y[]) {
    double newArray[sizeof(x[0])];

    for(int i = 0; i<(int)sizeof(x[0]); i++) {
        newArray[i]=x[i]*x[i];
        multipliedXX[i] = newArray[i];
    }
}

void arrMultiplyXY(double x[], double y[]) {
    double newArray[sizeof(x[0])];

    for(int i = 0; i<(int)sizeof(x[0]); i++) {
        newArray[i]=x[i]*y[i];
        multipliedXY[i] = newArray[i];
    }
}


double bestSlope(double x[], double  y[]) {
  double slope;
 //double xMean = mean(x);
  arrMultiplyXX(x,y);
  arrMultiplyXY(x,y);

  slope = ( ((mean(x) * mean(y)) - mean(multipliedXY))
                / ((mean(x)*mean(x)) - mean(multipliedXX)));
  //cout<<( (mean(x) * mean(y)) - mean(multipliedXY));
  return slope;
}

double bestYInt(double x[], double y[], double m) {
    double b;
    b = mean(y)-(m*mean(x));

    return b;
}

int  main() {
    double xPoints[] = {1,2,3,4,5,6,7,8};
    double yPoints[] = {1,2,5,7,6,8,10,9};
    double slope = 0;
    double yInt  = 0;

    slope = bestSlope(xPoints, yPoints);
    yInt = bestYInt(xPoints, yPoints, slope);

    cout << slope;
    cout <<"\n";
    cout << yInt;
    cout <<"\n";

}