//#include <fstream>
//#include <iostream>
//#include <vector>
//#include <stack>
//#include <algorithm>
//
//using namespace std;
//
//int add_element_to_empty_stack(const vector<bool>& visited) {
//	for (int i = visited.size() - 1; i >= 0; --i) {
//		if (visited[i] == false)
//			return i+1;
//	}
//	return -1;
//}
////
//int add_element_to_empty_stack2(const vector<int>& order, const vector<bool>& visited) {
//	for (int i = order.size() - 1; i >= 0; --i) {
//		if (visited[order[i]-1] == false)
//			return order[i];
//	}
//	return -1;
//}
//
//void dfs(const vector<vector<int>>& graph, vector<int>& order) {
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
//		if (vertex == s.top()) {
//			order.push_back(vertex);
//			s.pop();
//		}
//
//		if (s.empty()) {
//			int element_to_push = add_element_to_empty_stack(visited);
//			if (element_to_push != -1) {
//				s.push(element_to_push);
//				visited[element_to_push - 1] = true;
//			}
//			else
//				break;
//		}
//	}
//}
//
//void dfs2(const vector<vector<int>>& graph, const vector<int>& order, vector<int>& leaders, vector<int>& results){
//	stack<int> s;
//	vector<bool> visited(graph.size(), false);
//	int scc_size = 0;
//	s.push(order.back());
//	visited[order.back() - 1] = true;
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
//		if (vertex == s.top()) {
//			s.pop();
//			scc_size++;
//		}
//
//		if (s.empty()) {
//			results.push_back(scc_size);
//			scc_size = 0;
//			leaders.push_back(vertex);
//			int element_to_push = add_element_to_empty_stack2(order, visited);
//			if (element_to_push != -1) {
//				s.push(element_to_push);
//				visited[element_to_push -1] = true;
//			}
//			else
//				break;
//		}
//	}
//}
//
//void readin(vector<vector<int>>& graph, vector<vector<int>>& reverse_graph) {
//	ifstream in("scc.txt");
//	string line;
//	int tail, head;
//
//	while (in >> tail >> head)
//	{
//		graph[tail - 1].push_back(head);
//		reverse_graph[head - 1].push_back(tail);
//	}
//	in.close();
//}
//
//
//int main() {
//	vector<vector<int>> graph,reverse_graph;
//	vector<int> order;
//	vector<pair<int, bool>> visited;
//	vector<int> leaders,results;
//	int size = 875714;
//	graph.resize(size); reverse_graph.resize(size);
//	readin(graph, reverse_graph);
//	
//	dfs(graph, order);
//	dfs2(reverse_graph, order, leaders,results);
//	sort(results.begin(), results.end());
//	getchar();
//
//	return 0;
//}