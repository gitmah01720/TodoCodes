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
struct obj{
 char ch;
 int val;
 
 obj(){ }
 obj(char c,int i):ch(c),val(i){}
 void show(){
  cout<<val<<" "<<ch<<nl;
 }
};
bool compmin(obj*x,obj*y){
  return x->val >= y->val;
}

template<class T>
class hep{
   T**ar;
   int siz;
   bool(*comp)(T*,T*);

   public:
   void init(int n,bool(*cmp)(T*,T*)){
    ar=new T*[n+2];
    comp = cmp;
    siz=0;
   }
   int goodchild(int pos){
     if(2*pos + 1 <= siz){
      return (comp(ar[2*pos],ar[2*pos + 1]))?2*pos:2*pos + 1;
     }
     return 2*pos;
   }
   void sink(int pos){
      while(2*pos <= siz){
        int best = goodchild(pos);
        if(comp( ar[pos],ar[best])==false){
          swap(ar[pos],ar[best]);
          pos=best;
        }else break;
      }
   }
   void swim(int pos){
      while(pos > 1){
        if(comp(ar[pos/2],ar[pos])==false){
          swap(ar[pos],ar[pos/2]);
          pos/=2;
        }else break;
      }
      
   }
   void insert(T*nod){
     ar[siz+1] = nod;
     siz++;
     swim(siz);
   }
   T*unheap(){
    if(siz==0) return NULL;
    T*toret=ar[1];
    swap(ar[1],ar[siz]);
    siz--;
    sink(1);
    return toret;
   }
};

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
  char ch;
 
  hep<obj>qq;
  qq.init(9,compmin);
  
  var=15;
  t=var;
  while(t--){
    cin>>ch>>m;
    obj*p=new obj(ch,m);
    qq.insert(p);
  }
   t=var;
  while(t--){
    obj*p = qq.unheap();
    p->show();
  }
 
  

}


