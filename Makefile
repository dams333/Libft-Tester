# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhubleur <dhubleur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 10:05:58 by dhubleur          #+#    #+#              #
#    Updated: 2022/01/27 11:08:01 by dhubleur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#								  Utils										   #
################################################################################

NAME		= 	LibftTester
CC			= 	gcc
CFLAGS		=

RUN_PARAM	=	

################################################################################
#								  Sources									   #
################################################################################

SRCS_EXTENSION	=	.c
SRCS_PATH		=	./srcs
MAIN			=	main.c
SRCS			=	isalpha.c \
					isdigit.c \
					isalnum.c \
					isascii.c \
					isprint.c \
					strlen.c \
					memset.c \
					bzero.c \
					memcpy.c \
					atoi.c \
					itoa.c \
					putnbr.c \
					split.c \
					join.c \
					putchar.c \
					putstr.c \
					putendl.c \
					strdup.c

################################################################################
#								  Includes									   #
################################################################################

INCLUDE_DIRS		=	./includes

################################################################################
#								  Libft										   #
################################################################################

IS_LIBFT			=	true

LIBFT_DIR			=	..
LIBFT_INCLUDE_DIR	=	..
LIBFT_NAME			=	libft.a

################################################################################
#								  LibUnit									   #
################################################################################

IS_UNIT				=	true

UNIT_DIR			=	./lib-unit
UNIT_INCLUDE_DIR	=	./lib-unit/includes
UNIT_NAME			=	libunit.a

#               /!\ Do not touch the rest of the file /!\ 

################################################################################
#								  Objects									   #
################################################################################

OBJS_PATH		=	./objs

OBJS			=	$(addprefix $(OBJS_PATH)/, ${SRCS:$(SRCS_EXTENSION)=.o})
OBJ_MAIN		=	$(addprefix $(OBJS_PATH)/, ${MAIN:$(SRCS_EXTENSION)=.o})
OBJS_DEPEND		=	$(addprefix $(OBJS_PATH)/, ${SRCS:$(SRCS_EXTENSION)=.d})
OBJ_MAIN_DEPEND	=	$(addprefix $(OBJS_PATH)/, ${MAIN:$(SRCS_EXTENSION)=.d})

################################################################################
#								  Constants									   #
################################################################################

