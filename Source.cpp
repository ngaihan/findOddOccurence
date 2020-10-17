#include <iostream>
#include <vector>
#include <fstream>

// Function prototype
int findOdd(const std::vector<int>& numbers);

int main() {
	std::fstream inputFile;
	inputFile.open("inputFile.txt");

	std::vector<int> numbers;
	int num;

	if (inputFile.is_open()) {

		std::cout << "File is open" << std::endl;

		while (!inputFile.eof()) {
			inputFile >> num;
			numbers.push_back(num);
		}

		std::vector<int>::iterator i;
		for (i = numbers.begin(); i != numbers.end(); i++) {
			std::cout << *i << ' ';
		}
	}

	inputFile.close();
	return 0;
}

int findOdd(const std::vector<int>& numbers) {
	std::vector<int> cp_numbers = numbers;
	std::vector<int> record; // This vector is to hold the numbers

	// Define the iterators
	std::vector<int>::iterator i = cp_numbers.begin(); 
	std::vector<int>::iterator j = record.begin();

	// Set flags
	bool inList = false;

	// Iterate through the vector cp_numbers
	for (i; i != cp_numbers.end(); i++) {
		// Check if already in record
		j = record.begin();
		for (j; j != record.end(); j++) {
			// Clear flags
			inList = false;

			if (*i == *j) {
				*i *= -1; // Multiply to change sign. A number will be repeated an odd number of times if its value is positive in the vector. If the value is negative, then it has been repeated an even number.
				inList = true;
				break;
			}
		}

		// If not in record, add to record
		if (!inList) {
			j = record.insert(j, *i);
		}
	}

	// Find the positive entry in the list
	int result;
	bool found = false;
	j = record.begin();
	while (j != record.end()) {
		// Check for positive
		if (*j > 0) {
			result = *j;
			found = true;
			break;
		}

		j++;
	}

	if (!found) {
		result = 0;
	}

	return result;
}