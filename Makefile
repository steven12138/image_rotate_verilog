


TOP_MODULE=adapter
BUILD_DIR=obj_dir

VERILOG_SRC=$(wildcard ./src/*.v)
CPP_SRC=$(wildcard *.cpp *.hpp)

VERILOG_FLAGS= --cc --exe -Wall --top-module $(TOP_MODULE)

all: run

verify: $(VERILOG_SRC)
	verilator $(VERILOG_FLAGS) $(VERILOG_SRC) $(CPP_SRC)

compile: verify
	make -j -C $(BUILD_DIR) -f V$(TOP_MODULE).mk V$(TOP_MODULE)

run: compile png2bmp
	./$(BUILD_DIR)/V$(TOP_MODULE)

png2bmp: res/lenna.png
	python converter.py ./res/lenna.png


clean:
	rm -rf $(BUILD_DIR)
	rm ./output_lenna.bmp
	rm ./res/lenna.bmp
	rm ./output.bmp
