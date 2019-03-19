class Ex4{
	public static void main(String[] args){
		System.out.println("Os Fatoriais entre 1 e 10 são: ");
		long s = 1;
		for(long i = 1; i <= 10; i++){
			s = s * i;
			System.out.println("O fatorial de " +i+ " é " +s);
		}
	}
}