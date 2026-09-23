/*
 * Projeto: Desafio de Monitoramento de Temperatura
 * Disciplina: Desenvolvimento de Sistemas
 * Professora: Profa. Karla Sartin
 *
 * Monitora temperaturas digitadas pelo usuario. O programa encerra
 * automaticamente quando ocorrem tres leituras validas consecutivas
 * acima do limite definido.
 */

#include <stdio.h>
#include <float.h>

int main(void) {
    double limite;
    double temperatura;
    double soma = 0.0;
    double maior = -DBL_MAX;
    double menor = DBL_MAX;
    int quantidade = 0;
    int quantidade_acima = 0;
    int consecutivas = 0;
    int limite_valido = 0;

    /* O do...while solicita o limite ao menos uma vez e valida a entrada. */
    int limite_valido = 0;
    do {
        printf("Defina o limite maximo de temperatura: ");

        if (scanf("%lf", &limite) != 1) {
            printf("Entrada invalida. Digite um numero.\\n");
            while (getchar() != '\\n') {
                /* Descarta os caracteres restantes da entrada invalida. */
            }
        } else if (limite < 0) {
            printf("O limite nao pode ser negativo. Tente novamente.\\n");
        } else {
            limite_valido = 1;
        }
    } while (!limite_valido);

    printf("\nMonitoramento iniciado. Digite temperaturas numericas.\n");
    printf("Para encerrar, informe uma temperatura negativa.\n\n");

    /* O while mantem o monitoramento ate o sentinela ou tres excessos seguidos. */
    while (consecutivas < 3) {
        printf("Temperatura: ");

        if (scanf("%lf", &temperatura) != 1) {
            printf("Entrada invalida. Digite um numero.\n");
            while (getchar() != '\n') {
                /* Limpa a entrada para permitir uma nova tentativa. */
            }
            continue;
        }

        /* Valor negativo e reservado para encerrar, nao entra nos calculos. */
        if (temperatura < 0) {
            printf("Monitoramento encerrado pelo usuario.\n");
            break;
        }

        /* Atualiza estatisticas somente com leituras validas. */
        soma += temperatura;
        quantidade++;
        leituras_validas++;

        if (temperatura > maior) {
            maior = temperatura;
        }
        if (temperatura < menor) {
            menor = temperatura;
        }

        if (temperatura > limite) {
            quantidade_acima++;
            consecutivas++;
            printf("ALERTA: temperatura acima do limite! (%d consecutiva(s))\n",
                   consecutivas);
        } else {
            /* Uma leitura dentro do limite interrompe a sequencia. */
            consecutivas = 0;
            printf("Temperatura dentro do limite.\n");
        }
    }

    if (consecutivas == 3) {
        printf("\nENCERRAMENTO AUTOMATICO: tres temperaturas consecutivas acima do limite.\n");
    }

    /* Relatorio final: evita divisao por zero se nao houver leituras validas. */
    printf("\n========== RELATORIO FINAL ==========\n");
    printf("Limite definido: %.2f\n", limite);
    printf("Quantidade de leituras validas: %d\n", quantidade);

    if (quantidade > 0) {
        printf("Media das temperaturas: %.2f\n", soma / quantidade);
        printf("Maior temperatura: %.2f\n", maior);
        printf("Menor temperatura: %.2f\n", menor);
        printf("Leituras acima do limite: %d\n", quantidade_acima);
        printf("Percentual acima do limite: %.2f%%\n",
               (double)quantidade_acima / quantidade * 100.0);
    } else {
        printf("Nenhuma leitura valida foi registrada; estatisticas indisponiveis.\n");
    }

    printf("=====================================\n");
    return 0;
}
