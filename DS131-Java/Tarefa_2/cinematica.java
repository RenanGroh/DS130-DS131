import java.util.Scanner;

/**
 *
 * Exercico 1 Tarefa 2
 * Aluno: Renan Groh - GRR20250818
 *
 */
public class cinematica {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite a distancia em Km: ");
        double distance = scanner.nextDouble();

        System.out.print("Digite o tempo em horas: ");
        double time = scanner.nextDouble();

        double speed = distance / time;
        System.out.println("A velocidade média é: " + speed + " km/h");
    }
}
