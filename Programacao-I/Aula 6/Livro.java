import java.util.Scanner; 

public class Livro{
	Scanner entrada = new Scanner(System.in);
	String titulo, isbn;
	double valor;
	Pessoa autor = new Pessoa();

	public void cadastraDados(){
		System.out.println("Titulo: ");
		this.titulo = entrada.nextLine();
		System.out.println("ISBN: ");
		this.isbn = entrada.nextLine();
		System.out.println("Valor: ");
		this.valor = entrada.nextDouble();
		entrada.nextLine();
		System.out.println("Nome do autor: ");
		this.autor.nome = entrada.nextLine();
		System.out.println("Email do autor: ");
		this.autor.email = entrada.nextLine();
		System.out.println("CPF do autor: ");
		this.autor.cpf = entrada.nextLine();
		System.out.print("\n\n\n");
	}

	public String toString(){
		return "\nDetalhes Livro:\n"+"\nTitulo: "+this.titulo+"\nISBN: "+this.isbn
		+"Valor: "+this.valor + this.autor;
	}

}