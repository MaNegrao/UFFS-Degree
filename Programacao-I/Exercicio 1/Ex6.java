class Ex6{
	public static void main(String[] args){
		System.out.println(" A sequencia Fibonacci que ultrapasse 100: ");
		int n1 = 0, n2 = 1, nn = 0;
		for(int i = 1; i < 14; i++){
			if(i%2 == 1){
				System.out.print(" " +nn);
				nn = n1 + n2;
				n1 = nn;
			}
			else if(i == 2){
				System.out.print(" " +nn);
			}
			else if(i%2 == 0){
				System.out.print(" " +nn);
				nn = n1 + n2;
				n2 = nn;
			}
		}
	}
}