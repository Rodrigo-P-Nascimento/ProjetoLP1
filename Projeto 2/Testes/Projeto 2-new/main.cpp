#include <iostream>
#include <algorithm>
#include <windows.h>
#include "Produtos.h"
#include "Produtos.cpp"

#define TAM 100
#define LINHAS 30

using namespace std;

// Funções Suporte
void FazLinhas(int numLinhas);
void limparTela(void);
int LerOpcao(int comeco, int fim, int sair);

// Funções Suporte para as Classes
void CadastroGeral(Produto **prod);
void RelatorioGeral(Produto **prod);
void AtualizarGeral(Produto **prod);
void RemoverGeral(Produto **prod);
void MenuGeral(Produto **prod);
bool Compara(Produto *a, Produto *b);

int main(){

    Produto *merc[TAM];
    Produto *padaria[TAM];
    Produto *frios_acougue[TAM];
    Produto *limpeza[TAM];
    Produto *bebidas[TAM];

    int opcao, ativo=1;
    bool opInvalida;

    for(int i=0;i < TAM; i++){
        merc[i] = new Mercearia();
        frios_acougue[i] = new Frios_Acougue();
        padaria[i] = new Padaria();
        bebidas[i] = new Bebidas();
        limpeza[i] = new Limpeza();
    }
    
    while(ativo){
        limparTela();

        FazLinhas(LINHAS);
        cout << "Em qual das Secoes deseja trabalhar?" << endl;
        FazLinhas(LINHAS);

        cout << "\t[1] Mercearia" << endl;
        cout << "\t[2] Frios/Acougue" << endl;
        cout << "\t[3] Padaria" << endl;
        cout << "\t[4] Bebidas" << endl;
        cout << "\t[5] Limpeza" << endl;
        cout << "\t[-1] Sair do Programa" << endl;

        cout << "\nDigite uma opcao: ";
        opcao = LerOpcao(1, 5, -1);
    
        switch (opcao){
            case 1:
                limparTela();

                FazLinhas(LINHAS);
                cout << "Bem-vindo a Secao de Mercearia!" << endl;
                FazLinhas(LINHAS);

                MenuGeral(merc); // MERCEARIA

                cout << "\nPrecione ENTER para tentar novamente!" << endl;
                getchar();
                getchar();
                break;
            case 2:
                limparTela();
                
                FazLinhas(LINHAS);
                cout << "Bem-vindo a Secao de Frios e Acougue!" << endl;
                FazLinhas(LINHAS);

                MenuGeral(frios_acougue); // FRIOS E AÇOUGUE

                cout << "\nPrecione ENTER para tentar novamente!" << endl;
                getchar();
                getchar();
                break;
            case 3:
                limparTela();

                FazLinhas(LINHAS);
                cout << "Bem-vindo a Secao de Padaria!" << endl;
                FazLinhas(LINHAS);

                MenuGeral(padaria); // PADARIA

                cout << "\nPrecione ENTER para tentar novamente!" << endl;
                getchar();
                getchar();
                break;
            case 4:
                limparTela();

                FazLinhas(LINHAS);
                cout << "Bem-vindo a Secao de Bebidas!" << endl;
                FazLinhas(LINHAS);

                MenuGeral(bebidas); // BEBIDAS

                cout << "\nPrecione ENTER para tentar novamente!" << endl;
                getchar();
                getchar();
                break;
            case 5:
                limparTela();

                FazLinhas(LINHAS);
                cout << "Bem-vindo a Secao de Limpeza!" << endl;
                FazLinhas(LINHAS);

                MenuGeral(limpeza); // LIMPEZA

                cout << "\nPrecione ENTER para tentar novamente!" << endl;
                getchar();
                getchar();
                break;
            case -1:
                ativo = 0;
                break;
        }
    }// End While(ativo)
    
    cout << "Saindo do programa!" << endl;

    cout << "\nPrecione ENTER para sair do programa!" << endl;
    getchar();

    return 0;
}//End main

/******************** FUNÇÕES SUPORTE ********************/
void FazLinhas(int numLinhas){
    for(int i=1; i <= numLinhas; i++){
        if(i == numLinhas) cout << "-" << endl;
        else cout << "-";
    }
}// End FazLinhas()

void limparTela(void){
    system("cls"); // Só funciona no Windows
} // End limparTela()

