package veiculo;
public class Onibus extends veiculo{
    
    private int qtddPassageiros;
    
    public Onibus(){}
    
    public Onibus(String modelo, String placa, int ano, double valor, int qtddPassageiros){
        super(modelo, placa, ano, valor);
        this.qtddPassageiros = qtddPassageiros;        
    }
    
    public int getQtddPassageiros() {
        return qtddPassageiros;
    }

    public void setQtddPassageiros(int qtddPortas) {
        this.qtddPassageiros = qtddPassageiros;
    }
    
    public double depreciar(int meses){
        double valor = getValor();
        valor += (((valor/2.5)/12)*meses) - valor;
        System.out.println("valor depreciado " + valor);
        return valor;
    }
    
    public void imprimirDados(){
        super.imprimirDados();
        System.out.println("Passageiros: " + getQtddPassageiros());
    }
    
}
