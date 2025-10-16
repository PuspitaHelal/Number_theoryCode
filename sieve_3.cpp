HS08PAUL - A conjecture of Paul Erdős
#number-theory

In number theory there is a very deep unsolved conjecture of the Hungarian Paul Erdős (1913-1996), that there exist infinitely many primes of the form x2+1, where x is an integer. However, a weaker form of this conjecture has been proved: there are infinitely many primes of the form x2+y4. You don't need to prove this, it is only your task to find the number of (positive) primes not larger than n which are of the form x2+y4 (where x and y are integers).

Input
An integer T, denoting the number of testcases (T≤10000). Each of the T following lines contains a positive integer n, where n<10000000.

Output
Output the answer for each n.

Example
Input:
4
1
2
10
9999999

Output:
0
1
2
13175





#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000000;
bool isPrime[MAX + 1];
bool isSpecial[MAX + 1];
int specialCount[MAX + 1];

void sieve() {
    for (int i = 0; i <= MAX; i++)
        isPrime[i] = true;
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }
}

void precompute() {
    for (int y = 1; y * y * y * y <= MAX; y++) {
        int y4 = y * y * y * y;
        for (int x = 1; x * x + y4 <= MAX; x++) {
            int val = x * x + y4;
            if (isPrime[val]) {
                isSpecial[val] = true;
            }
        }
    }

    for (int i = 1; i <= MAX; i++) {
        specialCount[i] = specialCount[i - 1] + (isSpecial[i] ? 1 : 0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();
    precompute();

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << specialCount[n] << "\n";
    }

    return 0;
}
