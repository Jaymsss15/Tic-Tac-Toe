//Nome: Tiago Filipe Amorim Marques
//N�: 2020128217
#ifndef JOGO_H
#define JOGO_H

#define TRUE 1
#define FALSE 0

///Menu1
#define JOGAR1v1 1
#define JOGAR1vBOT 2
#define CONTINUAR 3
#define REGRAS 4
#define SAIR 5

///Menu2
#define JOGAR 1
#define JOGADAS 2
#define GUARDAR 3
#define SAIR2 4

///TabuleiroJogo
#define NLin 9
#define NCol 9

///TabuleiroFinal
#define NLin2 3
#define NCol2 3

typedef struct Jogadores
{

    char c;

} Jogador;

struct Lista
{

    int idJog;
    int AI;
    int miniTab;
    int coluna;
    int linha;
    struct Lista *next;
};

typedef struct Tabuleiro
{

    int miniTab;
    int coluna;
    int linha;
    char **p;

} Tab;

void flush_in();

///Menus
int menu();
int menu2();
int menu3();

void RegraJogo(int *miniTab, int l, int c);

void LibertaLista(struct Lista *L);

///ListaJogadas
struct Lista InsereJogada(struct Lista **L, int lin, int col, int miniTab, int AI, int nJogador);
int MostrarLista(struct Lista *L, int nJogada);
int MostrarListaBOT(struct Lista *L, int nJogada);

void GuardaJogobin(struct Lista *L);
void GuardaJogobinBOT(struct Lista *L);

void GuardaJogotxt(char *fName, struct Lista *L);
void GuardaJogotxtBOT(char *fName, struct Lista *L);

struct Lista ContinuaJogo(struct Lista *L, Tab TabuleiroJogo, Jogador Jogador1, Jogador Outro, int *mT, int *AI, int *nJogador);

int Jogadas(Tab TabuleiroJogo, Jogador Jogador1, Jogador Jogador2, Jogador BOT, int *nJogador, int *mT, struct Lista **L, int AI);

int GanhouTab1(Tab TabuleiroJogo, int *gTab, int *nJogador);
int GanhouTab2(Tab TabuleiroJogo, int *gTab, int *nJogador);
int GanhouTab3(Tab TabuleiroJogo, int *gTab, int *nJogador);
int GanhouTab4(Tab TabuleiroJogo, int *gTab, int *nJogador);
int GanhouTab5(Tab TabuleiroJogo, int *gTab, int *nJogador);
int GanhouTab6(Tab TabuleiroJogo, int *gTab, int *nJogador);
int GanhouTab7(Tab TabuleiroJogo, int *gTab, int *nJogador);
int GanhouTab8(Tab TabuleiroJogo, int *gTab, int *nJogador);
int GanhouTab9(Tab TabuleiroJogo, int *gTab, int *nJogador);
int GanhouTabFinal(Tab TabuleiroFinal, int *gTab, int *nJogador);

#endif
