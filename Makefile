USER = ssp

install:
	git submodule update --init --recursive
	rm -rf vial-qmk/keyboards
	ln -s $(shell pwd)/keyboards vial-qmk/keyboards

build:
	mkdir $(shell pwd)/.build
	cd vial-qmk; make BUILD_DIR=$(shell pwd)/.build $(kb)/$(USER):$(km):

	# # run lint check
	# cd vial-qmk; qmk lint -km $(USER) -kb $(PATH_$@) --strict

	# # run build
	# make BUILD_DIR=$(shell pwd) -j1 -C qmk_firmware $(PATH_$@):$(USER)

	# # cleanup symlinks
	# for f in $(KEYBOARDS); do rm -rf qmk_firmware/keyboards/$(PATH_$@)/keymaps/$(USER); done
	# rm -rf qmk_firmware/users/$(USER)

clean:
	rm -rf $(shell pwd)/.build
