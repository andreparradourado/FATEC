package br.cafemodelo.dao;

import br.cafemodelo.model.Mesa;

public class MesaDAO extends DAOGenerico<Mesa>{

    public MesaDAO() {
        super();
        instanciarMesas();
    }
    
    
    @Override
    public String update(Mesa obj) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public Mesa procurarPorId(int id) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    private void instanciarMesas() {
        Mesa m1 = new Mesa(1,6);
        Mesa m2 = new Mesa(2,4);
        Mesa m3 = new Mesa(3,4);
        System.out.println(this.add(m1));
        System.out.println(this.add(m2));
        System.out.println(this.add(m3));
    }


}
