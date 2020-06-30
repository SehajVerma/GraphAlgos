https://practice.geeksforgeeks.org/problems/minimum-cost-path/0

#include <bits/stdc++.h>
using namespace std;
int grid[1000][1000];
bool isSafe(int x,int y,int n,int m)
{
    if(x>=0 && y>=0 && x<n && y<m)
    return true;
    else
    return false;
}
int dijkastra(int n,int m)
{
    int dist[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
           dist[i][j]=INT_MAX;
    }
    
    dist[0][0]=grid[0][0];
    set<pair<int,pair<int,int>>>s;
    s.insert({grid[0][0],{0,0}});
    int dx[4]={0,-1,0,1};
    int dy[4]={-1,0,1,0};
    
    while(!s.empty())
    {
        auto p = *(s.begin());
        int x = p.second.first;
        int y = p.second.second;
        int nodeDist = p.first;
        s.erase(s.begin());
        
        for(int i=0;i<4;i++)
        {
            if(isSafe(x+dx[i],y+dy[i],n,m))
            {
               int destx = x+dx[i];
               int desty = y+dy[i];
               if(dist[destx][desty] > (grid[destx][desty] + nodeDist))
               {
                   dist[destx][desty] = grid[destx][desty] + nodeDist;
                   auto f = s.find({grid[destx][desty],{destx,desty}});
                   if(f!=s.end())
                   s.erase(f);
                   
                   s.insert({dist[destx][desty],{destx,desty}});
               }
            }
        }

    }
    return dist[n-1][m-1];
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>grid[i][j];
	        }
	    }
	    cout<<dijkastra(n,n)<<endl;
	}
	return 0;
}
