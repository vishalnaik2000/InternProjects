//impementing trie data structure to generate phonebook
// trie datastructure gives the required info in o(length) time
// only backdrop is its storage requirement
// it requires o(alphabetSize * lengthOfKey * TotKeys) space

#include<bits/stdc++.h>
using namespace std;
static int alpha_size = 26;
struct TrieNode
{
	TrieNode* children[26]; 	//creating all its 26 children 
	bool isend;     			
public:
	TrieNode()
	{	//constructor, initializes the struct
		for(int i=0;i<26;i++) children[i]=NULL;
		isend = false;
	}
};

void insert(TrieNode* root,string key)
{	//inserting node and generating trie
	TrieNode* temp = root; int idx;
	for(int i=0;i<key.length();i++)
	{
		idx = key[i]-'a';     				//going to corresponding index
		if(temp->children[idx]==NULL)		
		{	//if child is not present, then create one
			temp->children[idx] = new TrieNode();
		}	//goint to next node(child node)
		temp = temp->children[idx];
	}
	temp->isend = true;  //marking the last character of the string as end
}

bool search(TrieNode* root,string s)
{
	TrieNode* temp = root; int idx;
	for(int i=0;i<s.length(); i++)
	{	//looking at corresponding index (children)
		idx = s[i]-'a';
		if(temp->children[idx]==NULL) return false;			//if that child is not present, then return false
		temp = temp->children[idx];
	}
	return temp->isend;			//if the last char is marked as end, return true
}

bool isempty(TrieNode* root)
{	//check weather this is leaf node or not
	for(int i=0;i<26;i++) if(root->children[i]) return false;
	return true;
}

TrieNode* del(TrieNode* root, string s,int depth)
{	//first of all, check if the string is present or not, in first call only
	if(depth==0){ if(!search(root,s)) return root;}
	if(depth==s.length())
	{	//when we reach to leaf node
		root->isend = false;		//works in case of the and there
		//delete leaf node
		if(isempty(root)) 
		{
			delete root;
			return NULL;
		}
		return root;
	}
	int idx = s[depth]-'a';
	root->children[idx] = del(root->children[idx],s,depth+1);	//recursively go to next char

	if(!root->isend && isempty(root)){
		delete root;			//if the curr node is leaf and it is not an end char
		root = NULL;			//then only you can delet it
	}
	return root;
}

int main()
{
#ifndef ONLINE_JUDGE
      // or getting input from input.txt
      freopen("input.txt", "r", stdin);
      // for writing output to output.txt
      freopen("output2.txt", "w", stdout);
#endif
    int n;cin>>n;
    vector<string> keys(n);
    for(int i=0;i<n;i++) cin>>keys[i];
    TrieNode* root = new TrieNode();
	//constructing the trie
	for(int i=0;i<n;i++) insert(root,keys[i]); 
    int q; cin>>q; string s;
	while(q--)
	{	//for search queires
		cin>>s;
		if(search(root,s)) cout<<"PRESENT"<<endl;
		else cout<<"NOT PRESENT"<<endl;
	}
	int toBeDeleted; cin>>toBeDeleted;
	while(toBeDeleted--){
		//keys that are to be deleted from trie
		cin>>s;
		root = del(root,s,0);
	}
	cin>>q;
	while(q--){
		//again search quries after performing del operations
		cin>>s;
		if(search(root,s)) cout<<"PRESENT"<<endl;
		else cout<<"NOT PRESENT"<<endl;
	}
	return 0;
}