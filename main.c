
/*
    Objetivo: Programar o clássico Pedra Papel Tesoura com menu interativo.

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

int main(void){setlocale(LC_ALL, ""); //Adaptação do programa ao idioma padrão do sistema operacional.

    hide(); //Esconder o cursor.

    //Área de variáveis e atribuições:
    int player, win, loss, draw, op, again, pc;

    player = ZERO;
    win = ZERO;
    loss = ZERO;
    draw = ZERO;
    op = ZERO;
    again = ZERO;
    pc = ZERO;

    //-----

    op = menu(); //Op recebe 1 ou -21 da função menu.


    switch(op){

                 case ONE: //Usuário escolheu a opção JOGAR:
                           do{
                                do{

                                system("cls"); //não usei clrscr() porque da erro no CodeBlocks: undefined reference to 'clrscr'
                                printf("\t\tPEDRA PAPEL TESOURA");
                                printf("\n\t\t\tby Matheus Marcelino");
                                printf("\n\t__________________________________________");
                                printf("\n\n\t[1] - Pedra");
                                printf("\n\t[2] - Papel");
                                printf("\n\t[3] - Tesoura");
                                printf("\n\t__________________________________________");
                                printf("\n\n\tVocê jogará com um computador.\n");
                                printf("\n\tVitórias: %d\n\tDerrotas: %d\n\tEmpates: %d\n", win, loss, draw);
                                player = getch() - 48; //lê a vez do jogador.

                           }while(player != ONE && player != TWO && player != THREE);

                                pc = computer(); //vez do computador.

                                 switch(player){ //decisão de: jogador ganhou, perdeu ou empatou.

                                                    case ONE://jogador escolheu pedra
                                                             if(pc == 0){
                                                                      printf("\n\t               VS");
                                                                      printf("\n\t Você:       Pedra");
                                                                      printf("\n\t________________________________________________________");
                                                                      printf("\n\n\t Empate!");
                                                                      ++draw;
                                                             }else if(pc == 1){
                                                                      printf("\n\t               VS");
                                                                      printf("\n\t Você:       Pedra");
                                                                      printf("\n\t________________________________________________________");
                                                                      printf("\n\n\t Derrota!");
                                                                      ++loss;
                                                             }else if(pc == 2){
                                                                      printf("\n\t               VS");
                                                                      printf("\n\t Você:       Pedra");
                                                                      printf("\n\t________________________________________________________");
                                                                      printf("\n\n\t Vitória!");
                                                                      ++win;
                                                             }

                                                             break;

                                                    case TWO://jogador escolheu papel
                                                              if(pc == 0){
                                                                       printf("\n\t               VS");
                                                                       printf("\n\t Você:       Papel");
                                                                       printf("\n\t________________________________________________________");
                                                                       printf("\n\n\t Vitória!");
                                                                       ++win;
                                                              }else if(pc == 1){
                                                                       printf("\n\t               VS");
                                                                       printf("\n\t Você:       Papel");
                                                                       printf("\n\t________________________________________________________");
                                                                       printf("\n\n\t Empate!");
                                                                       ++draw;
                                                              }else if(pc == 2){
                                                                       printf("\n\t               VS");
                                                                       printf("\n\t Você:       Papel");
                                                                       printf("\n\t________________________________________________________");
                                                                       printf("\n\n\t Derrota!");
                                                                       ++loss;

                                                              }

                                                              break;

                                                    case THREE://jogador escolheu tesoura
                                                              if(pc == 0){
                                                                        printf("\n\t               VS");
                                                                        printf("\n\t Você:       Tesoura");
                                                                        printf("\n\t________________________________________________________");
                                                                        printf("\n\t Derrota!");
                                                                        ++loss;
                                                              }else if(pc == 1){
                                                                        printf("\n\t               VS");
                                                                        printf("\n\t Você:       Tesoura");
                                                                        printf("\n\t________________________________________________________");
                                                                        printf("\n\t Vitória!");
                                                                        ++win;
                                                              }else if(pc == 2){
                                                                        printf("\n\t               VS");
                                                                        printf("\n\t Você:       Tesoura");
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
                           printf("Até a próxima!\n\n");

                           break;

                 default:
                     system("cls");
                     printf("Até a próxima!\n\n");
                     break;



}
}
//Função para esconder o cursor
void hide(){

    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    ConCurInf.dwSize = 10;
    ConCurInf.bVisible = FALSE;

    SetConsoleCursorInfo(hOut, &ConCurInf);
}
//Função para imprimir um menu:
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
        printf("\n\n\tPressione a tecla referente a opção desejada.");
        loop = getch() - 48;

    }while(loop != ESC && loop != ONE);

    return loop; // retorna 1 ou -21 para função menu.
}
//Função responsável pelo "bot" do jogo:
int computer(){

    system("cls");
    srand(time(NULL)); //semente da função rand.
    int c = rand() % 3; //responsável pela vez da máquina.

    switch(c){ //switch para mostrar a decisão da máquina.

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
