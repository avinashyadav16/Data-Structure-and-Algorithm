/**
*  @file: 146_LRU_Cache.cpp
*  @author: Avinash Yadav
*  @date: 15-08-2025
*  @link: https://leetcode.com/problems/lru-cache/description/
*  @brief: Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
            Implement the LRUCache class:
                LRUCache(int capacity)
                    - Initialize the LRU cache with positive size capacity.
                int get(int key)
                    - Return the value of the key if the key exists, otherwise return -1.
                void put(int key, int value)
                    - Update the value of the key if the key exists.
                    - Otherwise, add the key-value pair to the cache.
                    - If the number of keys exceeds the capacity from this operation, evict the least recently used key.

            The functions get and put must each run in O(1) average time complexity.

            Example 1:
                Input
                    ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
                    [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
                Output
                    [null, null, null, 1, null, -1, null, -1, 3, 4]
                Explanation
                    LRUCache lRUCache = new LRUCache(2);
                    lRUCache.put(1, 1); // cache is {1=1}
                    lRUCache.put(2, 2); // cache is {1=1, 2=2}
                    lRUCache.get(1);    // return 1
                    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
                    lRUCache.get(2);    // returns -1 (not found)
                    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
                    lRUCache.get(1);    // return -1 (not found)
                    lRUCache.get(3);    // return 3
                    lRUCache.get(4);    // return 4

*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

class LRUCache
{
public:
    // Node class to represent a doubly linked list node
    class Node
    {
    public:
        // Stores the key-value pair
        int key, val;

        // Pointers to previous and next nodes
        Node *prev, *next;

        // Constructor to initialize the node with given key and value
        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };

    // Dummy head node
    Node *head = new Node(-1, -1);

    // Dummy tail node
    Node *tail = new Node(-1, -1);

    // Cache capacity
    int cap;

    // Hashmap to store key-node pairs for O(1) access
    unordered_map<int, Node *> mpp;

    // Function to insert a node right after the head (most recently used position)
    void insertAfterHead(Node *newNode)
    {
        // Store the first actual node
        Node *temp = head->next;

        // Connect newNode to first actual node
        newNode->next = temp;

        // Connect newNode to head
        newNode->prev = head;

        // Head should now point to newNode
        head->next = newNode;

        // Previous first node should now point back to newNode
        temp->prev = newNode;
    }

    // Function to delete a node from its current position
    void deleteNode(Node *delNode)
    {
        // Get the previous node
        Node *prevNode = delNode->prev;

        // Get the next node
        Node *nextNode = delNode->next;

        // Link previous node to next node
        prevNode->next = nextNode;

        // Link next node to previous node
        nextNode->prev = prevNode;
    }

    // Constructor to initialize LRUCache with a given capacity
    LRUCache(int capacity)
    {
        // Set the cache capacity
        cap = capacity;

        // Initialize dummy head to point to tail
        head->next = tail;

        // Initialize dummy tail to point to head
        tail->prev = head;
    }

    // Function to get the value of a key in the cache
    int get(int key)
    {
        // If key exists in cache
        if (mpp.find(key) != mpp.end())
        {
            // Get the corresponding node
            Node *ansNode = mpp[key];

            // Store the value to return
            int ans = ansNode->val;

            // Remove key from hashmap
            mpp.erase(key);

            // Remove node from its current position
            deleteNode(ansNode);

            // Move node to most recently used position
            insertAfterHead(ansNode);

            // Update hashmap with new position
            mpp[key] = head->next;

            // Return the value
            return ans;
        }

        // Return -1 if key does not exist in cache
        return -1;
    }

    // Function to insert or update a key-value pair in the cache
    void put(int key, int value)
    {
        // If key already exists
        if (mpp.find(key) != mpp.end())
        {
            // Get the existing node
            Node *currNode = mpp[key];

            // Remove it from hashmap
            mpp.erase(key);

            // Remove node from linked list
            deleteNode(currNode);
        }

        // If cache is at full capacity
        if (mpp.size() == cap)
        {
            // Remove least recently used (LRU) node from hashmap
            mpp.erase(tail->prev->key);

            // Delete LRU node from linked list
            deleteNode(tail->prev);
        }

        // Insert new node at most recently used position
        insertAfterHead(new Node(key, value));

        // Update hashmap with new node reference
        mpp[key] = head->next;
    }
};