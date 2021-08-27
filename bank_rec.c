#ifndef _TBPC_COMMON_SRC_GEN
#define _TBPC_COMMON_SRC_GEN



#define TBSQLCODE_NOTFOUND 1403



/*
==========================================
        host variable type
==========================================
*/

typedef enum esql_hostvar_type_e {

    /* string */
    ESQL_TYPE_CHARP = 0,        /* (signed) char* */
    ESQL_TYPE_UCHARP,           /* unsigned char* */
    ESQL_TYPE_CHAR_ARRAY,       /* (signed) char[n] */
    ESQL_TYPE_UCHAR_ARRAY,      /* unsigned char[n] */

    /* char */
    ESQL_TYPE_CHAR,             /* (signed) char */
    ESQL_TYPE_UCHAR,            /* unsigned char */

    /* int */
    ESQL_TYPE_INT,              /* (signed) int */
    ESQL_TYPE_UINT,             /* unsigned int */

    /* short */
    ESQL_TYPE_SHORT,            /* (signed) short (int) */
    ESQL_TYPE_USHORT,           /* unsigned short */

    /* long */
    ESQL_TYPE_LONG,             /* (signed) long (int) */
    ESQL_TYPE_ULONG,            /* unsigned long (int) */

    /* float/double */
    ESQL_TYPE_FLOAT,            /* float */
    ESQL_TYPE_DOUBLE,           /* double */

    /* VARCHAR */
    ESQL_TYPE_VARCHAR,          /* VARCHAR[n] */
    ESQL_TYPE_VARCHARP,         /* VARCHAR* */

    /* EXTERNAL DATATYPE */
    ESQL_TYPE_VARRAW,           /* VARRAW */
    ESQL_TYPE_LONG_VARRAW,      /* LONG VARRAW */

    /* EXTENED DATATYPE */
    ESQL_TYPE_NCHAR_ARRAY,      /* NCHAR */

    /* LOB */
    ESQL_TYPE_CLOB,             /* CLOB */
    ESQL_TYPE_BLOB,             /* BLOB */
    ESQL_TYPE_BFILE,            /* BFILE */

    /* COBOL COMP3 */
    ESQL_TYPE_CBL_COMP3,        /* COBOL COMP3 */
    ESQL_TYPE_EXT_VARCHAR,      /* external datatype */

    /* CURSOR */
    ESQL_TYPE_CURSOR,           /* SQL_CURSOR */

    /* NATION */
    ESQL_TYPE_NCHAR,           /* NATION CHAR */
    ESQL_TYPE_LONGLONG,         /* INT64_t */ 
    ESQL_TYPE_ULONGLONG,        /* usigned INT64_t */ 

    ESQL_TYPE_NVARCHAR              = 60,

    ESQL_HVTYPE_EXT_NUMBER          = 30,
    ESQL_HVTYPE_EXT_VARNUM          = 31,
    ESQL_HVTYPE_EXT_INTEGER         = 32,
    ESQL_HVTYPE_EXT_FLOAT           = 33,
    ESQL_HVTYPE_EXT_LONG            = 34,
    ESQL_HVTYPE_EXT_UNSIGNED        = 35,
    ESQL_HVTYPE_EXT_CHAR            = 36,
    ESQL_HVTYPE_EXT_CHARZ           = 37,
    ESQL_HVTYPE_EXT_CHARF           = 38,
    ESQL_HVTYPE_EXT_STRING          = 39,
    ESQL_HVTYPE_EXT_VARCHAR         = 40,
    ESQL_HVTYPE_EXT_VARCHAR2        = 41,
    ESQL_HVTYPE_EXT_LONG_VARCHAR    = 42,
    ESQL_HVTYPE_EXT_VARRAW          = 43,
    ESQL_HVTYPE_EXT_LONG_VARRAW     = 44,
    ESQL_HVTYPE_EXT_RAW             = 45,
    ESQL_HVTYPE_EXT_ROWID           = 46,
    ESQL_HVTYPE_EXT_LONG_RAW        = 47 
} esql_hostvar_type_t;



/*
==========================================
       ESQL type 
==========================================
*/

