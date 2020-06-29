

/*
 * File:   main.cpp
 * Author: CarlosGutierrez
 * A console-game based on Battleship
 * Not using POO
 * Created on 27 de junio de 2020, 11:27
 */

/*
 * Licencia libre con atribucion o nombramiento del autor
 */

#include <cstdlib>
#include <iostream>
#include <string>
//se importa time.h para ser usado en random
#include <time.h>
#include <stdio.h>




using namespace std;

//Tablero donde se colocaran los barcos y aviones
char TableroPrincipalP1[19][19];
char TableroPrincipalP2[19][19];
//Tablero donde se colocaran las jugadas
char TableroJugadasP1[19][19];
char TableroJugadasP2[19][19];

string Nombrejugador1 = "1";
string Nombrejugador2 = "2";

int Puntajejugador1 = 0;
int Puntajejugador2 = 0;

int CantidadjugadasMax = 0;
int CantidadJugadasAct = 0;

int CantidadPiezasDestruidasP1=0;
int CantidadPiezasDestruidasP2=0;

bool VerificarSiYaEstaOcupado(const int &Jugador, const int &randomi, const int &randomj) {
    /*
     * Funcion encargada de verificar si en los alrededores de las posiciones recibidas(random)
     * hay alguna otra pieza ya colocada en el tablero
     */
    for (int i = -2; i < 3; i++) {
        for (int j = -2; j <3; j++) {
            if (Jugador == 1) {
                if (TableroPrincipalP1[randomi + i][randomj + j] == 'X' || TableroPrincipalP1[randomi + i][randomj + j] == 'O'
                        || randomi>16 || randomj>16) {
                    return true;
                    
                }else if(i==2 && j==2){
                    //En caso de que se verifiquen todas las combinaciones posibles
                    //y no se encuentre ninguna pieza en el tablero se retorna false
                    //para terminar la operacion de la funcion
                    return false;
                } 
            } else {
                if (TableroPrincipalP2[randomi + i][randomj + j] == 'X' || TableroPrincipalP2[randomi + i][randomj + j] == 'O'
                        || randomi>17 || randomj>17) {
                    return true;
                    
                }else if(i==2 && j==2){
                    //En caso de que se verifiquen todas las combinaciones posibles
                    //y no se encuentre ninguna pieza en el tablero se retorna false
                    //para terminar la operacion de la funcion
                    return false;
                } 
            }
        }
    }
}

void RellenarP1() {
    /*Funcion para llenar el tablero principal con las fichas*/
    int randomi = 0, randomj = 0, jugador = 1;
    //se llama e inicia para generar numeros random, basados en tiempo
    srand(time(0));

    //ciclo de 8 posiciones. 4 barcos y 4 Aviones
    for (int t = 0; t < 8; t++) {
        //Se solicita un numero random, entre 1 y 17
        randomi = (1 + (rand() % 17));
        randomj = (1 + (rand() % 17));
        //Se verifica que no hallan otras fichas en el tablero
        //Si se cumple la condicion se devuelve el ciclo
        
        
        if (VerificarSiYaEstaOcupado(jugador, randomi, randomj)) {
            //En caso de estar ocupada la posicion se devuelve el ciclo
            //generandose nuevos numeros random
            t = t - 1;
        } else {
            
            //se inicia a colocar los barcos en el tablero
            if (t < 4) {

                int n = 0;
                //ciclo anidado para llenar segun la posicion random en forma de cuadrado
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        TableroPrincipalP1[randomi + x][randomj + y] = 'X';
                        if (x == 1 && y == 1) {
                            //Se cambia la X de la posicion randomi+1 y randomj+1
                            //por un O. Siendo el centro de la pieza
                            TableroPrincipalP1[randomi + 1][randomj + 1] = 'O';
                        } 
                    }
                }
            } else {
                //se continua colocando los aviones en el tablero
                for (int y = 0; y < 3; y++) {
                   
                    //ciclo para colocar x primero de forma horizontal ---> XXX
                    TableroPrincipalP1[randomi + 0][randomj + y] = 'X';
                    if (y == 1) {
                        //luego hacia arriba y abajo en forma de cruz
                        TableroPrincipalP1[randomi - 1][randomj + y] = 'X';
                        TableroPrincipalP1[randomi + 1][randomj + y] = 'X';
                        TableroPrincipalP1[randomi ][randomj + y] = 'O';

                    } else {

                    }
                }

            }
        }
    }

}

