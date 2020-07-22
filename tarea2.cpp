#include <iostream>

using namespace std;

template <class T , class G>
class functor{
    G comp ;
    public:
    functor(G c): comp(c) {};
    void burbuja(T *arr , int n ){         
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
};

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

void mostrar(int * arr,int n){
    int *fin = arr + n ; 
    for(int *i = arr ; i < fin ; i++)
        cout << *i << '\t';
    cout << endl;
}

int main(){
    int arr[10]= {3,4,5,6,7,8,9,1,2,0};

    des <int> tem1 ;
    functor<int,des<int>> a(tem1);

    a.burbuja(arr,10);
    mostrar(arr,10);

    cout << "--------------------------------------------------------------------------------" << endl;

    int arr2[10]= {3,4,5,6,7,8,9,1,2,0};

    asc <int> tem2 ;
    functor<int,asc<int>> b(tem2);

    b.burbuja(arr,10);
    mostrar(arr,10);

    return 0;
}