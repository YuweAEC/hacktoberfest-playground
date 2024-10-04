#include<stdio.h>

int main(){

    int N;
    printf("Enter Size of Array\t");
    scanf("%d",&N);

    int arr[N];
    printf("enter numbers\n");

    for(int b=0;b<N;b++){
        scanf("%d",&arr[b]);
    }
    
  
    int temp;

    for(int i=0;i<N-1;i++){
        for(int j=0;j<N-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                
            }
        }
    }
    for(int a=0;a<N;a++){
    printf("%d ",arr[a]);
    }
}