/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/jucompiler.y"


    // Joao Emanuel Sousa Moreira 2020230563
    // Tomas Cerveira da Cruz Pinto 2020224069

    // C Standard library Includes
    
  // Yacc and other Includes...
  #include "ast.h"
 
  // Functions
  extern int yylex();
  extern void yyerror(const char *str);
  extern char *yytext;
  // extern int yylineno;
  extern int num_line;
  extern int num_col;

  ast_node_t *my_program;
  ast_node_t *aux;
  ast_node_t *aux2;
  ast_node_t *aux3;

  // Compiler Flags TODO
  int a = 0;
  bool l = false, e1 = false, e2 = true, t = false; 


#line 100 "src/y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INTLIT = 3,                     /* INTLIT  */
  YYSYMBOL_STRLIT = 4,                     /* STRLIT  */
  YYSYMBOL_REALLIT = 5,                    /* REALLIT  */
  YYSYMBOL_ID = 6,                         /* ID  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_RETURN = 10,                    /* RETURN  */
  YYSYMBOL_BOOL = 11,                      /* BOOL  */
  YYSYMBOL_CLASS = 12,                     /* CLASS  */
  YYSYMBOL_DOUBLE = 13,                    /* DOUBLE  */
  YYSYMBOL_INT = 14,                       /* INT  */
  YYSYMBOL_PUBLIC = 15,                    /* PUBLIC  */
  YYSYMBOL_STATIC = 16,                    /* STATIC  */
  YYSYMBOL_STRING = 17,                    /* STRING  */
  YYSYMBOL_VOID = 18,                      /* VOID  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_GE = 20,                        /* GE  */
  YYSYMBOL_GT = 21,                        /* GT  */
  YYSYMBOL_LT = 22,                        /* LT  */
  YYSYMBOL_LE = 23,                        /* LE  */
  YYSYMBOL_NE = 24,                        /* NE  */
  YYSYMBOL_DOTLENGTH = 25,                 /* DOTLENGTH  */
  YYSYMBOL_PRINT = 26,                     /* PRINT  */
  YYSYMBOL_PARSEINT = 27,                  /* PARSEINT  */
  YYSYMBOL_BOOLLIT = 28,                   /* BOOLLIT  */
  YYSYMBOL_AND = 29,                       /* AND  */
  YYSYMBOL_NOT = 30,                       /* NOT  */
  YYSYMBOL_OR = 31,                        /* OR  */
  YYSYMBOL_XOR = 32,                       /* XOR  */
  YYSYMBOL_MOD = 33,                       /* MOD  */
  YYSYMBOL_DIV = 34,                       /* DIV  */
  YYSYMBOL_STAR = 35,                      /* STAR  */
  YYSYMBOL_MINUS = 36,                     /* MINUS  */
  YYSYMBOL_PLUS = 37,                      /* PLUS  */
  YYSYMBOL_ASSIGN = 38,                    /* ASSIGN  */
  YYSYMBOL_COMMA = 39,                     /* COMMA  */
  YYSYMBOL_LBRACE = 40,                    /* LBRACE  */
  YYSYMBOL_LPAR = 41,                      /* LPAR  */
  YYSYMBOL_LSQ = 42,                       /* LSQ  */
  YYSYMBOL_RBRACE = 43,                    /* RBRACE  */
  YYSYMBOL_RPAR = 44,                      /* RPAR  */
  YYSYMBOL_RSQ = 45,                       /* RSQ  */
  YYSYMBOL_SEMICOLON = 46,                 /* SEMICOLON  */
  YYSYMBOL_LSHIFT = 47,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 48,                    /* RSHIFT  */
  YYSYMBOL_ARROW = 49,                     /* ARROW  */
  YYSYMBOL_QUOTE = 50,                     /* QUOTE  */
  YYSYMBOL_RESERVED = 51,                  /* RESERVED  */
  YYSYMBOL_NO_ELSE = 52,                   /* NO_ELSE  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_Main = 54,                      /* Main  */
  YYSYMBOL_Program = 55,                   /* Program  */
  YYSYMBOL_Program2 = 56,                  /* Program2  */
  YYSYMBOL_MethodDecl = 57,                /* MethodDecl  */
  YYSYMBOL_FieldDecl = 58,                 /* FieldDecl  */
  YYSYMBOL_FieldDecl2 = 59,                /* FieldDecl2  */
  YYSYMBOL_Type = 60,                      /* Type  */
  YYSYMBOL_MethodHeader = 61,              /* MethodHeader  */
  YYSYMBOL_FormalParams = 62,              /* FormalParams  */
  YYSYMBOL_FormalParams2 = 63,             /* FormalParams2  */
  YYSYMBOL_MethodBody = 64,                /* MethodBody  */
  YYSYMBOL_MethodBody2 = 65,               /* MethodBody2  */
  YYSYMBOL_VarDecl = 66,                   /* VarDecl  */
  YYSYMBOL_VarDecl2 = 67,                  /* VarDecl2  */
  YYSYMBOL_Statement = 68,                 /* Statement  */
  YYSYMBOL_Statement2 = 69,                /* Statement2  */
  YYSYMBOL_MethodInvocation = 70,          /* MethodInvocation  */
  YYSYMBOL_MethodInvocation2 = 71,         /* MethodInvocation2  */
  YYSYMBOL_Assignment = 72,                /* Assignment  */
  YYSYMBOL_ParseArgs = 73,                 /* ParseArgs  */
  YYSYMBOL_Expr = 74                       /* Expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   590

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,    78,    80,    81,    82,    83,    87,    96,
      97,    99,   100,   104,   105,   106,   110,   111,   112,   114,
     116,   117,   124,   125,   129,   131,   132,   133,   138,   140,
     141,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   198,   199,   201,   202,   203,   206,
     207,   208,   212,   215,   216,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTLIT", "STRLIT",
  "REALLIT", "ID", "IF", "ELSE", "WHILE", "RETURN", "BOOL", "CLASS",
  "DOUBLE", "INT", "PUBLIC", "STATIC", "STRING", "VOID", "EQ", "GE", "GT",
  "LT", "LE", "NE", "DOTLENGTH", "PRINT", "PARSEINT", "BOOLLIT", "AND",
  "NOT", "OR", "XOR", "MOD", "DIV", "STAR", "MINUS", "PLUS", "ASSIGN",
  "COMMA", "LBRACE", "LPAR", "LSQ", "RBRACE", "RPAR", "RSQ", "SEMICOLON",
  "LSHIFT", "RSHIFT", "ARROW", "QUOTE", "RESERVED", "NO_ELSE", "$accept",
  "Main", "Program", "Program2", "MethodDecl", "FieldDecl", "FieldDecl2",
  "Type", "MethodHeader", "FormalParams", "FormalParams2", "MethodBody",
  "MethodBody2", "VarDecl", "VarDecl2", "Statement", "Statement2",
  "MethodInvocation", "MethodInvocation2", "Assignment", "ParseArgs",
  "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-40)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-52)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,    23,     4,   -40,    -4,   -40,     8,    15,    47,     8,
      29,     8,     8,   -40,    -8,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,    67,    68,    35,    50,    -2,   180,   -40,    51,
      70,   101,    52,    55,   -10,    63,    64,   227,    65,    72,
      93,   -40,   115,    80,   180,   180,    78,    79,    89,    84,
     -40,   132,    96,   104,   -40,   100,   -40,   -40,   283,   208,
     283,   283,   -40,   -40,   -11,   -40,   283,   283,   283,   255,
     -40,   -40,   -40,   -40,   306,   271,    10,    93,   106,   108,
     -40,   -40,   -40,   -40,   -40,   -40,   105,   112,   -40,   -40,
     -40,   466,   109,   -40,   136,   326,   356,   -40,   -40,    36,
      36,   117,   386,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   -40,   283,   283,
     118,   416,   119,   110,   -40,   -40,   158,   120,   168,    42,
     -40,   -40,   -40,   283,   133,   191,   191,   -40,   -40,   542,
      94,    94,    94,    94,   542,   505,   486,   524,   -40,   -40,
     -40,    36,    36,    11,    11,   130,   139,   -40,   283,   108,
     -40,   -40,   172,   136,   -40,   171,   -40,   -40,   -40,   446,
     -40,   112,   -40,   191,   138,   -40,   -40,   -40
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
       0,     0,     0,    10,     0,     6,     3,     4,     5,    13,
      15,    14,     0,     0,     0,     0,    12,     0,     8,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
      19,     0,     0,    12,    17,     0,     9,    40,     0,     0,
       0,     0,    81,    82,    80,    83,     0,     0,     0,     0,
      36,    76,    77,    78,     0,     0,     0,     0,     0,    30,
      24,    26,    25,    37,    38,    39,     0,    23,    18,    11,
      16,    52,     0,    46,     0,     0,     0,    79,    72,    71,
      73,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    35,     0,     0,
       0,     0,     0,     0,    44,    31,     0,     0,     0,     0,
      20,    47,    50,     0,     0,     0,     0,    75,    74,    65,
      66,    67,    69,    68,    70,    60,    61,    62,    59,    58,
      57,    56,    55,    63,    64,     0,     0,    54,     0,    30,
      28,    21,     0,     0,    48,    33,    34,    43,    42,     0,
      29,    23,    49,     0,     0,    22,    32,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -40,   -40,   -40,    48,   -40,   -40,   135,    -7,   -40,   164,
      25,   -40,    22,   -40,    40,   -39,   125,   -27,    41,   -25,
     -19,   -26
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    10,    11,    12,    32,    42,    24,    52,
     130,    28,    43,    44,   127,    45,    78,    71,   134,    72,
      73,    74
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,    77,    47,    19,     5,    20,    21,    23,    48,     7,
      22,   122,     1,    46,    97,    47,   123,    46,    46,    47,
      47,    48,    51,     8,    51,    48,    48,    58,    58,     4,
      59,    59,    91,    94,    95,    96,     6,    30,    77,    31,
      98,    99,   100,   102,   112,   113,   114,   115,   116,   121,
      46,    -7,    47,    19,     9,    20,    21,    15,    48,    17,
      18,    13,    19,    14,    20,    21,    81,    82,    49,   112,
     113,   114,    16,    25,    26,    27,    53,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,    29,   153,   154,    33,    50,   165,   166,    56,    34,
      35,    57,    36,    37,    60,    61,    75,   163,    46,    46,
      47,    47,    19,    76,    20,    21,    48,    48,    49,    38,
      39,    79,   162,    80,    83,    84,    86,   112,   113,   114,
     115,   116,   169,    40,   176,    85,   -45,   132,    87,    41,
      88,   118,   119,    30,    90,    54,    46,   126,    47,   125,
     128,   129,   158,   131,    48,   103,   104,   105,   106,   107,
     108,   137,   155,   157,   159,   109,   160,   110,   111,   112,
     113,   114,   115,   116,   161,   133,   167,   164,   171,   173,
     -51,    33,   177,   118,   119,   168,    34,    35,    89,    36,
      37,    19,    33,    20,    21,    55,   175,    34,    35,   170,
      36,    37,   124,     0,   172,     0,    38,    39,     0,    92,
       0,    62,     0,    63,    64,     0,     0,    38,    39,     0,
      40,     0,     0,   -27,     0,     0,    41,     0,     0,     0,
      62,    40,    63,    64,     0,    39,    65,    41,    66,     0,
       0,     0,     0,     0,    67,    68,     0,     0,     0,    69,
       0,     0,    93,     0,    39,    65,   101,    66,    62,     0,
      63,    64,     0,    67,    68,     0,     0,     0,    69,     0,
       0,     0,     0,    70,    62,   120,    63,    64,     0,     0,
       0,     0,    39,    65,     0,    66,    62,     0,    63,    64,
       0,    67,    68,     0,     0,     0,    69,     0,    39,    65,
       0,    66,     0,     0,     0,     0,     0,    67,    68,     0,
      39,    65,    69,    66,     0,     0,     0,     0,     0,    67,
      68,     0,     0,     0,    69,   103,   104,   105,   106,   107,
     108,     0,     0,     0,     0,   109,     0,   110,   111,   112,
     113,   114,   115,   116,     0,   103,   104,   105,   106,   107,
     108,     0,   117,   118,   119,   109,     0,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
     135,     0,     0,   118,   119,   103,   104,   105,   106,   107,
     108,     0,     0,     0,     0,   109,     0,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
     136,     0,     0,   118,   119,   103,   104,   105,   106,   107,
     108,     0,     0,     0,     0,   109,     0,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
     138,     0,     0,   118,   119,   103,   104,   105,   106,   107,
     108,     0,     0,     0,     0,   109,     0,   110,   111,   112,
     113,   114,   115,   116,     0,     0,     0,     0,     0,     0,
     156,     0,     0,   118,   119,   103,   104,   105,   106,   107,
     108,     0,     0,     0,     0,   109,     0,   110,   111,   112,
     113,   114,   115,   116,     0,   103,   104,   105,   106,   107,
     108,   174,     0,   118,   119,   109,     0,   110,   111,   112,
     113,   114,   115,   116,     0,   103,   104,   105,   106,   107,
     108,     0,     0,   118,   119,   109,     0,     0,   111,   112,
     113,   114,   115,   116,   103,   104,   105,   106,   107,   108,
       0,     0,     0,   118,   119,     0,     0,   111,   112,   113,
     114,   115,   116,   103,   104,   105,   106,   107,   108,     0,
       0,     0,   118,   119,     0,     0,     0,   112,   113,   114,
     115,   116,   104,   105,   106,   107,     0,     0,     0,     0,
       0,   118,   119,     0,     0,   112,   113,   114,   115,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   118,
     119
};

static const yytype_int16 yycheck[] =
{
      27,    40,    27,    11,     0,    13,    14,    14,    27,     1,
      18,     1,    12,    40,    25,    40,     6,    44,    45,    44,
      45,    40,    29,    15,    31,    44,    45,    38,    38,     6,
      41,    41,    58,    59,    60,    61,    40,    39,    77,    41,
      66,    67,    68,    69,    33,    34,    35,    36,    37,    75,
      77,    43,    77,    11,    46,    13,    14,     9,    77,    11,
      12,    46,    11,    16,    13,    14,    44,    45,    17,    33,
      34,    35,    43,     6,     6,    40,     6,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,    41,   118,   119,     1,    44,   135,   136,    46,     6,
       7,    46,     9,    10,    41,    41,    41,   133,   135,   136,
     135,   136,    11,    41,    13,    14,   135,   136,    17,    26,
      27,     6,   129,    43,    46,    46,    42,    33,    34,    35,
      36,    37,   158,    40,   173,    46,    43,     1,     6,    46,
      44,    47,    48,    39,    44,    44,   173,    39,   173,    43,
      45,    39,    42,    44,   173,    19,    20,    21,    22,    23,
      24,    44,    44,    44,     6,    29,    46,    31,    32,    33,
      34,    35,    36,    37,     6,    39,    46,    44,     6,     8,
      44,     1,    44,    47,    48,    46,     6,     7,    53,     9,
      10,    11,     1,    13,    14,    31,   171,     6,     7,   159,
       9,    10,    77,    -1,   163,    -1,    26,    27,    -1,     1,
      -1,     3,    -1,     5,     6,    -1,    -1,    26,    27,    -1,
      40,    -1,    -1,    43,    -1,    -1,    46,    -1,    -1,    -1,
       3,    40,     5,     6,    -1,    27,    28,    46,    30,    -1,
      -1,    -1,    -1,    -1,    36,    37,    -1,    -1,    -1,    41,
      -1,    -1,    44,    -1,    27,    28,     1,    30,     3,    -1,
       5,     6,    -1,    36,    37,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    46,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    27,    28,    -1,    30,     3,    -1,     5,     6,
      -1,    36,    37,    -1,    -1,    -1,    41,    -1,    27,    28,
      -1,    30,    -1,    -1,    -1,    -1,    -1,    36,    37,    -1,
      27,    28,    41,    30,    -1,    -1,    -1,    -1,    -1,    36,
      37,    -1,    -1,    -1,    41,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    19,    20,    21,    22,    23,
      24,    -1,    46,    47,    48,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    47,    48,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    47,    48,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    47,    48,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    47,    48,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    19,    20,    21,    22,    23,
      24,    45,    -1,    47,    48,    29,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    19,    20,    21,    22,    23,
      24,    -1,    -1,    47,    48,    29,    -1,    -1,    32,    33,
      34,    35,    36,    37,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    47,    48,    -1,    -1,    32,    33,    34,
      35,    36,    37,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    47,    48,    -1,    -1,    -1,    33,    34,    35,
      36,    37,    20,    21,    22,    23,    -1,    -1,    -1,    -1,
      -1,    47,    48,    -1,    -1,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,
      48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    54,    55,     6,     0,    40,     1,    15,    46,
      56,    57,    58,    46,    16,    56,    43,    56,    56,    11,
      13,    14,    18,    60,    61,     6,     6,    40,    64,    41,
      39,    41,    59,     1,     6,     7,     9,    10,    26,    27,
      40,    46,    60,    65,    66,    68,    70,    72,    73,    17,
      44,    60,    62,     6,    44,    62,    46,    46,    38,    41,
      41,    41,     3,     5,     6,    28,    30,    36,    37,    41,
      46,    70,    72,    73,    74,    41,    41,    68,    69,     6,
      43,    65,    65,    46,    46,    46,    42,     6,    44,    59,
      44,    74,     1,    44,    74,    74,    74,    25,    74,    74,
      74,     1,    74,    19,    20,    21,    22,    23,    24,    29,
      31,    32,    33,    34,    35,    36,    37,    46,    47,    48,
       4,    74,     1,     6,    69,    43,    39,    67,    45,    39,
      63,    44,     1,    39,    71,    44,    44,    44,    44,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    44,    44,    44,    42,     6,
      46,     6,    60,    74,    44,    68,    68,    46,    46,    74,
      67,     6,    71,     8,    45,    63,    68,    44
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    55,    56,    56,    56,    56,    57,    58,
      58,    59,    59,    60,    60,    60,    61,    61,    61,    61,
      62,    62,    63,    63,    64,    65,    65,    65,    66,    67,
      67,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    69,    69,    70,    70,    70,    71,
      71,    71,    72,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     5,     2,     2,     2,     0,     4,     6,
       2,     3,     0,     1,     1,     1,     5,     4,     5,     4,
       3,     4,     4,     0,     3,     2,     2,     0,     4,     3,
       0,     3,     7,     5,     5,     3,     2,     2,     2,     2,
       2,     1,     5,     5,     2,     0,     3,     4,     5,     3,
       1,     0,     3,     7,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     3,     3,     1,     1,     1,     2,
       1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Main: Program  */
