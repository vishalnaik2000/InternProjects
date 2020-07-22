//inplement priority queues and heap sort
//max heap has a property that every parent is atleast their child
//worst case time complexity o(nlogn), space complexity o(1)

#include<bits/stdc++.h>
using namespace std;

int leftchild(int i){ return 2*i;} 
int rightchild(int i) {return 2*i+1; }   //functions returning parents and children of a given node
int parent(int i)  { return i/2; }

//helps in building max heap
void shiftdown(int arr[],int i,int size){
	int maxindex = i,l,r;
	l = leftchild(i);  r = rightchild(i);
	if(l<=size && arr[l]>arr[maxindex]) maxindex = l;
	if(r<=size & arr[r]>arr[maxindex]) maxindex = r; 
	//basically in above step, we are finding its maximum child
	if(i!=maxindex){         //if a child has greater value then this node, then swap
		swap(arr[i],arr[maxindex]); 
		shiftdown(arr,maxindex,size);
	}
}
// builds a max heap out of the given array
void buildheap(int arr[],int size){
	for(int i=size/2;i>=1;i--){
		shiftdown(arr,i,size);
	}
}

void Heapsort(int arr[],int size){
	//from 1 to size
	buildheap(arr,size);  //converts the given array into a heap
	int tempsize = size;
	for(int i=1;i<size;i++){
		swap(arr[1],arr[tempsize]);
		tempsize--;                      //sorting the array in O(1) space
		shiftdown(arr,1,tempsize);
	}
}

int main(){
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output2.txt", "w", stdout);
#endif

	int n; cin>>n;          
	int arr[n+1]={-1};
	for(int i=1;i<=n;i++) cin>>arr[i];    //taking array input
	Heapsort(arr,n);
	for(int i=1;i<=n;i++) cout<<arr[i]<<" "; cout<<endl;
}