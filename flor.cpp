#include <cmath>
#include <iostream>
#define CONSTANTE 3

using namespace std;


// long long expoMod(long long base, long long exp, long long mod) {
//     long long res = 1;
//     base = base % mod;
//     while (exp > 0) {
//         if (exp % 2 == 1) res = (res * base) % mod;
//         base = (base * base) % mod;
//         exp /= 2;
//     }
//     return res;
// }



// int teste() {
//
//     long long semente = 0;
//
//     cin >> semente;
//
//     long long total = 0;
//
//     for (long long i = semente; i >= 0; i--) {
//         long long potencia = expoMod(CONSTANTE, i, 1000000007LL);
//         if (potencia <= semente) {
//             total = semente + potencia;
//             break;
//         }
//     }
//
//     cout << total;
//
//     return 0;
// }