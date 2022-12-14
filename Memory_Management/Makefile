SUBDIRS = $(shell ls -d */)
all:
	for dir in $(SUBDIRS) ; do \
		make clean -C  $$dir ; \
    done
