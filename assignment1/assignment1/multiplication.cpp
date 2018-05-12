//#include<stdlib.h>
//#include<math.h>
//#include<iostream>
//#include<vector>
//#include<String>
//using namespace std;
//
//int i1 = 1111;
//int i2 = 1000;
//
//int multi(vector<int> ab) {
//	int a = ab[0];
//	int b = ab[1];
//	string temp = to_string(a);
//	int n = temp.size();
//
//	if (n > 1) {
//		int a1 = a % int(pow(10, n / 2));
//		int a2 = (a - a1) / pow(10, n / 2);
//
//		int b1 = b % int(pow(10, n / 2));
//		int b2 = (b - b1) / pow(10, n / 2);
//
//		vector<int> in1;
//		in1.push_back(a1);
//		in1.push_back(b1);
//
//		vector<int> in2;
//		in2.push_back(a2);
//		in2.push_back(b2);
//
//		vector<int> in3;
//		in3.push_back(a1 + a2);
//		in3.push_back(b1 + b2);
//
//		int result = pow(10, n)*multi(in1) + multi(in2) + pow(10, n / 2)*(multi(in3) - multi(in1) - multi(in2));
//
//		return result;
//	}
//	else return a*b;
//	
//
//	
//	
//}
//
//int main() {
//	
//	vector<int> input;
//	input.push_back(i1);
//	input.push_back(i2);
//
//	cout << multi(input) << endl;
//	getchar();
//	return 0;
//
//}