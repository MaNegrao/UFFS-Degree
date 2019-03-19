public class Biblioteca{
	public static void main(String [] args){
		Livro[] lista = new Livro[3];
		for(int i = 0; i < 3; i++){
			lista[i] = new Livro();
			lista[i].cadastraDados();
		}

		for(Livro l: lista){
			System.out.println(l);
		}


	}
}