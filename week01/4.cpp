#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
int a=0;
int b=0;
int c=1;
cin >> a >> b;
if (a<b)
{
    c=a; a=b; b=c;
}
while (c)
{
    c=a%b;
    a=b;
    b=c;
}
cout << a;
}