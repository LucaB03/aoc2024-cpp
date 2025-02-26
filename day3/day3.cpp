#include <fstream>
#include <iostream>

using namespace std;

int count(ifstream * stream);

int main() {
    ifstream file("input.txt");
    cout << "The sum of the mul-operations is " << count(&file);
    return 0;
}

//simple DFA implementation for mul-regex
int count(ifstream * stream) {
    char c = stream->get();
    int mulOpParts = 0, mulOpCounter = 0;
    int x = 0, y = 0, sum = 0;
    while (c != EOF) {
        if (mulOpParts == 8) {
            ++mulOpCounter;
            mulOpParts = 0;
            sum += x * y;
            x = 0;
            y = 0;
        } 
        if (mulOpParts == 0 && c == 'm') ++mulOpParts;
        else if (mulOpParts == 1 && c == 'u') ++mulOpParts;
        else if (mulOpParts == 2 && c == 'l') ++mulOpParts;
        else if (mulOpParts == 3 && c == '(') ++mulOpParts;
        else if (mulOpParts == 4 && (c >= 48 && c <= 57)) {
            ++mulOpParts;
            int digitCounter = 1;
            string digits = "";
            while (digitCounter < 4) {
                digits += c;
                char p = stream->peek();
                if (p >= 48 && p <= 57) {
                    ++digitCounter;
                    c = stream->get();
                }
                else if (p == ',') break;
                else {
                    mulOpParts = 0;
                    break;
                }
            }
            if (digitCounter > 3) mulOpParts = 0;  
            x = stoi(digits);          
        }
        else if (mulOpParts == 5 && c == ',') ++mulOpParts;
        else if (mulOpParts == 6 && (c >= 48 && c <= 57)) {
            ++mulOpParts;
            int digitCounter = 1;
            string digits = "";
            while (digitCounter < 4) {
                digits += c;
                char p = stream->peek();
                if (p >= 48 && p <= 57) {
                    ++digitCounter;
                    c = stream->get();
                }
                else if (p == ')') break;
                else {
                    mulOpParts = 0;
                    break;
                }
            }
            if (digitCounter > 3) mulOpParts = 0;           
            y = stoi(digits);    
        }
        else if (mulOpParts == 7 && c == ')') ++mulOpParts;
        else mulOpParts = 0; 
        c = stream->get();
    }
    
    return sum;
}
