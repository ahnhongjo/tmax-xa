*DOMAIN
bank
    SHMKEY = 95039, MAXUSER = 256, MINCLH = 1,
    MAXCLH = 1, BLOCKTIME = 15, MAXCPC = 256,
    MAXSPR = 512, MAXSVR = 128, MAXSVC = 512,
    DOMAINID = 4, IPCPERM = 0777, MAXSACALL = 1024, MAXCACALL  = 1024
    
*NODE
DEFAULT:
    HOSTNAME = "hongjo",
    DOMAINNAME = "bank"
bank1
    TMAXHOME = "/home/hongjo/OF71/OHOME/tmax",
    TMAXDIR = "/home/hongjo/OF71/OHOME/tmax",
    APPDIR  = "/home/hongjo/OF71/OHOME/tmax/appbin",
    TLOGDIR = "/home/hongjo/OF71/OHOME/tmax/log/tlog",
    ULOGDIR = "/home/hongjo/OF71/OHOME/tmax/log/ulog",
    SLOGDIR = "/home/hongjo/OF71/OHOME/tmax/log/slog",
    TPORTNO = 8573, SHMKEY = 95039, RACPORT = 9450
    
*SVRGROUP
svg_domain  NODENAME = "bank1", DBNAME = TIBERO,
            OPENINFO = "TIBERO_XA:user=hongjo,pwd=hongjo,sestm=60,Loose_Coupling=true,db=tb_fix3",
            TMSNAME =tms_tbr

svg_domain2  NODENAME = "bank1", DBNAME = TIBERO,
             OPENINFO = "TIBERO_XA:user=1111,pwd=1111,sestm=60,Loose_Coupling=true,db=tb_fix3",
             TMSNAME =tms_tbr
	    

*SERVER
bank_svr        SVGNAME = svg_domain,  CLOPT ="-- -f aa -x bb" 
bank_rec	SVGNAME = svg_domain2, CLOPT ="-- -f aa -x bb"

*SERVICE
DEPOSIT      SVRNAME = bank_svr
WITHDRAW     SVRNAME = bank_svr
BALANCE	     SVRNAME = bank_svr
TRANSFER     SVRNAME = bank_svr
CHECK        SVRNAME = bank_svr
HISTORY	     SVRNAME = bank_svr

DEPOSIT_REC  SVRNAME = bank_rec
