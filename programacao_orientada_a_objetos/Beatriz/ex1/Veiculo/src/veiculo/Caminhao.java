package veiculo;
public class Caminhao extends veiculo{
    
    private int numeroEixos;
 
    private double capacidade;
    
    public Caminhao(){}
    
    public Caminhao(String modelo, String placa, int ano, double valor, int numeroEixos, double capacidade){
        super(modelo, placa, ano, valor);
        this.numeroEixos = numeroEixos;
        this.capacidade = capacidade;
        
    }

    public int getNumeroEixos() {
        return numeroEixos;
    }

    public void setNumeroEixos(int numeroEixos) {
        this.numeroEixos = numeroEixos;
    }

    public double getCapacidade() {
        return capacidade;
    }

    public void setCapacidade(double capacidade) {
        this.capacidade = capacidade;
    }

    public double depreciar(int meses){
        double valor = getValor();
        valor += (((valor/1.25)/12)*meses) - valor;
        System.out.println("valor depreciado " + valor);
        return valor;
    }
    
    public void imprimirDados(){
        super.imprimirDados();
        System.out.println("Numero de eixos:: " + getNumeroEixos());
        System.out.println("Capacidade: " + getCapacidade() + "T");
    }
    
}
