#!/bin/bash
SESSION=$(grep SESSION .env | cut -d '=' -f2)

DAY=$1
DAY_FOLDER="2024/day$DAY"

mkdir -p "$DAY_FOLDER"

curl --cookie "session=$SESSION" "https://adventofcode.com/2024/day/$DAY/input" -o "$DAY_FOLDER/input.txt"
echo "Input for Day $DAY downloaded to $DAY_FOLDER/input.txt"

PART1_FILE="$DAY_FOLDER/part1.cpp"
if [ ! -f "$PART1_FILE" ]; then
    cat <<EOL > "$PART1_FILE"
#include <bits/stdc++.h>
#include "helpers.h"
#define int long long

using namespace std;

int32_t main() {
    std::vector<std::string> input = readInput("../$DAY_FOLDER/input.txt");

    // Write solution for Part 1 here
    std::cout << "Solution for Part 1 of Day $DAY!" << std::endl;

    return 0;
}
EOL
    echo "Created boilerplate $PART1_FILE"
else
    echo "$PART1_FILE already exists"
fi

PART2_FILE="$DAY_FOLDER/part2.cpp"
if [ ! -f "$PART2_FILE" ]; then
    cat <<EOL > "$PART2_FILE"
#include <bits/stdc++.h>
#include "helpers.h"
#define int long long

using namespace std;

int32_t main() {
    std::vector<std::string> input = readInput("../$DAY_FOLDER/input.txt");

    // Write solution for Part 2 here
    std::cout << "Solution for Part 2 of Day $DAY!" << std::endl;

    return 0;
}
EOL
    echo "Created boilerplate $PART2_FILE"
else
    echo "$PART2_FILE already exists"
fi