void RellenarP2() {
    int randomi = 0, randomj = 0, jugador = 2;
    /*Funcion para llenar el tablero principal con las fichas del jugador 2*/
    //se llama e inicia para generar numeros random, basados en tiempo
    srand(time(0));
    //ciclo de 8 posiciones. 4 barcos y 4 Aviones
    for (int t = 0; t < 8; t++) {
        //Se solicita un numero random, entre 1 y 16
        randomi = (1 + (rand() % 16));
        randomj = (1 + (rand() % 16));

        //Se verifica que no hallan otras fichas en el tablero
        //Si se cumple la condicion se devuelve el ciclo
        if (VerificarSiYaEstaOcupado(jugador, randomi, randomj)) {
            t = t - 1;
        } else {
            //se inicia a colocar los barcos en el tablero
            if (t < 4) {
                //ciclo anidado para llenar segun la posicion random en forma de cuadrado
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        TableroPrincipalP2[randomi + x][randomj + y] = 'X';
                        if (x == 1 && y == 1) {
                            TableroPrincipalP2[randomi + 1][randomj + 1] = 'O';
                        } 
                    }

                }
            } else {
                //se continua colocando los aviones en el tablero
                for (int y = 0; y < 3; y++) {
                     //ciclo para colocar x primero de forma horizontal ---> XXX
                    TableroPrincipalP2[randomi + 0][randomj + y] = 'X';
                    if (y == 1) {
                        //luego hacia arriba y abajo en forma de cruz
                        TableroPrincipalP2[randomi - 1][randomj + y] = 'X';
                        TableroPrincipalP2[randomi + 1][randomj + y] = 'X';
                        TableroPrincipalP2[randomi ][randomj + y] = 'O';

                    } 
                }
            }
        }
    }
}

void CrearTableros() {
    //Funcion para crear los 4 tableros del juego
    //ciclo anidado para llenar cada posicion de
    //los tableros con =
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            TableroPrincipalP1[i][j] = '=';
            TableroPrincipalP2[i][j] = '=';
            TableroJugadasP1[i][j] = '=';
            TableroJugadasP2[i][j] = '=';
        }
    }
    cout << endl;
}

