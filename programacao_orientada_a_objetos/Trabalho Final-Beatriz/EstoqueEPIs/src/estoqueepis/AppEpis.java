package estoqueepis;
public class AppEpis {
    public static void main(String[] args) {
            
        medico m = new medico("pediatra", "sofia", 118654958, 001, "jlf", 668);
               m.consultarFunc();
                
        enfermeiro e = new enfermeiro("enf", "jose", 5486, 002, "sdf", 895);
                   e.consultarFunc();
        
        EPIs ep = new EPIs("luva", 44, 52);
             ep.consultarEPIs();
    }  
}
