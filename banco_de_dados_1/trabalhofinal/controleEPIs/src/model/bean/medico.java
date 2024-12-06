package model.bean;

public class medico extends Funcionario{
    
    private int crm;

    public medico() {
    }

    public medico(int crm, String epis) {
        super(epis);
        this.crm = crm;
    }

    public int getCrm() {
        return crm;
    }

    public void setCrm(int crm) {
        this.crm = crm;
    }

}
