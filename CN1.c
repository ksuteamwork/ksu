#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
int a[]={1,4,9,12};
int x,y,z,N;

//scanf("%d",&N);
N = sizeof(a)/sizeof(int);
	for(x=0;x<N;x++){
		for(y=x+1;y<N;y++){
  			for(z=y+1;z<N;z++){
				//if(a[x]+a[y]+a[z]==14){
				printf("%d %d %d\n",a[x],a[y],a[z]);
				}
			}
		}
	}
}

