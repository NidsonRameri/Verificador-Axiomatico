// Verificador de prova para o método axiomático.
// EQUIPE:
// - CLARA LIMA FONSECA                422007
// - ELYNEKER LUCIANI FREIRE DA SILVA  408276
// - NIDSON RAMERI GOMES NOGUEIRA      428565

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "axiomas.c"

FILE *arquivo;
bool correto = true, existeFalha=false; // mensagem se entrada está correta.
char pS[20], qS[20], rS[20]; //Valores SUBS pegos no arquivo separados
char formula[99],axioma[99],subs[99]; // Valores no arquivo
int  linha, linhaAtual=1, countGuardarFormulas=0;
char *arrayFormulas[50];


FILE* abrirArquivo(char caminho[20], char modo)
{
    FILE *arquivo;
    switch (modo)
    {
    case 'w':
        arquivo = fopen(caminho, "w");
        break;
    case 'r':
        arquivo = fopen(caminho, "r");
        break;
    case 'a':
        arquivo = fopen(caminho, "a");
        break;
    }

    if (arquivo == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
        system("pause");
        exit(1);
    }
}

fecharArquivo(FILE *arquivo)
{
    fclose(arquivo);
}

bool conferirLinha(int linhaRecebida){
    if (linhaAtual == linhaRecebida){
        return true;
    }
    correto=false;
    return false;
}

bool mp(int linha1, int linha2, char teste[]) {
    if(linha1 >= linhaAtual || linha2 >= linhaAtual){
        existeFalha=true;
        printf("\n ...Resolucao incorreta! ");
        printf("==> MODOS PONENS com linha futura NAO e permitido...\n");
        printf("\n=-=-=-=- VERIFIQUE SUA RESOLUCAO! -=-=-=-=\nFim!\n");
        system("pause");
        exit(1);
    }
        
    char comparar[99], primeiraFormula[99], segundaFormula[99], comparaTemp[99];
    int tamFormula, c, saoIguais;

    strcpy(primeiraFormula, arrayFormulas[linha1-1]);     // BUSCANDO FORMULAS DO VETOR GERAL
    strcpy(segundaFormula, arrayFormulas[linha2-1]);

    sleep(1);
    if(strlen(primeiraFormula) < strlen(segundaFormula)){
        int tamPrimeira = strlen(primeiraFormula);
        int tamSegunda = strlen(segundaFormula);

        for(c = 1; c < tamSegunda-1; c++){             //tirando parenteses externos da segunda form
            comparaTemp[c - 1 ] = segundaFormula[c];
        }
        comparaTemp[c] = '\0';

        saoIguais = strncmp(primeiraFormula, comparaTemp, tamPrimeira);   //comparar 1ª com 2ª até o tamanho da 1ª formula
        
        if(saoIguais == 0){    // 0 se forem iguais -> subtrair da formula maior
            int countZero = 0;
            for(c = tamPrimeira+2; c < tamSegunda -1 ; c++){                    //pegar o 'resto'
                comparaTemp[countZero] = segundaFormula[c];
                countZero++;
            }
            comparaTemp[countZero] = '\0';    // resultado da formula para comparar com form do arquivo

            saoIguais = strcmp(teste, comparaTemp);
            if(saoIguais == 0){
                printf("\n ...MODOS PONENS executado CORRETAMENTE!\n");
                return true;
            }
            else{
                printf("\nHa algo errado nesse MODO PONENS...\n");
                existeFalha = true;
                return false;
            }
        }
        else{                                       // se começo das formulas forem diferentes
            printf("\nHa algo errado nesse MODO PONENS...\n");
            existeFalha = true;
            return false;
        }
    }
    else{
        int tamP = strlen(primeiraFormula);
        int tamS = strlen(segundaFormula);
        
        for(c = 1; c < tamP-1; c++){                //tirando parenteses externos
            comparaTemp[c - 1 ] = primeiraFormula[c];
        }
        comparaTemp[c] = '\0';

        saoIguais = strncmp(segundaFormula, comparaTemp, tamS);
        
        if(saoIguais == 0){
            int countZero = 0;
            for(c = tamS+2; c < tamP -1 ; c++){
                comparaTemp[countZero] = primeiraFormula[c];
                countZero++;
            }
            comparaTemp[countZero] = '\0';

            saoIguais = strcmp(teste, comparaTemp);
            if(saoIguais == 0){
                printf("\n ...MODOS PONENS executado CORRETAMENTE!\n");
                return true;
            }
            else{
                printf("\nHa algo errado nesse MODO PONENS...\n");
                existeFalha = true;
                return false;
            }
        }else{
            printf("\nHa algo errado nesse MODO PONENS...\n");
            existeFalha = true;
            return false;
        }
    }
}

