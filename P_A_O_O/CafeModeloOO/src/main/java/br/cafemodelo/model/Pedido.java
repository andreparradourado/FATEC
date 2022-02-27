/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package br.cafemodelo.model;

import java.util.Date;
import java.util.List;

/**
 *
 * @author aluno
 */
public class Pedido {
    private int id;
    private Date dataHorario;
    private String status;
    private Mesa mesa;
    private List<ItensPedido> itens;
    
    public Pedido(){
    }

    public Pedido(Date dataHorario, String status, Mesa mesa, List<ItensPedido> itens) {
        this.dataHorario = dataHorario;
        this.status = status;
        this.mesa = mesa;
        this.itens = itens;
    }
    
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Date getDataHorario() {
        return dataHorario;
    }

    public void setDataHorario(Date dataHorario) {
        this.dataHorario = dataHorario;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public Mesa getMesa() {
        return mesa;
    }

    public void setMesa(Mesa mesa) {
        this.mesa = mesa;
    }

    public List<ItensPedido> getItens() {
        return itens;
    }

    public void setItens(List<ItensPedido> itens) {
        this.itens = itens;
    }
}