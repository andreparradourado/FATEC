package br.cafemodelo.dao;

import br.cafemodelo.model.UnidadeMedida;

public class UnidadeMedidaDAO extends DAOGenerico<UnidadeMedida>{

    public UnidadeMedidaDAO() {
        super();
        instanciarUnidadeMedidas();
    }

    @Override
    public String update(UnidadeMedida obj) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    @Override
    public UnidadeMedida procurarPorId(int id) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }

    private void instanciarUnidadeMedidas() {
        UnidadeMedida Unidade1 = new UnidadeMedida("Pequeno");
        UnidadeMedida Unidade2 = new UnidadeMedida("Médio");
        UnidadeMedida Unidade3 = new UnidadeMedida("Grande");
        System.out.println(this.add(Unidade1));
        System.out.println(this.add(Unidade2));
        System.out.println(this.add(Unidade3));
    }

}
