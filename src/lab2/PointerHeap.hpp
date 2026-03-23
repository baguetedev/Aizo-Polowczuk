#ifndef POINTERHEAP_HPP
#define POINTERHEAP_HPP

#include "HeapSort.hpp"

template <typename T>
class PointerHeap {
private:
    struct Node {
        T val;
        Node* left;
        Node* right;
        Node* parent;
        Node(T v) : val(v), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node* root;
    int count;

    Node* getNode(int k) {
        if (k <= 1) return root;
        int msb = 1;
        while ((msb << 1) <= k) msb <<= 1;
        msb >>= 1;
        
        Node* curr = root;
        while (msb > 0 && curr) {
            if (k & msb) curr = curr->right;
            else curr = curr->left;
            msb >>= 1;
        }
        return curr;
    }

    void heapifyUp(Node* node) {
        while (node->parent && node->val > node->parent->val) {
            mySwap(node->val, node->parent->val);
            node = node->parent;
        }
    }

    void heapifyDown(Node* node) {
        while (node) {
            Node* largest = node;
            if (node->left && node->left->val > largest->val) largest = node->left;
            if (node->right && node->right->val > largest->val) largest = node->right;

            if (largest != node) {
                mySwap(node->val, largest->val);
                node = largest;
            } else break;
        }
    }

    void clear(Node* node) {
        if (!node) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    PointerHeap(T* arr, int n) : root(nullptr), count(0) {
        for (int i = 0; i < n; ++i) push(arr[i]);
    }

    ~PointerHeap() {
        clear(root);
    }

    void push(T val) {
        Node* newNode = new Node(val);
        count++;

        if (count == 1) {
            root = newNode;
            return;
        }

        Node* parent = getNode(count / 2);
        newNode->parent = parent;
        if (count % 2 == 0) parent->left = newNode;
        else parent->right = newNode;

        heapifyUp(newNode);
    }

    void pop() {
        if (count == 0) return;
        if (count == 1) {
            delete root;
            root = nullptr;
            count = 0;
            return;
        }

        Node* lastNode = getNode(count);
        mySwap(root->val, lastNode->val);

        if (lastNode->parent->left == lastNode) lastNode->parent->left = nullptr;
        else lastNode->parent->right = nullptr;

        delete lastNode;
        count--;
        heapifyDown(root);
    }

    T top() {
        return root->val;
    }
};

#endif
