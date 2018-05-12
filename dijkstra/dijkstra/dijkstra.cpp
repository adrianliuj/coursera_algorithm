////We have build up a vertex class and priority queue
////implement dijkstra algorithm
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Vertex {
	friend bool operator<(Vertex a, Vertex b) {
		return a.dijkstra_score > b.dijkstra_score;
	}
public:
	vector<pair<int, int>> adj;
	int index;
	int dijkstra_score;
	int parent;
	bool visited;
	Vertex(vector<pair<int, int>>& adj_list, int v, int precedent_vertex) {
		adj = adj_list;
		index = v;
		dijkstra_score = INT_MAX;
		parent = precedent_vertex;
		visited = false;
	}
};

void dijkstra(priority_queue<Vertex>& v_x, vector<Vertex>& graph) {
	while (!v_x.empty()) {
		Vertex v = v_x.top();
		v_x.pop();
		graph[v.index-1].visited = true;
		for (int i = 0; i != graph[v.index - 1].adj.size(); ++i) {
			int head = graph[v.index - 1].adj[i].first;
			int weight = graph[v.index - 1].adj[i].second;

			if (graph[head-1].visited == false&&graph[head - 1].dijkstra_score > v.dijkstra_score + weight) {
				graph[head - 1].dijkstra_score = v.dijkstra_score + weight;
				graph[head - 1].parent = v.index;
				v_x.push(graph[head - 1]);
			}
		}
	}	
}

void readin(vector<Vertex>& graph) {
	ifstream in("graph.txt");
	vector<pair<int,int>> edges;
	string line, head_and_weight;
	int head, weight;
	int index = 1;
	while (getline(in, line))
	{
		stringstream stringin(line);
		line.clear();
		stringin >> head;
		while (stringin >> head_and_weight) {
			for (int i = 0; i != head_and_weight.size(); ++i) {
				if (head_and_weight[i] == ',') {
					head = stoi(head_and_weight.substr(0,i));
					weight = stoi(head_and_weight.substr(i+1));
					break;
				}
			}
			pair<int, int> edge(head, weight);
			edges.push_back(edge);
		}
		Vertex v(edges, index, 0);
		edges.clear();
		graph.push_back(v);
		index++;
	}
	in.close();
}

int main() {
	vector<Vertex> graph;
	graph.reserve(201);
	readin(graph);
	graph[0].dijkstra_score = 0;
	graph[0].parent = 1;
	priority_queue<Vertex> v_x;
	v_x.push(*(graph.begin()));
	dijkstra(v_x, graph);
	cout << "7:" << graph[6].dijkstra_score << endl;
	cout << "37:" << graph[36].dijkstra_score << endl;
	cout << "59:" << graph[58].dijkstra_score << endl;
	cout << "82:" << graph[81].dijkstra_score << endl;
	cout << "99:" << graph[98].dijkstra_score << endl;
	cout << "115:" << graph[114].dijkstra_score << endl;
	cout << "133:" << graph[132].dijkstra_score << endl;
	cout << "165:" << graph[164].dijkstra_score << endl;
	cout << "188:" << graph[187].dijkstra_score << endl;
	cout << "197:" << graph[196].dijkstra_score << endl;

	getchar();

	return 0;
}