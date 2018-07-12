#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

class Solution {
public:
    bool is_adj(string a,string b)
    {
        int cnt = 0;
        for(int i=0;i<a.length();i++)
        {
            if(a[i]!=b[i])
            {
                cnt++;
            }
        }
        return cnt==1 ? true : false;
    }

    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        wordList.push_back(beginWord);
        int n = wordList.size();
        vector<int> adj[n];
        int i,j,k;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(is_adj(wordList[i],wordList[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int dist[n];
        vector<vector<string> > history[n];
        int visited[n];
        memset(visited,0,sizeof(int)*n);
        memset(dist,INF,sizeof(int)*n);

        int end_pos = -1;
        for(i=0;i<n;i++)
        {
            if(endWord==wordList[i])
            {
                end_pos = i;
            }
        }
        if(end_pos==-1)
        {
            return history[0];
        }

        visited[n-1] = 1;
        dist[n-1] = 1;
        vector<string> his;
        his.push_back(wordList[n-1]);
        history[n-1].push_back(his);
        for(i=0;i<adj[n-1].size();i++)
        {
            int k_next = adj[n-1][i];
            dist[k_next] = 2;
            for(int x=0;x<history[n-1].size();x++)
            {
                vector<string> hist(history[n-1][x]);
                hist.push_back(wordList[k_next]);
                history[k_next].push_back(hist);
            }
        }

        for(i=1;i<n;i++)
        {
            int min_dist = INF;
            k = -1;
            for(j=0;j<n;j++)
            {
                if(visited[j]==0 && dist[j]<min_dist)
                {
                    min_dist = dist[j];
                    k = j;
                }
            }
            if(k==-1)
            {
                break;
            }
            visited[k] = 1;

            for(j=0;j<adj[k].size();j++)
            {
                int dist_sum = min_dist + 1;
                int k_next = adj[k][j];
                if(visited[k_next]==0)
                {
                    if(dist_sum<dist[k_next])
                    {
                        dist[k_next] = dist_sum;
                        history[k_next].clear();
                        for(int x=0;x<history[k].size();x++)
                        {
                            vector<string> hist(history[k][x]);
                            hist.push_back(wordList[k_next]);
                            history[k_next].push_back(hist);
                        }
                    }

                    else if(dist_sum==dist[k_next])
                    {
                        for(int x=0;x<history[k].size();x++)
                        {
                            vector<string> hist(history[k][x]);
                            hist.push_back(wordList[k_next]);
                            history[k_next].push_back(hist);
                        }
                    }
                }
            }
        }

        return history[end_pos];
    }
};



int main()
{

    return 0;
}
