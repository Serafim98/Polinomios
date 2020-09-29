#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>

//Luis Fernando da Silva Serafim e Bruna Bravin Bueno

void Imprime (int n, float *P){                    //Imprime os elementos do Array
	int i;
		for(i=n; i>=0; i--){
			if (i!=0)
			printf("%.2f.X^%d + ", P[i], i);
			else
			printf("%.2f.X^%d ", P[i], i);
		}
		printf("\n");
		return;
	}

int MAX(int a, int b){              //Encontra o maior(no caso foi usado para encontrar o maior Grau)
	if(a>b) return(a);
	else return(b);
}

void Soma(float *P1, int g1, float *P2, int g2){    //Soma os Polinômios selecionados
	int i, j, n= MAX(g1, g2);
	float S[n];
	for(i=0; i<=g1; i++){
		for(j=i; j<=g2; j++){
			S[j]= P1[j]+P2[j];
			break;
		}
		if(j>g2)
		S[i] = P1[i];
	}
	if((i>g1)&&(j<g2)){
		for(; j<=g2; j++){
		S[j]= P2[j];
		}
	}
	system("cls");
	Imprime(n, S);
	return;
}

void Mult(float *P1, int g1, float *P2, int g2){   //Multiplica os Polinômios selecionados
	int i, j, g=g1*g2+1;
	float M[g];
	int Po[g];

	for(i=0; i<=g; i++){
		M[i]=0;
	}

    for(i=0; i<=g1; i++){
        for(j=0; j<=g2; j++){
            M[i+j] = M[i+j] + P1[i] * P2[j];
            Po[i+j]= i+j;
            }
        }
    system("cls");
    for(i=0; i<g;i++){
        if(i==g-1)
        printf(" %.2fX^%d ", M[i], Po[i]);
        else printf(" %.2fX^%d +", M[i], Po[i]);
    }
}

void Xespec(float *P, int g, int x){       //Calcula o Polinômio usando um X específico
    int i;
    float soma=0;
    for(i=0; i<=g; i++){
        soma += pow(*(P+i)*x, i);
    }
    printf("Resultado da soma dos coeficientes aplicado no valor %d: %f", x, soma);
    return;
}

void MultK(float *P, int g, int k){      //Multiplica cada elemento por uma Constante
    int i;
    for(i=0; i<=g; i++)
        P[i]= P[i]*k;
    Imprime(g, P);
    return;
}

void Associa (int n, float *P){          //Associa elementos as posições do Array
	int i, j;
	float E;

	for(i=0; i<=n; i++){
		printf("Insira o elemento de grau %d: ", i);
		scanf("%f", &E);
		*(P+i) = E;
	}
	return;
}

void PossibilidadesSoma(int es1, int es2, float *P, float *Q, float *R, int g1, int g2, int g3){
	switch(es1){
		case 1: switch(es2){
				case 1: Soma(P, g1, P, g1);break;    //Mostra todas as Possibilidades para Soma
				case 2: Soma(P, g1, Q, g2);break;
				case 3: Soma(P, g1, R, g3);break;
			break;
		}
		case 2: switch(es2){
				case 1: Soma(Q, g2, P, g1);break;
				case 2: Soma(Q, g2, Q, g2);break;
				case 3: Soma(Q, g2, R, g3);break;
			break;
		}
		case 3: switch(es2){
				case 1: Soma(R, g3, P, g1);break;
				case 2: Soma(R, g3, Q, g2);break;
				case 3: Soma(R, g3, R, g3);break;
			break;
		}
	}
}

void PossibilidadesMult(int es1, int es2, float *P, float *Q, float *R, int g1, int g2, int g3){
	switch(es1){
		case 1: switch(es2){
				case 1: Mult(P, g1, P, g1);break;      //Mostra todas as Possibilidades para Multiplicação
				case 2: Mult(P, g1, Q, g2);break;
				case 3: Mult(P, g1, R, g3);break;
		}
		break;
		case 2: switch(es2){
				case 1: Mult(Q, g2, P, g1);break;
				case 2: Mult(Q, g2, Q, g2);break;
				case 3: Mult(Q, g2, R, g3);break;
		}
		break;
		case 3: switch(es2){
				case 1: Mult(R, g3, P, g1);break;
				case 2: Mult(R, g3, Q, g2);break;
				case 3: Mult(R, g3, R, g3);break;
		}
		 break;
	}
}

