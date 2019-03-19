import java.util.*;

public class Cliente{
	String nome, cpf;
	boolean fiado;

	public Cliente(String nome, String cpf, boolean fiado){
		this.nome = nome;
		this.cpf = cpf;
		this.fiado = fiado;
	}

	public Cliente(){

	}

	public String toString(){
		String fi;
		if(this.fiado)
			fi = new String("Sim");
		else
			fi = new String("Nao");
		return "\n\nNome: "+this.nome+"\nCPF: "+this.cpf
		+"\nPode comprar fiado? " + fi +"\n\n";
	}
}