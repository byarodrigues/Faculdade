package veiculo;

public class veiculo{
    
    private String modelo;
    private String placa;
    private int ano;
    private double valor;

    public veiculo() { }

    public veiculo(String modelo, String placa, int ano, double valor) {
        this.modelo = modelo;
        this.placa = placa;
        this.ano = ano;
        this.valor = valor;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }

    public int getAno() {
        return ano;
    }

    public void setAno(int ano) {
        this.ano = ano;
    }

    public double getValor() {
        return valor;
    }

    public void setValor(double valor) {
        this.valor = valor;
    }
    
    public double depreciar(int meses){
        double valor = getValor();
        valor += (((valor/5)/12)*meses) - valor;
        return valor;
    }
    
    public void imprimirDados(){
        System.out.println("modelo: " + getModelo());
        System.out.println("placa: " + getPlaca());
        System.out.println("Ano: " + getAno());
        System.out.println("valor: " + getValor());
   
    }
  
    
    
}
