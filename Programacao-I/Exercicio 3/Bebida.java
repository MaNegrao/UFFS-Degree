import java.util.*;

public class Bebida{
	Scanner entrada = new Scanner(System.in);
	String Nome, teor;
	double preco;
	int qtd, ml;

	public Bebida(String nome, double preco, String teor, int ml, int qtd){
		this.Nome = nome;
		this.preco = preco;
		this.teor = teor;
		this.ml = ml;
		this.qtd = qtd;	
	}

	public Bebida(){

	}	

	public void lista(ArrayList<Bebida> beb){
		System.out.println("Digite o codigo da Bebida desejada:\n\n");
		for(int i = 0; i < beb.size(); i++){
			Bebida prod = beb.get(i);
			System.out.println("Nome: " + prod.Nome + " Cod: [" +(i+1)+"]\n\n");
		}
	}

	public boolean confereEstoque(int n){
		if(n > 0){
			return true;
		}
		else{
			return false;
		}
	}

	public void compra(ArrayList<Bebida> beb){
		lista(beb);
		int i;
		int n = entrada.nextInt();
		n--;
		for(i = 0; i < beb.size(); i++){
			Bebida prod = beb.get(i);
			if(i == n){
				break;
			}
		}
		Bebida prod = beb.get(i);
		if(i == beb.size()){
			System.out.println("Codigo invalido ou bebida não cadastrada");
		}
		else{
			System.out.print("Digite a quantidade de bebidas compradas: ");
			int comp = entrada.nextInt();
			prod.qtd += comp;
			System.out.println("Quantidade de bebidas atualizada: " + prod.qtd);
		}

	}

	public void venda(ArrayList<Bebida> beb){
		lista(beb);
		int i;
		int n = entrada.nextInt();
		n--;
		for(i = 0; i < beb.size(); i++){
			Bebida prod = beb.get(i);
			if(i == n){
				break;
			}
		}
		Bebida prod = beb.get(i);
		if(i == beb.size()){
			System.out.println("Codigo invalido ou bebida não cadastrada");
		}
		else if(confereEstoque(prod.qtd)){
			System.out.print("Digite a quantidade de bebidas para vender: ");
			int a = entrada.nextInt();
			while(a > prod.qtd){
				System.out.println("Valor maior do que o estoque, Digite novamente: ");
				a = entrada.nextInt();
			}
			prod.qtd -= a;
			System.out.println("Quantidade de bebidas atualizada: " + prod.qtd);
		}
		else{
			System.out.println("Estoque Vazio! Abasteça");
		}
	}

	public void estoque(ArrayList<Bebida> beb){
		lista(beb);
		int i;
		int n = entrada.nextInt();
		n--;
		for(i = 0; i < beb.size(); i++){
			Bebida prod = beb.get(i);
			if(i == n){
				break;
			}
		}
		Bebida prod = beb.get(i);
		System.out.println("Ainda tem " +prod.qtd+ " " +prod.Nome);
	}

	public String toString(){
		return "\n\nNome: " +this.Nome+ "\nPreço: R$ " +this.preco
		+"\nTeor Alcoolico: " +this.teor+ "\nEstoque: " +this.qtd
		+ " und. - " +this.ml+ "ML\n";
	}
}