#line 76 "src/jucompiler.y"
                                                                                { (yyval.node) = my_program = ast_node("Program", NULL); add_children((yyval.node), (yyvsp[0].node)); }
#line 1359 "src/y.tab.c"
    break;

  case 3: /* Program: CLASS ID LBRACE Program2 RBRACE  */
#line 78 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Id", (yyvsp[-3].token)); add_brother((yyval.node), (yyvsp[-1].node)); }
#line 1365 "src/y.tab.c"
    break;

  case 4: /* Program2: MethodDecl Program2  */
#line 80 "src/jucompiler.y"
                                                                                { (yyval.node) = (yyvsp[-1].node); add_brother((yyval.node), (yyvsp[0].node)); }
#line 1371 "src/y.tab.c"
    break;

  case 5: /* Program2: FieldDecl Program2  */
#line 81 "src/jucompiler.y"
                                                                                { (yyval.node) = (yyvsp[-1].node); add_brother((yyval.node), (yyvsp[0].node)); }
#line 1377 "src/y.tab.c"
    break;

  case 6: /* Program2: SEMICOLON Program2  */
#line 82 "src/jucompiler.y"
                                                                                { (yyval.node) = (yyvsp[0].node); }
#line 1383 "src/y.tab.c"
    break;

  case 7: /* Program2: %empty  */
