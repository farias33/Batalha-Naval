# Batalha Naval

Este é um jogo simples de Batalha Naval desenvolvido em C++ para ser jogado no terminal. O jogo cria um tabuleiro 10x10 e posiciona barcos aleatoriamente, permitindo que o jogador tente adivinhar as posições dos barcos. Quando o jogador acerta uma posição de água, a letra 'A' é exibida em azul no terminal.

## Funcionalidades

- **Tabuleiro 10x10**: O tabuleiro do jogo é representado por uma matriz 10x10.
- **Posicionamento Aleatório de Barcos**: Dez barcos são posicionados aleatoriamente no tabuleiro.
- **Tentativas Limitadas**: O jogador tem um número máximo de tentativas para acertar os barcos.
- **Indicação Visual**: Quando o jogador acerta uma posição de água, a letra 'A' é exibida em azul no terminal.
- **Menu Inicial**: O jogo começa com um menu onde o jogador pode escolher iniciar o jogo, ver informações sobre o jogo ou sair.

## Detalhes do Código

### Principais Funções

1. **menuInicial**: Exibe o menu principal e lida com a escolha do jogador.
2. **limpaTela**: Limpa o terminal.
3. **iniciaTabuleiro**: Inicializa o tabuleiro e a máscara do jogo com água ('A') e caracteres ocultos ('*'), respectivamente.
4. **exibeMapa**: Exibe o indicador de colunas no topo do tabuleiro.
5. **exibeTabuleiro**: Exibe o estado atual do tabuleiro. As posições de água são mostradas em azul.
6. **posicionaBarcos**: Posiciona 10 barcos ('p') aleatoriamente no tabuleiro.
7. **verificaTiro**: Verifica o resultado de um tiro do jogador e atualiza a pontuação e a mensagem de acordo.
8. **jogo**: Controla a lógica principal do jogo, incluindo a interação com o jogador e a atualização do tabuleiro.

### Uso de Cores no Terminal

Para exibir a letra 'A' em azul quando o jogador acerta uma posição de água, foram utilizadas sequências de escape ANSI:

- `BLUE_TEXT`: Define a cor azul.
- `RESET_TEXT`: Reseta a cor para o padrão.

### Habilitação de Sequências de Escape no Windows

No Windows, é necessário habilitar o processamento de sequências de escape ANSI no terminal:

```cpp
cppCopiar código
HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
DWORD dwMode = 0;
GetConsoleMode(hOut, &dwMode);
dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
SetConsoleMode(hOut, dwMode);

```

## Como Compilar e Executar

1. Compile o código com um compilador C++ (por exemplo, g++):
    
    ```
    shCopiar código
    g++ -o batalha_naval batalha_naval.cpp
    
    ```
    
2. Execute o programa compilado:
    
    ```
    shCopiar código
    ./batalha_naval
    
    ```
    

## Requisitos

- Compilador C++ compatível.
- Terminal com suporte a sequências de escape ANSI (necessário habilitar no Windows).

Divirta-se jogando Batalha Naval!
