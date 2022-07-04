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




/**************** Code Area********************/

// Loose upper bound
int upperbound(int*ar,int l,int r,int val){
  int n=(r-l+1);
  while(l<=r){
    int m=(l+r)/2;

    if(ar[m]<=val) l=m+1;
    else r=m-1;

  }
  if(l==0) return l;
  else if ( ar[r]==val) {
     return r;
  }
  return l;
}
// loose lower bound:
int lowerbound(int*ar,int l,int r,int val)
{
  int n=(r-l+1);
  while(l<=r){
    int m=(l+r)/2;
    
    if(ar[m]>=val) r=m-1;
    else l=m+1;

  }
  
  if(l==n) return r; 
  else if(ar[l]==val) return l;
  return r;
  
}





/*********************** End of modules ***************/












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
 
 int ar[8] = {1,3,5,5,7,9,11,13};

  for(ll i=0;i<8;i++) cout<<setw(3)<<i<<" ";
  cout<<nl;
  for(ll i=0;i<8;i++)
  {
  cout<<setw(3)<<ar[i]<<" ";
  }cout<<nl;
  
  m=10;
  cout<<"val LLB  LUB \n";
  while(m--){
    cin>>t;
    cout<<t<<" => "<<"    "<<lowerbound(ar,0,7,t)<<"   |   "<<upperbound(ar,0,7,t)<<'\n';
  }
  

}


