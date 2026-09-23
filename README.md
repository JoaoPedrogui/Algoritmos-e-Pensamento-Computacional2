# Algoritmos-e-Pensamento-Computacional2[README.md](https://github.com/user-attachments/files/32561068/README.md)
# Desafio de Monitoramento de Temperatura

## 1. Identificação

- **Aluno:** João Pedro Guimarães de Lima Cruvinel
- **Disciplina:** Desenvolvimento de Sistemas
- **Professora:** Profa. Karla Sartin
- **Título:** Desafio de Monitoramento de Temperatura

## 2. Objetivo

Desenvolver um programa em C que monitore leituras de temperatura, compare cada valor com um limite definido pelo usuário e encerre automaticamente quando forem registradas três temperaturas consecutivas acima desse limite. Ao final, o programa apresenta um relatório estatístico.

## 3. Funcionamento do programa

1. O usuário define o limite máximo de temperatura. O programa aceita somente um valor numérico não negativo.
2. O usuário informa as temperaturas uma a uma.
3. Entradas que não sejam numéricas são descartadas e solicitadas novamente. O limite negativo também é rejeitado.
4. Cada temperatura válida é comparada com o limite. Valores acima dele geram um alerta e aumentam o contador de consecutivas.
5. Se uma temperatura estiver dentro do limite, o contador de consecutivas volta a zero.
6. O monitoramento termina quando o usuário informa um valor negativo (sentinela) ou quando são detectadas três temperaturas consecutivas acima do limite.
7. O relatório apresenta limite, quantidade de leituras válidas, média, maior e menor temperatura, quantidade acima do limite e percentual acima do limite. O valor negativo usado como sentinela não participa dos cálculos.

## 4. Estruturas de repetição utilizadas

- **`do...while`:** usado na definição do limite, pois a solicitação precisa acontecer pelo menos uma vez. A condição é verificada depois da tentativa de leitura, repetindo enquanto o limite não for válido.
- **`while`:** usado no monitoramento, mantendo a repetição enquanto a sequência de temperaturas acima do limite for menor que três. O laço também pode ser interrompido pelo valor negativo sentinela.
- **`while` para limpeza de entrada:** descarta os caracteres restantes quando o usuário digita algo que não é numérico, permitindo uma nova tentativa.

A combinação é adequada porque o limite deve ser solicitado antes de sua validação, enquanto o monitoramento precisa continuar somente enquanto a condição de encerramento não for atingida.

## 5. Como executar

É necessário ter um compilador C, como o GCC.

### Linux / macOS

```bash
gcc monitoramento.c -o monitoramento
./monitoramento
```

### Windows (MinGW)

```bash
gcc monitoramento.c -o monitoramento.exe
monitoramento.exe
```

## 6. Testes realizados

Os cenários abaixo podem ser reproduzidos no terminal. Registre uma captura de tela de cada execução e salve-a na pasta `evidencias/` com os nomes indicados. As imagens devem ser capturadas após executar o programa; não são substituídas por este roteiro.

### Teste 1 — Validação de entradas inválidas (`teste01.png`)

- Limite: digitar `abc`, depois `-5` e, por fim, `30`.
- Leituras: digitar `xyz`, depois `25`, e encerrar com `-1`.
- **Resultado esperado:** o programa informa entradas inválidas, rejeita o limite negativo, aceita `30`, contabiliza somente `25` e encerra pelo sentinela.

### Teste 2 — Temperaturas acima do limite, mas não consecutivas (`teste02.png`)

- Limite: `30`
- Leituras: `35`, `28`, `34`, `29`, `-1`
- **Resultado esperado:** os valores `35` e `34` geram alerta, mas `28` e `29` zeram a sequência. O programa não encerra automaticamente; encerra pelo sentinela. São 4 leituras válidas, 2 acima do limite e percentual de 50%.

### Teste 3 — Três temperaturas consecutivas acima do limite (`teste03.png`)

- Limite: `30`
- Leituras: `31`, `32`, `33`
- **Resultado esperado:** o contador chega a 3 e o monitoramento encerra automaticamente. São 3 leituras válidas, todas acima do limite (100%).

## 7. Reflexão final

Escolhi o `do...while` para solicitar o limite porque essa etapa precisa ser executada pelo menos uma vez, e só depois é possível verificar se o valor digitado é válido. Já o `while` foi escolhido para o monitoramento porque a repetição deve continuar enquanto ainda não houver três temperaturas consecutivas acima do limite. Assim, a diferença entre testar a condição depois da execução (`do...while`) e antes de cada repetição (`while`) foi importante para controlar corretamente essas duas etapas do algoritmo.
