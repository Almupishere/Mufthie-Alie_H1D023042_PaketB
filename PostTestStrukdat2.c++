#include <iostream>
using namespace std;


struct stack
{
    int data[10]={34,21,13,8,5,3,2,1,1,0};
    int count; 
};

stack tumpukan;
void inisiasi(stack *x){ 
    x->count=0;
}

void push(int n,stack *x)
{
    if (x->count==10)
    {
        cout<< " sudah full \n";
    }else
    {
        x->data[x->count]= n;
        x->count ++;
    }
}

void cetak(stack *x){

    for(int i=x->count+1; i>=0; i++){
        cin >> i;
        cout<<x->data[i]<<"\n";
    }
}

int main(){
    inisiasi(&tumpukan);
    cetak(&tumpukan);
}