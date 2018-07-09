#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int result = 0, last_id = 0;
    int len = s.length();
    map<char,int> last_char;
    for(int i=0;i<len;i++)
    {
        if(last_char.count(s[i])==1) //NOT first char in string
        {
            //cout << i << endl;
            if(last_char[s[i]]>=last_id)
            {
                last_id = last_char[s[i]]+1;
            }
        }
            result = max(result,i-last_id+1);
        //cout << s[i] << " " << last_id << " " << last_char[s[i]] << " " << last_char.count(s[i]) << endl;
        last_char[s[i]] = i;
    }
    return result;
}

int main()
{
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}
