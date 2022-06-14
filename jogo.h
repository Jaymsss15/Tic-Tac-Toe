//Nome: Tiago Filipe Amorim Marques
//Nº: 2020128217
#ifndef JOGO_H
#define JOGO_H

///Menu1
#define JOGAR 1
#define JOGAR1vBOT 2
#define CONTINUAR 3
#define REGRAS 4
#define SAIR 5

///Menu2
#define JOGADAS 2
#define GUARDAR 3
#define SAIR2 4

///TabuleiroJogo
#define NLin 9
#define NCol 9

///TabuleiroFinal
#define NLin2 3
#define NCol2 3

typedef struct Jogadores{

    char c;

}Jogador;


struct Lista{

int coluna;
int linha;
struct Lista* next;

};

typedef struct Tabuleiro{

    int miniTab;
    int coluna;
    int linha;
    char **p;

}Tab;


int menu();
int menu2();
int menu3();

//int GuardaJogo();

//int ContinuaJogo();

void RegraJogo(int *miniTab, int l, int c);

///ListaJogadas
struct Lista InsereJogada(struct Lista** L, int lin, int col);
int MostrarLista(struct Lista* L, int nJogada);
int MostrarLista2(struct Lista* L, int nJogada);


int Jogadas(Tab TabuleiroJogo, Jogador Jogador1, Jogador Jogador2, int *jogada, int *mT,struct Lista** L);

int Jogadas2(Tab TabuleiroJogo, Jogador Jogador1, Jogador BOT, int *jogada, int *mT,struct Lista** L);



int GanhouTab1(Tab TabuleiroJogo, int *gTab, int *jogada);
int GanhouTab2(Tab TabuleiroJogo, int *gTab, int *jogada);
int GanhouTab3(Tab TabuleiroJogo, int *gTab, int *jogada);
int GanhouTab4(Tab TabuleiroJogo, int *gTab, int *jogada);
int GanhouTab5(Tab TabuleiroJogo, int *gTab, int *jogada);
int GanhouTab6(Tab TabuleiroJogo, int *gTab, int *jogada);
int GanhouTab7(Tab TabuleiroJogo, int *gTab, int *jogada);
int GanhouTab8(Tab TabuleiroJogo, int *gTab, int *jogada);
int GanhouTab9(Tab TabuleiroJogo, int *gTab, int *jogada);
int GanhouTabFinal(Tab TabuleiroFinal, int *gTab, int *jogada);



#endif