typedef enum esql_type_t {
    /* CONNECT */
    ESQL_TYPE_CONNECT = 1,

    /* DML */
    ESQL_TYPE_SELECT,
    ESQL_TYPE_EXECUTE_DML,

    /* cursor */
    ESQL_TYPE_OPEN_CURSOR,
    ESQL_TYPE_CLOSE_CURSOR,
    ESQL_TYPE_FETCH,

    ESQL_TYPE_COMMIT,
    ESQL_TYPE_COMMIT_RELEASE,
    ESQL_TYPE_ROLLBACK,
    ESQL_TYPE_ROLLBACK_RELEASE,
    ESQL_TYPE_ROLLBACK_TO_SAVEPOINT,

    /* DDL */
    ESQL_TYPE_DDL,  

    /* PSM */
    ESQL_TYPE_PSM,  

    ESQL_TYPE_DYN_EXEC_IMMED,
    ESQL_TYPE_DYN_EXECUTE,
    ESQL_TYPE_DYN_PREPARE,
    ESQL_TYPE_DYN_OPEN_CURSOR,
    ESQL_TYPE_DYN_DESC_BIND,
    ESQL_TYPE_DYN_DESC_SELECT,

    ESQL_TYPE_ANSIDYN_ALLOC_DESC,
    ESQL_TYPE_ANSIDYN_DEALLOC_DESC,
    ESQL_TYPE_ANSIDYN_SET_DESC,
    ESQL_TYPE_ANSIDYN_GET_DESC,
    ESQL_TYPE_ANSIDYN_DESC_INPUT,
    ESQL_TYPE_ANSIDYN_DESC_OUTPUT,

    /* THREAD & CONTEXT */
    ESQL_TYPE_ENABLE_THREADS,
    ESQL_TYPE_CONTEXT_ALLOCATE,
    ESQL_TYPE_CONTEXT_USE,
    ESQL_TYPE_CONTEXT_FREE,

    /* ALLOCATE & FREE */
    ESQL_TYPE_ALLOCATE,
    ESQL_TYPE_FREE,

    /* LOB */
    ESQL_TYPE_LOB_APPEND,
    ESQL_TYPE_LOB_ASSIGN,
    ESQL_TYPE_LOB_CLOSE,
    ESQL_TYPE_LOB_COPY,
    ESQL_TYPE_LOB_CREATE_TEMP,
    ESQL_TYPE_LOB_DESCRIBE,
    ESQL_TYPE_LOB_ERASE,
    ESQL_TYPE_LOB_FREE_TEMP,
    ESQL_TYPE_LOB_OPEN,
    ESQL_TYPE_LOB_READ,
    ESQL_TYPE_LOB_TRIM,
    ESQL_TYPE_LOB_WRITE,

    /* ETC */
    ESQL_TYPE_START_SQL,
    ESQL_TYPE_END_SQL,

    ESQL_TYPE_REGISTER_CONNECT,
    ESQL_TYPE_XA_SET_CONNECTION,
    ESQL_TYPE_XA_START,
    ESQL_TYPE_XA_END,
    ESQL_TYPE_XA_PREPARE,
    ESQL_TYPE_XA_COMMIT,
    ESQL_TYPE_XA_ROLLBACK
} esql_type_t;



/*
==========================================
       char_map 
==========================================


CHAR_MAP  fixed-length  blank-padded  null-terminated  NULL is fixed-length
(DBMS)                                                      blank-padded
---------------------------------------------------------------------------
VARCHAR2        o           o             x               o
CHARF           o           o             x               x
CHARZ           o           o             o               o
STRING          x           x             o               x
*/

typedef enum char_map_e {
    CHAR_MAP_DEFAULT = 0,
    CHAR_MAP_VARCHAR2,
    CHAR_MAP_CHARF,
    CHAR_MAP_CHARZ,
    CHAR_MAP_STRING
} char_map_t;



