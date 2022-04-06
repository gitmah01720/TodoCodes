#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef  long int li;
typedef  long long int lli;
typedef unsigned long long int ulli;
#define all(x) (x).begin(), (x).end()
#define INF 1e18
#define nl '\n'
#define ll long long


// https://www.codechef.com/START33C/problems/STBMEX

 

int selectExcept(char ch){
  switch (ch)
  {
  case 'a':
     return 'e';
    break;
  
  case 'b':
     return 'e';
     
    break;
  
  case 'c':
     return 'e';
     
    break;
  
  case 'd':
     return 'e';
     
    break;
  
  case 'e':
     return 'a';
     
    break;
  }
  return 'a';


  /*write this in main:
  int od,n,ev,x,ans,t,m;
cin>>t;
string s,a;
map<int,char>mpp;
mpp[0] = 'a';
mpp[1] = 'b';
mpp[2] = 'c';
mpp[3] = 'd';
mpp[4] = 'e';
while(t--){
  cin>>n>>m;
  cin>>s>>a;
  int j=0;
  // cout<<s<<' '<<a;
  if(m==1){
    if(s.find(a)) cout<<-1<<'\n';
    continue;
  }
  

  for(int i=0;i<n;i++)
  {
   if(s[i]==a[j]){
      j++;
      if(j==m) break;
   }
   else if(s[i]=='?'){
        s[i] = selectExcept(a[j]);
        // cout<<a[j]<<' ';
   }else{
      continue;
   }
  }
  
  
  if(j==m) cout<<-1<<nl;
  else cout<<s<<'\n';
 
}
*/
}

long long solve(int*ar,int n){
  if(ar[0]!=0) return ar[0]-1;
  int l,r;
  
  vi uniq;
  uniq.push_back(0);
  int shouldbe = 0;

  for(int i=0;i<n;i++){
    if(ar[i]==uniq.back()) continue;
    uniq.push_back(ar[i]);
  } 
  
  n= uniq.size();
  // skipp the first continuous sequence. and find x
  l=0;
  int x=0,k=0;
  shouldbe = 0;
  for(int i=0;i<n && l<n;i++)
  {
   if(uniq[i]==shouldbe){
    x++;
    shouldbe++;
    l=i;
   }else break;

  }
  // cout<<x<<' '<<l<<' '<<n<<' ';
  

  if(x==1) return -1;    // because we have always 0 and x will be 1 except at polls
  else if(l>=n-1) return 0; // we have read all input;
  // for each continuousSequence of len >= X-1 k++;
  l++;
  int cnt = 0;
  
  // cout<<x<<' ';
  shouldbe = uniq[l]; // we are now going to start finding a continuous segment
  while (l<n)
  { cnt =0;
    shouldbe =uniq[l];
  for(;l<n;l++)  {
  if(uniq[l]==shouldbe++) cnt++;
  else break;
  }
  
  if(cnt >= x-1) k++;
  }
  return k;
}
int main()
{

#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
int od,n,ev,x,ans,t,m;
cin>>t;

while(t--){
  cin>>n;
  int ar[n];
  for(int i=0;i<n;i++) cin>>ar[i];
  sort(ar,ar+n);
  cout<<solve(ar,n)<<'\n';
  // for(int i=0;i<n;i++)
  // {
  //  cout<<ar[i]<<' ';
  // }
  // cout<<nl;
}

return 0;
}

/*

cin>>n;
  cin>>s;
  bool allzeors = true;
  bool anyadjacent1 = false;
  for(int i=0;i<n-1;i++)
  { 
   if(s[i]=='1'){
     allzeors = false;
     if(s[i+1] == '1') {
     anyadjacent1 = true;
     break;
     }
   }
  }
  if(n==1 && s[0]=='1') g=1;
  else if(allzeors) g = 0;
  else{
    if(anyadjacent1) g=2;
    else g=1;
  }
 cout<<g<<'\n';
*/