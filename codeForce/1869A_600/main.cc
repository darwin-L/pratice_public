#include<bits/stdc++.h>

using namespace std;

#define fo(i,n) for(i=0;i<n;i++)
#define rep(i,a,b) for (int i=(int)(a);i<(int)(b);i++)
using namespace std;
typedef vector<int> vi;

inline int nxt() {
  int x;
  cin >> x;
  return x;
}

//============================
void solve(){
    int i,j,n,m;
    n = nxt();
    vi arr(n); 
    rep(i,0,n){
        cin>>arr[i];
    }
    if(n%2==0){
        cout<<2<<"\n";
        cout<<1<<" "<<n<<"\n";
        cout<<1<<" "<<n<<"\n";
    }
    else{
        cout<<4<<"\n";
        cout<<1<<" "<<n<<"\n";
        cout<<1<<" "<<n-1<<"\n";
        cout<<n-1<<" "<<n<<"\n";
        cout<<n-1<<" "<<n<<"\n";
    }
}
 
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t=1;
    t = nxt();
    while(t--){
        solve();
    }
    return 0;
}