//Nome: Tiago Filipe Amorim Marques
//N�: 2020128217
#include <stdio.h>
#include <stdlib.h>
#include "matdin.h"
#include "jogo.h"

int menu()
{
    int opt, res = 0;
    do
    {
        printf("\n");
        puts("*** Main Menu ***\n");
        puts("1 - Jogar 1vs1");
        puts("2 - Jogar 1vsBOT");
        puts("3 - Continuar Jogo");
        puts("4 - Regras");
        puts("5 - Sair");

        printf("\nOption: ");

        res = scanf("%d", &opt);
        puts("\n\n");
    }
    while(res != 1 || opt < JOGAR || opt > SAIR);

    return opt;
}

int menu2()
{
    int opt, res = 0;
    do
    {

        puts("2 - Ver Jogadas");
        puts("3 - Guardar Jogo");
        puts("4 - Sair");

        printf("\nOption: ");

        res = scanf("%d", &opt);
    }
    while(res != 1 || opt < JOGAR || opt > SAIR2);

    return opt;
}

int menu3()
{
    int opt, res = 0;
    do
    {
        puts("*** Regras ***\n");
        puts("- O Jogador1 e o primeiro a comecar a jogar.");
        puts("- O jogo comeca no Tabuleiro1.\n");
        puts("1 - Voltar");

        printf("\nOption: ");

        res = scanf("%d", &opt);
        puts("\n\n");
    }
    while(res != 1);

    return opt;
}

/*
int GuardaJogo()
{


int ContinuaJogo()
{

}*/


void RegraJogo(int *miniTab, int l, int c)
{
    if((l == 1 || l == 4 || l == 7)&&(c == 1 || c == 4 || c == 7))
    {
        *miniTab = 1;
    }
    else if((l == 1 || l == 4 || l == 7)&&(c == 2 || c == 5 || c == 8))
    {
        *miniTab = 2;
    }
    else if((l == 1 || l == 4 || l == 7)&&(c == 3 || c == 6 || c == 9))
    {
        *miniTab = 3;
    }
    else if((l == 2 || l == 5 || l == 8)&&(c == 1 || c == 4 || c == 7))
    {
        *miniTab = 4;
    }
    else if((l == 2 || l == 5 || l == 8)&&(c == 2 || c == 5 || c == 8))
    {
        *miniTab = 5;
    }
    else if((l == 2 || l == 5 || l == 8)&&(c == 3 || c == 6 || c == 9))
    {
        *miniTab = 6;
    }
    else if((l == 3 || l == 6 || l == 9)&&(c == 1 || c == 4 || c == 7))
    {
        *miniTab = 7;
    }
    else if((l == 3 || l == 6 || l == 9)&&(c == 2 || c == 5 || c == 8))
    {
        *miniTab = 8;
    }
    else if((l == 3 || l == 6 || l == 9)&&(c == 3 || c == 6 || c == 9))
    {
        *miniTab = 9;
    }
}


struct Lista InsereJogada(struct Lista** L, int lin, int col)
{
    struct Lista* nova, *aux;
    aux = *L;
    nova = (struct Lista*)malloc(sizeof(struct Lista));

    if(nova == NULL)
    {
        printf("Erro ao alocar memoria");
    }

    nova->linha = lin;
    nova->coluna = col;
    nova->next = NULL;

    if(*L ==NULL)
    {
        *L = nova;
    }
    else
    {
        while(aux->next != NULL)
        {
            aux = aux->next;
        }

        aux->next = nova;

        return *aux;
    }
}



int MostrarLista(struct Lista* L)
{
    struct Lista* t = NULL;
    int count = 0;
    for(t = L; t != NULL; t = t->next)
    {
        if(count == 0)
        {
            printf("\n\nLista das Jogadas:\n\n");
        }
        if(count%2 == 0)
        {
        printf("Jogador1 jogou:\n");
        printf("Linha: %d\n", t->linha);
        printf("Coluna:% d\n\n", t->coluna);
        }
        else
        {
        printf("Jogador2 jogou:\n");
        printf("Linha: %d\n", t->linha);
        printf("Coluna:% d\n\n", t->coluna);
        }
        count++;
    }
}

int MostrarLista2(struct Lista* L)
{
    struct Lista* t = NULL;
    int count = 0;
    for(t = L; t != NULL; t = t->next)
    {
        if(count == 0)
        {
            printf("\n\nLista das Jogadas:\n\n");
        }
        if(count%2 == 0)
        {
        printf("Jogador1 jogou:\n");
        printf("Linha: %d\n", t->linha);
        printf("Coluna:% d\n\n", t->coluna);
        }
        else
        {
        printf("BOT jogou:\n");
        printf("Linha: %d\n", t->linha);
        printf("Coluna:% d\n\n", t->coluna);
        }
        count++;
    }
}


