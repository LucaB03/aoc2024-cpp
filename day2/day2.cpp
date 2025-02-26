#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

vector<vector<int>> readData(string filename);

int main() {
    vector<vector<int>> reports = readData("input.txt");
    int safeReports = 0;
    //Part 1
    /*
    for (vector<int> r : reports) {
        char mode = r[1] > r[0] ? 'i' : 'd';
        for (int i = 0; i < r.size()-1; i++) {
            if ((mode == 'i' && r[i] >= r[i+1]) || (mode == 'd' && r[i] <= r[i+1])  || (abs(r[i+1]-r[i]) > 3 || abs(r[i+1]-r[i]) < 1)) {
                safeReports--;
                break;
            }
        }
        safeReports++;
    }
    */
    //Part 2
    for (vector<int> r : reports) {
        char mode = r[1] > r[0] ? 'i' : 'd';
        bool unsafe = false;
        for (int i = 0; i < r.size()-1; i++) {
            if ((mode == 'i' && r[i] >= r[i+1]) || (mode == 'd' && r[i] <= r[i+1])  || (abs(r[i+1]-r[i]) > 3 || abs(r[i+1]-r[i]) < 1)) {
                if (unsafe) {
                    safeReports--;
                    break;
                }
                unsafe = true;
                r.erase(r.begin()+i+1);
                i--;
            }
        }
        safeReports++;
    }
    cout << "The number of safe reports (allowing one bad level) is: ";
    cout << safeReports;
    return 0;
}

vector<vector<int>> readData(string filename) {
    vector<vector<int>> reports(0);
    ifstream file(filename);
    char line[50];
    while (file.getline(line, 50)) {
        vector<int> reportLine(0);
        char* elem = strtok(line, " ");
        do {
            reportLine.push_back(atoi(elem));
            elem = strtok(NULL, " ");
        } while (elem);       
        reports.push_back(reportLine);
    }
    return reports;    
}
