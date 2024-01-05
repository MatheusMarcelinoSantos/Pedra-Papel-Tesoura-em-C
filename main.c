
/*
    Objetivo: Programar o cl�ssico Pedra Papel Tesoura com menu interativo.

    Data: 04/01/2024
                  by Matheus Marcelino
*/

//Bibliotecas:
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>

//Constantes:
#define ONE 1
#define TWO 2
#define THREE 3
#define ESC -21
#define ZERO 0

int main(void){setlocale(LC_ALL, ""); //Adapta��o do programa ao idioma padr�o do sistema operacional.

    hide(); //Esconder o cursor.

    //�rea de vari�veis e atribui��es:
    int player, win, loss, draw, op, again, pc;

    player = ZERO;
    win = ZERO;
    loss = ZERO;
    draw = ZERO;
    op = ZERO;
    again = ZERO;
    pc = ZERO;

    //-----

    op = menu(); //Op recebe 1 ou -21 da fun��o menu.


    switch(op){

                 case ONE: //Usu�rio escolheu a op��o JOGAR:
                           do{
                                do{

                                system("cls"); //n�o usei clrscr() porque da erro no CodeBlocks: undefined reference to 'clrscr'
                                printf("\t\tPEDRA PAPEL TESOURA");
                                printf("\n\t\t\tby Matheus Marcelino");
                                printf("\n\t__________________________________________");
                                printf("\n\n\t[1] - Pedra");
                                printf("\n\t[2] - Papel");
                                printf("\n\t[3] - Tesoura");
                                printf("\n\t__________________________________________");
                                printf("\n\n\tVoc� jogar� com um computador.\n");
                                printf("\n\tVit�rias: %d\n\tDerrotas: %d\n\tEmpates: %d\n", win, loss, draw);
                                player = getch() - 48; //l� a vez do jogador.

                           }while(player != ONE && player != TWO && player != THREE);

                                pc = computer(); //vez do computador.

                                 switch(player){ //decis�o de: jogador ganhou, perdeu ou empatou.

                                                    case ONE://jogador escolheu pedra
                                                             if(pc == 0){
                                                                      printf("\n\t               VS");
                                                                      printf("\n\t Voc�:       Pedra");
                                                                      printf("\n\t________________________________________________________");
                                                                      printf("\n\n\t Empate!");
                                                                      ++draw;
                                                             }else if(pc == 1){
                                                                      printf("\n\t               VS");
                                                                      printf("\n\t Voc�:       Pedra");
                                                                      printf("\n\t________________________________________________________");
                                                                      printf("\n\n\t Derrota!");
                                                                      ++loss;
                                                             }else if(pc == 2){
                                                                      printf("\n\t               VS");
                                                                      printf("\n\t Voc�:       Pedra");
                                                                      printf("\n\t________________________________________________________");
                                                                      printf("\n\n\t Vit�ria!");
                                                                      ++win;
                                                             }

                                                             break;

                                                    case TWO://jogador escolheu papel
                                                              if(pc == 0){
                                                                       printf("\n\t               VS");
                                                                       printf("\n\t Voc�:       Papel");
                                                                       printf("\n\t________________________________________________________");
                                                                       printf("\n\n\t Vit�ria!");
                                                                       ++win;
                                                              }else if(pc == 1){
                                                                       printf("\n\t               VS");
                                                                       printf("\n\t Voc�:       Papel");
                                                                       printf("\n\t________________________________________________________");
                                                                       printf("\n\n\t Empate!");
                                                                       ++draw;
                                                              }else if(pc == 2){
                                                                       printf("\n\t               VS");
                                                                       printf("\n\t Voc�:       Papel");
                                                                       printf("\n\t________________________________________________________");
                                                                       printf("\n\n\t Derrota!");
                                                                       ++loss;

                                                              }

                                                              break;

                                                    case THREE://jogador escolheu tesoura
                                                              if(pc == 0){
                                                                        printf("\n\t               VS");
                                                                        printf("\n\t Voc�:       Tesoura");
                                                                        printf("\n\t________________________________________________________");
                                                                        printf("\n\t Derrota!");
                                                                        ++loss;
                                                              }else if(pc == 1){
                                                                        printf("\n\t               VS");
                                                                        printf("\n\t Voc�:       Tesoura");
                                                                        printf("\n\t________________________________________________________");
                                                                        printf("\n\t Vit�ria!");
                                                                        ++win;
                                                              }else if(pc == 2){
                                                                        printf("\n\t               VS");
                                                                        printf("\n\t Voc�:       Tesoura");
                                                                        printf("\n\t________________________________________________________");
                                                                        printf("\n\t Empate!");
                                                                        ++draw;
                                                              }

                                                              break;
                                        }

                                printf("\n\n\t Pressione 1 para Jogar Novamente.");
                                printf("\n\t__________________________________________");
                                again = getch() - 48;
                           }while(again == ONE);

                           system("cls");
                           printf("At� a pr�xima!\n\n");

                           break;

                 default:
                     system("cls");
                     printf("At� a pr�xima!\n\n");
                     break;



}
}
//Fun��o para esconder o cursor
void hide(){

    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;

    SetConsoleCursorInfo(hOut, &ConCurInf);
}
//Fun��o para imprimir um menu:
int menu(){

    int loop;

    do{
        system("cls");
        printf("\t\tPEDRA PAPEL TESOURA");
        printf("\n\t\t\tby Matheus Marcelino");
        printf("\n\t__________________________________________");
        printf("\n\n\t[1] - Jogar");
        printf("\n\t[ESC] - Sair");
        printf("\n\t__________________________________________");
        printf("\n\n\tPressione a tecla referente a op��o desejada.");
        loop = getch() - 48;

    }while(loop != ESC && loop != ONE);

    return loop; // retorna 1 ou -21 para fun��o menu.
}
//Fun��o respons�vel pelo "bot" do jogo:
int computer(){

    system("cls");
    srand(time(NULL)); //semente da fun��o rand.
    int c = rand() % 3; //respons�vel pela vez da m�quina.

    switch(c){ //switch para mostrar a decis�o da m�quina.

               case 0:
                   printf("\n\t________________________________________________________");
                   printf("\n\t Computador: Pedra.");
                   break;

               case 1:
                   printf("\n\t________________________________________________________");
                   printf("\n\t Computador: Papel.");
                   break;

               case 2:
                   printf("\n\t________________________________________________________");
                   printf("\n\t Computador: Tesoura.");
                   break;
    }

    return c;
}