BLUE		=	\033[1;34m
CYAN		=	\033[0;36m
GREEN		=	\033[0;32m
ORANGE  	=	\033[0;33m
NO_COLOR	=	\033[m

################################################################################
#								  Makefile									   #
################################################################################

INCLUDE_FLAGS 	=	$(addprefix -I , ${INCLUDE_DIRS})

LIBFT_COMPLETE	=	$(LIBFT_DIR)/${LIBFT_NAME}
UNIT_COMPLETE	=	$(UNIT_DIR)/${UNIT_NAME}

INCLUDE_FLAGS	+=	$(addprefix -I , ${LIBFT_INCLUDE_DIR})
ALL_LIBS		+=	$(LIBFT_COMPLETE)

INCLUDE_FLAGS	+=	$(addprefix -I , ${UNIT_INCLUDE_DIR})
ALL_LIBS		+=	$(UNIT_COMPLETE)

ifeq (noflag, $(filter noflag,$(MAKECMDGOALS)))
	CFLAGS	+=	-Wall -Wextra
else
	CFLAGS	+=	-Wall -Wextra -Werror
endif
ifeq (debug, $(filter debug,$(MAKECMDGOALS)))
	CFLAGS	+=	-g3
endif
ifeq (sanadd, $(filter sanadd,$(MAKECMDGOALS)))
	CFLAGS	+=	-fsanitize=address
endif
ifeq (santhread, $(filter santhread,$(MAKECMDGOALS)))
	CFLAGS	+=	-fsanitize=thread
endif

################################################################################
#								  Rules										   #
################################################################################

all:	header message $(NAME)

#beautiful
header:
		@echo -n "${BLUE}"
		@echo "  _  _ ___                    _         __ _ _      "
		@echo " | || |__ \                  | |       / _(_) |     "
		@echo " | || |_ ) |  _ __ ___   __ _| | _____| |_ _| | ___ "
		@echo " |__   _/ /  | '_ \` _ \ / _\` | |/ / _ \  _| | |/ _ \\"
		@echo "    | |/ /_  | | | | | | (_| |   <  __/ | | | |  __/"
		@echo "    |_|____| |_| |_| |_|\__,_|_|\_\___|_| |_|_|\___|"
		@echo "                                         by dhubleur"
		@echo -n "${NO_COLOR}"

message:
		@make -q $(NAME) && echo "$(GREEN)Everything is already up to date ! No work for me$(NO_COLOR)" || true

#Compilation
$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%$(SRCS_EXTENSION)
			@mkdir -p $(dir $@)
			@echo "$(CYAN)Compiling $(BLUE)$@ ...$(NO_COLOR)"
			@$(CC) $(CFLAGS) -MMD -MF $(@:.o=.d)  ${INCLUDE_FLAGS} -c $< -o $@
$(OBJS_PATH)/%.o:	%$(SRCS_EXTENSION)
			@mkdir -p $(dir $@)
			@echo "$(CYAN)Compiling $(BLUE)$@ ...$(NO_COLOR)"
			@$(CC) $(CFLAGS) -MMD -MF $(@:.o=.d)  ${INCLUDE_FLAGS} -c $< -o $@

$(LIBFT_COMPLETE):
			@make -C $(LIBFT_DIR) all
			@echo "$(GREEN)Compiled libft !$(NO_COLOR)"
$(UNIT_COMPLETE):
			@make -C $(UNIT_DIR) all
			@echo "$(GREEN)Compiled lib-unit !$(NO_COLOR)"
			
#Link
-include $(OBJS_DEPEND) $(OBJ_MAIN_DEPEND)
$(NAME):	${OBJS} ${OBJ_MAIN} ${ALL_LIBS}
		@echo "$(ORANGE)Linking $(BLUE)$@ ...$(NO_COLOR)"
		@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -o $@ ${OBJS} ${OBJ_MAIN} ${ALL_LIBS} -ldl -rdynamic
		@echo "$(GREEN)$@ created !$(NO_COLOR)"

#clean
clean:		header
		@rm -rf $(OBJS_PATH)
		@echo "$(GREEN)Removed objects !$(NO_COLOR)"

fclean:		header clean
		@rm -f $(NAME)
		@echo "$(GREEN)Removed $(NAME) !$(NO_COLOR)"

fcleanlib:	header fclean
ifeq ($(IS_LIBFT),true)
		make -C $(LIBFT_DIR) fclean
endif
ifeq ($(IS_UNIT),true)
		make -C $(UNIT_DIR) fclean
endif

re:			header fclean all

relib:		header fcleanlib all

#test
run:		header all
		@echo "$(BLUE)Executing...$(NO_COLOR)"
		@echo ""
		@./$(NAME) $(RUN_PARAM)

show:		header
		@echo "$(CYAN)Compilator: $(GREEN)$(CC)$(NO_COLOR)"
		@echo "$(CYAN)Flags: $(GREEN)$(CFLAGS)$(NO_COLOR)"
		@echo "$(CYAN)Includes: $(GREEN)$(INCLUDE_FLAGS)$(NO_COLOR)"
		@echo ""
		@echo "$(CYAN)Sources:$(NO_COLOR)"
		@echo "$(GREEN)$(MAIN) ${addprefix $(SRCS_PATH)/, $(SRCS)}$(NO_COLOR)"
		@echo ""
		@echo "$(CYAN)Libs:$(NO_COLOR)"
		@echo "$(GREEN)$(ALL_LIBS)$(NO_COLOR)"

#do nothing
noflag: 	all
		@echo -n ""
debug:		all
		@echo -n ""
sanadd:		all
		@echo -n ""
santhread:	all
		@echo -n ""
		
.PHONY:		all header clean fclean re run fcleanlib relib noflag debug sanadd santhread show