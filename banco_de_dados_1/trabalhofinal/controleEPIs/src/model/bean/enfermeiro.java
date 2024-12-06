package model.bean;

public class enfermeiro extends Funcionario{
    
    private int cre;

    public enfermeiro() {
    }

    public enfermeiro(int cre, String epis) {
        super(epis);
        this.cre = cre;
    }

    public int getCre() {
        return cre;
    }

    public void setCre(int cre) {
        this.cre = cre;
    }
    
}
