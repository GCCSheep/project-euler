#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void initialize(string names, vector<string> &namesVect);
long sumScores(vector<string> namesVect);
void print(vector<string> v);

int main() {
    // Store names in buffer.  
    ifstream t("p022_names.txt");
    stringstream buffer;
    buffer << t.rdbuf();
    // Pass buffer content to vector of names.
    string names = buffer.str();
    vector<string> namesVect;
    initialize(names, namesVect);
    sort(namesVect.begin(), namesVect.end());
    cout << sumScores(namesVect);
}

// Pass list of names in a string to names vector.
void initialize(string names, vector<string> &namesVect) {
    for (   int i = 0, begin = 0, end = 0;
            i < names.size();
            i = end + 2)
        if (names[i] == '"') {
            begin = i + 1;
            end = i + 1;
            while (names[end] != '"')
                end++;
            namesVect.push_back(names.substr(begin, end - begin));
        }
}

// Return the sum of scores of names in the vector.
long sumScores(vector<string> namesVect) {
    long sum = 0;
    for (int i = 0, score = 0; i < namesVect.size(); i++, score = 0) {
        for (int j = 0; j < namesVect[i].size(); j++)
            score += namesVect[i][j] - 'A' + 1;
        // cout << i << ": " << score << endl;
        sum += score * (i + 1);
    }
    return sum;
}

// Print vector.
void print(vector<string> v) {
    for (string s : v)
        cout << s << endl;
    cout << endl;
}
