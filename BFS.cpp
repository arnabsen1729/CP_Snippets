#include<bits/stdc++.h>
using namespace std;
/*  BFS
    int n:              number of edges
    vector<bool> vis:           to mark a node visited
    vector<int> level:        to determine the level of a node
    vector<int> edge[]: adjacency list implementation

    N.B we can avoid using vis and rather use the level array
    to determine if a node is visited or not. we can initialise
    all the nodes by -1 and then when it is visited we will assign
    the level then we can check for that too

*/

//-----------------------------------------------------


void bfs(int s, vector<bool> &vis, vector<int> &level, vector<int> edge[]){
    queue<int> q;
    q.push(s);
    level[s]=1;
    vis[s]=true;
    while(!q.empty()){
        int p=q.front();
        q.pop();
        for(int i=0; i<edge[p].size(); i++){
            if(vis[edge[p][i]]==false){
                level[edge[p][i]]=level[p]+1;
                q.push(edge[p][i]);
                vis[edge[p][i]]=true;
            }
        }
    }
}

//-----------------------------------------------------


main(){

    int n;
    cin>>n;
    vector<int> edge[n];
    vector<int> level(n, 0);
    vector<bool> vis(n, false);
    for(int i=0; i<n-1; i++){
        int a, b;
        cin>>a>>b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    bfs(0, vis, level, edge);

    return 0;
}
