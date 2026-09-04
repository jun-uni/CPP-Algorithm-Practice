#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int count;
    std::cin >> count;

    std::vector<int> tails;
    tails.reserve(count);

    for (int index = 0; index < count; ++index) {
        int value;
        std::cin >> value;

        const auto position = std::lower_bound(tails.begin(), tails.end(), value);
        if (position == tails.end()) {
            tails.push_back(value);
        } else {
            *position = value;
        }
    }

    std::cout << tails.size();
    return 0;
}
