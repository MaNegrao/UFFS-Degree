import javax.swing.JOptionPane;

public class Dialogo{
	public static void main(String[] args){
		String nome = JOptionPane.showInputDialog("Qual é teu nome?");
		JOptionPane.showMessageDialog(null, "Olá " + nome + "!");
	}
}