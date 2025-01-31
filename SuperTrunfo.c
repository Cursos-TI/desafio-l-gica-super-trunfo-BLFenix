#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_CIDADES 8

// Criação da estrutura que armazenará as cidades

typedef struct
{
    char Estado[51];
    char Nome[51];
    char Codigo[4];
    int Populacao;
    float Area;
    float PIB;
    int NumPonTuristicos;
    float DensPopulacional;
    float PIBPerCapita;
    float SuperPoder;
} Cidade;

// Criação da função de amostragem de cartas

void ExibirCarta(Cidade cidade)
{
    printf("\nEstado: %s", cidade.Estado);
    printf("\nNome: %s", cidade.Nome);
    printf("\nCódigo: %s", cidade.Codigo);
    printf("\nPopulação: %d pessoas", cidade.Populacao);
    printf("\nÁrea: %.2f Km²", cidade.Area);
    printf("\nPIB: R$ %.2f", cidade.PIB);
    printf("\nPontos turísticos: %d", cidade.NumPonTuristicos);
    printf("\nDensidade populacional: %.2f pessoas por Km²", cidade.DensPopulacional);
    printf("\nPIB per capita: R$ %.2f por pessoa", cidade.PIBPerCapita);
    printf("\nSuper poder:  %.2f pontos\n\n", cidade.SuperPoder);
}

// Função que mostra o resultado das batalhas

void MostrarResultadoBatalha(char Bat_Carac[], float Bat_Campo1, float Bat_Campo2, char Bat_Nome1[], char Bat_Nome2[], int *Guer1_PTS, int *Guer2_PTS)
{
    if (Bat_Campo1 > Bat_Campo2)
    {
        printf("\nA cidade: %s é a vencedora da competição de %s\n", Bat_Nome1, Bat_Carac);
        (*Guer1_PTS)++;
    }
    else if (Bat_Campo2 > Bat_Campo1)
    {
        printf("\nA cidade: %s é a vencedora da competição de %s\n", Bat_Nome2, Bat_Carac);
        (*Guer2_PTS)++;
    }
    else
    {
        printf("\n\nHouve um empate na competição de %s: Nenhuma cidade pontuou\n\n", Bat_Carac);
    }
}

// Função que envia os dados para a que mostra os resultados da batalha

