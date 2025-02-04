#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos dos LEDs
#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13

// Variável para controlar o estado do semáforo
int estado = 0;

// Função para inicializar as GPIOs
void init_gpio() {
    gpio_init(LED_GREEN);
    gpio_init(LED_BLUE);
    gpio_init(LED_RED);

    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
    gpio_set_dir(LED_RED, GPIO_OUT);
}

// Callback do temporizador - Alterna os LEDs
bool semaforo_callback(repeating_timer_t *rt) {
    // Desliga todos os LEDs
    gpio_put(LED_GREEN, 0);
    gpio_put(LED_BLUE, 0);
    gpio_put(LED_RED, 0);

    // Muda o estado do semáforo
    if (estado == 0) {
        gpio_put(LED_RED, 1); // Liga o LED vermelho
    } else if (estado == 1) {
        gpio_put(LED_BLUE, 1); // Liga o LED azul (simboliza o amarelo)
    } else if (estado == 2) {
        gpio_put(LED_GREEN, 1); // Liga o LED verde
    }

    // Atualiza o estado para a próxima transição
    estado = (estado + 1) % 3;
    return true; // Mantém o temporizador ativo
}

int main() {
    stdio_init_all();
    init_gpio();

    repeating_timer_t timer;
    // Adiciona o temporizador para alterar os LEDs a cada 3000ms (3 segundos)
    add_repeating_timer_ms(3000, semaforo_callback, NULL, &timer);

    while (true) {
        sleep_ms(3000); // Espera 3 segundos para indicar a cor no terminal
        if (estado == 1) {
            printf("Semáforo: Vermelho\n");
        } else if (estado == 2) {
            printf("Semáforo: Amarelo\n");
        } else if (estado == 0) {
            printf("Semáforo: Verde\n");
        }
    }
}