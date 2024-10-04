#include<stdio.h>

int search(int arr[],int size,int x){
    for(int i=0;i<size;i++){
        if(arr[i] == x){
            return i;
        }
       
    }
     return -1;
}

int main(){
    int arr[] = {1,443,52,55,56,623,733,7336};
    int size = sizeof(arr)/sizeof(int);
    int x =55;
    
    int ind = search(arr,size,x);
    printf("num %d found at position %d",x,ind+1);
}