#line 83 "src/jucompiler.y"
                                                                                { (yyval.node) = NULL; }
#line 1389 "src/y.tab.c"
    break;

  case 8: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 87 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("MethodDecl", NULL); add_children((yyval.node), (yyvsp[-1].node)); add_brother((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1395 "src/y.tab.c"
    break;

  case 9: /* FieldDecl: PUBLIC STATIC Type ID FieldDecl2 SEMICOLON  */
#line 96 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("FieldDecl", NULL); aux = ast_node("Id", (yyvsp[-2].token)); }
#line 1401 "src/y.tab.c"
    break;

  case 10: /* FieldDecl: error SEMICOLON  */
#line 97 "src/jucompiler.y"
                                  {(yyval.node) = NULL;}
#line 1407 "src/y.tab.c"
    break;

  case 11: /* FieldDecl2: COMMA ID FieldDecl2  */
#line 99 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("FieldDecl", NULL); aux = ast_node("Id", (yyvsp[-1].token)); add_children((yyval.node), aux); add_brother((yyval.node), (yyvsp[0].node)); }
#line 1413 "src/y.tab.c"
    break;

  case 12: /* FieldDecl2: %empty  */
#line 100 "src/jucompiler.y"
                                                                                { (yyval.node) = NULL; }
#line 1419 "src/y.tab.c"
    break;

  case 13: /* Type: BOOL  */
#line 104 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Bool", NULL); }
#line 1425 "src/y.tab.c"
    break;

  case 14: /* Type: INT  */
#line 105 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Int", NULL); }
#line 1431 "src/y.tab.c"
    break;

  case 15: /* Type: DOUBLE  */
#line 106 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Double", NULL); }
#line 1437 "src/y.tab.c"
    break;

  case 16: /* MethodHeader: Type ID LPAR FormalParams RPAR  */
#line 110 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("MethodHeader", NULL); add_children((yyval.node), (yyvsp[-4].node)); aux = ast_node("Id", (yyvsp[-3].token)); add_brother((yyvsp[-4].node), aux); add_brother(aux, (yyvsp[-1].node)); }
#line 1443 "src/y.tab.c"
    break;

  case 17: /* MethodHeader: Type ID LPAR RPAR  */
#line 111 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("MethodHeader", NULL); add_children((yyval.node), (yyvsp[-3].node)); aux = ast_node("Id", (yyvsp[-2].token)); add_brother((yyvsp[-3].node), aux); add_brother(aux, ast_node("MethodParams", NULL)); }
#line 1449 "src/y.tab.c"
    break;

  case 18: /* MethodHeader: VOID ID LPAR FormalParams RPAR  */
#line 112 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("MethodHeader", NULL); aux = ast_node("Void", NULL); add_children((yyval.node), aux);  
                                                                                aux2 = ast_node("Id", (yyvsp[-3].token)); add_brother(aux, aux2); add_brother(aux2, (yyvsp[-1].node)); }
#line 1456 "src/y.tab.c"
    break;

  case 19: /* MethodHeader: VOID ID LPAR RPAR  */
#line 114 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("MethodHeader", NULL); aux = ast_node("Void", NULL); add_children((yyval.node), aux); aux2 = ast_node("Id", (yyvsp[-2].token)); add_brother(aux, aux2); add_brother(aux2, ast_node("MethodParams", NULL)); }
#line 1462 "src/y.tab.c"
    break;

  case 20: /* FormalParams: Type ID FormalParams2  */
#line 116 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("MethodParams", NULL); add_children((yyval.node), (yyvsp[0].node)); add_children((yyvsp[0].node), (yyvsp[-2].node)); aux = ast_node("Id", (yyvsp[-1].token)); add_brother((yyvsp[-2].node), aux); }
#line 1468 "src/y.tab.c"
    break;

  case 21: /* FormalParams: STRING LSQ RSQ ID  */
#line 117 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("MethodParams", NULL); aux2 = ast_node("ParamDecl", NULL); add_children((yyval.node), aux2);
                                                                                 aux = ast_node("StringArray", NULL); add_children(aux2, aux);
                                                                                  add_brother(aux, ast_node("Id", (yyvsp[0].token)));
                                                                                  /* Ainda nao foi testado */
                                                                                  }
