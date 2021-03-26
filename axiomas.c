// Axiomas
// EQUIPE:
// - CLARA LIMA FONSECA                422007
// - ELYNEKER LUCIANI FREIRE DA SILVA  408276
// - NIDSON RAMERI GOMES NOGUEIRA      428565

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*********************************************************************************/
//=> AXIOMASSSS
/*********************************************************************************/
bool verificarP (char p[]){
    if(p[0] == '\0'){
        printf("\n==> Falta informacao de \"P\" para concluir a verificacao...\n");
        return false;
    }
    return true;
}
bool verificarPQ (char p[], char q[]){
    if(p[0] == '\0' || q[0] == '\0'){
        printf("\n==> Falta informacao de \"P\" ou \"Q\" para concluir a verificacao...\n");
        return false;
    }
    return true;
}
bool verificarPQR (char p[], char q[], char r[]){
    if(p[0] == '\0' || q[0] == '\0' || r[0] == '\0'){
        printf("\n==> Falta informacao de \"P\", \"Q\" ou \"R\" para concluir a verificacao...\n");
        return false;
    }
    return true;
}

bool axioma1(char p[], char q[], char teste[]){ // (p>(q>p))
    if(!verificarPQ(p, q))
        return false;
         
    char   axioma[49];
    int confere;

    strcpy(axioma, "(");
    strcat(axioma, p);
    strcat(axioma, ">(");
    strcat(axioma, q);
    strcat(axioma, ">");
    strcat(axioma, p);
    strcat(axioma, "))");

    confere = strcmp(axioma, teste);
    sleep(1);
    if (confere == 0){
        printf("\n ...Substituicao CORRETA!\n");
        return true;
    }
    else{
        printf("\n ...Substituicao INCORRETA!\n==> Forma correta de acordo com as substituicoes: %s\n", axioma);
        return false;
    }
        
}

bool axioma2(char p[], char q[], char r[], char teste[]){// ((p>(q>r))>((p>q)>(p>r)))
    if(!verificarPQR(p, q, r))
        return false;    
    
    char   axioma[49];
    int confere;
    
    strcpy(axioma, "((");
    strcat(axioma, p);
    strcat(axioma, ">(");
    strcat(axioma, q);
    strcat(axioma, ">");
    strcat(axioma, r);
    strcat(axioma, "))>((");
    strcat(axioma, p);
    strcat(axioma, ">");
    strcat(axioma, q);
    strcat(axioma, ")>(");
    strcat(axioma, p);
    strcat(axioma, ">");
    strcat(axioma, r);
    strcat(axioma, ")))");

    confere = strcmp(axioma, teste);
    sleep(1);
    if (confere == 0){
        printf("\n ...Substituicao CORRETA!\n");
        return true;
    }
    else{
        printf("\n ...Substituicao INCORRETA!\n==> Forma correta de acordo com as substituicoes: %s\n", axioma);
        return false;
    }
}

bool axioma3(char p[], char q[], char teste[]){ // (p>(q>(p&q)))
    if(!verificarPQ(p, q))
        return false;
    
    char   axioma[49];
    int confere;

    strcpy(axioma, "(");
    strcat(axioma, p);
    strcat(axioma, ">(");
    strcat(axioma, q);
    strcat(axioma, ">(");
    strcat(axioma, p);
    strcat(axioma, "&");
    strcat(axioma, q);
    strcat(axioma, ")))");

    confere = strcmp(axioma, teste);
    sleep(1);
    if (confere == 0){
        printf("\n ...Substituicao CORRETA!\n");
        return true;
    }
    else{
        printf("\n ...Substituicao INCORRETA!\n==> Forma correta de acordo com as substituicoes: %s\n", axioma);
        return false;
    }
}

bool axioma4(char p[], char q[], char teste[]){ // ((p&q)>p)
    if(!verificarPQ(p, q))
        return false;
    
    char   axioma[49];
    int confere;

    strcpy(axioma, "((");
    strcat(axioma, p);
    strcat(axioma, "&");
    strcat(axioma, q);
    strcat(axioma, ")>");
    strcat(axioma, p);
    strcat(axioma, ")");
    
    confere = strcmp(axioma, teste);
    sleep(1);
    if (confere == 0){
        printf("\n ...Substituicao CORRETA!\n");
        return true;
    }
    else{
        printf("\n ...Substituicao INCORRETA!\n==> Forma correta de acordo com as substituicoes: %s\n", axioma);
        return false;
    }
}

