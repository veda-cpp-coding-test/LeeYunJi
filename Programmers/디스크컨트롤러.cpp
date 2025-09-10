#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> jobs)
{
    sort(jobs.begin(), jobs.end()); // 요청시각 기준 오름차순 정렬

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int cur = 0, idx = 0, total = 0, n = jobs.size();

    while (idx < n || !pq.empty())
    {
        // 현재 시간까지 도착한 작업 모두 push
        while (idx < n && jobs[idx][0] <= cur)
        {
            pq.push({jobs[idx][1], jobs[idx][0]}); // {소요시간, 요청시각}
            idx++;
        }

        if (!pq.empty())
        {
            auto [dur, req] = pq.top();
            pq.pop();
            cur += dur;
            total += cur - req; // 대기시간 + 실행시간
        }
        else
        {
            // 큐가 비어있으면 다음 job 시작 시각으로 점프
            cur = jobs[idx][0];
        }
    }

    return total / n;
}
