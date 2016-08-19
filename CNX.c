#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void com(int arr[], int data[], int start, int end, int index, int r){
        int j;
	if(index == r){
		FILE*fd=fopen("CN.txt","a");
		for( j=0;j<r;j++)
			fprintf(fd,"%d ",data[j]);
			fprintf(fd,"\n");
		}
	for(int i = start;i <= end && end-i+1 >= r-index;i++){
	                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       	data[index] = arr[i];
		com(arr, data, i+1, end, index+1, r);
	}
}

void print(int arr[], int n, int r){
	int data[r];
	com(arr, data, 0, n-1, 0, r);
}

int main(){
	//int e,r,a[];
	//char arr[100];
	//FILE*fp=fopen("CN1.txt","r");
	//	while(fgets(arr , 10 , fp)!=NULL){
	//		e=atoi(arr);
	//		a[i]=
	//	}
	int arr[]={2,3,4,5,6};
	int r;
	FILE*fd=fopen("CN.txt","w");
	fclose(fd);
	printf("CNX,Please enter X\n");
	scanf("%d",&r);
	int n = sizeof(arr)/sizeof(arr[0]);
	print(arr, n, r);

}
