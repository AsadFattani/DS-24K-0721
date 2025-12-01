#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int V;
    int **adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new int*[V];
        for(int i = 0; i < V; i++) {
            adj[i] = new int[V];
            for(int j = 0; j < V; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void print() {
        for(int i = 0; i < V; i++) {
            cout << i << " --> ";
            for(int j = 0; j < V; j++) {
                if(adj[i][j] == 1) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }

    ~Graph() {
        for(int i = 0; i < V; i++) {
            delete [] adj[i];
        }
        delete [] adj;
    }
};
//the adjacency matrix is represented as a 2D array of integers
int main() {
    Graph g(5);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 0);
    g.addEdge(3, 1);
    g.addEdge(4, 2);
    g.addEdge(0, 2);
    g.addEdge(3, 4);

    g.print();

    return 0;
}
