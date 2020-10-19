#include <iostream>
#include <fstream>
#include<string>

using namespace std;

void nombres(string);
void conversion_binario(char);
void invertir_binario(int, int *);

int main()
{   
    string nombre;
    getline(cin, nombre);

    //int arreglo[8] = {0,1,1,1,0,0,1,1}, x = 3;
    nombres(nombre);

    //invertir_binario(x, arreglo);


    return 0;
}


void conversion_binario(char letra)
{
        ofstream escribir;//para ingresar los valores al fichero

        int numero = letra - 0,arreglo[8], modulo = 0,n_bits = 0;//conversion de la letra a numero en decimal

        cout<<"la letra es: "<<letra<<" este es el numero que le corresponde a la letra: "<<letra-0<<endl;
        cout<<"ingrese la cantidad de bits en la cual se repartira: ";cin>>n_bits;

        *(arreglo+0) = 0;

        escribir.open("archivo.txt");

        for(int i = 7; i>0; i--)
        {
            modulo = numero%2;
            *(arreglo+i) = modulo;
            numero = numero/2;
        }

        invertir_binario(n_bits, arreglo);



}

void nombres(string name)
{
    int longitud = name.length();

    for(int i = 0; i<longitud;i++  )
    {
        conversion_binario(name[i]);
    }
}

void invertir_binario(int n , int *array)
{
    /*
        funcion donde se inverte cada caracter que esta en binario decimal
    */
    int clon[8],auxiliar = 8, i = 0,constante2 = 0,auxiliar2 = n;

    for(int j = 0; j<8; j++)//ciclo para crear un clon del arreglo con los numeros en binario
    {
        *(clon+j) = *(array+j);
        cout<<*(clon+j);
    }

    cout<<"AQUI EMPIEZA EL INTERCAMBIO: "<<endl;

    while(auxiliar >= 0)
    {

        for(int constante = n-1; i<n; i++)//ciclo para el intercambio de los numeros binarios en funcion de n
        {
            *(array+i) = *(clon+(constante-constante2));
            cout<<*(array+i)<<endl;
            auxiliar--;
            constante2++;

        }
        n = n+auxiliar2;//se reinician las variables con que se invierte cada n bits
        constante2 = 0;
        if(n>8)//condicional para que no se salga del arreglo
        {
            n = 8;
        }
        //auxiliar2--;

    }


    cout<<endl<<endl;
    for(int i = 0; i<8; i++)
    {
        cout<<*(array+i);
    }
    cout<<endl;

}


