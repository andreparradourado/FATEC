//boolean = FALSE Boolean = NULL
//double  = 0     Double = NULL
//int     = 0     Integer = NULL
//char            String
//char[]          String
// /\ primitivos  /\construidos


package br.cafemodelo.model;

public class ProdutoUnidade {
    private int id;
    private Produto produto;
    private UnidadeMedida unidade;
    private double valor;

    public ProdutoUnidade() {
    }

    public ProdutoUnidade(Produto produto, UnidadeMedida unidade, double valor) {
        this.produto = produto;
        this.unidade = unidade;
        this.valor = valor;
    }

    public double getValor() {
        return valor;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Produto getProduto() {
        return produto;
    }

    public void setProduto(Produto produto) {
        this.produto = produto;
    }

    public UnidadeMedida getUnidade() {
        return unidade;
    }

    public void setUnidade(UnidadeMedida unidade) {
        this.unidade = unidade;
    }
    
    
}