int Jogadas(Tab TabuleiroJogo, Jogador Jogador1, Jogador Jogador2, int *jogada, int *mT, struct Lista** L)
{

    ///JOGADOR 1
    if(*jogada == 1)
    {
        printf("\nDigite a linha e a coluna para jogar no Tabuleiro%d:  ",TabuleiroJogo.miniTab);
        if(TabuleiroJogo.miniTab == 1)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 1 && TabuleiroJogo.linha <= 3) && (TabuleiroJogo.coluna >= 1 && TabuleiroJogo.coluna <= 3)))
            {
                printf("\nNao estas a jogar no Tabuleiro1!!!");
                printf("\nEstas sao as restricoes do Tabuleiro1:");
                printf("\n\n 1 <= linhas <= 3");
                printf("\n 1 <= colunas <= 3");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 2)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 1 && TabuleiroJogo.linha <= 3) && (TabuleiroJogo.coluna >= 4 && TabuleiroJogo.coluna <= 6)))
            {
                printf("\nNao estas a jogar no Tabuleiro2!!!");
                printf("\nEstas sao as restricoes do Tabuleiro2:");
                printf("\n\n 1 <= linhas <= 3");
                printf("\n 4 <= colunas <= 6");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 3)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 1 && TabuleiroJogo.linha <= 3) && (TabuleiroJogo.coluna >= 7 && TabuleiroJogo.coluna <= 9)))
            {
                printf("\nNao estas a jogar no Tabuleiro3!!!");
                printf("\nEstas sao as restricoes do Tabuleiro3:");
                printf("\n\n 1 <= linhas <= 3");
                printf("\n 7 <= colunas <= 9");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 4)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 4 && TabuleiroJogo.linha <= 6) && (TabuleiroJogo.coluna >= 1 && TabuleiroJogo.coluna <= 3)))
            {
                printf("\nNao estas a jogar no Tabuleiro4!!!");
                printf("\nEstas sao as restricoes do Tabuleiro4:");
                printf("\n\n 4 <= linhas <= 6");
                printf("\n 1 <= colunas <= 3");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 5)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 4 && TabuleiroJogo.linha <= 6) && (TabuleiroJogo.coluna >= 4 && TabuleiroJogo.coluna <= 6)))
            {
                printf("\nNao estas a jogar no Tabuleiro5!!!");
                printf("\nEstas sao as restricoes do Tabuleiro5:");
                printf("\n\n 4 <= linhas <= 6");
                printf("\n 4 <= colunas <= 6");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 6)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 4 && TabuleiroJogo.linha <= 6) && (TabuleiroJogo.coluna >= 7 && TabuleiroJogo.coluna <= 9)))
            {
                printf("\nNao estas a jogar no Tabuleiro6!!!");
                printf("\nEstas sao as restricoes do Tabuleiro6:");
                printf("\n\n 4 <= linhas <= 6");
                printf("\n 7 <= colunas <= 9");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 7)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 7 && TabuleiroJogo.linha <= 9) && (TabuleiroJogo.coluna >= 1 && TabuleiroJogo.coluna <= 3)))
            {
                printf("\nNao estas a jogar no Tabuleiro7!!!");
                printf("\nEstas sao as restricoes do Tabuleiro7:");
                printf("\n\n 7 <= linhas <= 9");
                printf("\n 1 <= colunas <= 3");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 8)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 7 && TabuleiroJogo.linha <= 9) && (TabuleiroJogo.coluna >= 4 && TabuleiroJogo.coluna <= 6)))
            {
                printf("\nNao estas a jogar no Tabuleiro8!!!");
                printf("\nEstas sao as restricoes do Tabuleiro8:");
                printf("\n\n 7 <= linhas <= 9");
                printf("\n 4 <= colunas <= 6");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 9)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 7 && TabuleiroJogo.linha <= 9) && (TabuleiroJogo.coluna >= 7 && TabuleiroJogo.coluna <= 9)))
            {
                printf("\nNao estas a jogar no Tabuleiro9!!!");
                printf("\nEstas sao as restricoes do Tabuleiro9:");
                printf("\n\n 7 <= linhas <= 9");
                printf("\n 7 <= colunas <= 9");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        ///Alinhar Tabuleiro
        TabuleiroJogo.linha = TabuleiroJogo.linha-1;
        TabuleiroJogo.coluna = TabuleiroJogo.coluna-1;
        getPos(TabuleiroJogo.p, TabuleiroJogo.linha, TabuleiroJogo.coluna);

        /// Valida��o de Casas Ocupadas
        while(TabuleiroJogo.p[TabuleiroJogo.linha][TabuleiroJogo.coluna] == 'X' || TabuleiroJogo.p[TabuleiroJogo.linha][TabuleiroJogo.coluna] == 'O')
        {
            printf("\nCASA OCUPADA - Tente outra vez\n");

            if(TabuleiroJogo.miniTab == 1)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 1 && TabuleiroJogo.linha <= 3) && (TabuleiroJogo.coluna >= 1 && TabuleiroJogo.coluna <= 3)))
                {
                    printf("\nNao estas a jogar no Tabuleiro1!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro1:");
                    printf("\n\n 1 <= linhas <= 3");
                    printf("\n 1 <= colunas <= 3");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 2)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 1 && TabuleiroJogo.linha <= 3) && (TabuleiroJogo.coluna >= 4 && TabuleiroJogo.coluna <= 6)))
                {
                    printf("\nNao estas a jogar no Tabuleiro2!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro2:");
                    printf("\n\n 1 <= linhas <= 3");
                    printf("\n 4 <= colunas <= 6");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 3)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 1 && TabuleiroJogo.linha <= 3) && (TabuleiroJogo.coluna >= 7 && TabuleiroJogo.coluna <= 9)))
                {
                    printf("\nNao estas a jogar no Tabuleiro3!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro3:");
                    printf("\n\n 1 <= linhas <= 3");
                    printf("\n 7 <= colunas <= 9");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 4)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 4 && TabuleiroJogo.linha <= 6) && (TabuleiroJogo.coluna >= 1 && TabuleiroJogo.coluna <= 3)))
                {
                    printf("\nNao estas a jogar no Tabuleiro4!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro4:");
                    printf("\n\n 4 <= linhas <= 6");
                    printf("\n 1 <= colunas <= 3");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 5)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 4 && TabuleiroJogo.linha <= 6) && (TabuleiroJogo.coluna >= 4 && TabuleiroJogo.coluna <= 6)))
                {
                    printf("\nNao estas a jogar no Tabuleiro5!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro5:");
                    printf("\n\n 4 <= linhas <= 6");
                    printf("\n 4 <= colunas <= 6");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 6)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 4 && TabuleiroJogo.linha <= 6) && (TabuleiroJogo.coluna >= 7 && TabuleiroJogo.coluna <= 9)))
                {
                    printf("\nNao estas a jogar no Tabuleiro6!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro6:");
                    printf("\n\n 4 <= linhas <= 6");
                    printf("\n 7 <= colunas <= 9");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 7)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 7 && TabuleiroJogo.linha <= 9) && (TabuleiroJogo.coluna >= 1 && TabuleiroJogo.coluna <= 3)))
                {
                    printf("\nNao estas a jogar no Tabuleiro7!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro7:");
                    printf("\n\n 7 <= linhas <= 9");
                    printf("\n 1 <= colunas <= 3");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 8)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 7 && TabuleiroJogo.linha <= 9) && (TabuleiroJogo.coluna >= 4 && TabuleiroJogo.coluna <= 6)))
                {
                    printf("\nNao estas a jogar no Tabuleiro8!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro8:");
                    printf("\n\n 7 <= linhas <= 9");
                    printf("\n 4 <= colunas <= 6");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 9)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 7 && TabuleiroJogo.linha <= 9) && (TabuleiroJogo.coluna >= 7 && TabuleiroJogo.coluna <= 9)))
                {
                    printf("\nNao estas a jogar no Tabuleiro9!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro9:");
                    printf("\n\n 7 <= linhas <= 9");
                    printf("\n 7 <= colunas <= 9");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }


            ///Alinhar Tabuleiro
            TabuleiroJogo.linha = TabuleiroJogo.linha-1;
            TabuleiroJogo.coluna = TabuleiroJogo.coluna-1;
            getPos(TabuleiroJogo.p, TabuleiroJogo.linha, TabuleiroJogo.coluna);

        }

        setPos(TabuleiroJogo.p, TabuleiroJogo.linha, TabuleiroJogo.coluna, Jogador1.c);
        *mT = TabuleiroJogo.miniTab;
        *jogada = 2;
    }

    ///JOGADOR 2
    else if(*jogada == 2)
    {
        printf("\nDigite a linha e a coluna para jogar no Tabuleiro%d:  ",TabuleiroJogo.miniTab);
        if(TabuleiroJogo.miniTab == 1)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 1 && TabuleiroJogo.linha <= 3) && (TabuleiroJogo.coluna >= 1 && TabuleiroJogo.coluna <= 3)))
            {
                printf("\nNao estas a jogar no Tabuleiro1!!!");
                printf("\nEstas sao as restricoes do Tabuleiro1:");
                printf("\n\n 1 <= linhas <= 3");
                printf("\n 1 <= colunas <= 3");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 2)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 1 && TabuleiroJogo.linha <= 3) && (TabuleiroJogo.coluna >= 4 && TabuleiroJogo.coluna <= 6)))
            {
                printf("\nNao estas a jogar no Tabuleiro2!!!");
                printf("\nEstas sao as restricoes do Tabuleiro2:");
                printf("\n\n 1 <= linhas <= 3");
                printf("\n 4 <= colunas <= 6");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 3)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 1 && TabuleiroJogo.linha <= 3) && (TabuleiroJogo.coluna >= 7 && TabuleiroJogo.coluna <= 9)))
            {
                printf("\nNao estas a jogar no Tabuleiro3!!!");
                printf("\nEstas sao as restricoes do Tabuleiro3:");
                printf("\n\n 1 <= linhas <= 3");
                printf("\n 7 <= colunas <= 9");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 4)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 4 && TabuleiroJogo.linha <= 6) && (TabuleiroJogo.coluna >= 1 && TabuleiroJogo.coluna <= 3)))
            {
                printf("\nNao estas a jogar no Tabuleiro4!!!");
                printf("\nEstas sao as restricoes do Tabuleiro4:");
                printf("\n\n 4 <= linhas <= 6");
                printf("\n 1 <= colunas <= 3");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 5)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 4 && TabuleiroJogo.linha <= 6) && (TabuleiroJogo.coluna >= 4 && TabuleiroJogo.coluna <= 6)))
            {
                printf("\nNao estas a jogar no Tabuleiro5!!!");
                printf("\nEstas sao as restricoes do Tabuleiro5:");
                printf("\n\n 4 <= linhas <= 6");
                printf("\n 4 <= colunas <= 6");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 6)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 4 && TabuleiroJogo.linha <= 6) && (TabuleiroJogo.coluna >= 7 && TabuleiroJogo.coluna <= 9)))
            {
                printf("\nNao estas a jogar no Tabuleiro6!!!");
                printf("\nEstas sao as restricoes do Tabuleiro6:");
                printf("\n\n 4 <= linhas <= 6");
                printf("\n 7 <= colunas <= 9");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 7)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 7 && TabuleiroJogo.linha <= 9) && (TabuleiroJogo.coluna >= 1 && TabuleiroJogo.coluna <= 3)))
            {
                printf("\nNao estas a jogar no Tabuleiro7!!!");
                printf("\nEstas sao as restricoes do Tabuleiro7:");
                printf("\n\n 7 <= linhas <= 9");
                printf("\n 1 <= colunas <= 3");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 8)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 7 && TabuleiroJogo.linha <= 9) && (TabuleiroJogo.coluna >= 4 && TabuleiroJogo.coluna <= 6)))
            {
                printf("\nNao estas a jogar no Tabuleiro8!!!");
                printf("\nEstas sao as restricoes do Tabuleiro8:");
                printf("\n\n 7 <= linhas <= 9");
                printf("\n 4 <= colunas <= 6");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 9)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 7 && TabuleiroJogo.linha <= 9) && (TabuleiroJogo.coluna >= 7 && TabuleiroJogo.coluna <= 9)))
            {
                printf("\nNao estas a jogar no Tabuleiro9!!!");
                printf("\nEstas sao as restricoes do Tabuleiro9:");
                printf("\n\n 7 <= linhas <= 9");
                printf("\n 7 <= colunas <= 9");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        ///Alinhar Tabuleiro
        TabuleiroJogo.linha = TabuleiroJogo.linha-1;
        TabuleiroJogo.coluna = TabuleiroJogo.coluna-1;
        getPos(TabuleiroJogo.p, TabuleiroJogo.linha, TabuleiroJogo.coluna);

        /// Valida��o de Casas Ocupadas
        while(TabuleiroJogo.p[TabuleiroJogo.linha][TabuleiroJogo.coluna] == 'X' || TabuleiroJogo.p[TabuleiroJogo.linha][TabuleiroJogo.coluna] == 'O')
        {
            printf("\nCASA OCUPADA - Tente outra vez\n");

            if(TabuleiroJogo.miniTab == 1)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 1 && TabuleiroJogo.linha <= 3) && (TabuleiroJogo.coluna >= 1 && TabuleiroJogo.coluna <= 3)))
                {
                    printf("\nNao estas a jogar no Tabuleiro1!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro1:");
                    printf("\n\n 1 <= linhas <= 3");
                    printf("\n 1 <= colunas <= 3");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 2)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 1 && TabuleiroJogo.linha <= 3) && (TabuleiroJogo.coluna >= 4 && TabuleiroJogo.coluna <= 6)))
                {
                    printf("\nNao estas a jogar no Tabuleiro2!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro2:");
                    printf("\n\n 1 <= linhas <= 3");
                    printf("\n 4 <= colunas <= 6");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 3)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 1 && TabuleiroJogo.linha <= 3) && (TabuleiroJogo.coluna >= 7 && TabuleiroJogo.coluna <= 9)))
                {
                    printf("\nNao estas a jogar no Tabuleiro3!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro3:");
                    printf("\n\n 1 <= linhas <= 3");
                    printf("\n 7 <= colunas <= 9");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 4)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 4 && TabuleiroJogo.linha <= 6) && (TabuleiroJogo.coluna >= 1 && TabuleiroJogo.coluna <= 3)))
                {
                    printf("\nNao estas a jogar no Tabuleiro4!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro4:");
                    printf("\n\n 4 <= linhas <= 6");
                    printf("\n 1 <= colunas <= 3");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 5)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 4 && TabuleiroJogo.linha <= 6) && (TabuleiroJogo.coluna >= 4 && TabuleiroJogo.coluna <= 6)))
                {
                    printf("\nNao estas a jogar no Tabuleiro5!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro5:");
                    printf("\n\n 4 <= linhas <= 6");
                    printf("\n 4 <= colunas <= 6");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 6)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 4 && TabuleiroJogo.linha <= 6) && (TabuleiroJogo.coluna >= 7 && TabuleiroJogo.coluna <= 9)))
                {
                    printf("\nNao estas a jogar no Tabuleiro6!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro6:");
                    printf("\n\n 4 <= linhas <= 6");
                    printf("\n 7 <= colunas <= 9");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 7)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 7 && TabuleiroJogo.linha <= 9) && (TabuleiroJogo.coluna >= 1 && TabuleiroJogo.coluna <= 3)))
                {
                    printf("\nNao estas a jogar no Tabuleiro7!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro7:");
                    printf("\n\n 7 <= linhas <= 9");
                    printf("\n 1 <= colunas <= 3");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 8)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 7 && TabuleiroJogo.linha <= 9) && (TabuleiroJogo.coluna >= 4 && TabuleiroJogo.coluna <= 6)))
                {
                    printf("\nNao estas a jogar no Tabuleiro8!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro8:");
                    printf("\n\n 7 <= linhas <= 9");
                    printf("\n 4 <= colunas <= 6");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 9)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 7 && TabuleiroJogo.linha <= 9) && (TabuleiroJogo.coluna >= 7 && TabuleiroJogo.coluna <= 9)))
                {
                    printf("\nNao estas a jogar no Tabuleiro9!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro9:");
                    printf("\n\n 7 <= linhas <= 9");
                    printf("\n 7 <= colunas <= 9");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }


            ///Alinhar Tabuleiro
            TabuleiroJogo.linha = TabuleiroJogo.linha-1;
            TabuleiroJogo.coluna = TabuleiroJogo.coluna-1;
            getPos(TabuleiroJogo.p, TabuleiroJogo.linha, TabuleiroJogo.coluna);

        }

        setPos(TabuleiroJogo.p, TabuleiroJogo.linha, TabuleiroJogo.coluna, Jogador2.c);
        *mT = TabuleiroJogo.miniTab;
        *jogada = 1;
    }
}






