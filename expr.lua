sptbl["expr"] = {
    files = {
        module  = "adsr.c",
        header  = "adsr.h",
        example = "examples/ex_square.c",
    },
    func = {
        create  = "sp_expr_create",
        destroy = "sp_expr_destroy",
        init    = "sp_zxpr_init",
        compute = "sp_expr_compute",
    },
	params = {
		mandatory = {
			{
				name        = "exp",
				type        = "char*"
				description = "expression to parse"
				default = "N/A"
			},
			{
				name        = "names",
				type        = "char**"
				description = "array of variable names"
				default = "N/A"
			},
			{
				name        = "num",
				type        = "int"
				description = "umber of variables"
				default = "N/A"
			}
		}
	},
	modtype = "module",
	description == [[ parse mathematical expression ]],
	ninputs = 0,
    noutputs = 1,
    outputs = {
        {
            name = "out",
            description = "result of expression."
        },
    }
}
