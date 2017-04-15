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
    ud->expr->val[2] = sp->pos;
	sp_expr_compute(sp, ud->expr, &sp->out[0]);
}

int main() {
	char* names[] = { "freq", "sr", "pos" };
    srand(1234567);
    UserData ud;
    sp_data *sp;
    sp_create(&sp);

	sp_expr_create(&ud.expr);

	sp_expr_init(sp, ud.expr, "sin (pos/sr*freq * 6.28)", names, 3);
    ud.expr->val[0] = 440;
    ud.expr->val[1] = sp->sr;

    sp->len = sp->sr * 5;
    sp_process(sp, &ud, process);

    sp_expr_destroy(&ud.expr);

    sp_destroy(&sp);
    return 0;

}
