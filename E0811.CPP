/****************************************************************************
			Programa: e0811.cpp
		 Proposito: Mostrar passagem de funcoes para funcoes.
Ultima Revisao: 14/11/2021
****************************************************************************/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>

// ***********
// 1 Principal
// ***********
 main(){

	// ***************
	// 1.1 Declaracoes
	// ***************
	float a = 0.0,b = 5.0;  // limites do intervalo de busca
	float z;                // raiz da funcao f(z)=0
	float f(float);         // prototipos da funcao algebrica transcedente
	float acha_raiz(float,float,float(*)(float)); // prototipo da funcao que
																								// recebe funcao

	// ********************
	// 1.2 Entrada de dados
	// ********************
	
	puts("Calculo do zero de uma funcao transcendente: Metodo da Bisseccao\n");
	puts("Qual e' o valor de x que satisfaz: x - exp(-x) = 0 ?");
	puts("Vamos procurar uma solucao no seguinte intervalo:");
	printf("x é [ %.1f , %.1f ]",a,b);
	puts("\n\nPressione uma tecla...");
	getch();

	// *************************************
	// 1.3 Calculo e impressao de resultados
	// *************************************
	z = acha_raiz(a,b,f);   // chamada de acha_raiz: a funcao 'f' e' argumento!
	printf("\nx: %f (verifique!)\n",z);    // resultado!
	getch();
}

// ********************
// 2 rotina acha_raiz()
// ********************
float acha_raiz(float a,float b,float (*pt)(float)){ // declaracao da funcao...
//                                      �> ponteiro para funcao

	// ***************
	// 2.1 Declaracoes
	// ***************
	float tol = 1.0e-6; // tolerancia do resultado
	float r;            // estimativa de raiz
	float fa,fb,fr;     // valores funcionais f(a), f(b) e f(r)

	// **********************
	// 2.2 Teste de intervalo
	// **********************
	fa = (*pt)(a); // fa = f(a)
	fb = (*pt)(b); // fb = f(b)
	if( fa * fb > 0.0){      // se raiz esta' FORA do intervalo...
		puts("Erro: Funcao nao troca de sinal nos extremos do intervalo!");
		return(0.0);
	}

	// *******************
	// 2.3 Calculo ra raiz
	// *******************
	do{
		r = 0.5 * (a+b);     // bissecciona intervalo
		fr = (*pt)(r);       // fr = f(r)
		if( fa * fr < 0.0){  // se raiz esta' no intervalo da esquerda...
			b = r;             // puxa limite superior
			fb = fr;
		}else{
			a = r;             // empurra limite inferior
			fa = fr;
		}
	}while(b-a > tol);     // enquanto intervalo e' grande
	return(r);             // retorna raiz
}

// ************
// 3 rotina f()
// ************
float f(float x){
	return(exp(-x) - x);
}

//Angelo Abreu Zua