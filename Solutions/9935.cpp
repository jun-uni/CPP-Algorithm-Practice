#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string input;
    std::string pattern;
    std::cin >> input >> pattern;

    std::string result;
    result.reserve(input.size());

    for (char character : input) {
        result.push_back(character);

        if (result.size() >= pattern.size() &&
            std::equal(pattern.rbegin(), pattern.rend(), result.rbegin())) {
            result.resize(result.size() - pattern.size());
        }
    }

    std::cout << (result.empty() ? "FRULA" : result);
    return 0;
}
