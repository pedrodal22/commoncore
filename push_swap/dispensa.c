#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Protótipos das funções de operações
void sa(int *stack, int size);
void sb(int *stack, int size);
void ss(int *stack_a, int *stack_b, int size_a, int size_b);
void pa(int *stack_a, int *stack_b, int *size_a, int *size_b);
void pb(int *stack_a, int *stack_b, int *size_a, int *size_b);
void ra(int *stack, int size);
void rb(int *stack, int size);
void rr(int *stack_a, int *stack_b, int size_a, int size_b);
void rra(int *stack, int size);
void rrb(int *stack, int size);
void rrr(int *stack_a, int *stack_b, int size_a, int size_b);

// Funções auxiliares para testes
void print_stack(const char *label, int *stack, int size);
void assert_equal(int *a, int *b, int size, const char *message);

int main() {
    // Teste para a função sa
    int stack_a1[] = {3, 2, 1};
    sa(stack_a1, 3);
    int expected_a1[] = {2, 3, 1};
    assert_equal(stack_a1, expected_a1, 3, "Teste `sa` falhou");

    // Teste para a função sb
    int stack_b1[] = {3, 2, 1};
    sb(stack_b1, 3);
    int expected_b1[] = {2, 3, 1};
    assert_equal(stack_b1, expected_b1, 3, "Teste `sb` falhou");

    // Teste para a função pa
    int stack_a2[] = {3};
    int stack_b2[] = {2, 1};
    int size_a2 = 1, size_b2 = 2;
    pa(stack_a2, stack_b2, &size_a2, &size_b2);
    int expected_a2[] = {2, 3};
    int expected_b2[] = {1};
    assert_equal(stack_a2, expected_a2, size_a2, "Teste `pa` falhou");
    assert_equal(stack_b2, expected_b2, size_b2, "Teste `pa` falhou");

    // Teste para a função pb
    int stack_a3[] = {3, 2};
    int stack_b3[] = {1};
    int size_a3 = 2, size_b3 = 1;
    pb(stack_a3, stack_b3, &size_a3, &size_b3);
    int expected_a3[] = {2};
    int expected_b3[] = {3, 1};
    assert_equal(stack_a3, expected_a3, size_a3, "Teste `pb` falhou");
    assert_equal(stack_b3, expected_b3, size_b3, "Teste `pb` falhou");

    // Outros testes para as funções de rotação e reversão...

    printf("Todos os testes unitários passaram!\n");
    return 0;
}

void print_stack(const char *label, int *stack, int size) {
    printf("%s: [", label);
    for (int i = 0; i < size; i++) {
        printf("%d", stack[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

void assert_equal(int *a, int *b, int size, const char *message) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            printf("%s\n", message);
            print_stack("Esperado", b, size);
            print_stack("Obtido", a, size);
            exit(1);
        }





#include <stdio.h>
#include <stdlib.h>

// Protótipos das funções principais
void push_swap(int *stack_a, int size);

// Funções auxiliares para testes
void assert_sorted(int *stack, int size, const char *message);

int main() {
    int stack1[] = {3, 2, 1};
    int size1 = 3;
    push_swap(stack1, size1);
    assert_sorted(stack1, size1, "Teste `push_swap` falhou para stack1");

    int stack2[] = {5, 1, 4, 2, 3};
    int size2 = 5;
    push_swap(stack2, size2);
    assert_sorted(stack2, size2, "Teste `push_swap` falhou para stack2");

    int stack3[] = {10, 5, 2, 3, 8, 6};
    int size3 = 6;
    push_swap(stack3, size3);
    assert_sorted(stack3, size3, "Teste `push_swap` falhou para stack3");

    printf("Todos os testes de integração passaram!\n");
    return 0;
}

void assert_sorted(int *stack, int size, const char *message) {
    for (int i = 1; i < size; i++) {
        if (stack[i - 1] > stack[i]) {
            printf("%s\n", message);
            exit(1);
        }
    }
}




CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: test_operations test_push_swap

test_operations: test_operations.c operations.c
	$(CC) $(CFLAGS) -o test_operations test_operations.c operations.c
	./test_operations

test_push_swap: test_push_swap.c push_swap.c
	$(CC) $(CFLAGS) -o test_push_swap test_push_swap.c push_swap.c
	./test_push_swap

clean:
	rm -f test_operations test_push_swap

    }
}
