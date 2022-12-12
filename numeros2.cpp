//VAMOS ESCREVER UM PROGRAMA EM C++ PARA MUDANÇAS DE BASE EM DIFERENTES SISTEMAS DE NUMERAÇÃO

/*CABEÇALHO*/
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

//FUNÇÕES DE CONVERSÕES DE NÚMEROS INTEIROS EM BASES BINÁRIAS, OCTAL E HEXADECMAL
//LIMITES APROXIMADOS EM LINUX UBUNTU X86-X64: INT 2^29, LONG INT 2^62

//FUNÇÃO PARA CONVERSÃO EM BASE BINÁRIA
string to_bin(int a){
//VARIÁVEIS
int valor, power2, contador, resto;
char bin_digits[]="01";
string resultado="";

//PROCEDIMENTOS
//INICIALIZANDO AS VARIÁVEIS
power2=1;
valor=a;
contador=0;

//COMPUTANDO NÚMERO DE DIGITOS NA STRING BINÁRIA
while(power2<valor){
contador++;
power2=power2*2;
                   };
//ESCREVENDO A STRING BINÁRIA
power2=power2/2;
do{
// MÓDULO DE TESTE DA FUNÇÃO REMOVA OS /**/ PARA VALIDAR AS LINHAS DE CÓDIGOS OMITIDAS
/* 
cout<<"valor: "<<valor<<"\n";
cout<<"power2: "<<power2<<"\n";
cout<<"contador: "<<contador<<"\n";
*/
if(valor/power2>0){
resultado.push_back(bin_digits[1]);
resto=valor%power2;
//MÓDULO DE TESTE DA FUNÇÃO
/*
cout<<"resto: " <<resto<<"\n";
*/
contador--;
valor=resto;
power2=power2/2;
continue;
                   };

if(valor/power2==0){
resultado.push_back(bin_digits[0]);
contador--;
power2=power2/2;
continue;
                   };
  }while(contador>0);

//CASO BASE
if(a==2)
resultado="10";
return resultado;
};

//FUNÇÃO PARA CONVERSÃO EM BASE 8
string to_oct(int a){
//VARIÁVEIS
int valor, power8, contador, resto;
char oct_digits[]="01234567";
string resultado="";

//PROCEDIMENTOS
//INICIALIZANDO AS VARIÁVEIS
power8=1;
valor=a;
contador=0;

//CASO BASE
if(a<8)
return(to_string(a));

//COMPUTANDO NÚMERO DE DIGITOS NA STRING OCTAL
while(power8<valor){
contador++;
power8=power8*8;
                   };
//ESCREVENDO A STRING OCTAL
power8=power8/8;
do{

if(valor/power8>0){
resultado.push_back(oct_digits[valor/power8]);
resto=valor%power8;
contador--;
valor=resto;
power8=power8/8;
continue;
                   };

if(valor/power8==0){
resultado.push_back(oct_digits[0]);
contador--;
power8=power8/8;
continue;
                   };
  }while(contador>0);
//CASO BASE
if(a==8)
resultado="10";
return resultado;
};

//FUNÇÃO PARA CONVERSÃO EM BASE HEXADECIMAL
string to_hex(int a){
//VARIÁVEIS
int valor, power16, contador, resto;
char hex_digits[]="0123456789abcdef";
string resultado="";

//PROCEDIMENTOS
//INICIALIZANDO AS VARIÁVEIS
power16=1;
valor=a;
contador=0;

//COMPUTANDO NÚMERO DE DIGITOS NA STRING HEXADECIMAL
while(power16<valor){
contador++;
power16=power16*16;
                   };
//ESCREVENDO A STRING HEXADECIMAL
power16=power16/16;
do{

if(valor/power16>0){
resultado.push_back(hex_digits[valor/power16]);
resto=valor%power16;
contador--;
valor=resto;
power16=power16/16;
continue;
                   };

if(valor/power16==0){
resultado.push_back(hex_digits[0]);
contador--;
power16=power16/16;
continue;
                   };
  }while(contador>0);

//CASO BASE
if(a==16)
resultado="10";
return resultado;
};

//FUNÇÃO PRINCIPAL DO PROGRAMA
int main(){
int numero;
string bin, oct, hex;
//ENTRADA DE DADOS
cout<<"Digite um número inteiro:\n";
cin>>numero;

//CONVERSÃO PARA OUTRAS BASES DE NUMERAÇÃO
bin=to_bin(numero);
oct=to_oct(numero);
hex=to_hex(numero);
cout<<"A representação binária de "<< numero <<" é "<<bin<<".\n";
cout<<"A representação octal de "<< numero <<" é "<<oct<<".\n";
cout<<"A representação hexadecimal de "<< numero <<" é "<<hex<<".\n";
//FIM DA FUNÇÃO PRINCIPAL
return 0;
}
