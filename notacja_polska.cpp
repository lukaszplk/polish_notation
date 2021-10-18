#include<iostream>
#include <ctype.h>
using namespace std;

class Stack{
    public:
    int index=0, *tab = new int [0];
    
    void push(int num){
        int *tmp = new int [index+1];
        for(int i=0;i<index;i++){
            tmp[i] = this->tab[i];
        }
        tmp[index] = num;
        this->index++;
        delete [] this->tab;
        this->tab = tmp;
        delete [] tmp;  
    }

    int pop(){
        int num;
        index--;
        num = tab[index];
        int *tmp = new int[index];
        for(int i=0;i<index;i++){
            tmp[i] = this->tab[i];
        }
        delete [] this->tab;
        this->tab = tmp;
        delete [] tmp;
        return num;
    }

    void show(){
        for(int i=0;i<this->index;i++){
            cout<<this->tab[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Stack stos;
    char fig;
    //dziala na cyfrach
    while(cin>>fig){
        if(isdigit(fig)){
            stos.push(int(fig)-48);
        }else if(fig=='+'){
            stos.push(stos.pop() + stos.pop());
        }else if(fig=='-'){
            stos.push(stos.pop() - stos.pop());
        }else if(fig=='/'){
            stos.push(stos.pop() / stos.pop());
        }else if(fig=='*'){
            stos.push(stos.pop() * stos.pop());
        }
    }
    
    stos.show();

    return 0;
}