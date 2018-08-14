#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs)
    {
        vector<int> result(n);
        stack<int> s;
        int prev = 0;
        for(int i=0;i<logs.size();i++)
        {
            string log = logs[i];
            int pos1 = log.find(":");
            int pos2 = log.substr(pos1+1).find(":");
            int id = stoi(log.substr(0,pos1));
            string status = log.substr(pos1+1,pos2);
            int time = stoi(log.substr(pos2+pos1+2));
            //cout << id << " " << status << " " << time << endl;
            if(status=="start")
            {
                if(!s.empty())
                {
                    int last = s.top();
                    result[last] += time-prev;
                }
                s.push(id);
                prev = time;
            }
            else
            {
                int last = s.top();
                result[last] += time-prev+1;
                s.pop();
                prev = time+1;
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
