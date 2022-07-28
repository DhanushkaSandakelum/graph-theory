#include<iostream>
#include<conio.h>

using namespace std;

#define vertices 5

// print the solution
void printer(int path[]) {
	cout << "Solution exists: Following is one hamiltonian cycle" << endl;
	
	for(int i = 0; i < vertices; i++){
		cout << path[i] << " ";
	}
	
	cout << path[0] << " " << endl;
}

// Check is the vertex can be added to the hamiltonian cycle
bool isSafe(int v, bool graph[vertices][vertices], int path[], int pos) {
	if(graph[path[pos-1]][v] == 0) 
		return false;
		
	for(int i = 0; i < pos; i++){
		if(path[i] == v)
			return false;
	}
	
	return true;
}

// Recusrsively solve hamiltonian cycle problem
bool recHamiltonianCycle(bool graph[vertices][vertices], int path[], int pos) {
	if(pos == vertices) {
		if(graph[path[pos-1]][path[0]] == 1)
			return true;
		else
			return false;
	}
	
	for(int v = 1; v < vertices; v++) {
		if(isSafe(v, graph, path, pos)) {
			path[pos] = v;
			
			if(recHamiltonianCycle(graph, path, pos+1) == true)
				return true;
				
			path[pos] = -1;
		}
	}
	
	return false;
}


// Check hamiltonian cycle exists or not
bool hamiltonianCycle(bool graph[vertices][vertices]){
	int *path = new int[vertices];
	
	for(int i = 0; i < vertices; i++){
		path[i] = -1;
	}
	
	path[0] = 0;
	
	if(recHamiltonianCycle(graph, path, 1) == false) {
		cout << "No solution" << endl;
		return false;
	}
	
	printer(path);
	return true;
}

int main() {
	
	bool G1[vertices][vertices] =  {{0, 1, 0, 1, 0},
									{1, 0, 1, 1, 1},
									{0, 1, 0, 0, 1},
									{1, 1, 0, 0, 1},
									{0, 1, 1, 1, 0},
									};
									
	hamiltonianCycle(G1);
	
	getch();
}
