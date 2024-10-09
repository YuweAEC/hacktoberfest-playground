#include<iostream>
using namespace std;

int main(){
    //hollow half pyramid
    int n;
    cout<<"enter the value of n:";
    cin>>n;
    //outer loop
    for(int row=0;row<n;row++){
        //inner loop
        int totalColumns=row+1;
        for(int col=0;col<totalColumns;col++){
            if(row==0 || row==1 || row==n-1){
                cout<<"* ";
            }
            else{
                //middle rows
                if(col==0 || col==totalColumns-1){
                    cout<<"* ";
                }
                else{
                    cout<<"  ";
                }
            }
        }
        cout<<endl;
    }
    return 0;
}