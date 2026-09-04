#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testCount;
    std::cin >> testCount;

    while (testCount-- > 0) {
        int buildingCount;
        int ruleCount;
        std::cin >> buildingCount >> ruleCount;

        std::vector<int> buildTime(buildingCount + 1);
        std::vector<int> indegree(buildingCount + 1, 0);
        std::vector<std::vector<int>> graph(buildingCount + 1);

        for (int building = 1; building <= buildingCount; ++building) {
            std::cin >> buildTime[building];
        }

        for (int rule = 0; rule < ruleCount; ++rule) {
            int prerequisite;
            int next;
            std::cin >> prerequisite >> next;
            graph[prerequisite].push_back(next);
            ++indegree[next];
        }

        int target;
        std::cin >> target;

        std::queue<int> ready;
        std::vector<int> earliestCompletion = buildTime;

        for (int building = 1; building <= buildingCount; ++building) {
            if (indegree[building] == 0) {
                ready.push(building);
            }
        }

        while (!ready.empty()) {
            const int current = ready.front();
            ready.pop();

            for (int next : graph[current]) {
                earliestCompletion[next] = std::max(
                    earliestCompletion[next],
                    earliestCompletion[current] + buildTime[next]);

                if (--indegree[next] == 0) {
                    ready.push(next);
                }
            }
        }

        std::cout << earliestCompletion[target] << '\n';
    }

    return 0;
}
