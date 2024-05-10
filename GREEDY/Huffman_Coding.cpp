/**
 *  @file: Huffman_Coding.cpp
 *  @author: Avinash Yadav  
 *  @brief: Provide the implementation of the problem Huffman encoding.
 *  @date: 22-03-2024
 */

#include <bits/stdc++.h>
using namespace std;

// Structure for a Huffman tree node
struct Node
{
    char data;
    int freq;
    Node *left;
    Node *right;

    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// Comparison function for priority queue
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

// Function to build Huffman tree
Node *buildHuffmanTree(unordered_map<char, int> &freqMap)
{
    priority_queue<Node *, vector<Node *>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto &pair : freqMap)
    {
        pq.push(new Node(pair.first, pair.second));
    }

    // Merge nodes until there is only one node left in the priority queue
    while (pq.size() != 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        // Create a new internal node with the sum of frequencies
        // and set left and right children
        Node *internalNode = new Node('$', left->freq + right->freq);
        internalNode->left = left;
        internalNode->right = right;

        // Add the new internal node back to the priority queue
        pq.push(internalNode);
    }

    // The remaining node in the priority queue is the root of the Huffman tree
    return pq.top();
}

// Function to encode characters using Huffman encoding
void encode(Node *root, string str, unordered_map<char, string> &huffmanCode)
{
    if (root == nullptr)
        return;

    // If the current node is a leaf node, then it stores one of the input characters
    if (root->data != '$')
        huffmanCode[root->data] = str;

    // Traverse left and right
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Function to perform Huffman encoding
void huffmanEncoding(string text)
{
    // Calculate frequency of each character
    unordered_map<char, int> freqMap;
    for (char ch : text)
    {
        freqMap[ch]++;
    }

    // Print normal character frequency
    cout << "Normal Character Frequency:\n";
    for (auto &pair : freqMap)
    {
        cout << pair.first << " : " << pair.second << endl;
    }
    cout << endl;

    // Build Huffman tree
    Node *root = buildHuffmanTree(freqMap);

    // Generate Huffman codes
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    // Print Huffman codes
    cout << "Huffman Codes:\n";
    for (auto &pair : huffmanCode)
    {
        cout << pair.first << " : " << pair.second << endl;
    }

    // Calculate total bytes required using normal character representation
    int totalBytesNormal = 0;
    for (auto &pair : freqMap)
    {
        totalBytesNormal += pair.second; // Each character takes 1 byte
    }

    // Calculate total bytes required using Huffman coding
    int totalBitsHuffman = 0;
    for (auto &pair : huffmanCode)
    {
        // Multiply length of Huffman code with frequency
        totalBitsHuffman += pair.second.size() * freqMap[pair.first];
    }
    int totalBytesHuffman = (totalBitsHuffman + 7) / 8; // Convert bits to bytes

    // Print comparison of total bytes required
    cout << "\nTotal Bytes Required:\n";
    cout << "Normal Character Representation: " << totalBytesNormal << " bytes\n";
    cout << "Huffman Coding Approach: " << totalBytesHuffman << " bytes\n";
}

int main()
{
    string text = "Compression Method Using Huffman Coding Approach";

    // Perform Huffman encoding
    huffmanEncoding(text);

    return 0;
}