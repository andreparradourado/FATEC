package br.cafemodelo.testes;

import br.cafemodelo.model.Bebida;
import br.cafemodelo.model.Bolo;
import br.cafemodelo.model.Mesa;
import br.cafemodelo.model.Produto;


//ATRIBUTOS E METÓDOS SEMPRE COMEÇA COM LETRA MINUSCULA
//RUN FILE (SHIFT+F6) SÓ FUNCIONA SE HOUVER O MAIN NA CLASSE EM QUE ESTOU TENTANDO EXECUTAR
public class Teste {

    public static void main(String[] args) {
    Mesa mesaTeste = new Mesa();
//        System.out.println("Numero da mesa:" + mesaTeste.getId());
//
//        Mesa mesa2 = new Mesa(2, 6);
//        System.out.println("Numero da mesa:" + mesa2.getId());
    Produto prod = new Bebida();
    Produto prod2 = new Bolo();
    }
}

//FORMATAR CODIGO (FORMAT) - ALT + SHIFT + F
//SE INSTANCIAR INT SEM ESPECIFICAR É 0
//SE INSTANCIAR INTEGER SEM ESPECIFICAR É NULL