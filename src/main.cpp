// Implementado por Eduardo Machado
// 2015

#include <iostream>
#include <stdio.h>
#include "bst_lib.h"

using namespace std;

Node nullNode;

int main(int argc, char *argv[]) {
  Tree binaryTree;
  char truck, comma1, comma2;
  string answer;
  int requestedTime, currentTime;

  binaryTree.root=&nullNode;

  while (scanf("%d %c %c %c %d\n", &currentTime, &comma1, &truck, &comma2, &requestedTime)!=EOF) {
    if (requestedTime < currentTime) {
      answer="NOK";
    }else if((binaryTree.binarySearch(requestedTime, binaryTree.root) == &nullNode)&&(binaryTree.binarySearch(requestedTime-1, binaryTree.root) == &nullNode)&&(binaryTree.binarySearch(requestedTime-2, binaryTree.root) == &nullNode)){
      binaryTree.root=binaryTree.insertNode(requestedTime, truck, &nullNode, binaryTree.root);
      answer="OK";
    }else{
      answer="NOK";
    }
    cout << truck << "," << answer << endl;
  }
  return 0;
}
