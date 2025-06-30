default: normal

normal:
	@cd src; \
		g++ -o ../cas *.cpp

verbose:
	@cd src; \
		g++ -o ../cas_verbose *.cpp \
		-DVERBOSE
