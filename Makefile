
# Makefile - Compiler Tester
# version 0.1.1
#
# (C) 2021 Pedro Rodrigues <pedror@student.dei.uc.pt>
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy 
# of this software and associated documentation files (the “Software”), to deal 
# in the Software without restriction, including without limitation the rights 
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell 
# copies of the Software, and to permit persons to whom the Software is furnished 
# to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all 
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL 
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
# DEALINGS IN THE SOFTWARE.

########################### GENERAL CONFIGURATIONS ############################

# Build Toolchain
CC   := clang-14
LEX  := flex
YACC := yacc
LLC  := llc-14

# Other Tools
DIFF := diff
ZIP  := zip
VALGRIND := valgrind

# Target Executable Name
TARGET_NAME := jucompiler

# Project Base Directories
SRC_DIR   := src
BUILD_DIR := bin
TESTS_DIR := tests

# `make test` rule default flag values
DIR  := meta3
FLAG := s

# File Extensions
TEST_LOG_FILE := $(TARGET_NAME)_tests.log
VALGRIND_LOG_FILE := $(TARGET_NAME)_leaks.log

############################### PROGRAM FLAGS #################################

# Lex && Yacc (Bison) Flags
LEX_FLAGS  := 
YACC_FLAGS := -d -Wno-yacc

# CC Flags
CFLAGS 	:= -O3 -g
LDFLAGS :=

# Other Tools Flags
DIFF_FLAGS  := -y # --suppress-common-lines
VALGRIND_FLAGS :=  --errors-for-leak-kinds=all --leak-check=full \
		--show-leak-kinds=all --track-origins=yes

#################################### MISC #####################################

# Terminal Colors and Fonts Weights
ifneq (,$(findstring xterm,${TERM}))
	RED     := $(shell tput -Txterm setaf 1)
	GREEN   := $(shell tput -Txterm setaf 2)
	BLUE    := $(shell tput -Txterm setaf 6)
	RESET   := $(shell tput -Txterm sgr0)
	BOLD    := $(shell tput bold)
	NORM    := $(shell tput sgr0)
else
	RED     := ""
	GREEN   := ""
	BLUE    := ""
	RESET   := ""
	BOLD 	:= ""
	NORM 	:= ""
endif

############################### RULES #######################################

.PHONY: all clean zip build lex yacc test help leak-checks check
all: build 

check: test leak-checks

help:
	@echo "make" 
	@echo "make clean " 
	@echo "make zip"
	@echo "make test DIR=... FLAG=...";

require: 
	@echo "$(BLUE)$(BOLD)Checking requirements...$(NORM)$(RESET)"
	@fail=0; \
	for req in $(CC) $(LEX) $(YACC) $(LLC) $(DIFF) $(VALGRIND); do \
	if ! type $$req > /dev/null 2>&1; then \
			echo "$(RED)$(BOLD)ERROR:" $$req "is required.$(NORM)$(RESET)"; \
			fail=1; \
		fi \
	done; \
	[ $$fail -eq 0 ] || exit 1;
	@echo "$(GREEN)$(BOLD)Requirements Satisfied!$(NORM)$(RESET)"

build: require lex yacc  
	@echo "$(BLUE)$(BOLD)Building $(TARGET_NAME)...$(NORM)$(RESET)"
	@$(MAKE) -s --no-print-directory $(BUILD_DIR)/$(TARGET_NAME)
	@echo "$(GREEN)$(BOLD)Build Complete!$(NORM)$(RESET)"

clean:
	@echo "$(BLUE)$(BOLD)Cleaning...$(NORM)$(RESET)"
	@rm -rf $(BUILD_DIR)
	@rm -rf $(TEST_LOG_FILE)
	@rm -rf $(VALGRIND_LOG_FILE)
	@rm -rf $(SRC_DIR)/lex.yy.c $(SRC_DIR)/y.tab.*
	@rm -rf $(TARGET_NAME).zip
	@echo "$(GREEN)$(BOLD)All clean!$(NORM)$(RESET)"

zip: 
	@echo "$(GREEN)$(BOLD)Compressing $(SRC_DIR) directory...$(NORM)$(RESET)"
	@$(ZIP) $(TARGET_NAME).zip \
		-x $(SRC_DIR)/lex.yy.c $(SRC_DIR)/y.tab.* \
		-r -j $(SRC_DIR)
	@echo "$(BOLD)$(GREEN)Done!$(NORM)$(RESET)"

lex: $(shell find $(SRC_DIR) -type f -name '$(TARGET_NAME).l')
	@if [ $< ]; then \
		echo  "$(BLUE)$(BOLD)Compiling $< $(NORM)$(RESET)"; \
		$(LEX) $(LEX_FLAGS) -o $(SRC_DIR)/lex.yy.c $<; \
	fi