void HacerJugada(const int &posy, const int &posx, int &numerojugador) {

    /*Funcion troncal, encargada de tomar los datos enviados por la funcion
     * ProcesodeJuego().
     * Se encarga de evaluar si en las posiciones recibidas hay alguna pieza,
     * ademas de encargarse de puntajes, cantidad de jugadas
     */
    
    if (numerojugador == 1) {
        int posrelativex = 0, posrelativey = 0;
        //ciclo anidado para hallar el centro "O" de la ficha
        //Esto se realiza para lograr verificar de mejor manera
        //si la ficha en la posx y posy es un barco o un avion
        for (int u = -1; u < 2; u++) {
            for (int p = -1; p < 2; p++) {
                char caractercentro = 'O';
                //se convierte los char a string para ser comparados
                std::string Scaractercentro(1, caractercentro);
                char charobtenido = TableroPrincipalP2[posx + u][posy + p];
                std::string Scaracterobetenido(1, charobtenido);
                if (Scaractercentro == Scaracterobetenido) {
                    //si se logra encontrar el centro de la ficha
                    //se guarda la posicion en x,y
                    posrelativex = (posx + u);
                    posrelativey = (posy + p);
                }
            }
        }

        if (TableroPrincipalP2[posrelativex - 1][posrelativey - 1] == 'X') {
            //al ya tener el centro podemos saber si es un barco
            //unicamente verificando si en la posx-1 y posy-1 hay una X
            //esto por que los barcos tienen forma de cuadrado
            cout << "---------------" << endl;
            cout << "---------------" << endl;
            cout << "  Es un barco  " << endl;
            cout << "---------------" << endl;
            cout << "---------------" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            //se convierte los char a string para ser comparados
            char caractercentro = 'O';
            std::string Scaractercentro(1, caractercentro);
            char charobtenido = TableroPrincipalP2[posx][posy];
            std::string Scaracterobetenido(1, charobtenido);
            //se verifica si se dio en el centro del barco

            if (Scaractercentro == Scaracterobetenido) {
                //se verifica si se dio en el centro del barco
                //en caso de dar en el centro de un barco se suman
                //225 puntos al jugador
                Puntajejugador1 += 225;
                //CantidadDePiezasDestruidas  aumenta si y solo si se da 
                //en el centro de alguna ficha
                CantidadPiezasDestruidasP1+=1;
                cout << " -.-.-.-.-.-.-.-. " << endl;
                cout << " _._._._._._._._. " << endl;
                cout << " Le dio al centro " << endl;
                cout << " -.-.-.-.-.-.-.-. " << endl;
                cout << " _._._._._._._._. " << endl;
                cout << endl;
                cout << endl;
                cout << endl;

                //al dar en el centro en la matriz de jugadas se debe
                //mostrar todo el barco con * que serian dispàros acertados
                for (int u = -1; u < 2; u++) {
                    for (int p = -1; p < 2; p++) {
                        TableroJugadasP1[posx + u][posy + p] = '*';
                    }
                }

            } else {
                //sino se da en el centro, pero si se da en alguna parte del
                //barco, se coloca en la matriz de jugadas un *
                TableroJugadasP1[posx][posy] = '*';
                //Ademas solo se suman 25 puntos de acierto a un barco
                Puntajejugador1 += 25;
            }
            //en caso de no ser un barco se verifica si es un avion
            //al conocerce el centro se puede saber si es un avion
            //por medio de tomar posx y posy+1, si hay una X y
            //no hay nada en posx-1 y posy-1 se sabe que es un avion
            //al tener forma de cruz
        } else if ((TableroPrincipalP2[posrelativex][posrelativey + 1] == 'X') && (!(TableroPrincipalP2[posrelativex - 1][posrelativey - 1] == 'X'))) {
            cout << "---------------" << endl;
            cout << "---------------" << endl;
            cout << "  Es un Avion  " << endl;
            cout << "---------------" << endl;
            cout << "---------------" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            //se convierte los char a string para ser comparados
            char caractercentro = 'O';
            std::string Scaractercentro(1, caractercentro);
            char charobtenido = TableroPrincipalP2[posx][posy];
            std::string Scaracterobetenido(1, charobtenido);
            //se verifica si se dio en el centro del avion
            if (Scaractercentro == Scaracterobetenido) {
                Puntajejugador1 += 300;
                CantidadPiezasDestruidasP1+=1;
                cout << " -.-.-.-.-.-.-.-. " << endl;
                cout << " _._._._._._._._. " << endl;
                cout << " Le dio al centro " << endl;
                cout << " -.-.-.-.-.-.-.-. " << endl;
                cout << " _._._._._._._._. " << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                //al dar en el centro, en la matriz de jugadas se debe
                //mostrar todo el avion con * que serian dispàros acertados
                //ciclo para recorrer en forma de cruz
                for (int u = 0; u < 2; u++) {
                    if (u == 0) {
                        for (int p = -1; p < 2; p++) {
                            TableroJugadasP1[posx + u][posy + p] = '*';
                        }
                    } else {
                        for (int p = -1; p < 2; p++) {
                            TableroJugadasP1[posx + p][posy] = '*';
                        }
                    }

                }

            } else {
                //En caso de acertar al avion pero no al centro 
                //se suman 60 puntos al jugador
                TableroJugadasP1[posx][posy] = '*';
                Puntajejugador1 += 60;
            }

        } else {
            
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "                                   |                        " << endl;
            cout << "                                   |                        " << endl;
            cout << "                                   |                        " << endl;
            cout << "                                   |                        " << endl;
            cout << "                                   |                        " << endl;
            cout << "                                   v                        " << endl;
            cout << "                           No le dio a nada                   " << endl;
            //si no es ni barco, ni avion, se coloca en la matriz de jugadas un +
            TableroJugadasP1[posx][posy] = '+';
            cout << endl;
            cout << endl;
            cout << endl;
        }

    } else {
        int posrelativex2 = 0;
        int posrelativey2 = 0;

        for (int u = -1; u < 2; u++) {
            for (int p = -1; p < 2; p++) {
                char caractercentro = 'O';
                std::string Scaractercentro(1, caractercentro);
                char charobtenido = TableroPrincipalP1[posx + u][posy + p];
                std::string Scaracterobetenido(1, charobtenido);

                if (Scaractercentro == Scaracterobetenido) {
                    posrelativex2 = (posx + u);
                    posrelativey2 = (posy + p);
                }
            }
        }
        //al ya tener el centro podemos saber si es un barco
            //unicamente verificando si en la posx-1 y posy-1 hay una X
            //esto por que los barcos tienen forma de cuadrado
        if (TableroPrincipalP1[posrelativex2 - 1][posrelativey2 - 1] == 'X') {

            cout << "---------------" << endl;
            cout << "---------------" << endl;
            cout << "  Es un barco  " << endl;
            cout << "---------------" << endl;
            cout << "---------------" << endl;
            cout << endl;
            cout << endl;
            cout << endl;

            char caractercentro = 'O';
            std::string Scaractercentro(1, caractercentro);
            char charobtenido = TableroPrincipalP1[posx][posy];
            std::string Scaracterobetenido(1, charobtenido);
            
            if (Scaractercentro == Scaracterobetenido) {
                //se verifica si se dio en el centro del barco
                //en caso de dar en el centro de un barco se suman
                //225 puntos al jugador
                Puntajejugador2 += 225;
                //CantidadDePiezasDestruidas  aumenta si y solo si se da 
                //en el centro de alguna ficha
                CantidadPiezasDestruidasP2+=1;
                cout << " -.-.-.-.-.-.-.-. " << endl;
                cout << " _._._._._._._._. " << endl;
                cout << " Le dio al centro " << endl;
                cout << " -.-.-.-.-.-.-.-. " << endl;
                cout << " _._._._._._._._. " << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                //al dar en el centro en la matriz de jugadas se debe
                //mostrar todo el barco con * que serian dispàros acertados
                for (int u = -1; u < 2; u++) {
                    for (int p = -1; p < 2; p++) {
                        TableroJugadasP2[posx + u][posy + p] = '*';
                    }
                }

            } else {
                //sino se acierta al centro se suman
                //25 puntos al jugador y en la matriz de jugadas
                //se muestra el acierto
                TableroJugadasP2[posx][posy] = '*';
                Puntajejugador2 += 25;
            }
            //en caso de no ser un barco se verifica si es un avion
            //al conocerce el centro se puede saber si es un avion
            //por medio de tomar posx y posy+1, si hay una X y
            //no hay nada en posx-1 y posy-1 se sabe que es un avion
            //al tener forma de cruz

        } else if ((TableroPrincipalP1[posrelativex2][posrelativey2 + 1] == 'X') && (!(TableroPrincipalP1[posrelativex2 - 1][posrelativey2 - 1] == 'X'))) {
            cout << "---------------" << endl;
            cout << "---------------" << endl;
            cout << "  Es un Avion  " << endl;
            cout << "---------------" << endl;
            cout << "---------------" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            char caractercentro = 'O';
            std::string Scaractercentro(1, caractercentro);
            char charobtenido = TableroPrincipalP1[posx][posy];
            std::string Scaracterobetenido(1, charobtenido);
            //Se verifica si le dio al centro del avion
            if (Scaractercentro == Scaracterobetenido) {
                
                Puntajejugador2 += 300;
                CantidadPiezasDestruidasP2+=1;
                cout << " -.-.-.-.-.-.-.-. " << endl;
                cout << " _._._._._._._._. " << endl;
                cout << " Le dio al centro " << endl;
                cout << " -.-.-.-.-.-.-.-. " << endl;
                cout << " _._._._._._._._. " << endl;
                cout << endl;
                cout << endl;
                cout << endl;
                //al dar en el centro, en la matriz de jugadas se debe
                //mostrar todo el avion con * que serian dispàros acertados
                //ciclo para recorrer en forma de cruz
                for (int u = 0; u < 2; u++) {
                    if (u == 0) {
                        for (int p = -1; p < 2; p++) {
                            TableroJugadasP2[posx + u][posy + p] = '*';
                        }
                    } else {
                        for (int p = -1; p < 2; p++) {
                            TableroJugadasP2[posx + p][posy] = '*';
                        }
                    }

                }

            } else {
                //en caso de acertar se muestra en la matriz de jugadas
                //y se suman 60 puntos
                TableroJugadasP2[posx][posy] = '*';
                Puntajejugador2 += 60;
            }

        } else {
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "                                   |                        " << endl;
            cout << "                                   |                        " << endl;
            cout << "                                   |                        " << endl;
            cout << "                                   |                        " << endl;
            cout << "                                   |                        " << endl;
            cout << "                                   v                        " << endl;
            cout << "                         No le dio a nada               " << endl;
            //Sino le acerto a nada se muestra en la matriz de jugadas un +
            TableroJugadasP2[posx][posy] = '+';
            cout << endl;
            cout << endl;
            cout << endl;
        }
    }


}

