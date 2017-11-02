#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

#define CAP 1000000

void *xcalloc(int nr_elements, size_t size_per_element); 
void input(int arr[], int nr_elements); 
void sort(int arr[], int nr_elements); 
void output(int arr[], int nr_elements); 

int main(int argc, char *argv[]){
	int *arr; 
	int nr_elements; 
	
	if(argc != 2){
		fprintf(stderr,"Usage Error: %s nr_elements\n", argv[0]); 
		exit(EXIT_FAILURE); 
	}

	nr_elements = atoi(argv[1]); 
	if(nr_elements <= 0)
		exit(EXIT_SUCCESS); 
	arr = (int*)xcalloc(nr_elements, sizeof(int)); 
	input(arr, nr_elements); 
	sort(arr, nr_elements); 
	output(arr, nr_elements); 

	exit(EXIT_SUCCESS); 
}

void sort(int arr[], int nr_elements){
	int i, j, key; 

	for(j=1; j < nr_elements; ++j){

		key = arr[j]; 
		i = j - 1; 

		while(i > -1 && arr[i] > key){
			arr[i+1] = arr[i]; 
			i = i - 1; 
		}

		arr[i+1] = key; 
	}
}

void *xcalloc(int nr_elements, size_t size_per_element){
	void *ptr = calloc(nr_elements, sizeof(int)); 
	if(!ptr){
		fprintf(stderr, "fatal:out of memory\n"); 
		exit(EXIT_FAILURE);
	}

	return(ptr); 
}

void input(int arr[], int nr_elements){
	int i; 
	
	srand(time(0)); 
	for(i=0; i < nr_elements; ++i)
		arr[i] = rand() % CAP; 

	return; 
}

void output(int arr[], int nr_elements){
	int i; 
	for(i=0; i < nr_elements; ++i)
		printf("arr[%d]:%d\n", i, arr[i]); 
}
