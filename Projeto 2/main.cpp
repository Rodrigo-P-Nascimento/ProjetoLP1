#include <iostream>
#include "Produtos.h"
#include "Produtos.cpp"
#include "Mercearia.h"
#include "Mercearia.cpp"

#define LINHAS 30

using namespace std;

void Menu();
void FazLinhas(int numLinhas);
int LerOpcao(int comeco, int fim, int sair);
void MenuMercearia(vector<Mercearia> merc);

int main(){
    //classes de produtos
    ProdutoPeso PDpeso;
    ProdutoUnidade PDunidade;
    RemessaUnidade ReUNI;
    RemessaPeso RePES;
    vector<Mercearia> merc;

    //Variavéis de suporte ao programa
    int opcao, ativo=1;
    bool opInvalida;

    while(ativo){
        FazLinhas(LINHAS);
        cout << "Em qual das seções deseja trabalhar?" << endl;
        FazLinhas(LINHAS);
        cout << "[1] Mercearia" << endl;
        cout << "[2] Frios/Acougue" << endl;
        cout << "[3] Padaria" << endl;
        cout << "[4] Bebidas" << endl;
        cout << "[5] Limpeza" << endl;
        cout << "[-1] Sair do Programa" << endl;


        opcao = LerOpcao(1, 5, -1);
    
        switch (opcao){
            case 1:
                MenuMercearia(merc);
                cout << "AQUI!" << endl;
                cout << merc.size() << "!!!!!!!!" << endl;
                break;
            case -1:
                ativo = 0;
                break;
        }
    } // Ende while(ativo)
    

    return 0;
}

void FazLinhas(int numLinhas){
    for(int i=1; i <= numLinhas; i++){
        if(i == numLinhas) cout << "-" << endl;
        else cout << "-";
    }
}

void Menu(){
    FazLinhas(LINHAS);
    cout << "[1]    > Cadastrar novo Produto." << endl;
    cout << "[2]    > Remover um Produto." << endl;
    cout << "[-1]   > Voltar para Menu anterior." << endl;
    FazLinhas(LINHAS);

    cout << "Digite uma opcao: ";
}

int LerOpcao(int comeco, int fim, int sair){
    int opcao;
    bool opcaoInvalida = true;
    
    while (opcaoInvalida)
    {
        cin >> opcao;

        if ((opcao >= comeco && opcao <= fim) || (opcao == sair)){
            return opcao;
        }
        else {
            cout << "Opcao invalida! Tente novamente!" << endl;
        }
    }
}

void MenuMercearia(vector<Mercearia> merc){
    int opcao;

    merc.resize(1);
    cout << "Bem-vindo a secao de Mercearia!" << endl;
    while(true)
    {
        Menu();

        opcao = LerOpcao(1, 2, -1);

        switch (opcao){
            case 1:
                merc[0].CadastrarNovoProduto();
                cout << merc[0].getNome() << endl;
                break;
            case -1:
                return;
        }
    }// End while(ativo)
}