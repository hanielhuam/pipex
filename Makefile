CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/bin/libft.a
LDFLAGS = -L${LIBFT_DIR}/bin -lft 
INCLUDE = -Iinclude -I${LIBFT_DIR}/include

SRCS = ${SRC_DIR}/test.c ${SRC_DIR}/manege_pipes.c
	   
OBJS = ${SRCS:${SRC_DIR}/%.c=${OBJ_DIR}/%.o}

NAME = pipex

all: ${NAME}

$(NAME): ${LIBFT} ${OBJS}
	$(CC) ${CFLAGS} ${OBJS} ${LDFLAGS} -o ${NAME}

${OBJ_DIR}/%.o: ${SRC_DIR}/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) ${INCLUDE} -c $< -o $@

${LIBFT}:
	make -C ${LIBFT_DIR}

clean:
	rm -rf ${OBJ_DIR} && make -C ${LIBFT_DIR} clean

fclean: clean
	rm -rf ${NAME} && rm -rf ${LIBFT}

re: fclean all
