package estoqueepis;
public class enfermeiro extends funcionario{
    private int Cre;
    
    public enfermeiro(){}
    
    public enfermeiro(String funcao, String nome, int cpf, int codigo, String endereco, int Cre){
        super(funcao, nome, cpf, codigo, endereco);
        this.Cre = Cre;           
    }

    public int getCre() {
        return Cre;
    }

    public void setCre(int Cre) {
        this.Cre = Cre;
    }
    
    public void consultarFunc(){
        super.consultarFunc();
        System.out.println("Numero Cre: " + getCre());
    }
}