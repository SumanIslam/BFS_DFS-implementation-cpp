#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+2;
bool vis[N];
vector<int> adj[N];

void dfs(int s);

int main()
{
  for(int i=0; i<=N; i++)
  {
    vis[i] = 0;
  }

  // n means number of vertices/nodes, e means number of edges
  int n,e;
  
  // taking the number of vertices/nodes from the user
  cout<<"Enter the number of nodes: ";
  cin>>n;
  cout<<"Enter the number of edges: ";
  cin>>e;

  int x,y;
  // taking edges from the user
  cout<<"Enter the edges with source and target vertex: "<<endl;
  for (int i = 0; i < e; i++)
  {
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  // s means starting node
  int s;
  // take starting vertex/node from the user
  cout<<"Enter the starting vertex: ";
  cin>>s;

  cout<<"The DFS traversal is: ";
  
  dfs(s);

  return 0;
}

void dfs(int s)
{
  stack<int>st;
  st.push(s);
  vis[s] = true;
  while (!st.empty())
  {
    int node = st.top();
    st.pop();
    cout<<node<<" ";

    for(int i=0; i<adj[node].size(); i++)
    {
      if(!vis[adj[node][i]]) {
        st.push(adj[node][i]);
        vis[adj[node][i]] = true;
      }
    }
  }
}