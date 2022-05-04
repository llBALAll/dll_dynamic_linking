// Simples programa pra usar a funcao da dll de forma explicita
// Eh necessario saber os prototipos das funcoes que ira utilizar;
// Codigo mais complexo porem NAO eh necessario linkar o executavel com o arquivo (.lib) da dll;
// Nao eh possivel ver a dependencia da dll (dumpbin.exe /dependents EXECUTAVEL.EXE),
// mas eh possivel ver o nome da dll (dumpbin.exe /rawdata /section:.rdata EXECUTAVEL.EXE);
// Caso haja uma modificacao interna das funcoes da dll mas nao no prototipo das funcoes 
// NAO EH necessario recompilar o EXE que utiliza a dll para poder usufruir das novas alteracoes 
// APENAS colocar a nova dll com as alteracoes no diretorio do EXE;

#include <Windows.h>
#include <iostream>


int main() {

	HINSTANCE Hdlltarget = LoadLibraryA("libdynamic.dll");

	if (Hdlltarget == NULL) {
		std::cout << "Cannot load dll!" << std::endl;
		return 1;
    }

    //using TfuncMOO = void(__cdecl*)();
    using TfuncMOO = void(__stdcall*)();
    TfuncMOO const hello = reinterpret_cast<TfuncMOO>(GetProcAddress(Hdlltarget, "hello"));

    if (hello == NULL) {
		std::cout << "Cannot load function of dll!" << std::endl;
		return 1;
    }

    hello();

    FreeLibrary(Hdlltarget);
	
	return 0;
}