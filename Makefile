CC= cc 
CFLAGS= -Wall -Wextra -Werror
NAME= client
BNAME= client_bonus
SNAME= server
BSNAME= server_bonus

SRC= Mandatory/client.c \
	Mandatory/ft_printf_ft.c \
	Mandatory/ft_printf.c
BSRC= bonus/client.c \
	bonus/ft_printf_ft.c \
	bonus/ft_printf.c

SSRC= Mandatory/ft_printf_ft.c \
	Mandatory/ft_printf.c \
	Mandatory/server.c

BSSRC= bonus/ft_printf_ft.c \
	bonus/ft_printf.c \
	bonus/server.c

OBJ= $(SRC:.c=.o)
SOBJ= $(SSRC:.c=.o)

BOBJ= $(BSRC:.c=.o)
BSOBJ= $(BSSRC:.c=.o)

all: $(NAME) $(SNAME)

$(NAME) : $(OBJ) Mandatory/minitalk.h
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(SNAME) : $(SOBJ) Mandatory/minitalk.h
	@$(CC) $(CFLAGS) $(SOBJ) -o $(SNAME)

bonus: $(BNAME) $(BSNAME)
	@touch bonus

$(BNAME) : $(BOBJ) bonus/minitalk.h
	$(CC) $(CFLAGS) $(BOBJ) -o $(BNAME)

$(BSNAME) : $(BSOBJ) bonus/minitalk.h
	$(CC) $(CFLAGS) $(BSOBJ) -o $(BSNAME)

clean: 
	@-rm -f $(OBJ) $(SOBJ) $(BOBJ) $(BSOBJ)

fclean: clean
	@-rm -f $(OBJ) $(NAME) $(SNAME) $(BNAME) $(BSNAME)

re: fclean all

.PHONY: re fclean clean all