void RealizarBatalha(int *ListCaracBat, int QuantCaracBat, Cidade guerreira1, Cidade guerreira2, int *Guer1_PTS, int *Guer2_PTS)
{
    float Bat_Campo1, Bat_Campo2;
    char Bat_Carac[51], Bat_Nome1[51], Bat_Nome2[51];
    // Realizando a batalha entre cada característica das cartas

    printf("\n\n***** A seguir estarão os resultados da batalha de cartas *****\n\n");

    for (int i = 0; i < QuantCaracBat; i++)
    {
        switch (ListCaracBat[i])
        {
        case 1:
            strcpy(Bat_Carac, "População");
            Bat_Campo1 = (float)guerreira1.Populacao;
            Bat_Campo2 = (float)guerreira2.Populacao;
            strcpy(Bat_Nome1, guerreira1.Nome);
            strcpy(Bat_Nome2, guerreira2.Nome);
            MostrarResultadoBatalha(Bat_Carac, Bat_Campo1, Bat_Campo2, Bat_Nome1, Bat_Nome2, Guer1_PTS, Guer2_PTS);
            break;
        case 2:
            strcpy(Bat_Carac, "Área");
            Bat_Campo1 = guerreira1.Area;
            Bat_Campo2 = guerreira2.Area;
            strcpy(Bat_Nome1, guerreira1.Nome);
            strcpy(Bat_Nome2, guerreira2.Nome);
            MostrarResultadoBatalha(Bat_Carac, Bat_Campo1, Bat_Campo2, Bat_Nome1, Bat_Nome2, Guer1_PTS, Guer2_PTS);
            break;
        case 3:
            strcpy(Bat_Carac, "PIB");
            Bat_Campo1 = guerreira1.PIB;
            Bat_Campo2 = guerreira2.PIB;
            strcpy(Bat_Nome1, guerreira1.Nome);
            strcpy(Bat_Nome2, guerreira2.Nome);
            MostrarResultadoBatalha(Bat_Carac, Bat_Campo1, Bat_Campo2, Bat_Nome1, Bat_Nome2, Guer1_PTS, Guer2_PTS);
            break;
        case 4:
            strcpy(Bat_Carac, "Número De Pontos Turísticos");
            Bat_Campo1 = (float)guerreira1.NumPonTuristicos;
            Bat_Campo2 = (float)guerreira2.NumPonTuristicos;
            strcpy(Bat_Nome1, guerreira1.Nome);
            strcpy(Bat_Nome2, guerreira2.Nome);
            MostrarResultadoBatalha(Bat_Carac, Bat_Campo1, Bat_Campo2, Bat_Nome1, Bat_Nome2, Guer1_PTS, Guer2_PTS);
            break;
        case 5:
            strcpy(Bat_Carac, "Densidade Populacional");
            Bat_Campo1 = guerreira2.DensPopulacional; // Densidades populacionais trocadas, pois a densidade vencedora é a menor
            Bat_Campo2 = guerreira1.DensPopulacional; // Densidades populacionais trocadas, pois a densidade vencedora é a menor
            strcpy(Bat_Nome1, guerreira1.Nome);
            strcpy(Bat_Nome2, guerreira2.Nome);
            MostrarResultadoBatalha(Bat_Carac, Bat_Campo1, Bat_Campo2, Bat_Nome1, Bat_Nome2, Guer1_PTS, Guer2_PTS);
            break;
        case 6:
            strcpy(Bat_Carac, "PIB Per Capita");
            Bat_Campo1 = guerreira1.PIBPerCapita;
            Bat_Campo2 = guerreira2.PIBPerCapita;
            strcpy(Bat_Nome1, guerreira1.Nome);
            strcpy(Bat_Nome2, guerreira2.Nome);
            MostrarResultadoBatalha(Bat_Carac, Bat_Campo1, Bat_Campo2, Bat_Nome1, Bat_Nome2, Guer1_PTS, Guer2_PTS);
            break;
        case 7:
            strcpy(Bat_Carac, "Super Poder");
            Bat_Campo1 = guerreira1.SuperPoder;
            Bat_Campo2 = guerreira2.SuperPoder;
            strcpy(Bat_Nome1, guerreira1.Nome);
            strcpy(Bat_Nome2, guerreira2.Nome);
            MostrarResultadoBatalha(Bat_Carac, Bat_Campo1, Bat_Campo2, Bat_Nome1, Bat_Nome2, Guer1_PTS, Guer2_PTS);
            break;

        default:
            break;
        }
    }

    // Limpando os dados da lista

    free(ListCaracBat);

    // Amostragem da carta vencedora

    if (*Guer1_PTS > *Guer2_PTS)
    {
        char PalPonto[7] = "Exemplo";
        strcpy(PalPonto, ((*Guer1_PTS) == 1 ? "ponto" : "pontos"));
        printf("\nA Cidade vencedora da competição é a %s, com %d %s!\n", guerreira1.Codigo, *Guer1_PTS, PalPonto);
        printf("\nTodos os dados da vencedora:\n");

        ExibirCarta(guerreira1);
    }
    else if (*Guer2_PTS > *Guer1_PTS)
    {
        char PalPonto[7] = "Exemplo";
        strcpy(PalPonto, ((*Guer1_PTS) == 1 ? "ponto" : "pontos"));
        printf("\nA Cidade vencedora da competição é a %s, com %d %s!\n", guerreira2.Codigo, *Guer2_PTS, PalPonto);
        printf("\nTodos os dados da vencedora:\n");

        ExibirCarta(guerreira2);
    }
    else
    {
        printf("\nHouve um empate na competição: A pontuação de ambas as cidades foi igual a %d\n\n", *Guer1_PTS);
    }
}

// Função que mostra as regras

