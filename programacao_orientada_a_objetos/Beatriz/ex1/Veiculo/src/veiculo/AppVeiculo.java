package veiculo;
public class AppVeiculo {

    public static void main(String[] args) {
        Carro car = new Carro("corola", "hcq2552", 2020, 30000, 4, "agua");
                car.imprimirDados();
        car.depreciar(12);
        
        Onibus oni = new Onibus("busao", "luz2020", 2020, 250000, 16);
                oni.imprimirDados();
        oni.depreciar(20);
        
        Caminhao cam = new Caminhao("minhao", "wet5614", 2020, 150000, 6, 2);
                cam.imprimirDados();
        cam.depreciar(15);
        
    }
    
}
