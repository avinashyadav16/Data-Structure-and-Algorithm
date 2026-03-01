/**
 *  @file: 460_LFU_Cache.cpp
 *  @author: Avinash Yadav
 *  @date: 16-08-2025
 *  @link: https://leetcode.com/problems/lfu-cache/description/
 *  @brief: Design and implement a data structure for a Least Frequently Used (LFU) cache.
            Implement the LFUCache class:
                LFUCache(int capacity)
                    - Initializes the object with the capacity of the data structure.
                int get(int key)
                    - Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
                void put(int key, int value)
                    - Update the value of the key if present, or inserts the key if not already present.
                    - When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item.
                    - For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.

            To determine the least frequently used key, a use counter is maintained for each key in the cache.
            The key with the smallest use counter is the least frequently used key.
            When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation).
            The use counter for a key in the cache is incremented either a get or put operation is called on it.
            The functions get and put must each run in O(1) average time complexity.



Example 1:
    Input
        ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
        [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
    Output
        [null, null, null, 1, null, -1, 3, null, -1, 3, 4]

    Explanation
        // cnt(x) = the use counter for key x
        // cache=[] will show the last used order for tiebreakers (leftmost element is  most recent)
        LFUCache lfu = new LFUCache(2);
        lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
        lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
        lfu.get(1);      // return 1
                        // cache=[1,2], cnt(2)=1, cnt(1)=2
        lfu.put(3, 3);   // 2 is the LFU key because cnt(2)=1 is the smallest, invalidate 2.
                        // cache=[3,1], cnt(3)=1, cnt(1)=2
        lfu.get(2);      // return -1 (not found)
        lfu.get(3);      // return 3
                        // cache=[3,1], cnt(3)=2, cnt(1)=2
        lfu.put(4, 4);   // Both 1 and 3 have the same cnt, but 1 is LRU, invalidate 1.
                        // cache=[4,3], cnt(4)=1, cnt(3)=2
        lfu.get(1);      // return -1 (not found)
        lfu.get(3);      // return 3
                        // cache=[3,4], cnt(4)=1, cnt(3)=3
        lfu.get(4);      // return 4
                        // cache=[4,3], cnt(4)=2, cnt(3)=3

 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Node structure for doubly linked list
struct Node
{
    // Key of the cache entry
    int key;

    // Value of the cache entry
    int value;

    // Frequency count (number of accesses)
    int cnt;

    // Pointer to previous node in the list
    Node *prev;

    // Pointer to next node in the list
    Node *next;

    // Constructor initializes key, value, and
    // sets frequency to 1
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        cnt = 1;
    }
};

// Doubly linked list to maintain nodes
// of the same frequency
struct List
{
    // Number of nodes in the list
    int size;

    // Dummy head node
    Node *head;

    // Dummy tail node
    Node *tail;

    // Constructor initializes
    // empty list with dummy head and tail
    List()
    {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;

        size = 0;
    }

    // Adds a node to the front
    // (right after head) of the list
    void addFront(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;

        size++;
    }

    // Removes a given node from the list
    void removeNode(Node *delNode)
    {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;

        size--;
    }
};

// LFU Cache implementation
class LFUCache
{
    // Maps key to its node for O(1) access
    map<int, Node *> keyNode;

    // Maps frequency to its corresponding list of nodes
    map<int, List *> freqListMap;

    // Maximum capacity of the cache
    int maxCacheSize;

    // Minimum frequency among all keys (used for eviction)
    int minFreq;

    // Current number of items in the cache
    int currSize;

public:
    // Constructor initializes cache with given capacity
    LFUCache(int capacity)
    {
        maxCacheSize = capacity;
        minFreq = 0;
        currSize = 0;
    }

    // Helper function to update a node's frequency and
    // move it to the correct list
    void updateFreqListMap(Node *node)
    {
        // Remove node from keyNode map temporarily
        keyNode.erase(node->key);

        // Remove node from current frequency list
        freqListMap[node->cnt]->removeNode(node);

        // If this node was the only one with minFreq,
        // increment minFreq
        if (node->cnt == minFreq &&
            freqListMap[node->cnt]->size == 0)
        {
            minFreq++;
        }

        // Get the list for the next higher frequency,
        // or create it if it doesn't exist
        List *nextHigherFreqList = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end())
        {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }

        // Increment node's frequency
        node->cnt += 1;

        // Add node to the front of the new frequency list
        nextHigherFreqList->addFront(node);

        // Update frequency list map
        freqListMap[node->cnt] = nextHigherFreqList;

        // Add node back to keyNode map
        keyNode[node->key] = node;
    }

    // Returns the value for the given key, or -1 if not found
    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];

            int val = node->value;

            // Update frequency due to access
            updateFreqListMap(node);

            return val;
        }

        return -1; // Key not found
    }

    // Inserts or updates the value for the given key
    void put(int key, int value)
    {
        if (maxCacheSize == 0)
        {
            return; // No capacity, do nothing
        }

        // If key exists, update its value and frequency
        if (keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqListMap(node);
        }
        else
        {
            // If cache is full, remove least frequently used node
            if (currSize == maxCacheSize)
            {
                List *list = freqListMap[minFreq];
                // Remove from keyNode map
                keyNode.erase(list->tail->prev->key);

                // Remove from frequency list
                freqListMap[minFreq]->removeNode(list->tail->prev);

                currSize--;
            }

            currSize++;
            minFreq = 1; // New node will have frequency 1
            List *listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end())
            {
                listFreq = freqListMap[minFreq];
            }

            // Create new node
            Node *node = new Node(key, value);

            // Add to front of frequency 1 list
            listFreq->addFront(node);

            // Add to keyNode map
            keyNode[key] = node;

            // Update frequency list map
            freqListMap[minFreq] = listFreq;
        }
    }
};