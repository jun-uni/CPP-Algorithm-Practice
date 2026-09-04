#include <iostream>
#include <utility>

constexpr long long Modulo = 1'000'000'007;

std::pair<long long, long long> FibonacciPair(long long index) {
    if (index == 0) {
        return {0, 1};
    }

    const auto [current, next] = FibonacciPair(index / 2);
    const long long doubled = current * ((2 * next % Modulo - current + Modulo) % Modulo) % Modulo;
    const long long advanced = (current * current % Modulo + next * next % Modulo) % Modulo;

    if (index % 2 == 0) {
        return {doubled, advanced};
    }

    return {advanced, (doubled + advanced) % Modulo};
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long index;
    std::cin >> index;
    std::cout << FibonacciPair(index).first;
    return 0;
}
