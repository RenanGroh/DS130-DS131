import java.util.Random;

/**
 * 
 * Corrida de sapos
 * 
 * - infinita e 5 sapos. Cada rodada segue a sequencia decrescente.
 * - Em cada jogada o sapo deve pular entre 1 e 5cm, imprimi numero do
 *   pulo, o valor deste salto, o total percorrido.
 * - para pular aleatorio entre 1 e 5 usar rando(5)+1. 
 */
class corrida_sapos extends Thread {

    static int DISTANCIA_TOTAL = 100;
    Random ramdom = new Random();

    public static void main(String[] args) {

        for (int i = 1; i <= 5; i++) {
            int id = i;
            new Thread(() -> {
                int distancia_atual = 0;
                int pulos = 0;



                System.out.println("Thread Lambda #" + id + " rodando!");
            }).start();
        }

    }

}