#line 1478 "src/y.tab.c"
    break;

  case 22: /* FormalParams2: COMMA Type ID FormalParams2  */
#line 124 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("ParamDecl", NULL); add_brother((yyval.node), (yyvsp[0].node)); add_children((yyvsp[0].node), (yyvsp[-2].node)); aux = ast_node("Id", (yyvsp[-1].token)); add_brother((yyvsp[-2].node), aux); }
#line 1484 "src/y.tab.c"
    break;

  case 23: /* FormalParams2: %empty  */
#line 125 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("ParamDecl", NULL); }
#line 1490 "src/y.tab.c"
    break;

  case 24: /* MethodBody: LBRACE MethodBody2 RBRACE  */
#line 129 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("MethodBody", NULL); add_children((yyval.node), (yyvsp[-1].node)); }
#line 1496 "src/y.tab.c"
    break;

  case 25: /* MethodBody2: Statement MethodBody2  */
#line 131 "src/jucompiler.y"
                                                                                { (yyval.node) = (yyvsp[-1].node); add_brother((yyval.node), (yyvsp[0].node)); }
#line 1502 "src/y.tab.c"
    break;

  case 26: /* MethodBody2: VarDecl MethodBody2  */
#line 132 "src/jucompiler.y"
                                                                                { (yyval.node) = (yyvsp[-1].node); add_brother((yyval.node), (yyvsp[0].node));}
