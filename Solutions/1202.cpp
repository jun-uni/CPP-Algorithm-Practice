#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int jewelCount;
    int bagCount;
    std::cin >> jewelCount >> bagCount;

    std::vector<std::pair<int, int>> jewels(jewelCount);
    std::vector<int> bags(bagCount);

    for (auto& [weight, value] : jewels) {
        std::cin >> weight >> value;
    }

    for (int& capacity : bags) {
        std::cin >> capacity;
    }

    std::sort(jewels.begin(), jewels.end());
    std::sort(bags.begin(), bags.end());

    std::priority_queue<int> availableValues;
    std::size_t jewelIndex = 0;
    long long totalValue = 0;

    for (int capacity : bags) {
        while (jewelIndex < jewels.size() && jewels[jewelIndex].first <= capacity) {
            availableValues.push(jewels[jewelIndex].second);
            ++jewelIndex;
        }

        if (!availableValues.empty()) {
            totalValue += availableValues.top();
            availableValues.pop();
        }
    }

    std::cout << totalValue;
    return 0;
}
