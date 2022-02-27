public class Cachorro {
    private String nome;
    private String cor;
    private String tamanho;
    private int idade;
    public void setCor(String cor) {
        this.cor = cor;
    }
    public void setIdade(int idade) {
        this.idade = idade;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public void setTamanho(String tamanho) {
        this.tamanho = tamanho;
    }
    public String getCor() {
        return cor;
    }
    public int getIdade() {
        return idade;
    }
    public String getNome() {
        return nome;
    }
    public String getTamanho() {
        return tamanho;
    }
    
    public void latir(){
        System.out.println("au au");
    }

    public void correr(){
        System.out.println("Estou correndo!");
    }
    
}
