#include <iostream>
using namespace std;

struct Job {
    int number, time, fine;
} temp;

Job jobs[1000];

int main() {
    int tc, n; scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &jobs[i].time, &jobs[i].fine);
            jobs[i].number = i + 1;
        }

        bool change = true;
        while (change) {
            change = false;
            for (int i = 0; i < n - 1; ++i)
                if (jobs[i].time * jobs[i + 1].fine - jobs[i + 1].time * jobs[i].fine > 0) {
                    change = true;

                    temp.number = jobs[i].number;
                    temp.time = jobs[i].time;
                    temp.fine = jobs[i].fine;

                    jobs[i].number = jobs[i + 1].number;
                    jobs[i].time = jobs[i + 1].time;
                    jobs[i].fine = jobs[i + 1].fine;

                    jobs[i + 1].number = temp.number;
                    jobs[i + 1].time = temp.time;
                    jobs[i + 1].fine = temp.fine;
                }
        }

        printf("%d", jobs[0].number);
        for (int i = 1; i < n; ++i)
            printf(" %d", jobs[i].number);
        printf("\n");
        if (tc) printf("\n");
    }
}
