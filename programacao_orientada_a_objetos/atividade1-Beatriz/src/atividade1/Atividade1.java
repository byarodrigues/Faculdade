/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package atividade1;

/**
 *
 * @author beatriz
 */
import java.util.Scanner;
public class Atividade1 {
    public static class Elevador{
        public int AtualAndar;
        public int TotalAndar;
        public int Capacidade;
        public int lotacao;
        
        public Elevador(){}
    
        public Elevador(int atual, int total, int cpcdd, int lot){
            if((lot <= cpcdd) && (atual <= total)){
                this.AtualAndar = atual;
                this.Capacidade = cpcdd;
                this.TotalAndar = total;
                this.lotacao = lot;
            }
        }
        public void setAtual(int atual, int total){
            if (atual <= total && atual >= 0){
                this.AtualAndar = atual;
            }
        }
        public void setLot(int lot, int cpcdd){
            if (lot <= cpcdd && lot > 0) {
                this.lotacao = lot;
            }    
        }
        public void setCpcdd(int cpcdd){
            this.Capacidade = cpcdd = 6;
        }
        public void setTotal(int total){
            this.TotalAndar = total = 10;
        }
        public int getAtual(){
            return this.AtualAndar;
        }
        public int getLot(){
            return this.lotacao;
        }
        public int getCpcdd(){
            return this.Capacidade;
        }
        public int getTotal(){
            return this.TotalAndar;
        }
        
    }
    
    public static boolean inicializa(){       //: que deve receber como parâmetros a capacidade do elevador 
        Elevador e1 = new Elevador();         //e o total de andares no prédio
        e1.AtualAndar = 0;                    //(os elevadores sempre começam no térreo e vazio);
        e1.Capacidade = 6;
        e1.TotalAndar = 10;
        e1.lotacao = 0;
        System.out.print(e1.AtualAndar);                                                        
        System.out.print(e1.Capacidade);                                                        
        System.out.print(e1.TotalAndar);                                                        
        System.out.print(e1.lotacao);                                                        
        return true;
    }
    public static boolean entra(Elevador e1){                   //para acrescentar uma pessoa no elevador
        int cap;
        int lot;
        cap = e1.Capacidade;
        lot = e1.lotacao;
        if(cap >= lot){                                       //(só deve acrescentar se ainda houver espaço);
            return false;
        }
        return true;
    }
    public static boolean sai(Elevador e1){//para remover uma pessoa do elevador 
        int lot;
        lot = e1.lotacao;
        if(lot > 0){                //(só deve remover se houver alguém dentro dele);
            lot = lot-1;
        }
        return true;
    }
    public static boolean sobe(Elevador e1){//para subir um andar (não deve subir se já estiver no último andar)
        int atual;
        int total;
        atual = e1.AtualAndar;
        total = e1.TotalAndar;
        if(atual == total){
            return false;
        }
        atual = atual + 1;
        return true;
    }
    public static boolean desce(Elevador e1){ //para descer um andar (não deve descer se já estiver no térreo);
        int atual;
        atual = e1.AtualAndar;
        if(atual == 0){
            return false;
        }
        atual = atual - 1;
        return true;
    }
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        //    Elevador e1 = new Elevador();
        //    e1.AtualAndar = 0;
        Elevador e1;
        inicializa();
        //System.out.print(e1.AtualAndar);
       
    }
}