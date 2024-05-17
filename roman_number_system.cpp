//VAMOS CRIAR UM PROGRAMA QUE IMPLEMENTA O SISTEMA DE ESCRITA DE NÚMEROS ROMANOS PARA NÚMEROS INTEIROS
//COMPILAR ESTE PROGRAMA COMO COMANDO: g++ -o roman_number_system roman_number_system.cpp


//****************************************************************************************************************************************
//CABEÇALHO
#include<iostream>
#include<string>
#include<cassert>
using namespace std;

//****************************************************************************************************************************************
//DECLARAÇÃO DE FUNÇÕES
void positional_decomposition(int&, int&, int&, int&, int);
string to_roman(int);

//****************************************************************************************************************************************
//FUNÇÕES

//Função que decompõe de acordo com seu valor posicional
void positional_decomposition(int& thousands, int& hundreds, int& tens, int& unities, int number){

  //Unidades de milhares
  thousands=number-(number%1000);
  //Centenas
  hundreds=(number-thousands)-(number%100);
  //Dezenas
  tens=(number-thousands-hundreds)-(number%10);
  //Unidades
  unities=number%10;

                                                                                                 };

//Função que escreve um inteiro inferior a 4000 em algarismos romanos
string to_roman(int number){
  //Restrição a inteiros inferiores a 4000
  assert(number<4000);

  //Variáveis locais
  int thousands, hundreds, tens, unities;
  string result="";


  //Procedimentos
    //Decompondo o número de acordo com seu valor posicional
    positional_decomposition(thousands, hundreds, tens, unities, number);

    //Escrevendo a string númerica em algarismos romanos

    //Unidades de milhares
    if(thousands==3000) result+="MMM"; if(thousands==2000) result+="MM"; if(thousands==1000) result+="M"; 

    //Centenas
    if(hundreds==900) result+="CM"; if(hundreds==800) result+="DCCC"; if(hundreds==700) result+="DCC"; if(hundreds==600) result+="DC"; if(hundreds==500) result+="D";
    if(hundreds==400) result+="CD"; if(hundreds==300) result+="CCC"; if(hundreds==200) result+="CC"; if(hundreds==100) result+="C";

    //Dezenas
    if(tens==90) result+="XC"; if(tens==80) result+="LXXX"; if(tens==70) result+="LXX"; if(tens==60) result+="LX"; if(tens==50) result+="L";
    if(tens==40) result+="XL"; if(tens==30) result+="XXX"; if(tens==20) result+="XX"; if(tens==10) result+="X";
    
    //Unidades
    if(unities==9) result+="IX"; if(unities==8) result+="VIII"; if(unities==7) result+="VII"; if(unities==6) result+="VI"; if(unities==5) result+="V";
    if(unities==4) result+="IV"; if(unities==3) result+="III"; if(unities==2) result+="II"; if(unities==1) result+="I"; if(number==0) result="N";


  //Resultado
  return result;

                           };


//****************************************************************************************************************************************
//PROGRAMA PRINCIPAL
int main(){

  //Variáveis locais
  string roman_string;
  int number;

  //Procedimentos 
    //Recebendo input do usuário
    cout<<"Digite um inteiro (até 3999): ";
    cin>>number;


    //Escrevendo o número em questão usando algarismos romanos
    roman_string=to_roman(number);
    cout<<number <<" em algarismos romanos: "<<roman_string<<'\n';


  //Finalizando a aplicação
  return 0;

          }
