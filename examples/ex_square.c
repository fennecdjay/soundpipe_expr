#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "soundpipe.h"
#include "expr.h"
typedef struct {
    sp_expr *expr;
} UserData;

void process(sp_data *sp, void *udata) {
    UserData *ud = udata;
    if(sp->pos % (sp->sr / 400) == 0)
        ud->expr->val[0] *= -1;
	sp_expr_compute(sp, ud->expr, &sp->out[0]);
}

int main() {
	char* names[] = { "x" };
    srand(1234567);
    UserData ud;
    sp_data *sp;
    sp_create(&sp);

	sp_expr_create(&ud.expr);

	sp_expr_init(sp, ud.expr, "x", names, 1);
    ud.expr->val[0] = 1;

    sp->len = 44100 * 5;
    sp_process(sp, &ud, process);

    sp_expr_destroy(&ud.expr);

    sp_destroy(&sp);
    return 0;

}
