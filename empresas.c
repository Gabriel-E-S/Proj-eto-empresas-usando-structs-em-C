#include <stdio.h>
#include <locale.h>
#include <windows.h>

#define tam 3
//criação dos novos tipos
void printgreenText(const char* text) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("%s", text);
    SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

struct reg_filial{
    int codigo;
    char descricao[20];
    char modelo[20];
    char marca[20];
    int inicio,fim;
    float preco;
    int qtd;
};
typedef struct reg_filial reg_filial;



struct reg_matriz{
    int codigo;
    int qtd_vendida;
    float valor_total;
    };
typedef struct reg_matriz reg_matriz;

//criação de variaveis globais

reg_filial f1[tam] ={
            {1,"Motor","Kombi","Volks",1900,2005,100,10},
            {2,"suco de laranja","Celta","Chevrolet",2000,2010,100,10},
            {3,"Suco de maracuja","Civic","Honda",1999,2012,150,115}
};



reg_filial f2[tam] = {
        {1,"Motor","Kombi","Volks",1900,2005,100,10},
        {4,"Caixa de câmbio","Lancer EVO","Mitsubishi",1980,2023,100,100},
        {5,"Espelho dianteiro","Uno","Fiat",1999,2020,100,10}
};
reg_matriz matriz[2*tam];
int tamvetmat = 0,tamf1 = tam,tamf2 = tam;
int i,j;



//funções

void imprimirfiliais(){
    printgreenText("RESULTADOS: FILIAL 1\n\n");

    for(i=0;i<tamf1;i++ ){
        printf("\tDESCRIÇÃO: %s\n",f1[i].descricao);
        printf("\tCÓDIGO: %d\n",f1[i].codigo);
        printf("\tMODELO: %s\n",f1[i].modelo);
        printf("\tMARCA: %s\n",f1[i].marca);
        printf("\tANO INICIO: %d ANO FINAL: %d\n",f1[i].inicio,f1[i].fim);
        printf("\tPREÇO: %.2f \n",f1[i].preco);
        printf("\tQUANTIDADE: %d \n",f1[i].qtd);
        printf("\t----------------------------------\n");
    }
    printgreenText("\n\nRESULTADOS: FILIAL 2\n\n");

    for(i=0;i<tamf2;i++ ){
        printf("\n\nDESCRIÇÃO: %s\n",f2[i].descricao);
        printf("CÓDIGO: %d\n",f2[i].codigo);
        printf("MODELO: %s\n",f2[i].modelo);
        printf("MARCA: %s\n",f2[i].marca);
        printf("ANO INICIO: %d ANO FINAL: %d\n",f2[i].inicio,f2[i].fim);
        printf("PREÇO: %.2f \n",f2[i].preco);
        printf("QUANTIDADE: %d \n",f2[i].qtd);
         printf("\n----------------------------------\n");
}
}

void imprimirmatriz(){
    printgreenText("\n\nVETOR DA MATRIZ\n\n");
    printf("CÓDIGO\tQUANTIDADE VENDIDA\tVALOR TOTAL\n\n");

    for(i=0;i<tamvetmat;i++){
            printf("  %d\t\t%d\t\t  %.2f\n",matriz[i].codigo,matriz[i].qtd_vendida,matriz[i].valor_total);


    }

}



void criando_vet_da_matriz(){
    for(i=0;i<tamf1;i++){
        matriz[tamvetmat].codigo = f1[i].codigo;
        matriz[tamvetmat].qtd_vendida = f1[i].qtd;
        matriz[tamvetmat].valor_total = f1[i].preco * f1[i].qtd;
        tamvetmat = tamvetmat+1;

    }
}

void verificar_existencia(){


    for(i=0;i<tamf2;i++){

        int pecaexiste = 0;

        for(j=0;j<tamvetmat;j++){
                if(matriz[j].codigo == f2[i].codigo){
                        matriz[j].qtd_vendida += f2[i].qtd;
                        matriz[j].valor_total +=  f2[i].preco * f2[i].qtd;
                        pecaexiste = 1;
                        break;
                }
        }
        if(!pecaexiste){
                matriz[tamvetmat].codigo = f2[i].codigo;
                matriz[tamvetmat].qtd_vendida = f2[i].qtd;
                matriz[tamvetmat].valor_total = f2[i].preco * f2[i].qtd;
                tamvetmat = tamvetmat+1;
        }

    }
}
int maiorvenda(){
    int maior = matriz[0].qtd_vendida;
    int ondeemaior = 0;

    for(i=1;i<tamvetmat;i++){
        if(matriz[i].qtd_vendida > maior){
            maior = matriz[i].qtd_vendida;
            ondeemaior = i;
        }
    }
    printf("\nA MAIOR VENDA FOI DA PEÇA COM CÓDIGO: %d",matriz[ondeemaior].codigo);

    return matriz[ondeemaior].codigo;

}

void acharpecamaisvendida(int codigo){
    int achou = 0;

    for(i=0;i<tamf1;i++){
        if(codigo == f1[i].codigo){
            printf("\nPEÇA MAIS VENDIDA: %s\n",f1[i].descricao);
            printf("MODELO DE CARRO: %s\n",f1[i].modelo);
            achou = 1;
        }
    }
       if(!achou){

        for(i=0;i<tamf2;i++){
        if(codigo == f2[i].codigo){
            printf("\nPEÇA MAIS VENDIDA: %s\n",f2[i].descricao);
            printf("MODELO DE CARRO: %s\n",f2[i].modelo);
            achou = 1;

            }
        }
       }


}

int main(){

    setlocale(LC_ALL,"");
    int y;

    imprimirfiliais();
    criando_vet_da_matriz();
    verificar_existencia();
    imprimirmatriz();
    y = maiorvenda();
    acharpecamaisvendida(y);


return 0 ;
}
