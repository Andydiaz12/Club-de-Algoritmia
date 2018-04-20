#include <bits/stdc++.h>

using namespace std;

typedef struct tree{
	struct tree *left;
	struct tree *right;
	char ch;
}binaryTree, *binaryTreePtr;

binaryTreePtr buildBinaryTree(){
	
	char ch;
	binaryTreePtr subTree = new binaryTree;
	
	if(cin >> ch){
		if(ch == '@')
			return NULL;
			
		subTree -> ch = ch;
		subTree -> left = buildBinaryTree();
		subTree -> right = buildBinaryTree();
	}
	
	return subTree;
}

void visit(binaryTreePtr nodo){
	cout << nodo -> ch << " ";
}

void preOrder(binaryTreePtr nodo){
	if(nodo != NULL){
		visit(nodo);
		preOrder(nodo -> left);
		preOrder(nodo -> right);
	}
}

void postOrder(binaryTreePtr nodo){
	if(nodo != NULL){
		postOrder(nodo -> left);
		postOrder(nodo -> right);
		visit(nodo);
	}
}

void inOrder(binaryTreePtr nodo){
	if(nodo != NULL){
		inOrder(nodo -> left);
		visit(nodo);
		inOrder(nodo -> right);
	}
}

int main(){
		
	freopen("input.txt", "r", stdin);
	binaryTreePtr bt;
	char ch;
	
	
	bt = buildBinaryTree(); 
	
	cout << "Pre-order = ";
	preOrder(bt);
	cout << "\n";
	
	cout << "Post-order = ";
	postOrder(bt);
	cout << "\n";
	
	cout << "In-order = ";
	inOrder(bt);
	cout << "\n";
	
	fclose(stdin);	
		
	return 0;
}
