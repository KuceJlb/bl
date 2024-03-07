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
std::cout << a;