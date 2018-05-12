//#include <fstream>
//#include <iostream>
//#include <vector>
//#include <sstream>
//#include <string>
//#include <stack>
//
//using namespace std;
//
//int add_element_to_empty_stack(vector<bool>& visited) {
//	for (int i = visited.size() - 1; i >= 0; --i) {
//		if (visited[i] == false)
//			return i;
//	}
//	return -1;
//}
//
//void dfs(const vector<vector<int>>& graph,vector<int>& order) {
//	stack<int> s;
//	vector<bool> visited(graph.size(), false);
//
//	s.push(graph.size());
//	visited.back() = true;
//
//	while (!s.empty()) {
//		// do dfs here
//		int vertex = s.top();
//		for (vector<int>::const_iterator iter = graph[vertex - 1].begin(); iter != graph[vertex - 1].end(); ++iter) {
//			if (visited[*iter - 1] == false) {
//				s.push(*iter);
//				visited[*iter - 1] = true;
//				break;
//			}
//		}
//		if (vertex == s.top() ){
//			order.push_back(vertex);
//			s.pop();
//		}			
//			
//		if (s.empty()) {
//			int element_to_push = add_element_to_empty_stack(visited);
//			if (element_to_push != -1) {
//				s.push(element_to_push + 1);
//				visited[element_to_push] = true;
//			}
//			else 
//				break;
//		}
//	}
//}
//
//void readin(vector<vector<int>>& graph, vector<vector<int>>& reverse_graph) {
//	ifstream in("test.txt");
//	string line;
//	int tail, head;
//
//	while (getline(in, line))
//	{
//		stringstream stringin(line);
//		line.clear();
//		stringin >> tail >> head;
//		graph[tail - 1].push_back(head);
//		reverse_graph[head - 1].push_back(tail);
//
//	}
//	in.close();
//}
//
//
//int main() {
//	vector<vector<int>> graph,reverse_graph;
//	vector<int> order;
//	graph.resize(9); reverse_graph.resize(9);
//
//	readin(graph, reverse_graph);
//	dfs(graph, order);
//	getchar();
//
//	return 0;
//}