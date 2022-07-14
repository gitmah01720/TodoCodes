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

struct tnode{
  char data;
  tnode* charMap[26];
  bool isterminl;
  int wrdcnt;

  tnode(){ 
     for(int i=0;i<26;i++) charMap[i]=NULL;
     isterminl=false; 
    wrdcnt=0;
  }
  tnode(char ch){
   wrdcnt=0;
   data=ch;
   for(int i=0;i<26;i++) charMap[i]=NULL;
   isterminl=false; 
  }
  void setterminal(){
    isterminl = true;
  }
  
};


class triee{
  tnode*Root;
  int wcnt;
  
  void inserthelp(tnode*vtx,string&x,int i,int n){
    if(i==n-1){
      if(vtx->charMap[x[i]-'a']==NULL){
        vtx->charMap[x[i]-'a'] = new tnode(x[i]);
      }
        vtx->charMap[x[i]-'a']->setterminal();
        return;
    }

    if(vtx->charMap[x[i]-'a']==NULL){
        vtx->charMap[x[i]-'a'] = new tnode(x[i]);
    }
    inserthelp(vtx->charMap[x[i]-'a'],x,i+1,n);
  }
  void dfsHelp(tnode*vtx,string&ans){
    ans.push_back(vtx->data);
    // if(vtx->isterminl) cout<<ans<<'\n';
    cout<<vtx->data<<" "<<vtx->wrdcnt<<'\n';

    for(int i=0;i<26;i++)
    {
     if(vtx->charMap[i]) dfsHelp(vtx->charMap[i],ans);
    }
    ans.pop_back();
  }
  void wrdCntHelp(tnode*vtx){
    if(vtx->isterminl) vtx->wrdcnt = 1;

    for(int i=0;i<26;i++)
    {
      if(vtx->charMap[i]){  
      wrdCntHelp(vtx->charMap[i]); 
      vtx->wrdcnt += vtx->charMap[i]->wrdcnt;
      }
    }
  }
  void UNIQ_PrefixsHELP(tnode*vtx,string&ans){
    if(vtx->isterminl && vtx->wrdcnt > 1) cout<<-1<<nl;
    else if(vtx->wrdcnt == 1){
      ans.push_back(vtx->data);
      cout<<ans<<nl;
      ans.pop_back();
      return;
    }
    
    ans.push_back(vtx->data);

    for(int i=0;i<26;i++)
    {
     if(vtx->charMap[i]){
      UNIQ_PrefixsHELP(vtx->charMap[i],ans);
     }
    }

    ans.pop_back();

  }
  int Prefx_SUMHELP(tnode*vtx){

    int ans= vtx->wrdcnt;
    for(int i=0;i<26;i++)
    {
     if(vtx->charMap[i]){
      ans += Prefx_SUMHELP(vtx->charMap[i]);
     }
    }

    return ans;
  }
  
  public:
  triee(){
    Root = new tnode('*');
    wcnt=0;
  }
  void insert(string wrd ){
    // wrd.push_back('.');
    inserthelp(Root,wrd,0,wrd.size());
  }
  bool serarchPrefix(string &wrd,int i=0){
    static tnode*ptr=Root;
    if(i>= wrd.size()) return true;
    else if(ptr->charMap[wrd[i]-'a']){
      ptr=ptr->charMap[wrd[i]-'a'];
      return serarchPrefix(wrd,i+1);
    }

    return false;
  }
  bool serchWrd(string &wrd,int i=0){
    static tnode*ptr = Root;
    if(i >= wrd.size()){
      return ptr->isterminl;
    }else if(ptr->charMap[wrd[i]-'a']){
      ptr=ptr->charMap[wrd[i]-'a'];
      return serchWrd(wrd,i+1);
    }

    return false;
  }
  
  void levelOrder(){
    queue<tnode*>qq;
    qq.push(Root);
    int lev=0;
    while(qq.empty()==false){
     cout<<lev++<<" => ";
     int n=qq.size();
     for(int i=0;i<n;i++){
      tnode*ptr = qq.front(); qq.pop();
      if(ptr->isterminl) cout<<'.';
      cout<<ptr->data<<" ";
      for(int nbr=0;nbr<26;nbr++)
      {
       if(ptr->charMap[nbr]) qq.push(ptr->charMap[nbr]);
      }  
     }
     
     cout<<'\n';
    }
  }
  void dfs(){
    string wrd;
    for(int i=0;i<26;i++)
    {
     if(Root->charMap[i]) dfsHelp(Root->charMap[i],wrd);
    }
  }
  
