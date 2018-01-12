# Default qmake
QMAKE=$(shell command -v qmake)

# On Fedora and other systems the binary has a different name
# QT5 is preferred
ifeq "$(QMAKE)" ""
	QMAKE=$(shell command -v qmake-qt5)
endif

# QT4
ifeq "$(QMAKE)" ""
	QMAKE=$(shell command -v qmake-qt4)
endif


# Build directory
BUILD_DIR=build

.ONESHELL:
all:
ifeq "$(QMAKE)" ""
	$(error "qmake is not installed")
else
	echo "found qmake: $(QMAKE)"
endif

	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR)
	$(QMAKE) -makefile ..
	$(MAKE) clean all
