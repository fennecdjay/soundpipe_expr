#include <stdlib.h>
#include <soundpipe.h>
#include "tinyexpr.h"
#include "expr.h"

int sp_expr_create(sp_expr **p) {
    sp_expr* expr = *p;
    expr = malloc(sizeof(sp_expr));
    *p = expr;
    return SP_OK;
}

int sp_expr_destroy(sp_expr **p) {
    sp_expr* expr = *p;
    te_free(expr->exp);
    free(expr->var);
    free(expr->val);
    free(expr);
    return SP_OK;
}

int sp_expr_init(sp_data *sp, sp_expr *p, char* exp, char** names, int num) {
    int i, error;
    p->val = calloc(num, sizeof(double));
    p->var = malloc(num * sizeof(te_variable));
    for(i = 0; i < num; i++) {
        p->var[i].name = names[i];
        p->var[i].type = TE_VARIABLE;
        p->var[i].address = &p->val[i];
    }
    p->exp = te_compile(exp, p->var, num, 0);
    return p->exp ? SP_OK : SP_NOT_OK;
}

int sp_expr_compute(sp_data *sp, sp_expr *p, SPFLOAT *out) {
    *out = p->exp ? (SPFLOAT)te_eval(p->exp) : 0.0;
    return SP_OK;
}