void main(){
    system("cls");

    // LER ARQUIVO DE ENTRADA COM RESOLUÇÃO
    arquivo = abrirArquivo("entrada.txt",'r');
    
    while(!feof(arquivo)){
        fscanf(arquivo, "%d %s %s %s\n", &linha, &formula, &axioma, &subs);

        printf(" **** Analisando: %d %s %s", linha, formula, axioma);
        
        if(strlen(subs)>1)
            printf(" %s", subs);
        
    /*********************************************************************************/
    //=> CONFERIR LINHA
    /*********************************************************************************/
        bool linhaCorreta;
        linhaCorreta = conferirLinha(linha);    //conferir linha com a função
        if(!linhaCorreta){
            printf("\nA contagem da sua resolucao esta INCORRETA...");
            printf(" Agora seria a linha %d e nao a linha %d", linhaAtual, linha);
            existeFalha = true;                                 //erro na entrada
        }

    
        int tamanhoSubs = strlen(subs);
        int i=2, j=0, k=0;

        /*********************************************************************************/
        //=> COMPARAR COM QUAL AXIOMA? OU MP?
        /*********************************************************************************/
        char nAx[1];                  //num axioma String
        int numeroAxioma;             //num axioma int
        int mP1=0, mP2=0, l=0;

        if(axioma[0] == 'A'){
            for(i = 1; axioma[i] != '\0'; i++){
                nAx[i-1] = axioma[i];
            }
            nAx[i] = '\0';
            numeroAxioma = atoi(nAx); // transformando String -> Inteiro

            /*********************************************************************************/
            //=> SUBS
            /*********************************************************************************/
                //PEGAR P
            if(tamanhoSubs <= 1){
                printf("\nFaltando informacoes dos valores a serem substituidos!\n");
                printf("\n=-=-=-=- VERIFIQUE SUA RESOLUCAO! -=-=-=-=\nFim!\n");
                system("pause");
                exit(1);
            }else{
                for(i = 2; subs[i] != ';' && subs[i] != '\0'; i++){
                    pS[i - 2] = subs[i]; //pS[0] =  p
                }
                pS[i-2] = '\0'; //p[1] = p,\0, 
                
                //PEGAR Q
                if (tamanhoSubs > i){
                    i = i+3;
                    for(i; subs[i] != ';' && subs[i] != '\0'; i++){
                        qS[j] = subs[i];  // qS[q]
                        j++;
                    }
                    qS[j] = '\0';
                }else{
                    qS[0] = '\0';
                }   

                //PEGAR R
                if (tamanhoSubs > i){
                    i = i+3;
                    for(i; subs[i] != ';' && subs[i] != '\0'; i++){
                        rS[k] = subs[i];
                        k++;
                    }
                    rS[k] = '\0';
                }else{
                    rS[0] = '\0';
                }
            }

        }else{
            numeroAxioma = 11;
            //Modos Ponens 1º
            for(i = 0; subs[i] != ',' && subs[i] != '\0'; i++){
                nAx[i] = subs[i];
            }
            mP1 = atoi(nAx);

            //Modos Ponens 2º
            i++;
            for(i; subs[i] != ',' && subs[i] != '\0'; i++){
                nAx[l] = subs[i];
                l++;
            }
            nAx[l] = '\0';
            mP2 = atoi(nAx);
        }

        switch (numeroAxioma)
        {
            case 1:
                correto = axioma1(pS, qS, formula);
            break;
            case 2:
                correto = axioma2(pS, qS, rS,formula);
            break;
            case 3:
                correto = axioma3(pS, qS, formula);
            break;
            case 4:
                correto = axioma4(pS, qS, formula);
            break;
            case 5:
                correto = axioma5(pS, qS, formula);
            break;
            case 6:
                correto = axioma6(pS, qS, formula);
            break;
            case 7:
                correto = axioma7(pS, qS, formula);
            break;
            case 8:
                correto = axioma8(pS, qS, rS, formula);
            break;
            case 9:
                correto = axioma9(pS, qS, formula);
            break;
            case 10:
                correto = axioma10(pS, formula);
            break;
            default:
                correto = mp(mP1, mP2, formula);
        }

        if(correto == 0) existeFalha = true;    // 0 = erro

        //Guardando formulas:
        for(countGuardarFormulas; countGuardarFormulas < linhaAtual; countGuardarFormulas++){
            arrayFormulas[countGuardarFormulas] = malloc(sizeof(char) * 60);
            if(correto == 1){
                strcpy(arrayFormulas[countGuardarFormulas], formula);
            }
            else{
                strcpy(arrayFormulas[countGuardarFormulas], "houve erro");
            }
        }
        linhaAtual++;
        
    }
    fecharArquivo(arquivo);
    
    if(!existeFalha)
        printf("\n=-=-=-=- CORRETO! -=-=-=-=\nFim!\n");
    else
        printf("\n=-=-=-=- VERIFIQUE SUA RESOLUCAO! -=-=-=-=\nFim!\n");

    system("pause");
}