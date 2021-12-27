#include <iostream>
#include <math.h>

using namespace std;

int getTNum(int n);
int getNumDiv(int n);

int main() {
    int i, tNum, numDiv;
    for (   i = 1, tNum = getTNum(i), numDiv = getNumDiv(tNum);
            numDiv <= 500;
            numDiv = getNumDiv(tNum = getTNum(++i)))
        ;
    cout << tNum;
}

int getTNum(int n) {
    return (n * (n + 1)) / 2;
}

int getNumDiv(int n) {
    int numDiv = 2;
    int root = sqrt(n);
    for (int i = 2; i <= root; i++)
        if (n % i == 0)
            if (i != root)
                numDiv += 2;
            else
                numDiv++;
    return n == 2 ? 2 : numDiv;
}
