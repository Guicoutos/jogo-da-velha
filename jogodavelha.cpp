#include <iostream>
using namespace std;

void init(int tabuleiro[][3]);           // Inicia o tabuleiro com 0's
char printBlock(int block);              // Exibe cada quadrado do tabuleiro
void mostrar(int tabuleiro[][3]);        // Exibe o tabuleiro
void fazJogada(int tabuleiro[][3], int); // Joga uma vez
int checkContinuar(int *tabuleiro[3]);   // Verifica se há espaço em branco
int checkVitoria(int *tabuleiro[3]);     // Verifica se há vencedor
int game(int tabuleiro[][3]);            // Inicia jogo
void placarTabuleiro(int, int &, int &); // Mostra placar

int main()
{
	setlocale (LC_ALL, "Portuguese");
	
    int tabuleiro[3][3];

    int cont=0, jogador1=0, jogador2=0, resultado;
    do{
        init(tabuleiro);
        resultado = game(tabuleiro);
        mostrar(tabuleiro);
        placarTabuleiro(resultado, jogador1, jogador2);

        cout<<"\n                       Deseja jogar outra partida?"<<endl;
        cout<< endl;
        cout<<"                                0. Sair"<<endl;
        cout<<"                                1. Jogar de novo"<<endl;
        cin >> cont;
    }while(cont);

    return 0;
}

void init(int tabuleiro[][3])
{
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            tabuleiro[i][j]=0;

}

char printBlock(int block)
{
    if(block==0)
        return ' ';
    else if(block==1)
        return 'X';
    else
        return 'O';
}

void mostrar(int tabuleiro[][3])
{
    cout<<endl;
    for(int lin=0 ; lin<3 ; lin++){
        cout<<" "<< printBlock(tabuleiro[lin][0]) <<" |";
        cout<<" "<< printBlock(tabuleiro[lin][1]) <<" |";
        cout<<" "<< printBlock(tabuleiro[lin][2]) <<endl;

        if(lin!=2){
            cout<<"___ ___ ___\n"<<endl;
        }
    }
}

void fazJogada(int tabuleiro[][3], int jogador)
{
    int lin, col, check;
    do{
        cout<<" Linha: ";
        cin >>lin;
        cout<<" Coluna: ";
        cin >> col;
        lin--; col--;

        check = tabuleiro[lin][col] || lin<0 || lin>2 || col<0 || col>2;
        if(check)
            cout<<" Essa casa não está vazia ou fora do intervalo 3x3"<<endl;

    }while(check);

    if(jogador==0)
        tabuleiro[lin][col]=1;
    else
        tabuleiro[lin][col]=-1;
}

int checkContinuar(int tabuleiro[][3])
{
    for(int i=0 ; i<3 ; i++)
        for(int j=0 ; j<3 ; j++)
            if(tabuleiro[i][j]==0)
                return 1;
    return 0;
}

int checkVitoria(int tabuleiro[][3])
{
    int lin, col, sum;

    // Adicionando linhas
    for(lin=0 ; lin<3 ; lin++){
        sum=0;

        for(col=0 ; col<3 ; col++)
            sum += tabuleiro[lin][col];

        if(sum==3)
            return 1;
        if(sum==-3)
            return -1;
    }

    // Adicionando colunas
    for(col=0 ; col<3 ; col++){
        sum=0;

        for(lin=0 ; lin<3 ; lin++)
            sum += tabuleiro[lin][col];

        if(sum==3)
            return 1;
        if(sum==-3)
            return -1;
    }

    // Adicionando diagonais
    sum=0;
    for(lin=0 ; lin<3 ; lin++)
        sum += tabuleiro[lin][lin];
    if(sum==3)
        return 1;
    if(sum==-3)
        return -1;

    sum=tabuleiro[0][2]+tabuleiro[1][1]+tabuleiro[2][0];
    if(sum==3)
        return 1;
    if(sum==-3)
        return -1;

    return 0;
}

int game(int tabuleiro[][3])
{
    int vez=0, cont, vitoria;

    do{
        mostrar(tabuleiro);
        cout<< endl;
        cout<< endl;
        cout<<"JOGADOR "<<1+vez%2<<endl;
        fazJogada(tabuleiro, vez%2);
        vez++;

        cont=checkContinuar(tabuleiro);
        vitoria = checkVitoria(tabuleiro);
    }while(cont && !vitoria);

    if(vitoria==1){
    	cout<< endl;
        cout<<" Parabéns! JOGADOR 1 ganhou! :D\n"<<endl;
        return 1;
    }else
        if(vitoria==-1){
        	cout<< endl;
            cout<<" Parabéns! JOGADOR 2 ganhou! :D\n"<<endl;
            return 2;
    }else
        cout<<" EMPATE\n"<<endl;
    return 0;
}

void placarTabuleiro(int resultado, int &jogador1, int &jogador2)
{
    if(resultado==1)
        jogador1++;
    if(resultado==2)
        jogador2++;
	
	cout<< endl;
    cout<<"\n------------------------------ *~ PLACAR ~*------------------------------"<<endl;
    cout<<"\n                                  "<<jogador1<<" x "<<jogador2<<endl;
}