int Jogadas2(Tab TabuleiroJogo, Jogador Jogador1, Jogador BOT, int *jogada, int *mT, struct Lista** L)
{
    ///JOGADOR 1
    if(*jogada == 1)
    {
        printf("\nDigite a linha e a coluna para jogar no Tabuleiro%d:  ",TabuleiroJogo.miniTab);
        if(TabuleiroJogo.miniTab == 1)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 1 && TabuleiroJogo.linha <= 3) && (TabuleiroJogo.coluna >= 1 && TabuleiroJogo.coluna <= 3)))
            {
                printf("\nNao estas a jogar no Tabuleiro1!!!");
                printf("\nEstas sao as restricoes do Tabuleiro1:");
                printf("\n\n 1 <= linhas <= 3");
                printf("\n 1 <= colunas <= 3");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 2)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 1 && TabuleiroJogo.linha <= 3) && (TabuleiroJogo.coluna >= 4 && TabuleiroJogo.coluna <= 6)))
            {
                printf("\nNao estas a jogar no Tabuleiro2!!!");
                printf("\nEstas sao as restricoes do Tabuleiro2:");
                printf("\n\n 1 <= linhas <= 3");
                printf("\n 4 <= colunas <= 6");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 3)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 1 && TabuleiroJogo.linha <= 3) && (TabuleiroJogo.coluna >= 7 && TabuleiroJogo.coluna <= 9)))
            {
                printf("\nNao estas a jogar no Tabuleiro3!!!");
                printf("\nEstas sao as restricoes do Tabuleiro3:");
                printf("\n\n 1 <= linhas <= 3");
                printf("\n 7 <= colunas <= 9");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 4)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 4 && TabuleiroJogo.linha <= 6) && (TabuleiroJogo.coluna >= 1 && TabuleiroJogo.coluna <= 3)))
            {
                printf("\nNao estas a jogar no Tabuleiro4!!!");
                printf("\nEstas sao as restricoes do Tabuleiro4:");
                printf("\n\n 4 <= linhas <= 6");
                printf("\n 1 <= colunas <= 3");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 5)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 4 && TabuleiroJogo.linha <= 6) && (TabuleiroJogo.coluna >= 4 && TabuleiroJogo.coluna <= 6)))
            {
                printf("\nNao estas a jogar no Tabuleiro5!!!");
                printf("\nEstas sao as restricoes do Tabuleiro5:");
                printf("\n\n 4 <= linhas <= 6");
                printf("\n 4 <= colunas <= 6");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 6)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 4 && TabuleiroJogo.linha <= 6) && (TabuleiroJogo.coluna >= 7 && TabuleiroJogo.coluna <= 9)))
            {
                printf("\nNao estas a jogar no Tabuleiro6!!!");
                printf("\nEstas sao as restricoes do Tabuleiro6:");
                printf("\n\n 4 <= linhas <= 6");
                printf("\n 7 <= colunas <= 9");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 7)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 7 && TabuleiroJogo.linha <= 9) && (TabuleiroJogo.coluna >= 1 && TabuleiroJogo.coluna <= 3)))
            {
                printf("\nNao estas a jogar no Tabuleiro7!!!");
                printf("\nEstas sao as restricoes do Tabuleiro7:");
                printf("\n\n 7 <= linhas <= 9");
                printf("\n 1 <= colunas <= 3");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 8)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 7 && TabuleiroJogo.linha <= 9) && (TabuleiroJogo.coluna >= 4 && TabuleiroJogo.coluna <= 6)))
            {
                printf("\nNao estas a jogar no Tabuleiro8!!!");
                printf("\nEstas sao as restricoes do Tabuleiro8:");
                printf("\n\n 7 <= linhas <= 9");
                printf("\n 4 <= colunas <= 6");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        else if(TabuleiroJogo.miniTab == 9)
        {
            printf("\nlinha: ");
            scanf("%d",&TabuleiroJogo.linha);
            printf("coluna: ");
            scanf("%d",&TabuleiroJogo.coluna);
            printf("\n");
            while(!((TabuleiroJogo.linha >= 7 && TabuleiroJogo.linha <= 9) && (TabuleiroJogo.coluna >= 7 && TabuleiroJogo.coluna <= 9)))
            {
                printf("\nNao estas a jogar no Tabuleiro9!!!");
                printf("\nEstas sao as restricoes do Tabuleiro9:");
                printf("\n\n 7 <= linhas <= 9");
                printf("\n 7 <= colunas <= 9");
                printf("\n\nTenta outra vez.");
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
            }
            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
        }
        ///Alinhar Tabuleiro
        TabuleiroJogo.linha = TabuleiroJogo.linha-1;
        TabuleiroJogo.coluna = TabuleiroJogo.coluna-1;
        getPos(TabuleiroJogo.p, TabuleiroJogo.linha, TabuleiroJogo.coluna);

        /// Valida��o de Casas Ocupadas
        while(TabuleiroJogo.p[TabuleiroJogo.linha][TabuleiroJogo.coluna] == 'X' || TabuleiroJogo.p[TabuleiroJogo.linha][TabuleiroJogo.coluna] == 'O')
        {
            printf("\nCASA OCUPADA - Tente outra vez\n");

            if(TabuleiroJogo.miniTab == 1)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 1 && TabuleiroJogo.linha <= 3) && (TabuleiroJogo.coluna >= 1 && TabuleiroJogo.coluna <= 3)))
                {
                    printf("\nNao estas a jogar no Tabuleiro1!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro1:");
                    printf("\n\n 1 <= linhas <= 3");
                    printf("\n 1 <= colunas <= 3");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 2)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 1 && TabuleiroJogo.linha <= 3) && (TabuleiroJogo.coluna >= 4 && TabuleiroJogo.coluna <= 6)))
                {
                    printf("\nNao estas a jogar no Tabuleiro2!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro2:");
                    printf("\n\n 1 <= linhas <= 3");
                    printf("\n 4 <= colunas <= 6");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 3)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 1 && TabuleiroJogo.linha <= 3) && (TabuleiroJogo.coluna >= 7 && TabuleiroJogo.coluna <= 9)))
                {
                    printf("\nNao estas a jogar no Tabuleiro3!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro3:");
                    printf("\n\n 1 <= linhas <= 3");
                    printf("\n 7 <= colunas <= 9");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 4)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 4 && TabuleiroJogo.linha <= 6) && (TabuleiroJogo.coluna >= 1 && TabuleiroJogo.coluna <= 3)))
                {
                    printf("\nNao estas a jogar no Tabuleiro4!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro4:");
                    printf("\n\n 4 <= linhas <= 6");
                    printf("\n 1 <= colunas <= 3");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 5)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 4 && TabuleiroJogo.linha <= 6) && (TabuleiroJogo.coluna >= 4 && TabuleiroJogo.coluna <= 6)))
                {
                    printf("\nNao estas a jogar no Tabuleiro5!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro5:");
                    printf("\n\n 4 <= linhas <= 6");
                    printf("\n 4 <= colunas <= 6");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 6)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 4 && TabuleiroJogo.linha <= 6) && (TabuleiroJogo.coluna >= 7 && TabuleiroJogo.coluna <= 9)))
                {
                    printf("\nNao estas a jogar no Tabuleiro6!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro6:");
                    printf("\n\n 4 <= linhas <= 6");
                    printf("\n 7 <= colunas <= 9");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 7)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 7 && TabuleiroJogo.linha <= 9) && (TabuleiroJogo.coluna >= 1 && TabuleiroJogo.coluna <= 3)))
                {
                    printf("\nNao estas a jogar no Tabuleiro7!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro7:");
                    printf("\n\n 7 <= linhas <= 9");
                    printf("\n 1 <= colunas <= 3");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 8)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 7 && TabuleiroJogo.linha <= 9) && (TabuleiroJogo.coluna >= 4 && TabuleiroJogo.coluna <= 6)))
                {
                    printf("\nNao estas a jogar no Tabuleiro8!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro8:");
                    printf("\n\n 7 <= linhas <= 9");
                    printf("\n 4 <= colunas <= 6");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }
            else if(TabuleiroJogo.miniTab == 9)
            {
                printf("\nlinha: ");
                scanf("%d",&TabuleiroJogo.linha);
                printf("coluna: ");
                scanf("%d",&TabuleiroJogo.coluna);
                printf("\n");
                while(!((TabuleiroJogo.linha >= 7 && TabuleiroJogo.linha <= 9) && (TabuleiroJogo.coluna >= 7 && TabuleiroJogo.coluna <= 9)))
                {
                    printf("\nNao estas a jogar no Tabuleiro9!!!");
                    printf("\nEstas sao as restricoes do Tabuleiro9:");
                    printf("\n\n 7 <= linhas <= 9");
                    printf("\n 7 <= colunas <= 9");
                    printf("\n\nTenta outra vez.");
                    printf("\nlinha: ");
                    scanf("%d",&TabuleiroJogo.linha);
                    printf("coluna: ");
                    scanf("%d",&TabuleiroJogo.coluna);
                    printf("\n");
                }
                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);

                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            }


            ///Alinhar Tabuleiro
            TabuleiroJogo.linha = TabuleiroJogo.linha-1;
            TabuleiroJogo.coluna = TabuleiroJogo.coluna-1;
            getPos(TabuleiroJogo.p, TabuleiroJogo.linha, TabuleiroJogo.coluna);

        }

        setPos(TabuleiroJogo.p, TabuleiroJogo.linha, TabuleiroJogo.coluna, Jogador1.c);
        *mT = TabuleiroJogo.miniTab;
        *jogada = 3;
    }

    ///BOT
    else if(*jogada == 3)
    {
        printf("\n");

        if(TabuleiroJogo.miniTab == 1)
        {

            TabuleiroJogo.linha = intUniformRnd(1,3);
            TabuleiroJogo.coluna = intUniformRnd(1,3);

            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);

        }
        else if(TabuleiroJogo.miniTab == 2)
        {


            TabuleiroJogo.linha = intUniformRnd(1,3);
            TabuleiroJogo.coluna = intUniformRnd(4,6);

            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);

        }
        else if(TabuleiroJogo.miniTab == 3)
        {

            TabuleiroJogo.linha = intUniformRnd(1,3);
            TabuleiroJogo.coluna = intUniformRnd(7,9);

            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);

        }
        else if(TabuleiroJogo.miniTab == 4)
        {

            TabuleiroJogo.linha = intUniformRnd(4,6);
            TabuleiroJogo.coluna = intUniformRnd(1,3);

            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);

        }
        else if(TabuleiroJogo.miniTab == 5)
        {

            TabuleiroJogo.linha = intUniformRnd(4,6);
            TabuleiroJogo.coluna = intUniformRnd(4,6);

            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);

        }
        else if(TabuleiroJogo.miniTab == 6)
        {
            TabuleiroJogo.linha = intUniformRnd(4,6);
            TabuleiroJogo.coluna = intUniformRnd(7,9);

            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);

        }
        else if(TabuleiroJogo.miniTab == 7)
        {

            TabuleiroJogo.linha = intUniformRnd(7,9);
            TabuleiroJogo.coluna = intUniformRnd(1,3);

            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);

        }
        else if(TabuleiroJogo.miniTab == 8)
        {
            TabuleiroJogo.linha = intUniformRnd(7,9);
            TabuleiroJogo.coluna = intUniformRnd(4,6);

            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);

        }
        else if(TabuleiroJogo.miniTab == 9)
        {
            TabuleiroJogo.linha = intUniformRnd(7,9);
            TabuleiroJogo.coluna = intUniformRnd(7,9);

            InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);
            RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);

        }
        ///Alinhar Tabuleiro
        TabuleiroJogo.linha = TabuleiroJogo.linha-1;
        TabuleiroJogo.coluna = TabuleiroJogo.coluna-1;
        getPos(TabuleiroJogo.p, TabuleiroJogo.linha, TabuleiroJogo.coluna);

        while(TabuleiroJogo.p[TabuleiroJogo.linha][TabuleiroJogo.coluna] == 'X' || TabuleiroJogo.p[TabuleiroJogo.linha][TabuleiroJogo.coluna] == 'O')
        {
            if(TabuleiroJogo.miniTab == 1)
            {

                TabuleiroJogo.linha = intUniformRnd(1,3);
                TabuleiroJogo.coluna = intUniformRnd(1,3);

                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);
                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            }
            else if(TabuleiroJogo.miniTab == 2)
            {


                TabuleiroJogo.linha = intUniformRnd(1,3);
                TabuleiroJogo.coluna = intUniformRnd(4,6);

                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);
                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            }
            else if(TabuleiroJogo.miniTab == 3)
            {

                TabuleiroJogo.linha = intUniformRnd(1,3);
                TabuleiroJogo.coluna = intUniformRnd(7,9);

                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);
                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            }
            else if(TabuleiroJogo.miniTab == 4)
            {

                TabuleiroJogo.linha = intUniformRnd(4,6);
                TabuleiroJogo.coluna = intUniformRnd(1,3);

                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);
                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            }
            else if(TabuleiroJogo.miniTab == 5)
            {

                TabuleiroJogo.linha = intUniformRnd(4,6);
                TabuleiroJogo.coluna = intUniformRnd(4,6);

                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);
                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            }
            else if(TabuleiroJogo.miniTab == 6)
            {
                TabuleiroJogo.linha = intUniformRnd(4,6);
                TabuleiroJogo.coluna = intUniformRnd(7,9);

                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);
                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            }
            else if(TabuleiroJogo.miniTab == 7)
            {

                TabuleiroJogo.linha = intUniformRnd(7,9);
                TabuleiroJogo.coluna = intUniformRnd(1,3);

                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);
                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            }
            else if(TabuleiroJogo.miniTab == 8)
            {
                TabuleiroJogo.linha = intUniformRnd(7,9);
                TabuleiroJogo.coluna = intUniformRnd(4,6);

                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);
                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            }
            else if(TabuleiroJogo.miniTab == 9)
            {
                TabuleiroJogo.linha = intUniformRnd(7,9);
                TabuleiroJogo.coluna = intUniformRnd(7,9);

                InsereJogada(L,TabuleiroJogo.linha,TabuleiroJogo.coluna);
                RegraJogo(&TabuleiroJogo.miniTab,TabuleiroJogo.linha,TabuleiroJogo.coluna);

            }

            ///Alinhar Tabuleiro
            TabuleiroJogo.linha = TabuleiroJogo.linha-1;
            TabuleiroJogo.coluna = TabuleiroJogo.coluna-1;
            getPos(TabuleiroJogo.p, TabuleiroJogo.linha, TabuleiroJogo.coluna);
        }

        setPos(TabuleiroJogo.p, TabuleiroJogo.linha, TabuleiroJogo.coluna, BOT.c);
        *mT = TabuleiroJogo.miniTab;
        *jogada = 1;
    }
}






