#include <iostream>

using namespace std;

template <class T>
class des{
    T x , y ;
    public:
        des(){};
        des(T A , T B): x(A) , y(B) {};
        bool operator()(int* a , int* b){
            return *a < *b;
        }
};
template <class T>
class asc{
    T x , y ;
    public:
        asc(){};
        asc(T A , T B): x(A) , y(B) {};
        bool operator()(int* a , int* b){
            return *a > *b;
        }
};

template <class T , class G >
void burbuja(T *arr , int n , G comp ){
    T aux , *fin =  arr +  n - 1 ;  

    for(int *i = arr; i < fin ; i++ ){
        for(int *j = arr  ; j < fin ; j++)
            if(comp(j,(j+1))){
                aux = *j;
                *j = *(j+1);
                *(j+1) = aux;
        }
    }
}

void mostrar(int * arr,int n){
    int *fin = arr + n ; 
    for(int *i = arr ; i < fin ; i++)
        cout << *i << '\t';
    cout << endl;
}

int main(){

    int arr[10]= {3,4,5,6,7,8,9,1,2,0};
    int *ptr1 = arr;
    des <int> tem1 ; 
    burbuja(ptr1 , 10 , tem1 );
    mostrar(ptr1 ,10);

    cout << "--------------------------------------------------------------------------------" << endl;

    int arr2[10]= {3,4,5,6,7,8,9,1,2,0};
    int *ptr2 = arr2;
    asc <int> tem2 ; 
    burbuja(ptr2 , 10 , tem2 );
    mostrar(ptr2 ,10);


    return 0;
}