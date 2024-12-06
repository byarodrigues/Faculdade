package veiculo;
public class Carro extends veiculo{
    
    private int qtddPortas;
 
    private String combustivel;
    
    public Carro(){}
    
    public Carro(String modelo, String placa, int ano, double valor, int qtddPortas, String combustivel){
        super(modelo, placa, ano, valor);
        this.qtddPortas = qtddPortas;
        this.combustivel = combustivel;
        
    }

    public int getQtddPortas() {
        return qtddPortas;
    }

    public void setQtddPortas(int qtddPortas) {
        this.qtddPortas = qtddPortas;
    }

    public String getCombustivel() {
        return combustivel;
    }

    public void setCombustivel(String combustivel) {
        this.combustivel = combustivel;
    }
    
    public double depreciar(int meses){
        double valor = getValor();
        valor += (((valor/5)/12)*meses) - valor;
        System.out.println("valor depreciado " + valor);
        return valor;
    }
    
    public void imprimirDados(){
        super.imprimirDados();
        System.out.println("Portas: " + getQtddPortas());
        System.out.println("Combustivel: " + getCombustivel());
    }
    
}
