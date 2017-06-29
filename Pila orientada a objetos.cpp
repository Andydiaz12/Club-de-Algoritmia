#include <cstdio>
#include <cstdlib>

using namespace std;

class nodo{
	public:
		int valor;
		nodo *next;

		nodo(int x){
			valor = x;
			next = NULL;
		}
};

class pila{
	public:
		nodo *top;
		int num;
		pila(void){
			top=NULL;
		}

		int pop(pila s){
			nodo *temp;
			if(isEmpty(s)){
				exit(1);
			}
			else{
			num = top->valor;
			temp = top;
			top = top->next;
			delete(temp);
			return num;
			}

		}

		void push(pila s, int x){
			nodo *temp = new nodo(x);
			if(!isEmpty(s))
				temp->next=top;
			top = temp;
		}

		bool isEmpty(pila s){
			return (s.top == NULL);
		}


};

int main(){
	int x;
	pila stack;
	while(scanf("%d",&x)&&x!=0){
		stack.push(stack,x);

	}
	while(stack.top != NULL){
		printf("%d\n",stack.pop(stack));
	}
	return 0;
}