#line 1508 "src/y.tab.c"
    break;

  case 27: /* MethodBody2: %empty  */
#line 133 "src/jucompiler.y"
                                                                                { (yyval.node) = NULL;}
#line 1514 "src/y.tab.c"
    break;

  case 28: /* VarDecl: Type ID VarDecl2 SEMICOLON  */
#line 138 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("VarDecl", NULL); aux = ast_node("Id", (yyvsp[-2].token)); add_children((yyval.node), aux); add_brother((yyval.node), (yyvsp[-1].node));}
#line 1520 "src/y.tab.c"
    break;

  case 29: /* VarDecl2: COMMA ID VarDecl2  */
#line 140 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("VarDecl", NULL); aux = ast_node("Id", (yyvsp[-1].token)); add_children((yyval.node), aux); add_brother((yyval.node), (yyvsp[0].node)); }
#line 1526 "src/y.tab.c"
    break;

  case 30: /* VarDecl2: %empty  */
#line 141 "src/jucompiler.y"
                                                                                { (yyval.node) = NULL; }
#line 1532 "src/y.tab.c"
    break;

  case 31: /* Statement: LBRACE Statement2 RBRACE  */
#line 183 "src/jucompiler.y"
                                                                                { (yyval.node) = (yyvsp[-1].node); }
