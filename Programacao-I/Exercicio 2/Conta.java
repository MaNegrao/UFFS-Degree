import java.util.Scanner; 

public class Conta{
	Scanner entrada = new Scanner(System.in);
	int numero;
	String dono;
	double saldo;
	static int cont;

	public Conta(String nome, int num, double saldo){
		this.dono = nome;
		this.numero = num;
		this.saldo = saldo;
		this.cont++;	
	}

	public void depositar(){
		System.out.println("Digite o valor do deposito");
		double valor = entrada.nextDouble();
		this.saldo += valor;
		System.out.println("Saldo após deposito: "+this.saldo);
		System.out.println("\n\n");
	}
	public void sacar(){
		System.out.print("Digite o valor desejado para saque: ");
		double valor = entrada.nextDouble();
		if(valor > this.saldo){
			System.out.println("Saldo insufienciente para saque");	
		}
		else{
			System.out.println("Transação aprovada!");
			this.saldo -= valor;
		}
		System.out.println("\n\n");
	}
	public void saldo(){
		System.out.println("Saldo atual da conta: "+this.saldo);
		System.out.println("\n\n");
	}
	public void transferir(double conta){
		System.out.println("Digite o valor desejado para transferir");
		double valor = entrada.nextDouble();
		if(valor > this.saldo){
			System.out.println("Saldo insufienciente para transação");
		}
		else{
			conta += valor;
			this.saldo -= valor;
			System.out.println("Transação aprovada!");
		}
		System.out.println("\n\n");
	}
	public void dados(){
		System.out.println("Titular da conta: "+this.dono);
		System.out.println("Saldo atual da conta: "+this.saldo);
		System.out.println("Numero da conta: "+this.numero);
		System.out.println("\n");
	}
}