yacc: $(shell find $(SRC_DIR) -type f -name '$(TARGET_NAME).y')
	@if [ $< ]; then \
		echo  "$(BLUE)$(BOLD)Compiling $< $(NORM)$(RESET)"; \
		$(YACC) $(YACC_FLAGS) -o $(SRC_DIR)/y.tab.c $<; \
	fi

$(BUILD_DIR)/$(TARGET_NAME): $(wildcard $(SRC_DIR)/*.c)
	@if [ "$^" ]; then \
		mkdir -p $(dir $@); \
		echo  "$(BLUE)$(BOLD)Compiling $^ $(NORM)$(RESET)"; \
		$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS); \
	fi


test:  
	@touch $(BUILD_DIR)/$(TARGET_NAME) 2> /dev/null || \
		$(MAKE) -s --no-print-directory build
	@echo  "$(BLUE)$(BOLD)Running Tests...$(NORM)$(RESET)"
	@echo  "$(BOLD) Y/N |     STATUS    |          FILE    		  "
	@echo  "---------------------------------------------$(NORM)"
	@comp_out=$$(mktemp -t COMP.OXXXXXXXXX); \
	diff_out=$$(mktemp -t COMP.DXXXXXXXXX); \
	llc_out=$$(mktemp -t COMP.LXXXXXXXXX.s); \
	exec=$$(mktemp -t COMP.EXXXXXXXXX); \
	rm -f $(TEST_LOG_FILE); \
	for t in $$(find $(TESTS_DIR)/$(DIR) -type f -not -name "*.out"); do \
		out=$${t%.*}.out; \
		touch $$out 2> /dev/null || continue; \
		./$(BUILD_DIR)/$(TARGET_NAME) -$(FLAG) < $$t > $$comp_out; \
		if [ ! $(FLAG) ]; then \
			$(LLC) $$comp_out -o $$llc_out; \
			$(CC) $$llc_out -o $$exec; \
		  $$exec > $$comp_out; \
		fi; \
		$(DIFF) $(DIFF_FLAGS) $$comp_out $$out > $$diff_out; \
		if [ $$? -eq 0 ]; then \
      echo  " " ✅" $(BOLD)| $(GREEN)TEST PASSED!!$(RESET) $(BOLD)|$(NORM)" \
				$$(basename $$t) ; \
    else \
      echo  " " ❌" $(BOLD)| ${RED}TEST FAILED!!${RESET} $(BOLD)|$(NORM)" \
				$$(basename $$t) ; \
			echo "================== $${t} DIFF OUTPUT ==================" \
				>> $(TEST_LOG_FILE); \
			cat $$diff_out >> $(TEST_LOG_FILE); \
		fi; \
	done; \
	rm -f $$comp_out $$diff_out $$llc_out $$exec; \
	echo  "$(GREEN)$(BOLD)Done!$(NORM)$(RESET)";\

leak-checks:
	@touch $(BUILD_DIR)/$(TARGET_NAME) 2> /dev/null || \
		$(MAKE) -s --no-print-directory build
	@echo  "$(BLUE)$(BOLD)Running Leak Checks...$(NORM)$(RESET)"
	@echo  "$(BOLD) Y/N |    STATUS     |          FILE    		  "
	@echo  "---------------------------------------------$(NORM)"
	@val_out=$$(mktemp -t COMP.VXXXXXXXXX); \
	rm -f $(VALGRIND_LOG_FILE); \
	for t in $$(find $(TESTS_DIR)/$(DIR) -type f -not -name "*.out"); do \
		out=$${t%.*}.out; \
		touch $$out 2> /dev/null || continue; \
		$(VALGRIND)  $(VALGRIND_FLAGS) --error-exitcode=1 \
			./$(BUILD_DIR)/$(TARGET_NAME) -$(FLAG) < $$t > $$val_out 2>&1 /dev/null; \
		if [ $$? -eq 0 ]; then \
      echo  " " ✅" $(BOLD)| $(GREEN)    OK!! $(RESET)     $(BOLD)|$(NORM)"\
				$$(basename $$t) ; \
    else \
      echo  " " ❌" $(BOLD)| ${RED}  LEAKING!!${RESET}   $(BOLD)|$(NORM)" \
				$$(basename $$t) ; \
			echo "================== $${t} VALGRIND OUTPUT ==================" \
				>> $(VALGRIND_LOG_FILE); \
			cat $$val_out >> $(VALGRIND_LOG_FILE); \
		fi; \
	done; \
	rm -rf $$val_out; \
	echo  "$(GREEN)$(BOLD)Done!$(NORM)$(RESET)";\
