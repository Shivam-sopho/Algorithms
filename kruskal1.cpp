/* ==========================chotu.kv============================*/
#include<bits/stdc++.h>
#define ll long long int
#define le(n) scanf("%d", &n)
#define out(n) printf("%d", n)
#define pb push_back()
/*Program to perform minimum spanning tree via "Kruskal Algorithm Part -I"(Without using stl)*/
using namespace std;
class disunion{
    public:
		vector<ll> size;
		vector <ll> v;
		disunion(ll n);// Utility function to carry out initialization process
        bool find(ll a,ll b);// Utility function to check the that 2 numbers are from same set or not
        ll root( ll a);// Find the root of the current element
		void union1( ll a , ll b);// Utility function to carry out the union process
};
disunion ::disunion(ll n)
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
void disunion :: union1(ll a, ll b){
	ll x = root(a);
	ll y = root(b);
	if(size[x] < size[y]){
		v[root(x)] = v[root(y)];
		size[y]+=size[x];
	}
	else{
		v[root(y)] = v[root(x)];
		size[x]+=size[y];
	}
}
class graph{
    public:
	    ll v,e;
	    vector < pair<ll,pair<ll,ll>> > adj;
	    void addEdge(ll a, ll b, ll w);
	    graph(ll v,ll e);
	    void kruskal();
};
graph :: graph(ll v,ll e)
{
	this->v = v;
	this->e = e;
	//adj = new list < pair<ll,ll> > [v+1];

}
void graph :: addEdge(ll a , ll b , ll w){
     adj.push_back({w, {a, b}});
}
void graph :: kruskal(){
    disunion d(v);
    ll cost = 0;
    sort(adj.begin(),adj.end());
	//list < pair<ll,ll> > :: iterator it;
	cout << "Edges in MST are :";
	for(auto it = adj.begin() ; it != adj.end(); it++)
	{

		ll x = it->second.first;
        ll y = it->second.second;
        if(!d.find(x,y)){
            cost+= it->first;

            d.union1(x,y);
            cout << x <<"--"<< y << endl;
        }

	}
	cout << "Minimum cost in MST is :" << cost << endl;
}
int main(){
    graph g(9,14);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.kruskal();
    return 0;

}

