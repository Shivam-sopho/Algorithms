/* ==========================chotu.kv============================*/
#include<bits/stdc++.h>
#define ll long long int
#define le(n) scanf("%d", &n)
#define out(n) printf("%d", n)
#define pb push_back
/* Union-1 part (without using the path compression technique*/
using namespace std;
class disjoint_union{
    public:
		ll size;
		disjoint_union(ll size);// initializing the size of the parent vector
		void union1(ll a , ll b);// utiliy function to find the union of 2 sets
        ll root(ll a);// function to find the root of a particular element
		vector <ll> vp;// parent vector of the graph

};
disjoint_union :: disjoint_union(ll size)
{
	this->size = size;
        vp.resize(size+1);
	//memset(vp,-1,size);
        for(ll i = 0 ; i <= size ; i++){
          vp[i]=-1;
        }
}
void disjoint_union :: union1(ll a , ll b){
	ll x = root(a);
	ll y = root(b);
	vp[x] = y;
}
ll disjoint_union :: root(ll a){
  if(vp[a]==-1)
  {
     // cout << a;
return a;
  }
    return(root(vp[a]));
}
class graph
{
	public:
          ll v ;
		  vector <ll> *adj;//creating the adjacency list
		  graph(ll v);
		  void addedge(ll a, ll b);      // function to add edge in graph
		  ll iscycle();//Utility function to check if there is a cycle in a graph


};
graph :: graph(ll v){
	this->v = v;
	adj = new vector <ll> [v+1];
}
/* adding an edge in directed*/
void graph::addedge(ll a , ll b)
{
	adj[a].pb(b);
	//adj[b].pb(a);

}
ll graph ::iscycle(){
	disjoint_union du(v);
	bool visited[v];

    for(ll i = 0 ; i <v ;i++){

		for(auto j = adj[i].begin() ; j!=adj[i].end();j++)
		{


            	ll x = du.root(i);
				ll y = du.root(*j);
				if(x == y)
					return 1;
                du.union1(x,y);

		}
		}
return 0;
}
int main(){
	ll n = 3;
	graph g(n);
    g.addedge(0,1);
   g.addedge(0,2);
	g.addedge(1,2);
	if(g.iscycle()==1)
		cout << "yes contains cycle " <<endl;
	else
		cout << "no cycle" << endl;
return 0;
}

