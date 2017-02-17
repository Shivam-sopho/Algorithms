/* ==========================chotu.kv============================*/
#include<bits/stdc++.h>
#define ll long long int
#define le(n) scanf("%d", &n)
#define de(n) printf("%d", n)
#define pb push_back
#define inf INT_MAX
#define minf INT_MIN
#define fast ios_base::sync_with_stdio(false);
using namespace std;
/* Implementation of heap via the class concepts of c++ i.e Implementation of min heap*/
class minheap{
    vector<ll> heap ;// Stores the element of the heap
	ll n;// Maximum capacity of the heap
	ll currsize;// Stores the value of the current size of the heap
	public:
        minheap(ll n);// Initialize the value of initial capacity of the heap
	    void MinHeapify(ll i );// Utility function to carry out the heapify property along each subtree of the tree
        ll getmin(){return (heap[0]);};// Utility function to get the minimum element of the heap tree
        ll extractmin(); // Extracts the minimum element of the heap tree and then deletes it from the tree
		void deletekey(ll i);// Delete the element at the given index of the tree
		void insertkey(ll i);// Insert new element of the given value in the heap
		void decreasekey(ll i, ll new_val); // Decrease the key with a new value (given ) in the heap
		int parent(ll i){return((i-1)/2);}// Returns the parent of the given index
		ll left(ll i){return(2*i + 1);};//Returns the left child of the given index
	    ll right(ll i){return (2*i + 2);}// Returns the right child of the given index
};
minheap:: minheap(ll n)
{
   this->n = n;
   heap.resize(n+1);
   currsize=0;
}
void minheap :: insertkey(ll i){
    if(currsize==n){
        cout << "Capacity is full" << endl;
		return;
	}
	currsize++;
	ll j = 0;
	j = currsize-1;
	heap[j] = i;
    /*Fixing the heap property if violated*/
    while(j != 0 && heap[parent(j)] > heap[j]){
        swap(heap[j],heap[parent(j)]);
        j = parent(j);
    }
}
void minheap :: decreasekey(ll i , ll new_val){
	heap[i] = new_val;
	/* Again fixing the property of the heap if violated */
	while(i != 0 && heap[parent(i)] > heap[i]){
    	swap(heap[i],heap[parent(i)]);
        i = parent(i);

	}

}
ll minheap :: extractmin(){
	if(currsize == 0){
		return minf;
	}
	else if(currsize == 1){
    	currsize--;
    	return heap[0];
	}
	else{
		ll root = heap[0];
		heap[0] = heap[currsize - 1];
		currsize--;
		MinHeapify(0);
		return root;
	}
}
void minheap :: deletekey(ll i){
	decreasekey(i , minf);// Makes that element as the root of the heap
	extractmin();// Deletes the root the heap tree
}
void minheap :: MinHeapify(ll i){
	ll lef = left(i); // Left child of the heap
	ll r = right(i); // Right child of the heap
	ll smallest = i;
	if(lef < currsize && heap[lef]< heap[i]){
    	smallest = lef;
	}
	if(r < currsize && heap[r] < heap[smallest])
		smallest = r;
	if(smallest != i){
    	swap(heap[i],heap[smallest]);
	    MinHeapify(smallest);
	}
}
int main(){
    minheap h(11);
    h.insertkey(3);
    h.insertkey(2);
    h.deletekey(1);
    h.insertkey(5);
    h.insertkey(4);
    h.insertkey(45);
    cout << h.extractmin() << " ";
    cout << h.getmin() << " ";
    h.decreasekey(2, 1);
    cout << h.getmin();
    return 0;
}

