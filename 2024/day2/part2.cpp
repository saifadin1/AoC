#include <bits/stdc++.h>
#include "helpers.h"
#define int long long

using namespace std;

int32_t main() {
    std::vector<std::string> input = readInput("../2024/day2/input.txt");

    vector<vector<int>> reports;
    int safe = 0;
    for(auto& line : input) {
        istringstream ss(line);
        vector<int> report;
        string token;
        while(getline(ss, token, ' ')) {
            report.push_back(stoll(token));
        }
        reports.push_back(report);
    }

    auto validAsInc = [](const vector<int> report) {
        bool valid = true;
        for(int i=0; i+1<report.size(); i++) {
            if(report[i + 1] - report[i] <= 0 || report[i + 1] - report[i] >= 4) {
                valid = false;
                break;
            }
        }
        return valid;
    };

    auto validAsDec = [](const vector<int> report) {
        bool valid = true;
        for(int i=0; i+1<report.size(); i++) {
            if(report[i] - report[i + 1] <= 0 || report[i] - report[i + 1] >= 4) {
                valid = false;
                break;
            }
        }
        return valid;
    };

    for(auto& report : reports) {
        int sz = report.size();
        for(int i=0; i<report.size(); i++) {
            auto copy = report;
            copy.erase(copy.begin() + i);
            if(validAsDec(copy) || validAsInc(copy)) {
                safe++;
                break;
            }
        }
    }

    cout << safe << '\n';

    return 0;
}
