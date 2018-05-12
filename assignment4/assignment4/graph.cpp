#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <algorithm>

using namespace std;

std::pair<int,int> selectEdge(const vector<vector<int>>& graph) {
	srand(time(0));
	int index1 = rand() % graph.size();
	while (graph[index1].size() == 0) {
		index1 = rand() % graph.size();
	}
	int index2 = rand() % graph[index1].size();

	pair<int,int> result(index1, index2);
	return result;
}

void cut(vector<vector<int>>& graph){
	int vertices = 0;
	int node = 0;
	for (int i = 0; i < graph.size();++i) {
		if (!graph[i].empty()) {
			vertices++;
			node = i;
		}
	}
	if (vertices > 2) {
		pair<int, int> line = selectEdge(graph);
		const int vertice2 = graph[line.first][line.second];
		const int vertice1 = line.first + 1;
		//for all other vertices(but v1 and v2), if they have an edge with vertice2, change it to vertice1;
		for (int i = 0; i < graph.size();++i) {
			if (i != vertice1 - 1 && i != vertice2 - 1 && !graph[i].empty()) {
				for (int j = 0; j < graph[i].size(); ++j) {
					if (graph[i][j] == vertice2) {
						graph[i][j] = vertice1;
						graph[vertice1 - 1].push_back(i + 1);
					}
				}
			}
		}
			
		//delete all the edges in v1 that is connected to v2	
		//this guy has problem
		graph[vertice1 - 1].erase(remove(graph[vertice1 - 1].begin(), graph[vertice1 - 1].end(), vertice2),graph[vertice1-1].end());

		//merge the edges of v2 into v1, along side delete the edge contains v1
		graph[vertice2 - 1].clear();
		//cut the new graph
		cut(graph);
	}		
}

void readin(vector<vector<int>>& graph) {
	ifstream in("graph.txt");
	vector<int> edges;
	string line;
	int edge;

	while (getline(in, line))
	{
		stringstream stringin(line);
		line.clear();
		int flag = 0;
		while (stringin >> edge) {
			if (flag != 0) {
				edges.push_back(edge);
			}
			++flag;
		}
		graph.push_back(edges);
		edges.clear();
	}
	in.close();
}

int main() {
	vector<vector<int>> graph;
	readin(graph);

	cut(graph);
	int result = 0;
	for (vector<vector<int>>::iterator iter = graph.begin(); iter != graph.end(); ++iter) {
		if (!(*iter).empty()) {
			result = (*iter).size();
			break;
		}
	}
	cout << result << endl;
	getchar();
	return 0;

}

