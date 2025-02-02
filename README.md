# 🚦 Projeto Semáforo com Raspberry Pi Pico W

## 📌 Descrição

Este projeto implementa um **semáforo** utilizando a placa **Raspberry Pi Pico W**, controlando **três LEDs (vermelho, amarelo e verde)**. A mudança de estado ocorre a cada **3 segundos**, simulando um semáforo real. O programa utiliza **temporizadores** para alternar automaticamente os LEDs e exibe no terminal a cor do LED atualmente aceso.

## 🎯 Objetivos

- Controlar LEDs para simular um semáforo.
- Usar a função `add_repeating_timer_ms()` do **Pico SDK** para temporização automática.
- Exibir no terminal a cor correspondente ao estado atual do semáforo.
- Manter o código eficiente e estruturado para uso em sistemas embarcados.

## 🛠️ Componentes Utilizados

1. **Microcontrolador:** Raspberry Pi Pico W
2. **LEDs:** 3 (Vermelho, Azul e Verde)
3. **Resistores:** 3 unidades de **330Ω**
4. **Software:**
   - **Linguagem:** C
   - **SDK:** Pico SDK
   - **IDE recomendada:** Visual Studio Code com extensão do Pico SDK

## 📜 Funcionamento

1. **Inicia, após 3 segundos, com o LED vermelho aceso.**
2. **Alterna para o LED amarelo (vermelho e verde) após 3 segundos.**
3. **Alterna para o LED verde após mais 3 segundos.**
4. **O ciclo se repete indefinidamente.**

## 📂 Estrutura do Código

- **Inicialização das GPIOs:** Configura os pinos dos LEDs como saída.
- **Callback do Temporizador:** Alterna os LEDs a cada 3 segundos.
- **Loop Principal:** Mantém o programa rodando e exibe uma mensagem no terminal.

## 📷 Diagrama de Ligações

| LED      | GPIO |
| -------- | ---- |
| Vermelho | 13   |
| Azul  | 12   |
| Verde    | 11   |

Os resistores de **330Ω** devem ser conectados em **série** com cada LED.

## 🎥 Vídeo explicativo

Aqui segue o link de um vídeo que ilustra o funcionamento do código na placa e explica brevemente a estrutura do código:

- **[Link para acessar o vídeo]**