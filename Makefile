


TOP_MODULE=adapter
BUILD_DIR=obj_dir

VERILOG_SRC=$(wildcard ./src/*.v)
SYSTEMC_SRC=$(wildcard *.cpp)

VERILOG_FLAGS= --cc --exe -Wall --top-module $(TOP_MODULE)

all: verify compile run


verify: $(VERILOG_SRC)
	verilator $(VERILOG_FLAGS) $(VERILOG_SRC) $(SYSTEMC_SRC)

compile:
	make -j -C $(BUILD_DIR) -f V$(TOP_MODULE).mk V$(TOP_MODULE)

run:
	./$(BUILD_DIR)/V$(TOP_MODULE)

clean:
	rm -rf $(BUILD_DIR)
