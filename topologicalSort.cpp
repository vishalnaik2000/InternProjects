  #include<bits/stdc++.h>
  //
  #define ll long long
  #define mp make_pair
  #define vi vector<int>
  #define f(i,j,n,k) for(int i=j;i<=n;i+=k)
  #define all(c) c.begin(),c.end()
  #define pb push_back
  #define endl '\n'
  #define hell 1000000007

  using namespace std;
//output the topological sort of the given DAG
// topological sort meaning relative order between two vertices
//like if A->B then you have to do A before B, then A comes before B in topological sort

int cc=1;     //it will be required to give post order numbers

void explore( unordered_map<int,vector<int> > & nbrs, vvi& post,int u){
  auto itr = nbrs[u].begin();      
  while(itr!=nbrs[u].end()){
    if(post[*itr][0]== -1) explore(nbrs,post,*itr);    //if it's post order is -1 meaning do dfs from this point.
    itr++;
  }
  post[u][0]=cc; post[u][1]=u;   //remembering numbers and post, because we have to sort at last, so we can not rely on index
  cc++;
}

// again complexity will be o(V + E)

int main(){

#ifndef ONLINE_JUDGE
      // or getting input from input.txt
      freopen("input.txt", "r", stdin);
      // for writing output to output.txt
      freopen("output.txt", "w", stdout);
#endif
 
   
   int n ,m,u,v ;cin>>n>>m;
   vb source(n+1,true);         //to find the source, because we will start our topological sort from the source
   vvi post(n+1,vi(2,-1));     //keeping track of post order traversal
   unordered_map<int,vector<int> > nbrs;  
   for(int i=1;i<=m;i++){
    cin>>u>>v; source[v]=false; // v is not the source as en edge is going to v
    nbrs[u].pb(v);
   }
   for(int i=1;i<=n;i++){
      if(source[i]){             // exporing all the sources
        explore(nbrs,post,i);
      }
   }
   sort(all(post));
   for(int i=n;i>0;i--) cout<<post[i][1]<<" ";
   return 0;
}