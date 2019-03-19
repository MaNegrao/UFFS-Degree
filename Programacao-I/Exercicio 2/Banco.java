import java.util.Scanner; 

public class Banco{
	public static void main(String [] args){
		Scanner entrada = new Scanner(System.in);
		Conta m = new Conta("Matheus Negrão", 1000, 1711100026);
		Conta auxiliar = new Conta("Vida", 100000000, 1711100021);
		Conta em = new Conta("Emilio", 43332131, 98999832);
		int x;

		System.out.println(Conta.cont);
		/*do{
			System.out.print("1. Consultar saldo\n2. Efetuar saque\n3. Efetuar depósito\n4. Efetuar transferência\n5. Exibir dados da conta\n6. Sair\n");
			x = entrada.nextInt();
			switch(x){
				case 1:
					m.saldo();
					break;
				case 2:
					m.sacar();
					break;
				case 3:
					m.depositar();
					break;
				case 4:
					m.transferir(auxiliar.saldo);
					break;
				case 5:
					m.dados();
					break;
				case 6:
					System.out.println("Saindo...");
					break;
				default:
					System.out.println("Numero invalido, tente novamente");
					break;

			}
			//System.out.printf("\33[2J");
		}while(x != 6);*/
	}
}