bool axioma5(char p[], char q[], char teste[]){ // ((p&q)>q)
    if(!verificarPQ(p, q))
        return false;
    
    char axioma[49];
    int  confere;

    strcpy(axioma, "((");
    strcat(axioma, p);
    strcat(axioma, "&");
    strcat(axioma, q);
    strcat(axioma, ")>");
    strcat(axioma, q);
    strcat(axioma, ")");
    
    confere = strcmp(axioma, teste);
    sleep(1);
    if (confere == 0){
        printf("\n ...Substituicao CORRETA!\n");
        return true;
    }
    else{
        printf("\n ...Substituicao INCORRETA!\n==> Forma correta de acordo com as substituicoes: %s\n", axioma);
        return false;
    }
}

bool axioma6(char p[], char q[], char teste[]){ // (p>(pvq))
    if(!verificarPQ(p, q))
        return false;
    
    char axioma[49];
    int  confere;

    strcat(axioma, "(");
    strcat(axioma, p);    
    strcat(axioma, ">(");
    strcat(axioma, p);   
    strcat(axioma, "v");
    strcat(axioma, q);
    strcat(axioma, "))");  
    
    confere = strcmp(axioma, teste);
    sleep(1);
    if (confere == 0){
        printf("\n ...Substituicao CORRETA!\n");
        return true;
    }
    else{
        printf("\n ...Substituicao INCORRETA!\n==> Forma correta de acordo com as substituicoes: %s\n", axioma);
        return false;
    }
}

bool axioma7(char p[], char q[], char teste[]){ // (q>(pvq))
    if(!verificarPQ(p, q))
        return false;
    
    char   axioma[49];
    int confere;

    strcat(axioma, "(");
    strcat(axioma, q);    
    strcat(axioma, ">(");
    strcat(axioma, p);   
    strcat(axioma, "v");
    strcat(axioma, q);
    strcat(axioma, "))");

    confere = strcmp(axioma, teste);
    sleep(1);
    if (confere == 0){
        printf("\n ...Substituicao CORRETA!\n");
        return true;
    }
    else{
        printf("\n ...Substituicao INCORRETA!\n==> Forma correta de acordo com as substituicoes: %s\n", axioma);
        return false;
    }
}

bool axioma8(char p[], char q[], char r[], char teste[]){// ((p>r)>((q>r)>(pVq)>r))
    if(!verificarPQR(p, q, r))
        return false;
    
    char   axioma[49];
    int confere;

    strcpy(axioma, "((");
    strcat(axioma, p);
    strcat(axioma, ">");
    strcat(axioma, r);
    strcat(axioma, ")>((");
    strcat(axioma, q);
    strcat(axioma, ">");
    strcat(axioma, r);
    strcat(axioma, ")>(");
    strcat(axioma, p);
    strcat(axioma, "v");
    strcat(axioma, q);
    strcat(axioma, ")>");
    strcat(axioma, r);
    strcat(axioma, "))");
    
    confere = strcmp(axioma, teste);
    sleep(1);
    if (confere == 0){
        printf("\n ...Substituicao CORRETA!\n");
        return true;
    }
    else{
        printf("\n ...Substituicao INCORRETA!\n==> Forma correta de acordo com as substituicoes: %s\n", axioma);
        return false;
    }
}

bool axioma9(char p[], char q[], char teste[]){ // ((p>q)>((p>¬q)>¬p))
    if(!verificarPQ(p, q))
        return false;
    
    char   axioma[49];
    int confere;

    strcpy(axioma, "((");
    strcat(axioma, p);
    strcat(axioma, ">");
    strcat(axioma, q);
    strcat(axioma, ")>((");
    strcat(axioma, p);
    strcat(axioma, ">¬");
    strcat(axioma, q);
    strcat(axioma, ")>¬");
    strcat(axioma, p);
    strcat(axioma, "))");

    confere = strcmp(axioma, teste);
    sleep(1);
    if (confere == 0){
        printf("\n ...Substituicao CORRETA!\n");
        return true;
    }
    else{
        printf("\n ...Substituicao INCORRETA!\n==> Forma correta de acordo com as substituicoes: %s\n", axioma);
        return false;
    }
}

bool axioma10(char p[], char teste[]){ // (¬¬p>p)
    if(!verificarP(p))
        return false;
    
    char   axioma[49];
    int confere;

    strcpy(axioma, "(¬¬");
    strcat(axioma, p);
    strcat(axioma, ">");
    strcat(axioma, p);
    strcat(axioma, ")");

    
    confere = strcmp(axioma, teste);
    sleep(1);
    if (confere == 0){
        printf("\n ...Substituicao CORRETA!\n");
        return true;
    }
    else{
        printf("\n ...Substituicao INCORRETA!\n==> Forma correta de acordo com as substituicoes: %s\n", axioma);
        return false;
    }
}