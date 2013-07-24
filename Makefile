ifneq (,$(findstring cunit,$(USEMODULE)))
	DIRS += cunit
endif
ifneq (,$(findstring regex,$(USEMODULE)))
	DIRS += regex
endif
ifneq (,$(findstring compat_misc,$(USEMODULE)))
	DIRS += compat_misc
endif
ifneq (,$(findstring print_malloc,$(USEMODULE)))
	DIRS += print_malloc
endif

all:
	mkdir -p $(BINDIR)
	@for i in $(DIRS) ; do $(MAKE) -C $$i ; done ;

clean:
	@for i in $(DIRS) ; do $(MAKE) -C $$i clean ; done ;
	@if [ -d $(BINDIR) ] ; \
	then rmdir --ignore-fail-on-non-empty $(BINDIR) ; \
	fi
