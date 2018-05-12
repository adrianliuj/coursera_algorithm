//#include <fstream>
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int comp = 0;
//
//
//int getPivot(vector<int>& nums, int begin, int end) {
//	int mid;
//	if ((begin + end) % 2 == 0)
//		mid = (begin + end) / 2 - 1;
//	else
//		mid = (begin + end) / 2;
//	if (nums[begin] > nums[mid]) {
//		if (nums[end-1] < nums[mid])
//			return mid;
//		else if (nums[end-1] > nums[begin])
//			return begin;
//		return end-1;
//	}
//
//	else if (nums[begin] < nums[mid]) {
//		if (nums[end-1] > nums[mid])
//			return mid;
//		else if (nums[end-1] < nums[begin])
//			return begin;
//		return end-1;
//	}
//}
//
//void quickSort(vector<int>& nums, int begin, int end) {
//	if ((end - begin) > 2) {
//		comp += end - begin - 1;
//		int pivot = nums[getPivot(nums, begin, end)];
//		swap(nums[begin], nums[getPivot(nums, begin, end)]);
//		int i = begin + 1;
//		for (int j = begin + 1; j < end; ++j) {
//			if (pivot > nums[j]) {
//				swap(nums[i], nums[j]);
//				++i;
//			}
//		}
//		swap(nums[begin], nums[i-1]);
//		quickSort(nums, begin, i-1);
//		quickSort(nums, i, end);
//	}
//	if ((end - begin == 2)) {
//		comp++;
//		int c = 0;
//		nums[begin] > nums[begin + 1] ? swap(nums[begin], nums[begin + 1]) : c = 1;
//	}
//}
//
//int main() {
//	ifstream in("array.txt");
//	vector<int> a;
//	string line;
//	int size = 10000;
//	for (int i = 0;i<size;++i)
//	{
//		getline(in, line);
//		a.push_back(stoi(line));
//	}
//	quickSort(a, 0, a.size());
//	for (vector<int>::iterator iter = a.begin(); iter < a.end(); ++iter) {
//		cout << *iter << endl;
//	}
//	cout << comp << endl;
//	getchar();
//	return 0;
//
//}
