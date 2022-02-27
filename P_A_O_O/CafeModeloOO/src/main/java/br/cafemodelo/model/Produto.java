
package br.cafemodelo.model;

import java.util.List;

public abstract class Produto {
    private int id;
    private String nome;
    private String foto;
    private List<ProdutoUnidade> listaUnidades;
    private List<ItensPedido> listItens;

    public Produto() {
    }

    public Produto(String nome, String foto) {
        this.nome = nome;
        this.foto = foto;
    }

    public String getFoto() {
        return foto;
    }

    public void setFoto(String foto) {
        this.foto = foto;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public List<ProdutoUnidade> getListaUnidades() {
        return listaUnidades;
    }

    public void setListaUnidades(List<ProdutoUnidade> listaUnidades) {
        this.listaUnidades = listaUnidades;
    }

    public List<ItensPedido> getListItens() {
        return listItens;
    }

    public void setListItens(List<ItensPedido> listItens) {
        this.listItens = listItens;
    }

}
