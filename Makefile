
install:
	git submodule update --init --recursive
	rm -rf vial-qmk/keyboards
	ln -s $(shell pwd)/keyboards vial-qmk/keyboards

build:
	if [ ! -d "$(shell pwd)/.build" ]; then mkdir $(shell pwd)/.build; fi
	cd vial-qmk; make BUILD_DIR=$(shell pwd)/.build $(kb):$(km):

clean:
	rm -rf $(shell pwd)/.build
