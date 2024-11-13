#include <bits/stdc++.h>
using namespace std;

int bellmanford(int n , int m , int src, int dest, vector<vector<int>> edge);

int main(){
    int n, src, dest;

    cout<<"Enter the number of nodes"<<endl;
    cin>>n;

    int m = n-1 ;

    cout<<"Enter the source:";
    cin>>src;

    cout<<"Enter the destination:";
    cin>>dest;

    vector<vector<int>> edge;

    for(int i= 0; i< n; i++){
        cout<<"Enter the start node, end node and weight between them:";
        int p,q,r;
        cin>>p>>q>>r;
        edge.push_back({p,q,r});
    }

    int ans = bellmanford(n,m,src,dest,edge);
    cout<<"The minimum distance between "<<src<<" and "<<dest<<" is "<<ans<<endl;
    return 0;
}

int bellmanford(int n , int m , int src, int dest, vector<vector<int>> edge){
    vector<int> dist(n+1, 1e9);
    dist[src] = 0;

    for(int i =1; i<=m; i++){
        for(int j= 0; j < n; j++){
            int u = edge[j][0];
            int v = edge[j][1];
            int w = edge[j][2];

            if(dist[u] != 1e9 && ((dist[u] + w) < dist[v]))
                dist[v] = dist[u] + w;
        }
    }
    return dist[dest];
}
