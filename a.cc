#include<bits/stdc++.h>
using namespace std;
long long T,a,b,n,t;
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&a,&b,&n);
		for(int i=1;i<=n;++i) scanf("%lld",&t),b+=min(a-1,t);
		printf("%lld\n",b);
	}
	return 0;
}