  void setWrdCnt(){
    // static tnode*ptr=Root;
    for(int i=0;i<26;i++)
    {
     if(Root->charMap[i]) wrdCntHelp(Root->charMap[i]);
    }
  }
  void UNIQ_Prefixs(){
    string ans;
    for(int i=0;i<26;i++)
    { 
     if(Root->charMap[i]){
       ans.clear();
      UNIQ_PrefixsHELP(Root->charMap[i],ans);
     }
    }
  } 


  // this question asked by google to me ALL prefix sum of strings.
  int Prefx_SUM(){
    int ans=0;
    for(int i=0;i<26;i++)
    {
     if(Root->charMap[i]){
      ans+= Prefx_SUMHELP(Root->charMap[i]); 
     }
    }

    return ans;
  }

};
/*********************** End of modules ***************/

// Competitive way of making trie.
struct btn{
  int data;
  btn* child[2];
  bool isterminal;
    
  btn(){}
  btn(int x){data = x;
  child[0]=NULL;
  child[1]=NULL;
  isterminal=false;
  }

};
btn*root=new btn(-1);

int getNUM(string num){
  int sm=0;
  for(int i=31;i>=0;i--)
  {
  //  cout<<i<<"-"<<num[i]<<" "<<(1<<i)<<nl;
   if(num[i]=='1'){sm += (1<<(31-i));
   }
  }
  return sm;
}
string getBIT(int num){
  string s;
for(int i=0;i<32;i++)
{
 if(num&(1<<i)){
   s.push_back('1');
 }else s.push_back('0');
}
return s;
}
void insert(string num){
  btn*p=root;
  for(int i=31;i>0;i--)
  {
   if(p->child[num[i]-'0']){
    p=p->child[num[i]-'0'];
   }else{
    p->child[num[i]-'0']=new btn(num[i]-'0');
    p=p->child[num[i]-'0'];
   }
  }

  if(p->child[num[0]-'0']){
    // p->data=num[0]-'0';
    // p->isterminal = true;
    p->child[num[0]-'0']->isterminal = true;
   }else{
    p->child[num[0]-'0']=new btn(num[0]-'0');
    p->child[num[0]-'0']->isterminal = true;
   }

}
void dfs(btn*rt,string&num){
  if(rt==NULL) return;

  num.push_back(rt->data+'0');
  if(rt->isterminal) cout<<num<<" = "<<getNUM(num)<<nl;
  
  dfs(rt->child[0],num);
  dfs(rt->child[1],num);
  
  num.pop_back();
}
int getmaXOR(string snum){
  btn*p=root;
  string ans;
  for(int i=31;i>=0;i--)
  { if(snum[i]=='0'){
       if(p->child[1]){
         ans.push_back('1');
         p=p->child[1];
       }else{
        ans.push_back('0');
        p=p->child[0];
       }
    }else{
      if(p->child[0]){
        ans.push_back('1');
        p=p->child[0];
      }else{
        ans.push_back('0');
        p=p->child[1];
      }
    }
   
  }
  return getNUM(ans);
}








int main()
{
  mahi();

  int t;
  
  solve();
  // test();
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
  
  triee tree;
  tree.insert("cobra");
  tree.insert("cobred");
  tree.insert("dog");
  tree.insert("car");
  tree.insert("dove");
  tree.insert("duck");
  tree.insert("z");
  tree.insert("zar");
  tree.insert("q");
  
  // tree.levelOrder();
  tree.setWrdCnt();
  tree.dfs();
  tree.UNIQ_Prefixs();
  
  // cout<<tree.Prefx_SUM();
  
  // wr ="not";
  // cout<<tree.serchWrd(wr)<<nl;
 
  
}


void solve()
{
   
  ll t,k, n, var, m, x, p, a, b, c,d, y, i, j,V,E;
  string wrd="00001010", ans;
  var = 0;
  string s;
  char ch;
  cin>>n;
  vi vv(n);
  for( auto & x : vv ) cin>>x;
  // cout<<sizeof(int);
  // cout<<getNUM(wrd);
    insert(getBIT(vv[0]));
  // int ans=0;
  for( const auto & x : vv ){
    s=getBIT(x);
    var=getmaXOR(s);
    insert(s);
   cout<<x<<" ---- "<<var<<nl;

  //  cout<<x<<" "<<getBIT(x)<<nl;
  }

  // dfs(root->child[0],s);
  // dfs(root->child[1],s);
  

}