typedef enum esql_desc_item_e {
    ESQL_DESC_ITEM_NONE = 0,
    ESQL_DESC_ITEM_TYPE,
    ESQL_DESC_ITEM_LENGTH,
    ESQL_DESC_ITEM_INDICATOR,
    ESQL_DESC_ITEM_INDICATOR_P,
    ESQL_DESC_ITEM_DATA,
    ESQL_DESC_ITEM_DATA_P,
    ESQL_DESC_ITEM_OCTET_LENGTH,
    ESQL_DESC_ITEM_RETURNED_LENGTH,
    ESQL_DESC_ITEM_RETURNED_LENGTH_P,
    ESQL_DESC_ITEM_RETURNED_OCTET_LENGTH,
    ESQL_DESC_ITEM_PRECISION,
    ESQL_DESC_ITEM_SCALE,
    ESQL_DESC_ITEM_NULLABLE,
    ESQL_DESC_ITEM_NAME,
    ESQL_DESC_ITEM_CHARACTER_SET_NAME,
    ESQL_DESC_COUNT
} esql_desc_item_t;



#include <string.h>


#include "sqlca.h"
typedef struct esql_cpool_env_s {
    int cpool_max;
    int cpool_min;
    int cpool_incr;
    int cpool_timeout;
    int cpool_nowait;
}esql_cpool_env_t;


typedef void * sql_context;
typedef void * SQL_CONTEXT;



typedef void * sql_cursor;
typedef void * SQL_CURSOR;



typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;




typedef struct esql_sqlctx_ext {
    unsigned short     version;
    esql_cpool_env_t  *cp_env;
    void* reserved[20];
}esql_sqlctx_ext_t;




static struct esql_sqlctx {
    esql_type_t     stmt_type;

    char           *db_name;
    char           *cursor_name;
    char           *pstmt_name;
    char           *savepoint;
    char           *stmt;

    char_map_t      char_map;
    int             stmt_cache_size;
    int             fetch_type;
    int             abs_rel_nth;
    int             flag;
    int             option;

    struct sqlca   *sqlca;
    void           *sqlda;

    char           *desc_name;
    char           *desc_into;
    int             value;

    sql_context    *sql_ctx;
    char           *sqlstate;

    unsigned int    file_id;
    unsigned int    prefetch;

    int             rmid;

    unsigned int    dummy[2];

    esql_sqlctx_ext_t *sqlctx_ext;

    void           *oraca;
    void           *ep_ctx;

    unsigned int    iter_cnt;               /* count of iteration */
    unsigned int    host_var_total_cnt;     /* total # of host var */
    unsigned int    host_var_out_cnt;       /* # of out host var */

    void               **p_hostvar;         /* array of host var */
    unsigned int        *p_hostvar_len;     /* array of length of host var */
    unsigned int        *p_hostvar_stride;  /* array of stride of host var */
    esql_hostvar_type_t *p_hostvar_type;    /* array of host var type */
    esql_hostvar_type_t *p_varchar_len_type;/* array of len member of varchar type */
    unsigned int        *p_param_type;      /* array of param type */
    esql_desc_item_t    *p_ansi_dyn_type;   /* array of ansi dyn item type */
    void               **p_hostind;         /* array of host ind */
    unsigned int        *p_hostind_stride;  /* array of stride of host ind */
    long                *p_ind;             /* array of indicator */


    void                *hostvar[6];        /* array of host var */
    unsigned int         hostvar_len[6];    /* array of length of host var */
    unsigned int         hostvar_stride[6]; /* array of stride of host var */
    esql_hostvar_type_t  hostvar_type[6];   /* array of host var type */
    esql_hostvar_type_t  varchar_len_type[6];   /* array of len member of varchar type */
    unsigned int         param_type[6];     /* array of param type */
    esql_desc_item_t     ansi_dyn_type[6];  /* array of ansi dyn item type */
    void                *hostind[6];        /* array of host ind */
    unsigned int         hostind_stride[6]; /* array of stride of host ind */
    long                 ind[6];            /* array of indicator */

} sqlstm;


extern void esql_do(struct esql_sqlctx *_sqlctx);
extern void esql_do_odbc(struct esql_sqlctx *_sqlctx);
extern void esql_do_oci(struct esql_sqlctx *_sqlctx);



#endif



    #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <usrinc/atmi.h>
#include <usrinc/fbuf.h>
#include <sqlca.h>
#include <bank/bank_fdl.h>
	/*
		EXEC SQL INCLUDE bank_db.h;
	 */
	/*
		EXEC SQL INCLUDE sqlca.h;
	 */
#ifndef _SQLCA_H
#define _SQLCA_H

#define SQLERRMC_LEN	70

struct sqlca {
    char    sqlcaid[8];              /* "SQLCA" id */
    int     sqlabc;                  /* byte length of SQL structure */
    int     sqlcode;                 /* status code of SQL execution */

