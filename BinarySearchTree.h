#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <queue>
#include "Node.h"

class BinarySearchTree {
private:
    Node* root;
public:
    BinarySearchTree() : root(nullptr) {}
    BinarySearchTree(int value) {
        root = new Node(value);
    }
    int calculateHeight() {
        return calculateHeight(root);
    }
    Node* getroot() {
        return root;
    }
    std::string printTree() {
        return printTree(root);
    }
    std::string inOrderTraversal()
    {
        std::string result = "";
        inOrder(root, result);
        return result;
    }
    // Exercise 1
    std::string search(int key)
    {
        if (search(root, key))
            return "Value Found";
        else 
            return "Value not Found";
    }
    void insert(int newValue)
    {
        root = insert(root, newValue);
    }
    void deleteNode(int value)
    {
        deleteNode(root, value);
    }

    // Exercise 2
    std::string levelOrderTraverse() {
        std::string result = "";
        //your code here
        levelOrder(root, result);
        return result;
    }

private:
    //exercise 1
    bool search(Node* root, int key){
        //your code here
        while (root != nullptr)
        {
            if (root->data == key)
                return true;
            
            if (key < root->data)
                root = root->left;
            else 
                root = root->right;
        }
        return false;
    }
    Node* insert(Node* root, int newValue) {
        //your code here
        if (root == nullptr)
        {
            root = new Node(newValue);
            return root;
        }

        if (newValue < root->data)
            root->left = insert(root->left, newValue);
        else 
            root->right = insert(root->right, newValue);
    }
    Node* deleteNode(Node* root, int value){
        //your code here
        if (root == nullptr)
            return root;
        
        if (value < root->data)
            root->left = deleteNode(root->left, value);
        else if (value > root->data)
            root->right = deleteNode(root->right, value);
        else 
        {
            // 0 child node
            if (root->left == nullptr && root->right == nullptr)
            {
                delete root;
                root = nullptr;
                return root;
            }
            // 1 child node
            else if (root->left == nullptr)
            {
                Node* temp = root->right;
                delete root;
                root = temp;
                return root;
            }
            else if (root->right == nullptr)
            {
                Node* temp = root->left;
                delete root;
                root = temp;
                return root;
            }

            // 2 children node
            Node* successor = findSuccessor(root->right);
            root->data = successor->data;
            root->right = deleteNode(root->right, successor->data);

        }
    }
    //exercise2
    std::string levelOrder(Node* root, std::string& result)
    {
        std::queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            Node* current = q.front();
            q.pop();
            result += std::to_string(current->data) + " ";
            
            if (current->left != nullptr)
                q.push(current->left);
            if (current->right != nullptr)
                q.push(current->right);
        }
        return result;
    }
    
private:

    int calculateHeight(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }

    void inOrder(Node* node, std::string& result) {
        // Left -> Root -> Right

        if (node->left != nullptr)
            inOrder(node->left, result);
        
        result += std::to_string(node->data) + " ";

        if (node->right != nullptr)
            inOrder(node->right, result);
    };

    Node* findSuccessor(Node* root)
    {
        Node* temp = root;

        while (temp->left != nullptr)
        {
            temp = temp->left;
        }
        
        return temp;
    }

    std::string printTree(Node* root, std::string space = "", int count = 0) {
        std::string treeStr;
        if (root == nullptr)
        {
            treeStr = "Tree is empty";
            return treeStr;
        }

        treeStr += space; 
        std::string childSpace;
        if (count == 0) // For tree root, we have to print data first before |_
        {
            treeStr += std::to_string(root->data);
            treeStr += "\n";
        }
        else 
        {
            treeStr += "|_";
            treeStr += std::to_string(root->data);
            treeStr += "\n";
            childSpace = space + "  ";
        }
        count++;
        if (root->left != nullptr)
            treeStr += printTree(root->left, childSpace, count);
        if (root->right != nullptr)
            treeStr += printTree(root->right, childSpace, count);
        return treeStr;
    }
};

#endif // BINARYTREE_H