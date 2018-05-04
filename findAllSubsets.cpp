#include <bits/stdc++.h>

using namespace std;

void findAll(int array[], int limit, int index, vector <int> subset){
	
	if(index == limit){
		for(int i = 0 ; i < subset.size() ; i++){
			cout << subset[i] << " ";
		}cout << endl;
		return; 
	}else{
		findAll(array, limit, index + 1, subset);
		subset.push_back(array[index]);
		findAll(array, limit, index + 1, subset);	
	}
}

int main(){
	
	int array[6] = {1,2,3,4,5,6};
	vector <int> subset; 
	
	findAll(array, 6, 0, subset);
	
	return 0;
}
