#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

/*
research
https://medium.com/basecs/going-broad-in-a-graph-bfs-traversal-959bd1a09255
*/

const int MAX_N = 10000;
const int MAX_M = 100000;
int graph[MAX_N + 1][MAX_N + 1]; // Adjacency matrix to store graph connections
int dist[MAX_N + 1]; // Array to store the shortest dist from node 1

// bfs
// finds the shortest path and stores it in the dist array
// this continues until the queue is empty
void findShortestPath(int n) {
    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) 
    {
        int current = q.front();
        q.pop();

        for (int i = 1; i <= n; ++i) {
            if (graph[current][i] && dist[i] == -1) 
            {
                dist[i] = dist[current] + 1;
                q.push(i);
            }
        }
    }
}

int main(){
    int t,n,m;
    cin >> t ;

    for(int i = 0; i < t; i++)
    {
 	    cin >> n >> m;
        //research
        memset(graph, 0, sizeof(graph));
        memset(dist, -1, sizeof(dist));


        for(int j = 0; j < m; j++)
        {
            int a, b;
            cin >> a >> b;

            //Graph is bidirectional as described in the source
            graph[a][b] = 1;
            graph[b][a] = 1;
        }

        findShortestPath(n);
        cout << dist[n] << endl;
    }
    return 0;

}
