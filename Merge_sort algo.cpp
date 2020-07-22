// Merge sorl algo give worts case time complexity of o(nlogn)
// one drawback is that is uses o(n) extra space.

#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m , int r);

void merge_sort(int arr[],int l, int r)
{
	if(l<r){ 						//do something only if size of array is >1
		int m = (l+r)/2;
		merge_sort(arr, l, m);		//dividing the current segment into left and right subsegments
		merge_sort(arr, m+1,r);
		merge(arr,l,m,r);			//merging the sorted left and right subsegments
	}
}
void merge(int arr[],int l,int m,int r)
{
	int t1[m-l+1],t2[r-m],ans[r-l+1];						//making two arrays
	for(int i=l;i<=m;i++) t1[i-l] = arr[i];					//from l to m and from m+1 to r
	for(int i=m+1;i<=r;i++) t2[i-(m+1)] = arr[i];			
	int i=0,j=0,k=0;
	while(i<sizeof(t1)/4 && j < sizeof(t2)/4){
		if(t1[i] < t2[j]){									//this loop merges the two sorted arrays
			ans[k]=t1[i]; i++;								//while maintaing the sort property
		}
		else{
			ans[k]=t2[j]; j++;
		}
		k++;
	}
	while(i<sizeof(t1)/4 ){
		ans[k]=t1[i]; i++; k++;				//these loops take care if one array is completed before other
	}
	while(j < sizeof(t2)/4){
		ans[k] = t2[j]; j++; k++;
	}
	for(int i=0;i<sizeof(ans)/4;i++){
		arr[l+i] = ans[i];					//copying the sorted array into our main array
	}
}

int main(){

#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output2.txt", "w", stdout);
#endif

	int n ;cin>>n;
	int arr[n];
	for(int i=0; i<n ; i++) cin>>arr[i];
	merge_sort(arr,0,n-1);                     //calling merge_sort function
	for(int i=0;i<n; i++) cout<<arr[i]<<' ';
	return 0;
}