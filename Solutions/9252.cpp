#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string first;
    std::string second;
    std::cin >> first >> second;

    std::vector<std::vector<int>> length(
        first.size() + 1,
        std::vector<int>(second.size() + 1, 0));

    for (std::size_t row = 1; row <= first.size(); ++row) {
        for (std::size_t column = 1; column <= second.size(); ++column) {
            if (first[row - 1] == second[column - 1]) {
                length[row][column] = length[row - 1][column - 1] + 1;
            } else {
                length[row][column] = std::max(length[row - 1][column], length[row][column - 1]);
            }
        }
    }

    std::string subsequence;
    std::size_t row = first.size();
    std::size_t column = second.size();

    while (row > 0 && column > 0) {
        if (first[row - 1] == second[column - 1]) {
            subsequence.push_back(first[row - 1]);
            --row;
            --column;
        } else if (length[row - 1][column] >= length[row][column - 1]) {
            --row;
        } else {
            --column;
        }
    }

    std::reverse(subsequence.begin(), subsequence.end());
    std::cout << subsequence.size() << '\n';

    if (!subsequence.empty()) {
        std::cout << subsequence;
    }

    return 0;
}
