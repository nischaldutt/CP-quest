#include <bits/stdc++.h>
#include <vector>
#define null nullptr

using namespace std;

vector<vector<int>> adjacencyMatrix(vector<vector<int>> &matrix, int vertices, int edges) {
  int src, dest;
  while(edges--) {
    cin>>src>>dest;
    matrix[src-1][dest-1] = 1;
    matrix[dest-1][src-1] = 1;
  }
  return matrix;
}

vector<vector<int>> adjacencyList(vector<vector<int>> &list, int vertices, int edges) {
  int src, dest;
  while(edges--) {
    cin>>src>>dest;
    list[src].push_back(dest);
    list[dest].push_back(src);
  }
  return list;
}

int main() {
  int vertices, edges, src, dest;
  cin>>vertices>>edges;

  // vector<vector<int>> matrix(vertices, vector<int> (vertices, 0));
  // matrix = adjacencyMatrix(matrix, vertices, edges);

  vector<vector<int>> list(vertices+1);
  list = adjacencyList(list, vertices, edges);

  return 0;
}