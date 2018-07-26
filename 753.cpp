#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    set<string> visit;
    string result;
    void dfs(string node,int k)
    {
        for(int i=0;i<k;i++)
        {
            char c = '0'+i;
            string tmp = node.substr(1);
            tmp += c;
            if(visit.count(tmp)==0)
            {
                visit.insert(tmp);
                dfs(tmp, k);
                result += c;
            }
        }
    }

    string crackSafe(int n, int k) {
        if(n==1)
        {
            for(int i=0;i<k;i++)
            {
                result += ('0'+i);
            }
            return result;
        }
        string node;
        for(int i=0;i<n;i++)
        {
            node += '0';
        }
        dfs(node,k);
        for(int i=1;i<n;i++)
        {
            result += '0';
        }


        return result;
    }
};

int main()
{
    return 0;
}
