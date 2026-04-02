import java.util.Scanner;

/**
 * Classe executável que calcula o faturamento e ganhos com multas
 * de uma vídeo locadora com base na quantidade de DVDs e no valor do aluguel.
 *
 * Exercicio 2 Tarefa 2
 * Aluno: Renan Groh - GRR20250818
 *
 */
public class locadora {

    /**
     * Método principal que executa a leitura dos dados e realiza os cálculos
     * solicitados sobre o faturamento da locadora.
     *
     * @param args Argumentos da linha de comando (não utilizados)
     */
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite a quantidade de DVDs que a locadora possui: ");
        int quantidade = scanner.nextInt();

        System.out.print("Digite o valor cobrado por aluguel: ");
        double valor_aluguel = scanner.nextDouble();

        // a. Um terço dos DVDs são alugados por mês.
        // Usamos 3.0 para forçar a divisão com ponto flutuante e não perder valores decimais
        double dvdsAlugadosPorMes = quantidade / 3.0;
        
        // Faturamento anual = (quantidade de DVDs alugados no mes * valor do aluguel) * 12 meses
        double faturamento_anual = (dvdsAlugadosPorMes * valor_aluguel) * 12;

        // b. Um décimo das fitas alugadas no mês atrasam. Multa de 10% sobre o valor do aluguel.
        double dvdsAtrasadosPorMes = dvdsAlugadosPorMes / 10.0;
        double valorMulta = valor_aluguel * 0.10;
        double ganhoMultasMes = dvdsAtrasadosPorMes * valorMulta;

        // c. Formata a saída para aparecer com duas casas decimais e (R$) na frente
        System.out.printf("Faturamento anual: R$ %.2f\n", faturamento_anual);
        System.out.printf("Ganho com multas por mês: R$ %.2f\n", ganhoMultasMes);
        
        scanner.close();
    }
}
