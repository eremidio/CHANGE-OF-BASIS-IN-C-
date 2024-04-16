//VAMOS CRIAR UM PROGRAMA EM C++ QUE EXPRESSA NÚMEROS INTEIROS EM DIFERENTES BASES NUMÉRICAS
//COMPILAR  ESTE PROGRAMA COM O COMANDO: g++ -o numeric_base_change numeric_base_change.cpp



//*******************************************************************************************************************************************************************
//CABEÇALHO
#include<iostream>
#include<stdint.h>
#include<cmath>
#include<string>
#include<cassert>
using namespace std;

//Constantes globais
const char number_digits[37]="0123456789abcdefghijklmnopqrstuvwxyz";

//*******************************************************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
void from_dec(uint64_t, int);
int find_index(char, int);
void to_dec(string, int);


//*******************************************************************************************************************************************************************
//FUNÇÕES AUXILIARES

//Função que expressa um número em notação decimal em uma base qualquer
void from_dec(uint64_t number, int base){

 //Restrição: usaremos apenas caractéres alfa-numéricos
 assert(base<=36 && base>1);

 //Variáveis locais
 string number_string="";
 uint64_t N=number;
 uint64_t value, digit_index;
 int digit_number=(log(number)/log(base))+1; //Logaritmo de 'b' na base 'a' é  ln(b)/ln(a) ln() denota o logaritmo natural a função log() em C/C++
 int exponent;


 //Procedimento
 //Loop principal: cálculo dos dígitos do número na base escolhida
 for(exponent=(digit_number-1); exponent>=0; exponent--){

  value=pow(base, exponent);
  digit_index=floor(number/value);
  number_string+=number_digits[digit_index];
  number=(number%value);

                                                        };


 //Exbindoo resultado da execução do algoritmo
 cout<<N<< " escrito na base "<< base<< " é "<<number_string<< '\n';

                                        };


//Função que calcula oindex de um caractére na string de digitos númericos
int find_index(char c, int base){

 //Variáveis locais
 int index=0;

 //Loop principal
 for(auto character:number_digits){

  if(c==character)
   break;
  else
   index++;
                                  };

 //Restrição
 if(index>base)
  cout<<"A representação contém um caractére inválido.\n";
 assert(index<base);

 //Resultado
 return index;
                                };


//Função que converte um número de uma base qualquer para a sua representação decimal
void to_dec(string number_string, int base){


 //Restrição: usaremos apenas caractéres alfa-numéricos
 assert(base<=36 && base>1);

 //Variáveis locais
 uint64_t value=1, sum=0;
 int digit_index;

 //Procedimento
 //Loop principal: iterando sobre os digitos da representação de um número da direita para a esquerda
 for(digit_index=(number_string.length()-1); digit_index>=0; digit_index--){

  sum=sum+(value*find_index(number_string[digit_index], base));
  value=value*base;
                                                                           };



 //Exbindoo resultado da execução do algoritmo
 cout<<number_string<< " escrito na base 10 é "<<sum<< '\n';

                                           };


//*******************************************************************************************************************************************************************
//FUNÇÃO PRINCIPAL
int main(){

 //Variáveis locais
 string number_string;
 uint64_t number, dec_number;
 int base;

 //Recebendo input do usuário
 cout<<"Número: ";
 cin>>number;
 cout<<"Base em que este número será escrito: ";
 cin>>base;

 //Escrevendo o número na base desejada
 from_dec(number,base);

 //Recebendo input do usuário
 cout<<"\n\nSequência de digitos do número: ";
 cin>>number_string;
 cout<<"Base em que este número está escrito: ";
 cin>>base;


 //Escrevendo o número na base desejada
 to_dec(number_string, base);

 //Finalizando a aplicação
 return 0;
          }
