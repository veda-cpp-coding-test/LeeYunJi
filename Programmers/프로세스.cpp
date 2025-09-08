#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location)
{
    queue<pair<int, int>> q;
    priority_queue<int> pq; // max 값 확인을 위한 우선순위 큐 생성
    for (int i = 0; i < priorities.size(); i++)
    {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    int order = 0;
    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        // 현재 큐의 최고 우선순위와 비교
        if (cur.first == pq.top())
        {
            // 실행
            ++order;
            pq.pop();
            if (cur.second == location)
                return order;
        }
        else
        {
            // 뒤로 이동
            q.push(cur);
        }
    }
    return order; // 정상적으로는 여기 도달하지 않음
}