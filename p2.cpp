#include<iostream>
#include<vector>
using namespace std;
int inner_multiply(vector<int> input, int temp, int size, int counter, int multiply) {
	if (counter == size)
		return multiply;
	else {
		if (counter == temp) {
			counter += 1;
			return inner_multiply(input, temp, size, counter, multiply);
		}
		multiply *= input[counter];
		return inner_multiply(input, temp, size, counter + 1, multiply);
	}
}


vector<int> multiply(vector<int>&input, int temp, int size) {
	if (temp == size) {
		return input;
	}
	else {
		input.push_back(inner_multiply(input, temp, size, 0, 1));
		return multiply(input, temp + 1, size);
	}
}



int main() {
	vector<int> input;
	int temp;
	while (cin >> temp) {
		input.push_back(temp);
	}
	int i = input.size();
	multiply(input, 0, input.size());
	for (; i < input.size(); i++) {
		cout << input[i] << " ";
	}
}
