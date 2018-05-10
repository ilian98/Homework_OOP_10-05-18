#include <iostream>
#include <string.h>
#include "Vector3D.cpp"
using namespace std;
int main () {
    char operation[1001]; // string for parsing the operation in the input
    Vector3D vectors[10000]; // array containing the vectors in the input;
    int number_of_vectors;

    cin >> operation >> number_of_vectors ;
    for (int i=0; i<number_of_vectors; i++) {
        cin >> vectors[i] ;
    }

    if (operation[0] == '+') {
        Vector3D result; // instance of the class for the end result
        for (int i = 0; i < number_of_vectors; i++) {
            result = result + vectors[i];
        }

        cout << result ;
    }

    else if (operation[0] == '-') {
        Vector3D result; // instance of the class for the end result
        if (number_of_vectors > 0) result = vectors[0];
        for (int i = 1; i < number_of_vectors; i++) {
            result = result - vectors[i];
        }

        cout << result ;
    }

    else if (operation[0] == 'N') {
        for (int i = 0; i < number_of_vectors; i++) {
            if (i!=0) cout << " "; // print space between vectors without space before the first vector
            cout << -vectors[i] ;
        }
    }

    else if (operation[0] == '*') {
        double number_for_multiplying = 0;
        int length_of_operation = strlen(operation);
        for (int i = 1; i < length_of_operation; i++) {
            if (operation[i] == '.') {
                double decimal_part = 0;
                /* traversing the digits in decimal part in reverse order
                   in order to use horner's method for converting the digits
                   into the decimal part of the number */
                for (int j = length_of_operation - 1; j > i; j--) {
                    decimal_part += (operation[j] - '0');
                    decimal_part /= 10.;
                }

                number_for_multiplying += decimal_part;
                break;
            }
            // using horner's method for converting the digits into number
            number_for_multiplying *= 10. ;
            number_for_multiplying += (operation[i] - '0');
        }

        for (int i = 0; i < number_of_vectors; i++) {
            if (i!=0) cout << " "; // print space between vectors without space before the first vector
            cout << vectors[i] * number_for_multiplying;
            }
        }

    else {
        double number_for_multiplying = 0;
        int length_of_operation = strlen(operation);
        for (int i = 0; i < length_of_operation-1; i++) {
            if (operation[i] == '.') {
                double decimal_part = 0;
                /* traversing the digits in decimal part in reverse order
                   in order to use horner's method for converting the digits
                   into the decimal part of the number */
                for (int j = length_of_operation - 2; j > i; j--) {
                    decimal_part += (operation[j] - '0');
                    decimal_part /= 10.;
                }

                number_for_multiplying += decimal_part;
                break;
            }
            // using horner's method for converting the digits into number
            number_for_multiplying *= 10. ;
            number_for_multiplying += (operation[i] - '0');
        }

        for (int i = 0; i < number_of_vectors; i++) {
            if (i!=0) cout << " "; // print space between vectors without space before the first vector
            cout << number_for_multiplying * vectors[i];
            }
        }

    return 0;
}
