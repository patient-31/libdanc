/*
 * ________________________________________________________________________________
 * |  File: libdanc.h
 * |  Project: includes
 * |  File Created: Monday, 9th December 2024 06:15 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#ifndef LIBDANC_H
# define LIBDANC_H


# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>
# include <ctype.h>
# include <time.h>
# include <math.h>
# include <unistd.h>


typedef struct s_node {
	void *data;
	struct s_node *next;
} t_node;

/** from s_node.c
 * create node of type t_node for head of linked list */
t_node 	*create_node(void *data);
/** from s_node.c
 * add to front of linked list */
void		insert_front(t_node **head, void *data);
/** from s_node.c
 * remove from front of linked list */
void		delete_front(t_node **head);
/** from s_node.c
 * prints int data only */
void		print_nodes(t_node *head);
/** from s_node.c
 * free all nodes for singly linked list t_node */
void		free_nodes(t_node *head);

typedef struct s_stack {
	t_node *top;
} t_stack;

/** from s_stack.c 
 * create stack type and push first int to top */
t_stack 	*create_stack();
/** from s_stack.c 
 * push int to top of t_stack */
void 		push(t_stack *stack, int data);
/** from s_stack.c 
 * returns data popped off top of stack */
int			pop(t_stack *stack);
/** from s_stack.c 
 * prints int stack */
void 		print_stack(t_stack *stack);
/** from s_stack.c
 * checks top of stack without destroying data 
 * returns INT32_MIN if stack is empty and prints message */
int			stack_peek(t_stack *stack);

typedef unsigned int u32;

#define MEMORY_ALLOCATION_ERROR 12
#define INLINE static inline
#define BUFFER_SIZE 256

/** Definitions for the 32 pattern descriptors in the md number set system */
#define _A		  1
#define	_B		  2
#define	_C		  3
#define	_D		  4
#define	_E		  5
#define	_F		  6
#define	_G		  7
#define	_H		  8
#define	_I		  9
#define	_J		 10
#define	_K		 11
#define	_L		 12
#define	_M		 13
#define	_N		 14
#define	_O		 15
#define	_P		 16
#define	A_		 17
#define	B_		 18
#define	C_		 19
#define	D_		 20
#define	E_		 21
#define	F_		 22
#define	G_		 23
#define	H_		 24
#define	I_		 25
#define	J_		 26
#define	K_		 27
#define	L_		 28
#define	M_		 29
#define	N_		 30
#define	O_		 31
#define	P_		 32

/**
provides evaluation of assertion and debugging notices
*/
#define ASSERT_MSG(cond, msg) assert_msg((cond), (msg), __FILE__, __LINE__)
void assert_msg(int condition, const char *msg, const char *file, int line);

/**
	memoffset can define a register location in memory
	memoffset takes 4 arguments
	1. type - type of pointer
	2. MEM - Designation of Memory Block (for example - MEM_VRAM)
	3. OFFSET - Designation Within Memory Block
	4. index - defines the index for the succeeding offset (index*offset)
	5. offset - Used for register locations that are grouped within 
			the second designation
*/
#define memoffset(type, MEM, OFFSET, index, offset) *((volatile type*)(MEM+OFFSET+(index*offset)))

/**
defines macro for bitsetter function where a list of bit-places in a 32 bit integer to be set,
this allows duplicates but will only set once, can be in any order
*/
#define mask(...) ((u32)bitsetter(0, __VA_ARGS__, -1)) 
u32 bitsetter(u32 result, ...);


typedef struct t_program t_program; // reusable struct
typedef void (*p_cleanup_function)(t_program *);

/// FUNCTION DEFINITIONS ///

void cleanup(t_program *c); // function to be defined by user


/** from error_exit.c
 * cleanup function must be defined with declaration
 * 'void cleanup(t_program *c)'
 * for freeing on exit
*/
void	error_exit(char *mess, int error_type, t_program *strct, p_cleanup_function cleanup);

/** from exit_malloc.c
 * performs error checking and uses ERROR_MEM for exit, cleanup and critical message
*/
void	*exit_malloc(size_t size, t_program *c, char *mess);

/** from error_exit.c 
 * cleanup function must be defined with declaration 
 * 'void cleanup(t_program *c)'
 * for freeing on exit
*/
void	ERROR_MEM(t_program *o, char *mess);

/** from error_exit.c 
 * cleanup function must be defined with declaration 
 * 'void cleanup(t_program *c)'
 * for freeing on exit
*/
void	ERROR_MEM_index(t_program *o, char *mess, int v1, int v2, int v3);

/** from free_2d_char.c 
 * frees 2d character array */
void	free_2d_char(char **f, size_t len);

/** from get_next_line.c
 * returns line from file up to newline character */
char	*get_next_line(int fd);

/** from is_md_val.c
 * returns true if value inputted is valid md value */
bool	is_md_val(char *_x_);

/**from is_whitespace.c
 * returns true if string is all whitespace */ 
bool	is_whitespace(char *s);

/** from itoa.c
 * returns converted integer to character array pointer */
char	*itoa(int n);

/** from itomd.c
 * returns converted integer to character array pointer following md number set system convention
 * if the number is very large, it will take too long */
char	*itomd(int d);

/** from md_val.c
 * returns positive integers only, converts md numbers to there base 10 integer form */
u32		md_val(char *_x_);

/** from lstlen.c
 * returns size of 2d character list */
size_t	lstlen(char **list);

/** from rand_range.c
 * returns random number between l and r */
int		rand_range(int l, int r);

/** from read_file_to_string.c
 *  reads entire file and assigns content to a char pointer */
char	*read_file_to_string(const char *filename);

/** from safe_malloc.c
 * performs error checking and error logging in "error.txt" with graceful NULL returned */
void	*safe_malloc(size_t size, char *mess);

/** from save_to_error_txt.c
 * saves error message to file "error.txt" */
void	save_to_error_txt(char *mess);

/** from numlen.c
 * returns length of positive and negative numbers (includes negative symbol) */
size_t	numlen(int n);

/** from split.c
 * returns pointers to 2d character array split by the delimiter c */
char	**split(char const *s, char c);

/** from str_reverse.c
 * reverses string inputted */
char *str_reverse(char *in);

/** from strjoin_e.c
 * returns pointer to character array of some number(c) of joined strings; */
char	*strjoin_e(size_t c, ...);

/** from tabdup.c
 * duplicates pointers to a 2d character array */
char	**ft_tabdup(char **in);

/** from wordcnt.c
 * dependency of split.c, returns number of words in string based on delimeter c */
size_t	wordcnt(char const *s, char c);

/** from write_string_to_file
 * writes contents to file "filename"
 */
void write_string_to_file(const char *filename, const char *content);

#endif
