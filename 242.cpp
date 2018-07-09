#include <bits/stdc++.h>

using namespace std;

bool isAnagram(string s, string t)
{
    map<char,int> cnt1,cnt2;
    int len1 = s.length();
    int len2 = t.length();
    if(len1!=len2)
    {
        return false;
    }
    for(int i=0;i<len1;i++)
    {
        cnt1[s[i]]++;
        cnt2[t[i]]++;
        /*
        if(cnt1.count(s[i]))
        {
            cnt1[s[i]] = cnt1[s[i]] + 1;
        }
        else
        {
            cnt1[s[i]] = 1;
        }

        if(cnt2.count(t[i]))
        {
            cnt2[t[i]] = cnt2[t[i]] + 1;
        }
        else
        {
            cnt2[t[i]] = 1;
        }
        */
    }
    int size1 = cnt1.size();
    map<char,int> ::iterator it;
    for(it=cnt1.begin(); it!=cnt1.end(); it++)
    {
        char key = it->first;
        if(it->second != cnt2[key])
        {
            return false;
        }
        cout << key << " " << it->second << " " << cnt2[key] << endl;
    }
    return true;

}

int main()
{
    string s,t;
    cin >> s >> t;
    string result = isAnagram(s,t)? "true" : "false";
    cout << result << endl;
    return 0;
}
