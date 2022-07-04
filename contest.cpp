#include <bits/stdc++.h>
#include "theory\graphs.cpp"


using namespace std;

#define INF 1e18
#define nl '\n'


// #define pii pair<int, int>
#define ll long long
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<pii> vpii;

void mahi(){
   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

}
void solve();
void test(); 

const int N=1e5+1;
vector<pii>gp[N];
const int M=22;
vector<vi>partab(N,vi(M,0));
vi level(N,0);
vi pathlen(N,0);
vi tin(N,0);
vi tout(N,0);
void makegraph(int V,int E){
  int u,v,w;
  while(E--){
    cin>>u>>v>>w;
    gp[u].push_back({v,w});
    gp[v].push_back({u,w});

  }
}

void printgraph(int V){
     for(int i=1;i<=V;i++)
     {cout<<i<<" => : ";
      for( const auto & vw : gp[i] ){
        cout<<vw.first<<" "<<vw.second<<", ";
      }
      cout<<'\n';
     }
}

void dfs(int u,int par){
  static int t=0;
  tin[u]=++t;
  partab[u][0]=par;
  for(int i=1;i<M;i++)
  partab[u][i]=partab[partab[u][i-1]][i-1];
   level[u]=level[par]+1;
  for( const auto & vw : gp[u] ){
    if(vw.first != par){
   pathlen[vw.first] = pathlen[u]+vw.second;
      dfs(vw.first,u);
    }
  }
  tout[u]=t;
}

int lcs(int u,int v){
  if(level[u]<level[v]) swap(u,v);

  int x=level[u]-level[v];
  for(int i=0;i<M;i++)
  {
   if(1<<i & x){
    u=partab[u][i];
   }
  }
  
  if(u==v) return u;

  for(int i=M-1;i>=0;i--)
  {
    if(partab[u][i]!=partab[v][i]) {
      u=partab[u][i];
      v=partab[v][i];
    } 
  }
  
  return partab[u][0];
}

void printPath(int lc,int x){
  if(lc==x) return;
  printPath(lc,partab[x][0]);
  cout<<x<<" ";
}

int main()
{
  mahi();

  int t=89;
  
  solve();
  /*
  cin >> t;
  while (t--)
  {
  solve();
  cout << nl;
  }
  */ 
 
} 

void test()
{
  
   int t, n, var, m, x, p, a, b, c, y, i, j;
  string wr, ans;
  var = 0;
  
  
}
void solve()
{
   
  ll t,k, n, var, m, x, p, a, b, c,d, y, i, j,V,E;
  string wrd, ans;
  var = 0;
  string s;
 
  cin>>V>>E;
  makegraph(V,E);
  printgraph(V);
  
  level[0]=0;
  level[1]=1;
  partab[0][0]=partab[1][0]=0;
  pathlen[0]=pathlen[1]=0;
  tin[0]=0;tout[0]=V+1;
  dfs(1,0);
  
  // ! level of tree 
  for(int i=0;i<=V;i++)
  {
   cout<<i<<"->  "<<level[i]<<" | "<<pathlen[i]<<'\n';
  }
  
  //! tin tout
  for(int i=0;i<=V;i++)
  {
   cout<<i<<"->  "<<tin[i]<<" | "<<tout[i]<<'\n';
  }
 
 //! parent table
  for(int i=0;i<=V;i++)
  {
    cout<<i<<" => ";
   for(int j=0;j<M;j++)
   {
     cout<<setw(3)<<partab[i][j]<<" ";
   }
   cout<<'\n';
  }
  
  t=6;
  // ! LCA testing
  while (t--)
  {
    cin>>x>>y;
    a=lcs(x,y);
    b=pathlen[x]+pathlen[y]-2*pathlen[a];
    cout<<x<<" "<<y<<" LCS= "<<a<<" "<<b<<"\n";
    printPath(a,x);
    cout<<a<<" ";
    printPath(a,y);
    cout<<"\n\n";
  }
  


}


