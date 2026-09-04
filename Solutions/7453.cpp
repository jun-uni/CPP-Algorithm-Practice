#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int size;
    std::cin >> size;

    std::vector<int> a(size);
    std::vector<int> b(size);
    std::vector<int> c(size);
    std::vector<int> d(size);

    for (int index = 0; index < size; ++index) {
        std::cin >> a[index] >> b[index] >> c[index] >> d[index];
    }

    const std::size_t pairCount = static_cast<std::size_t>(size) * size;
    std::vector<int> ab;
    std::vector<int> cd;
    ab.reserve(pairCount);
    cd.reserve(pairCount);

    for (int first = 0; first < size; ++first) {
        for (int second = 0; second < size; ++second) {
            ab.push_back(a[first] + b[second]);
            cd.push_back(c[first] + d[second]);
        }
    }

    std::sort(cd.begin(), cd.end());

    long long zeroSumCount = 0;
    for (int sum : ab) {
        const auto range = std::equal_range(cd.begin(), cd.end(), -sum);
        zeroSumCount += std::distance(range.first, range.second);
    }

    std::cout << zeroSumCount;
    return 0;
}
