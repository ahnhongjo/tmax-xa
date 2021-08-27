all:
	tbpc bank_svr.tbc
	tbpc bank_rec.tbc
	gcc -O -I$(TMAXDIR) -o bank_client bank_client.c -L$(TMAXDIR)/lib64 -lcli -lnsl
	gcc -O -o bank_svr -I$(TMAXDIR) -I$(TB_HOME)/client/include -L$(TMAXDIR)/lib64 -L$(TB_HOME)/client/lib bank_svr.c $(TMAXDIR)/svct/bank_svr_svctab.c $(TMAXDIR)/lib64/sdl.o -lsvr -ltbs -ltbxa -ltbertl -ltbcli -lm -lpthread -lnodb
	gcc -O -o bank_rec -I$(TMAXDIR) -I$(TB_HOME)/client/include -L$(TMAXDIR)/lib64 -L$(TB_HOME)/client/lib bank_rec.c $(TMAXDIR)/svct/bank_rec_svctab.c $(TMAXDIR)/lib64/sdl.o -lsvr -ltbs -ltbxa -ltbertl -ltbcli -lm -lpthread -lnodb
	cp bank_svr $(TMAXDIR)/appbin
	cp bank_rec $(TMAXDIR)/appbin
clean:
	rm -f bank_client bank_client.o bank_svr.o bank_svr
