#include <iostream>
#include <algorithm>

using namespace std;

int payments[10000], pc, bookPrice = -1;

int main()
{
   while (scanf("%d", &pc) != EOF) {
       for (int i = 0; i < pc; ++i)
           scanf("%d", &payments[i]);
       scanf("%d", &bookPrice);

       sort(payments, payments + pc);

       int i = 0, j = pc - 1, lower, upper, total;
       while (i < j) {
           total = payments[i] + payments[j];
           if (total == bookPrice)
               lower = i++, upper = j--;
           else if (total < bookPrice)
               i++;
           else
               j--;
       }

       printf("Peter should buy books whose prices are %d and %d.\n\n", payments[lower], payments[upper]);
   }
   return 0;
}
