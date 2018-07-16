#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        string result;
        map<char,int> first;
        map<char,int> ::iterator it;
        for(int i=0;i<s.length();i++)
        {
            first[s[i]] = i;
        }
        char c;
        int index,last_index = 0;
        int turns = first.size();
        for(int i=0;i<turns;i++)
        {
            index = s.length()+1;
            for(it=first.begin();it!=first.end();it++)
            {
                if(it->second<index)
                {
                    index = it->second;
                    c = it->first;
                }
            }
            cout << last_index << " " << index << " " << c << endl;

            char res = 'z'+1;
            //cout <<  << index << endl;
            for(int j=last_index;j<=index;j++)
            {
                if(s[j]<res && first.count(s[j]))
                {
                    res = s[j];
                    last_index = j+1;
                }
            }
            first.erase(res);
            result += res;
        }

        return result;
    }
};

int main()
{
    return 0;
}
