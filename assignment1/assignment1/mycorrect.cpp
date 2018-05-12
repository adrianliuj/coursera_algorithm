#include<algorithm>
#include<iostream>
#include<fstream>
#include<string>
//for this one, we can do small number multiplication
//the must have same digits and digits must be 2^n
using namespace std;

//something wrong
//something wrong
//something wrong
//something wrong
//something wrong
//something wrong

int cc = 0;
int makeSameLen(string& str1, string& str2) {
	int digit1 = str1.length();
	int digit2 = str2.length();
	if (digit1 < digit2) {
		str1.insert(str1.begin(), digit2 - digit1, '0');
		return digit2;
	}
	else if (digit1 > digit2) {
		str2.insert(str2.begin(), digit1 - digit2, '0');
		return digit1;
	}
	else
		return digit2;
}
// we require the digits of addition numbers are the same
string addString(string str1, string str2) {
	string result;
	int carry = 0;
	int length = makeSameLen(str1, str2);
	for (int i = 0; i < length;  ++i) {
		int num1 = str1.back() - '0';
		str1.pop_back();
		int num2 = str2.back() - '0';
		str2.pop_back();

		int add = num1 + num2 + carry;
		int single = add % 10;
		if (add >= 10)
			carry = 1;
		else
			carry = 0;

		result.insert(result.begin(), single + '0');
	}
	if (carry == 1) {
		result.insert(result.begin(), '1');
	}
	return result;
}

string minusString(string str1, string str2) {
	string result;
	int carry = 0;
	int length = makeSameLen(str1, str2);
	for (int i = 0; i < length; ++i) {
		int num1 = str1.back() - '0';
		str1.pop_back();
		int num2 = str2.back() - '0';
		str2.pop_back();
		if (num1 >= num2) {
			int single = num1 - num2 - carry;
			result.insert(result.begin(), single + '0');
			carry = 0;
		}
		else {
			int single = num1 + 10 - num2 - carry;
			result.insert(result.begin(), single + '0');
			carry = 1;
		}
	}
	return result;
}

string movebits(string str, int n) {
	str.append(n, '0');
	return str;
}

string multi(string str1, string str2) {
	int n = makeSameLen(str1, str2);
	if (n > 1) {
		int m = ceil(str1.length() / 2);
		string a1(str1.begin(), str1.begin() + m);
		string a2(str1.begin() + m, str1.end());
		string b1(str2.begin(), str2.begin() + m);
		string b2(str2.begin() + m, str2.end());

		string input1 = multi(a1, b1);
		string input2 = multi(a2, b2);
		string input3 = multi(addString(a1, a2), addString(b1, b2));
//		int result = pow(10, n)*multi(in1) + multi(in2) + pow(10, n / 2)*(multi(in3) - multi(in1) - multi(in2));
		string result = addString(addString(movebits(input1, 2 * m), input2), movebits(minusString(input3, addString(input1, input2)), m));
		return result;
	}

	else if (n == 1){
		return to_string((str1.back()-'0')*(str2.back() - '0'));
	}	

}


int main() {
	string i1 = "3141592653589793238462643383279502884197169399375105820974944592";
	string i2 = "2718281828459045235360287471352662497757247093699959574966967627";

	cout << multi(i1,i2) << endl;
	getchar();
	return 0;

}