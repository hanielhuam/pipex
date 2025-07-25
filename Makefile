CC = cc
CFLAGS = -Wall -Wextra -Werror -g
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/bin/libft.a
LDFLAGS = -L${LIBFT_DIR}/bin -lft 
INCLUDE = -Iinclude -I${LIBFT_DIR}/include

SRCS = ${SRC_DIR}/pipex.c ${SRC_DIR}/create_comand_chain.c \
	   ${SRC_DIR}/extract_file.c ${SRC_DIR}/clear_struct.c \
	   ${SRC_DIR}/extract_comands.c ${SRC_DIR}/extract_path.c \
	   ${SRC_DIR}/validate_config_chain.c ${SRC_DIR}/file_manager.c \
	   ${SRC_DIR}/here_doc_handler.c ${SRC_DIR}/finish_program.c \
	   ${SRC_DIR}/pipe_maneger.c ${SRC_DIR}/process_comand_chain.c

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
