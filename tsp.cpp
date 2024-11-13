#include <bits/stdc++.h>
using namespace std;
#define V 4

// Implementation of the Traveling Salesman Problem
int travellingSalesmanProblem(int graph[][V], int s) {
    // Store all vertices apart from the source vertex
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    // Store the minimum weight Hamiltonian Cycle and path
    int min_path = INT_MAX;
    vector<int> min_path_sequence;

    do {
        // Store current path weight (cost)
        int current_pathweight = 0;
        int k = s;

        // Compute current path weight
        for (int i = 0; i < vertex.size(); i++) {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];

        // Update minimum path and path sequence if the current path is shorter
        if (current_pathweight < min_path) {
            min_path = current_pathweight;
            min_path_sequence = {s}; // start from the source
            for (int i = 0; i < vertex.size(); i++)
                min_path_sequence.push_back(vertex[i]);
            min_path_sequence.push_back(s); // return to the source
        }

    } 
    while (next_permutation(vertex.begin(), vertex.end()));

    // Print the minimum cost path
    cout << "Minimum cost: " << min_path << endl;
    cout << "Path: ";
    for (int i = 0; i < min_path_sequence.size(); i++) {
        cout << min_path_sequence[i];
        if (i < min_path_sequence.size() - 1) 
            cout << " -> ";
    }
    cout << endl;

    return min_path;
}

// Driver Code
int main() {
    // Matrix representation of graph
    int graph[][V] = { {0, 10, 15, 20},
                       {10, 0, 35, 25},
                       {15, 35, 0, 30},
                       {20, 25, 30, 0} };
    int s = 0;
    travellingSalesmanProblem(graph, s);
    return 0;
}
