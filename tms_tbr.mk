# TMS Makefile for Tibero
# HP 64bit

TBLIBDIR = $(TB_HOME)/client/lib
TBLIB =-ltbxa -ltbertl -ltbcli -lpthread -ltbs -lm 
#TBLIB = -ltbxas -ltbxa -ltbertl -ltbcli -lm -lpthread 
#TBLIB = -ltbs -ltbertl -ltbcli -lm -lpthread 

TARGET  = tms_tbr
APOBJ   = dumy.o
#APOBJ   = dumy.o db_stub.o

APPDIR  = $(TMAXDIR)/appbin
TMAXLIBD= $(TMAXDIR)/lib64
TMAXLIBS= -ltms -ltbs
TMAXINC = -I$(TMAXDIR)
#CFLAGS  =  -m32
SYSLIBS =

all : $(TARGET)

$(TARGET): $(APOBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(TMAXINC) -L$(TMAXLIBD) $(TMAXLIBS) $(APOBJ) -L$(TBLIBDIR) $(TBLIB) $(SYSLIBS)
	mv $(TARGET) $(APPDIR)/

$(APOBJ):
	$(CC) $(CFLAGS) $(LDFLAGS) -c dumy.c
#	$(CC) $(CFLAGS) $(LDFLAGS) $(TMAXINC) -c db_stub.c

clean:
	-rm -f *.o core $(APPDIR)/$(TARGET)

