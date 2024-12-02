#include "helpers.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> readInput(const  string& filename) {
     ifstream file(filename);
     vector<string> lines;
     string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}
