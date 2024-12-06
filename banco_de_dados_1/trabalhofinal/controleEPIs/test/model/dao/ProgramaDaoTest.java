package model.dao;

import model.bean.Funcionario;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author beatr
 */
public class ProgramaDaoTest {
    
    public ProgramaDaoTest() {
    }

    @Test
    public void inserir() {
       
       Funcionario fun = new Funcionario("medico", "soh", "852", 001, "jlf", 85);
       ProgramaDao dao = new ProgramaDao();
       
       if(dao.inserirFuncao(fun)){
           System.err.println("Salvo com sucesso");
       }else{
           fail("erro ao salvar");
       }
       if(dao.inserirNome(fun)){
           System.err.println("Salvo com sucesso");
       }else{
           fail("erro ao salvar");
       }
       if(dao.inserirCpf(fun)){
           System.err.println("Salvo com sucesso");
       }else{
           fail("erro ao salvar");
       }

       if(dao.inserirEndereco(fun)){
           System.err.println("Salvo com sucesso");
       }else{
           fail("erro ao salvar");
       }  
     
    }
  
}