int GanhouTab1(Tab TabuleiroJogo, int *gTab, int *jogada)
{
    int i, j, q=3;
    char x;
    char y;

    ///COLUNA
    for(i=0; i<q; i++)
        if(TabuleiroJogo.p[0][i] != '_')
        {
            for(j=0; j<q-1 && TabuleiroJogo.p[j][i] == TabuleiroJogo.p[j+1][i]; j++);
            if(j==q-1)
            {
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            }

            //printf("GANHOUUUUUUUUUUU   COLUNA");
        }

    ///LINHA
    for(i=0; i<q; i++)
        if(TabuleiroJogo.p[i][0] != '_')
        {
            for(j=0; j<q-1 && TabuleiroJogo.p[i][j] == TabuleiroJogo.p[i][j+1]; j++);
            if(j==q-1)
            {
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            }
            // printf("GANHOUUUUUUUUUUU   LINHA");
        }

    ///DIAGONAL.1
    x = TabuleiroJogo.p[0][0];
    int cont=0;

    if (x != '_')
    {
        for (i = 0; i < q; i++)
        {
            if (TabuleiroJogo.p[i][i] == x)
            {
                cont++;
            }
        }
        if (cont==3)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            //printf("GANHOUUUUUUUUUUU   DIAGONAL1");
        }

    }

    ///DIAGONAL.2
    y = TabuleiroJogo.p[0][q-1];
    int cont2=0;

    if(y != '_')
    {
        for (i = 0; i < q; i++)
        {
            if (TabuleiroJogo.p[i][q-i-1] == y)
            {
                cont2++;
            }
        }
        if (cont2==3)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            //printf("GANHOUUUUUUUUUUU   DIAGONAL2");
        }
    }
}

