#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>
#include <windows.h>

using namespace std;

// Define sequências de escape ANSI para cores
#define BLUE_TEXT "\033[34m"
#define RESET_TEXT "\033[0m"

// Define o valor de ENABLE_VIRTUAL_TERMINAL_PROCESSING caso não esteja definido
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif


//Cabeçalhos de funções
void menuInicial();

void limpaTela(){
    system("CLS");
}

void iniciaTabuleiro(char tabuleiro[10][10], char mascara[10][10]){
    int linha, coluna;

    //Popula o tabuleiro com agua
    for(linha = 0; linha < 10; linha++){
        for(coluna = 0; coluna < 10; coluna++){
            tabuleiro[linha][coluna] = 'A';
            mascara[linha][coluna] = '*';
        }
    }
}

void exibeMapa(){
    //Mapa indicador de colunas
    int cont;
    for(cont = 0; cont < 10; cont++){
        if(cont == 0){
            cout << "     ";
        }
        cout << cont << " ";
    }
    cout << "\n";

}

void exibeTabuleiro(char tabuleiro[10][10], char mascara[10][10], bool mostraGabarito){

    int linha, coluna;
    
    //Exibe o tabuleiro
    for(linha = 0; linha < 10; linha++){
        cout << linha << " - ";
        for(coluna = 0; coluna < 10; coluna++){
            if(mascara[linha][coluna] == 'A'){
                cout << " " << BLUE_TEXT << mascara[linha][coluna] << RESET_TEXT;
            }else{
                cout << " " << mascara[linha][coluna];
            }
        }
        cout << "\n";
    }
    if(mostraGabarito == true){
        for(linha = 0; linha < 10; linha++){
            for(coluna = 0; coluna < 10; coluna++){
                cout << " " << tabuleiro[linha][coluna];
            }
            cout << "\n";
        }

    }
    
    
}

void posicionaBarcos(char tabuleiro[10][10]){
    int quantidade = 10, quantidadePosicionada = 0;

    //Verifica se ja posicionou todos os barcos
    while(quantidadePosicionada < quantidade){
        int linhaAleatoria = rand() % 10; //Gera um numero aleatorio de 0 a 9
        int colunaAleatoria = rand() % 10; //Gera um numero aleatorio de 0 a 9

        if(tabuleiro[linhaAleatoria][colunaAleatoria] == 'A'){

            //Posiciona 10 barcos aleatoriamente
            tabuleiro[linhaAleatoria][colunaAleatoria] = 'p';

            //Aumenta o contador de barcos posicionados
            quantidadePosicionada++;

        }

        
    }

}


void verificaTiro(char tabuleiro[10][10], int linhaJogada, int colunaJogada, int *pontos, string *mensagem){
    //Verifica quantos pontos adicionar
    switch(tabuleiro[linhaJogada][colunaJogada]){ //Uso switch caso queria adicionar outros tipos de barcos
        case 'p':
            *pontos = *pontos + 10;
            *mensagem = "Voce acertou um barco pequeno";
            break;
        case 'A':
            *mensagem = "Voce acertou a agua";
            break;
    } 
}

void jogo(string nomeDoJogador){    
    //Variáveis gerais
    char tabuleiro[10][10], mascara[10][10];
    int linhaJogada, colunaJogada;  //Posição escolhida pelo jogador           
    int pontos = 0;
    int tentativas = 0;
    int maximoDeTentativas = 5;
    int opcao;


    string mensagem = "Bem vindo ao jogo";

    //Inicia o tabuleiro com agua
    iniciaTabuleiro(tabuleiro, mascara);

    //POsiciona barcos aleatoriamente
    posicionaBarcos(tabuleiro);


    while(tentativas < maximoDeTentativas){
        limpaTela();

        //Exibe o mapa de indicações
        exibeMapa();

        //Exibe tabuleiro
        exibeTabuleiro(tabuleiro, mascara, false);

        cout << "\nPontos: " << pontos << ", Tentativas restantes: " << maximoDeTentativas - tentativas;
        cout << "\n" << mensagem;

        //Verificação de dados
        linhaJogada = - 1;
        colunaJogada = -1;

        while((linhaJogada < 0 || colunaJogada < 0) || (linhaJogada > 9 || colunaJogada > 9)){
            cout << "\n" <<nomeDoJogador <<", digite uma linha: ";
            cin >> linhaJogada;

        
            cout << "\n" << nomeDoJogador <<", digite uma coluna: ";
            cin >> colunaJogada;
        }

  

        //Verifica o que aconteceu
        verificaTiro(tabuleiro, linhaJogada, colunaJogada, &pontos, &mensagem);
        
        //Revela o que está no tabuleiro
        mascara[linhaJogada][colunaJogada] = tabuleiro[linhaJogada][colunaJogada];
        tentativas++;
    }

    cout << "Fim de Jogo, o que deseja fazer?";
    cout << "\n1 - Jogar novamente";
    cout << "\n2 - Ir para o Menu ";
    cout << "\n3 - Sair";
    cin >> opcao;

    switch(opcao){
        case 1:
            jogo(nomeDoJogador);
            break;
        case 2:
            menuInicial();
            break;
    }
}



void menuInicial(){
    int opcao = 0;
    string nomeDoJogador;
    
    //Enquanto o jogador n]ao digita uma opção válida, mostra o menu novamente
    while(opcao < 1 || opcao > 3){
        limpaTela();
        cout << "Bem vindo ao Jogo";
        cout << "\n1 - Jogar";
        cout << "\n2 - Sobre";
        cout << "\n3 - Sair";
        cout << "\nEscolha uma opcao e tecle ENTER: ";

        //Faz a leitura da opcao
        cin >> opcao;

        switch(opcao){
            case 1: //Inicia o jogo
                cout << "Qual seu nome: ";
                cin >> nomeDoJogador;
                cout << "Jogo Iniciado:\n";
                jogo(nomeDoJogador);
                break;
            case 2://Mostra Informações do jogo, escrever mais depois
                cout << "Informações do jogo";
                break;
            case 3:
                cout << "Ate mais";
                break;
        }
    }
}




int main(){
    //Para gerar numeros realmente aleatorios, se eu nao usar esse codigo, ele pega numeros aleatorios de acordo com o tempo do programa
    srand((unsigned)time(NULL));

    // Habilita sequências de escape ANSI no console do Windows
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    menuInicial();
    

    return 0;
}