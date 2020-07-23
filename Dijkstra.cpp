  #include<bits/stdc++.h>
  //
  #define ll long long
  #define si set<int> 
  #define siitr set<int>::iterator
  #define scit set<char>::iterator
  #define mp make_pair
  #define vi vector<int>
  #define vs vector<string>
  #define vll vector<long long>
  #define vc vector<char>
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
// shortest path for weighted graph

void dijkstra( unordered_map<int,vector<pair<int,int> > > & nbrs, int s, vi& dist, vb& visited){
   priority_queue<pi, vector<pi>, greater<pi> > H; //creating a min heap, remember the syntax 

  H.push(mp(dist[s],s));       //we want to extract min using dist, so we put that first
  int d,u;  
  while(!H.empty()){
    d = H.top().first; u = H.top().second; H.pop();     //curr node and its distance from the original start node
    if(visited[u]) continue;  //if this node is already visited, then continue
    visited[u]=true;     //mark this node as visited and explore its nbrs
    auto itr = nbrs[u].begin();
    while(itr!=nbrs[u].end()){                   
      if(dist[itr->first] > d + itr->second){       //basically here we are updating distance of its nbrs       
        dist[itr->first] = d + itr->second; 
        H.push(mp(dist[itr->first],itr->first));     //pushing new distance 
      }
      itr++;
    }
  }
}
// complexity o( V + E*logV) something of this sort

void solve(){ 
  int n,m,u,v,w; cin>>n>>m;
  unordered_map<int,vector<pair<int,int> > > nbrs;
  f(i,1,m,1){
    cin>>u>>v>>w;
    nbrs[u].pb(mp(v,w));       //see here we used pairs to store weights also
  }
  cin>>u>>v;  //starting node, ending node(like vadodara to varanasi)
  vb visited(n+1,false);
  vi dist(n+1,INT_MAX); dist[u]=0;
  dijkstra(nbrs,u,dist,visited);
  if(dist[v]==INT_MAX) cout<<-1;
  else cout<<dist[v];
}

int main(){

  #ifndef ONLINE_JUDGE
      // or getting input from input.txt
      freopen("input.txt", "r", stdin);
      // for writing output to output.txt
      freopen("output.txt", "w", stdout);
  #endif

    int t=1;  //cin>>t;
    while(t--){
      solve();
      cout<<endl;
    }
}