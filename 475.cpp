#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters)
    {
        int result = 0;
        int i,j;
        int r[houses.size()+1];
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int last = heaters[0];
        for(i=0,j=0;i<houses.size();i++)
        {
            int house = houses[i];
            int heater = heaters[j];
            while(j<heaters.size()-1 && heater<house)
            {
                j++;
                last = heater;
                heater = heaters[j];
            }
            r[i] = min(abs(house-last),abs(heater-house));
            result = max(result,r[i]);
        }
        return result;
    }
};

int main()
{
    return 0;
}
