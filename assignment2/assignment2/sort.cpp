#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

long long invs = 0;

void mergestr(vector<int>& str, int begin, int n, int end) {
	vector<int> str1(str.begin() + begin, str.begin() + n);
	vector<int> str2(str.begin() + n, str.begin() + end);

	while (!str1.empty() && !str2.empty()) {
		if (str1.front() < str2.front()) {
			str[begin] = str1.front();
			str1.erase(str1.begin());
			begin++;
		}
		else if (str2.front() < str1.front()) {
			str[begin] = str2.front();
			str2.erase(str2.begin());
			begin++;
			invs += str1.size();
			//cout << invs << endl;
		}
	}

	if (!str1.empty()) {
		int len = str1.size();
		for (int i = len; i >0; --i) {
			str[end - 1] = str1.back();
			str1.pop_back();
			end--;
		}
	}

	else if (!str2.empty()) {
		int len = str2.size();
		for (int i = len; i > 0; --i) {
			str[end - 1] = str2.back();
			str2.pop_back();
			end--;
		}
	}
}

void sort_inv(vector<int>& str, int begin, int end) {
	if ((end - begin) >= 2) {
		int n = (end - begin) / 2;
		sort_inv(str, begin, begin + n);
		sort_inv(str, begin + n, end);
		mergestr(str, begin, begin + n, end);
	}
}

int main() {
	ifstream in("array.txt");
	ofstream out("result.txt");
	vector<int> a;
	string line;
	while (getline(in, line))
	{
		a.push_back(stoi(line));
	}
	int size = a.size();
	sort_inv(a, 0, size);
	cout << invs << endl;
	out << invs;
	getchar();
	return 0;
}

