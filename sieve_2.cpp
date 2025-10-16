
In 1742, Christian Goldbach, a German amateur mathematician, sent a letter to Leonhard Euler in
which he made the following conjecture:
Every number greater than 2 can be written as the sum of three prime numbers.
Goldbach was considering 1 as a primer number, a convention that is no longer followed. Later on,
Euler re-expressed the conjecture as:
Every even number greater than or equal to 4 can be expressed as the sum of two prime
numbers.
For example:
• 8 = 3 + 5. Both 3 and 5 are odd prime numbers.
• 20 = 3 + 17 = 7 + 13.
• 42 = 5 + 37 = 11 + 31 = 13 + 29 = 19 + 23.
Today it is still unproven whether the conjecture is right. (Oh wait, I have the proof of course, but
it is too long to write it on the margin of this page.)
Anyway, your task is now to verify Goldbach’s conjecture as expressed by Euler for all even numbers
less than a million.
Input
The input file will contain one or more test cases.
Each test case consists of one even integer n with 6 ≤ n < 1000000.
Input will be terminated by a value of 0 for n.
Output
For each test case, print one line of the form n = a + b, where a and b are odd primes. Numbers and
operators should be separated by exactly one blank like in the sample output below. If there is more
than one pair of odd primes adding up to n, choose the pair where the difference b − a is maximized.
If there is no such pair, print a line saying ‘Goldbach's conjecture is wrong.’
Sample Input
8
20
42
0
Sample Output
8 = 3 + 5
20 = 3 + 17
42 = 5 + 37





#include <iostream>
using namespace std;

const int MAX = 1000000;
bool isPrime[MAX + 1];


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

int main() {
    sieve();

    int n;
    while (cin >> n && n != 0) {
        bool found = false;

        for (int a = 3; a <= n / 2; a += 2) {
            int b = n - a;
            if (isPrime[a] && isPrime[b]) {
                cout << n << " = " << a << " + " << b << endl;
                found = true;
                break;
            }
        }

        if (!found)
            cout << "Goldbach's conjecture is wrong." << endl;
    }

    return 0;
}

