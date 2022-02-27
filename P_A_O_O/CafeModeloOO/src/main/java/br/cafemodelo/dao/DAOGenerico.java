package br.cafemodelo.dao;

import java.util.ArrayList;
import java.util.List;

public abstract class DAOGenerico<T> { //T - Type
    private List<T> listaObjetos;
    
    public DAOGenerico(){
        listaObjetos = new ArrayList<>();
    }
    
    public String add(T obj){
        listaObjetos.add(obj);
        return obj.getClass().getSimpleName()+" salvo com sucesso!";
    }

    public abstract String update(T obj);
    public String delete(T obj){
       if(listaObjetos.contains(obj)){
           listaObjetos.remove(obj);
           return obj.getClass().getSimpleName()+"não consta na lista";
       } else {
           return obj.getClass().getSimpleName()+"não consta na lista";
       }
    }
    
    public List<T> listFull(){
        return listaObjetos;
    }
    
    public abstract T procurarPorId(int id);
}
