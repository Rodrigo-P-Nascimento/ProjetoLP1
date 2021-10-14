#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include "Produtos.h"
#include "Produtos.cpp"

#define LINHAS 30

using namespace std;


// Funções Suporte
extern void FazLinhas(int numLinhas);
extern void limparTela(void);
extern int LerOpcao(int comeco, int fim, int sair);

// Funções Suporte para as Classes
extern bool Compara(Produto *a, Produto *b);
extern void MenuGeral(Seccao sec, vector<Produto*> &vec);
extern void NovoProduto(Seccao sec, vector<Produto*> &vec);
extern void AtualizarGeral(Seccao sec, vector<Produto*> &vec);
extern void RelatorioSeccao(Seccao sec, vector<Produto*> &prod);
extern void RemoverGeral(Seccao sec, vector<Produto*> &vec);


int main(){

    vector<Produto*> mercearia;
    vector<Produto*> frios;
    vector<Produto*> padaria;
    vector<Produto*> bebidas;
    vector<Produto*> limpeza;
    
    int opcao, ativo=1;
    
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
                MenuGeral(Seccao::MERCEARIA, mercearia);
                break;
            case 2:
                MenuGeral(Seccao::FRIOS, frios);
                break;
            case 3:
                MenuGeral(Seccao::PADARIA, padaria);
                break;
            case 4:
                MenuGeral(Seccao::BEBIDAS, bebidas);
                break;
            case 5:
                MenuGeral(Seccao::LIMPEZA, limpeza);
                break;
            case -1:
                ativo = 0;
                break;
        }
    }

    cout << "Saindo do programa!" << endl;

    cout << "\nPressione ENTER para sair do programa!" << endl;
    getchar();
    getchar();
    

    return 0;
}


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
    
    while (opcaoInvalida)
    {
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


bool Compara(Produto *a, Produto *b){
	return a->getCodigo() < b->getCodigo();
} // End Compara()


void MenuGeral(Seccao sec, vector<Produto*> &vec){

    int opcao;

    while (true){
        limparTela();
        FazLinhas(LINHAS);
        cout << "Qual acao deseja realizar?" << endl
            << "[1] > Cadastrar um Novo Produto." << endl
            << "[2] > Atualizar os Dados de Um Produto." << endl
            << "[3] > Ver o Relatorio de Produtos." << endl
            << "[4] > Remover um Produto." << endl
            << "[-1] > Voltar para Secçao Anterior." << endl;
        FazLinhas(LINHAS);

        cout << "\nEscolha uma opcao: ";
        opcao = LerOpcao(1, 4, -1);

        switch (opcao){
            case 1:
                cout << "\n";
                NovoProduto(sec, vec);
                break;
            case 2:
                AtualizarGeral(sec, vec);
                break;
            case 3:
                RelatorioSeccao(sec, vec);
                break;
            case 4:
                RemoverGeral(sec, vec);
                break;
            case -1:
                return;
        }
        cout << "\nPressione ENTER para voltar ao menu" << endl;
        getchar();
        getchar();
    }
}


void NovoProduto(Seccao sec, vector<Produto*> &vec){
    
    switch (sec){
        case Seccao::MERCEARIA:
            vec.push_back(new Mercearia());
            break;
        case Seccao::FRIOS:
            vec.push_back(new Frios_Acougue());
            break;
        case Seccao::PADARIA:
            vec.push_back(new Padaria());
            break;
        case Seccao::BEBIDAS:
            vec.push_back(new Bebidas());
            break;
        case Seccao::LIMPEZA:
            vec.push_back(new Limpeza());
            break;
    }

    vec[vec.size()-1]->Cadastro();

    cout << "\nProduto cadastrado com sucesso!" << endl;
}


void AtualizarGeral(Seccao sec, vector<Produto*> &vec){

    if (vec.size() == 0){
        cout << "\nESTOQUE VAZIO! NAO HA NENHUM PRODUTO PARA SE ATUALIZAR!" << endl;
        return;
    }

    RelatorioSeccao(sec, vec);


    int codigo;
    cout << "\nDigite o codigo do produto que deseja atualizar: ";
    cin >> codigo;

    bool produtoEncontrado = false;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i]->getCodigo() == codigo){
            vec[i]->Atualizar();
            produtoEncontrado = true;
            cout << "\nProduto atualizado com sucesso!" << endl;
            break;
        }
    }

    if (produtoEncontrado == false) cout << "\nProduto nao encontrado.";
}


void RelatorioSeccao(Seccao sec, vector<Produto*> &prod){

    limparTela();
    cout << "\n\n";
    FazLinhas(LINHAS);

    /*
    if(prod.size() != 0){
        cout << "\nCODIGO" << "\tNOME" << "\t\tPRECO" << "\tESTOQUE" << endl;
    } else {
        cout << "\nESTOQUE VAZIO!" << endl;
        cout << "\nPressione ENTER para voltar ao menu" << endl;
        getchar();
        getchar();
        return;
    }
    */

    if (prod.size() == 0){
        cout << "\nESTOQUE VAZIO!" << endl;
        FazLinhas(LINHAS);
        return;
    }

    sort(prod.begin(), prod.end(), Compara);

    cout << "Relatorio de produtos da seccao ";
    switch (sec){
        case Seccao::MERCEARIA:
            cout << "Mercearia:" << endl;
            break;
        case Seccao::FRIOS:
            cout << "Frios:" << endl;
            break;
        case Seccao::PADARIA:
            cout << "Padaria:" << endl;
            break;
        case Seccao::BEBIDAS:
            cout << "Bebidas:" << endl;
            break;
        case Seccao::LIMPEZA:
            cout << "Limpeza:" << endl;
            break;
    }

    cout << "\n";
    for (int i = 0; i < prod.size(); i++){
        prod[i]->Relatorio();
        cout << "\n";
    }

    FazLinhas(LINHAS);
} // End RelatorioSeccao()


void RemoverGeral(Seccao sec, vector<Produto*> &vec){

    if (vec.size() == 0){
        cout << "\nESTOQUE VAZIO!" << endl;
        return;
    }

    RelatorioSeccao(sec, vec);

    int codigo;
    cout << "\nDigite o codigo do produto que deseja deletar: ";
    cin >> codigo;

    bool produtoEncontrado = false;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i]->getCodigo() == codigo){
            produtoEncontrado = true;
            delete vec[i];
            vec.erase(vec.begin() + i);
            cout << "\nProduto Removido com Sucesso!" << endl;
            break;
        }
    }

    if (produtoEncontrado == false) cout << "\nProduto nao encontrado!" << endl;
}// End RemoverGeral()