  #include<bits/stdc++.h>
  //
  #define ll long long
  #define F first
  #define S second
  #define vi vector<int>
  #define vb vector<bool>
  #define vvi vector<vector<int> >
  #define vvll vector<vector<ll> >
  #define vvc vector< vector<char> >
  #define f(i,j,n,k) for(int i=j;i<=n;i+=k)
  #define all(c) c.begin(),c.end()
  #define allr(c) c.rbegin(),c.rend()
  #define pb push_back
  #define endl '\n'
  #define hell 1000000007
#define pi pair<int,int>  
  using namespace std;
ll gcd(ll a,ll b){if(b==0) return a; else return gcd(b,a%b); }

//time complexity is o(nlogn) 

int findf(int i,vi& parent){
  if(i!=parent[i]) parent[i]=findf(parent[i],parent);  //this step basically connects all leafs to root.
  return parent[i];
}
void unionf(int u,int v,vi& parent){
  parent[u]=findf(u,parent);
  parent[v]=findf(v,parent);
  parent[parent[v]]=parent[u];   //simple union operation.
}
void kruskal(vector<vector<double> >& edges,vi& parent){
  int idx = 0; int u,v; double d,ans=0;
  while(idx!=edges.size()){
    d = edges[idx][0]; u=edges[idx][1]; v=edges[idx][2];
    if(findf(u,parent)!=findf(v,parent)){
      ans+=d;
      unionf(u,v,parent);
    }
    idx++;
  }
  cout<<fixed<<setprecision(9)<<ans;
}

void solve(){ 
  int n ;cin>>n;
  vector<pair<double,double> > points(n+1);
  for(int i=1;i<=n;i++){
    cin>>points[i].F>>points[i].S; //points
  }
  double di;
  vector<vector<double> > edges;
  for(int i=1;i<=n;i++){
    for(int j=i+1;j<=n;j++){
      di = sqrt(pow(points[j].F-points[i].F,2)+pow(points[j].S - points[i].S,2));
      edges.pb({di,double(i),double(j)});    //dist between points i & j
    }
  }
  vi parent(n+1,0); f(i,1,n,1) parent[i]=i;
  sort(all(edges));  //sorting the edges, as we take min. edge which does not form a cycle
  kruskal(edges, parent);

}

int main(){

  #ifndef ONLINE_JUDGE
      // or getting input from input.txt
      freopen("input.txt", "r", stdin);
      // for writing output to output.txt
      freopen("output.txt", "w", stdout);
  #endif 

      ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;  //cin>>t; 
    while(t--){
      solve();
      //cout<<endl;
    }
}

//below is prim's algorithm

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
#include <bits/stdc++.h>

#define pii pair<int,int>
int spanningTree(int V, int E, vector<vector<int>> &graph) {
    //cout<<graph.size()<<endl;
    int mn=INT_MAX, u,v;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(graph[i][j] < mn){
                mn = graph[i][j], u=i,v=j;
            }
        }
    }
    bool check[V];
    memset(check,false,sizeof(check));
    check[u]=true; check[v]=true;
    priority_queue<pii, vector<pii>, greater<pii> > H;
    for(int i=0;i<V;i++){
        if(graph[u][i]!=INT_MAX && !check[i]) H.push(make_pair(graph[u][i],i));
        if(graph[v][i]!=INT_MAX && !check[i]) H.push(make_pair(graph[v][i],i));
    }
     int cnt = 2, ans = mn,d;
    while(cnt<V){
       d = H.top().first; u = H.top().second; H.pop();
       if(check[u]) continue;
       ans+=d; check[u]=true; cnt++;
       for(int i=0;i<V;i++){
            if(graph[u][i]!=INT_MAX && !check[i]) H.push(make_pair(graph[u][i],i));
       }
    }
    return ans;
}