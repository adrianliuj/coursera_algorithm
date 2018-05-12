//#include<math.h>
//#include<algorithm>
//#include<iostream>
//#include<vector>
//#include<string>
////for this one, we can do small number multiplication
////the must have same digits and digits must be 2^n
//using namespace std;
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
//		return a*b;
//	}
//
//}
//
//string processed_input(int i1, int i2) {
//	string num1 = to_string(i1);
//	string num2 = to_string(i2);
//	int digit1 = num1.size();
//	int digit2 = num2.size();
//	int digit = max(ceil(log2(digit1)),ceil(log2(digit2)));
//	
//	const int num1_size = num1.size();
//	const int num2_size = num2.size();
//	
//	num1.insert(num1.begin(), pow(2, digit) - num1_size, '0');
//	num2.insert(num2.begin(), pow(2, digit) - num2_size, '0');
//
//	return num1.append(num2);
//	
//}
//
//int main() {
//	int i1 = 342156;
//	int i2 = 50278;
//	cout << multi(processed_input(i1,i2)) << endl;
//	getchar();
//	return 0;
//
//}