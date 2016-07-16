// Implementado por Eduardo Machado
// 2015

#include <iostream>

using namespace std;

class Node{
  private:
    int key;
    char truck;
    Node *leftNode;
    Node *rightNode;
    Node *fatherNode;

  public:
    void setKey(int newKey);
    void setTruck(char newTruck);
    void setLeftNode(Node *newLeftNode);
    void setRightNode(Node *newRightNode);
    void setFatherNode(Node *newRatherNode);

    int getKey();
    char getTruck();
    Node* getLeftNode();
    Node* getRightNode();
    Node* getFatherNode();

    bool printInOrder();
};

class Tree{
  public:
    Node *root;
    Node* createNode(int key, char truck, Node *father);
    Node* insertNode(int key, char truck, Node *father, Node *current);
    Node* binarySearch(int key, Node *current);
};

extern Node nullNode;
