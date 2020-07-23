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
  #define vd vector<double>
  #define vvi vector<vector<int> >
  #define vvll vector<vector<ll> >
  #define vvc vector< vector<char> >
  #define f(i,j,n,k) for(int i=j;i<=n;i+=k)
  #define all(c) c.begin(),c.end()
  #define allr(c) c.rbegin(),c.rend()
  #define pb push_back
  #define endl '\n'
  #define hell 1000000007

  using namespace std;

//basic bfs, what makemytrip uses when finding flight from vadodara to varanasi


void bfs(unordered_map<int,vector<int> > nbrs,vi& dist,int s){
  queue<int> q; int u;      //generating queue for bfs
  q.push(s);      //obviously dist[s]=0
  while(!q.empty()){             
    u = q.front(); q.pop();           
    auto itr = nbrs[u].begin();      //take one node and bfs to all its nbrs
    while(itr!=nbrs[u].end()){
      if(dist[*itr]==-1){       //if it has not been set dist yet
        q.push(*itr);
        dist[*itr]=dist[u]+1;     //set dist = curr dist + 1 basically deciding layers 
      }
      itr++;
    }
  }
}
// complexity would be o(V + E) 

void solve(){ 
  int n ,m,u,v; cin>>n>>m;
  unordered_map<int,vector<int> > nbrs;
  f(i,1,m,1){
    cin>>u>>v;
    nbrs[u].pb(v); nbrs[v].pb(u);  //generating edge list
  }
  cin>>u>>v;        // start and end node
  vi dist(n+1,-1);  //every node is initially -1
  dist[u]=0;   //start dist is zero
  bfs(nbrs,dist,u);   //apply bfs from starting point
  cout<<dist[v];   //simply gives dist of end pont from start point
}

int main(){
  ifstream cin;
  ofstream cout;

      ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t=1;  //cin>>t;
    while(t--){
      solve();
      cout<<endl;
    }
}