#include <iostream>
#include "BinaryTreePrinter.h"

using namespace std;

const int BinaryTreePrinter::POWERS_OF_2[] = {1, 2, 4, 8, 16, 32, 64, 128};

void BinaryTreePrinter::print() const
{
    // Queue of nodes at this level.
    BinaryNode *this_level_nodes[32];

    int height = tree.height();
    int offset = POWERS_OF_2[(height+1)]-1;

    this_level_nodes[0] = tree.get_root();

    // Loop to print each level of nodes.
    for (int level = 0; level <= height; level++)
    {
        if (level > MAX_LEVELS)
        {
            cout << "*** Too many levels to print. ***\n";
            break;
        }

        // Print node data.
        print_data(level, offset, this_level_nodes);

        if (level != height)
        {
            // Print outgoing pointers /\ from each parent node->
            print_outgoing_pointers(level, offset, this_level_nodes);

            offset = POWERS_OF_2[height - level] - 1;

            // Print connecting dashes ----
            if (level < height-1)
            {
                print_connecting_dashes(level, offset, this_level_nodes);
            }

            // Print incoming pointers / and \ to each child node->
            print_incoming_pointers(level, offset, this_level_nodes);

            // Prepare the next level of nodes.
            next_level(level, this_level_nodes);
        }
    }
}

void BinaryTreePrinter::print_data(const int level, const int offset,
                                   BinaryNode *level_nodes[]) const
{
    print_spaces(offset);

    int k = POWERS_OF_2[level];
    for (int i = 0; i < k; i++)
    {
        BinaryNode *ptr = level_nodes[i];

        if (ptr != nullptr) cout << setw(3) << ptr->data << " ";
        else                cout << "    ";

        // Space over to the next node in this level.
        if (i < k-1) print_spaces(2*offset - 2);
    }

    cout << endl;
}

void BinaryTreePrinter::print_outgoing_pointers(
                                    const int level, const int offset,
                                    BinaryNode *level_nodes[]) const
{
    print_spaces(offset);

    int k = POWERS_OF_2[level];
    for (int i = 0; i < k; i++)
    {
        BinaryNode *ptr = level_nodes[i];

        // Has left child: print / forward slash
        if ((ptr != nullptr) && (ptr->left != nullptr)) cout << " /";

        // No left child: print space
        else cout << "  ";

        // Has right child: print \ backward slash
        if ((ptr != nullptr) && (ptr->right != nullptr)) cout << "\\ ";

        // No right child: print space
        else cout << "  ";

        // Space over to the next node in this level.
        if (i < k-1) print_spaces(2*offset-2);
    }

    cout << endl;
}

void BinaryTreePrinter::print_connecting_dashes(
                                        int level, int offset,
                                        BinaryNode *level_nodes[]) const
{
    if (offset > 1) print_spaces(offset);

    int k = POWERS_OF_2[level];
    for (int i = 0; i < k; i++)
    {
        BinaryNode *ptr = level_nodes[i];

        // Has left child: print dashes
        if ((ptr != nullptr) && (ptr->left != nullptr))
        {
            print_spaces(3);
            print_dashes(offset-1);
        }

        // No left child: print spaces
        else print_spaces(offset+2);

        // Has right child: print dashes
        if ((ptr != nullptr) && (ptr->right != nullptr))
        {
            print_spaces(2);
            print_dashes(offset-1);
        }

        // No right child: print spaces
        else print_spaces(offset+1);

        // Space over to the next node in this level.
        if (i < k-1) print_spaces(2*offset+1);
    }

    cout << endl;
}

void BinaryTreePrinter::print_incoming_pointers(
                                    const int level, const int offset,
                                    BinaryNode *level_nodes[]) const
{
    print_spaces(offset);

    int k = POWERS_OF_2[level];
    for (int i = 0; i < k; i++)
    {
        BinaryNode *ptr = level_nodes[i];

        // Left child: print /
        if ((ptr != nullptr) && (ptr->left != nullptr)) cout <<"  /";

        // No left child: print spaces
        else print_spaces(3);

        // Right child: print \ backward slash
        if ((ptr != nullptr) && (ptr->right != nullptr))
        {
            print_spaces(2*offset);
            cout << "\\";
        }

        // No right child: print spaces
        else print_spaces(2*offset+1);

        // Space over to the next node in this level.
        if (i < k-1) print_spaces(2*offset);
    }

    cout << endl;
}

void BinaryTreePrinter::next_level(int level, BinaryNode *level_nodes[]) const
{
    int size = POWERS_OF_2[level+1];
    BinaryNode *next_level[size];

    for (int i = 0; i < POWERS_OF_2[level]; i++)
    {
        BinaryNode *ptr = level_nodes[i];

        // Queue the left child nodes of each non-null parent node->
        next_level[2*i] = (ptr != nullptr) && (ptr->left != nullptr)
                       ? ptr->left : nullptr;

        // Queue the right child nodes of each non-null parent node->
        next_level[2*i+1] = (ptr != nullptr) && (ptr->right != nullptr)
                         ? ptr->right : nullptr;
    }

    for (int i = 0; i < size; i++) level_nodes[i] = next_level[i];
}

void BinaryTreePrinter::print_spaces(int count) const
{
    for (int i = 0; i < count; i++) cout << " ";
}

void BinaryTreePrinter::print_dashes(int count) const
{
    for (int i = 0; i < count; i++) cout << "-";
}
