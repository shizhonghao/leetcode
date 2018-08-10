#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<string,string> father;
    map<string,double> ratio_to_father;

    string get_father(string x)
    {
        if(father[x]==x)
        {
            return x;
        }
        else
        {
            string old_father = father[x];
            father[x] = get_father(father[x]);
            ratio_to_father[x] *= ratio_to_father[old_father];
            return father[x];
        }
    }

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries)
    {
        for(int i=0;i<equations.size();i++)
        {
            string a = equations[i].first;
            string b = equations[i].second;
            if(father.count(a)==0)
            {
                father[a] = a;
                ratio_to_father[a] = 1.0;
            }
            if(father.count(b)==0)
            {
                father[b] = b;
                ratio_to_father[b] = 1.0;
            }
            string fa = get_father(a);
            string fb = get_father(b);
            if(fa!=fb)
            {
                father[fa] = fb;
                ratio_to_father[fa] = values[i]*ratio_to_father[b]/ratio_to_father[a];
            }

        }


        vector<double> result;
        for(int i=0;i<queries.size();i++)
        {
            string a = queries[i].first;
            string b = queries[i].second;
            if(father.count(a)==0 || father.count(b)==0)
            {
                result.push_back(-1.0);
            }
            else
            {
                string fa = get_father(a);
                string fb = get_father(b);
                //cout << fa << " " << fb << endl;
                if(fa!=fb)
                {
                    result.push_back(-1.0);
                }
                else
                {
                    result.push_back(ratio_to_father[a]/ratio_to_father[b]);
                }
            }
        }
        return result;
    }
};

int main()
{
    return 0;
}