    struct {
        unsigned short sqlerrml;     /* message length */
        char           sqlerrmc[SQLERRMC_LEN]; /* error message */
    } sqlerrm;

    char    sqlerrp[8];              /* RESERVED */
    int     sqlerrd[6];              /* error */
	/* Element 0: empty						*/
	/* 1: OID of processed tuple if applicable			*/
	/* 2: number of rows affected after an INSERT, UPDATE, DELETE	*/
	/* 3: empty							*/
	/* 4: empty							*/
	/* 5: empty							*/

    char    sqlwarn[8];              /* warning */
  	/* Element 0: set to 'W' if at least one other is 'W'		*/
	/* 1: if 'W' at least one character string			*/
	/* value was truncated when it was stored into a host variable.	*/
	/* 2: if 'W' a (hopefully) non-fatal notice occured		*/
	/* 3: empty 							*/
	/* 4: empty							*/
	/* 5: empty							*/
	/* 6: empty							*/
	/* 7: empty							*/
    char    sqlext[8];               /* RESERVED */
};

#ifndef _WIN32
extern struct sqlca sqlca;
#else   /* _WIN32 */
#   ifdef __cplusplus
extern "C" struct sqlca __declspec(dllimport) sqlca;
#   else
extern struct sqlca __declspec(dllimport) sqlca;
#   endif
#endif  /* _WIN32 */

