NAME = libftprintf.a
DIR_SRC = ./src
DIR_BUILD = build
FLAGS = -Wall -Wextra -Werror -I ./

SOURCES		=	format_c.c format_di.c format_p.c format_percent.c format_s.c format_u.c format_x.c ft_printf.c ft_put_long.c ft_put_ulong.c utils.c 
FUNCTIONS	=	$(subst .c,,$(notdir $(SOURCES)))
OBJECTS		=	$(addsuffix .o, $(addprefix $(DIR_BUILD)/, $(FUNCTIONS)))

all: $(NAME)

$(NAME): $(OBJECTS)
	@ar -cr $@ $^

$(DIR_BUILD)/%.o: $(DIR_SRC)/%.c | $(DIR_BUILD)
	@cc $(FLAGS) -c $^ -o $@

$(DIR_BUILD):
	@mkdir $(DIR_BUILD)

so: $(OBJECTS)
	@cc -nostartfiles -shared -o libft.so $(OBJECTS)

test: all ./.test.c
	cc $(FLAGS) -L ./ -lftprintf ./.test.c -o test

clean:
	rm -rf $(DIR_BUILD)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_SO)

re: fclean all
