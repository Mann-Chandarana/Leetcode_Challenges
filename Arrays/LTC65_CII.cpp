///// Important question

/*--------Medium-----------*/

/*- Top K Frequent Words -*/

//////// Question number 692.

#include <bits/stdc++.h>
using namespace std;

// Type 1:
//   auto myComparator = [](const psi &p1 const psi &p2){
//     if(p1.first == p2.first) return p1.second < p2.second;

//     return p1.first > p2.first;
//   } 

//   While declaring the priority queue
//   priority_queue<psi, vector<psi>, decltype(myComparator)> anyName(myComparator)

//   Type 2: If you want to declare a normal function and use it in the priority queue then it can be done in the following way
//   bool myComparator(const psi &p2 const psi *p2) {
//     if(p1.first == p2.first) return p1.second < p2.second;

//     return p1.first > p2.first;
//   }

//   While declaring the priority queue you just have to give the pointer to the function
//   priority_queue<psi, vector<psi>, decltype(&myComparator)> anyName(myComparator)  anyName(myComparator)

class cmp
{
public:
    bool operator()(pair<string, int> p1, pair<string, int> p2)
    {
        if (p1.second == p2.second)
        {
            return p1.first < p2.first;
        }
        return p1.second > p2.second;
    }
};

vector<string> topKFrequent(vector<string> &words, int k)
{
    unordered_map<string, int> ump;

    for (auto element : words)
    {
        ump[element]++;
    }
    vector<string> answer(k);
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;

    for (auto element : ump)
    {
        pq.push({element.first, element.second});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    int m = k - 1;
    while (pq.size() > 0)
    {
        answer[m--] = pq.top().first;
        pq.pop();
    }

    return answer;
}

int main()
{
    vector<string> words = {"the","day","is","sunny","the","the","the","sunny","is","is"};
    words = topKFrequent(words, 4);
    for (auto element : words)
    {
        cout << element << " ";
    }
    return 0;
}