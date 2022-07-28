#include<iostream>
#include<vector>
#include <conio.h>
using namespace std;

class Graph{
    int vertex;
    vector<vector<int> > adj;

    public:
        // Primary constructo for inializing the adjacency list for set of v nodes
        Graph(int v){
            vertex = v;
            adj = vector<vector<int> >(v+1);
        }

        // Add edge(u,v) to the Graph
        void addEdge(int u, int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Remove edge(u,v) from the Graph
        void removeEdge(int v, int u){
            // Removing u --> Find the vertex u in adj list of v, swap u with the last, delete last
            for(int i=0; i<adj[v].size(); ++i) {
                if(adj[v][i] == u){
                    swap(adj[v][i], adj[v][adj[v].size() - 1]);
                    adj[v].pop_back();
                    break;
                }
            }

            // Removing v --> Find the vertex v in adj list of u, swap v with the last, delete last
            for(int i=0; i<adj[u].size(); ++i) {
                if(adj[u][i] == v){
                    swap(adj[u][i], adj[u][adj[u].size() - 1]);
                    adj[u].pop_back();
                    break;
                }
            }
        }

        // Find out whether Euler path or Circuit exists
        void findEulerPathCircuit(){
            int odd = 0;
            int oddVertex = 0;

            for(int i=1; i < vertex; ++i){
                if(adj[i].size() % 2 == 1) {
                    ++odd;
                    oddVertex = i;
                }
            }

            if(odd == 0){
                cout << "Euler Circuit: ";
                printEuler(1);
            }
            else if(odd == 2){
                cout << "Euler Path: ";
                printEuler(oddVertex);
            }
            else{
                cout << "Euler path or circuit does not exist." << endl;
            }
        }

        // Printer
        void printEuler(int v) {
            cout << " " << v << " ";

            if(adj[v].size() == 0) {
                return;
            }

            if(adj[v].size() == 1) {
                int u = adj[v][0];
                removeEdge(v, u);
                printEuler(u);
                return;
            }

            for(int i=0;i<adj[v].size();++i){
				int u = adj[v][i];
				removeEdge(v, u);
				printEuler(u);
				return;
			}
        }

        // Check an edge (v, u) is a bridge or not
        bool isValidEdge(int v, int u){
            int c1, c2;
            c1 = c2 = 0;
            vector<bool> visited;

            // Remove the edge (v, u) and count the connected vertices
            removeEdge(v, u);
            visited = vector<bool>(vertex + 1, false);
            c1 = countConnectedVertices(u, visited);

            // Add the edge (v, u) and count the connected vertices
            addEdge(v, u);
            visited = vector<bool>(vertex + 1, false);
            c2 = countConnectedVertices(u, visited);

            // Check (v, u) is a bridge or not, if c1 == c2 then not a bride, hence valid
            if(c1 == c2)
                return true;
            else
                return false;
        }

        // DFS to count the number of vetices can reach from u
        int countConnectedVertices(int u, vector<bool> &visited) {
            visited[u] = true;
            int count = 1;

            for(int i=0;i<adj[u].size();++i){
				int v = adj[u][i];
				if(!visited[v]){
					count += countConnectedVertices(v, visited);
				}
			}

            return count;
        }
};

int main() {
    Graph graph(7);

    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(1, 6);
    graph.addEdge(2, 3);
    graph.addEdge(2, 5);
    graph.addEdge(2, 7);
    graph.addEdge(5, 6);
    graph.addEdge(6, 7);

    graph.findEulerPathCircuit();
    
    getch();
}
