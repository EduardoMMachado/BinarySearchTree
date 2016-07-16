// Implementado por Eduardo Machado
// 2015

#include <iostream>
#include "bst_lib.h"

using namespace std;

// Funções do objeto Node.
void Node::setKey(int newKey){
  key=newKey;
}

void Node::setTruck(char newTruck){
  truck=newTruck;
}

void Node::setLeftNode(Node *newLeftNode){
  leftNode=newLeftNode;
}

void Node::setRightNode(Node *newRightNode){
  rightNode=newRightNode;
}

void Node::setFatherNode(Node *newFatherNode){
  fatherNode=newFatherNode;
}

int Node::getKey(){
  return(key);
}

char Node::getTruck(){
  return(truck);
}

Node* Node::getLeftNode(){
  return(leftNode);
}

Node* Node::getRightNode(){
  return(rightNode);
}

Node* Node::getFatherNode(){
  return(fatherNode);
}

// Funções de manipulação da árvore

bool Node::printInOrder(){
  if(this==&nullNode){
    return 0;
  }
  if(leftNode!=&nullNode){
    leftNode->printInOrder();
  }
  std::cout << truck << " " << key << std::endl;
  if(rightNode!=&nullNode){
    rightNode->printInOrder();
  }
  return 1;
}

Node* Tree::createNode(int key, char truck, Node *father){
  Node *aux=new Node;
  aux->setKey(key);
  aux->setTruck(truck);
  aux->setLeftNode(&nullNode);
  aux->setRightNode(&nullNode);
  aux->setFatherNode(father);
  return aux;
}

Node* Tree::insertNode(int key, char truck, Node *father, Node *current){
  if(current==&nullNode){
    current=createNode(key, truck, father);
  }else if(current->getKey() > key){
    current->setLeftNode(insertNode(key, truck, current, current->getLeftNode()));
  }else if(current->getKey() < key){
    current->setRightNode(insertNode(key, truck, current, current->getRightNode()));
  }else{
    return &nullNode;
  }
  return current;
}

Node* Tree::binarySearch(int key, Node *current){
  if(current==&nullNode){
    return(&nullNode);
  }else if(current->getKey() > key){
    return(binarySearch(key,current->getLeftNode()));
  }else if(current->getKey() < key){
    return(binarySearch(key, current->getRightNode()));
  }else if(current->getKey() == key){
    return(current);
  }
  return(&nullNode);
}
