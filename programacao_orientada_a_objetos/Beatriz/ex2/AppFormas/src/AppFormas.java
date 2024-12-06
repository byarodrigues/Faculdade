
public class AppFormas {
    public static void main(String[] args) {
        int[]numeros = new int[10];
        
        for(int i=0; i<10; i++){
            numeros[i] = 10;
        }
      
        Quadrado[]quadrado = new Quadrado[10];
        
        for(int i=0; i<10; i++){
            quadrado[i] = new Quadrado();
        }
        
        Forma[]formas = new Forma[10]; 
        Quadrado Q = new Quadrado(9.9, 8.8, 7.7);
        formas[0] = Q;

        System.out.println(formas[0]);
        
        System.out.println("\n\nAlturaQ: " + formas[0].getAltura());
                
        Bidimensional[]bi = new Bidimensional[10]; 
        bi[0] = new Quadrado(9.9, 8.8, 7.7);
        System.out.println("ObArea: " + bi[0].obterArea());
   
    }
}
