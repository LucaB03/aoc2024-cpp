#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;
//func declarations
void makeLists(string filename, vector<int> &l1, vector<int> &l2);
void sort(vector<int> &list);


int main() {
    cout << "Hello World\n";
    vector<int> list1(0), list2(0);
    makeLists("input.txt", list1, list2);
    int distance = 0;
    sort(list1);
    sort(list2);
    for (int i = 0; i < list1.size(); i++) {
        distance += abs(list1[i] - list2[i]);
    }
    cout << "The summed distance is: ";
    cout << distance;
    return 0;
}

void makeLists(string filename, vector<int> &l1, vector<int> &l2) {
    ifstream file(filename, ifstream::in);
    char line[20];
    while (file.getline(line, 20)) {
        char *left = strtok(line, " ");
        char *right = strtok(NULL, " ");
        l1.push_back(atoi(left));
        l2.push_back(atoi(right));
    }
    file.close();
}

void sort(vector<int> &list) {
    for (int j = 0; j < list.size(); j++) {
        int low = j;
        for (int i = j+1; i < list.size(); i++) {
            low = list[i] <= list[low] ? i : low;
        }
        int temp = list[j];
        list[j] = list[low];
        list[low] = temp;
    }
}
