package visualiza;

import java.awt.Color;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import controle.*;

public class JanelaDadosEstoque implements ActionListener {

	private JFrame janelaDadsEstoque = new JFrame("Dados do Estoque");
	private JSeparator separa1 = new JSeparator();
	private JSeparator separa2 = new JSeparator();
	
	private JLabel titulo1 = new JLabel("Dados do Estoque/Editar Dados");
	private JLabel labelCateg = new JLabel("Categoria do produto:");
	private JTextField texCateg;
	private JLabel labelNomProd  = new JLabel("Nome do produto:");
	private JTextField texNomProd;
	private JLabel labelQtdForn = new JLabel("Quantidade fornecida:");
	private JTextField texQtdForn;
	private JLabel labelPreco  = new JLabel("Preço da quantidade Fornecida:");
	private JTextField texPreco;
	private JButton btnSalvar = new JButton("Salvar");
	private JButton btnExcluir = new JButton("Excluir");
	private String[] dadosNovos = new String[9];
	private static ControleDado dads;
	private int posicao;
	private int opcao;

	public void VerDadosEditar(int op, ControleDado d, int pos) {

		opcao = op;
		dads = d;
		posicao = pos;

		//Campos do JTexField sendo preenchidos por dados do estoque selecionado
		if (op == 1) {
			texCateg = new JTextField(dads.getEstoques()[pos].getCategoriaProd(), 100);
			texNomProd = new JTextField(dads.getEstoques()[pos].getNomeProd(), 100);
			texQtdForn = new JTextField(String.valueOf(dads.getEstoques()[pos].getQuantidadeFornecida()), 20);
			texPreco = new JTextField(String.valueOf(dads.getEstoques()[pos].getPrecoDaQuantFornecida()), 20);		
		} 
		
		titulo1.setFont(new Font("Microsoft Sans Serif", Font.BOLD, 34));
		labelCateg.setFont(new Font("Microsoft Sans Serif", Font.BOLD, 20));
		labelNomProd.setFont(new Font("Microsoft Sans Serif", Font.BOLD, 20));
		labelQtdForn.setFont(new Font("Microsoft Sans Serif", Font.BOLD, 20));
		labelPreco.setFont(new Font("Microsoft Sans Serif", Font.BOLD, 20));
		btnSalvar.setFont(new Font("Microsoft Sans Serif", Font.BOLD, 17));
		btnExcluir.setFont(new Font("Microsoft Sans Serif", Font.BOLD, 17));
		separa1.setBackground(Color.LIGHT_GRAY);
		separa1.setForeground(Color.BLACK);
		separa2.setBackground(Color.LIGHT_GRAY);
		separa2.setForeground(Color.BLACK);
	
		titulo1.setBounds(78, 10, 616, 56);
		separa1.setBounds(56, 76, 596, 9);
		separa2.setBounds(67, 441, 596, 9);
		labelCateg.setBounds(123, 115, 275, 34);
		texCateg.setBounds(122, 147, 472, 26);
		labelNomProd.setBounds(123, 191, 196, 34);
		texNomProd.setBounds(123, 223, 471, 26);
		labelQtdForn.setBounds(123, 268, 238, 34);
		texQtdForn.setBounds(123, 299, 129, 26);		
		labelPreco.setBounds(125, 342, 317, 34);
		texPreco.setBounds(123, 373, 131, 26);
		btnSalvar.setBounds(480, 471, 97, 40);
		btnExcluir.setBounds(597, 471, 97, 40);

		janelaDadsEstoque.add(titulo1);
		janelaDadsEstoque.add(separa1);
		janelaDadsEstoque.add(separa2);
		janelaDadsEstoque.add(labelCateg);
		janelaDadsEstoque.add(texCateg);
		janelaDadsEstoque.add(labelNomProd);
		janelaDadsEstoque.add(texNomProd);
		janelaDadsEstoque.add(labelQtdForn);
		janelaDadsEstoque.add(texQtdForn);
		janelaDadsEstoque.add(labelPreco);
		janelaDadsEstoque.add(texPreco);
		janelaDadsEstoque.add(btnSalvar);
		janelaDadsEstoque.add(btnExcluir);

		janelaDadsEstoque.setLayout(null);

		janelaDadsEstoque.setBounds(100, 100, 730, 561);
		janelaDadsEstoque.setLocationRelativeTo(null); //para janela ficar centralizada na hora de abrir
		janelaDadsEstoque.setVisible(true);

		btnSalvar.addActionListener(this);
		btnExcluir.addActionListener(this);
	}

	public void actionPerformed(ActionEvent e) {
		Object src = e.getSource();
		if(src == btnSalvar) {
			try {
				boolean truOrFals;
				if(opcao == 1)
					dadosNovos[0] = Integer.toString(posicao); //editar os dados

				dadosNovos[1] =  texCateg.getText();
				dadosNovos[2] =  texNomProd.getText();
				dadosNovos[3] =  texQtdForn.getText();
				dadosNovos[4] =  texPreco.getText();

				//novo valor boolean para o truOrFals
				truOrFals = dads.AdicionarEditarEstoque(dadosNovos);

				if(truOrFals) {
					msgSalvarEstoqueSucesso();
				}
				else msgSalvarEstoqueErro();

			} catch (NullPointerException exc1) {
				msgSalvarEstoqueErro();
			} catch (NumberFormatException exc2) {
				msgSalvarEstoqueErro();
			}
		}

		if(src == btnExcluir) {
			boolean truOrFals = false;

			if (opcao == 1) {
				truOrFals = dads.removerEstoque(posicao); //Exclui dados do estoque
				if (truOrFals) msgExcluirEstoqueSucesso(); 
				else msgExcluirEstoqueErro(); 
			}			
		}
	}

	public void msgExcluirEstoqueSucesso() {
		JOptionPane.showMessageDialog(null, "Os Dados do Estoque Foram Excluidos!" 
				+ "\nDica: Atualize a lista dos estoques para ver as alterações.", null, 
				JOptionPane.INFORMATION_MESSAGE);
		janelaDadsEstoque.dispose();
	}
	
	public void msgExcluirEstoqueErro() {
		JOptionPane.showMessageDialog(null,"Erro ao excluir. "
				+ "\nVerifique se o nome do produto em estoque esta na lista dos estoques atualizada.\n", null, 
				JOptionPane.ERROR_MESSAGE);
	}

	public void msgSalvarEstoqueSucesso() {
		JOptionPane.showMessageDialog(null, "Os Dados do Estoque Foram Salvos!"
				+ "\nDica: Atualize a lista dos estoques para ver as alterações.", null, 
				JOptionPane.INFORMATION_MESSAGE);
		janelaDadsEstoque.dispose();
	}

	public void msgSalvarEstoqueErro() {
		JOptionPane.showMessageDialog(null,"ERRO AO SALVAR OS DADOS!\n "
				+ "Motivos para o erro:  \n"
				+ "1) O campo na caixa de texto esta vazio. \n"
				+ "2) Não foi preenchido de maneira correta em (Quantidade Fornecida e/ou Preço da Quantidade Fornecida), "
				+ "\nambos só podem conter números.", null, 
				JOptionPane.ERROR_MESSAGE);

	}

}


