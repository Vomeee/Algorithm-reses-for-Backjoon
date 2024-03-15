#include <iostream>
using namespace std;

char most_chars(int* arr);

int main() {
	int alphabets[26] = { 0 };

	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		char curr = toupper(str[i]);
		alphabets[curr - 65]++;
	}

	cout << most_chars(alphabets);

}

char most_chars(int* arr) {
	int max_count = arr[0];
	int max_char = 65;

	for (int i = 0; i < 26; i++) {
		if (arr[i] > max_count) max_count = arr[i];
		
	}

	int duplicate = 0;

	for (int i = 0; i < 26; i++) {
		if (arr[i] == max_count) {
			duplicate++; 
			max_char = 65 + i;
		}
	}

	if (duplicate == 1) return max_char;
	else return '?';
}