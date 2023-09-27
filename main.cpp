#include <iostream>
using namespace std;
bool compararCadenas(const char *cadena1, const char *cadena2);
int cadenaAEntero(const char *cadena);
void enteroACadena(int numero, char*& cadena);

const int FILAS = 6;
const int COLUMNAS = 8;

int contarEstrellas(int (*matriz)[COLUMNAS]) {
    int contador = 0;

    for (int i = 1; i < FILAS - 1; i++) {
        for (int j = 1; j < COLUMNAS - 1; j++) {
            int suma = matriz[i][j] + matriz[i][j-1] + matriz[i][j+1] + matriz[i-1][j] + matriz[i+1][j];
            if (suma / 5 > 6) {
                contador++;
            }
        }
    }

    return contador;
}
const int filas = 5;
const int columnas = 5;

// Función para imprimir una matriz
void imprimirMatriz(int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
}

// Función para rotar una matriz 90 grados en sentido horario
void rotar90Grados(int matriz[filas][columnas]) {
    int matrizRotada[columnas][filas];

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matrizRotada[j][filas - 1 - i] = matriz[i][j];
        }
    }

    // Copiamos la matriz rotada de vuelta a la matriz original
    for (int i = 0; i < columnas; i++) {
        for (int j = 0; j < filas; j++) {
            matriz[i][j] = matrizRotada[i][j];
        }
    }
}

