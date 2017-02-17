/* ==========================chotu.kv============================*/
/*Prims Algorithm when we are using matrix representation of the graph(Without using stl of c++)*/
#include<bits/stdc++.h>
#define ll long long int
#define le(n) scanf("%d", &n)
#define out(n) printf("%d", n)
#define pb push_back
#define INF  LONG_MAX
#define mINF  INT_MIN
using namespace std;
#define v 5
/* Utility function to find the next minimum element of the remaining edges*/
ll minkey(ll key[],bool mst[]){
	ll max = LONG_MAX, min_element = 0;
	for(ll i = 0 ; i < v; i++){
	    if(mst[i]== false && key[i]<max)
			max = key[i], min_element = i;
			//cout << i << endl;
	}
	//cout << min_element;
	return min_element;

}
/* Utility function to print the edged included in the prims algo*/
void printprim(ll parent[],ll graph[v][v],ll key[]){
    for(ll i = 1 ; i < v; i++){
        cout << parent[i] <<"--"<< i << "  " << key[i] << endl;
	}
}
/* Utility function to perform the prims algoritm*/
void primalgo(ll graph[v][v]){
	ll key[v+1];
	bool mstset[v+1];
	memset(mstset,false,sizeof(mstset));
	for(ll j = 0 ; j < v ; j++)
        key[j]= LONG_MAX;
    ll parent[v+1];
	parent[0]= -1;
	key[0] = 0;
    for(ll i = 0 ; i < v-1 ; i++){
        ll u = minkey(key,mstset);

		mstset[u]=true;
		for(ll j = 0 ; j < v ; j++){
			if(graph[u][j] && mstset[j]==false && graph[u][j]<key[j]){
			    key[j]=graph[u][j] ;
				parent[j]=u;
			}
   	}
    }
    printprim(parent,graph,key);

}


int main(){
   ll graph[v][v] = { {0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

    // Print the solution
    primalgo(graph);

   return 0;
}

