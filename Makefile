TOP_MODULE=adapter
BUILD_DIR=obj_dir
# 源代码自动扫描
VERILOG_SRC=$(wildcard ./src/*.v)
CPP_SRC=$(wildcard *.cpp *.hpp)
# Verilog参数设置
VERILOG_FLAGS= --cc --exe -Wall --top-module $(TOP_MODULE)

all: run

# 编译验证Verilog模块
verify: $(VERILOG_SRC)
	verilator $(VERILOG_FLAGS) $(VERILOG_SRC) $(CPP_SRC)
# 构建项目
compile: verify
	make -j -C $(BUILD_DIR) -f V$(TOP_MODULE).mk V$(TOP_MODULE)

# 运行仿真
run: compile png2bmp
	./$(BUILD_DIR)/V$(TOP_MODULE)

# 将从网络获取的png使用py脚本转换为24bit(RGB) bmp
png2bmp: res/lenna.png
	python converter.py ./res/lenna.png


clean:
	rm -rf $(BUILD_DIR)
	rm ./output_lenna.bmp
	rm ./res/lenna.bmp
	rm ./output.bmp
