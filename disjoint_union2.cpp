/* ==========================chotu.kv============================*/
/* Union -2 part2 (using the concept of path compression*/
#include<bits/stdc++.h>
#define ll long long int
#define le(n) scanf("%d", &n)
#define out(n) printf("%d", n)
#define pb push_back()
using namespace std;
class disunion{
    public:
		vector<ll> size;
		vector <ll> v;
		disunion(n);// Utility function to carry out initialization process
        bool find(ll a,ll b);// Utility function to check the that 2 numbers are from same set or not
        ll root( ll a);// Find the root of the current element
		void union( ll a , ll b);// Utility function to carry out the union process
};
disunion ::disunion(n)
{		
	size.resize(n+1);
	v.resize(n+1);
	for(ll i = 0 ; i <= v.size(); i++)
	{
		v[i] = i;
		size[i]=1;
	}
}
bool disunion :: find (ll a,ll b){
	if(root(a)==root(b))
		return true;
	else
		return false;
}
ll disunion :: root(ll a){
	while(v[a]!=a){
		v[a]=v[v[a]];
		a=v[a];
	}
    return a;
}
void disunion :: union(ll a, ll b){
	ll x = root(a);
	ll y = root(b);
	if(size(x) < size(y)){
		root(x) = root(y);
		size(y)+=size(x);
	}
	else{
		root(y) = root(x);
		size(x)+=size(y);
	}
}
int main()
{
	 

	
}

