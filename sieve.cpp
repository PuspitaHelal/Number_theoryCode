TDPRIMES - Printing some primes
#sieve-of-eratosthenes

The problem statement is really simple. You are to write all primes less than 108.

Input
There is no input.

Output
To make the problem less output related write out only the 1st, 101st, 201st, ... 1st mod 100.

Example
Input:

Output:
2
547
1229
...
99995257
99996931
99998953


#include <bits/stdc++.h>
using namespace std;

int main() {
    const int n = 1e8;
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= n; j += i)
                prime[j] = false;
        }
    }

    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            count++;
            if (count % 100 == 1)
                cout << i << "\n";
        }
    }

    return 0;
}
