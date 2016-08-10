#include <iostream>
using namespace std;

struct Piece {
    int left, right;
    bool used;
}pieces[20], valid[20];

int spaces, piecesCount;

bool select(int piecePlace) {
    if (piecePlace == spaces + 1)
        return valid[piecePlace].left == valid[piecePlace - 1].right;

    for (int i = 0; i < piecesCount; ++i) {
        if (!pieces[i].used) {
            if (valid[piecePlace - 1].right == pieces[i].left) {
                valid[piecePlace].left = pieces[i].left;
                valid[piecePlace].right = pieces[i].right;
                pieces[i].used = true;
                if (select(piecePlace + 1)) return true;
                pieces[i].used = false;
            } else if (valid[piecePlace - 1].right == pieces[i].right) {
                valid[piecePlace].left = pieces[i].right;
                valid[piecePlace].right = pieces[i].left;
                pieces[i].used = true;
                if (select(piecePlace + 1)) return true;
                pieces[i].used = false;
            }
        }
    }
    return false;
}

int main() {
    while (scanf("%d", &spaces), spaces) {
        scanf("%d", &piecesCount);
        scanf("%d%d", &valid[0].left, &valid[0].right);
        scanf("%d%d", &valid[spaces + 1].left, &valid[spaces + 1].right);

        for (int i = 0; i < piecesCount; ++i) {
            scanf("%d%d", &pieces[i].left, &pieces[i].right);
            pieces[i].used = false;
        }

        printf("%s\n", select(1)? "YES": "NO");
    }
    return 0;
}
