#include <iostream>
#include <string>
using namespace std;

struct Maker {
    string name;
    int l, h;
};

int main() {
    int tc, mc, qc, *queries;
    Maker *makers;
    string result;
    char temp[25];

    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &mc);
        makers = new Maker[mc];
        for (int i = 0; i < mc; i++) {
            scanf("%s%d%d", temp, &(makers[i].l), &(makers[i].h));
            makers[i].name = temp;
            // printf("%s, %d, %d\n", result.c_str(), makers[i].l, makers[i].h);
        }

        scanf("%d", &qc);
        queries = new int[qc];
        for (int i = 0; i < qc; i++) {
            scanf("%d", &(queries[i]));
        }

        for (int i = 0; i < qc; i++) {
            result = "";
            for (int j = 0; j < mc; j++) {
                if (makers[j].l <= queries[i] && queries[i] <= makers[j].h) {
                    if (result == "")
                        result = makers[j].name;
                    else
                        result = "UNDETERMINED";
                }
            }
            if (result == "") result = "UNDETERMINED";
            printf("%s\n", result.c_str());
        }

        if (tc) printf("\n");
        delete[] makers;
        delete[] queries;
    }
    return 0;
}