#line 1538 "src/y.tab.c"
    break;

  case 32: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 184 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("If", NULL); add_children((yyval.node), (yyvsp[-4].node)); add_brother((yyvsp[-4].node), (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[0].node)); add_brother((yyvsp[0].node), ast_node("Block", NULL)); }
#line 1544 "src/y.tab.c"
    break;

  case 33: /* Statement: IF LPAR Expr RPAR Statement  */
#line 185 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("If", NULL); add_children((yyval.node), (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[0].node)); add_brother((yyvsp[0].node), ast_node("Block", NULL)); }
#line 1550 "src/y.tab.c"
    break;

  case 34: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 186 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("While", NULL); add_children((yyval.node), (yyvsp[-2].node)); add_children((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1556 "src/y.tab.c"
    break;

  case 35: /* Statement: RETURN Expr SEMICOLON  */
#line 187 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Return", NULL); add_children((yyval.node), (yyvsp[-1].node)); }
#line 1562 "src/y.tab.c"
    break;

  case 36: /* Statement: RETURN SEMICOLON  */
#line 188 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Return", NULL); }
#line 1568 "src/y.tab.c"
    break;

  case 37: /* Statement: MethodInvocation SEMICOLON  */
#line 189 "src/jucompiler.y"
                                                                                { (yyval.node) = (yyvsp[-1].node); }
#line 1574 "src/y.tab.c"
    break;

  case 38: /* Statement: Assignment SEMICOLON  */
#line 190 "src/jucompiler.y"
                                                                                { (yyval.node) = (yyvsp[-1].node); }
#line 1580 "src/y.tab.c"
    break;

  case 39: /* Statement: ParseArgs SEMICOLON  */
#line 191 "src/jucompiler.y"
                                                                                { (yyval.node) = (yyvsp[-1].node); }
#line 1586 "src/y.tab.c"
    break;

  case 40: /* Statement: error SEMICOLON  */
#line 192 "src/jucompiler.y"
                                                                                      { (yyval.node) = NULL; }
#line 1592 "src/y.tab.c"
    break;

  case 41: /* Statement: SEMICOLON  */
#line 193 "src/jucompiler.y"
                                                                                { (yyval.node) = NULL; }
#line 1598 "src/y.tab.c"
    break;

  case 42: /* Statement: PRINT LPAR Expr RPAR SEMICOLON  */
#line 194 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Print", NULL); add_children((yyval.node), (yyvsp[-2].node));  }
#line 1604 "src/y.tab.c"
    break;

  case 43: /* Statement: PRINT LPAR STRLIT RPAR SEMICOLON  */
#line 195 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Print", NULL); add_children((yyval.node), ast_node("StrLit", (yyvsp[-2].token)));  }
#line 1610 "src/y.tab.c"
    break;

  case 44: /* Statement2: Statement Statement2  */
#line 198 "src/jucompiler.y"
                                         { (yyval.node) = (yyvsp[-1].node); add_brother((yyval.node), (yyvsp[0].node)); }
#line 1616 "src/y.tab.c"
    break;

  case 45: /* Statement2: %empty  */
#line 199 "src/jucompiler.y"
            { (yyval.node) = NULL;}
#line 1622 "src/y.tab.c"
    break;

  case 46: /* MethodInvocation: ID LPAR RPAR  */
#line 201 "src/jucompiler.y"
                                                                                {  (yyval.node) = ast_node("Call", NULL); aux = ast_node("Id", (yyvsp[-2].token)); add_children((yyval.node), aux);  }
#line 1628 "src/y.tab.c"
    break;

  case 47: /* MethodInvocation: ID LPAR error RPAR  */
#line 202 "src/jucompiler.y"
                                                                                {  (yyval.node) = NULL; free((yyvsp[-3].token));}
#line 1634 "src/y.tab.c"
    break;

  case 48: /* MethodInvocation: ID LPAR Expr MethodInvocation2 RPAR  */
#line 203 "src/jucompiler.y"
                                                                                {  (yyval.node) = ast_node("Call", NULL); aux = ast_node("Id", (yyvsp[-4].token)); add_children((yyval.node), aux); add_brother(aux, (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[-1].node));  }
#line 1640 "src/y.tab.c"
    break;

  case 49: /* MethodInvocation2: COMMA Expr MethodInvocation2  */
#line 206 "src/jucompiler.y"
                                                                                { (yyval.node) = (yyvsp[-1].node); add_brother((yyval.node), (yyvsp[0].node)); }
#line 1646 "src/y.tab.c"
    break;

  case 50: /* MethodInvocation2: error  */
#line 207 "src/jucompiler.y"
                                                                                { (yyval.node) = NULL;}
#line 1652 "src/y.tab.c"
    break;

  case 51: /* MethodInvocation2: %empty  */
#line 208 "src/jucompiler.y"
                                                                                { (yyval.node) = NULL; }
#line 1658 "src/y.tab.c"
    break;

  case 52: /* Assignment: ID ASSIGN Expr  */
#line 212 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Assign", NULL); aux = ast_node("Id", (yyvsp[-2].token)); add_children((yyval.node), aux); add_brother(aux, (yyvsp[0].node)); /*addicionar expr*/ }
#line 1664 "src/y.tab.c"
    break;

  case 53: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 215 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("ParseArgs", NULL); aux = ast_node("Id", (yyvsp[-4].token)); add_children((yyval.node), aux); add_brother(aux, (yyvsp[-2].node)); }
#line 1670 "src/y.tab.c"
    break;

  case 54: /* ParseArgs: PARSEINT LPAR error RPAR  */
#line 216 "src/jucompiler.y"
                                      {(yyval.node)= NULL;}
#line 1676 "src/y.tab.c"
    break;

  case 55: /* Expr: Expr PLUS Expr  */
#line 218 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Add", NULL); add_children((yyval.node), (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[0].node));; }
#line 1682 "src/y.tab.c"
    break;

  case 56: /* Expr: Expr MINUS Expr  */
#line 219 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Sub", NULL); add_children((yyval.node), (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[0].node));; }
#line 1688 "src/y.tab.c"
    break;

  case 57: /* Expr: Expr STAR Expr  */
#line 220 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Mul", NULL); add_children((yyval.node), (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[0].node));; }
#line 1694 "src/y.tab.c"
    break;

  case 58: /* Expr: Expr DIV Expr  */
#line 221 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Div", NULL); add_children((yyval.node), (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[0].node));; }
#line 1700 "src/y.tab.c"
    break;

  case 59: /* Expr: Expr MOD Expr  */
#line 222 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Mod", NULL); add_children((yyval.node), (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[0].node));; }
#line 1706 "src/y.tab.c"
    break;

  case 60: /* Expr: Expr AND Expr  */
#line 223 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("And", NULL); add_children((yyval.node), (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[0].node));; }
#line 1712 "src/y.tab.c"
    break;

  case 61: /* Expr: Expr OR Expr  */
#line 224 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Or", NULL); add_children((yyval.node), (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[0].node));; }
#line 1718 "src/y.tab.c"
    break;

  case 62: /* Expr: Expr XOR Expr  */
#line 225 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Xor", NULL); add_children((yyval.node), (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[0].node));; }
#line 1724 "src/y.tab.c"
    break;

  case 63: /* Expr: Expr LSHIFT Expr  */
#line 226 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Lshift", NULL); add_children((yyval.node), (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[0].node));; }
#line 1730 "src/y.tab.c"
    break;

  case 64: /* Expr: Expr RSHIFT Expr  */
#line 227 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Rshift", NULL); add_children((yyval.node), (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[0].node));; }
#line 1736 "src/y.tab.c"
    break;

  case 65: /* Expr: Expr EQ Expr  */
#line 228 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Eq", NULL); add_children((yyval.node), (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1742 "src/y.tab.c"
    break;

  case 66: /* Expr: Expr GE Expr  */
#line 229 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Ge", NULL); add_children((yyval.node), (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1748 "src/y.tab.c"
    break;

  case 67: /* Expr: Expr GT Expr  */
#line 230 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Gt", NULL); add_children((yyval.node), (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1754 "src/y.tab.c"
    break;

  case 68: /* Expr: Expr LE Expr  */
#line 231 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Le", NULL); add_children((yyval.node), (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1760 "src/y.tab.c"
    break;

  case 69: /* Expr: Expr LT Expr  */
#line 232 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Lt", NULL); add_children((yyval.node), (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1766 "src/y.tab.c"
    break;

  case 70: /* Expr: Expr NE Expr  */
#line 233 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("NE", NULL); add_children((yyval.node), (yyvsp[-2].node)); add_brother((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1772 "src/y.tab.c"
    break;

  case 71: /* Expr: MINUS Expr  */
#line 234 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Minus", NULL); add_children((yyval.node), (yyvsp[0].node)); }
#line 1778 "src/y.tab.c"
    break;

  case 72: /* Expr: NOT Expr  */
#line 235 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Not", NULL); add_children((yyval.node), (yyvsp[0].node)); }
#line 1784 "src/y.tab.c"
    break;

  case 73: /* Expr: PLUS Expr  */
#line 236 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Plus", NULL); add_children((yyval.node), (yyvsp[0].node)); }
#line 1790 "src/y.tab.c"
    break;

  case 74: /* Expr: LPAR Expr RPAR  */
#line 237 "src/jucompiler.y"
                                                                                { (yyval.node) = (yyvsp[-1].node); }
#line 1796 "src/y.tab.c"
    break;

  case 75: /* Expr: LPAR error RPAR  */
#line 238 "src/jucompiler.y"
                                                                                { (yyval.node) = NULL; }
#line 1802 "src/y.tab.c"
    break;

  case 76: /* Expr: MethodInvocation  */
#line 239 "src/jucompiler.y"
                                                                                { (yyval.node) = (yyvsp[0].node); }
#line 1808 "src/y.tab.c"
    break;

  case 77: /* Expr: Assignment  */
#line 240 "src/jucompiler.y"
                                                                                { (yyval.node) = (yyvsp[0].node); }
#line 1814 "src/y.tab.c"
    break;

  case 78: /* Expr: ParseArgs  */
#line 241 "src/jucompiler.y"
                                                                                { (yyval.node) = (yyvsp[0].node); }
#line 1820 "src/y.tab.c"
    break;

  case 79: /* Expr: ID DOTLENGTH  */
#line 242 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Id", (yyvsp[-1].token)); }
#line 1826 "src/y.tab.c"
    break;

  case 80: /* Expr: ID  */
#line 243 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("Id", (yyvsp[0].token)); }
#line 1832 "src/y.tab.c"
    break;

  case 81: /* Expr: INTLIT  */
#line 244 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("DecLit", (yyvsp[0].token)); }
#line 1838 "src/y.tab.c"
    break;

  case 82: /* Expr: REALLIT  */
#line 245 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("RealLit", (yyvsp[0].token)); }
#line 1844 "src/y.tab.c"
    break;

  case 83: /* Expr: BOOLLIT  */
#line 246 "src/jucompiler.y"
                                                                                { (yyval.node) = ast_node("BoolLit", (yyvsp[0].token)); }
#line 1850 "src/y.tab.c"
    break;


#line 1854 "src/y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 249 "src/jucompiler.y"



void flags(int argc, char *argv[]) {
}


int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; ++i) {
      if (!strcmp(argv[i], "-l")) {
           e1 = t = e2 = false;
           l = true;  
      } else if (!strcmp(argv[i], "-e1")){
          t = l = e2 = false;
          e1 = true;
      } else if (!strcmp(argv[i], "-e2")) {
          e1 = t = l = false;
          e2 = true;
      } else if (!strcmp(argv[i], "-t")) {
          l = e2 = e1 = false;
          t = true; 
      }
  }

  if (l || e1) {
      return yylex();
  } 
 
  if (e2) {
      yyparse(); 
  } else if (t) {
      yyparse();
      print_ast(my_program);  
  }
  // yylex();kk
  //yyparse();
  //print_ast(my_program);
  free_ast(my_program);
  return 0;
}


