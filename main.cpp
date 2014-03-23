#include <iostream>
#include <fstream>
#include "functions.h"

using namespace std;

int main()
{
    const int n = 20;
    Brand *a = new Brand[n];
    Menu(a, n);
    delete []a;
    return 0;
}
