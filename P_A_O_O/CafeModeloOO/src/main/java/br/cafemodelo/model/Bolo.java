package br.cafemodelo.model;

public class Bolo extends Produto{
    private String ingredientes;

    public Bolo() {
    }

    public Bolo(String ingredientes) {
        this.ingredientes = ingredientes;
    }

    public Bolo(String nome, String foto) {
        super(nome, foto);
    }

    public String getIngredientes() {
        return ingredientes;
    }

    public void setIngredientes(String ingredientes) {
        this.ingredientes = ingredientes;
    }
}