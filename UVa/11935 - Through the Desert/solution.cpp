#include <iostream>
#include <string.h>
using namespace std;

int ld, d, t, a, leak; // last distance, distance, type, amount, decrease
float tank, minimumTank = 0, decrease;
char temp[20];

void read() {
    // Read distance that the event happens
    scanf("%d", &d);

    // Find out what event happend
    scanf("%s", temp);
    if (strcmp(temp, "Fuel") == 0) scanf("%s%d", temp, &a), t = 1;
    else if (strcmp(temp, "Leak") == 0) t = 2;
    else if (strcmp(temp, "Gas") == 0) scanf("%s", temp), t = 3;
    else if (strcmp(temp, "Mechanic") == 0) t = 4;
    else if (strcmp(temp, "Goal") == 0) t = 5;
}

int main() {
    while (read(), d || a) {
        // Initialization
        if (d == 0 && t == 1) minimumTank = tank = decrease  = leak = ld = 0;

        // Decreasing the tank
        tank -= (d - ld) * (decrease + leak);
        ld = d;

        // Find most used fuel
        if (minimumTank > tank) minimumTank = tank;

        // Updating variables considering the event
        if (t == 1) decrease = a / 100.0;
        else if (t == 2) ++leak;
        else if (t == 3) tank = 0;
        else if (t == 4) leak = 0;
        else if (t == 5) printf("%.3f\n", -minimumTank);
    }
    return 0;
}
