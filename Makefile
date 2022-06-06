NAME		=	libqueue.a
NAME_D		=	libqueue_debug.a

AR			=	ar
AR_FLAGS	=	rcs
AR_FLAGS_D	=	rc

CC			=	cc
CC_FLAGS	=	-Wall -Werror -Wextra
CC_FLAGS_D	=	-g

SRCS		=	$(addprefix srcs/,\
					deinit.c empty.c init.c pop.c push.c top.c copy.c)
HEADERS		=	includes/queue.h

OBJS		=	${SRCS:%.c=%.o}
OBJS_D		=	${SRCS:%.c=%_debug.o}

INCLUDES	=	-I includes
RM			=	rm -rf

OS				=	${shell uname -s}

NOCOLOR			=	\033[0m
COLOR_LGREEN	=	\033[92m
COLOR_LYELLOW	=	\033[93m
COLOR_LCYAN		=	\033[96m
NEWLINE			=	\n

%.o			:	%.c $(HEADERS)
				@$(CC) $(INCLUDES) $(CC_FLAGS) -c $< -o $@
				@printf "$(COLOR_LCYAN)build object$(NOCOLOR) [$(COLOR_LGREEN)info$(NOCOLOR)]: "
				@printf "ready $(COLOR_LYELLOW)$@$(NOCOLOR)$(NEWLINE)"

%_debug.o	:	%.c $(HEADERS)
				@$(CC) $(INCLUDES) $(CC_FLAGS) $(CC_FLAGS_D) -c $< -o $@
				@printf "$(COLOR_LCYAN)build object$(NOCOLOR) [$(COLOR_LGREEN)info$(NOCOLOR)]: "
				@printf "ready $(COLOR_LYELLOW)$@$(NOCOLOR)$(NEWLINE)"

.PHONY		:	all debug clean fclean re

all			:	$(NAME)

debug		:	$(NAME_D)

$(NAME)		:	$(OBJS)
				@$(AR) $(AR_FLAGS) $(NAME) $?
				@printf "$(COLOR_LCYAN)ar$(NOCOLOR) [$(COLOR_LGREEN)info$(NOCOLOR)]: "
				@printf "ready $(COLOR_LYELLOW)$(NAME)$(NOCOLOR) for $(COLOR_LYELLOW)$(OS)$(NOCOLOR)$(NEWLINE)"

$(NAME_D)	:	$(OBJS_D)
				@$(AR) $(AR_FLAGS_D) $(NAME_D) $?
				@printf "$(COLOR_LCYAN)ar debug$(NOCOLOR) [$(COLOR_LGREEN)info$(NOCOLOR)]: "
				@printf "ready $(COLOR_LYELLOW)$(NAME_D)$(NOCOLOR) for $(COLOR_LYELLOW)$(OS)$(NOCOLOR)$(NEWLINE)"

clean		:	
				@$(RM) $(OBJS) $(OBJS_D)
				@printf "$(COLOR_LCYAN)$@$(NOCOLOR) [$(COLOR_LGREEN)info$(NOCOLOR)]: "
				@printf "ready $(COLOR_LYELLOW)$(NAME)$(NOCOLOR) for $(COLOR_LYELLOW)$(OS)$(NOCOLOR)$(NEWLINE)"

fclean		:	clean
				@$(RM) $(NAME) $(NAME_D)
				@printf "$(COLOR_LCYAN)$@$(NOCOLOR) [$(COLOR_LGREEN)info$(NOCOLOR)]: "
				@printf "ready $(COLOR_LYELLOW)$(NAME)$(NOCOLOR) for $(COLOR_LYELLOW)$(OS)$(NOCOLOR)$(NEWLINE)"

re			:	fclean all
				@printf "$(COLOR_LCYAN)$@$(NOCOLOR) [$(COLOR_LGREEN)info$(NOCOLOR)]: "
				@printf "ready $(COLOR_LYELLOW)$(NAME)$(NOCOLOR) for $(COLOR_LYELLOW)$(OS)$(NOCOLOR)$(NEWLINE)"

print-%  	: ; @echo $* = $($*)