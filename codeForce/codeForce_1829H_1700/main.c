// # Url: https://codeforces.com/problemset/problem/1829/H
//  buildin_popcount: https://blog.csdn.net/github_38148039/article/details/109598368
#include<bits/stdc++.h>
using namespace std;
 
const int mod=1e9+7;
 
void sol(){
	int n,k;
	cin>>n>>k;
	
	vector<int>a(n+1),dp(64,0);
	for(int i=1;i<=n;i++) cin>>a[i];
 
	for(int i=1;i<=n;i++){
		for(int j=0;j<64;j++)
			(dp[a[i]&j]+=dp[j])%=mod;
		dp[a[i]]++;
	}
 
	int ans=0;
	for(int i=0;i<64;i++){
		if(__builtin_popcount(i)==k) (ans+=dp[i])%=mod;
	}
 
	cout<<ans<<'\n';
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int T;cin>>T;
	while(T--)
		sol();
 
	return 0;
}