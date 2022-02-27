/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.cafemodelo.model;

/**
 *
 * @author aluno
 */
public class ItensPedido {
    private int id;
    private int qtde;
    private double valor;
    private Produto produto;
    private Pedido pedido;

    public ItensPedido() {
    }

    public ItensPedido(int qtde, Produto produto, Pedido pedido) {
        this.qtde = qtde;
        this.produto = produto;
        this.pedido = pedido;
    }

    public Pedido getPedido() {
        return pedido;
    }

    public void setPedido(Pedido pedido) {
        this.pedido = pedido;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getQtde() {
        return qtde;
    }

    public void setQtde(int qtde) {
        this.qtde = qtde;
    }

    public double getValor() {
        return valor;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }

    public Produto getProduto() {
        return produto;
    }

    public void setProduto(Produto produto) {
        this.produto = produto;
    }
    
}
