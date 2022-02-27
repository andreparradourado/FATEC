import javax.print.attribute.standard.Media;

public class App {
    public static void main(String[] args) throws Exception {
        Cachorro meuCachorro = new Cachorro();

        meuCachorro.setNome("totó");
        meuCachorro.setCor("preto");
        meuCachorro.setIdade(80);
        meuCachorro.setTamanho("grande");
        meuCachorro.latir();
        
    }

}
