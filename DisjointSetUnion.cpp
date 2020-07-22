//here is the implementation of Disjoint Set Union Data Structure ( class Based )

#include<bits/stdc++.h>
using namespace std;
class DSU
{
	vector<int> v;
	vector<int> rank;
	vector<int> parent;
public:
	void insert(int x)
	{   //building the set 
		v.push_back(x);
	}
	void makeset()
	{    //this function assigns rank and parents to each point/node
		for(int i=0;i<v.size();i++) parent.push_back(i);
		for(int i=0;i<v.size();i++) rank.push_back(0);
	}
	void return_parent(int i){ cout<<parent[i]; }
	int find(int i)
	{	//it does two things
		//1st it connects every node to its root, so height becomes 1
		//and then it return the parent of the required node
		//this is path compression method
		if(i != parent[i]) parent[i] = find(parent[i]);
		return parent[i];
	}
	void Union(int i,int j){
		//if they both have same parent, meaning both in same set, then no need to union
		int i_id = find(i);
		int j_id = find(j);
		if(i_id == j_id) return;
		//otherwise append the smaller tree to larger tree
		if(rank[i_id] < rank[j_id])
		{
			parent[i_id] = j_id;
		}
		else if(rank[i_id] > rank[j_id]) parent[j_id] = i_id;
		else{
			parent[i_id] = j_id;
			rank[j_id]++;
		}
	}
	void printparents()
	{	//just printing parents
		for(int i=0;i<v.size();i++) cout<<parent[i]<<" ";
			cout<<endl;
	}
	void showdata(int i){ cout<<v[i]<<endl;}
};

int main()
{
#ifndef ONLINE_JUDGE
      // or getting input from input.txt
      freopen("input.txt", "r", stdin);
      // for writing output to output.txt
      freopen("output2.txt", "w", stdout);
#endif
    DSU o1;
    int n,x; cin>>n;
    for(int i=0;i<n;i++) cin>>x, o1.insert(x);
    o1.makeset();
	o1.Union(2,4);
	o1.printparents();
	o1.showdata(5);
}