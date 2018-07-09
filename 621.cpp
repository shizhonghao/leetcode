#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool cmp(const int &a, const int &b)
    {
        return a>b;
    }

    int leastInterval(vector<char>& tasks, int n)
    {
        int result = tasks.size();
        map<char,int> cnt;
        map<char,int> ::iterator it;
        //cout << tasks[0] << endl;
        for(int i=0;i<tasks.size();i++)
        {
            cnt[tasks[i]]++;
        }
        vector<int> task_cnt;
        for(it=cnt.begin();it!=cnt.end();it++)
        {
            task_cnt.push_back(it->second);
        }
        sort(task_cnt.begin(),task_cnt.end(),this->cmp);
        int max_cnt = 1;
        for(int i=1;i<task_cnt.size();i++)
        {
            if(task_cnt[i] != task_cnt[i-1])
            {
                break;
            }
            max_cnt++;
        }
        //cout << result << " " << task_cnt[0] << " " << max_cnt << endl;
        result = max(result,(task_cnt[0]-1)*(n+1)+max_cnt);

        return result;
    }
};

int main()
{
    Solution s;
    vector<char> tasks;
    string input;
    int n;
    cin >> input >> n;
    for(int i=0;i<input.length();i++)
    {
        tasks.push_back(input[i]);
    }
    cout << s.leastInterval(tasks,n) << endl;
    return 0;
}
