#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool is_pa(string s, int len)
    {
        for(int i=0;i<(len-1)/2+1;i++)
        {
            if(len-i-1<s.length())
            {
                if(s[i]!=s[len-1-i])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool is_pa_r(string s, int len)
    {
        int slen = s.length();
        for(int i=slen-(len-1)/2-1;i<slen;i++)
        {
            //cout<<i<<" "<<2*slen-len-i-1<<endl;
            if(2*slen-len-i-1>=0)
            {
                if(s[i]!=s[2*slen-len-i-1])
                {
                    return false;
                }
            }
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words)
    {
        //is_pa_r("sslll",8);
        vector<vector<int> > result;
        //return result;
        map<string,int> sub;
        for(int i=0;i<words.size();i++)
        {
            string rev = words[i];
            reverse(rev.begin(),rev.end());
            sub[words[i]] = i;
        }
        for(int i=0;i<words.size();i++)
        {
            string str = words[i];
            int len = str.length();
            for(int j=len;j<=len*2;j++)
            {
                if(is_pa(str,j))
                {
                    string rev = str.substr(0,j-len);
                    reverse(rev.begin(),rev.end());
                    if(sub.count(rev))
                    {
                //cout << str << " " << j << " " << rev << endl;
                        //cout<<i<<" "<<sub[rev]<<endl;
                        if(sub[rev]!=i)
                        {
                            vector<int> tmp;
                            tmp.push_back(i);
                            tmp.push_back(sub[rev]);
                            result.push_back(tmp);
                        }
                    }
                }
                if(is_pa_r(str,j))
                {
                    //cout<<str<<" "<<rev<<" "<<j<<endl;
                    string rev = str.substr(2*len-j);
                    reverse(rev.begin(),rev.end());
                    if(sub.count(rev))
                    {
                        if(sub[rev]!=i)
                        {
                            vector<int> tmp;
                            tmp.push_back(sub[rev]);
                            tmp.push_back(i);
                            result.push_back(tmp);
                        }
                    }
                }
            }
        }
        sort(result.begin(),result.end());
        for(int i=1;i<result.size();i++)
        {
            if(result[i]==result[i-1])
            {
                result.erase(result.begin()+i);
                i--;
            }
        }

        return result;
    }
};

int main()
{
    return 0;
}
