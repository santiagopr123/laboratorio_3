#include <iostream>

using namespace std;

void binarios();

int main()
{
    char letra = 'C';
    int numero = letra - 0,arreglo[8];

    cout<<"este es el numero que le corresponde a la letra: "<<letra-0<<endl;

    cout<<0;

    for(int i = 0; i<7; i++)
    {
        cout<<numero%2;
        numero = numero/2;
    }



    return 0;
}

void binarios()
{

}


