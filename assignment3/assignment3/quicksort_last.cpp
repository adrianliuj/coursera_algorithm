//#include <fstream>
//#include <iostream>
//#include <vector>
//#include <string>
//
//using namespace std;
//int comp = 0;
//
//void quicksort(vector<int>& nums, int begin, int end) {
//	//if ((end - begin) > 1) {
//	//	comp += end - begin - 1;
//	//	int pivot = nums[end - 1];
//	//	int i = begin;
//	//	for (int j = begin; j < end - 1; ++j) {
//	//		if (pivot > nums[j]) {
//	//			swap(nums[i], nums[j]);
//	//			++i;
//	//		}
//	//	}
//	//	swap(nums[end-1], nums[i]);
//	//	int a = comp;
//	//	quicksort(nums,begin, i);
//	//	quicksort(nums, i+1, end);
//	//}
//	if ((end - begin) > 1) {
//		comp += end - begin - 1;
//		int pivot = nums[end-1];
//		swap(nums[begin], nums[end - 1]);
//		int i = begin;
//		if (pivot > nums[begin + 1]) {
//			i++;
//		}
//		for (int j = begin + 2; j < end; ++j) {
//			if (pivot > nums[j]) {
//				swap(nums[i + 1], nums[j]);
//				++i;
//			}
//		}
//		if (i != begin) {
//			swap(nums[begin], nums[i]);
//		}
//		quicksort(nums, begin, i);
//		quicksort(nums, i + 1, end);
//	}
//}
//
//int main() {
//	ifstream in("array.txt");
//	vector<int> a;
//	string line;
//	int size = 10000;
//	for (int i = 0; i<size; ++i)
//	{
//		getline(in, line);
//		a.push_back(stoi(line));
//	}
//	quicksort(a, 0, a.size());
//	for (vector<int>::iterator iter = a.begin(); iter < a.end(); ++iter) {
//		cout << *iter << endl;
//	}
//	cout << comp << endl;
//	getchar();
//	return 0;
//
//}
//
