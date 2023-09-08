#include <iostream>

using namespace std;
bool compararCadenas(const char *cadena1, const char *cadena2);


int main()
{
    while(true){
        int opcion;
        //Menú de opciones
        cout << "EJERCICIOS DISPONIBLES" << endl;
        cout << "1. Problema 2" << endl;
        cout << "2. Problema 3" << endl;


        cout << "0. Salir" << endl;
        cout << "Ingrese el numero del ejercicio: ";
        cin >> opcion;

        switch(opcion){
        case 1:{
            cout << "Has escogido problema 2" << endl;
            char letras[200];

            for (int i = 0; i < 200; i++){
                letras[i] = 'A' + rand() % 26; //Genera letras aleatorias de la 'A' a la Z

            }
            //Mostrar arreglo de letras
            for (int i = 0; i < 200; i++){
                cout << letras[i];
            }
            cout << endl;

            //Arreglo para contar la frecuencia de las letras
            int frecuencia[26] = {0};

            for (int i = 0; i < 200; i++){
                int indice = letras[i] - 'A'; //
                frecuencia[indice]++;

            }

            //Mostrar la frecuencia de cada letra
            for (char letra = 'A'; letra <= 'Z'; letra++){
                int indice = letra - 'A';
                if (frecuencia[indice] > 0){
                    cout << letra << ": " << frecuencia[indice] << endl;
                }

            }

            break;

        }
        case 2: {
            cout << "Has escogido el problema 3" << endl;

            const char *cadena1 = "Hola, mundo!";
            const char *cadena2 = "Hola, mundo!";
            const char *cadena3 = "Hola";

            if (compararCadenas(cadena1,cadena2)){
                cout << "cadena1 y cadena2 son iguales." << endl;

            } else{
                cout << "cadena1 y cadena2 no son iguales." << endl;

            }

            if(compararCadenas(cadena1, cadena3)){
                cout << "cadena1 y cadena3 son iguales." << endl;

            }else{
                cout << "cadena1 y cadena3 no son iguales." << endl;
            }
            break;
        }
        case 0: {
            cout << "Saliendo del programa." << endl;
            return 0;
        }
        default:
            cout << "Opcion no valida. Por favor ingresa un numero valido." << endl;
        }

    }
    return 0;
}
bool compararCadenas(const char *cadena1, const char *cadena2){
    while (*cadena1 && *cadena2){
        if (*cadena1 != *cadena2){
            return false;
        }
        cadena1++;
        cadena2++;
    }
    return (*cadena1 == *cadena2);
}
