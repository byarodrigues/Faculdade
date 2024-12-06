package estoqueepis;
public class medico extends funcionario{
    private int Crm;
    
    public medico(){}
    
    public medico(String funcao, String nome, int cpf, int codigo, String endereco, int Crm){
        super(funcao, nome, cpf, codigo, endereco);
        this.Crm = Crm;     
    }

    public int getCrm() {
        return Crm;
    }

    public void setCrm(int Crm) {
        this.Crm = Crm;
    }
    
    public void consultarFunc(){
        super.consultarFunc();
        System.out.println("Numero Crm: " + getCrm());
    }   
}