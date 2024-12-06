package estoqueepis;
public class EPIs extends array{
    private String nome;
    private int codigoE;
    private int preco;

    public EPIs() { }

    public EPIs(String nome, int codigoE, int preco) {
        this.nome = nome;
        this.codigoE = codigoE;
        this.preco = preco;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getCodigoE() {
        return codigoE;
    }

    public void setCodigo(int codigo) {
        this.codigoE = codigoE;
    }

    public int getPreco() {
        return preco;
    }

    public void setPreco(int preco) {
        this.preco = preco;
    }
        
    public void consultarEPIs(){
        System.out.println("Nome: " + getNome());
        System.out.println("Codigo EPIs: " + getCodigoE());
        System.out.println("Preco: " + getPreco());
    }
    
    public void inserirEpis(){
        EPIs e = new EPIs("luva", 001, 668);
             e.consultarEPIs();
    }
}
