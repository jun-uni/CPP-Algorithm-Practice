#include <iostream>
#include <vector>

void WritePreorder(
    const std::vector<int>& postorder,
    const std::vector<int>& inorderIndex,
    int inorderBegin,
    int inorderEnd,
    int postorderBegin,
    int postorderEnd) {
    if (inorderBegin > inorderEnd || postorderBegin > postorderEnd) {
        return;
    }

    const int root = postorder[postorderEnd];
    const int rootIndex = inorderIndex[root];
    const int leftSize = rootIndex - inorderBegin;

    std::cout << root << ' ';

    WritePreorder(
        postorder,
        inorderIndex,
        inorderBegin,
        rootIndex - 1,
        postorderBegin,
        postorderBegin + leftSize - 1);

    WritePreorder(
        postorder,
        inorderIndex,
        rootIndex + 1,
        inorderEnd,
        postorderBegin + leftSize,
        postorderEnd - 1);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int nodeCount;
    std::cin >> nodeCount;

    std::vector<int> inorder(nodeCount);
    std::vector<int> postorder(nodeCount);
    std::vector<int> inorderIndex(nodeCount + 1);

    for (int index = 0; index < nodeCount; ++index) {
        std::cin >> inorder[index];
        inorderIndex[inorder[index]] = index;
    }

    for (int& node : postorder) {
        std::cin >> node;
    }

    WritePreorder(postorder, inorderIndex, 0, nodeCount - 1, 0, nodeCount - 1);
    return 0;
}
