#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 10;
int tree[maxn] = {0};
int sz=0;

int parent(int index){
    return (index-1)/2;
        }
        
int right_child(int index){
    return ((index*2)+2);
}

int left_child(int index){

    return ((index*2)+1);
}

bool hasParent(int index){
        return parent(index)>= 0;
}

bool askleft(int index){
    return left_child(index)<sz;
}

bool askright(int index){
    return right_child(index)<sz;
}

int getMin(){
    if(sz==0){
        printf("Esta Vacio ;V prro como su corazaoo\n");
        return 666;
    }else{
    return tree[0];
    }
}

void swap(int child, int parent){
    int temp = tree[parent];
    tree[parent] = tree[child];
    tree[child] = temp;
}

void insert(int value){

    int index=sz;
    tree[sz] = value;
   
    while(hasParent(index)){
        if(tree[parent(index)] > tree [index]){
            swap(index,parent(index));
            index = parent(index);
        }else
        break;
    }
    ++sz;
}

int erase(){
	int temp = tree[0], index = 0, minChild;
	tree[0] = tree[--sz];
	
	while(askleft(index)){
		minChild = left_child(index);
		if(askright(index) && tree[right_child(index)] < tree[minChild])
			minChild = right_child(index);
		if(tree[minChild] < tree[index]){
			swap(index, minChild);
		}else{
			break;
		}
		
		index = minChild;
	}
	
	return temp;
}


int main (){
	
	int arr[10], i, numero;
	
	for(i = 0 ; i < 10 ; i++){
		scanf("%d", &numero);
		insert(numero);
	}
	
	while(sz != 0){
		printf("%d\n", erase());
	}
	

    return 0;
}