void ParametrosInciales() {
    /*
     * Funcion donde se solicitan los datos iniciales para el juego
     * Nombres de los jugadores y cantidad de jugadas maximas
     */
    cout << "Se van a crear las matrices(Tableros)" << endl;
    CrearTableros();
    cout << "Se van a rellenar los tableros" << endl;

    RellenarP1();
    cout << "Tablero 1 rellenado" << endl;
    cout << "Rellenando Tablero 2" << endl;
    RellenarP2();
    cout << "Tablero 2 rellenado" << endl;
    cout << "Ingrese el nombre del jugador 1: ";
    cin>>Nombrejugador1;
    cout << endl;
    cout << "Ingrese el nombre del jugador 2: ";
    cin>>Nombrejugador2;
    cout << endl;
    cout << "Ingrese la cantidad de jugadas maximas: ";
    cin>>CantidadjugadasMax;
    cout << endl;
}

void ProcesodeJuego() {
    /*
     * Funcion troncal, encargada de verificar cantidad de jugadas
     * cantidad de piezas destruidas por cada jugador, ademas
     * de encargarse de imprimir los 2 tableros de cada jugador
     * en el turno de cada uno
     */
    while ((CantidadJugadasAct <= CantidadjugadasMax) && (CantidadPiezasDestruidasP1<4)&&(CantidadPiezasDestruidasP2<4)) {
        int jugador = 0;
        //Se toma la cantidaddejugadas actuales y se verifica si es par o impar
        //esto para saber si es turno del jugador 1 o 2
        //Siempre empieza el jugador 1, en caso de terminar su turno las jugadasactuales pasara a ser
        //1 y por efecto, se consideraria impar, dando paso al jugador 2
        if (CantidadJugadasAct % 2 == 0) {
            //Ciclo anidado para imprimir el tablero principal del jugador 1
            for (int i = 0; i < 19; i++) {
                for (int j = 0; j < 19; j++) {
                    cout << TableroPrincipalP1[i][j] << " ";
                }
                cout << endl;

            }
            cout << endl;
            cout << endl;
            //Ciclo anidado para imprimir el tablero de jugadas del jugador 1
            for (int n = 0; n < 19; n++) {
                for (int m = 0; m < 19; m++) {
                    cout << TableroJugadasP1[n][m] << " ";
                }
                cout << endl;

            }
            cout << endl;
            cout << endl;

            cout << endl;
            
            //Informa de quien es el turno, ademas del puntaje que lleva
            //y la cantidad de jugadas que se han realizado en total
            cout << "Es el turno del jugador:  " << Nombrejugador1 << endl;

            cout << "--------------------------------------------------" << endl;
            cout << "   -       Puntaje del jugador: " << Nombrejugador1 << "          - " << endl;
            cout << "                                                " << endl;
            cout << "      -             " << Puntajejugador1 << "                 -   " << endl;
            cout << "                                                " << endl;
            cout << "       - Llevan: " << CantidadJugadasAct << " jugadas totales    -     " << endl;
            cout << "--------------------------------------------------" << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            jugador = 1;
            CantidadJugadasAct += 1;

        } else {
            //De no ser par se referencia como el turno del jugador 2
            jugador = 2;
            //Ciclo anidado para imprimir el tablero principal del jugador 2
            for (int l = 0; l < 19; l++) {
                for (int k = 0; k < 19; k++) {
                    cout << TableroPrincipalP2[l][k] << " ";
                }
                cout << endl;

            }
            cout << endl;
            cout << endl;
            
            //Ciclo anidado para imprimir el tablero de jugadas del jugador 2
            for (int n = 0; n < 19; n++) {
                for (int m = 0; m < 19; m++) {
                    cout << TableroJugadasP2[n][m] << " ";
                }
                cout << endl;

            }
            
            //Se informa de quien es el turno, ademas de mostrar
            //el puntaje del jugador 2 y la cantidad de jugadas
            //que se han realizado en total
            cout << endl;
            cout << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "   -       Puntaje del jugador: " << Nombrejugador2 << "          - " << endl;
            cout << "                                                " << endl;
            cout << "      -             " << Puntajejugador2 << "                 -   " << endl;
            cout << "                                                " << endl;
            cout << "       - Llevan: " << CantidadJugadasAct << " jugadas totales    -     " << endl;
            cout << "--------------------------------------------------" << endl;
            CantidadJugadasAct += 1;
        }
        //Se solicitan las coordenadas para realizar una 'Jugada'
        int posx = 0, posy = 0;
        cout << "Ingrese la posicion en x(0-18): ";
        cin>>posx;
        cout << endl;
        cout << "Ingrese la posicion en y(0-18): ";
        cin>>posy;
        cout << endl;
        HacerJugada(posx, posy, jugador);
    }
}

