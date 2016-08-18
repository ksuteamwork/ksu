#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
char buffer[10];
int a[100];
//int a[]={1,4,9,12,20,6,7};
int x,y,z,N,m,i=0;

scanf("%d",&N);
//N = printf("%d\n",sizeof(a)/sizeof(int));
FILE *fp;
FILE *fb;

fb = fopen("CN0.txt","r");
fp = fopen("CN.txt","w");
memset(a,0,sizeof(a));
	while(fgets(buffer,100,fb)!=NULL){
	m = atoi(buffer);
	a[i]=m;
	i++;
	printf("%d",a[i]);
	}
	for(x=0;x<N;x++){
		for(y=x+1;y<N;y++){
			for(z=y+1;z<N;z++){
				if(a[x]+a[y]+a[z]==14){
				fprintf(fp,"%d %d %d\n",a[x],a[y],a[z]);
				printf("%d %d %d\n",a[x],a[y],a[z]);
				}
			}
		}
	}
}
