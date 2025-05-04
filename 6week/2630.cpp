#include <iostream>

using namespace std;

int paper[128][128];
int white = 0, blue = 0;

bool check(int x, int y, int size)
{
    int color = paper[x][y];
    for (int i = x; i < x + size; ++i)
        for (int j = y; j < y + size; ++j)
            if (paper[i][j] != color)
                return false;
    return true;
}

void divide(int x, int y, int size)
{
    if (check(x, y, size))
    {
        if (paper[x][y] == 0)
            ++white;
        else
            ++blue;
        return;
    }
    int half = size / 2;
    divide(x, y, half);
    divide(x, y + half, half);
    divide(x + half, y, half);
    divide(x + half, y + half, half);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> paper[i][j];
    divide(0, 0, n);
    cout << white << '\n'
         << blue;
    return 0;
}
