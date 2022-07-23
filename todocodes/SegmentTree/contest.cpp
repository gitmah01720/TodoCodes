#include <bits/stdc++.h>
// #include "theory\graphs.cpp"


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
#define inf 1e9
const int N=1e5+1;
bitset<N>bb;

vi primes;

void mahi(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
   #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

}
void solve();
void test(); 

int *tre;
void init(int n_){
    int n = n_;
    tre= new int[4*n+1];
    // lazy= new int[4*n+1];
    fill(tre , tre+4*n+1 , -1*inf);
    // fill(lazy , lazy+4*n+1 , 0);
}

// recursive way t make segment tree:
int fun(int L,int R){
  // return L+R; // and change inf to 0;
return max(L,R);
}
int built_seg(int* ar,int s,int e,int index=1){
// base case:
if(s==e) return tre[index] = ar[s]; 

// Post order traversal:
int m=(s+e)/2;
int L = built_seg(ar,s,m,2*index);
int R = built_seg(ar,m+1,e,2*index + 1);

return tre[index]= fun(L,R);

}

int query_non_ovlp(int qs,int qe,int ss,int se,int indx=1){ //! O_log_n

// complete overlap:
if(qs<=ss && qe>=se) return tre[indx];

// No overlap
if(qe<ss || se < qs) return -1*inf;

// partial verlap:
int m = (ss+se)/2;

int L = query_non_ovlp(qs,qe,ss,m,2*indx);
int R = query_non_ovlp(qs,qe,m+1,se,2*indx+1);

return fun(L,R);

}
int point_update(int pos,int updt,int ss,int se,int idx=1){//! O_log_n
 // base case:
 // indx is not in range
 if(pos>se || pos<ss) return tre[idx];  // do not update


 if(ss==se) { tre[idx] += updt;cout<<"Updating for "<<ss<<" "<<se<<'\n'; return tre[idx];}

// updating ancesters:
int m = (ss+se)/2;

// tre[2*idx]  = fun(tre[2*idx],
point_update(pos,updt,ss,m,2*idx);
// tre[2*idx+1]  = fun(tre[2*idx+1],
point_update(pos,updt,m+1,se,2*idx+1);

return tre[idx] = fun(tre[2*idx],tre[2*idx+1]);

}
int rang_update(int l, int r,int updt,int ss,int se,int idx=1){ //! O_logn
    // base case:
    if(r<ss || l>se) return tre[idx];  // do not update if l,r does not lies:

    //updating if reached to leaf node;
    if(ss==se) {cout<<"Updating for "<<ss<<" "<<se<<'\n'; return tre[idx]+= updt;}

// range overlap:
  int m = (ss+se)/2;
   rang_update(l,r,updt,ss,m,2*idx);
   rang_update(l,r,updt,m+1,se,2*idx+1);

   return tre[idx] = fun(tre[2*idx],tre[2*idx+1]);

}
void print_tr(){
    for(int i=0;i<16;i++)
    {
     
    cout<<tre[i]<<'\n';
    }
}
 

int main()
{
  mahi();

  int t;
  
  solve();
  // test();
  // cout<<"Jai Ram\n";

  /*
  cin >> t;
  while (t--)
  {
  solve();
  // cout << nl;
  }
  */ 
 

} 

void test()
{
  
  int t, n, var, m, x, p, a, b, c, y, i, j;
  string wr="00001010", ans;
  var = 0;
  
  }


void solve()
{
   
  ll t,k, n, var, m, x, p, a, b, c,d, y, i, j,V,E;
  string wrd="00001010", ans;
  var = 0;
  t=5;
//   // init()
//  int ar[6] = {1,3,2,-5,6,4};
//   init(6);
//   m=5;
//   built_seg(ar,0,5);
// //  print_tr();

//   while (m--)
//   {
//     cin>>x>>y;
//     cout<<x<<" "<<y<<" " <<query_non_ovlp(x,y,0,5)<<nl;
//   }

cin>>n>>m;
int ar[m];
for(int i=0;i<m;i++)
{
 cin>>ar[i];
}
init(m+1);
built_seg(ar,0,m-1);
// print_tr();
  // while (t--)
  // {
  //   cin>>x>>y;
  //   cout<<x<<" "<<y<<" " <<query_non_ovlp(x-1,y-1,0,m-1)<<nl;
  // }

// return;
int xs,ys,xf,yf,q;
int h;
cin>>q;
while (q--)
{
  cin>>xs>>ys>>xf>>yf>>k;
  if(ys>=yf){
  swap(ys,yf);
  swap(xs,xf);
  }
  bool leftright,updwn;
  h=query_non_ovlp(ys-1,yf-1,0,m-1);
  
  // cout<<h;
  if(h==n) cout<<"NO\n";
  else{
   leftright = ((yf-ys)%k == 0)?true:false;
   updwn;
   if(h>=xs && h>=xf){
    int rem = (h-xs)%k;
    int top = h+k-rem;
    if(top>n){
      updwn=false;
    }else{
      updwn = ((top-xf)%k==0)?true:false;
    }
   }else{
      updwn = (abs(xf-xs)%k==0)?true:false;
   }
  if(leftright && updwn){
    cout<<"YES\n";
  }else{
    cout<<"NO\n";
  }
  }
  
  

}


}