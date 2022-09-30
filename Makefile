CC=gcc
FLAGS=-Wall -Wpedantic -O2
SRC_DIR=src

SRC+=$(wildcard $(SRC_DIR)/*.c)

INCLUDE+=-I$(SRC_DIR)

BUILD_DIR=build
build-dir:
	mkdir -p $(BUILD_DIR)

TEST_DIR=test
test: build-dir test-lexer

TEST_LEXER=$(BUILD_DIR)/lexer_test
test-lexer: $(TEST_LEXER)

$(TEST_LEXER): $(TEST_DIR)/lexer_test.c $(SRC)
	$(CC) -o $@ $(FLAGS) $< $(INCLUDE)
	./$@ $(TEST_DIR)/lexer_input1.monkey

clean:
	rm -rf $(BUILD_DIR)
