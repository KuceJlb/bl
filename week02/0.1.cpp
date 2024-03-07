#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;
int sum_ab(int a, int b) {
    return a + b;
}

double sum_ab(double a, double b) {
    return a + b;
}

void print(int a) {
    cout << "You put number " << a << endl;
}

int main()
{
     int x = 1; 
     int y = 0;
     cin >> x >> y;
     cout << sum_ab(x, y) << endl;
     print(sum_ab(x, y));
     return 0;
}