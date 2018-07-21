#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<vector<string> > result;
        map<string,int> line;
        for(int i=0;i<strs.size();i++)
        {
            string str = strs[i];
            sort(str.begin(),str.end());
            if(line.count(str)==0)
            {
                line[str] = result.size();
                vector<string> new_line;
                new_line.push_back(strs[i]);
                result.push_back(new_line);
            }
            else
            {
                result[line[str]].push_back(strs[i]);
            }
        }

        return result;
    }
};
int main()
{
    return 0;
}
