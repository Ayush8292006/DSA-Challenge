#include <iostream>
using namespace std;

// even binform  rhega to multiply nhi krenge,  odd rhega tb multiply krenge
// jese n = 10 to multiply nhi krenge , binform fir n/2 hokr 5 hoga to multiply krenge, x = x*x krke x ko update krenge, binform ko bhi n/2 krke update krenge

double myPow(double x, int n) {
    if(n == 0) return 1.0;
    if(x == 0) return 0.0;
    if(x == 1) return 1.0;
    if(x == -1 && n % 2 == 0) return 1.0;
    if(x == -1 && n % 2 != 0) return -1.0;

    long long binForm = n;

    // handle negative power
    if(n < 0) {
        x = 1 / x;
        binForm = -binForm;
    }

    double ans = 1;

    while(binForm > 0) {
        if(binForm % 2 == 1) {
            ans *= x;
        }
        x *= x;
        binForm /= 2;
    }

    return ans;
}

int main() {
    double x = 2.0;
    int n = 10;

    cout << "Result: " << myPow(x, n) << endl;

    return 0;
}