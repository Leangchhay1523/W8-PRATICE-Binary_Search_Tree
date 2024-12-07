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
    cout << "In-Order Traverse : " << tree.inOrderTraversal() << endl;

    cout << "\nSearch for Values : " << endl;
    cout << "Find 10 : " << tree.search(10) << endl;
    cout << "Find 9 : " << tree.search(9) << endl;
    cout << "Find 11 : " << tree.search(11) << endl;

    cout << "\nDelete Values : " << endl;
    cout << "Delete Leaf (11) : " << endl; tree.deleteNode(7);
    cout << "Delete 2 children Node (5) << endl : "; tree.deleteNode(5);
    cout << "Print Tree : " << endl << tree.printTree() << endl;
    cout << "In-Order Traverse : " << tree.inOrderTraversal() << endl;
    return 0;
}