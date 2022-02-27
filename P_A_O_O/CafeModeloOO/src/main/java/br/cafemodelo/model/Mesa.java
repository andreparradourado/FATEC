
// AWT > COMPONENTES PARA VISUAL
package br.cafemodelo.model;
import java.util.List;

public class Mesa {
    private int id;
    private int qtdePessoas;
    private List<Pedido> pedidos;
    
    //IMPLEMENTAÇÃO/LISTA GENÉRICA
    //List<Class_Name> list_name;
    //CLICAR NO ERRO DA LINHA OU CTRL+SHIFT+I
    //CONSTRUTOR IMPLICITO > EXISTE P/ QUEM ESQUECEU DE ESPECIFICAR O CONSTRUTOR DE QLQ CLASSE
    //A PARTIR DO MOMENTO QUE O CONSTRUTOR É ESPECIFICO ESTE CONSTRUTOR IMPLICITO/VAZIO SOME

    //CONSTRUTOR SEM ARGUMENTOS - ÚNICO OBRIGATÓRIO DE TODA CLASSE
    public Mesa() {
    }
    
    //CONSTRUTOR COM ARGUMENTOS
    //ALT + INSERT  > CONSTRUTOR > ESCOLHER O QUE SER INSTANCIADO AO USAR O METODO CONSTRUTOR
    public Mesa(int id, int qtdePessoas) {
        this.id = id;
        this.qtdePessoas = qtdePessoas;
    }

    //INICIO - POJO > ALT + INSERT > GETTER AND SETTER > ENCAPSULATE
    public int getQtdePessoas() {
        return qtdePessoas;
    }

    public void setQtdePessoas(int qtdePessoas) {
        this.qtdePessoas = qtdePessoas;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public List<Pedido> getPedidos() {
        return pedidos;
    }

    public void setPedidos(List<Pedido> pedidos) {
        this.pedidos = pedidos;
    }
    // FIM - POJO
    
    
    
    
    
    
    
    
    
    
    
}
