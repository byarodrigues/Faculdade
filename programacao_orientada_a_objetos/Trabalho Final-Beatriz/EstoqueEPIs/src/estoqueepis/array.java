package estoqueepis;
public class array{
    public void inserirEpis(String[] args){
        EPIs e = new EPIs("luva", 001, 668);
        String [] EpisArray;
        EpisArray = new String[100];
        EpisArray [0] = "ffs";
        System.out.printf("%s %10s \n", "Index", "Valores");
        for(int i = 0; i < 100; i++)
            System.out.printf("%3d %10d \n", i, EpisArray[ i ]);
            e.consultarEPIs();
    }
}
