##
## Makefile for Makefile in /home/aubess_t/work/oxo
## 
## Made by au
## Login   <aubess_t@epitech.net>
## 
## Started on  Fri Jan 24 19:41:22 2014 au
## Last update Sat Mar  1 00:18:09 2014 au
##

SRC			= ./src/aff_fct.c \
			  ./src/get_next_line.c \
			  ./src/ia.c \
			  ./src/ia_check_forms.c \
			  ./src/ia_get_empty.c \
			  ./src/ia_play_fct.c \
			  ./src/init_fct.c \
			  ./src/logo.c \
			  ./src/main.c \
			  ./src/my_free.c \
			  ./src/my_malloc.c \
			  ./src/my_usleep.c \
			  ./src/select_fct.c

SRC_LIBMY		= ./lib/libmy/my_atoi.c \
			  ./lib/libmy/my_memset.c \
			  ./lib/libmy/my_putchar.c \
			  ./lib/libmy/my_putnbr.c \
			  ./lib/libmy/my_putstr.c \
			  ./lib/libmy/my_strcat.c \
			  ./lib/libmy/my_strlen.c

SRC_PRINTF		= ./lib/my_printf/epur_printf.c \
			  ./lib/my_printf/fct1.c \
			  ./lib/my_printf/fct2.c \
			  ./lib/my_printf/fct3.c \
			  ./lib/my_printf/fct_l.c \
			  ./lib/my_printf/fill_tab.c \
			  ./lib/my_printf/my_atoi.c \
			  ./lib/my_printf/my_printf.c \
			  ./lib/my_printf/my_putchar.c \
			  ./lib/my_printf/my_putlnbr_base.c \
			  ./lib/my_printf/my_put_lnbr.c \
			  ./lib/my_printf/my_putnbr_base.c \
			  ./lib/my_printf/my_put_nbr.c \
			  ./lib/my_printf/my_putstr.c \
			  ./lib/my_printf/my_putunbr_base.c \
			  ./lib/my_printf/my_strcat.c \
			  ./lib/my_printf/my_strlen.c \
			  ./lib/my_printf/run.c

SRC_LIST_MANAGER	= ./lib/list_manager/list_manager.c \
		  	  ./lib/list_manager/lc.c

OBJ			= $(SRC:.c=.o)
OBJ_LIBMY		= $(SRC_LIBMY:.c=.o)
OBJ_PRINTF		= $(SRC_PRINTF:.c=.o)
OBJ_LIST_MANAGER	= $(SRC_LIST_MANAGER:.c=.o)

NAME			= allum1
NAME_LIBMY		= ./lib/libmy.a
NAME_PRINTF		= ./lib/lib_my_printf.a
NAME_LIST_MANAGER	= ./lib/lib_list_manager.a

LFLAGS			= -l_my_printf -lmy -l_list_manager -L ./lib/

MISC			= ./misc

LOADING			= @$(MISC)/loading

USLEEP			= @$(MISC)/my_usleep

GREEN			= \033[1;32m
CYAN			= \033[0;36m
CYAN_BRIGHT		= \033[1;36m
WHITE			= \033[0m
RED			= \033[1;31m
GREY			= \033[1;37m
HIDDEN			= \033[8m



## #####################################################################
##
## OXO'S RULES
##

all: $(NAME)

$(NAME): cc link

cc: deco_cc $(OBJ_LIBMY) newline $(OBJ_PRINTF) newline2 $(OBJ_LIST_MANAGER) newline3 $(OBJ)
	@echo "$(WHITE)"

link: deco_link
	$(USLEEP)
	@ar rc $(NAME_LIBMY) $(OBJ_LIBMY)
	@ar rc $(NAME_PRINTF) $(OBJ_PRINTF)
	@ar rc $(NAME_LIST_MANAGER) $(OBJ_LIST_MANAGER)
	@cc -o $(NAME) $(OBJ) $(LFLAGS)
	@echo "\n"
	@echo "$(GREEN)\t >\tLIBS & BINARY'S UPDATE : FINISHED\t<\n\n"
	@echo "$(GREY) > Projet développé par :\n"
	@cat $(MISC)/login
	@echo "$(GREY) Copyrigth ©\n"
	@echo "$(WHITE)"

deco_cc:
	$(USLEEP)
	@echo "\n"
	@echo "$(RED) >\tCOMPILATION IN PROGRESS ...\t<\n$(WHITE)"
	$(USLEEP)
	@echo "$(CYAN)"

deco_link:
	$(USLEEP)
	@echo ""
	@echo "$(RED) >\tARCHIVE'S CONTENT TABLE BUILDING & BINARY'S LINKAGE\t<\n"
	$(LOADING)

newline:
	@echo ""
newline2:
	@echo ""
newline3:
	@echo ""

clean:	
	@echo ""
	@echo "$(RED) >\tDELETING .o & TEMPORARY FILES ...\n$(WHITE)"
	@rm -rf $(OBJ) $(OBJ_LIBMY) $(OBJ_PRINTF) $(OBJ_LIST_MANAGER)

fclean: clean
	@echo ""
	$(USLEEP)
	@echo "$(RED) >\tDELETING BINARY ...\n$(WHITE)"
	@rm -rf $(NAME)
	@echo ""
	$(USLEEP)
	@echo "$(RED) >\tDELETING ARCHIVES ...\n$(WHITE)"
	@rm -rf $(NAME_LIBMY) $(NAME_PRINTF) $(NAME_LIST_MANAGER)

re:	fclean all



## #####################################################################
##
## COLOR RULES
##

hidden:
	@echo "$(HIDDEN)"

white:
	@echo "$(WHITE)"



## #####################################################################
##
## MISC' RULES
##

$(MISC):
	@echo "$(GREY)\n\n\n\t\t\t\t > MAKE TOOLS <\n$(WHITE)"
	$(USLEEP)
	@(make -C $(MISC) re)



## #####################################################################
##
## BONUS RULES
##

coffee:
	@echo "$(CYAN_BRIGHT)"
	@cat $(MISC)/$@
	@echo "$(WHITE)"

boobs:
	@echo "$(CYAN_BRIGHT)"
	@cat $(MISC)/$@
	@echo "$(WHITE)"

## #####################################################################
##
## .PHONY
##

.PHONY: all cc link deco_cc deco_link clean fclean re libmy printf tools coffee
