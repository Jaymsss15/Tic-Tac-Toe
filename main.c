//Nome: Tiago Filipe Amorim Marques
//Nº: 2020128217

#include <stdio.h>
#include <stdlib.h>
#include "matdin.h"
#include "jogo.h"
#include "utils.h"


int main()
{
    initRandom();
    int opt;

    struct Lista* L = NULL;
    char fName[100] = "jogo.bin";

    Tab TabuleiroJogo;
    Tab TabuleiroFinal;

    Jogador Jogador1,Jogador2,BOT;
    Jogador1.c = 'X';
    Jogador2.c = 'O';
    BOT.c = 'O';

    int jogada=1;
    int Rondas=0;
    int miniTab = 1;
    int vencedor = 0;

    int nJogada;

    TabuleiroJogo.miniTab = 1;

    int gTab1 = 0, gTab2 = 0, gTab3 = 0, gTab4 = 0, gTab5 = 0, gTab6 = 0, gTab7 = 0, gTab8 = 0, gTab9 = 0;
    int gTabF = 0;



///Menu Inicial

    do
    {
        opt = menu();
        switch(opt)
        {
        case JOGAR:
            TabuleiroJogo.p = criaMat(9,9);
            TabuleiroFinal.p = criaMat(NLin2, NCol2);

            mostraMat(TabuleiroJogo.p, NLin, NCol);

            ///Menu Jogo
            do
            {

                printf("\n\n1 - Jogador%d a jogar: \n",jogada);
                opt = menu2();
                switch(opt)
                {

                case JOGAR:


                    while((TabuleiroJogo.miniTab==1 && gTab1!=0)||(TabuleiroJogo.miniTab==2 && gTab2!=0)||(TabuleiroJogo.miniTab==3 && gTab3!=0)||(TabuleiroJogo.miniTab==4 && gTab4!=0)||(TabuleiroJogo.miniTab==5 && gTab5!=0)||(TabuleiroJogo.miniTab==6 && gTab6!=0)||(TabuleiroJogo.miniTab==7 && gTab7!=0)||(TabuleiroJogo.miniTab==8 && gTab8!=0)||(TabuleiroJogo.miniTab==9 && gTab9!=0))
                    {
                        TabuleiroJogo.miniTab++;

                        if(TabuleiroJogo.miniTab>9)
                        {
                            TabuleiroJogo.miniTab = 1;
                        }
                    }


                    ///Jogadas(TabuleiroJogo)

                    Jogadas(TabuleiroJogo,Jogador1,Jogador2,&jogada,&TabuleiroJogo.miniTab,&L);

                    mostraMat(TabuleiroJogo.p, NLin, NCol);

                    Rondas++;


                    ///Formas de ganhar em cada miniTab
                    GanhouTab1(TabuleiroJogo, &gTab1, &jogada);
                    GanhouTab2(TabuleiroJogo, &gTab2, &jogada);
                    GanhouTab3(TabuleiroJogo, &gTab3, &jogada);
                    GanhouTab4(TabuleiroJogo, &gTab4, &jogada);
                    GanhouTab5(TabuleiroJogo, &gTab5, &jogada);
                    GanhouTab6(TabuleiroJogo, &gTab6, &jogada);
                    GanhouTab7(TabuleiroJogo, &gTab7, &jogada);
                    GanhouTab8(TabuleiroJogo, &gTab8, &jogada);
                    GanhouTab9(TabuleiroJogo, &gTab9, &jogada);



                    ///Jogadas(TabuleiroFinal)
                    if(gTab1==1)
                    {
                        setPos(TabuleiroFinal.p,0,0,Jogador1.c);
                    }
                    else if(gTab1==2)
                    {
                        setPos(TabuleiroFinal.p,0,0,Jogador2.c);
                    }

                    if(gTab2==1)
                    {
                        setPos(TabuleiroFinal.p,0,1,Jogador1.c);
                    }
                    else if(gTab2==2)
                    {
                        setPos(TabuleiroFinal.p,0,1,Jogador2.c);
                    }

                    if(gTab3==1)
                    {
                        setPos(TabuleiroFinal.p,0,2,Jogador1.c);
                    }
                    else if(gTab3==2)
                    {
                        setPos(TabuleiroFinal.p,0,2,Jogador2.c);
                    }

                    if(gTab4==1)
                    {
                        setPos(TabuleiroFinal.p,1,0,Jogador1.c);
                    }
                    else if(gTab4==2)
                    {
                        setPos(TabuleiroFinal.p,1,0,Jogador2.c);
                    }

                    if(gTab5==1)
                    {
                        setPos(TabuleiroFinal.p,1,1,Jogador1.c);
                    }
                    else if(gTab5==2)
                    {
                        setPos(TabuleiroFinal.p,1,1,Jogador2.c);
                    }

                    if(gTab6==1)
                    {
                        setPos(TabuleiroFinal.p,1,2,Jogador1.c);
                    }
                    else if(gTab6==2)
                    {
                        setPos(TabuleiroFinal.p,1,2,Jogador2.c);
                    }

                    if(gTab7==1)
                    {
                        setPos(TabuleiroFinal.p,2,0,Jogador1.c);
                    }
                    else if(gTab7==2)
                    {
                        setPos(TabuleiroFinal.p,2,0,Jogador2.c);
                    }

                    if(gTab8==1)
                    {
                        setPos(TabuleiroFinal.p,2,1,Jogador1.c);
                    }
                    else if(gTab8==2)
                    {
                        setPos(TabuleiroFinal.p,2,1,Jogador2.c);
                    }

                    if(gTab9==1)
                    {
                        setPos(TabuleiroFinal.p,2,2,Jogador1.c);
                    }
                    else if(gTab9==2)
                    {
                        setPos(TabuleiroFinal.p,2,2,Jogador2.c);
                    }

                    GanhouTabFinal(TabuleiroFinal, &gTabF, &jogada);

                    if(gTabF ==1)
                    {
                        vencedor = 1;

                        printf("\n\n\nAcabou o Jogo!");
                        printf("\nGanhou o Jogador%d",vencedor);
                    }
                    else if(gTabF ==2)
                    {
                        vencedor = 2;

                        printf("\n\n\nAcabou o Jogo!");
                        printf("\nGanhou o Jogador%d",vencedor);
                    }

                    if(gTabF == 0 && gTab1 !=0 && gTab2 !=0 && gTab3 !=0 && gTab4 !=0 && gTab5 !=0 && gTab6 !=0 && gTab7 !=0 && gTab8 !=0 && gTab9 !=0)
                    {
                        printf("\n\n\nAcabou o Jogo!");
                        printf("\nEmpate");
                        printf("\n\n\n");
                        mostraMat(TabuleiroFinal.p, NLin2, NCol2);
                        return;
                    }
                    break;

                case JOGADAS:

                    if(Rondas == 0)
                    {
                        printf("\n\nAinda nao foram feitas Jogadas!\n\n");
                    }
                    else
                    {

                        do
                        {
                            printf("\nEscreva quantas Jogadas quer ver [1 - 10]: ");
                            scanf("%d",&nJogada);

                            if(Rondas < nJogada)
                            {
                                printf("\nEsse numero e maior que o numero de Jogadas!");
                            }

                        }
                        while(nJogada>10 || nJogada<1 || Rondas < nJogada);

                        MostrarLista(L,nJogada);
                    }

                    break;

                case GUARDAR:
                    GuardaJogo(fName,L);

                    break;
                };
            }
            while(opt != SAIR2 || vencedor!=0);
            break;

        case JOGAR1vBOT:
            TabuleiroJogo.p = criaMat(NLin, NCol);
            TabuleiroFinal.p = criaMat(NLin2, NCol2);

            mostraMat(TabuleiroJogo.p, NLin, NCol);

            ///Menu Jogo
            do
            {
                if(jogada==1)
                {
                    printf("\n\n1 - Jogador%d a jogar: \n",jogada);
                }
                else if(jogada==2)
                {
                    printf("\n\n1 - BOT a jogar: \n");
                }

                opt = menu2();
                switch(opt)
                {

                case JOGAR:

                    while((TabuleiroJogo.miniTab==1 && gTab1!=0)||(TabuleiroJogo.miniTab==2 && gTab2!=0)||(TabuleiroJogo.miniTab==3 && gTab3!=0)||(TabuleiroJogo.miniTab==4 && gTab4!=0)||(TabuleiroJogo.miniTab==5 && gTab5!=0)||(TabuleiroJogo.miniTab==6 && gTab6!=0)||(TabuleiroJogo.miniTab==7 && gTab7!=0)||(TabuleiroJogo.miniTab==8 && gTab8!=0)||(TabuleiroJogo.miniTab==9 && gTab9!=0))
                    {
                        TabuleiroJogo.miniTab++;

                        if(TabuleiroJogo.miniTab>9)
                        {
                            TabuleiroJogo.miniTab = 1;
                        }
                    }


                    ///Jogadas(TabuleiroJogo)
                    Jogadas2(TabuleiroJogo,Jogador1,BOT,&jogada, &TabuleiroJogo.miniTab,&L);

                    mostraMat(TabuleiroJogo.p, NLin, NCol);

                    Rondas++;


                    ///Formas de ganhar em cada miniTab
                    GanhouTab1(TabuleiroJogo, &gTab1, &jogada);
                    GanhouTab2(TabuleiroJogo, &gTab2, &jogada);
                    GanhouTab3(TabuleiroJogo, &gTab3, &jogada);
                    GanhouTab4(TabuleiroJogo, &gTab4, &jogada);
                    GanhouTab5(TabuleiroJogo, &gTab5, &jogada);
                    GanhouTab6(TabuleiroJogo, &gTab6, &jogada);
                    GanhouTab7(TabuleiroJogo, &gTab7, &jogada);
                    GanhouTab8(TabuleiroJogo, &gTab8, &jogada);
                    GanhouTab9(TabuleiroJogo, &gTab9, &jogada);



                    ///Jogadas(TabuleiroFinal)
                    if(gTab1==1)
                    {
                        setPos(TabuleiroFinal.p,0,0,Jogador1.c);
                        printf("\n\n\n");
                    }
                    else if(gTab1==2)
                    {
                        setPos(TabuleiroFinal.p,0,0,BOT.c);
                        printf("\n\n\n");
                    }


                    if(gTab2==1)
                    {
                        setPos(TabuleiroFinal.p,0,1,Jogador1.c);
                    }
                    else if(gTab2==2)
                    {
                        setPos(TabuleiroFinal.p,0,1,BOT.c);
                    }


                    if(gTab3==1)
                    {
                        setPos(TabuleiroFinal.p,0,2,Jogador1.c);
                    }
                    else if(gTab3==2)
                    {
                        setPos(TabuleiroFinal.p,0,2,BOT.c);
                    }

                    if(gTab4==1)
                    {
                        setPos(TabuleiroFinal.p,1,0,Jogador1.c);
                    }
                    else if(gTab4==2)
                    {
                        setPos(TabuleiroFinal.p,1,0,BOT.c);
                    }

                    if(gTab5==1)
                    {
                        setPos(TabuleiroFinal.p,1,1,Jogador1.c);
                    }
                    else if(gTab5==2)
                    {
                        setPos(TabuleiroFinal.p,1,1,BOT.c);
                    }

                    if(gTab6==1)
                    {
                        setPos(TabuleiroFinal.p,1,2,Jogador1.c);
                    }
                    else if(gTab6==2)
                    {
                        setPos(TabuleiroFinal.p,1,2,BOT.c);
                    }

                    if(gTab7==1)
                    {
                        setPos(TabuleiroFinal.p,2,0,Jogador1.c);
                    }
                    else if(gTab7==2)
                    {
                        setPos(TabuleiroFinal.p,2,0,BOT.c);
                    }

                    if(gTab8==1)
                    {
                        setPos(TabuleiroFinal.p,2,1,Jogador1.c);
                    }
                    else if(gTab8==2)
                    {
                        setPos(TabuleiroFinal.p,2,1,BOT.c);
                    }

                    if(gTab9==1)
                    {
                        setPos(TabuleiroFinal.p,2,2,Jogador1.c);
                    }
                    else if(gTab9==2)
                    {
                        setPos(TabuleiroFinal.p,2,2,BOT.c);
                    }

                    GanhouTabFinal(TabuleiroFinal, &gTabF, &jogada);

                    if(gTabF ==1)
                    {
                        vencedor = 1;

                        printf("\n\n\nAcabou o Jogo!");
                        printf("\nGanhou o Jogador%d",vencedor);
                        printf("\n\n\n");
                        mostraMat(TabuleiroFinal.p, NLin2, NCol2);
                        return;
                    }
                    else if(gTabF ==2)
                    {
                        printf("\n\n\nAcabou o Jogo!");
                        printf("\nGanhou o BOT");
                        printf("\n\n\n");
                        mostraMat(TabuleiroFinal.p, NLin2, NCol2);
                        return;
                    }

                    if(gTabF == 0 && gTab1 !=0 && gTab2 !=0 && gTab3 !=0 && gTab4 !=0 && gTab5 !=0 && gTab6 !=0 && gTab7 !=0 && gTab8 !=0 && gTab9 !=0)
                    {
                        printf("\n\n\nAcabou o Jogo!");
                        printf("\nEmpate");
                        printf("\n\n\n");
                        mostraMat(TabuleiroFinal.p, NLin2, NCol2);
                        return;
                    }

                    break;

                case JOGADAS:
                    if(Rondas == 0)
                    {
                        printf("\n\nAinda nao foram feitas Jogadas!\n\n");
                    }
                    else
                    {

                        do
                        {
                            printf("\nEscreva quantas Jogadas quer ver [1 - 10]: ");
                            scanf("%d",&nJogada);

                            if(Rondas < nJogada)
                            {
                                printf("\nEsse numero e maior que o numero de Jogadas!");
                            }

                        }
                        while(nJogada>10 || nJogada<1 || Rondas < nJogada);
                        MostrarLista2(L,nJogada);
                    }
                    break;

                case GUARDAR:

                    //GuardaJogo(TabuleiroJogo,&Jogador1,&BOT);
                    break;
                };
            }
            while(opt != SAIR2 || vencedor!=0);
            break;

        case CONTINUAR:
            ContinuaJogo(fName, L);
            break;


        case REGRAS:
            do
            {
                opt = menu3();
            }
            while(opt!=1);

            break;
        };
    }
    while(opt != SAIR || vencedor!=0);


    libertaMat(TabuleiroJogo.p, NLin);
    libertaMat(TabuleiroFinal.p, NLin2);
    free(L);

    return 0;
}


