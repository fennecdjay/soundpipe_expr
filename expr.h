#include <stdlib.h>
#include <soundpipe.h>
#include "tinyexpr.h"

typedef struct {
  te_expr*      exp;
  te_variable* var;
  double*      val;
} sp_expr;

int sp_expr_create(sp_expr **p);
int sp_expr_destroy(sp_expr **p);
int sp_expr_init(sp_data *sp, sp_expr *p, char* exp, char** names, int num);
int sp_expr_compute(sp_data *sp, sp_expr *p, SPFLOAT *out);
