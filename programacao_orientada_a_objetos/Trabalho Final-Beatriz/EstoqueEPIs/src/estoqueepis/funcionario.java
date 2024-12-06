package estoqueepis;
public class funcionario { 
    private String funcao;
    private String nome;
    private int cpf;
    private int codigo;
    private String endereco;

    public funcionario() { }

    public funcionario(String funcao, String nome, int cpf, int codigo, String endereco) {
        this.funcao = funcao;
        this.nome = nome;
        this.cpf = cpf;
        this.codigo = codigo;
        this.endereco = endereco;
    }

    public String getFuncao() {
        return funcao;
    }

    public void setFuncao(String funcao) {
        this.funcao = funcao;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getCpf() {
        return cpf;
    }

    public void setCpf(int cpf) {
        this.cpf = cpf;
    }

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getEndereco() {
        return endereco;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }
    
    public void consultarFunc(){
        System.out.println("Funcao: " + getFuncao());
        System.out.println("Nome: " + getNome());
        System.out.println("Cpf: " + getCpf());
        System.out.println("Codigo: " + getCodigo());
        System.out.println("Endereco: " + getEndereco());
    }
}