int GanhouTab2(Tab TabuleiroJogo, int *gTab, int *jogada)
{
    int i, j, l=3, c=6;
    char x;
    char y;

    ///COLUNA
    for(i=3; i<c; i++)
        if(TabuleiroJogo.p[0][i] != '_')
        {
            for(j=0; j<l-1 && TabuleiroJogo.p[j][i] == TabuleiroJogo.p[j+1][i]; j++);
            if(j==l-1)
            {
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            }
            // printf("GANHOUUUUUUUUUUU   COLUNA TAB2");
        }

    ///LINHA
    for(i=0; i<l; i++)
        if(TabuleiroJogo.p[i][3] != '_')
        {
            for(j=3; j<c-1 && TabuleiroJogo.p[i][j] == TabuleiroJogo.p[i][j+1]; j++);
            if(j==c-1)
            {
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            }
            // printf("GANHOUUUUUUUUUUU   LINHA TAB2");
        }

    ///DIAGONAL.1
    x = TabuleiroJogo.p[0][3];
    if (x != '_')
    {
        if (TabuleiroJogo.p[1][4] == x && TabuleiroJogo.p[2][5] == x)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            // printf("GANHOUUUUUUUUUUU   DIAGONAL1 TAB2");
        }
    }


    ///DIAGONAL.2
    y = TabuleiroJogo.p[0][5];
    if(y != '_')
    {
        if (TabuleiroJogo.p[1][4] == y && TabuleiroJogo.p[2][3] == y)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            // printf("GANHOUUUUUUUUUUU   DIAGONAL2 TAB2");
        }
    }
}

