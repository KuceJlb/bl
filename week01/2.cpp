
#include <iostream>
#include <cstdio>
#include <math.h>

using namespace std;

int main()
{
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    std::cin >> a >> b >> c;
    d = b*b-4*a*c;
    if (a == 0)
    {   if (b == 0)
        {
            std::cout << endl;
        }
        else
        {
            std::cout << -(float)c/b;
        }
    }
    else
    {
        if (d == 0)
        {
            std::cout << -(float)b/2/a;
        } 
        else 
        {
            if (d>0)
                {
                    if (a<0)
                    {
                        std::cout << (-b+sqrt(d))/2/(float)a << ' ' << (-b-sqrt(d))/2/(float)a;
                    }
                    else 
                    {
                        std::cout << (-b-sqrt(d))/2/(float)a << ' ' << (-b+sqrt(d))/2/(float)a;
                    }
                }
            else 
            {
                std::cout << endl;
            }
                   
        }
    }
    return 0;
}