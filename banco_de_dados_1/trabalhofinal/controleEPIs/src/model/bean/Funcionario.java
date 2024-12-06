package model.bean;

public class Funcionario extends programa{
    private String funcao;
    private String nome;
    private String cpf;
    private int codigo;
    private String endereco;

    public Funcionario(){
    }

    public Funcionario(String funcao, String nome, String cpf, int codigo, String endereco, int senha) {
        super(senha);
        this.funcao = funcao;
        this.nome = nome;
        this.cpf = cpf;
        this.codigo = codigo;
        this.endereco = endereco;
    }

    public Funcionario(String epis) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
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

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
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
    
}
