#include <bits/stdc++.h>

using namespace std;

const int limit = 1e6;
bool isPrime[limit];
vector <int> primes;

typedef struct{
	int prime, potencia;
}elemento;

vector <elemento> factorizacion;

void sieve(){
	for(int i = 2 ; i < limit ; i++){
		if(!isPrime[i]){
			primes.push_back(i);
			for(int j = i * 2 ; j < limit ; j += i){
				isPrime[j] = true;
			}
		}
	}	
}

void factorizar(int n){
	int cont;
	for(int i = 2 ; i * i <= n ; i++){
		if(n % i == 0){
			cont = 0;
			while(n % i == 0){
				++cont;
				n /= i;
			}
			cout << i << " " << cont << endl;
		}
	}
	if(n != 1)
		cout << n << " " << "1" << endl;
}

void factorizarCriba(int n){
	int index = 0, contador;
	
	factorizacion.clear();
	elemento temp;
	
	while(primes[index] <= sqrt(n)){
		if(n % primes[index] ==  0){
			contador = 0;
			while(n % primes[index] == 0){
				n /= primes[index];
				contador++;
			}
			
			temp.prime = primes[index];
			temp.potencia = contador;
			factorizacion.push_back(temp);
		}		
		++index;
	}
		if(n != 1){
			temp.prime = n;
			temp.potencia = 1;
			factorizacion.push_back(temp);
		}
			
}

int phi(int n){
	factorizarCriba(n);
	double resultado = n;
	
	for(int i = 0 ; i < factorizacion.size(); i++)
		resultado *= (1.0 - (1.0 / (double)factorizacion[i].prime));
	
	return resultado;
}

int main(){
	
	int n = 25;
	
	sieve();
	cout << phi(n) << endl;
	
	return 0;
}
