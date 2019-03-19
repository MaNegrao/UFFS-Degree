/* O Codigo vai exibir os resultados errados pois o limite do int é de
2.147.483.647 e o do long de 9.223.372.036.854.775.807, por isso, a partir
de certo momento o codigo irá printar os resultados errados*/

class Ex5{
	public static void main(String[] args){
		System.out.println("Os Fatoriais entre 1 e 10 são: ");
		long s = 1;
		for(long i = 1; i <= 40; i++){
			s = s * i;
			System.out.println("O fatorial de " +i+ " é " +s);
		}
	}
}