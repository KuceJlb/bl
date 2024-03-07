#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
int a=0;
int a_=1;
std::cin >> a;
while (a)
{
a_ *= a;
--a;
}
std::cout << a_;
}