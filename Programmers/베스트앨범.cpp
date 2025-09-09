#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays)
{ // ← by-value로 변경
    vector<int> answer;

    unordered_map<string, int> genreSum;
    unordered_map<string, vector<pair<int, int>>> genreSongs;

    genreSum.reserve(genres.size());
    genreSongs.reserve(genres.size());

    for (int i = 0; i < (int)genres.size(); ++i)
    {
        genreSum[genres[i]] += plays[i];
        genreSongs[genres[i]].emplace_back(plays[i], i);
    }

    vector<pair<string, int>> orderedGenres;
    orderedGenres.reserve(genreSum.size());
    for (const auto &kv : genreSum)
        orderedGenres.emplace_back(kv.first, kv.second);

    sort(orderedGenres.begin(), orderedGenres.end(),
         [](const pair<string, int> &a, const pair<string, int> &b)
         {
             return a.second > b.second;
         });

    for (const auto &gs : orderedGenres)
    {
        auto &vec = genreSongs[gs.first];
        sort(vec.begin(), vec.end(),
             [](const pair<int, int> &a, const pair<int, int> &b)
             {
                 if (a.first == b.first)
                     return a.second < b.second;
                 return a.first > b.first;
             });
        for (int k = 0; k < (int)vec.size() && k < 2; ++k)
            answer.push_back(vec[k].second);
    }

    return answer;
}
