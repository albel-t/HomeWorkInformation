#include <iostream>

int toS(int i, int s)
{
    int res = 0;
    while (i != 0)
    {
        res = res * 10 + i % s;
        i /= s;
    }
    return res;
}
int toDec(int i, int s)
{
    int res = 0;
    int S = 1;
    int dec = 1;
    while (i != 0)
    {
        res = res + (i % 10) * S;// *dec;
        i /= 10;
        S = S * s;
        dec *= 10;
    }
    return res;
}


int main()
{
    int max = 0;
    for (int i = 0; i < 1000; i++)
    {
        int x = toS(i, 6);
        x = x * 10 + x % 10;
        x = toS(toDec(x, 6), 2);
        x = x * 10 + x % 10;
        x = toDec(x, 2);
        max = x > max && x < 344 ? x : max;
    }
    std::cout << max;
}