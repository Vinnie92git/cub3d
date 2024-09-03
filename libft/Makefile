# name
NAME = libft.a

# sources
SRC =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_calloc.c ft_memchr.c ft_memcmp.c \
		ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
		ft_atoi.c ft_itoa.c \
		ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
		ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_printf.c ft_writechar.c ft_writenbr.c \
		ft_writehex.c ft_writep.c ft_writestr.c ft_writeunbr.c get_next_line.c get_next_line_utils.c

# # # # # #

# flags
AR = ar -rcs

INCLUDE = include/

SRC_PATH = src/*/
SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE)
RM = rm -rf

# colors.
DEF_COLOR = \033[0;39m
CUT = \033[K
R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
GR = \033[30;1m
END = \033[0m

# rules

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(INCLUDE)
	@ar rcs $(NAME) $(OBJS)
	@echo "Library compiled! :D"

clean:
	@$(RM) $(OBJ_PATH)

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GR)Library removed! :D$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