int GanhouTab3(Tab TabuleiroJogo, int *gTab, int *jogada)
{
    int i, j, l=3, c=9;
    char x;
    char y;

    ///COLUNA
    for(i=6; i<c; i++)
        if(TabuleiroJogo.p[0][i] != '_')
        {
            for(j=0; j<l-1 && TabuleiroJogo.p[j][i] == TabuleiroJogo.p[j+1][i]; j++);
            if(j==l-1)
            {
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            }
            // printf("GANHOUUUUUUUUUUU   COLUNA TAB3");
        }

    ///LINHA
    for(i=0; i<l; i++)
        if(TabuleiroJogo.p[i][6] != '_')
        {
            for(j=6; j<c-1 && TabuleiroJogo.p[i][j] == TabuleiroJogo.p[i][j+1]; j++);
            if(j==c-1)
            {
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            }
            // printf("GANHOUUUUUUUUUUU   LINHA TAB3");
        }

    ///DIAGONAL.1
    x = TabuleiroJogo.p[0][6];
    if (x != '_')
    {
        if (TabuleiroJogo.p[1][7] == x && TabuleiroJogo.p[2][8] == x)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            //printf("GANHOUUUUUUUUUUU   DIAGONAL1 TAB3");
        }
    }


    ///DIAGONAL.2
    y = TabuleiroJogo.p[0][8];
    if(y != '_')
    {
        if (TabuleiroJogo.p[1][7] == y && TabuleiroJogo.p[2][6] == y)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            // printf("GANHOUUUUUUUUUUU   DIAGONAL2 TAB3");
        }
    }
}

