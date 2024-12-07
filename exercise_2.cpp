#include <iostream>
#include <string>
#include "Node.h"
#include "BinarySearchTree.h"
using namespace std;

int main()
{
    BinarySearchTree tree(7);
    // Insert Values
    tree.insert(5);
    tree.insert(9);
    tree.insert(1);
    tree.insert(6);
    tree.insert(8);
    tree.insert(11);
    cout << "Print Tree : " << endl << tree.printTree() << endl;
    cout << "Level-Order Traverse : " << tree.levelOrderTraverse() << endl;
    return 0;
}