#endif  /* _SQLCA_H */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int check_account(char* account)
{
    int check = -1;
    
    	/*
		EXEC SQL SELECT COUNT(*)
                 INTO :check
                 FROM BANK
                 WHERE "key"=:account;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_SELECT;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = " SELECT COUNT(*)\n\
                            \n\
                 FROM BANK\n\
                 WHERE \"key\"=:v000";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 1;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 529;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 2;
    __sqlctx.host_var_out_cnt   = 1;
    __sqlctx.hostvar[0]         = (void *)(&(check));
    __sqlctx.hostvar_len[0]     = (unsigned int)sizeof(int);
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_INT;
    __sqlctx.varchar_len_type[0]= ESQL_TYPE_INT;
    __sqlctx.param_type[0]      = 5;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar[1]         = (void *)(account);
    __sqlctx.hostvar_len[1]     = (unsigned int)0;
    __sqlctx.hostvar_stride[1]  = (unsigned int)0;
    __sqlctx.hostvar_type[1]    = ESQL_TYPE_CHARP;
    __sqlctx.varchar_len_type[1]= ESQL_TYPE_INT;
    __sqlctx.param_type[1]      = 2;
    __sqlctx.ansi_dyn_type[1]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[1]         = (void *)0;
    __sqlctx.hostind_stride[1]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_varchar_len_type = (esql_hostvar_type_t *)&__sqlctx.varchar_len_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}


    return check;
}

int get_balance_amount(char* account)
{
    char ret[1024];
    int check = 0;

    if(check_account(account)<0) return -1;

    	/*
		EXEC SQL SELECT BALANCE 
         INTO :ret
         FROM BANK
         WHERE "key"=:account;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_SELECT;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = " SELECT BALANCE \n\
                  \n\
         FROM BANK\n\
         WHERE \"key\"=:v000";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 1;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 529;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 2;
    __sqlctx.host_var_out_cnt   = 1;
    __sqlctx.hostvar[0]         = (void *)(ret);
    __sqlctx.hostvar_len[0]     = (unsigned int)1024;
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_CHAR_ARRAY;
    __sqlctx.varchar_len_type[0]= ESQL_TYPE_INT;
    __sqlctx.param_type[0]      = 5;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar[1]         = (void *)(account);
    __sqlctx.hostvar_len[1]     = (unsigned int)0;
    __sqlctx.hostvar_stride[1]  = (unsigned int)0;
    __sqlctx.hostvar_type[1]    = ESQL_TYPE_CHARP;
    __sqlctx.varchar_len_type[1]= ESQL_TYPE_INT;
    __sqlctx.param_type[1]      = 2;
    __sqlctx.ansi_dyn_type[1]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[1]         = (void *)0;
    __sqlctx.hostind_stride[1]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_varchar_len_type = (esql_hostvar_type_t *)&__sqlctx.varchar_len_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}


    return atoi(ret);
}

int deposit_money(char *amount, char* account){
    int tmp = 0;
    char sum[100];
    if(check_account(account)<=0) return -1;
    tmp=get_balance_amount(account) + atoi(amount);
    sprintf(sum,"%d",tmp);
    	/*
		EXEC SQL UPDATE BANK
         SET BALANCE = :sum
         WHERE "key"=:account;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_EXECUTE_DML;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "UPDATE BANK\n\
         SET BALANCE = :v000\n\
         WHERE \"key\"=:v001";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 1;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 529;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 2;
    __sqlctx.host_var_out_cnt   = 0;
    __sqlctx.hostvar[0]         = (void *)(sum);
    __sqlctx.hostvar_len[0]     = (unsigned int)100;
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_CHAR_ARRAY;
    __sqlctx.varchar_len_type[0]= ESQL_TYPE_INT;
    __sqlctx.param_type[0]      = 8;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar[1]         = (void *)(account);
    __sqlctx.hostvar_len[1]     = (unsigned int)0;
    __sqlctx.hostvar_stride[1]  = (unsigned int)0;
    __sqlctx.hostvar_type[1]    = ESQL_TYPE_CHARP;
    __sqlctx.varchar_len_type[1]= ESQL_TYPE_INT;
    __sqlctx.param_type[1]      = 2;
    __sqlctx.ansi_dyn_type[1]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[1]         = (void *)0;
    __sqlctx.hostind_stride[1]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_varchar_len_type = (esql_hostvar_type_t *)&__sqlctx.varchar_len_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}

    return tmp;
}

int withdraw_money(char *amount, char* account){
    int tmp = 0;
    char sum[100];
    int balance=get_balance_amount(account);
    int realamount=atoi(amount);

    if(check_account(account)<=0) return -1;

    if(balance>=realamount){
            tmp=balance-realamount;
            sprintf(sum,"%d",tmp);
            	/*
		EXEC SQL UPDATE BANK
                SET BALANCE = :sum
                WHERE "key"=:account;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_EXECUTE_DML;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "UPDATE BANK\n\
                SET BALANCE = :v000\n\
                WHERE \"key\"=:v001";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 1;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 529;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 2;
    __sqlctx.host_var_out_cnt   = 0;
    __sqlctx.hostvar[0]         = (void *)(sum);
    __sqlctx.hostvar_len[0]     = (unsigned int)100;
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_CHAR_ARRAY;
    __sqlctx.varchar_len_type[0]= ESQL_TYPE_INT;
    __sqlctx.param_type[0]      = 8;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar[1]         = (void *)(account);
    __sqlctx.hostvar_len[1]     = (unsigned int)0;
    __sqlctx.hostvar_stride[1]  = (unsigned int)0;
    __sqlctx.hostvar_type[1]    = ESQL_TYPE_CHARP;
    __sqlctx.varchar_len_type[1]= ESQL_TYPE_INT;
    __sqlctx.param_type[1]      = 2;
    __sqlctx.ansi_dyn_type[1]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[1]         = (void *)0;
    __sqlctx.hostind_stride[1]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_varchar_len_type = (esql_hostvar_type_t *)&__sqlctx.varchar_len_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}

        
        return tmp;
    }

    else return -2;
        
}

void record_trading(int amount, char* who,char * account){
    int idx=0;
    int balance=0;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char nowdate[100];
    sprintf(nowdate,"%d-%d-%d", tm.tm_year+1900, tm.tm_mon+1, tm.tm_mday);
    balance=get_balance_amount(account);

    	/*
		EXEC SQL SELECT COUNT(*)
             INTO :idx
             FROM TRADE_HISTORY;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_SELECT;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = " SELECT COUNT(*)\n\
                      \n\
             FROM TRADE_HISTORY";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 1;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 529;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 1;
    __sqlctx.host_var_out_cnt   = 1;
    __sqlctx.hostvar[0]         = (void *)(&(idx));
    __sqlctx.hostvar_len[0]     = (unsigned int)sizeof(int);
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_INT;
    __sqlctx.varchar_len_type[0]= ESQL_TYPE_INT;
    __sqlctx.param_type[0]      = 5;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_varchar_len_type = (esql_hostvar_type_t *)&__sqlctx.varchar_len_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}


    idx++;

    	/*
		EXEC SQL INSERT INTO TRADE_HISTORY
             VALUES(:idx,:who,:amount,:nowdate,:balance,:account);
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_EXECUTE_DML;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = "INSERT INTO TRADE_HISTORY\n\
             VALUES(:v000,:v001,:v002,:v003,:v004,:v005)";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 1;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 529;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
    __sqlctx.iter_cnt           = 1;
    __sqlctx.host_var_total_cnt = 6;
    __sqlctx.host_var_out_cnt   = 0;
    __sqlctx.hostvar[0]         = (void *)(&(idx));
    __sqlctx.hostvar_len[0]     = (unsigned int)sizeof(int);
    __sqlctx.hostvar_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_INT;
    __sqlctx.varchar_len_type[0]= ESQL_TYPE_INT;
    __sqlctx.param_type[0]      = 0;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar[1]         = (void *)(who);
    __sqlctx.hostvar_len[1]     = (unsigned int)0;
    __sqlctx.hostvar_stride[1]  = (unsigned int)0;
    __sqlctx.hostvar_type[1]    = ESQL_TYPE_CHARP;
    __sqlctx.varchar_len_type[1]= ESQL_TYPE_INT;
    __sqlctx.param_type[1]      = 0;
    __sqlctx.ansi_dyn_type[1]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[1]         = (void *)0;
    __sqlctx.hostind_stride[1]  = (unsigned int)0;
    __sqlctx.hostvar[2]         = (void *)(&(amount));
    __sqlctx.hostvar_len[2]     = (unsigned int)sizeof(int);
    __sqlctx.hostvar_stride[2]  = (unsigned int)0;
    __sqlctx.hostvar_type[2]    = ESQL_TYPE_INT;
    __sqlctx.varchar_len_type[2]= ESQL_TYPE_INT;
    __sqlctx.param_type[2]      = 0;
    __sqlctx.ansi_dyn_type[2]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[2]         = (void *)0;
    __sqlctx.hostind_stride[2]  = (unsigned int)0;
    __sqlctx.hostvar[3]         = (void *)(nowdate);
    __sqlctx.hostvar_len[3]     = (unsigned int)100;
    __sqlctx.hostvar_stride[3]  = (unsigned int)0;
    __sqlctx.hostvar_type[3]    = ESQL_TYPE_CHAR_ARRAY;
    __sqlctx.varchar_len_type[3]= ESQL_TYPE_INT;
    __sqlctx.param_type[3]      = 0;
    __sqlctx.ansi_dyn_type[3]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[3]         = (void *)0;
    __sqlctx.hostind_stride[3]  = (unsigned int)0;
    __sqlctx.hostvar[4]         = (void *)(&(balance));
    __sqlctx.hostvar_len[4]     = (unsigned int)sizeof(int);
    __sqlctx.hostvar_stride[4]  = (unsigned int)0;
    __sqlctx.hostvar_type[4]    = ESQL_TYPE_INT;
    __sqlctx.varchar_len_type[4]= ESQL_TYPE_INT;
    __sqlctx.param_type[4]      = 0;
    __sqlctx.ansi_dyn_type[4]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[4]         = (void *)0;
    __sqlctx.hostind_stride[4]  = (unsigned int)0;
    __sqlctx.hostvar[5]         = (void *)(account);
    __sqlctx.hostvar_len[5]     = (unsigned int)0;
    __sqlctx.hostvar_stride[5]  = (unsigned int)0;
    __sqlctx.hostvar_type[5]    = ESQL_TYPE_CHARP;
    __sqlctx.varchar_len_type[5]= ESQL_TYPE_INT;
    __sqlctx.param_type[5]      = 0;
    __sqlctx.ansi_dyn_type[5]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[5]         = (void *)0;
    __sqlctx.hostind_stride[5]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_varchar_len_type = (esql_hostvar_type_t *)&__sqlctx.varchar_len_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}


}

int trade_recording(char* account){
    	/*
		EXEC SQL BEGIN DECLARE SECTION;
	 */

/*	        VARCHAR who[30][100];	*/
struct __tag21 { unsigned short len; unsigned char arr[100]; } who[30];

        int amount[30];
/*	        VARCHAR date[30][100];	*/
struct __tag22 { unsigned short len; unsigned char arr[100]; } date[30];

        int balance[30];

    	/*
		EXEC SQL END DECLARE SECTION;
	 */



    
    	/*
		EXEC SQL SELECT WHO, AMOUNT, "date", BALANCE
             INTO :who, :amount, :date, :balance
             FROM TRADE_HISTORY 
             WHERE "ACCOUNT"=:account;
	 */
{
    esql_cpool_env_t __cp_env;
    esql_sqlctx_ext_t __sqlctx_ext;
    struct esql_sqlctx  __sqlctx;
    
    __cp_env.cpool_max     = 100;
    __cp_env.cpool_min     = 1;
    __cp_env.cpool_incr    = 1;
    __cp_env.cpool_timeout = 0;
    __cp_env.cpool_nowait  = 0;
    
    memset(&__sqlctx, 0, sizeof(struct esql_sqlctx));
    __sqlctx.stmt_type   = ESQL_TYPE_SELECT;
    __sqlctx.db_name     = "";
    __sqlctx.cursor_name = "";
    __sqlctx.pstmt_name  = "";
    __sqlctx.savepoint   = "";
    __sqlctx.stmt        = " SELECT WHO, AMOUNT, \"date\", BALANCE\n\
                                                \n\
             FROM TRADE_HISTORY \n\
             WHERE \"ACCOUNT\"=:v000";
    __sqlctx.char_map    = CHAR_MAP_CHARZ;
    __sqlctx.stmt_cache_size = 0;
    __sqlctx.fetch_type  = 1;
    __sqlctx.abs_rel_nth = 0;
    __sqlctx.flag        = 0;
    __sqlctx.option      = 1052674;
    __sqlctx.sqlca       = (struct sqlca *)&sqlca;
    __sqlctx.sqlctx_ext  = &__sqlctx_ext;
    __sqlctx.oraca       = (void *)0;
    __sqlctx.sqlda       = (void *)0;
    __sqlctx.desc_name   = "";
    __sqlctx.desc_into   = "";
    __sqlctx.value       = 0;
    __sqlctx.sql_ctx     = (sql_context *)0;
    __sqlctx.ep_ctx      = (void *)0;
    __sqlctx.sqlstate    = (char *)0;
    __sqlctx.file_id     = 529;
    __sqlctx.prefetch    = 1;
    __sqlctx.rmid        = -1;
    __sqlctx_ext.version = 1;
    __sqlctx_ext.cp_env  = &__cp_env;
    __sqlctx.iter_cnt           = 30;
    __sqlctx.host_var_total_cnt = 5;
    __sqlctx.host_var_out_cnt   = 4;
    __sqlctx.hostvar[0]         = (void *)(who);
    __sqlctx.hostvar_len[0]     = (unsigned int)sizeof(who[0].arr);
    __sqlctx.hostvar_stride[0]  = (unsigned int)sizeof(who[0]);
    __sqlctx.hostvar_type[0]    = ESQL_TYPE_VARCHAR;
    __sqlctx.varchar_len_type[0]= ESQL_TYPE_INT;
    __sqlctx.param_type[0]      = 5;
    __sqlctx.ansi_dyn_type[0]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[0]         = (void *)0;
    __sqlctx.hostind_stride[0]  = (unsigned int)0;
    __sqlctx.hostvar[1]         = (void *)(amount);
    __sqlctx.hostvar_len[1]     = (unsigned int)sizeof(int);
    __sqlctx.hostvar_stride[1]  = (unsigned int)sizeof(int);
    __sqlctx.hostvar_type[1]    = ESQL_TYPE_INT;
    __sqlctx.varchar_len_type[1]= ESQL_TYPE_INT;
    __sqlctx.param_type[1]      = 5;
    __sqlctx.ansi_dyn_type[1]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[1]         = (void *)0;
    __sqlctx.hostind_stride[1]  = (unsigned int)0;
    __sqlctx.hostvar[2]         = (void *)(date);
    __sqlctx.hostvar_len[2]     = (unsigned int)sizeof(date[0].arr);
    __sqlctx.hostvar_stride[2]  = (unsigned int)sizeof(date[0]);
    __sqlctx.hostvar_type[2]    = ESQL_TYPE_VARCHAR;
    __sqlctx.varchar_len_type[2]= ESQL_TYPE_INT;
    __sqlctx.param_type[2]      = 5;
    __sqlctx.ansi_dyn_type[2]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[2]         = (void *)0;
    __sqlctx.hostind_stride[2]  = (unsigned int)0;
    __sqlctx.hostvar[3]         = (void *)(balance);
    __sqlctx.hostvar_len[3]     = (unsigned int)sizeof(int);
    __sqlctx.hostvar_stride[3]  = (unsigned int)sizeof(int);
    __sqlctx.hostvar_type[3]    = ESQL_TYPE_INT;
    __sqlctx.varchar_len_type[3]= ESQL_TYPE_INT;
    __sqlctx.param_type[3]      = 5;
    __sqlctx.ansi_dyn_type[3]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[3]         = (void *)0;
    __sqlctx.hostind_stride[3]  = (unsigned int)0;
    __sqlctx.hostvar[4]         = (void *)(account);
    __sqlctx.hostvar_len[4]     = (unsigned int)0;
    __sqlctx.hostvar_stride[4]  = (unsigned int)0;
    __sqlctx.hostvar_type[4]    = ESQL_TYPE_CHARP;
    __sqlctx.varchar_len_type[4]= ESQL_TYPE_INT;
    __sqlctx.param_type[4]      = 2;
    __sqlctx.ansi_dyn_type[4]   = ESQL_DESC_ITEM_NONE;
    __sqlctx.hostind[4]         = (void *)0;
    __sqlctx.hostind_stride[4]  = (unsigned int)0;
    __sqlctx.p_hostvar        = (void **)&__sqlctx.hostvar[0];
    __sqlctx.p_hostvar_len    = (unsigned int *)&__sqlctx.hostvar_len[0];
    __sqlctx.p_hostvar_stride = (unsigned int *)&__sqlctx.hostvar_stride[0];
    __sqlctx.p_hostvar_type   = (esql_hostvar_type_t *)&__sqlctx.hostvar_type[0];
    __sqlctx.p_varchar_len_type = (esql_hostvar_type_t *)&__sqlctx.varchar_len_type[0];
    __sqlctx.p_param_type     = (unsigned int *)&__sqlctx.param_type[0];
    __sqlctx.p_ansi_dyn_type  = (esql_desc_item_t *)&__sqlctx.ansi_dyn_type[0];
    __sqlctx.p_hostind        = (void **)&__sqlctx.hostind[0];
    __sqlctx.p_hostind_stride = (unsigned int *)&__sqlctx.hostind_stride[0];
    __sqlctx.p_ind            = (long *)&__sqlctx.ind[0];
      sqlstm.stmt        = __sqlctx.stmt;
    esql_do(&__sqlctx);
}

    
    for (int i=0;i<sqlca.sqlerrd[2];i++){
        printf("\t%.*s %d %.*s %d\n",who[i].len,who[i].arr,amount[i],date[i].len,date[i].arr,balance[i]);
    }

    return 0;
}


int DEPOSIT_REC(TPSVCINFO *msg)
{       
        char amount[100];
        int ret = 0;
        int realamount=0;
        char account[10];
        char account_send[10];
        char ret_msg[1024] = {'\0',};
        FBUF *retbuf;
        
        retbuf=(FBUF *)tpalloc("FIELD", NULL,0);

        fbget((FBUF *)(msg->data), FB_AMOUNT,amount,0);
        fbget((FBUF *)(msg->data), FB_ACCNT_REC,account,0);
        fbget((FBUF*)(msg->data),ACCOUNT,account_send,0);
        
        realamount=atoi(amount);
        ret=deposit_money(amount,account);

        if(ret == -1){
            sprintf(ret_msg, "\n\tAccount number is wrong\n");
            fbput(retbuf,MESSAGE,ret_msg,0);
            tpreturn(TPFAIL,0,(char *)retbuf,0,TPNOFLAGS);
        }

        
        else{
            sprintf(ret_msg, "\n\tBalance : %d\n",ret);
            record_trading(realamount,account_send,account);
            fbput(retbuf,MESSAGE,ret_msg,0);
            tpreturn(TPSUCCESS,0,(char *)retbuf,0,TPNOFLAGS);
        }

         
}

