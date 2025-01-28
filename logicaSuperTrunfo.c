#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

#define MAX_CIDADES 8

// Criação da estrutura que armazenará as cidades

typedef struct
{
    char Estado[20];
    char Nome[20];
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

void ParaMaiuscula(char Variavel[])
{
    for (int i = 0; Variavel[i] != '\0'; i++)
    {
        Variavel[i] = toupper(Variavel[i]);
    }
}

// Função que mostra o resultado das batalhas

int MostrarResultadoBatalha(char Bat_Carac[50], float Bat_Campo1, float Bat_Campo2, char Bat_Nome1[20], char Bat_Nome2[20], int *Guer1_PTS, int *Guer2_PTS)
{
    if (Bat_Campo1 > Bat_Campo2)
    {
        printf("\nCidade: %s é a vencedora da competição de %s\n", Bat_Nome1, Bat_Carac);
        (*Guer1_PTS)++;
    }
    else if (Bat_Campo2 > Bat_Campo1)
    {
        printf("\nCidade: %s é a vencedora da competição de %s\n", Bat_Nome2, Bat_Carac);
        (*Guer2_PTS)++;
    }
    else
    {
        printf("\n\nHouve um empate na competição de %s: Nenhuma cidade pontuou\n\n", Bat_Carac);
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Cidade cidades[MAX_CIDADES];
    Cidade guerreira1;
    Cidade guerreira2;

    int NumCidades, QuantCaracBat, NumCaracBat;
    float Bat_Campo1, Bat_Campo2;
    char CodBatalha1[4], CodBatalha2[4], JogNovam[2] = "Y", CriaCarta[2] = "Y", VisuCartas[2], Bat_Carac[50], Bat_Nome1[20], Bat_Nome2[20];
    int Guer1_PTS = 0, Guer2_PTS = 0;

    printf("\n**** Seja bem vindo ao Super Trunfo! ****");

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

    // Verificação para saber se o número de cidades a cadastrar respeita a lógica

    while (strcmp(CriaCarta, "Y") == 0)
    {

        // Coleta dos dados das cidades.

        for (int i = 0; i < NumCidades; i++)
        {
            printf("\nCrie uma carta a seguir:\n\n");

            printf("\nEstado: ");
            scanf(" %19[^\n]", cidades[i].Estado);

            printf("\nNome: ");
            scanf(" %19[^\n]", cidades[i].Nome);

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

        if (NumCidades < 2)
        {
            printf("\nPara conseguir batalhar com as cartas, deve-se ter pelo menos duas.\n\n");
        }

        while (strcmp(JogNovam, "Y") == 0 && NumCidades > 2) // Serve para finalizar o código quando a pessoa não quiser mais jogar
        {
            Guer1_PTS = 0;
            Guer2_PTS = 0;

            // Amostragem das cartas criadas

            printf("\n**** Ok! Vamos agora pôr as cidades em batalha! ****\n");

            printf("\nGostaria de ver as cartas completas ou apenas seus nome e código? \n('C' para completa, outro para nome e código) \n");
            scanf(" %1s", VisuCartas);
            ParaMaiuscula(VisuCartas);

            // Verificação se a pessoa quer visualizar apenas o nome, ou as cartas completas.

            if (strcmp(VisuCartas, "C") == 0)
            {
                printf("\nA seguir, estão as cartas criadas:\n");

                for (int i = 0; i < NumCidades; i++)
                {
                    ExibirCarta(cidades[i]);
                }
            }
            else
            {
                printf("\nA seguir, estão as cartas criadas:\n");

                for (int i = 0; i < NumCidades; i++)
                {
                    printf("\nNome da carta: %s\n", cidades[i].Nome);
                    printf("Código da carta: %s\n", cidades[i].Codigo);
                }
            }

            // Seleção das cartas que irão batalhar

            printf("\nDigite, a seguir, os códigos das cartas que deseja que batalhem:\n");
            scanf(" %3s %3s", CodBatalha1, CodBatalha2);

            for (int i = 0; i < NumCidades; i++)
            {
                if (strcmp(CodBatalha1, cidades[i].Codigo) == 0)
                {
                    guerreira1 = cidades[i];
                }
                else if (strcmp(CodBatalha2, cidades[i].Codigo) == 0)
                {
                    guerreira2 = cidades[i];
                }
            }

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

            if (QuantCaracBat == 7)
            {
                /* code */
            }
            else
            {
                int ListCaracBat[QuantCaracBat];

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

                // Preparando os dados para enviar para a função

                printf("\n\n***** A seguir estarão os resultados da batalha de cartas *****\n\n");

                for (int i = 0; i < QuantCaracBat; i++)
                {
                    switch (ListCaracBat[i])
                    {
                    case 1:
                        strcpy(Bat_Carac, "População");
                        Bat_Campo1 = guerreira1.Populacao;
                        Bat_Campo2 = guerreira2.Populacao;
                        strcpy(Bat_Nome1, guerreira1.Nome);
                        strcpy(Bat_Nome2, guerreira2.Nome);
                        MostrarResultadoBatalha(Bat_Carac, Bat_Campo1, Bat_Campo2, Bat_Nome1, Bat_Nome2, &Guer1_PTS, &Guer2_PTS);
                        break;
                    case 2:
                        strcpy(Bat_Carac, "Área");
                        Bat_Campo1 = guerreira1.Area;
                        Bat_Campo2 = guerreira2.Area;
                        strcpy(Bat_Nome1, guerreira1.Nome);
                        strcpy(Bat_Nome2, guerreira2.Nome);
                        MostrarResultadoBatalha(Bat_Carac, Bat_Campo1, Bat_Campo2, Bat_Nome1, Bat_Nome2, &Guer1_PTS, &Guer2_PTS);
                        break;
                    case 3:
                        strcpy(Bat_Carac, "PIB");
                        Bat_Campo1 = guerreira1.PIB;
                        Bat_Campo2 = guerreira2.PIB;
                        strcpy(Bat_Nome1, guerreira1.Nome);
                        strcpy(Bat_Nome2, guerreira2.Nome);
                        MostrarResultadoBatalha(Bat_Carac, Bat_Campo1, Bat_Campo2, Bat_Nome1, Bat_Nome2, &Guer1_PTS, &Guer2_PTS);
                        break;
                    case 4:
                        strcpy(Bat_Carac, "Número De Pontos Turísticos");
                        Bat_Campo1 = guerreira1.NumPonTuristicos;
                        Bat_Campo2 = guerreira2.NumPonTuristicos;
                        strcpy(Bat_Nome1, guerreira1.Nome);
                        strcpy(Bat_Nome2, guerreira2.Nome);
                        MostrarResultadoBatalha(Bat_Carac, Bat_Campo1, Bat_Campo2, Bat_Nome1, Bat_Nome2, &Guer1_PTS, &Guer2_PTS);
                        break;
                    case 5:
                        strcpy(Bat_Carac, "Densidade Populacional");
                        Bat_Campo1 = guerreira2.DensPopulacional; // Densidades populacionais trocadas, pois a densidade vencedora é a menor
                        Bat_Campo2 = guerreira1.DensPopulacional; // Densidades populacionais trocadas, pois a densidade vencedora é a menor
                        strcpy(Bat_Nome1, guerreira1.Nome);
                        strcpy(Bat_Nome2, guerreira2.Nome);
                        MostrarResultadoBatalha(Bat_Carac, Bat_Campo1, Bat_Campo2, Bat_Nome1, Bat_Nome2, &Guer1_PTS, &Guer2_PTS);
                        break;
                    case 6:
                        strcpy(Bat_Carac, "PIB Per Capita");
                        Bat_Campo1 = guerreira1.PIBPerCapita;
                        Bat_Campo2 = guerreira2.PIBPerCapita;
                        strcpy(Bat_Nome1, guerreira1.Nome);
                        strcpy(Bat_Nome2, guerreira2.Nome);
                        MostrarResultadoBatalha(Bat_Carac, Bat_Campo1, Bat_Campo2, Bat_Nome1, Bat_Nome2, &Guer1_PTS, &Guer2_PTS);
                        break;
                    case 7:
                        strcpy(Bat_Carac, "Super Poder");
                        Bat_Campo1 = guerreira1.SuperPoder;
                        Bat_Campo2 = guerreira2.SuperPoder;
                        strcpy(Bat_Nome1, guerreira1.Nome);
                        strcpy(Bat_Nome2, guerreira2.Nome);
                        MostrarResultadoBatalha(Bat_Carac, Bat_Campo1, Bat_Campo2, Bat_Nome1, Bat_Nome2, &Guer1_PTS, &Guer2_PTS);
                        break;

                    default:
                        break;
                    }
                }

                // Amostragem da carta vencedora

                if (Guer1_PTS > Guer2_PTS)
                {
                    printf("\nA Cidade vencedora da competição é a %s, com %d pontos!\n", guerreira1.Codigo, Guer1_PTS);
                    printf("\nTodos os dados da cidade:\n");

                    ExibirCarta(guerreira1);
                }
                else if (Guer2_PTS > Guer1_PTS)
                {
                    printf("\nA Cidade vencedora da competição é a %s, com %d pontos!\n", guerreira2.Codigo, Guer2_PTS);

                    ExibirCarta(guerreira2);
                }
                else
                {
                    printf("\nHouve um empate na competição: A pontuação de ambas as cidades foi igual a %d\n\n", Guer1_PTS);
                }
            }

            printf("\nGostaria de realizar outra batalha dentre as cartas criadas? ('Y' para sim ou 'N' para criar novas cartas ou finalizar o jogo)\n\n");
            scanf(" %1s", JogNovam);
            ParaMaiuscula(JogNovam);

            if (strcmp(JogNovam, "N") == 0)
            {
                printf("\nJogo Finalizado!\n\n");
                break;
            }
        }

        printf("\nGostaria de criar novas cartas? ('Y' para sim ou 'N' para finalizar o jogo)\n\n");
        scanf(" %1s", CriaCarta);
        ParaMaiuscula(CriaCarta);

        if (strcmp(CriaCarta, "N") == 0)
        {
            printf("\nJogo Finalizado!\n\n");
            break;
        }
    }

    return 0;
}