#include <iostream>
#include<Vector.h>

int main()
{
    const int N = 33;
    bool array[N] = {true, false, true, true, true, false, false, true, false, true, false, true, true, true, true, true, false, false, false, false, true, true, false, false, true, false, true, false, true, false, true, true, false};
    Vector<bool> v;

    for (int i = 0; i < N; ++i)
        v.push_back(array[i]);

    return 0;
}