// Función para calcular el número de caminos posibles en una cuadrícula de nxn
unsigned long long calcularCaminos(int n) {
    // Creamos una matriz para almacenar los resultados
    unsigned long long caminos[n + 1][n + 1];

    // Inicializamos la primera fila y la primera columna con 1
    for (int i = 0; i <= n; i++) {
        caminos[0][i] = 1;
        caminos[i][0] = 1;
    }

    // Llenamos la matriz utilizando programación dinámica
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            caminos[i][j] = caminos[i - 1][j] + caminos[i][j - 1];
        }
    }

    return caminos[n][n];
}

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
        cout << "7. Problema 9" << endl;
        cout << "8. Problema 11" << endl;
        cout << "9. Problema 12" << endl;
        cout << "10. Problema 13" << endl;
        cout << "11. Problema 14" << endl;
        cout << "12. Problema 16" << endl;


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
        case 7: {
            cout << "Ha seleccionado el problema 9." << endl;
            // Declaramos las variables

            int n;
            string numero;
            int suma = 0;

            // Pedimos al usuario que ingrese el número n
            cout << "Ingrese el numero n: ";
                    cin >> n;

            // Pedimos al usuario que ingrese el número
            cout << "Ingrese el numero: ";
                    cin >> numero;

            // Verificamos si la longitud de la cadena es divisible por n
            int longitud = numero.length();
            if (longitud % n != 0) {
                // Si no es divisible, agregamos un cero a la izquierda
                int ceros_a_agregar = n - (longitud % n);
                string ceros(ceros_a_agregar, '0');
                numero = ceros + numero;
            }

            // Separamos el número en números de n cifras y calculamos la suma
            for (int i = 0; i < numero.length(); i += n) {
                string numero_n = numero.substr(i, n);
                int num = stoi(numero_n);
                suma += num;
            }

            // Imprimimos el resultado
            cout << "Original: " << numero << endl;
            cout << "Suma: " << suma << endl;


            break;
        }
        case 8: {
            cout << "Has elegido el problema 11 (sala de cine)." << endl;


            const int FILAS = 15;
            const int ASIENTOS_POR_FILA = 20;

            // Matriz para representar la sala de cine
            char sala[FILAS][ASIENTOS_POR_FILA];

            // Inicializar la sala con asientos disponibles
            for (int i = 0; i < FILAS; i++) {
                for (int j = 0; j < ASIENTOS_POR_FILA; j++) {
                    sala[i][j] = '-';
                }
            }

            char fila;
            int numeroAsiento;

            while (true) {
                // Mostrar la sala de cine
                for (int i = 0; i < FILAS; i++) {
                    for (int j = 0; j < ASIENTOS_POR_FILA; j++) {
                        cout << sala[i][j] << " ";
                    }
                    cout << endl;
                }

                // Pedir al usuario que ingrese la fila y el número del asiento
                cout << "Para ingresar la fila use letras mayusculas. ";
                cout << "Ingrese la fila (A-O) y el numero del asiento (1-20): ";
                        cin >> fila >> numeroAsiento;

                // Verificar si el asiento está disponible o reservado
                if (fila >= 'A' && fila <= 'O' && numeroAsiento >= 1 && numeroAsiento <= 20) {
                    int filaIndex = fila - 'A';
                    int asientoIndex = numeroAsiento - 1;

                    if (sala[filaIndex][asientoIndex] == '-') {
                        // El asiento está disponible, reservarlo
                        sala[filaIndex][asientoIndex] = '+';
                        cout << "Reserva exitosa." << endl;
                    } else if (sala[filaIndex][asientoIndex] == '+') {
                        // El asiento está reservado, cancelar la reserva
                        sala[filaIndex][asientoIndex] = '-';
                        cout << "Cancelación de reserva exitosa." << endl;
                    } else {
                        // El usuario ingresó una fila o un número de asiento inválido
                        cout << "Fila o número de asiento inválido." << endl;
                    }
                } else {
                    // El usuario ingresó una fila o un número de asiento inválido
                    cout << "Fila o número de asiento inválido." << endl;
                }
            }



            break;
        }
        case 9:{
            cout << "Has elegido el problema 12 (Cuadrado magico). " << endl;
            // Declaramos las variables
            int n;
            int matriz[10][10];
            int suma_filas[10], suma_columnas[10], suma_diagonales[2];

            // Pedimos al usuario que ingrese el tamaño de la matriz
            cout << "Ingrese el tamaño de la matriz: ";
                    cin >> n;

            // Pedimos al usuario que ingrese los números de la matriz
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << "Ingrese el numero en la posición (" << i << "," << j << "): ";
                    cin >> matriz[i][j];
                }
            }

            // Calculamos las sumas de las filas, columnas y diagonales
            for (int i = 0; i < n; i++) {
                suma_filas[i] = 0;
                for (int j = 0; j < n; j++) {
                    suma_filas[i] += matriz[i][j];
                }
            }

            for (int i = 0; i < n; i++) {
                suma_columnas[i] = 0;
                for (int j = 0; j < n; j++) {
                    suma_columnas[i] += matriz[j][i];
                }
            }

            suma_diagonales[0] = 0;
            for (int i = 0; i < n; i++) {
                suma_diagonales[0] += matriz[i][i];
            }

            suma_diagonales[1] = 0;
            for (int i = 0; i < n; i++) {
                suma_diagonales[1] += matriz[i][n - i - 1];
            }

            // Verificamos si la matriz es un cuadrado mágico
            bool es_cuadrado_magico = true;
            for (int i = 0; i < 2; i++) {
                if (suma_diagonales[i] != suma_filas[0]) {
                    es_cuadrado_magico = false;
                    break;
                }
            }

            for (int i = 1; i < n; i++) {
                if (suma_filas[i] != suma_filas[0] || suma_columnas[i] != suma_filas[0]) {
                    es_cuadrado_magico = false;
                    break;
                }
            }

            // Imprimimos la matriz
            cout << endl;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << matriz[i][j] << " ";
                }
                cout << endl;
            }

            // Imprimimos el resultado
            if (es_cuadrado_magico) {
                cout << "La matriz es un cuadrado magico." << endl;
            } else {
                cout << "La matriz no es un cuadrado magico." << endl;
            }
            break;
        }
        case 10:{
            cout << "Has elegido el problema 13. " << endl;
            int matriz[FILAS][COLUMNAS] = {
                {0, 3, 4, 0, 0, 0, 6, 8},
                {5, 13, 6, 0, 0, 0, 2, 3},
                {2, 6, 2, 7, 3, 0, 10, 0},
                {0, 0, 4, 15, 4, 1, 6, 0},
                {0, 0, 7, 12, 6, 9, 10, 4},
                {5, 0, 6, 10, 6, 4, 8, 0}
            };

            int estrellas = contarEstrellas(matriz);
            cout << "Número de estrellas encontradas: " << estrellas << endl;

            break;
        }
        case 11: {
            cout << "Has elegido el problema 14 (Matriz rotada). " << endl;
            int matriz[filas][columnas];

            // Llenar la matriz con los números del 1 al 25
            int contador = 1;
            for (int i = 0; i < filas; i++) {
                for (int j = 0; j < columnas; j++) {
                    matriz[i][j] = contador;
                    contador++;
                }
            }

            // Imprimir la matriz original
            cout << "Matriz Original:" << endl;
            imprimirMatriz(matriz);

            // Rotar 90 grados y mostrar
            cout << "\nMatriz Rotada 90 Grados:" << endl;
            rotar90Grados(matriz);
            imprimirMatriz(matriz);

            // Rotar 180 grados y mostrar
            cout << "\nMatriz Rotada 180 Grados:" << endl;
            rotar90Grados(matriz);
            rotar90Grados(matriz);
            imprimirMatriz(matriz);

            // Rotar 270 grados y mostrar
            cout << "\nMatriz Rotada 270 Grados:" << endl;
            rotar90Grados(matriz);
            rotar90Grados(matriz);
            rotar90Grados(matriz);
            imprimirMatriz(matriz);

            break;
        }
        case 12: {
            int n;
            cout << "Has elegido el problema 16. " << endl;
            cout << "Ingrese el tamanio de la cuadricula (n): ";
            cin >> n;

            // Calculamos el número de caminos posibles
            unsigned long long numCaminos = calcularCaminos(n);

            cout << "Para una malla de " << n << "x" << n << " puntos hay " << numCaminos << " caminos." << endl;
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



