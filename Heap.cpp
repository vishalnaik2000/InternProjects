// implementing heap data structure.
//starting index is 1
// it can perform following operations.
// push, getmax/top() , pop

#include<bits/stdc++.h>
using namespace std;

int leftchild(int i){ return 2*i;} 
int rightchild(int i) {return 2*i+1; }   //functions returning parents and children of a given node
int parent(int i)  { return i/2; }
int size,n;

void shiftdown(int arr[],int i){
	int maxindex = i,l,r;
	l = leftchild(i);  r = rightchild(i);
	if(l<=size && arr[l]>arr[maxindex]) maxindex = l;
	if(r<=size & arr[r]>arr[maxindex]) maxindex = r; 
	//basically in above step, we are finding its maximum child
	if(i!=maxindex){         //if a child has greater value then this node, then swap
		swap(arr[i],arr[maxindex]); 
		shiftdown(arr,maxindex);
	}
}
void shiftup(int arr[], int i)
{
	while(i>1 && arr[parent(i)] < arr[i])
	{
		swap(arr[parent(i)],arr[i]);
		i = parent(i);
	}
}

void getmax(int arr[]){
	cout<<arr[1]<<endl; return;
}
void pop(int arr[]){
	arr[1]=arr[size];
	size--;
	shiftdown(arr,1);
}
void change_priority(int arr[], int idx,int p)
{
	int old_p = arr[idx];
	arr[idx] = p;
	if(p > old_p) shiftup(arr,idx);
	else shiftdown(arr,idx);
}
void buildheap(int arr[]){
	for(int i=size/2; i>0; i--){
		shiftdown(arr,i);
	}
}
void push(int arr[], int val){
	size++;
	arr[size] = val;
	shiftup(arr,size);
}
int main(){

#ifndef vishal
	freopen("input.txt","r",stdin);
	freopen("output2.txt","w",stdout);
#endif

	cin>>n; size = n;
	int arr[2*n+1];
	for(int i=1;i<=n;i++) cin>>arr[i];
	buildheap(arr);      //builds heap
	getmax(arr);		 //teturns max element, just like top() function
	pop(arr);			 //pops the element with highest priority. like pop() function
	change_priority(arr,2,25);      //this is an addtional function.
	getmax(arr);
	push(arr,100);
	getmax(arr);
}