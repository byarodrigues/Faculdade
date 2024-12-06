package estoqueepis;
public class controle {
    private String nome;
    private int codigoE;
    private int codigo;
    
    public controle(){}
    
    public controle(String nome, int codigoE, int codigo){
        this.nome = nome; 
        this.codigoE = codigoE; 
        this.codigo = codigo; 
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

    public void setCodigoE(int codigoE) {
        this.codigoE = codigoE;
    }

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public void consultarFunc(){
        System.out.println("nome: " + getNome());
        System.out.println("codigo epi: " + getCodigoE());
        System.out.println("codigo funcionario: " + getCodigo());
    } 
}