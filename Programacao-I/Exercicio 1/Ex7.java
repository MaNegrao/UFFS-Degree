import java.util.Scanner; 

class Ex7{
	public static void main(String[] args){
		Scanner entrada = new Scanner(System.in);
		System.out.print("Digite um numero: ");
		int x = entrada.nextInt();
		while(x != 2){
			if(x%2 == 0){
				x = x / 2;
			}
			else{
				x = (3 * x) + 1;
			}
			System.out.print( x+ " -> ");
		}
	System.out.println("1");
	}
}