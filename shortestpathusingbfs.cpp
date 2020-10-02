#include<bits/stdc++.h>
//#include<boost/multiprecision/cpp_ll.hpp>
//using boost::multiprecision::cpp_ll; // use cpp_ll as data type for large numbers 
using namespace std;

#define ll long long
#define pb push_back
#define fast() ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define mod 1000000007
#define mp make_pair
#define ff first
#define ss second
#define vi vector<ll>
#define vll vector<long long ll>
#define log2(X) (63ll - __builtin_clzll(X))
#define test ll t; cin>>t; while(t--)
#define modInv(n) po(n,mod-2)%mod
#define ncr(n,r) (((fact[n]*modInv(fact[r]))%mod)*modInv(fact[n-r]))%mod

vector<int> adj[2*100000+5];
int visited[100005];
int parent[100005];
int dis[100005];


bool bfs(int s, int d)
{
    queue<int> q;
    q.push(s);
    visited[s]=1;
    dis[s]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0; i<adj[x].size(); i++)
        {
            if(visited[adj[x][i]]==0)
            {
                visited[adj[x][i]]=1;
                dis[adj[x][i]]=dis[x]+1;
                parent[adj[x][i]]=x;
                q.push(adj[x][i]);
                
                if(adj[x][i]==d)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
int main() 
{
   fast()
   int n,m;
   cin>>n>>m;
   int c=0;
   while(m--)
   {
      int u,v;
      cin>>u>>v;
      adj[u].pb(v);
      adj[v].pb(u);
   }
   for(int i=0; i<=n; i++)
   {
       dis[i]=INT_MAX;
       visited[i]=0;
       parent[i]=-1;
   }
  bool check= bfs(1,n);
   if(check==false)
   {
       cout<<"IMPOSSIBLE"<<"\n";
       return 0;
   }
   cout<<dis[n]+1<<"\n";
   vector<int> ans;
   int res=n;
   ans.pb(n);
   while(parent[res]!=-1)
   {
      ans.pb(parent[res]);
      res=parent[res];
   }
   for(int i=ans.size()-1; i>=0; i--)
   {
       cout<<ans[i]<<" ";
   }
   return 0;
}
