#include <iostream>
#include <vector>
#include <queue>
#include <climits>  // For INT_MAX
using namespace std;

typedef pair<int, int> pii;

void dijkstra(int src, vector<vector<pii> >& adjList, int V) {
    // Priority queue to store vertices based on their shortest distance from src
    priority_queue<pii, vector<pii>, greater<pii> > pq;

    // Vector to store the shortest distance from src to each vertex
    vector<int> dist(V, INT_MAX);

    // Start with the source vertex (distance is 0)
    dist[src] = 0;
    pq.push(pii(0, src));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Traverse all adjacent vertices of the extracted vertex
        for (vector<pii>::iterator it = adjList[u].begin(); it != adjList[u].end(); ++it) {
            int v = it->first;
            int weight = it->second;

            // If there is a shorter path to v through u
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(pii(dist[v], v));
            }
        }
    }

    // Print the shortest distances from the source vertex
    cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<pii> > adjList(V);

    // Add edges to the adjacency list (u, v, weight)
    adjList[0].push_back(pii(1, 10));
    adjList[0].push_back(pii(4, 5));
    adjList[1].push_back(pii(2, 1));
    adjList[1].push_back(pii(4, 2));
    adjList[2].push_back(pii(3, 4));
    adjList[3].push_back(pii(0, 7));
    adjList[3].push_back(pii(2, 6));
    adjList[4].push_back(pii(1, 3));
    adjList[4].push_back(pii(2, 9));
    adjList[4].push_back(pii(3, 2));

    int source = 0; // Source vertex
    dijkstra(source, adjList, V);

    return 0;
}
