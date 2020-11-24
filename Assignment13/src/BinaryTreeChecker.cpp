#include <iostream>
#include "BinaryTreeChecker.h"

using namespace std;

int BinaryTreeChecker::check(const bool dump)
{
    data.clear();
    walk(tree.get_root());

    return compare(dump);
}

void BinaryTreeChecker::walk(BinaryNode *node)
{
    if (node == nullptr) return;

    walk(node->left);
    data.push_back(node->data);
    walk(node->right);
}

int BinaryTreeChecker::compare(const bool dump) const
{
    auto itCache = cache.begin();
    auto itData  = data.begin();

    if (dump) cout << endl;

    while (itCache != cache.end())
    {
        if (itData == data.end()) return INSUFFICIENT_DATA;
        if (dump) cout << *itData << ":" << *itCache << " ";
        if (*itCache != *itData) return DATA_MISMATCH;

        itCache++;
        itData++;
    }

    if (dump) cout << endl;
    if (itData != data.end()) return REMAINING_DATA;

    return NO_ERROR;
}
