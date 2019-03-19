import java.util.*; 

public class Empresa{
	String Nome, cnpj, Dono;
	Scanner entrada = new Scanner(System.in);
	boolean vrf = false;

	public Empresa(String Nome, String cnpj, String Dono){
		this.Dono = Dono;
		this.Nome = Nome;
		this.cnpj = cnpj;
	}
	public Empresa(){

	}

	public void menu(){
		System.out.print("\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		System.out.print("\t\t┃                         ♣ Bodega do Seu João ♣                       ┃\n");
		System.out.print("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		System.out.print("\t\t┃ ➊ ─ Contratar Bodegueiro          ┃ ➏ ─ Conferir Estoque de Bebida   ┃\n");
		System.out.print("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		System.out.print("\t\t┃ ➋ ─ Cadastrar Bebida no Estoque   ┃ ➐ ─ Mostrar Dados Bebidas        ┃\n");
		System.out.print("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		System.out.print("\t\t┃ ➌ ─ Cadastrar Cliente Novo        ┃ ➑ ─ Mostrar Dados Clientes       ┃\n");
		System.out.print("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		System.out.print("\t\t┃ ➍ ─ Vender Bebida                 ┃ ➒ ─ Mostrar Dados Bodegueiros    ┃\n");
		System.out.print("\t\t┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		System.out.print("\t\t┃ ➎ ─ Comprar Bebida                ┃ ➓ ─ Fechar Programa.             ┃\n");
		System.out.print("\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\n\t\t\t");
	}

	public Funcionario contrata(){
		String nome, cpf, nasc, cargo;
		double salario;
		if(vrf)
			entrada.nextLine();
		else
			vrf = true;
		System.out.print("Digite o nome do bodegueiro: ");
		nome = entrada.nextLine();
		System.out.print("\nCPF: ");
		cpf = entrada.next();
		System.out.print("\nSalario: ");
		salario = entrada.nextDouble();
		System.out.print("\nCargo: ");
		entrada.nextLine();
		cargo = entrada.nextLine();
		System.out.print("\nData de nascimento: ");
		nasc = entrada.next();
		Funcionario bo = new Funcionario(nome, cpf, nasc, cargo, salario);
		return bo;
	}

	public Bebida cadastraBebida(){
		if(vrf)
			entrada.nextLine();
		else
			vrf = true;
		System.out.print("Digite o nome da bebida: ");
		String nome = entrada.nextLine();
		System.out.print("\nTeor alcoolico: ");
		String teor = entrada.next();
		System.out.print("\nPreço: ");
		double preco = entrada.nextDouble();
		System.out.print("\nQuantidade de ml: ");
		int ml = entrada.nextInt();
		System.out.print("\nQuantidade de bebidas: ");
		int qtd = entrada.nextInt();
		Bebida beb = new Bebida(nome, preco, teor, ml, qtd);
		return beb;
	}

	public Cliente cadastraCliente(){
		String nome, cpf, c;
		boolean fiado = false;
		if(vrf)
			entrada.nextLine();
		else
			vrf = true;
		System.out.print("Digite o nome do Cliente: ");
		nome = entrada.nextLine();
		System.out.print("\nCPF: ");
		cpf = entrada.next();
		System.out.println("Pode comprar fiado? (S/N)");
		c = entrada.next();
		if(c.equals("S"))
			fiado = true;
		else if(c.equals("N"))
			fiado = false;
		Cliente cl = new Cliente(nome, cpf, fiado);
		return cl;
	}

	public void mostraFun(ArrayList<Funcionario> bod){
		for(int i = 0; i < bod.size(); i++){
				Funcionario b = bod.get(i);
			System.out.println("Dados Bodegueiro [" +(i+1)+ "]" + b);
		}
	}

	public void mostraBeb(ArrayList<Bebida> beb){
		for(int i = 0; i < beb.size(); i++){
			Bebida b = beb.get(i);
			System.out.println("Dados Bebida [" +(i+1)+"]" + b);
		}
	}

	public void mostraCli(ArrayList<Cliente> cli){
		for(int i = 0; i < cli.size(); i++){
			Cliente c = cli.get(i);
			System.out.println("Dados Cliente [" +(i+1)+"]" + c);
		}
	}
}