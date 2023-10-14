#include <bits/stdc++.h>
using namespace std;

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int l1 = abs(A - C);
    int h1 = abs(B - D);

    int l2 = abs(E - G);
    int h2 = abs(F - H);

    int result = l1 * h1 + l2 * h2;

    // no overlap
    if (B >= H || F >= D || C <= E || G <= A)
        return result;

    // overlap exists
    int l3 = abs(min(C, G) - max(A, E));
    int h3 = abs(min(D, H) - max(B, F));
    result = result - l3 * h3;
    return result;
}

int main()
{

    return 0;
}