void exibirRegras()
{
    printf("=== Regras do Jogo Super Trunfo - Países ===\n\n");

    printf("Objetivo do Jogo:\n");
    printf("- O objetivo do jogo é comparar cartas de cidades e determinar a vencedora com base em atributos como:\n");
    printf("- População\n");
    printf("- Área\n");
    printf("- PIB\n");
    printf("- Número de Pontos Turísticos\n");
    printf("- Densidade Populacional (onde a menor densidade é vantajosa)\n\n");

    printf("Como Jogar:\n");
    printf("1. Cadastro das Cartas:\n");
    printf("- Você vai cadastrar várias cartas com informações sobre diferentes cidades.\n");
    printf("- Cada carta possui os seguintes atributos:\n");
    printf("- Estado\n");
    printf("- Código da Carta\n");
    printf("- Nome da Cidade\n");
    printf("- População\n");
    printf("- Área\n");
    printf("- PIB\n");
    printf("- Número de Pontos Turísticos\n");
    printf("- Densidade Populacional (onde a menor densidade é vantajosa)\n\n");

    printf("2. Escolha do Atributo para Comparação:\n");
    printf("- Você escolherá um atributo para comparar entre duas cartas.\n");
    printf("- No nível Novato, o atributo é fixo, mas em níveis mais avançados, você pode escolher.\n\n");

    printf("3. Comparação das Cartas:\n");
    printf("- O sistema irá comparar duas cartas com base no atributo escolhido.\n");
    printf("- A carta com o maior valor (ou menor, no caso da densidade populacional) vence.\n");
    printf("- Em caso de empate, será exibido uma mensagem dizendo que houve um empate.\n\n");

    printf("4. Exibição dos Resultados:\n");
    printf("- Após a comparação, o sistema exibirá qual carta venceu.\n");
    printf("- Será mostrado o valor do atributo utilizado na comparação.\n\n");

    printf("5. Reiniciar ou Continuar:\n");
    printf("- Após cada rodada, você pode fazer uma nova comparação, cadastrar mais cartas ou encerrar o jogo.\n\n");

    printf("Regras Específicas de Comparação:\n");
    printf("- Para os atributos: População, Área e PIB: a carta com o maior valor vence.\n");
    printf("- Para Densidade Populacional: a carta com a menor densidade vence (mais espaço por pessoa).\n");
    printf("- Para o Número de Pontos Turísticos: a cidade com o maior número vence.\n\n");

    printf("Empates:\n");
    printf("- Se o valor do atributo for o mesmo para ambas as cartas, haverá um empate.\n");
    printf("- O sistema pode pedir para você escolher outro critério ou realizar uma nova rodada.\n\n");

    printf("Finalização do Jogo:\n");
    printf("- O jogo continuará até você decidir parar ou todas as cartas serem comparadas.\n");
    printf("- Ao final, você verá um resumo das vitórias, empates e derrotas.\n\n");

    printf("===========================================\n\n");
    printf("Boa sorte e divirta-se jogando Super Trunfo - Países!\n\n");
    printf("Agora, vamos jogar!\n\n");
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Cidade cidades[MAX_CIDADES];
    Cidade guerreira1;
    Cidade guerreira2;

    int NumCidades, QuantCaracBat, Menu;

Inicio:

    printf("\n**** Seja bem vindo ao Super Trunfo! ****");

    printf("\nDiga-me, o que desejas:\n1 - Jogar\n2 - Ver as regras\n3 - Finalizar jogo\n");
    scanf(" %d", &Menu);

    switch (Menu)
    {
    case 1:
    CriarCarta:

        // Só permite ao usuário cadastrar cidades no limite estabelecido

        do
        {
            printf("\nQuantas cidades deseja cadastrar? (Max.: %d) \n", MAX_CIDADES);
            scanf(" %d", &NumCidades);

            if (NumCidades < 1 || NumCidades > MAX_CIDADES)
            {
                printf("\nO número digitado não respeita o limite!");
                continue;
            }

        } while (NumCidades < 1 || NumCidades > MAX_CIDADES);

        while (Menu == 1)
        {

            // Coleta dos dados das cidades.

            for (int i = 0; i < NumCidades; i++)
            {
                printf("\nCrie uma carta a seguir:\n\n");

                printf("\nEstado: ");
                scanf(" %20[^\n]", cidades[i].Estado);

                printf("\nNome da cidade: ");
                scanf(" %20[^\n]", cidades[i].Nome);

                printf("\nCódigo:(Ex.: A01, A02) ");
                scanf(" %3s", cidades[i].Codigo);

                printf("\nPopulação: ");
                scanf(" %d", &cidades[i].Populacao);

                printf("\nÁrea: (Em Km²)");
                scanf(" %f", &cidades[i].Area);

                printf("\nPIB: (Em R$)");
                scanf(" %f", &cidades[i].PIB);

                printf("\nNúmero de pontos turísticos: ");
                scanf(" %d", &cidades[i].NumPonTuristicos);

                cidades[i].DensPopulacional = (float)cidades[i].Populacao / cidades[i].Area;
                cidades[i].PIBPerCapita = (float)cidades[i].PIB / cidades[i].Populacao;
                cidades[i].SuperPoder = (float)cidades[i].Populacao + cidades[i].Area + cidades[i].PIB + cidades[i].NumPonTuristicos + cidades[i].DensPopulacional + cidades[i].PIBPerCapita;

                printf("\nCidade cadastrada! Dados exibidos a seguir:");

                ExibirCarta(cidades[i]);
            }

            // Mínimo duas cidades para jogar

            if (NumCidades < 2)
            {
                printf("\nPara conseguir batalhar com as cartas, deve-se ter pelo menos duas.\n");
                printf("\nO que gostaria de fazer?\n1 - Criar novas cartas\n2 - Finalizar o jogo\n");
                scanf(" %d", &Menu);

                switch (Menu)
                {
                case 1:
                    goto CriarCarta;
                    break;
                case 2:
                    goto Finalizar;
                    break;
                default:
                    break;
                }
            }
            else
            {
                Menu = 3;
            }

        Batalhar:

            while (Menu == 3 && NumCidades >= 2)
            {
                int Guer1_PTS = 0;
                int Guer2_PTS = 0;

                // Amostragem das cartas criadas

                printf("\n**** Ok! Vamos agora pôr as cidades em batalha! ****\n");

                printf("\nGostaria de ver as cartas completas ou apenas seus nome e código?\n1 - Completa\n2 - Nome e código \n");
                scanf(" %d", &Menu);

                // Verificação se a pessoa quer visualizar apenas o nome, ou as cartas completas.

                switch (Menu)
                {
                case 1:
                    printf("\nA seguir, estão as cartas criadas:\n");

                    for (int i = 0; i < NumCidades; i++)
                    {
                        ExibirCarta(cidades[i]);
                    }
                    break;
                case 2:
                    printf("\nA seguir, estão as cartas criadas:\n");

                    for (int i = 0; i < NumCidades; i++)
                    {
                        printf("\nNome da carta: %s\n", cidades[i].Nome);
                        printf("Código da carta: %s\n", cidades[i].Codigo);
                    }
                    break;
                default:
                    break;
                }

                // Seleção das cartas que irão batalhar

                int Encontrou1 = 0;
                int Encontrou2 = 0;

                do
                {
                    char CodBatalha1[4], CodBatalha2[4];

                    printf("\nDigite, a seguir, os códigos das cartas que deseja que batalhem: (Digite o primeiro, pressione enter e digite o segundo)\n");
                    scanf(" %3s %3s", CodBatalha1, CodBatalha2);

                    for (int i = 0; i < NumCidades; i++)
                    {
                        if (strcmp(CodBatalha1, cidades[i].Codigo) == 0)
                        {
                            guerreira1 = cidades[i];
                            Encontrou1 = 1;
                        }
                        else if (strcmp(CodBatalha2, cidades[i].Codigo) == 0)
                        {
                            guerreira2 = cidades[i];
                            Encontrou2 = 1;
                        }
                    }
                    if (Encontrou1 != 1 || Encontrou2 != 1)
                    {
                        printf("\nErro, código não encontrado, tente novamente!\n");
                        continue;
                    }
                } while (Encontrou1 != 1 || Encontrou2 != 1);

                // Amostragem das cartas que irão batalhar

                printf("\nLogo abaixo estão nossas cartas guerreiras:\n");

                printf("\n**** Primeira desafiante: ****\n");

                ExibirCarta(guerreira1);

                printf("\n**** Segunda desafiante: ****\n");

                ExibirCarta(guerreira2);

                // Só permite ao usuário selecionar as características no limite estabelecido

                do
                {
                    printf("\nQuantas características você deseja colocar em batalha? (1 a 7)");
                    scanf(" %d", &QuantCaracBat);

                    if (QuantCaracBat < 1 || QuantCaracBat > 7)
                    {
                        printf("\nA quantidade fornecida não respeita o limite!");
                        continue;
                    }

                } while (QuantCaracBat < 1 || QuantCaracBat > 7);

                // Deixando a lista com o tamanho certo permanentemente

                int *ListCaracBat = (int *)malloc(QuantCaracBat * 4);
                if (ListCaracBat == NULL)
                {
                    printf("Erro ao alocar memória!\n");
                    return 1; // Saída com erro
                }

                // If e else que vão delimitar se o usuário quer todas as características ou não, na batalha

                if (QuantCaracBat == 7)
                {
                    for (int i = 0; i < 7; i++)
                    {
                        ListCaracBat[i] = i + 1;
                        printf("\nItem %d: %d \n", i + 1, ListCaracBat[i]);
                    }

                    RealizarBatalha(ListCaracBat, QuantCaracBat, guerreira1, guerreira2, &Guer1_PTS, &Guer2_PTS);

                    printf("\nEscolha, agora, sua próxima ação:\n1 - Para criar novas cartas\n2 - Para finalizar o jogo\n3 - Para batalhar novamente\n");
                    scanf(" %d", &Menu);
                    switch (Menu)
                    {
                    case 1:
                        goto CriarCarta;
                        break;
                    case 2:
                        goto Finalizar;
                        break;
                    case 3:
                        goto Batalhar;
                        break;
                    default:
                        break;
                    }
                }
                else
                {

                    // Dá as opções de características a se escolher

                    printf("\nAnalise as características e, à seguir, escolha segundo a quantidade selecionada:\n");
                    printf("\n1 - População");
                    printf("\n2 - Area");
                    printf("\n3 - PIB");
                    printf("\n4 - Número de pontos turísticos");
                    printf("\n5 - Densidade populacional");
                    printf("\n6 - PIB per capita");
                    printf("\n7 - Super poder\n");

                    // Adicionando à lista as características que serão usadas na batalha

                    for (int i = 0; i < QuantCaracBat; i++)
                    {
                        int NumCaracBat;
                        do
                        {
                            printf("\nDigite o número da %d característica: ", i + 1);
                            scanf(" %d", &NumCaracBat);

                            if (NumCaracBat < 1 || NumCaracBat > 7)
                            {
                                printf("\nO valor fornecido não respeita o limite! (1 a 7)");
                                continue;
                            }
                        } while (NumCaracBat < 1 || NumCaracBat > 7);
                        ListCaracBat[i] = NumCaracBat;
                    }

                    // Chamando a função para realizar a batalha

                    RealizarBatalha(ListCaracBat, QuantCaracBat, guerreira1, guerreira2, &Guer1_PTS, &Guer2_PTS);

                    printf("\nEscolha, agora, sua próxima ação:\n1 - Para criar novas cartas\n2 - Para finalizar o jogo\n3 - Para batalhar novamente\n");
                    scanf(" %d", &Menu);
                    switch (Menu)
                    {
                    case 1:
                        goto CriarCarta;
                        break;
                    case 2:
                        goto Finalizar;
                        break;
                    case 3:
                        goto Batalhar;
                        break;
                    default:
                        break;
                    }
                }
            }
        }
        return 0;
        break;
    case 2:
        exibirRegras();
        goto Inicio;
        break;
    case 3:
        goto Finalizar;
        break;
    default:
        break;
    }
Finalizar:
    printf("Jogo Finalizado! Obrigado por jogar!");
    return 0;
}