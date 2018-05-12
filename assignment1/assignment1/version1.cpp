//#include<stdlib.h>
//#include<math.h>
//#include<iostream>
//#include<vector>
//#include<string>
////for this one, we can do small number multiplication
////the must have same digits and digits must be 2^n
//using namespace std;
//
//int i1 = 34;
//int i2 = 50;
//
//int multi(string str) {
//	int n = str.size() / 2;
//	if (n > 1) {
//		string s(str.begin(), str.begin() + n);
//		int a = stoi(s);
//		string p(str.begin() + n, str.end());
//		int b = stoi(p);
//
//		int a2 = a % int(pow(10, n / 2));
//		int a1 = (a - a2) / pow(10, n / 2);
//
//		int b2 = b % int(pow(10, n / 2));
//		int b1 = (b - b2) / pow(10, n / 2);
//
//		string in1 = to_string(a1);
//		in1.append(to_string(b1));
//
//		string in2 = to_string(a2);
//		in2.append(to_string(b2));
//
//		string in3 = to_string(a1 + a2);
//		in3.append(to_string(b1 + b2));
//		int result = pow(10, n)*multi(in1) + multi(in2) + pow(10, n / 2)*(multi(in3) - multi(in1) - multi(in2));
//
//		return result;
//	}
//	else {
//		int num = stoi(str);
//		int b = num % 10;
//		int a = (num - b) / 10;
//		cout << a*b<< endl;
//		return a*b;
//	}
//
//}
//
//int main() {
//
//	string input(to_string(i1));
//	input.append(to_string(i2));
//	cout<<input<<endl;
//	cout << multi(input) << endl;
//	getchar();
//	return 0;
//
//}