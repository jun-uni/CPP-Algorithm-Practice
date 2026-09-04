#include <iostream>
#include <limits>
#include <queue>
#include <vector>

struct Edge {
    int from;
    int to;
    int cost;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cityCount;
    int start;
    int destination;
    int edgeCount;
    std::cin >> cityCount >> start >> destination >> edgeCount;

    std::vector<Edge> edges(edgeCount);
    std::vector<std::vector<int>> graph(cityCount);

    for (Edge& edge : edges) {
        std::cin >> edge.from >> edge.to >> edge.cost;
        graph[edge.from].push_back(edge.to);
    }

    std::vector<long long> income(cityCount);
    for (long long& value : income) {
        std::cin >> value;
    }

    constexpr long long unreachable = std::numeric_limits<long long>::lowest() / 4;
    std::vector<long long> profit(cityCount, unreachable);
    profit[start] = income[start];

    std::vector<int> cycleCandidates;

    for (int iteration = 0; iteration < cityCount; ++iteration) {
        for (const Edge& edge : edges) {
            if (profit[edge.from] == unreachable) {
                continue;
            }

            const long long candidate = profit[edge.from] - edge.cost + income[edge.to];
            if (candidate <= profit[edge.to]) {
                continue;
            }

            profit[edge.to] = candidate;
            if (iteration == cityCount - 1) {
                cycleCandidates.push_back(edge.to);
            }
        }
    }

    // 마지막 완화 정점에서 목적지까지의 도달 가능성 검사
    std::queue<int> queue;
    std::vector<bool> visited(cityCount, false);

    for (int city : cycleCandidates) {
        if (!visited[city]) {
            visited[city] = true;
            queue.push(city);
        }
    }

    while (!queue.empty()) {
        const int current = queue.front();
        queue.pop();

        for (int next : graph[current]) {
            if (!visited[next]) {
                visited[next] = true;
                queue.push(next);
            }
        }
    }

    if (visited[destination]) {
        std::cout << "Gee";
    } else if (profit[destination] == unreachable) {
        std::cout << "gg";
    } else {
        std::cout << profit[destination];
    }

    return 0;
}