int LerOpcao(int comeco, int fim, int sair){
    int opcao;
    bool opcaoInvalida = true;
    
    while (opcaoInvalida){
        cin >> opcao;

        if ((opcao >= comeco && opcao <= fim) || (opcao == sair)){
            return opcao;
        }
        else {
            cout << "Opcao invalida! Tente novamente!" << endl;
            cout << "\nDigite uma opcao: ";
        }
    }// End While(opcaoInvalida)
}// End LerOpcao()

/******************** Funções Suporte para as Classes ********************/
void CadastroGeral(Produto **prod){
    for (int i = 0; i < TAM; i++){
        if(prod[i]->getNome() == ""){
            prod[i]->Cadastro();
            break;
        }
    }
} //End CadastroGeral()

bool Compara(Produto *a, Produto *b){
	return a->getCodigo() < b->getCodigo();
} // End Compara()

void RelatorioGeral(Produto **prod){
    bool produtosEmEstoque = false;

    for (int i = 0; i < TAM; i++){
        if(prod[i]->getNome() != ""){
            produtosEmEstoque = true;
            break;
        }
    }

    if(produtosEmEstoque){
        cout << "\nCODIGO" << "\tNOME" << "\t\tPRECO" << "\tESTOQUE" << endl;
    } else {
        cout << "\nESTOQUE VAZIO!" << endl;
        return;
    }

    sort(prod, prod+TAM, Compara);

    for (int i = 0; i < TAM; i++){
        if(prod[i]->getNome() != ""){
            prod[i]->Relatorio();
            cout << "\n";
        }
    }
} //End RelatorioGeral()

void AtualizarGeral(Produto **prod){
    int opcao;
    bool produtoEncontrado = false;
    bool produtosEmEstoque = false;

    for (int i = 0; i < TAM; i++){
        if(prod[i]->getNome() != ""){
            produtosEmEstoque = true;
            break;
        }
    }

    if(produtosEmEstoque){
        cout << "\nSelecione um Produto para atualizar" <<  endl;
    } else {
        cout << "\nESTOQUE VAZIO!" << endl;
        return;
    }
    
    RelatorioGeral(prod);

    cout << "\nCodigo: ";
    cin >> opcao;

    for (int i = 0; i < TAM; i++){
        if(prod[i]->getCodigo() == opcao){
            produtoEncontrado = true;
            prod[i]->Atualizar();
            cout << "\nProduto Atualizado!" << endl;
            break;
        }
    }

    if(produtoEncontrado == false) cout << "\nProduto nao encontrado " << endl;
} //End AtualizarGeral()

void RemoverGeral(Produto **prod){
    int opcao;
    bool produtoEncontrado = false;
    bool produtosEmEstoque = false;

    for (int i = 0; i < TAM; i++){
        if(prod[i]->getNome() != ""){
            produtosEmEstoque = true;
            break;
        }
    }

    if(produtosEmEstoque){
        cout << "\nSelecione um Produto para remover" <<  endl;
    } else {
        cout << "\nESTOQUE VAZIO!" << endl;
        return;
    }

    RelatorioGeral(prod);

    cout << "\nCodigo: ";
    cin >> opcao;

    for (int i = 0; i < TAM; i++){
        if(prod[i]->getCodigo() == opcao){
            produtoEncontrado = true;
            prod[i]->Remover();
            cout << "\nProduto Removido!" << endl;
            break;
        }
    }

    if(produtoEncontrado == false) cout << "\nProduto nao encontrado " << endl;
} //End RemoverGeral()

void MenuGeral(Produto **prod){
    int opcao;

    cout << "[1] Cadastrar um Novo Produto" << endl;
    cout << "[2] Relatorio de Secao" << endl;
    cout << "[3] Atualizar um Produto" << endl;
    cout << "[4] Remover um Produto" << endl;
    cout << "[-1] Voltar para Menu Anterior" << endl;

    cout << "\nDigite uma opcao: ";
    opcao = LerOpcao(1, 4, -1);

    switch (opcao){
    case 1:
        CadastroGeral(prod);
        break;
    case 2:
        RelatorioGeral(prod);
        break;
    case 3:
        AtualizarGeral(prod);
        break;
    case 4:
        RemoverGeral(prod);
        break;
    case -1:
        return;
    }
} // MenuGeral()