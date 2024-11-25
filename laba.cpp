#include <cstdbool>
#include <iostream>
using namespace std;

bool number(char line[], char forbidden[]) {
	bool count = true;
	int n = strlen(line);
	int d = strlen(forbidden);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			if (line[i] == forbidden[j]) {
				count = false;
			}
		}
	}
	return(count);
}

bool letter(char line[], char forbiddenLetter[]) {
	bool character = true;
	int n = strlen(line);
	int d = strlen(forbiddenLetter);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			if (line[i] == forbiddenLetter[j]) {
				character = false;
			}
		}
	}
	return (character);
}


void check(char line[], char forbidden[], char forbiddenLetter[]) {
	if (number(line, forbidden) && letter(line, forbiddenLetter)) {
		cout << line << endl;
	}
	else {
		cout << "" << endl;
	}
}
char forbidden[5] = { '6', '7', '8', '9', '0' };
char forbiddenLetter[7] = { 'z', 'x', 'c', 'v', 'b', 'n', 'm' };
char input[1000];

int main()
{
	while (true) {
		cin.getline(input, 1000);
		check(input, forbidden, forbiddenLetter);
		if (number(input, forbidden) && letter(input, forbiddenLetter)) {
			break;
		}
	}
	return 0;
}
