#include <stdio.h>
#define MAX 100

int insert(int (*set)[MAX], int longitud, int numero){
int i, j;
	for(i = 0 ; i <= longitud ; i++){
		if(numero > (*set)[longitud]){
			(*set)[longitud+1]=numero;
			break;
		}
		else if(numero < (*set)[i]){
			for(j = (longitud+1) ; j > i ; j--){
				(*set)[j] = (*set)[j-1];
			}
			(*set)[i] = numero;
			break;
		}

	}
	longitud=longitud+1;
		return longitud;
		}

void impresion(int (*set)[MAX], int longitud){
	int i;
	for(i = 0 ; i <= longitud ; i++){
		printf("%d\t", (*set)[i]);
	}
}
	


int main(){

	int arr[MAX] = {-8, 1, 7, 17, 21, 54};
	int casos, cont = 5, num;

	scanf("%d", &casos);

	while(casos--){
		scanf("%d", &num);
		cont = insert(&arr, cont, num);
		impresion(&arr, cont);
	}

	return 0;
}