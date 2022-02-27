
package br.cafemodelo.testes;

import br.cafemodelo.dao.MesaDAO;
import br.cafemodelo.dao.UnidadeMedidaDAO;
import br.cafemodelo.model.Mesa;
import br.cafemodelo.model.UnidadeMedida;

public class TesteDAO {
    public static void main(String[] args){
        MesaDAO daoMesa = new MesaDAO();
        UnidadeMedidaDAO daoUnidadeMedida = new UnidadeMedidaDAO();
        
        Mesa m4 = new Mesa(4,8);
        daoMesa.add(m4);
        
        UnidadeMedida x4 = new UnidadeMedida("Nova");
        daoUnidadeMedida.add(x4);
        for(Mesa mesa :daoMesa.listFull()){ //FOR EACH - PARA CADA ELEMENTO
            System.out.println("N." + mesa.getId() + " - qtde Pessoas: " + mesa.getQtdePessoas());
        }
        
        for(UnidadeMedida unidadeMedida :daoUnidadeMedida.listFull()){ //FOR EACH - PARA CADA ELEMENTO
            System.out.println("Descrição " + unidadeMedida.getDescricao());
        }
    }
}
