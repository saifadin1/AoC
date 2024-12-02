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

    for(auto& report : reports) {
        bool inc = (report[0] < report[1]) , ok = true;
        for(int i=0; i+1<report.size(); i++) {
            if(inc){
                if(report[i + 1] - report[i] <= 0 || report[i + 1] - report[i] >= 4){
                    ok = false;
                    break;
                }
            } else {
                if(report[i] - report[i + 1] <= 0 || report[i] - report[i + 1] >= 4){
                    ok = false;
                    break;
                }
            }
        }
        if(ok) safe++;
    }

    cout << safe << '\n';

    return 0;
}
