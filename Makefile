# var
MODULE = $(notdir $(CURDIR))
REL    = $(shell git rev-parse --short=4    HEAD)
BRANCH = $(shell git rev-parse --abbrev-ref HEAD)
NOW    = $(shell date +%d%m%y)

# version

# cross
TARGET = thumbv7m-none-eabi

# dir
CWD   = $(CURDIR)
TMP   = $(CWD)/tmp
REF   = $(CWD)/ref
GZ    = $(HOME)/gz
MOUNT = $(TMP)/mount

# tool
CURL   = curl -L -o
CF     = clang-format -style=file -i
GITREF = git clone --depth 1

# src
C += $(wildcard src/*.c*)
H += $(wildcard inc/*.h*)

# cfg
CFLAGS += -Iinc -Itmp
CFLAGS += $(shell pkg-config fuse --cflags)

# libs
L += $(shell pkg-config fuse --libs)

# all
.PHONY: run all
all: bin/$(MODULE)
run: bin/$(MODULE)
	$(MAKE) testfs &
	mkdir -p tmp/mount
	bin/$(MODULE) -d -s tmp/mount 2> tmp/$(MODULE).log

.PHONY: testfs
testfs:
	sleep 1 ; ls -la tmp/mount ; umount tmp/mount

# format
.PHONY: format
format: tmp/format_cpp
tmp/format_cpp: $(C) $(H)
	$(CF) $? && touch $@

# rule
bin/$(MODULE): $(C) $(H)
	$(CXX) $(CFLAGS) -o $@ $(C) $(L)

# doc
.PHONY: doc
doc:

.PHONY: doxy
doxy: .doxygen
	rm -rf docs ; doxygen $< 

# install
.PHONY: install update ref gz
install: doc ref gz
	$(MAKE) rust update
update:
	sudo apt update
	sudo apt install -uy `cat apt.txt`
ref:
gz:

# merge
MERGE += Makefile README.md apt.txt LICENSE
MERGE += .clang-format .doxygen .gitignore
MERGE += .vscode bin doc lib inc src tmp ref

.PHONY: dev
dev:
	git push -v
	git checkout $@
	git pull -v
	git checkout shadow -- $(MERGE)

.PHONY: shadow
shadow:
	git push -v
	git checkout $@
	git pull -v

.PHONY: release
release:
	git tag $(NOW)-$(REL)
	git push -v --tags
	$(MAKE) shadow

.PHONY: zip
zip:
	git archive \
		--format zip \
		--output $(TMP)/$(MODULE)_$(NOW)_$(REL).src.zip \
	HEAD
