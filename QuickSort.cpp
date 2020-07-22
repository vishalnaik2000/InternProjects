//it is quicksort sort and randomized quicksort
//this algorithm can be used in order statistics also

#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int p,int q){
	int key = arr[p];			//simply select 1st element as pivot
	int i=p+1,j=p;
	while(i<=q ){
		if(arr[i]<=key){ j++; swap(arr[j],arr[i]); }
		i++;
	}
	swap(arr[j],arr[p]);
	return j;
}

int rand_partition(int arr[],int p,int q){  //to be used in randomized quick sort
	srand(time(NULL)); 				
	int ind = p + rand()%(q-p);   //choosing a random index between p and q
	swap(arr[ind],arr[p]);        //
	int key = arr[p];			  // 1st element is selected as pivot ( key )	
	int i=p+1,j=p;				  
	while(i<=q ){ 
		if(arr[i]<=key){ j++; swap(arr[j],arr[i]);}       //less than key are at left, greater than key are at ringht
		i++;
	}
	swap(arr[j],arr[p]);
	return j;
}
void Quicksort(int arr[],int p,int q){
	if(p>=q) return ;
	int r = partition(arr,p,q);
	Quicksort(arr,p,r-1);
	Quicksort(arr,r+1,q);
}
void rand_quicksort(int arr[],int p, int q){
	if(p>=q) return ;						//if it is a single or no elemts -> return
	int r = rand_partition(arr,p,q);        //generates a random partition of an 
	rand_quicksort(arr,p,r-1);				//recursively sort the two parts, as r position is fixed
	rand_quicksort(arr,r+1,q);
}

int main(){
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output2.txt", "w", stdout);
#endif

	int n ; cin>>n;
	int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
	rand_quicksort(arr,0,n-1);      
	for(int i=0;i<n;i++) cout<<arr[i]<<' ';
}