#include <stdlib.h>

#include <time.h>
#include<stdio.h>
#define MAX 101
int Post_office(int P[],int H[],int n){
    P[1]=H[1]+1000; 
	int m=1;
	int i;
	for(i=2;i<=n;i++){
        if(H[i]>P[m]+1000){
            m++;
			P[m]=H[i]+1000;
		}
	}
	if(P[m]>H[n])
	    P[m]=H[n];
 
	return m;
}
int main(){
    int P[MAX];
	int H[MAX];
	int n=4;
	int m=0;
	int min=0;
	int max=0;
	int r=0;
	
	printf("Please input the min value:\n");
	scanf("%d", &min);
	printf("Please input the max value:\n");
	scanf("%d", &max);
	
	
//	printf("Please input the quantity:\n");
//	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		r = rand()%(max - min + 1) + min;
		H[i] = r;
	}
	
//	printf("Please input the family`s distance:\n");
//	for(int i=1;i<=n;i++){
//        scanf("%d",&H[i]);
//	}
	m=Post_office(P,H,n);
    printf("There are %d post office,there are:\n",m);
	for(int i=1;i<=m;i++){
	    printf("%d ",P[i]);
	}
	
	
	return 0; 
}
