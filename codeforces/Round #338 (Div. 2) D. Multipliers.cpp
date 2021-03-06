#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll p(ll a,ll b,ll m)
{
	ll t=1;
	while(b>0)
	{
		if(b&1)t*=a;
		t%=m;
		a*=a;
		a%=m;
		b>>=1;
	}
	return t;
}

int main()
{
	int n;
	cin>>n;
	map<ll,ll> a;
	ll x;
	for(int i=0;i<n;++i)
	{
		scanf("%lld",&x);
		a[x]++;
	} 
	ll sum=1;
	ll ans=1;
	ll cnt=1;
	map<ll,ll>::iterator it;
	for(it = a.begin();it!=a.end();++it)
	{
		ll X=it->first;
		ll Y=it->second;
		cnt=p(X,(Y*(Y+1))/2,mod);
		ans=(p(ans,(Y+1),mod)*p(cnt,sum,mod))%mod;
		sum=sum*(Y+1)%(mod-1);
	}
	cout<<ans<<endl;
	return 0;
}
