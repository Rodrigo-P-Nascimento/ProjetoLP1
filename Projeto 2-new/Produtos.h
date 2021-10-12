#ifndef PRODUTO_H
#define PRODUTO_H

#include <string>


enum Seccao
{
	INDEFINIDO,
	MERCEARIA,
	PADARIA,
	FRIOS,
	BEBIDAS,
	LIMPEZA
};


class Produto{
	protected:
		std::string nome;
		int codigo;
		float preco;

	public:
		/******** CONSTRUTORES / DESTRUTOR ********/
		Produto();
		Produto(std::string nome, int codigo, float preco);
		virtual ~Produto();

		/******** MÉTODOS ********/
		virtual void Relatorio();
		virtual void Cadastro();
		virtual void Remover();
		virtual void Atualizar();
		virtual Seccao Seccao();
};

class Mercearia : public Produto{
	protected:
		int unidade;

	public:
		/******** CONSTRUTORES / DESTRUTOR ********/
		Mercearia();
		Mercearia(std::string nome, int codigo, float preco, int unidade);
		virtual ~Mercearia();

		/******** MÉTODOS ********/
		virtual void Relatorio() override;
		virtual void Cadastro() override;
		virtual void Remover() override;
		//virtual void Atualizar() override; Nao eh necessario
		virtual ::Seccao Seccao() override;
};

#endif