void MostrarPuntajesFinales() {
    //se imprime los nombres y puntajes de los jugadores con
    //una decoracion en forma de caja
    cout << "------------------------             " << "------------------------             " << endl;
    cout << "Puntaje de: " << Nombrejugador1 << " es: " << Puntajejugador1 << "             " << "           Puntaje de: " << Nombrejugador2 << " es: " << Puntajejugador2 << "             " << endl;
    cout << "------------------------             " << "------------------------             " << endl;
    cout << "__________________________________________________" << endl;
}

void MostrarGanador() {
    //se imprime la informacion del ganador
    if (Puntajejugador1 > Puntajejugador2) {
        cout << "            El ganador es: " << Nombrejugador1 << endl;
    } else if (Puntajejugador1 == Puntajejugador2) {
        cout << "            Es un empate!" << endl;
    } else {
        cout << "            El ganador es: " << Nombrejugador2 << endl;
    }
    cout << "__________________________________________________" << endl;
    cout << endl;
}

int main(int argc, char** argv) {

    /*Llama la funcion para configurar nombres de jugadores,
     * crear los tableros, rellenar cada tablero, cantidad de jugadas.
     */
    ParametrosInciales();
    /*
     * Llama la funcion para comenzar el proceso de juego
     * donde se solicitaran los movimientos a los jugadores,
     * ademas de hacer conteo de puntajes
     */
    ProcesodeJuego();
    /*Llama la funcion para mostrar los resultados de
     * ambos jugadores en una tabla
     */
    MostrarPuntajesFinales();
    /*Llama la funcion para mostrar la informacion
     * del jugador ganador(Nombre y puntaje)
     */
    MostrarGanador();


    return 0;
}

