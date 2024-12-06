
public class Forma {
    
    private double altura;
    private double largura;
    private double raio;
    
    public Forma() {}
    
    public Forma(double altura) {
        this.altura = altura;
    }

    public Forma(double altura, double largura, double raio) {
        this.altura = altura;
        this.largura = largura;
        this.raio = raio;
    }
    
    public double getAltura() {
        return altura;
    }

    public void setAltura(double altura) {
        this.altura = altura;
    }

    public double getLargura() {
        return largura;
    }

    public void setLargura(double largura) {
        this.largura = largura;
    }

    public double getRaio() {
        return raio;
    }

    public void setRaio(double raio) {
        this.raio = raio;
    }    
}
