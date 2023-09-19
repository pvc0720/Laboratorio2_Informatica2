#include <iostream>
using namespace std;
bool compararCadenas(const char *cadena1, const char *cadena2);
int cadenaAEntero(const char *cadena);
void enteroACadena(int numero, char*& cadena);


int main()
{
    while(true){
        int opcion;
        //Menú de opciones
        cout << "EJERCICIOS DISPONIBLES" << endl;
        cout << "1. Problema 2" << endl;
        cout << "2. Problema 3" << endl;
        cout << "3. Problema 4" << endl;
        cout << "4. Problema 5" << endl;
        cout << "5. Problema 7" << endl;
        cout << "6. Problema 8" << endl;


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
        case 3:{
            cout <<"Has escogido el problema 4."<< endl;
            const char *cadena = "12345"; // Ejemplo de cadena de caracteres numéricos

            int numero = cadenaAEntero(cadena);

            cout << "El numero entero convertido desde la cadena es: " << numero << endl;

            break;
        }
        case 4: {


            int numero = 123;
            char* cadena = nullptr;
            cout << "Has elegido el problema 5." << endl;
            enteroACadena(numero, cadena);
            cout << "cadena: " << cadena << endl;

            delete[] cadena;

            break;
        }

        case 5:{
            cout << "Has escogido el problema 7 " << endl;
            const int MAX_CARACTERES = 256;
            char cadena[MAX_CARACTERES];
            cin.ignore(); // Agregar esta línea para eliminar el carácter de nueva línea en el búfer
            cout << "Ingrese una cadena de caracteres: ";
            cin.getline(cadena, MAX_CARACTERES); // Leer la cadena con espacios

            cout << "Original: " << cadena << endl;

            int len = 0;

            for (int i = 0; cadena[i] != '\0'; i++) {
                char caracter = cadena[i];
                bool repetido = false;

                // Verificar si el carácter ya está en la cadena resultante
                for (int j = 0; j < len; j++) {
                    if (cadena[j] == caracter) {
                        repetido = true;
                        break;
                    }
                }

                // Si no es un carácter repetido, agregarlo a la cadena resultante
                if (!repetido) {
                    cadena[len] = caracter;
                    len++;
                }
            }

            // Terminar la cadena resultante con un carácter nulo
            cadena[len] = '\0';

            cout << "Sin repetidos: " << cadena << endl;

            break;
        }
        case 6:{
            cout << "Has escogido el problema 8. " << endl;

            const int MAX_CARACTERES = 256;
            char cadena[MAX_CARACTERES];
            cin.ignore(); // Agregar esta línea para eliminar el carácter de nueva línea en el búfer

            cout << "Ingrese una cadena de caracteres: ";
            cin.getline(cadena, MAX_CARACTERES);

            cout << "Orginal: " << cadena << "." << endl;

            char texto[MAX_CARACTERES] = "";
            char numero[MAX_CARACTERES] = "";

            int lenTexto = 0;
            int lenNumero = 0;

            for (int i = 0; cadena[i] != '\0'; i++){
                char caracter = cadena[i];
                if (caracter >= '0' && caracter <= '9'){
                    numero[lenNumero] = caracter;
                    lenNumero++;
                } else {
                    texto[lenTexto] = caracter;
                    lenTexto++;
                }
            }

            texto[lenTexto] = '\0';
            numero[lenNumero] = '\0';

            cout << "Texto: " << texto << ". Numero: " << numero << "." << endl;

            break;
        }


        case 0: {
            cout << "Saliendo del programa." << endl;
            return 0;
        }
        default:{
            cout << "Opcion no valida. Por favor ingresa un numero valido." << endl;
        }

    }

}
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

int cadenaAEntero(const char *cadena) {
    int numero = 0;
    int indice = 0;
    int signo = 1;

    // Manejar el signo si la cadena comienza con '+' o '-'
    if (cadena[0] == '+') {
        indice++;
    } else if (cadena[0] == '-') {
        signo = -1;
        indice++;
    }

    // Recorrer la cadena y construir el número entero
    while (cadena[indice] != '\0') {
        if (cadena[indice] >= '0' && cadena[indice] <= '9') {
            numero = numero * 10 + (cadena[indice] - '0');
        } else {
            // Si se encuentra un carácter no numérico, salir del bucle
            break;
        }
        indice++;
    }

    // Aplicar el signo al resultado
    numero *= signo;

    return numero;
}


void enteroACadena(int numero, char*& cadena){
    int n = numero;
    int digitos = 0;

    while (n != 0){
        n /= 10;
        digitos++;
    }
    cadena = new char[digitos +1];
    n = numero;
    for (int i = digitos -1; i >= 0; i--){
        cadena[i] = '0' + (n % 10);
        n /= 10;

    }
    cadena[digitos] = '\0';

}