int GanhouTab4(Tab TabuleiroJogo, int *gTab, int *jogada)
{
    int i, j, l=6, c=3;
    char x;
    char y;

    ///COLUNA
    for(i=0; i<c; i++)
        if(TabuleiroJogo.p[3][i] != '_')
        {
            for(j=3; j<l-1 && TabuleiroJogo.p[j][i] == TabuleiroJogo.p[j+1][i]; j++);
            if(j==l-1)
            {
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            }
            // printf("GANHOUUUUUUUUUUU   COLUNA TAB4");
        }

    ///LINHA
    for(i=3; i<l; i++)
        if(TabuleiroJogo.p[i][0] != '_')
        {
            for(j=0; j<c-1 && TabuleiroJogo.p[i][j] == TabuleiroJogo.p[i][j+1]; j++);
            if(j==c-1)
            {
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            }
            //  printf("GANHOUUUUUUUUUUU   LINHA TAB4");
        }

    ///DIAGONAL.1
    x = TabuleiroJogo.p[3][0];
    if (x != '_')
    {
        if (TabuleiroJogo.p[4][1] == x && TabuleiroJogo.p[5][2] == x)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            // printf("GANHOUUUUUUUUUUU   DIAGONAL1 TAB4");
        }
    }


    ///DIAGONAL.2
    y = TabuleiroJogo.p[3][2];
    if(y != '_')
    {
        if (TabuleiroJogo.p[4][1] == y && TabuleiroJogo.p[5][0] == y)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            // printf("GANHOUUUUUUUUUUU   DIAGONAL2 TAB4");
        }
    }
}

int GanhouTab5(Tab TabuleiroJogo, int *gTab, int *jogada)
{
    int i, j, l=6, c=6;
    char x;
    char y;

    ///COLUNA
    for(i=3; i<c; i++)
        if(TabuleiroJogo.p[3][i] != '_')
        {
            for(j=3; j<l-1 && TabuleiroJogo.p[j][i] == TabuleiroJogo.p[j+1][i]; j++);
            if(j==l-1)
            {
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            }
            // printf("GANHOUUUUUUUUUUU   COLUNA TAB5");
        }

    ///LINHA
    for(i=3; i<l; i++)
        if(TabuleiroJogo.p[i][3] != '_')
        {
            for(j=3; j<c-1 && TabuleiroJogo.p[i][j] == TabuleiroJogo.p[i][j+1]; j++);
            if(j==c-1)
            {
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            }
            // printf("GANHOUUUUUUUUUUU   LINHA TAB5");
        }

    ///DIAGONAL.1
    x = TabuleiroJogo.p[3][3];
    if (x != '_')
    {
        if (TabuleiroJogo.p[4][4] == x && TabuleiroJogo.p[5][5] == x)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            // printf("GANHOUUUUUUUUUUU   DIAGONAL1 TAB5");
        }
    }


    ///DIAGONAL.2
    y = TabuleiroJogo.p[3][5];
    if(y != '_')
    {
        if (TabuleiroJogo.p[4][4] == y && TabuleiroJogo.p[5][3] == y)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            // printf("GANHOUUUUUUUUUUU   DIAGONAL2 TAB5");
        }
    }
}

int GanhouTab6(Tab TabuleiroJogo, int *gTab, int *jogada)
{
    int i, j, l=6, c=9;
    char x;
    char y;

    ///COLUNA
    for(i=6; i<c; i++)
        if(TabuleiroJogo.p[3][i] != '_')
        {
            for(j=3; j<l-1 && TabuleiroJogo.p[j][i] == TabuleiroJogo.p[j+1][i]; j++);
            if(j==l-1)
            {
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            }
            //  printf("GANHOUUUUUUUUUUU   COLUNA TAB6");
        }

    ///LINHA
    for(i=3; i<l; i++)
        if(TabuleiroJogo.p[i][6] != '_')
        {
            for(j=6; j<c-1 && TabuleiroJogo.p[i][j] == TabuleiroJogo.p[i][j+1]; j++);
            if(j==c-1)
            {
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            }
            //  printf("GANHOUUUUUUUUUUU   LINHA TAB6");
        }

    ///DIAGONAL.1
    x = TabuleiroJogo.p[3][6];
    if (x != '_')
    {
        if (TabuleiroJogo.p[4][7] == x && TabuleiroJogo.p[5][8] == x)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            //  printf("GANHOUUUUUUUUUUU   DIAGONAL1 TAB6");
        }
    }


    ///DIAGONAL.2
    y = TabuleiroJogo.p[3][8];
    if(y != '_')
    {
        if (TabuleiroJogo.p[4][7] == y && TabuleiroJogo.p[5][6] == y)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            //  printf("GANHOUUUUUUUUUUU   DIAGONAL2 TAB6");
        }
    }
}

