SUBDIRS = $(shell ls -d */)
clean:
	for dir in $(SUBDIRS) ; do \
		make clean -C  $$dir ; \
    done
