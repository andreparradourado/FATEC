
package br.cafemodelo.model;

import java.util.List;

public class UnidadeMedida {
    private int id;
    private String descricao;
    private List<ProdutoUnidade> produtos;

    public UnidadeMedida() {
    }

    public UnidadeMedida(String descricao) {
        this.descricao = descricao;
    }

    public String getDescricao() {
        return descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public List<ProdutoUnidade> getProdutos() {
        return produtos;
    }

    public void setProdutos(List<ProdutoUnidade> produtos) {
        this.produtos = produtos;
    }
    
    
}
