#include <fstream>
#include <iostream>
#include <regex>
#include <iterator>
#include <vector>

using namespace std;

int sum(ifstream * stream);

int main() {
    ifstream file("input.txt");
    cout << "The sum of the mul-operations is " << sum(&file);
    return 0;
}

//using regex
//Part 2 included
int sum(ifstream * stream) {
    int sum = 0;
    bool enabled = true;
    //buffer the whole file into a vector
    vector<char> buffer;
    char c = stream->get();
    while(c != EOF) {
        buffer.push_back(c);
        c = stream->get();
    }
    string s(buffer.begin(), buffer.end());

    regex mul("mul\\((\\d{1,3}),(\\d{1,3})\\)|do\\(\\)|don't\\(\\)");
    auto itBegin = sregex_iterator(s.begin(), s.end(), mul);
    auto itEnd = sregex_iterator();
    for (regex_iterator i = itBegin; i != itEnd; ++i) {
        if (i->str() == "do()" || i->str() == "don't()") enabled = i->str() == "do()" ? true : false;
        else if (enabled) sum += stoi((*i)[1]) * stoi((*i)[2]);
    }
    stream->close();
    return sum;
}
