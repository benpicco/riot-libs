Libraries that are not general purpose enough to be included into the RIOT source tree, but still come in handy as a module.

Usage:

	export RIOTLIBS = /path/to/riot-libs

	EXTERNAL_MODULES +=$(RIOTLIBS)
	export EXTERNAL_MODULES

	INCLUDES += -I$(RIOTLIBS)
