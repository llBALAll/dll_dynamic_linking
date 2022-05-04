// Simples programa pra usar a funcao da dll de forma implicita;
// Eh necessario declarar apenas os prototipos das funcoes que ira utilizar;
// Codigo mais simples porem eh necessario linkar o executavel com o arquivo (.lib) da dll;
// Eh possivel ver a dependencia da dll (dumpbin.exe /dependents EXECUTAVEL.EXE);
// Caso haja uma modificacao interna das funcoes da dll mas nao no prototipo das funcoes 
// NAO EH necessario recompilar o EXE que utiliza a dll para poder usufruir das novas alteracoes 
// APENAS colocar a nova dll com as alteracoes no diretorio do EXE;
#include "..\libdynamic\libdynamic.h"

// passa o nome da lib para o linker, dessa forma nao tendo q editar o .bat de build incluindo a libdynamic.lib
#pragma comment(lib, "..\\libdynamic\\libdynamic.lib")

//void hello();

int main() {
	
	hello();

	return 0;
}