int GanhouTab7(Tab TabuleiroJogo, int *gTab, int *jogada)
{

    int i, j, l=9, c=3;
    char x;
    char y;

    ///COLUNA
    for(i=0; i<c; i++)
        if(TabuleiroJogo.p[6][i] != '_')
        {
            for(j=6; j<l-1 && TabuleiroJogo.p[j][i] == TabuleiroJogo.p[j+1][i]; j++);
            if(j==l-1)
            {
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            }
            // printf("GANHOUUUUUUUUUUU   COLUNA TAB7");
        }

    ///LINHA
    for(i=6; i<l; i++)
        if(TabuleiroJogo.p[i][0] != '_')
        {
            for(j=0; j<c-1 && TabuleiroJogo.p[i][j] == TabuleiroJogo.p[i][j+1]; j++);
            if(j==c-1)
            {
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            }
            //  printf("GANHOUUUUUUUUUUU   LINHA TAB7");
        }

    ///DIAGONAL.1
    x = TabuleiroJogo.p[6][0];
    if (x != '_')
    {
        if (TabuleiroJogo.p[7][1] == x && TabuleiroJogo.p[8][2] == x)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            // printf("GANHOUUUUUUUUUUU   DIAGONAL1 TAB7");
        }
    }


    ///DIAGONAL.2
    y = TabuleiroJogo.p[6][2];
    if(y != '_')
    {
        if (TabuleiroJogo.p[7][1] == y && TabuleiroJogo.p[8][0] == y)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            // printf("GANHOUUUUUUUUUUU   DIAGONAL2 TAB7");
        }
    }
}

int GanhouTab8(Tab TabuleiroJogo, int *gTab, int *jogada)
{
    int i, j, l=9, c=6;
    char x;
    char y;

    ///COLUNA
    for(i=3; i<c; i++)
        if(TabuleiroJogo.p[6][i] != '_')
        {
            for(j=6; j<l-1 && TabuleiroJogo.p[j][i] == TabuleiroJogo.p[j+1][i]; j++);
            if(j==l-1)
            {
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            }
            //   printf("GANHOUUUUUUUUUUU   COLUNA TAB8");
        }

    ///LINHA
    for(i=6; i<l; i++)
        if(TabuleiroJogo.p[i][3] != '_')
        {
            for(j=3; j<c-1 && TabuleiroJogo.p[i][j] == TabuleiroJogo.p[i][j+1]; j++);
            if(j==c-1)
            {
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            }
            // printf("GANHOUUUUUUUUUUU   LINHA TAB8");
        }

    ///DIAGONAL.1
    x = TabuleiroJogo.p[6][3];
    if (x != '_')
    {
        if (TabuleiroJogo.p[7][4] == x && TabuleiroJogo.p[8][5] == x)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            // printf("GANHOUUUUUUUUUUU   DIAGONAL1 TAB8");
        }
    }


    ///DIAGONAL.2
    y = TabuleiroJogo.p[6][5];
    if(y != '_')
    {
        if (TabuleiroJogo.p[7][4] == y && TabuleiroJogo.p[8][3] == y)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            // printf("GANHOUUUUUUUUUUU   DIAGONAL2 TAB8");
        }
    }
}

int GanhouTab9(Tab TabuleiroJogo, int *gTab, int *jogada)
{
    int i, j, l=9, c=9;
    char x;
    char y;

    ///COLUNA
    for(i=6; i<c; i++)
        if(TabuleiroJogo.p[6][i] != '_')
        {
            for(j=6; j<l-1 && TabuleiroJogo.p[j][i] == TabuleiroJogo.p[j+1][i]; j++);
            if(j==l-1)
            {
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            }
            // printf("GANHOUUUUUUUUUUU   COLUNA TAB9");
        }

    ///LINHA
    for(i=6; i<l; i++)
        if(TabuleiroJogo.p[i][6] != '_')
        {
            for(j=6; j<c-1 && TabuleiroJogo.p[i][j] == TabuleiroJogo.p[i][j+1]; j++);
            if(j==c-1)
            {
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            }
            // printf("GANHOUUUUUUUUUUU   LINHA TAB9");
        }

    ///DIAGONAL.1
    x = TabuleiroJogo.p[6][6];
    if (x != '_')
    {
        if (TabuleiroJogo.p[7][7] == x && TabuleiroJogo.p[8][8] == x)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            // printf("GANHOUUUUUUUUUUU   DIAGONAL1 TAB9");
        }
    }


    ///DIAGONAL.2
    y = TabuleiroJogo.p[6][8];
    if(y != '_')
    {
        if (TabuleiroJogo.p[7][7] == y && TabuleiroJogo.p[8][6] == y)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            // printf("GANHOUUUUUUUUUUU   DIAGONAL2 TAB9");
        }
    }
}

int GanhouTabFinal(Tab TabuleiroFinal, int *gTab, int *jogada)
{
    int i, j, q=3;
    char x;
    char y;

    ///COLUNA
    for(i=0; i<q; i++)
        if(TabuleiroFinal.p[0][i] != '_')
        {
            for(j=0; j<q-1 && TabuleiroFinal.p[j][i] == TabuleiroFinal.p[j+1][i]; j++);
            if(j==q-1)
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            //printf("GANHOUUUUUUUUUUU   COLUNA");
        }

    ///LINHA
    for(i=0; i<q; i++)
        if(TabuleiroFinal.p[i][0] != '_')
        {
            for(j=0; j<q-1 && TabuleiroFinal.p[i][j] == TabuleiroFinal.p[i][j+1]; j++);
            if(j==q-1)
                if(*jogada==1)
                {
                    *gTab=2;
                }
                else if(*jogada==2)
                {
                    *gTab=1;
                }
            // printf("GANHOUUUUUUUUUUU   LINHA");
        }

    ///DIAGONAL.1
    x = TabuleiroFinal.p[0][0];
    int cont=0;

    if (x != '_')
    {
        for (i = 0; i < q; i++)
        {
            if (TabuleiroFinal.p[i][i] == x)
            {
                cont++;
            }
        }
        if (cont==3)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            //printf("GANHOUUUUUUUUUUU   DIAGONAL1");
        }

    }

    ///DIAGONAL.2
    y = TabuleiroFinal.p[0][q-1];
    int cont2=0;

    if(y != '_')
    {
        for (i = 0; i < q; i++)
        {
            if (TabuleiroFinal.p[i][q-i-1] == y)
            {
                cont2++;
            }
        }
        if (cont2==3)
        {
            if(*jogada==1)
            {
                *gTab=2;
            }
            else if(*jogada==2)
            {
                *gTab=1;
            }
            //printf("GANHOUUUUUUUUUUU   DIAGONAL2");
        }
    }
}