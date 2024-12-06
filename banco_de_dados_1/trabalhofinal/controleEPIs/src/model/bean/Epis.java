package model.bean;

public class Epis extends programa{
    
    private String nome;
    private int preco;
    private int controle_codigoE;

    public Epis() {
    }

    public Epis(String nome, int codigo, int preco, int controle_codigoE) {
        this.nome = nome;
        this.preco = preco;
        this.controle_codigoE = controle_codigoE;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getPreco() {
        return preco;
    }

    public void setPreco(int preco) {
        this.preco = preco;
    }

    public int getControle_codigoE() {
        return controle_codigoE;
    }

    public void setControle_codigoE(int controle_codigoE) {
        this.controle_codigoE = controle_codigoE;
    }

}
