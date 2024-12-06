package model.dao;

import conectar.conexao;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import model.bean.Funcionario;

public class ProgramaDao {
    private Connection con = null;

    public ProgramaDao() {
        con = conexao.getConction();
    }
    
    public boolean inserirFuncao(Funcionario funcionario){
        
        String sql = "INSERT INTO funcionario(funcao) VALUES (?)";
        
        PreparedStatement stmt = null;
        
        try {
            stmt = con.prepareStatement(sql);
            stmt.setString(1, funcionario.getFuncao());
            
            int executeUpdate = stmt.executeUpdate();
            return true;
        } catch (SQLException ex) {
            System.err.println("Erro! "+ex);
            return false;
        }
    }
    public boolean inserirNome(Funcionario funcionario){
        
        String sql = "INSERT INTO funcionario(nome) VALUES (?)";
        
        PreparedStatement stmt = null;
        
        try {
            stmt = con.prepareStatement(sql);
            stmt.setString(1, funcionario.getNome());
            
            int executeUpdate = stmt.executeUpdate();
            return true;
        } catch (SQLException ex) {
            System.err.println("Erro! "+ex);
            return false;
        }
    }
    public boolean inserirCpf(Funcionario funcionario){
        
        String sql = "INSERT INTO funcionario(cpf) VALUES (?)";
        
        PreparedStatement stmt = null;
        
        try {
            stmt = con.prepareStatement(sql);
            stmt.setString(1, funcionario.getCpf());
            
            int executeUpdate = stmt.executeUpdate();
            return true;
        } catch (SQLException ex) {
            System.err.println("Erro! "+ex);
            return false;
        }
    }
    
    public boolean inserirEndereco(Funcionario funcionario){
        
        String sql = "INSERT INTO funcionario(endereco) VALUES (?)";
        
        PreparedStatement stmt = null;
        
        try {
            stmt = con.prepareStatement(sql);
            stmt.setString(1, funcionario.getEndereco());
            
            int executeUpdate = stmt.executeUpdate();
            return true;
        } catch (SQLException ex) {
            System.err.println("Erro! "+ex);
            return false;
        }finally{
        conexao.closeConnection(con, stmt);
        }
    }
    
}