void PossibilidadesXespec(int es1, float *P, float *Q, float *R, int g1, int g2, int g3){
    float x;
    printf("Digite um valor x específico a ser calculado");   //Escolhe o Polinômio a ser calculado com o X específico
    scanf("%f", &x);
	switch(es1){
        case 1: Xespec(P, g1, x);break;
        case 2: Xespec(Q, g2, x);break;
        case 3: Xespec(R, g3, x);break;
	}
	return;
}

void PossibilidadesMultK(int es1, float *P, float *Q, float *R, int g1, int g2, int g3){
    float x;
    printf("Digite um valor x específico a ser multiplicado pelo polinômio");
    scanf("%f", &x);
	switch(es1){
        case 1: MultK(P, g1, x);break;       //Escolhe a Constante 
        case 2: MultK(Q, g2, x);break;
        case 3: MultK(R, g3, x);break;
	}
	return;
}



void EscolhePol(int *es1, int *es2){     //Esoclher Polinômio a ser Utilizado
	printf("Com quais polinômios deseja realizar esta operação?");
	scanf("%d", es1);
	switch(*es1){
		case 1: scanf("%d", es2);
				break;
		case 2: scanf("%d", es2);
				break;
		case 3: scanf("%d", es2);
				break;
	}
	return;
}

int EscolhaOperacao(int ch){                              //Escolhe a Operação a ser realizada
	printf("Qual operação deseja realizar com os polinômios?\n");
	printf("1: Soma\n");
	printf("2: Multiplicação\n");
	printf("3: Calcular o valor do polinômio num valor x\n");
	printf("4: Multiplicar um polinômio por uma constante\n");
	scanf("%d", &ch);
	return(ch);
}

void InsereElPo(float *P, float *Q, float *R, int g1, int g2, int g3){
	 
	if((g1>0)&&(g1<=30)){
	printf("Insira os elementos do 1º Polinômio\n");      //insere os elementos do 1º Polinômio
	Associa(g1, P);
	Imprime(g1, P);
	}

	if((g2>0)&&(g2<=30)){
	printf("Insira os elementos do 2º Polinômio\n");      //insere os elementos do 2º Polinômio
	Associa(g2, Q);
	Imprime(g2, Q);
	}

	if((g2>0)&&(g2<=30)){
	printf("Insira os elementos do 3º Polinômio\n");     //insere os elementos do 3º Polinômio
	Associa(g3, R);
	Imprime(g3, R);
	}
	return;
}

void EscolheGrau1(int *g1){
	printf("\nInsira o grau do 1º polinômio ");        //Escolhe o grau do 1º Polinômio 
	scanf("%d", g1);
	if((*g1<1)||(*g1>30)){
		printf("\nValor fora do intervalo");
		EscolheGrau1(g1);
	}
	return;
}

void EscolheGrau2(int *g2){
	printf("\nInsira o grau do 2º polinômio ");        //Escolhe o grau do 2º Polinômio 
	scanf("%d", g2);
	if((*g2<1)||(*g2>30)){
		printf("\nValor fora do intervalo");
		EscolheGrau2(g2);
	}
	return;
}

void EscolheGrau3(int *g3){
	printf("\nInsira o grau do 3º polinômio ");        //Escolhe o grau do 3º Polinômio 
	scanf("%d", g3);
	if((*g3<1)||(*g3>30)){
		printf("\nValor fora do intervalo");
		EscolheGrau3(g3);
	}
	return;
}

void EscolheGrau(int *g1, int *g2, int *g3){      //Escolhe o Grau(variando de 1 a 30)
	printf("\nInsira o grau variando de 1 a 30");
	EscolheGrau1(g1);
	EscolheGrau2(g2);
	EscolheGrau3(g3);
	return;
}


int main(void){
	setlocale(LC_ALL, "Portuguese");
	int g1, g2, g3, ch, es1, es2;
	EscolheGrau(&g1, &g2, &g3);
	float P[g1], Q[g2], R[g3];
	InsereElPo(P, Q, R, g1, g2, g3);
	ch=EscolhaOperacao(ch);
	if((ch!=3)&&(ch!=4))
	EscolhePol(&es1, &es2);
	switch(ch){
		case 1: PossibilidadesSoma(es1, es2, P, Q, R, g1, g2, g3);
				break;
		case 2: PossibilidadesMult(es1, es2, P, Q, R, g1, g2, g3);
				break;
        case 3: printf("Insira o polinômio que deseja fazer a operação: ");
                scanf("%d", &es1);
                PossibilidadesXespec(es1, P, Q, R, g1, g2, g3);
        case 4: printf("Insira o polinômio que deseja fazer a operação: ");
                scanf("%d", &es1);
                PossibilidadesMultK(es1, P, Q, R, g1, g2, g3);
    }
}
