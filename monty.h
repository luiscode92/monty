#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/**
 * struct global_s - file pointer
 * @fp: file ponter
 * @queue: 0 if LIFO. 1 if FIFO
 */
 typedef struct global_s
 {
         FILE *fp;
         int queue;
 } global_t;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line);
} instruction_t;

extern global_t global;

//int main(int argc, char **argv);
void (*get_opcode(stack_t **stack, char *str, int line))(stack_t **, unsigned int);
void _push(stack_t **stack, unsigned int line);
void error(stack_t **stack, unsigned int line);
void add_node(stack_t **stack, int value);
void add_node_end(stack_t **stack, int value);
void free_all(stack_t **stack);
void _pall(stack_t **stack, unsigned int line);
void _pint(stack_t **stack, unsigned int line);
void _pop(stack_t **stack, unsigned int line);
void _swap(stack_t **stack, unsigned int line);
void _add(stack_t **stack, unsigned int line);
void _nop(stack_t **stack, unsigned int line);

#endif /* MONTY_H */


