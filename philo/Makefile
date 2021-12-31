NAME		= philo

DEBUG		= philosophers_debug

SRC_FILES	= main.c\
			  utils.c\
			  check.c\
			  init.c\
			  error.c\
			  mutex.c\
			  thread.c\
			  free.c\
			  do_action.c\
			  print_state.c\
			  timestamp.c\
			  is_philo_dead.c\
			  mutex_error.c\
			  ft_atoi.c\
			  ft_calloc.c\

INC_FILES	=	philosophers.h\
				error.h\
				free.h\
				struct.h\
				utils.h\
				is_philo_dead.h\
				print_state.h\
				timestamp.h\

OBJS_DIR	= objs

SRC_DIR		= src

INCLUDE		= ./include

OBJS		= $(addprefix $(OBJS_DIR)/, $(SRC_FILES:.c=.o))

INCS		= $(addprefix $(INCLUDE)/, $(INC_FILES))

CC			= clang

CFLAGS		= -Wall -Wextra -Werror -I$(INCLUDE) -g -pthread #-fsanitize=thread

RM			= rm -rf

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c $(INCS)
			@$(CC) $(CFLAGS) -c $< -o $@


all:		$(NAME)

$(NAME):	$(OBJS)
				@$(CC) $(CFLAGS) -o $@ $^
				@echo "$(NAME) created"

clean:
			@$(RM) $(OBJS)
			@echo "$(NAME) .o deleted"

fclean:		clean
				@$(RM) $(NAME) $(DEBUG)
				@echo "$(NAME) deleted"

re:			fclean all

.PHONY:		all clean fclean re