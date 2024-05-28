    #include<bits/stdc++.h>
    using namespace std;
    int b[2000000];
    int main(){
    	ios::sync_with_stdio(false),cin.tie(0);
    	int T,n,i,j;
    	for(cin>>T;T>0;T--)
    	{
    		cin>>n;
    		for(i=0;i<n*(n-1)/2;i++)cin>>b[i];
    		sort(b,b+n*(n-1)/2);
    		j=n-1;
    		for(i=0;j>0;i+=j,j--)cout<<b[i]<<' ';
    		cout<<1000000000<<' ';
    		cout<<'\n';
    	}
    	return 0;
    }