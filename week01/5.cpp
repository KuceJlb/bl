#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
string a=" ";
int d=1;
int e=1;
std::cin >> a;
d=a.size()-1;
for (int i=0; i<=d; ++i)
{
    if (a[i]!=a[d-i])
    {
        e=0;
    }
}
std::cout << e;
return 0;
}