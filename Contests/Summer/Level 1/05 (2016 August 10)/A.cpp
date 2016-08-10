// #include <iostream>
// #include <string>
// using namespace std;
//
// int digit(long long number) {
//     if (number == 0) return 1;
//
//     int i = 0;
//     while (number) {
//         number /= 10;
//         ++i;
//     }
//     return i;
// }
//
// int main() {
//     long long i, j, sum, mul;
//     string sos /* square of sums */, is, js;
//     int k = 8, bound = 10000;
//
//     for (i = 0; i < bound; ++i) {
//         for (j = 0; j < bound; ++j) {
//             sum = i + j;
//             mul = sum * sum;
//             if (digit(mul) > k) continue;
//             sos = "00000000" + to_string(mul);
//
//             is = "00000000" + to_string(i);
//             js = "00000000" + to_string(j);
//
//             if (sos.substr(sos.length() - k, k) == is.substr(is.length() - k/2, k/2) + js.substr(js.length() - k/2, k/2))
//                 printf("%s\n", sos.substr(sos.length() - k, k).data());
//         }
//     }
//     return 0;
// }

// 00
// 01
// 81
// 
// 0000
// 0001
// 2025
// 3025
// 9801
//
// 000000
// 000001
// 088209
// 494209
// 998001
//
// 00000000
// 00000001
// 04941729
// 07441984
// 24502500
// 25502500
// 52881984
// 60481729
// 99980001


#include <iostream>
using namespace std;

int main() {
    int t;
    while (scanf("%d", &t) != EOF) {
        if (t == 2)
            printf("00\n01\n81\n");
        else if (t == 4)
            printf("0000\n0001\n2025\n3025\n9801\n");
        else if (t == 6)
            printf("000000\n000001\n088209\n494209\n998001\n");
        else if (t == 8)
            printf("00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n");
    }
    return 0;
}
