#include <iostream>
using namespace std;

int main() {
    double cuts;
    while (scanf("%lf", &cuts), cuts > 0) {
        if (cuts == 1) printf("0%%\n");
        else {
            cuts /= 4;
            printf("%.0lf%%\n", cuts * 100);
        }
    }
    return 0;
}
