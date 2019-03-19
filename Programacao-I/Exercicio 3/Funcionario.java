import java.util.*;

public class Funcionario{
	String nome, cpf;
	String nasc, cargo;
	double salario;
	public Funcionario(String nome, String cpf, String nasc, String cargo, double salario){
		this.nome = nome;
		this.cpf = cpf;
		this.nasc = nasc;
		this.cargo = cargo;
		this.salario = salario;
	}
	public Funcionario(){

	}
	public String toString(){
		return "\n\nNome: "+this.nome+"\nCPF: "+this.cpf
		+"\nSalario : R$ " +this.salario+ "\nCargo: " +this.cargo
		+"\nData de Nascimento: " +this.nasc+ "\n\n";
	}
}