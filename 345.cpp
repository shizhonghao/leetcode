#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool is_vowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'
           || c=='A' || c=='E' || c=='I' || c=='O' || c=='U')
        {
            return true;
        }
        return false;
    }

    string reverseVowels(string s)
    {
        int l = 0,r = s.length()-1;
        {
            while(!is_vowel(s[l]) && l<s.length()-1)
            {
                l++;
            }
            while(!is_vowel(s[r]) && r>0)
            {
                r--;
            }
            while(l<r)
            {
                swap(s[l],s[r]);
                l++;
                r--;
                while(!is_vowel(s[l]) && l<s.length()-1)
                {
                    l++;
                }
                while(!is_vowel(s[r]) && r>0)
                {
                    r--;
                }
            }
        }
        return s;
    }
};


int main()
{
    return 0;
}
