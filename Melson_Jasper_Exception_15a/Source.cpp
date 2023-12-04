// Jasper Melson
// CIS 1202 
// 11/30/2023

#include <iostream>

using namespace std;

// Custom exceptions

// Invalid starting character exception
class InvalidCharacterException {};

// Invalid range exception
class InvalidRangeException {};

// Case conversion exception
class CaseConversionException {};

// Function to find character offset value
char character(char start, int offset) {
    // Convert starting character to ASCII value
    int startAsciiValue = int(start);

    // Calculate target ASCII value based on offset
    int target = startAsciiValue + offset;

    try {
        // Check if starting character is a valid letter
        if (startAsciiValue < 65 || (startAsciiValue > 90 && startAsciiValue < 97) || startAsciiValue > 122) {
            throw InvalidCharacterException();
        }

        // Check if target character is within valid letter range
        else if (target < 65 || (target > 90 && target < 97) || target > 122) {
            throw InvalidRangeException();
        }

        // Check for case conversion attempt
        else if ((target >= 65 && target <= 90 && startAsciiValue >= 95 && startAsciiValue <= 122) || (target >= 95 && target <= 122 && startAsciiValue >= 65 && startAsciiValue <= 90)) {
            throw CaseConversionException();
        }
    }
    // Handle and print corresponding exceptions
    catch (InvalidCharacterException) {
        cout << "Invalid Character Exception" << endl;
        return ' ';
    }
    catch (InvalidRangeException) {
        cout << "Invalid Range Exception" << endl;
        return ' ';
    }
    catch (CaseConversionException) {
        cout << "Cannot change case from upper to lower or vice versa" << endl;
        return ' ';
    }

    // Return the resulting character if no exception was caught
    return char(target);
}

int main() {
    // Test cases
    cout << character('a', 1) << endl;
    cout << character('a', -1) << endl;
    cout << character('Z', -1) << endl;
    cout << character('?', 5) << endl;
    cout << character('A', 32) << endl;
}
