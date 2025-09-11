#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow)
{
    int total = brown + yellow;
    for (int h = 3; h <= total; h++)
    {
        if (total % h != 0)
            continue; // 세로 길이가 total의 약수여야 한다.
        int w = total / h;
        if ((w - 2) * (h - 2) == yellow)
        {
            return {w, h};
        }
    }
}