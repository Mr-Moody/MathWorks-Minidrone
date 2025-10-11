/* Include files */

#include "flightControlSystem_sfun.h"
#include "c4_flightControlSystem.h"
#include <string.h>
#include "mwmathutil.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

/* Forward Declarations */

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static emlrtMCInfo c4_emlrtMCI = { 87, /* lineNo */
  33,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtMCInfo c4_b_emlrtMCI = { 26,/* lineNo */
  23,                                  /* colNo */
  "polyfit",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m"/* pName */
};

static emlrtMCInfo c4_c_emlrtMCI = { 45,/* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pName */
};

static emlrtMCInfo c4_d_emlrtMCI = { 48,/* lineNo */
  13,                                  /* colNo */
  "infocheck",                         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\infocheck.m"/* pName */
};

static emlrtMCInfo c4_e_emlrtMCI = { 13,/* lineNo */
  9,                                   /* colNo */
  "sqrt",                              /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m"/* pName */
};

static emlrtMCInfo c4_f_emlrtMCI = { 18,/* lineNo */
  27,                                  /* colNo */
  "eml_int_forloop_overflow_check",    /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pName */
};

static emlrtRSInfo c4_emlrtRSI = { 60, /* lineNo */
  "Control System/Path Planning/Chart/control/MATLAB Function",/* fcnName */
  "#flightControlSystem:2685::128"     /* pathName */
};

static emlrtRSInfo c4_b_emlrtRSI = { 62,/* lineNo */
  "Control System/Path Planning/Chart/control/MATLAB Function",/* fcnName */
  "#flightControlSystem:2685::128"     /* pathName */
};

static emlrtRSInfo c4_c_emlrtRSI = { 147,/* lineNo */
  "bwboundaries",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwboundaries.m"/* pathName */
};

static emlrtRSInfo c4_d_emlrtRSI = { 149,/* lineNo */
  "bwboundaries",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwboundaries.m"/* pathName */
};

static emlrtRSInfo c4_e_emlrtRSI = { 42,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c4_f_emlrtRSI = { 178,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c4_g_emlrtRSI = { 181,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c4_h_emlrtRSI = { 184,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c4_i_emlrtRSI = { 196,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c4_j_emlrtRSI = { 323,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c4_k_emlrtRSI = { 325,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c4_l_emlrtRSI = { 329,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c4_m_emlrtRSI = { 331,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c4_n_emlrtRSI = { 20,/* lineNo */
  "eml_int_forloop_overflow_check",    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"/* pathName */
};

static emlrtRSInfo c4_o_emlrtRSI = { 97,/* lineNo */
  "imclearborder",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imclearborder.m"/* pathName */
};

static emlrtRSInfo c4_p_emlrtRSI = { 22,/* lineNo */
  "mustBeConnectivity",                /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\mustBeConnectivity.m"/* pathName */
};

static emlrtRSInfo c4_q_emlrtRSI = { 20,/* lineNo */
  "mustBeMember",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\validators\\mustBeMember.m"/* pathName */
};

static emlrtRSInfo c4_r_emlrtRSI = { 78,/* lineNo */
  "imclearborder",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imclearborder.m"/* pathName */
};

static emlrtRSInfo c4_s_emlrtRSI = { 243,/* lineNo */
  "imkeepborder",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pathName */
};

static emlrtRSInfo c4_t_emlrtRSI = { 239,/* lineNo */
  "bwboundaries",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwboundaries.m"/* pathName */
};

static emlrtRSInfo c4_u_emlrtRSI = { 240,/* lineNo */
  "bwboundaries",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwboundaries.m"/* pathName */
};

static emlrtRSInfo c4_v_emlrtRSI = { 256,/* lineNo */
  "bwboundaries",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwboundaries.m"/* pathName */
};

static emlrtRSInfo c4_w_emlrtRSI = { 257,/* lineNo */
  "bwboundaries",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwboundaries.m"/* pathName */
};

static emlrtRSInfo c4_x_emlrtRSI = { 8,/* lineNo */
  "imclearborder",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imclearborder.m"/* pathName */
};

static emlrtRSInfo c4_y_emlrtRSI = { 14,/* lineNo */
  "imclearborder",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imclearborder.m"/* pathName */
};

static emlrtRSInfo c4_ab_emlrtRSI = { 36,/* lineNo */
  "imclearborder",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imclearborder.m"/* pathName */
};

static emlrtRSInfo c4_bb_emlrtRSI = { 8,/* lineNo */
  "imkeepborder",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pathName */
};

static emlrtRSInfo c4_cb_emlrtRSI = { 100,/* lineNo */
  "imkeepborder",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pathName */
};

static emlrtRSInfo c4_db_emlrtRSI = { 116,/* lineNo */
  "imkeepborder",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pathName */
};

static emlrtRSInfo c4_eb_emlrtRSI = { 191,/* lineNo */
  "imkeepborder",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pathName */
};

static emlrtRSInfo c4_fb_emlrtRSI = { 224,/* lineNo */
  "imkeepborder",                      /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pathName */
};

static emlrtRSInfo c4_gb_emlrtRSI = { 28,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c4_hb_emlrtRSI = { 125,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c4_ib_emlrtRSI = { 328,/* lineNo */
  "colon",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pathName */
};

static emlrtRSInfo c4_jb_emlrtRSI = { 78,/* lineNo */
  "imreconstruct",                     /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imreconstruct.m"/* pathName */
};

static emlrtRSInfo c4_kb_emlrtRSI = { 287,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c4_lb_emlrtRSI = { 298,/* lineNo */
  "bwlabel",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m"/* pathName */
};

static emlrtRSInfo c4_mb_emlrtRSI = { 29,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c4_nb_emlrtRSI = { 26,/* lineNo */
  "BoundaryFinder",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pathName */
};

static emlrtRSInfo c4_ob_emlrtRSI = { 29,/* lineNo */
  "BoundaryFinder",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pathName */
};

static emlrtRSInfo c4_pb_emlrtRSI = { 40,/* lineNo */
  "BoundaryFinder",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pathName */
};

static emlrtRSInfo c4_qb_emlrtRSI = { 91,/* lineNo */
  "padarray",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\padarray.m"/* pathName */
};

static emlrtRSInfo c4_rb_emlrtRSI = { 56,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c4_sb_emlrtRSI = { 57,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c4_tb_emlrtRSI = { 58,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c4_ub_emlrtRSI = { 71,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c4_vb_emlrtRSI = { 81,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c4_wb_emlrtRSI = { 220,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c4_xb_emlrtRSI = { 252,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c4_yb_emlrtRSI = { 291,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c4_ac_emlrtRSI = { 192,/* lineNo */
  "BoundaryFinder",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pathName */
};

static emlrtRSInfo c4_bc_emlrtRSI = { 36,/* lineNo */
  "polyfit",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m"/* pathName */
};

static emlrtRSInfo c4_cc_emlrtRSI = { 40,/* lineNo */
  "polyfit",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m"/* pathName */
};

static emlrtRSInfo c4_dc_emlrtRSI = { 47,/* lineNo */
  "polyfit",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m"/* pathName */
};

static emlrtRSInfo c4_ec_emlrtRSI = { 61,/* lineNo */
  "qrsolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_fc_emlrtRSI = { 80,/* lineNo */
  "qrsolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_gc_emlrtRSI = { 85,/* lineNo */
  "qrsolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_hc_emlrtRSI = { 63,/* lineNo */
  "xgeqp3",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_ic_emlrtRSI = { 138,/* lineNo */
  "xgeqp3",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_jc_emlrtRSI = { 143,/* lineNo */
  "xgeqp3",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_kc_emlrtRSI = { 148,/* lineNo */
  "xgeqp3",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_lc_emlrtRSI = { 119,/* lineNo */
  "xzgeqp3",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_mc_emlrtRSI = { 174,/* lineNo */
  "xzgeqp3",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_nc_emlrtRSI = { 189,/* lineNo */
  "xzgeqp3",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzgeqp3.m"/* pathName */
};

static emlrtRSInfo c4_oc_emlrtRSI = { 30,/* lineNo */
  "xswap",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xswap.m"/* pathName */
};

static emlrtRSInfo c4_pc_emlrtRSI = { 20,/* lineNo */
  "xswap",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xswap.m"/* pathName */
};

static emlrtRSInfo c4_qc_emlrtRSI = { 81,/* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo c4_rc_emlrtRSI = { 71,/* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo c4_sc_emlrtRSI = { 68,/* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo c4_tc_emlrtRSI = { 41,/* lineNo */
  "xzlarfg",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarfg.m"/* pathName */
};

static emlrtRSInfo c4_uc_emlrtRSI = { 37,/* lineNo */
  "xscal",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xscal.m"/* pathName */
};

static emlrtRSInfo c4_vc_emlrtRSI = { 49,/* lineNo */
  "xscal",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xscal.m"/* pathName */
};

static emlrtRSInfo c4_wc_emlrtRSI = { 68,/* lineNo */
  "xzlarf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo c4_xc_emlrtRSI = { 75,/* lineNo */
  "xzlarf",                            /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzlarf.m"/* pathName */
};

static emlrtRSInfo c4_yc_emlrtRSI = { 86,/* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv.m"/* pathName */
};

static emlrtRSInfo c4_ad_emlrtRSI = { 98,/* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv.m"/* pathName */
};

static emlrtRSInfo c4_bd_emlrtRSI = { 37,/* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

static emlrtRSInfo c4_cd_emlrtRSI = { 71,/* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgemv.m"/* pathName */
};

static emlrtRSInfo c4_dd_emlrtRSI = { 113,/* lineNo */
  "xgemv",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemv.m"/* pathName */
};

static emlrtRSInfo c4_ed_emlrtRSI = { 45,/* lineNo */
  "xgerc",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgerc.m"/* pathName */
};

static emlrtRSInfo c4_fd_emlrtRSI = { 45,/* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xger.m"/* pathName */
};

static emlrtRSInfo c4_gd_emlrtRSI = { 53,/* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xger.m"/* pathName */
};

static emlrtRSInfo c4_hd_emlrtRSI = { 15,/* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xger.m"/* pathName */
};

static emlrtRSInfo c4_id_emlrtRSI = { 41,/* lineNo */
  "xgerx",                             /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+refblas\\xgerx.m"/* pathName */
};

static emlrtRSInfo c4_jd_emlrtRSI = { 67,/* lineNo */
  "xger",                              /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xger.m"/* pathName */
};

static emlrtRSInfo c4_kd_emlrtRSI = { 189,/* lineNo */
  "qrsolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_ld_emlrtRSI = { 119,/* lineNo */
  "qrsolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_md_emlrtRSI = { 128,/* lineNo */
  "qrsolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_nd_emlrtRSI = { 138,/* lineNo */
  "qrsolve",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pathName */
};

static emlrtRSInfo c4_od_emlrtRSI = { 40,/* lineNo */
  "xunormqr",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xunormqr.m"/* pathName */
};

static emlrtRSInfo c4_pd_emlrtRSI = { 106,/* lineNo */
  "xunormqr",                          /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xunormqr.m"/* pathName */
};

static emlrtRSInfo c4_qd_emlrtRSI = { 21,/* lineNo */
  "xzunormqr",                         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+reflapack\\xzunormqr.m"/* pathName */
};

static emlrtRSInfo c4_rd_emlrtRSI = { 14,/* lineNo */
  "warning",                           /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+internal\\warning.m"/* pathName */
};

static emlrtRTEInfo c4_emlrtRTEI = { 62,/* lineNo */
  17,                                  /* colNo */
  "Control System/Path Planning/Chart/control/MATLAB Function",/* fName */
  "#flightControlSystem:2685::128"     /* pName */
};

static emlrtRTEInfo c4_b_emlrtRTEI = { 62,/* lineNo */
  31,                                  /* colNo */
  "Control System/Path Planning/Chart/control/MATLAB Function",/* fName */
  "#flightControlSystem:2685::128"     /* pName */
};

static emlrtRTEInfo c4_c_emlrtRTEI = { 62,/* lineNo */
  27,                                  /* colNo */
  "Control System/Path Planning/Chart/control/MATLAB Function",/* fName */
  "#flightControlSystem:2685::128"     /* pName */
};

static emlrtRTEInfo c4_d_emlrtRTEI = { 87,/* lineNo */
  5,                                   /* colNo */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pName */
};

static emlrtRTEInfo c4_e_emlrtRTEI = { 171,/* lineNo */
  5,                                   /* colNo */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pName */
};

static emlrtRTEInfo c4_f_emlrtRTEI = { 172,/* lineNo */
  26,                                  /* colNo */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pName */
};

static emlrtRTEInfo c4_g_emlrtRTEI = { 106,/* lineNo */
  30,                                  /* colNo */
  "applyToMultipleDims",               /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\applyToMultipleDims.m"/* pName */
};

static emlrtRTEInfo c4_h_emlrtRTEI = { 178,/* lineNo */
  5,                                   /* colNo */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pName */
};

static emlrtRTEInfo c4_i_emlrtRTEI = { 179,/* lineNo */
  27,                                  /* colNo */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pName */
};

static emlrtRTEInfo c4_j_emlrtRTEI = { 100,/* lineNo */
  5,                                   /* colNo */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pName */
};

static emlrtRTEInfo c4_k_emlrtRTEI = { 114,/* lineNo */
  8,                                   /* colNo */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imkeepborder.m"/* pName */
};

static emlrtRTEInfo c4_l_emlrtRTEI = { 320,/* lineNo */
  20,                                  /* colNo */
  "colon",                             /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\ops\\colon.m"/* pName */
};

static emlrtRTEInfo c4_m_emlrtRTEI = { 39,/* lineNo */
  22,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c4_n_emlrtRTEI = { 51,/* lineNo */
  48,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c4_o_emlrtRTEI = { 52,/* lineNo */
  13,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c4_p_emlrtRTEI = { 171,/* lineNo */
  38,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c4_q_emlrtRTEI = { 72,/* lineNo */
  29,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c4_r_emlrtRTEI = { 82,/* lineNo */
  29,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c4_s_emlrtRTEI = { 220,/* lineNo */
  30,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c4_t_emlrtRTEI = { 290,/* lineNo */
  26,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c4_u_emlrtRTEI = { 191,/* lineNo */
  39,                                  /* colNo */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pName */
};

static emlrtRTEInfo c4_v_emlrtRTEI = { 17,/* lineNo */
  20,                                  /* colNo */
  "vander",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\vander.m"/* pName */
};

static emlrtRTEInfo c4_w_emlrtRTEI = { 92,/* lineNo */
  22,                                  /* colNo */
  "xgeqp3",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pName */
};

static emlrtRTEInfo c4_x_emlrtRTEI = { 97,/* lineNo */
  5,                                   /* colNo */
  "xgeqp3",                            /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\+lapack\\xgeqp3.m"/* pName */
};

static emlrtRTEInfo c4_y_emlrtRTEI = { 85,/* lineNo */
  26,                                  /* colNo */
  "qrsolve",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pName */
};

static emlrtRTEInfo c4_ab_emlrtRTEI = { 119,/* lineNo */
  5,                                   /* colNo */
  "qrsolve",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\eml\\+coder\\+internal\\qrsolve.m"/* pName */
};

static emlrtRTEInfo c4_bb_emlrtRTEI = { 60,/* lineNo */
  6,                                   /* colNo */
  "Control System/Path Planning/Chart/control/MATLAB Function",/* fName */
  "#flightControlSystem:2685::128"     /* pName */
};

static emlrtRTEInfo c4_cb_emlrtRTEI = { 62,/* lineNo */
  22,                                  /* colNo */
  "Control System/Path Planning/Chart/control/MATLAB Function",/* fName */
  "#flightControlSystem:2685::128"     /* pName */
};

static emlrtRTEInfo c4_db_emlrtRTEI = { 62,/* lineNo */
  36,                                  /* colNo */
  "Control System/Path Planning/Chart/control/MATLAB Function",/* fName */
  "#flightControlSystem:2685::128"     /* pName */
};

static emlrtRTEInfo c4_eb_emlrtRTEI = { 71,/* lineNo */
  29,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c4_fb_emlrtRTEI = { 171,/* lineNo */
  13,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtRTEInfo c4_gb_emlrtRTEI = { 32,/* lineNo */
  1,                                   /* colNo */
  "polyfit",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\eml\\lib\\matlab\\polyfun\\polyfit.m"/* pName */
};

static emlrtBCInfo c4_emlrtBCI = { -1, /* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  19,                                  /* colNo */
  "B",                                 /* aName */
  "Control System/Path Planning/Chart/control/MATLAB Function",/* fName */
  "#flightControlSystem:2685::128",    /* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_b_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  62,                                  /* lineNo */
  33,                                  /* colNo */
  "B",                                 /* aName */
  "Control System/Path Planning/Chart/control/MATLAB Function",/* fName */
  "#flightControlSystem:2685::128",    /* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_emlrtDCI = { 114,/* lineNo */
  8,                                   /* colNo */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imkeepborder.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_c_emlrtBCI = { 1,/* iFirst */
  120,                                 /* iLast */
  114,                                 /* lineNo */
  8,                                   /* colNo */
  "",                                  /* aName */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imkeepborder.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_d_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  114,                                 /* lineNo */
  8,                                   /* colNo */
  "",                                  /* aName */
  "imkeepborder",                      /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\imkeepborder.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_e_emlrtBCI = { 1,/* iFirst */
  122,                                 /* iLast */
  724,                                 /* lineNo */
  19,                                  /* colNo */
  "",                                  /* aName */
  "padarray",                          /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\padarray.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_f_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  151,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_g_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  346,                                 /* lineNo */
  11,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_h_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  349,                                 /* lineNo */
  7,                                   /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_i_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  188,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_j_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  176,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_k_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  177,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_l_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  180,                                 /* lineNo */
  38,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_m_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  178,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_n_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  315,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_o_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  183,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_p_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  181,                                 /* lineNo */
  57,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_q_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  184,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_r_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  337,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_s_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  338,                                 /* lineNo */
  18,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_t_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  196,                                 /* lineNo */
  75,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_u_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  344,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_v_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  345,                                 /* lineNo */
  15,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_w_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  204,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_x_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  197,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_y_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  76,                                  /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ab_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  198,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_bb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  85,                                  /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_cb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  86,                                  /* lineNo */
  52,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_db_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  114,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_eb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  115,                                 /* lineNo */
  56,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_fb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  103,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_gb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  90,                                  /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_hb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  108,                                 /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_ib_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  104,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_jb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  91,                                  /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_kb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  132,                                 /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_lb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  119,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_mb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  105,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_nb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  137,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_ob_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  133,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_pb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  120,                                 /* lineNo */
  59,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_qb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  134,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_rb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  96,                                  /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_sb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  101,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_tb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  97,                                  /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ub_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  125,                                 /* lineNo */
  53,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_vb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  98,                                  /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_wb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  130,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_xb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  126,                                 /* lineNo */
  55,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_yb_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  127,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_ac_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  263,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_bc_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  290,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_cc_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  286,                                 /* lineNo */
  24,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_dc_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  286,                                 /* lineNo */
  34,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ec_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  287,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_fc_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  298,                                 /* lineNo */
  75,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_gc_emlrtBCI = { 1,/* iFirst */
  160,                                 /* iLast */
  224,                                 /* lineNo */
  29,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_hc_emlrtBCI = { 1,/* iFirst */
  168,                                 /* iLast */
  306,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ic_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  299,                                 /* lineNo */
  22,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_jc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  300,                                 /* lineNo */
  30,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_kc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  230,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_lc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  231,                                 /* lineNo */
  48,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_mc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  248,                                 /* lineNo */
  41,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_nc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  235,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_oc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  253,                                 /* lineNo */
  35,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_pc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  249,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_qc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  236,                                 /* lineNo */
  51,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_rc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  250,                                 /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_sc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  241,                                 /* lineNo */
  45,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_tc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  246,                                 /* lineNo */
  39,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_uc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  242,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_vc_emlrtBCI = { 1,/* iFirst */
  9601,                                /* iLast */
  243,                                 /* lineNo */
  43,                                  /* colNo */
  "",                                  /* aName */
  "bwlabel",                           /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\eml\\bwlabel.m",/* pName */
  3                                    /* checkKind */
};

static emlrtBCInfo c4_wc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  72,                                  /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_xc_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  82,                                  /* lineNo */
  31,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtRTEInfo c4_hb_emlrtRTEI = { 186,/* lineNo */
  25,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pName */
};

static emlrtDCInfo c4_b_emlrtDCI = { 51,/* lineNo */
  37,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  1                                    /* checkKind */
};

static emlrtDCInfo c4_c_emlrtDCI = { 52,/* lineNo */
  13,                                  /* colNo */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  1                                    /* checkKind */
};

static emlrtBCInfo c4_yc_emlrtBCI = { 1,/* iFirst */
  19764,                               /* iLast */
  63,                                  /* lineNo */
  83,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ad_emlrtBCI = { 1,/* iFirst */
  19764,                               /* iLast */
  64,                                  /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_bd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  68,                                  /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_cd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  78,                                  /* lineNo */
  54,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_dd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  73,                                  /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ed_emlrtBCI = { 1,/* iFirst */
  8,                                   /* iLast */
  189,                                 /* lineNo */
  95,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_fd_emlrtBCI = { 1,/* iFirst */
  19764,                               /* iLast */
  194,                                 /* lineNo */
  47,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_gd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  83,                                  /* lineNo */
  49,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_hd_emlrtBCI = { 1,/* iFirst */
  8,                                   /* iLast */
  191,                                 /* lineNo */
  100,                                 /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_id_emlrtBCI = { 1,/* iFirst */
  8,                                   /* iLast */
  236,                                 /* lineNo */
  58,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_jd_emlrtBCI = { 1,/* iFirst */
  8,                                   /* iLast */
  238,                                 /* lineNo */
  63,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_kd_emlrtBCI = { 1,/* iFirst */
  8,                                   /* iLast */
  213,                                 /* lineNo */
  72,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_ld_emlrtBCI = { 1,/* iFirst */
  8,                                   /* iLast */
  215,                                 /* lineNo */
  77,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_md_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  224,                                 /* lineNo */
  33,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_nd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  292,                                 /* lineNo */
  28,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_od_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  292,                                 /* lineNo */
  13,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinderObjectHoles",         /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_pd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  193,                                 /* lineNo */
  64,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_qd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  194,                                 /* lineNo */
  37,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_rd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  195,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m",/* pName */
  0                                    /* checkKind */
};

static emlrtBCInfo c4_sd_emlrtBCI = { -1,/* iFirst */
  -1,                                  /* iLast */
  196,                                 /* lineNo */
  26,                                  /* colNo */
  "",                                  /* aName */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m",/* pName */
  0                                    /* checkKind */
};

static emlrtDCInfo c4_d_emlrtDCI = { 191,/* lineNo */
  45,                                  /* colNo */
  "BoundaryFinder",                    /* fName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m",/* pName */
  4                                    /* checkKind */
};

static emlrtRSInfo c4_sd_emlrtRSI = { 191,/* lineNo */
  "BoundaryFinder",                    /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinder.m"/* pathName */
};

static emlrtRSInfo c4_td_emlrtRSI = { 82,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c4_ud_emlrtRSI = { 72,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c4_vd_emlrtRSI = { 51,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c4_wd_emlrtRSI = { 52,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

static emlrtRSInfo c4_xd_emlrtRSI = { 290,/* lineNo */
  "BoundaryFinderObjectHoles",         /* fcnName */
  "C:\\Program Files\\MATLAB\\R2024b\\toolbox\\images\\images\\+images\\+internal\\+coder\\BoundaryFinderObjectHoles.m"/* pathName */
};

/* Function Declarations */
static void initialize_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void initialize_params_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_start_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_terminate_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_setup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void mdl_cleanup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void enable_c4_flightControlSystem(SFc4_flightControlSystemInstanceStruct
  *chartInstance);
static void disable_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void sf_gateway_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void ext_mode_exec_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void c4_update_jit_animation_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void c4_do_animation_call_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance);
static void set_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const mxArray *c4_st);
static void c4_bwboundaries(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint8_T c4_varargin_1[19200],
  c4_coder_array_cell_wrap_0 *c4_B, real_T c4_c_L[19200]);
static void c4_bwlabel(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_varargin_1[19200], real_T c4_c_L[19200],
  real_T *c4_numComponents);
static void c4_check_forloop_overflow_error
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp);
static void c4_validateConnectivity(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp);
static void c4_eml_float_colon(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_a, real_T c4_b_b, real_T
  c4_y_data[], int32_T c4_y_size[2]);
static void c4_b_bwlabel(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_varargin_1[19200], real_T c4_c_L[19200],
  real_T *c4_numComponents);
static void c4_BoundaryFinderObjectHoles_findBoundaries
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_images_internal_coder_BoundaryFinderObjectHoles *c4_obj, real_T
   c4_cutoffL, real_T c4_holesN, c4_coder_array_cell_wrap_0 *c4_B);
static void c4_expandScratchSpace(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T *c4_scratchIn,
  int32_T c4_scratchLengthIn, c4_coder_array_int32_T *c4_scratch, int32_T
  *c4_scratchLength);
static void c4_BoundaryFinder_copyCoordsToBuf
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_images_internal_coder_BoundaryFinderObjectHoles *c4_obj, int32_T
   c4_numPixels, c4_coder_array_int32_T *c4_linearIndices,
   c4_coder_array_real_T_2D *c4_boundary);
static void c4_polyfit(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_coder_array_real_T *c4_x, c4_coder_array_real_T
  *c4_y, real_T c4_p[2]);
static void c4_warning(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp);
static void c4_b_warning(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp);
static real32_T c4_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_nullptr, const char_T *c4_identifier);
static real32_T c4_b_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_feval(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c4_sp, const mxArray *c4_input0, const
                     mxArray *c4_input1, const mxArray *c4_input2);
static const mxArray *c4_assert(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1);
static const mxArray *c4_b_feval(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1);
static void c4_c_feval(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1);
static const mxArray *c4_d_feval(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1);
static void c4_e_feval(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1);
static void c4_array_real_T_2D_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_real_T_2D
  *c4_coderArray, const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0, int32_T
  c4_size1);
static void c4_array_real_T_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_real_T *c4_coderArray,
  const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0);
static void c4_array_cell_wrap_0_SetSize(SFc4_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c4_sp, c4_coder_array_cell_wrap_0
  *c4_coderArray, const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0);
static void c4_array_real_T_2D_Destructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_real_T_2D *c4_coderArray);
static void c4_array_cell_wrap_0_Destructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance, c4_cell_wrap_0
   *c4_pStruct);
static void c4_array_cell_wrap_0_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance, c4_cell_wrap_0
   *c4_pStruct);
static void c4_array_real_T_2D_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_real_T_2D *c4_coderArray);
static void c4_array_boolean_T_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_boolean_T
  *c4_coderArray, const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0);
static void c4_array_int32_T_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T *c4_coderArray,
  const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0);
static void c4_array_cell_wrap_0_Constructor1
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_cell_wrap_0 *c4_coderArray);
static void c4_array_real_T_Constructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_real_T *c4_coderArray);
static void c4_array_cell_wrap_0_Destructor1
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_cell_wrap_0 *c4_coderArray);
static void c4_array_real_T_Destructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_real_T *c4_coderArray);
static void c4_array_boolean_T_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_boolean_T *c4_coderArray);
static void c4_array_int32_T_Constructor(SFc4_flightControlSystemInstanceStruct *
  chartInstance, c4_coder_array_int32_T *c4_coderArray);
static void c4_array_boolean_T_Destructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_boolean_T *c4_coderArray);
static void c4_array_int32_T_Destructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_int32_T *c4_coderArray);
static int32_T c4_div_s32_ndbzs(SFc4_flightControlSystemInstanceStruct
  *chartInstance, int32_T c4_numerator, int32_T c4_denominator, int32_T
  c4_EMLOvCount_src_loc, uint32_T c4_ssid_src_loc, int32_T c4_offset_src_loc,
  int32_T c4_length_src_loc);
static void init_dsm_address_info(SFc4_flightControlSystemInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc4_flightControlSystemInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  emlrtStack c4_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  emlrtLicenseCheckR2022a(&c4_st, "EMLRT:runTime:MexFunctionNeedsLicense",
    "image_toolbox", 2);
  sim_mode_is_external(chartInstance->S);
  chartInstance->c4_doneDoubleBufferReInit = false;
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void initialize_params_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_start_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void mdl_terminate_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void mdl_setup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  static const int32_T c4_postfixPredicateTree[3] = { 0, 1, -2 };

  static const int32_T c4_condTxtEndIdx[2] = { 1548, 1564 };

  static const int32_T c4_condTxtStartIdx[2] = { 1538, 1552 };

  static const uint32_T c4_decisionTxtEndIdx = 0U;
  static const uint32_T c4_decisionTxtStartIdx = 0U;
  sfSetAnimationVectors(chartInstance->S, &chartInstance->c4_JITStateAnimation[0],
                        &chartInstance->c4_JITTransitionAnimation[0]);
  covrtCreateStateflowInstanceData(chartInstance->c4_covrtInstance, 1U, 0U, 1U,
    40U);
  covrtChartInitFcn(chartInstance->c4_covrtInstance, 0U, false, false, false);
  covrtStateInitFcn(chartInstance->c4_covrtInstance, 0U, 0U, false, false, false,
                    0U, &c4_decisionTxtStartIdx, &c4_decisionTxtEndIdx);
  covrtTransInitFcn(chartInstance->c4_covrtInstance, 0U, 0, NULL, NULL, 0U, NULL);
  covrtEmlInitFcn(chartInstance->c4_covrtInstance, "", 4U, 0U, 1U, 0U, 1U, 0U,
                  0U, 0U, 0U, 0U, 2U, 1U);
  covrtEmlFcnInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U,
                     "c4_flightControlSystem", 0, -1, 1799);
  covrtEmlIfInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 1535, 1564,
                    1629, 1636, false);
  covrtEmlMCDCInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 1538, 1564,
                      2U, 0U, &c4_condTxtStartIdx[0], &c4_condTxtEndIdx[0], 3U,
                      &c4_postfixPredicateTree[0], false);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 0U, 1538,
    1548, -1, 4U);
  covrtEmlRelationalInitFcn(chartInstance->c4_covrtInstance, 4U, 0U, 1U, 1552,
    1564, -1, 2U);
}

static void mdl_cleanup_runtime_resources_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  covrtDeleteStateflowInstanceData(chartInstance->c4_covrtInstance);
}

static void enable_c4_flightControlSystem(SFc4_flightControlSystemInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void sf_gateway_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  c4_coder_array_cell_wrap_0 c4_B;
  c4_coder_array_real_T c4_r2;
  c4_coder_array_real_T c4_r3;
  c4_coder_array_real_T_2D c4_r;
  c4_coder_array_real_T_2D c4_r1;
  emlrtStack c4_b_st;
  emlrtStack c4_st = { NULL,           /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  real_T c4_p[2];
  real_T c4_a;
  real_T c4_b_x;
  real_T c4_b_y;
  real_T c4_c_x;
  real_T c4_d_x;
  real_T c4_theta;
  real_T c4_x;
  real_T c4_y;
  int32_T c4_b_loop_ub;
  int32_T c4_c_loop_ub;
  int32_T c4_d_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_loop_ub;
  real32_T c4_b_forward;
  real32_T c4_b_right;
  uint8_T c4_uv[19200];
  c4_st.tls = chartInstance->c4_fEmlrtCtx;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  if (covrtIsSigCovEnabledFcn(chartInstance->c4_covrtInstance, 0U) != 0U) {
    for (c4_i = 0; c4_i < 19200; c4_i++) {
      covrtSigUpdateFcnAssumingCovEnabled(chartInstance->c4_covrtInstance, 0U,
        (real_T)(*chartInstance->c4_path)[c4_i]);
    }
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_JITTransitionAnimation[0] = 0U;
  chartInstance->c4_sfEvent = CALL_EVENT;
  covrtEmlFcnEval(chartInstance->c4_covrtInstance, 4U, 0, 0);
  c4_array_cell_wrap_0_Constructor1(chartInstance, &c4_B);
  c4_b_st.site = &c4_emlrtRSI;
  for (c4_i1 = 0; c4_i1 < 19200; c4_i1++) {
    c4_uv[c4_i1] = (*chartInstance->c4_path)[c4_i1];
  }

  c4_bwboundaries(chartInstance, &c4_b_st, c4_uv, &c4_B, chartInstance->c4_L);
  c4_i2 = c4_B.size[0] - 1;
  if (c4_i2 < 0) {
    emlrtDynamicBoundsCheckR2012b(0, 0, c4_i2, &c4_emlrtBCI, &c4_st);
  }

  c4_i3 = 0;
  c4_array_real_T_2D_Constructor(chartInstance, &c4_r);
  c4_array_real_T_2D_SetSize(chartInstance, &c4_st, &c4_r, &c4_emlrtRTEI,
    c4_B.vector.data[c4_i3].f1.size[0], 2);
  c4_loop_ub = (c4_B.vector.data[c4_i3].f1.size[0] << 1) - 1;
  for (c4_i4 = 0; c4_i4 <= c4_loop_ub; c4_i4++) {
    c4_r.vector.data[c4_i4] = c4_B.vector.data[c4_i3].f1.vector.data[c4_i4];
  }

  c4_i5 = c4_B.size[0] - 1;
  if (c4_i5 < 0) {
    emlrtDynamicBoundsCheckR2012b(0, 0, c4_i5, &c4_b_emlrtBCI, &c4_st);
  }

  c4_i6 = 0;
  c4_array_real_T_2D_Constructor(chartInstance, &c4_r1);
  c4_array_real_T_2D_SetSize(chartInstance, &c4_st, &c4_r1, &c4_b_emlrtRTEI,
    c4_B.vector.data[c4_i6].f1.size[0], 2);
  c4_b_loop_ub = (c4_B.vector.data[c4_i6].f1.size[0] << 1) - 1;
  for (c4_i7 = 0; c4_i7 <= c4_b_loop_ub; c4_i7++) {
    c4_r1.vector.data[c4_i7] = c4_B.vector.data[c4_i6].f1.vector.data[c4_i7];
  }

  c4_array_cell_wrap_0_Destructor1(chartInstance, &c4_B);
  c4_array_real_T_Constructor(chartInstance, &c4_r2);
  c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_r2, &c4_emlrtRTEI,
    c4_r.size[0]);
  c4_c_loop_ub = c4_r.size[0] - 1;
  for (c4_i8 = 0; c4_i8 <= c4_c_loop_ub; c4_i8++) {
    c4_r2.vector.data[c4_i8] = c4_r.vector.data[c4_i8 + c4_r.size[0]];
  }

  c4_array_real_T_2D_Destructor(chartInstance, &c4_r);
  c4_array_real_T_Constructor(chartInstance, &c4_r3);
  c4_array_real_T_SetSize(chartInstance, &c4_st, &c4_r3, &c4_c_emlrtRTEI,
    c4_r1.size[0]);
  c4_d_loop_ub = c4_r1.size[0] - 1;
  for (c4_i9 = 0; c4_i9 <= c4_d_loop_ub; c4_i9++) {
    c4_r3.vector.data[c4_i9] = 120.0 - c4_r1.vector.data[c4_i9];
  }

  c4_array_real_T_2D_Destructor(chartInstance, &c4_r1);
  c4_b_st.site = &c4_b_emlrtRSI;
  c4_polyfit(chartInstance, &c4_b_st, &c4_r2, &c4_r3, c4_p);
  c4_array_real_T_Destructor(chartInstance, &c4_r3);
  c4_array_real_T_Destructor(chartInstance, &c4_r2);
  if (covrtEmlCondEval(chartInstance->c4_covrtInstance, 4U, 0, 0,
                       covrtRelationalopUpdateFcn
                       (chartInstance->c4_covrtInstance, 4U, 0U, 0U, c4_p[0],
                        1000.0, -1, 4U, c4_p[0] > 1000.0)) || covrtEmlCondEval
      (chartInstance->c4_covrtInstance, 4U, 0, 1, covrtRelationalopUpdateFcn
       (chartInstance->c4_covrtInstance, 4U, 0U, 1U, c4_p[0], -1000.0, -1, 2U,
        c4_p[0] < -1000.0))) {
    covrtEmlMcdcEval(chartInstance->c4_covrtInstance, 4U, 0, 0, true);
    covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 0, true);
    c4_b_right = 0.0F;
    c4_b_forward = 0.1F;
  } else {
    covrtEmlMcdcEval(chartInstance->c4_covrtInstance, 4U, 0, 0, false);
    covrtEmlIfEval(chartInstance->c4_covrtInstance, 4U, 0, 0, false);
    c4_y = c4_p[0];
    c4_a = c4_y;
    c4_b_y = c4_a;
    c4_theta = muDoubleScalarAtan2(c4_b_y, 1.0);
    c4_x = c4_theta;
    c4_b_x = c4_x;
    c4_b_x = muDoubleScalarCos(c4_b_x);
    c4_b_right = (real32_T)(0.1 * c4_b_x);
    c4_c_x = c4_theta;
    c4_d_x = c4_c_x;
    c4_d_x = muDoubleScalarSin(c4_d_x);
    c4_b_forward = (real32_T)(0.1 * c4_d_x);
  }

  *chartInstance->c4_forward = c4_b_forward;
  *chartInstance->c4_right = c4_b_right;
  covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 1U, (real_T)
                    *chartInstance->c4_forward);
  covrtSigUpdateFcn(chartInstance->c4_covrtInstance, 2U, (real_T)
                    *chartInstance->c4_right);
}

static void ext_mode_exec_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_update_jit_animation_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c4_do_animation_call_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance)
{
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(2, 1), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", chartInstance->c4_forward, 1, 0U, 0,
    0U, 0), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", chartInstance->c4_right, 1, 0U, 0,
    0U, 0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_flightControlSystem
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *chartInstance->c4_forward = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 0)), "forward");
  *chartInstance->c4_right = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c4_u, 1)), "right");
  sf_mex_destroy(&c4_u);
  sf_mex_destroy(&c4_st);
}

static void c4_bwboundaries(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, uint8_T c4_varargin_1[19200],
  c4_coder_array_cell_wrap_0 *c4_B, real_T c4_c_L[19200])
{
  static char_T c4_cv[33] = { 'i', 'm', 'a', 'g', 'e', 's', ':', 'b', 'w', 'b',
    'o', 'u', 'n', 'd', 'a', 'r', 'i', 'e', 's', ':', 'b', 'a', 'd', 'S', 'c',
    'a', 'l', 'a', 'r', 'C', 'o', 'n', 'n' };

  static boolean_T c4_conn[9] = { false, true, false, true, true, true, false,
    true, false };

  c4_cell_wrap_1 c4_args[1];
  c4_cell_wrap_1 c4_r;
  c4_cell_wrap_14 c4_connSubs[2];
  c4_cell_wrap_14 c4_subs[2];
  c4_cell_wrap_14 c4_r1;
  c4_cell_wrap_14 c4_r2;
  c4_cell_wrap_14 c4_r3;
  c4_cell_wrap_14 c4_r4;
  c4_images_internal_coder_BoundaryFinderObjectHoles *c4_b_obj;
  c4_images_internal_coder_BoundaryFinderObjectHoles *c4_c_obj;
  c4_images_internal_coder_BoundaryFinderObjectHoles *c4_obj;
  c4_images_internal_coder_BoundaryFinderObjectHoles *c4_this;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_f_st;
  emlrtStack c4_st;
  const mxArray *c4_d_y = NULL;
  const mxArray *c4_e_y = NULL;
  real_T c4_imSizeT[2];
  real_T c4_N;
  real_T c4_a;
  real_T c4_b_N;
  real_T c4_b_a;
  real_T c4_b_d;
  real_T c4_b_j;
  real_T c4_b_x;
  real_T c4_b_y;
  real_T c4_c_a;
  real_T c4_c_b;
  real_T c4_c_d;
  real_T c4_c_i;
  real_T c4_c_x;
  real_T c4_c_y;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d_a;
  real_T c4_d_b;
  real_T c4_d_j;
  real_T c4_d_x;
  real_T c4_e_b;
  real_T c4_e_i;
  real_T c4_f_a;
  real_T c4_first;
  real_T c4_g_a;
  real_T c4_g_j;
  real_T c4_h_a;
  real_T c4_h_i;
  real_T c4_holesN;
  real_T c4_i_a;
  real_T c4_last;
  real_T c4_x;
  real_T c4_y;
  int32_T c4_b_tmp_data[160];
  int32_T c4_tmp_data[120];
  int32_T c4_iv[2];
  int32_T c4_b_tmp_size[1];
  int32_T c4_tmp_size[1];
  int32_T c4_b_c;
  int32_T c4_b_i;
  int32_T c4_b_ix;
  int32_T c4_b_loop_ub;
  int32_T c4_c;
  int32_T c4_c_c;
  int32_T c4_c_ix;
  int32_T c4_c_j;
  int32_T c4_c_loop_ub;
  int32_T c4_d_c;
  int32_T c4_d_i;
  int32_T c4_d_ix;
  int32_T c4_d_loop_ub;
  int32_T c4_e_j;
  int32_T c4_e_loop_ub;
  int32_T c4_f_i;
  int32_T c4_f_j;
  int32_T c4_f_loop_ub;
  int32_T c4_g_i;
  int32_T c4_g_loop_ub;
  int32_T c4_h_j;
  int32_T c4_h_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_i;
  int32_T c4_i_loop_ub;
  int32_T c4_ix;
  int32_T c4_j;
  int32_T c4_j_loop_ub;
  int32_T c4_loop_ub;
  uint8_T c4_b_varargin_1[19200];
  boolean_T c4_BWcomplement[19200];
  boolean_T c4_marker[19200];
  boolean_T c4_b_x_data[3];
  boolean_T c4_varargin_1_data[3];
  boolean_T c4_x_data[3];
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b3;
  boolean_T c4_b_b;
  boolean_T c4_e_a;
  boolean_T c4_exitg1;
  boolean_T c4_u;
  boolean_T c4_useFirstBorder;
  boolean_T c4_useSecondBorder;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  c4_f_st.prev = &c4_e_st;
  c4_f_st.tls = c4_e_st.tls;
  for (c4_i = 0; c4_i < 19200; c4_i++) {
    c4_r.f1[c4_i] = c4_varargin_1[c4_i];
  }

  c4_args[0] = c4_r;
  for (c4_i1 = 0; c4_i1 < 19200; c4_i1++) {
    c4_b_varargin_1[c4_i1] = c4_args[0].f1[c4_i1];
  }

  for (c4_j = 0; c4_j < 160; c4_j++) {
    c4_b_j = (real_T)c4_j + 1.0;
    for (c4_b_i = 0; c4_b_i < 120; c4_b_i++) {
      c4_c_i = (real_T)c4_b_i + 1.0;
      c4_BWcomplement[((int32_T)c4_c_i + 120 * ((int32_T)c4_b_j - 1)) - 1] =
        (c4_b_varargin_1[((int32_T)c4_c_i + 120 * ((int32_T)c4_b_j - 1)) - 1] !=
         0);
    }
  }

  c4_st.site = &c4_c_emlrtRSI;
  c4_bwlabel(chartInstance, &c4_st, c4_BWcomplement, chartInstance->c4_b_L,
             &c4_N);
  c4_st.site = &c4_d_emlrtRSI;
  c4_b_N = c4_N;
  for (c4_i2 = 0; c4_i2 < 19200; c4_i2++) {
    c4_BWcomplement[c4_i2] = !c4_BWcomplement[c4_i2];
  }

  c4_b_st.site = &c4_t_emlrtRSI;
  c4_c_st.site = &c4_x_emlrtRSI;
  c4_d_st.site = &c4_ab_emlrtRSI;
  c4_e_st.site = &c4_r_emlrtRSI;
  c4_validateConnectivity(chartInstance, &c4_e_st);
  c4_c_st.site = &c4_y_emlrtRSI;
  c4_d_st.site = &c4_bb_emlrtRSI;
  c4_e_st.site = &c4_eb_emlrtRSI;
  c4_f_st.site = &c4_fb_emlrtRSI;
  c4_validateConnectivity(chartInstance, &c4_f_st);
  c4_r1.f1.size[0] = 1;
  c4_r1.f1.size[1] = 3;
  for (c4_i3 = 0; c4_i3 < 3; c4_i3++) {
    c4_r1.f1.data[c4_i3] = 1.0 + (real_T)c4_i3;
  }

  c4_r2.f1.size[0] = 1;
  c4_r2.f1.size[1] = 3;
  for (c4_i4 = 0; c4_i4 < 3; c4_i4++) {
    c4_r2.f1.data[c4_i4] = 1.0 + (real_T)c4_i4;
  }

  c4_connSubs[0] = c4_r1;
  c4_connSubs[1] = c4_r2;
  c4_connSubs[0].f1.size[1] = 1;
  c4_connSubs[0].f1.data[0] = 1.0;
  for (c4_i5 = 0; c4_i5 < 3; c4_i5++) {
    c4_loop_ub = c4_connSubs[0].f1.size[1] - 1;
    for (c4_i7 = 0; c4_i7 <= c4_loop_ub; c4_i7++) {
      c4_x_data[c4_i7 + c4_i5] = c4_conn[((int32_T)c4_connSubs[0].f1.data[c4_i7]
        + 3 * ((int32_T)c4_connSubs[1].f1.data[c4_i5] - 1)) - 1];
    }
  }

  for (c4_i6 = 0; c4_i6 < 3; c4_i6++) {
    c4_varargin_1_data[c4_i6] = c4_x_data[c4_i6];
  }

  c4_useFirstBorder = false;
  c4_ix = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_ix + 1 < 4)) {
    if (!c4_varargin_1_data[c4_ix]) {
      c4_b_b = true;
    } else {
      c4_b_b = false;
    }

    if (!c4_b_b) {
      c4_useFirstBorder = true;
      c4_exitg1 = true;
    } else {
      c4_ix++;
    }
  }

  c4_connSubs[0].f1.size[1] = 1;
  c4_connSubs[0].f1.data[0] = 3.0;
  for (c4_i8 = 0; c4_i8 < 3; c4_i8++) {
    c4_b_loop_ub = c4_connSubs[0].f1.size[1] - 1;
    for (c4_i10 = 0; c4_i10 <= c4_b_loop_ub; c4_i10++) {
      c4_x_data[c4_i10 + c4_i8] = c4_conn[((int32_T)c4_connSubs[0]
        .f1.data[c4_i10] + 3 * ((int32_T)c4_connSubs[1].f1.data[c4_i8] - 1)) - 1];
    }
  }

  for (c4_i9 = 0; c4_i9 < 3; c4_i9++) {
    c4_varargin_1_data[c4_i9] = c4_x_data[c4_i9];
  }

  c4_useSecondBorder = false;
  c4_b_ix = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_b_ix + 1 < 4)) {
    if (!c4_varargin_1_data[c4_b_ix]) {
      c4_b1 = true;
    } else {
      c4_b1 = false;
    }

    if (!c4_b1) {
      c4_useSecondBorder = true;
      c4_exitg1 = true;
    } else {
      c4_b_ix++;
    }
  }

  if (c4_useFirstBorder) {
    c4_first = 2.0;
  } else {
    c4_first = 1.0;
  }

  if (c4_useSecondBorder) {
    c4_last = 119.0;
  } else {
    c4_last = 120.0;
  }

  c4_d_st.site = &c4_cb_emlrtRSI;
  c4_a = c4_first;
  c4_d = c4_last;
  c4_e_st.site = &c4_gb_emlrtRSI;
  c4_b_a = c4_a;
  c4_c_b = c4_d;
  c4_x = c4_b_a;
  c4_b_x = c4_x;
  c4_y = c4_b_x;
  c4_y = muDoubleScalarFloor(c4_y);
  if (c4_y == c4_b_a) {
    c4_subs[0].f1.size[1] = (int32_T)(c4_c_b - c4_b_a) + 1;
    c4_c_loop_ub = (int32_T)(c4_c_b - c4_b_a);
    for (c4_i11 = 0; c4_i11 <= c4_c_loop_ub; c4_i11++) {
      c4_subs[0].f1.data[c4_i11] = c4_b_a + (real_T)c4_i11;
    }
  } else {
    c4_f_st.site = &c4_hb_emlrtRSI;
    c4_eml_float_colon(chartInstance, &c4_f_st, c4_b_a, c4_c_b, c4_subs[0].
                       f1.data, c4_subs[0].f1.size);
  }

  c4_r3.f1.size[0] = 1;
  c4_r3.f1.size[1] = 3;
  for (c4_i12 = 0; c4_i12 < 3; c4_i12++) {
    c4_r3.f1.data[c4_i12] = 1.0 + (real_T)c4_i12;
  }

  c4_r4.f1.size[0] = 1;
  c4_r4.f1.size[1] = 3;
  for (c4_i13 = 0; c4_i13 < 3; c4_i13++) {
    c4_r4.f1.data[c4_i13] = 1.0 + (real_T)c4_i13;
  }

  c4_connSubs[0] = c4_r3;
  c4_connSubs[1] = c4_r4;
  c4_connSubs[1].f1.size[1] = 1;
  c4_connSubs[1].f1.data[0] = 1.0;
  c4_d_loop_ub = c4_connSubs[1].f1.size[1] - 1;
  for (c4_i14 = 0; c4_i14 <= c4_d_loop_ub; c4_i14++) {
    for (c4_i16 = 0; c4_i16 < 3; c4_i16++) {
      c4_b_x_data[c4_i16 + 3 * c4_i14] = c4_conn[((int32_T)c4_connSubs[0].
        f1.data[c4_i16] + 3 * ((int32_T)c4_connSubs[1].f1.data[c4_i14] - 1)) - 1];
    }
  }

  for (c4_i15 = 0; c4_i15 < 3; c4_i15++) {
    c4_varargin_1_data[c4_i15] = c4_b_x_data[c4_i15];
  }

  c4_useFirstBorder = false;
  c4_c_ix = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_c_ix + 1 < 4)) {
    if (!c4_varargin_1_data[c4_c_ix]) {
      c4_b2 = true;
    } else {
      c4_b2 = false;
    }

    if (!c4_b2) {
      c4_useFirstBorder = true;
      c4_exitg1 = true;
    } else {
      c4_c_ix++;
    }
  }

  c4_connSubs[1].f1.size[1] = 1;
  c4_connSubs[1].f1.data[0] = 3.0;
  c4_e_loop_ub = c4_connSubs[1].f1.size[1] - 1;
  for (c4_i17 = 0; c4_i17 <= c4_e_loop_ub; c4_i17++) {
    for (c4_i19 = 0; c4_i19 < 3; c4_i19++) {
      c4_b_x_data[c4_i19 + 3 * c4_i17] = c4_conn[((int32_T)c4_connSubs[0].
        f1.data[c4_i19] + 3 * ((int32_T)c4_connSubs[1].f1.data[c4_i17] - 1)) - 1];
    }
  }

  for (c4_i18 = 0; c4_i18 < 3; c4_i18++) {
    c4_varargin_1_data[c4_i18] = c4_b_x_data[c4_i18];
  }

  c4_useSecondBorder = false;
  c4_d_ix = 0;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_d_ix + 1 < 4)) {
    if (!c4_varargin_1_data[c4_d_ix]) {
      c4_b3 = true;
    } else {
      c4_b3 = false;
    }

    if (!c4_b3) {
      c4_useSecondBorder = true;
      c4_exitg1 = true;
    } else {
      c4_d_ix++;
    }
  }

  if (c4_useFirstBorder) {
    c4_first = 2.0;
  } else {
    c4_first = 1.0;
  }

  if (c4_useSecondBorder) {
    c4_last = 159.0;
  } else {
    c4_last = 160.0;
  }

  c4_d_st.site = &c4_cb_emlrtRSI;
  c4_c_a = c4_first;
  c4_b_d = c4_last;
  c4_e_st.site = &c4_gb_emlrtRSI;
  c4_d_a = c4_c_a;
  c4_d_b = c4_b_d;
  c4_c_x = c4_d_a;
  c4_d_x = c4_c_x;
  c4_b_y = c4_d_x;
  c4_b_y = muDoubleScalarFloor(c4_b_y);
  if (c4_b_y == c4_d_a) {
    c4_subs[1].f1.size[1] = (int32_T)(c4_d_b - c4_d_a) + 1;
    c4_f_loop_ub = (int32_T)(c4_d_b - c4_d_a);
    for (c4_i20 = 0; c4_i20 <= c4_f_loop_ub; c4_i20++) {
      c4_subs[1].f1.data[c4_i20] = c4_d_a + (real_T)c4_i20;
    }
  } else {
    c4_f_st.site = &c4_hb_emlrtRSI;
    c4_eml_float_colon(chartInstance, &c4_f_st, c4_d_a, c4_d_b, c4_subs[1].
                       f1.data, c4_subs[1].f1.size);
  }

  for (c4_i21 = 0; c4_i21 < 19200; c4_i21++) {
    c4_marker[c4_i21] = c4_BWcomplement[c4_i21];
  }

  c4_tmp_size[0] = c4_subs[0].f1.size[1];
  c4_g_loop_ub = c4_subs[0].f1.size[1] - 1;
  for (c4_i22 = 0; c4_i22 <= c4_g_loop_ub; c4_i22++) {
    c4_c_d = c4_subs[0].f1.data[c4_i22];
    if (c4_c_d != (real_T)(int32_T)muDoubleScalarFloor(c4_c_d)) {
      emlrtIntegerCheckR2012b(c4_c_d, &c4_emlrtDCI, &c4_c_st);
    }

    c4_i24 = (int32_T)c4_c_d;
    if ((c4_i24 < 1) || (c4_i24 > 120)) {
      emlrtDynamicBoundsCheckR2012b(c4_i24, 1, 120, &c4_c_emlrtBCI, &c4_c_st);
    }

    c4_tmp_data[c4_i22] = c4_i24;
  }

  c4_b_tmp_size[0] = c4_subs[1].f1.size[1];
  c4_h_loop_ub = c4_subs[1].f1.size[1] - 1;
  for (c4_i23 = 0; c4_i23 <= c4_h_loop_ub; c4_i23++) {
    c4_d1 = c4_subs[1].f1.data[c4_i23];
    if (c4_d1 != (real_T)(int32_T)muDoubleScalarFloor(c4_d1)) {
      emlrtIntegerCheckR2012b(c4_d1, &c4_emlrtDCI, &c4_c_st);
    }

    c4_i26 = (int32_T)c4_d1;
    if ((c4_i26 < 1) || (c4_i26 > 160)) {
      emlrtDynamicBoundsCheckR2012b(c4_i26, 1, 160, &c4_d_emlrtBCI, &c4_c_st);
    }

    c4_b_tmp_data[c4_i23] = c4_i26;
  }

  c4_iv[0] = c4_tmp_size[0];
  c4_iv[1] = c4_b_tmp_size[0];
  c4_i_loop_ub = c4_iv[1] - 1;
  for (c4_i25 = 0; c4_i25 <= c4_i_loop_ub; c4_i25++) {
    c4_j_loop_ub = c4_iv[0] - 1;
    for (c4_i27 = 0; c4_i27 <= c4_j_loop_ub; c4_i27++) {
      c4_marker[(c4_tmp_data[c4_i27] + 120 * (c4_b_tmp_data[c4_i25] - 1)) - 1] =
        false;
    }
  }

  c4_d_st.site = &c4_db_emlrtRSI;
  c4_e_st.site = &c4_jb_emlrtRSI;
  for (c4_i28 = 0; c4_i28 < 2; c4_i28++) {
    c4_imSizeT[c4_i28] = 120.0 + 40.0 * (real_T)c4_i28;
  }

  ippreconstruct_uint8((uint8_T *)&c4_marker[0], (uint8_T *)&c4_BWcomplement[0],
                       &c4_imSizeT[0], 1.0);
  for (c4_i29 = 0; c4_i29 < 19200; c4_i29++) {
    c4_marker[c4_i29] = !c4_marker[c4_i29];
  }

  for (c4_i30 = 0; c4_i30 < 19200; c4_i30++) {
    c4_BWcomplement[c4_i30] = (c4_BWcomplement[c4_i30] && c4_marker[c4_i30]);
  }

  c4_b_st.site = &c4_u_emlrtRSI;
  c4_b_bwlabel(chartInstance, &c4_b_st, c4_BWcomplement,
               chartInstance->c4_labeledHoles, &c4_holesN);
  for (c4_c_j = 0; c4_c_j < 160; c4_c_j++) {
    c4_d_j = (real_T)c4_c_j + 1.0;
    for (c4_d_i = 0; c4_d_i < 120; c4_d_i++) {
      c4_e_i = (real_T)c4_d_i + 1.0;
      c4_e_a = (chartInstance->c4_labeledHoles[((int32_T)c4_e_i + 120 *
                 ((int32_T)c4_d_j - 1)) - 1] != 0.0);
      c4_e_b = c4_b_N;
      c4_c_y = (real_T)c4_e_a * c4_e_b;
      c4_c_L[((int32_T)c4_e_i + 120 * ((int32_T)c4_d_j - 1)) - 1] =
        (chartInstance->c4_b_L[((int32_T)c4_e_i + 120 * ((int32_T)c4_d_j - 1)) -
         1] + c4_c_y) + chartInstance->c4_labeledHoles[((int32_T)c4_e_i + 120 *
        ((int32_T)c4_d_j - 1)) - 1];
    }
  }

  c4_b_st.site = &c4_v_emlrtRSI;
  c4_obj = &chartInstance->c4_finder;
  c4_b_obj = c4_obj;
  c4_c_st.site = &c4_mb_emlrtRSI;
  c4_c_obj = c4_b_obj;
  c4_b_obj = c4_c_obj;
  c4_d_st.site = &c4_nb_emlrtRSI;
  c4_this = c4_b_obj;
  c4_b_obj = c4_this;
  c4_d_st.site = &c4_ob_emlrtRSI;
  c4_e_st.site = &c4_qb_emlrtRSI;
  for (c4_f_i = 0; c4_f_i < 122; c4_f_i++) {
    c4_h_i = (real_T)c4_f_i + 1.0;
    chartInstance->c4_b[(int32_T)c4_h_i - 1] = 0.0;
  }

  for (c4_g_i = 0; c4_g_i < 122; c4_g_i++) {
    c4_h_i = (real_T)c4_g_i + 1.0;
    chartInstance->c4_b[(int32_T)c4_h_i + 19641] = 0.0;
  }

  for (c4_e_j = 0; c4_e_j < 160; c4_e_j++) {
    c4_g_j = (real_T)c4_e_j + 1.0;
    c4_f_a = c4_g_j;
    c4_c = (int32_T)c4_f_a;
    chartInstance->c4_b[122 * c4_c] = 0.0;
  }

  for (c4_f_j = 0; c4_f_j < 160; c4_f_j++) {
    c4_g_j = (real_T)c4_f_j + 1.0;
    c4_g_a = c4_g_j;
    c4_b_c = (int32_T)c4_g_a;
    chartInstance->c4_b[121 + 122 * c4_b_c] = 0.0;
  }

  for (c4_h_j = 0; c4_h_j < 160; c4_h_j++) {
    c4_g_j = (real_T)c4_h_j + 1.0;
    for (c4_i_i = 0; c4_i_i < 120; c4_i_i++) {
      c4_h_i = (real_T)c4_i_i + 1.0;
      c4_h_a = c4_h_i;
      c4_c_c = (int32_T)c4_h_a;
      c4_i_a = c4_g_j;
      c4_d_c = (int32_T)c4_i_a;
      c4_i32 = c4_c_c + 1;
      if ((c4_i32 < 1) || (c4_i32 > 122)) {
        emlrtDynamicBoundsCheckR2012b(c4_i32, 1, 122, &c4_e_emlrtBCI, &c4_e_st);
      }

      chartInstance->c4_b[(c4_i32 + 122 * c4_d_c) - 1] = c4_c_L[((int32_T)c4_h_i
        + 120 * ((int32_T)c4_g_j - 1)) - 1];
    }
  }

  for (c4_i31 = 0; c4_i31 < 19764; c4_i31++) {
    c4_b_obj->paddedLabelMatrix[c4_i31] = chartInstance->c4_b[c4_i31];
  }

  c4_b_obj->numRows = 122;
  c4_b_obj->numCols = 162;
  c4_u = true;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_u, 11, 0U, 0, 0U, 0), false);
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 33),
                false);
  c4_d_st.site = &c4_pb_emlrtRSI;
  c4_assert(chartInstance, &c4_d_st, c4_d_y, sf_mex_call(&c4_c_st, NULL,
             "message", 1U, 1U, 14, c4_e_y));
  c4_b_obj->conn = 8.0;
  c4_b_obj->ConnectivityHoles = 4.0;
  c4_b_st.site = &c4_w_emlrtRSI;
  c4_BoundaryFinderObjectHoles_findBoundaries(chartInstance, &c4_b_st,
    &chartInstance->c4_finder, c4_b_N, c4_holesN, c4_B);
}

static void c4_bwlabel(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_varargin_1[19200], real_T c4_c_L[19200],
  real_T *c4_numComponents)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  int64_T c4_i7;
  real_T c4_a;
  real_T c4_b_c;
  real_T c4_b_i;
  real_T c4_b_j;
  real_T c4_b_numComponents;
  real_T c4_b_r;
  real_T c4_b_root;
  real_T c4_b_rootj;
  real_T c4_b_thread;
  real_T c4_b_varargin_1;
  real_T c4_b_x;
  real_T c4_c_i;
  real_T c4_c_j;
  real_T c4_c_root;
  real_T c4_c_rootj;
  real_T c4_c_varargin_1;
  real_T c4_c_x;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d10;
  real_T c4_d11;
  real_T c4_d2;
  real_T c4_d3;
  real_T c4_d4;
  real_T c4_d5;
  real_T c4_d6;
  real_T c4_d7;
  real_T c4_d8;
  real_T c4_d9;
  real_T c4_d_a;
  real_T c4_d_i;
  real_T c4_d_j;
  real_T c4_d_root;
  real_T c4_d_rootj;
  real_T c4_d_x;
  real_T c4_e_i;
  real_T c4_e_j;
  real_T c4_e_root;
  real_T c4_e_x;
  real_T c4_f_i;
  real_T c4_f_j;
  real_T c4_f_root;
  real_T c4_firstLabel;
  real_T c4_g_i;
  real_T c4_g_j;
  real_T c4_h_i;
  real_T c4_h_j;
  real_T c4_i_i;
  real_T c4_i_j;
  real_T c4_j;
  real_T c4_j_i;
  real_T c4_j_j;
  real_T c4_k_i;
  real_T c4_k_x;
  real_T c4_l_i;
  real_T c4_l_x;
  real_T c4_label;
  real_T c4_m_i;
  real_T c4_minval;
  real_T c4_n_i;
  real_T c4_n_x;
  real_T c4_o_i;
  real_T c4_o_x;
  real_T c4_p_i;
  real_T c4_p_x;
  real_T c4_q_x;
  real_T c4_r_x;
  real_T c4_root;
  real_T c4_rootj;
  real_T c4_startC;
  real_T c4_x;
  real_T c4_y;
  real_T c4_z;
  int32_T c4_chunksSizeAndLabels[168];
  int32_T c4_b_a;
  int32_T c4_b_b;
  int32_T c4_b_q0;
  int32_T c4_b_q1;
  int32_T c4_b_qY;
  int32_T c4_b_y;
  int32_T c4_b_z;
  int32_T c4_c;
  int32_T c4_c_a;
  int32_T c4_c_b;
  int32_T c4_c_c;
  int32_T c4_c_q0;
  int32_T c4_c_q1;
  int32_T c4_c_qY;
  int32_T c4_c_r;
  int32_T c4_d_c;
  int32_T c4_d_q0;
  int32_T c4_d_q1;
  int32_T c4_d_qY;
  int32_T c4_d_r;
  int32_T c4_e_a;
  int32_T c4_e_q0;
  int32_T c4_e_q1;
  int32_T c4_e_qY;
  int32_T c4_exitg1;
  int32_T c4_f_a;
  int32_T c4_f_q0;
  int32_T c4_f_q1;
  int32_T c4_f_qY;
  int32_T c4_f_x;
  int32_T c4_g_q0;
  int32_T c4_g_q1;
  int32_T c4_g_qY;
  int32_T c4_g_x;
  int32_T c4_h_q0;
  int32_T c4_h_q1;
  int32_T c4_h_qY;
  int32_T c4_h_x;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i38;
  int32_T c4_i39;
  int32_T c4_i4;
  int32_T c4_i40;
  int32_T c4_i41;
  int32_T c4_i42;
  int32_T c4_i43;
  int32_T c4_i44;
  int32_T c4_i45;
  int32_T c4_i46;
  int32_T c4_i47;
  int32_T c4_i48;
  int32_T c4_i49;
  int32_T c4_i5;
  int32_T c4_i50;
  int32_T c4_i51;
  int32_T c4_i52;
  int32_T c4_i53;
  int32_T c4_i54;
  int32_T c4_i55;
  int32_T c4_i56;
  int32_T c4_i57;
  int32_T c4_i58;
  int32_T c4_i59;
  int32_T c4_i6;
  int32_T c4_i60;
  int32_T c4_i61;
  int32_T c4_i62;
  int32_T c4_i63;
  int32_T c4_i64;
  int32_T c4_i65;
  int32_T c4_i66;
  int32_T c4_i67;
  int32_T c4_i68;
  int32_T c4_i69;
  int32_T c4_i70;
  int32_T c4_i71;
  int32_T c4_i72;
  int32_T c4_i73;
  int32_T c4_i74;
  int32_T c4_i75;
  int32_T c4_i76;
  int32_T c4_i77;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_q0;
  int32_T c4_i_q1;
  int32_T c4_i_qY;
  int32_T c4_i_x;
  int32_T c4_j_q0;
  int32_T c4_j_q1;
  int32_T c4_j_qY;
  int32_T c4_j_x;
  int32_T c4_k_q0;
  int32_T c4_k_q1;
  int32_T c4_k_qY;
  int32_T c4_l_q0;
  int32_T c4_l_q1;
  int32_T c4_l_qY;
  int32_T c4_m_x;
  int32_T c4_q0;
  int32_T c4_q1;
  int32_T c4_qY;
  int32_T c4_q_i;
  int32_T c4_r;
  int32_T c4_stripeFirstLabel;
  int32_T c4_thread;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_e_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  chartInstance->c4_P[0] = 0.0;
  for (c4_thread = 0; c4_thread < 8; c4_thread++) {
    c4_b_thread = (real_T)c4_thread;
    c4_b_c = c4_b_thread * 20.0 + 1.0;
    c4_b_varargin_1 = (c4_b_thread + 1.0) * 20.0 + 1.0;
    c4_x = c4_b_varargin_1;
    c4_b_x = c4_x;
    c4_c_x = c4_b_x;
    c4_a = c4_c_x;
    c4_d_x = c4_a;
    c4_e_x = c4_d_x;
    c4_minval = muDoubleScalarMin(c4_e_x, 161.0);
    c4_d1 = muDoubleScalarRound(c4_minval);
    if (c4_d1 < 2.147483648E+9) {
      if (c4_d1 >= -2.147483648E+9) {
        c4_i = (int32_T)c4_d1;
      } else {
        c4_i = MIN_int32_T;
      }
    } else if (c4_d1 >= 2.147483648E+9) {
      c4_i = MAX_int32_T;
    } else {
      c4_i = 0;
    }

    c4_chunksSizeAndLabels[(int32_T)c4_b_c - 1] = c4_i;
    c4_k_x = c4_b_c / 2.0;
    c4_l_x = c4_k_x;
    c4_y = c4_l_x;
    c4_y = muDoubleScalarFloor(c4_y);
    c4_label = c4_y * 60.0 + 1.0;
    c4_firstLabel = c4_label;
    c4_startC = c4_b_c;
    c4_d6 = c4_b_thread * 20.0 + 1.0;
    c4_c_varargin_1 = (c4_b_thread + 1.0) * 20.0;
    c4_n_x = c4_c_varargin_1;
    c4_o_x = c4_n_x;
    c4_p_x = c4_o_x;
    c4_d_a = c4_p_x;
    c4_q_x = c4_d_a;
    c4_r_x = c4_q_x;
    c4_d7 = muDoubleScalarMin(c4_r_x, 160.0);
    c4_i10 = (int32_T)(c4_d7 + (1.0 - c4_d6));
    for (c4_d_c = 0; c4_d_c < c4_i10; c4_d_c++) {
      c4_b_c = c4_d6 + (real_T)c4_d_c;
      for (c4_d_r = 0; c4_d_r < 120; c4_d_r++) {
        c4_b_r = (real_T)c4_d_r + 1.0;
        c4_i15 = (int32_T)c4_b_c;
        if ((c4_i15 < 1) || (c4_i15 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c4_i15, 1, 160, &c4_y_emlrtBCI, &c4_st);
        }

        if (c4_varargin_1[((int32_T)c4_b_r + 120 * (c4_i15 - 1)) - 1]) {
          if ((c4_b_c > c4_startC) && c4_varargin_1[((int32_T)c4_b_r + 120 *
               ((int32_T)(c4_b_c - 1.0) - 1)) - 1]) {
            c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
              c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)(c4_b_c - 1.0) - 1)) - 1];
          } else if ((c4_b_r < 120.0) && (c4_b_c > c4_startC) && c4_varargin_1
                     [((int32_T)(c4_b_r + 1.0) + 120 * ((int32_T)(c4_b_c - 1.0)
                       - 1)) - 1]) {
            if ((c4_b_c > c4_startC) && (c4_b_r > 1.0) && c4_varargin_1
                [((int32_T)(c4_b_r - 1.0) + 120 * ((int32_T)(c4_b_c - 1.0) - 1))
                - 1]) {
              c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
                c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 * ((int32_T)(c4_b_c - 1.0)
                         - 1)) - 1];
              do {
                c4_exitg1 = 0;
                c4_i23 = (int32_T)(c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)
                  c4_b_c - 1)) - 1] + 1.0);
                if ((c4_i23 < 1) || (c4_i23 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i23, 1, 9601, &c4_bb_emlrtBCI,
                    &c4_st);
                }

                if (chartInstance->c4_P[c4_i23 - 1] < c4_c_L[((int32_T)c4_b_r +
                     120 * ((int32_T)c4_b_c - 1)) - 1]) {
                  c4_i31 = (int32_T)(c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)
                    c4_b_c - 1)) - 1] + 1.0);
                  if ((c4_i31 < 1) || (c4_i31 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i31, 1, 9601,
                      &c4_cb_emlrtBCI, &c4_st);
                  }

                  c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
                    chartInstance->c4_P[c4_i31 - 1];
                } else {
                  c4_exitg1 = 1;
                }
              } while (c4_exitg1 == 0);

              if (c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 * ((int32_T)(c4_b_c -
                     1.0) - 1)) - 1] != c4_c_L[((int32_T)(c4_b_r + 1.0) + 120 *
                   ((int32_T)(c4_b_c - 1.0) - 1)) - 1]) {
                c4_d_rootj = c4_c_L[((int32_T)(c4_b_r + 1.0) + 120 * ((int32_T)
                  (c4_b_c - 1.0) - 1)) - 1];
                do {
                  c4_exitg1 = 0;
                  c4_i45 = (int32_T)(c4_d_rootj + 1.0);
                  if ((c4_i45 < 1) || (c4_i45 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i45, 1, 9601,
                      &c4_gb_emlrtBCI, &c4_st);
                  }

                  if (chartInstance->c4_P[c4_i45 - 1] < c4_d_rootj) {
                    c4_i51 = (int32_T)(c4_d_rootj + 1.0);
                    if ((c4_i51 < 1) || (c4_i51 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c4_i51, 1, 9601,
                        &c4_jb_emlrtBCI, &c4_st);
                    }

                    c4_d_rootj = chartInstance->c4_P[c4_i51 - 1];
                  } else {
                    c4_exitg1 = 1;
                  }
                } while (c4_exitg1 == 0);

                if (c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] >
                    c4_d_rootj) {
                  c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
                    c4_d_rootj;
                }

                do {
                  c4_exitg1 = 0;
                  c4_i65 = (int32_T)(c4_c_L[((int32_T)(c4_b_r + 1.0) + 120 *
                    ((int32_T)(c4_b_c - 1.0) - 1)) - 1] + 1.0);
                  if ((c4_i65 < 1) || (c4_i65 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i65, 1, 9601,
                      &c4_rb_emlrtBCI, &c4_st);
                  }

                  if (chartInstance->c4_P[c4_i65 - 1] < c4_c_L[((int32_T)(c4_b_r
                        + 1.0) + 120 * ((int32_T)(c4_b_c - 1.0) - 1)) - 1]) {
                    c4_i71 = (int32_T)(c4_c_L[((int32_T)(c4_b_r + 1.0) + 120 *
                      ((int32_T)(c4_b_c - 1.0) - 1)) - 1] + 1.0);
                    if ((c4_i71 < 1) || (c4_i71 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c4_i71, 1, 9601,
                        &c4_tb_emlrtBCI, &c4_st);
                    }

                    c4_g_j = chartInstance->c4_P[c4_i71 - 1];
                    c4_i76 = (int32_T)(c4_c_L[((int32_T)(c4_b_r + 1.0) + 120 *
                      ((int32_T)(c4_b_c - 1.0) - 1)) - 1] + 1.0);
                    if ((c4_i76 < 1) || (c4_i76 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c4_i76, 1, 9601,
                        &c4_vb_emlrtBCI, &c4_st);
                    }

                    chartInstance->c4_P[c4_i76 - 1] = c4_c_L[((int32_T)c4_b_r +
                      120 * ((int32_T)c4_b_c - 1)) - 1];
                    c4_c_L[((int32_T)(c4_b_r + 1.0) + 120 * ((int32_T)(c4_b_c -
                              1.0) - 1)) - 1] = c4_g_j;
                  } else {
                    c4_exitg1 = 1;
                  }
                } while (c4_exitg1 == 0);

                c4_i74 = (int32_T)(c4_c_L[((int32_T)(c4_b_r + 1.0) + 120 *
                  ((int32_T)(c4_b_c - 1.0) - 1)) - 1] + 1.0);
                if ((c4_i74 < 1) || (c4_i74 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i74, 1, 9601, &c4_sb_emlrtBCI,
                    &c4_st);
                }

                chartInstance->c4_P[c4_i74 - 1] = c4_c_L[((int32_T)c4_b_r + 120 *
                  ((int32_T)c4_b_c - 1)) - 1];
              }

              do {
                c4_exitg1 = 0;
                c4_i44 = (int32_T)(c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 *
                  ((int32_T)(c4_b_c - 1.0) - 1)) - 1] + 1.0);
                if ((c4_i44 < 1) || (c4_i44 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i44, 1, 9601, &c4_fb_emlrtBCI,
                    &c4_st);
                }

                if (chartInstance->c4_P[c4_i44 - 1] < c4_c_L[((int32_T)(c4_b_r -
                      1.0) + 120 * ((int32_T)(c4_b_c - 1.0) - 1)) - 1]) {
                  c4_i50 = (int32_T)(c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 *
                    ((int32_T)(c4_b_c - 1.0) - 1)) - 1] + 1.0);
                  if ((c4_i50 < 1) || (c4_i50 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i50, 1, 9601,
                      &c4_ib_emlrtBCI, &c4_st);
                  }

                  c4_g_j = chartInstance->c4_P[c4_i50 - 1];
                  c4_i59 = (int32_T)(c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 *
                    ((int32_T)(c4_b_c - 1.0) - 1)) - 1] + 1.0);
                  if ((c4_i59 < 1) || (c4_i59 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i59, 1, 9601,
                      &c4_mb_emlrtBCI, &c4_st);
                  }

                  chartInstance->c4_P[c4_i59 - 1] = c4_c_L[((int32_T)c4_b_r +
                    120 * ((int32_T)c4_b_c - 1)) - 1];
                  c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 * ((int32_T)(c4_b_c -
                            1.0) - 1)) - 1] = c4_g_j;
                } else {
                  c4_exitg1 = 1;
                }
              } while (c4_exitg1 == 0);

              c4_i57 = (int32_T)(c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 *
                ((int32_T)(c4_b_c - 1.0) - 1)) - 1] + 1.0);
              if ((c4_i57 < 1) || (c4_i57 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i57, 1, 9601, &c4_hb_emlrtBCI,
                  &c4_st);
              }

              chartInstance->c4_P[c4_i57 - 1] = c4_c_L[((int32_T)c4_b_r + 120 *
                ((int32_T)c4_b_c - 1)) - 1];
            } else if ((c4_b_r > 1.0) && c4_varargin_1[((int32_T)(c4_b_r - 1.0)
                        + 120 * ((int32_T)c4_b_c - 1)) - 1]) {
              c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
                c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 * ((int32_T)c4_b_c - 1)) -
                1];
              do {
                c4_exitg1 = 0;
                c4_i25 = (int32_T)(c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)
                  c4_b_c - 1)) - 1] + 1.0);
                if ((c4_i25 < 1) || (c4_i25 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i25, 1, 9601, &c4_db_emlrtBCI,
                    &c4_st);
                }

                if (chartInstance->c4_P[c4_i25 - 1] < c4_c_L[((int32_T)c4_b_r +
                     120 * ((int32_T)c4_b_c - 1)) - 1]) {
                  c4_i33 = (int32_T)(c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)
                    c4_b_c - 1)) - 1] + 1.0);
                  if ((c4_i33 < 1) || (c4_i33 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i33, 1, 9601,
                      &c4_eb_emlrtBCI, &c4_st);
                  }

                  c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
                    chartInstance->c4_P[c4_i33 - 1];
                } else {
                  c4_exitg1 = 1;
                }
              } while (c4_exitg1 == 0);

              if (c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 * ((int32_T)c4_b_c - 1))
                  - 1] != c4_c_L[((int32_T)(c4_b_r + 1.0) + 120 * ((int32_T)
                    (c4_b_c - 1.0) - 1)) - 1]) {
                c4_d_rootj = c4_c_L[((int32_T)(c4_b_r + 1.0) + 120 * ((int32_T)
                  (c4_b_c - 1.0) - 1)) - 1];
                do {
                  c4_exitg1 = 0;
                  c4_i48 = (int32_T)(c4_d_rootj + 1.0);
                  if ((c4_i48 < 1) || (c4_i48 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i48, 1, 9601,
                      &c4_lb_emlrtBCI, &c4_st);
                  }

                  if (chartInstance->c4_P[c4_i48 - 1] < c4_d_rootj) {
                    c4_i54 = (int32_T)(c4_d_rootj + 1.0);
                    if ((c4_i54 < 1) || (c4_i54 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c4_i54, 1, 9601,
                        &c4_pb_emlrtBCI, &c4_st);
                    }

                    c4_d_rootj = chartInstance->c4_P[c4_i54 - 1];
                  } else {
                    c4_exitg1 = 1;
                  }
                } while (c4_exitg1 == 0);

                if (c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] >
                    c4_d_rootj) {
                  c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
                    c4_d_rootj;
                }

                do {
                  c4_exitg1 = 0;
                  c4_i67 = (int32_T)(c4_c_L[((int32_T)(c4_b_r + 1.0) + 120 *
                    ((int32_T)(c4_b_c - 1.0) - 1)) - 1] + 1.0);
                  if ((c4_i67 < 1) || (c4_i67 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i67, 1, 9601,
                      &c4_ub_emlrtBCI, &c4_st);
                  }

                  if (chartInstance->c4_P[c4_i67 - 1] < c4_c_L[((int32_T)(c4_b_r
                        + 1.0) + 120 * ((int32_T)(c4_b_c - 1.0) - 1)) - 1]) {
                    c4_i72 = (int32_T)(c4_c_L[((int32_T)(c4_b_r + 1.0) + 120 *
                      ((int32_T)(c4_b_c - 1.0) - 1)) - 1] + 1.0);
                    if ((c4_i72 < 1) || (c4_i72 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c4_i72, 1, 9601,
                        &c4_xb_emlrtBCI, &c4_st);
                    }

                    c4_g_j = chartInstance->c4_P[c4_i72 - 1];
                    c4_i77 = (int32_T)(c4_c_L[((int32_T)(c4_b_r + 1.0) + 120 *
                      ((int32_T)(c4_b_c - 1.0) - 1)) - 1] + 1.0);
                    if ((c4_i77 < 1) || (c4_i77 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c4_i77, 1, 9601,
                        &c4_yb_emlrtBCI, &c4_st);
                    }

                    chartInstance->c4_P[c4_i77 - 1] = c4_c_L[((int32_T)c4_b_r +
                      120 * ((int32_T)c4_b_c - 1)) - 1];
                    c4_c_L[((int32_T)(c4_b_r + 1.0) + 120 * ((int32_T)(c4_b_c -
                              1.0) - 1)) - 1] = c4_g_j;
                  } else {
                    c4_exitg1 = 1;
                  }
                } while (c4_exitg1 == 0);

                c4_i75 = (int32_T)(c4_c_L[((int32_T)(c4_b_r + 1.0) + 120 *
                  ((int32_T)(c4_b_c - 1.0) - 1)) - 1] + 1.0);
                if ((c4_i75 < 1) || (c4_i75 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i75, 1, 9601, &c4_wb_emlrtBCI,
                    &c4_st);
                }

                chartInstance->c4_P[c4_i75 - 1] = c4_c_L[((int32_T)c4_b_r + 120 *
                  ((int32_T)c4_b_c - 1)) - 1];
              }

              do {
                c4_exitg1 = 0;
                c4_i47 = (int32_T)(c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 *
                  ((int32_T)c4_b_c - 1)) - 1] + 1.0);
                if ((c4_i47 < 1) || (c4_i47 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i47, 1, 9601, &c4_kb_emlrtBCI,
                    &c4_st);
                }

                if (chartInstance->c4_P[c4_i47 - 1] < c4_c_L[((int32_T)(c4_b_r -
                      1.0) + 120 * ((int32_T)c4_b_c - 1)) - 1]) {
                  c4_i53 = (int32_T)(c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 *
                    ((int32_T)c4_b_c - 1)) - 1] + 1.0);
                  if ((c4_i53 < 1) || (c4_i53 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i53, 1, 9601,
                      &c4_ob_emlrtBCI, &c4_st);
                  }

                  c4_g_j = chartInstance->c4_P[c4_i53 - 1];
                  c4_i61 = (int32_T)(c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 *
                    ((int32_T)c4_b_c - 1)) - 1] + 1.0);
                  if ((c4_i61 < 1) || (c4_i61 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i61, 1, 9601,
                      &c4_qb_emlrtBCI, &c4_st);
                  }

                  chartInstance->c4_P[c4_i61 - 1] = c4_c_L[((int32_T)c4_b_r +
                    120 * ((int32_T)c4_b_c - 1)) - 1];
                  c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 * ((int32_T)c4_b_c - 1))
                    - 1] = c4_g_j;
                } else {
                  c4_exitg1 = 1;
                }
              } while (c4_exitg1 == 0);

              c4_i58 = (int32_T)(c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 *
                ((int32_T)c4_b_c - 1)) - 1] + 1.0);
              if ((c4_i58 < 1) || (c4_i58 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i58, 1, 9601, &c4_nb_emlrtBCI,
                  &c4_st);
              }

              chartInstance->c4_P[c4_i58 - 1] = c4_c_L[((int32_T)c4_b_r + 120 *
                ((int32_T)c4_b_c - 1)) - 1];
            } else {
              c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
                c4_c_L[((int32_T)(c4_b_r + 1.0) + 120 * ((int32_T)(c4_b_c - 1.0)
                         - 1)) - 1];
            }
          } else if ((c4_b_c > c4_startC) && (c4_b_r > 1.0) && c4_varargin_1
                     [((int32_T)(c4_b_r - 1.0) + 120 * ((int32_T)(c4_b_c - 1.0)
                       - 1)) - 1]) {
            c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
              c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 * ((int32_T)(c4_b_c - 1.0) -
                       1)) - 1];
          } else if ((c4_b_r > 1.0) && c4_varargin_1[((int32_T)(c4_b_r - 1.0) +
                      120 * ((int32_T)c4_b_c - 1)) - 1]) {
            c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
              c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 * ((int32_T)c4_b_c - 1)) - 1];
          } else {
            c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
              c4_label;
            c4_i20 = (int32_T)(c4_label + 1.0);
            if ((c4_i20 < 1) || (c4_i20 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c4_i20, 1, 9601, &c4_f_emlrtBCI,
                &c4_st);
            }

            chartInstance->c4_P[c4_i20 - 1] = c4_label;
            c4_label++;
          }
        } else {
          c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] = 0.0;
        }
      }
    }

    c4_d10 = muDoubleScalarRound(c4_label - c4_firstLabel);
    if (c4_d10 < 2.147483648E+9) {
      if (c4_d10 >= -2.147483648E+9) {
        c4_i13 = (int32_T)c4_d10;
      } else {
        c4_i13 = MIN_int32_T;
      }
    } else if (c4_d10 >= 2.147483648E+9) {
      c4_i13 = MAX_int32_T;
    } else {
      c4_i13 = 0;
    }

    c4_chunksSizeAndLabels[(int32_T)(c4_startC + 1.0) - 1] = c4_i13;
  }

  c4_c = c4_chunksSizeAndLabels[0];
  while (c4_c <= 160) {
    for (c4_r = 0; c4_r < 120; c4_r++) {
      c4_b_r = (real_T)c4_r + 1.0;
      if ((c4_c < 1) || (c4_c > 160)) {
        emlrtDynamicBoundsCheckR2012b(c4_c, 1, 160, &c4_j_emlrtBCI, &c4_st);
      }

      c4_d = c4_c_L[((int32_T)c4_b_r + 120 * (c4_c - 1)) - 1];
      if (c4_d != 0.0) {
        if (c4_b_r > 1.0) {
          c4_b_q0 = c4_c;
          c4_b_q1 = 1;
          if ((c4_b_q1 < 0) && (c4_b_q0 > c4_b_q1 + MAX_int32_T)) {
            c4_b_qY = MAX_int32_T;
          } else if ((c4_b_q1 > 0) && (c4_b_q0 < c4_b_q1 + MIN_int32_T)) {
            c4_b_qY = MIN_int32_T;
          } else {
            c4_b_qY = c4_b_q0 - c4_b_q1;
          }

          c4_i2 = c4_b_qY;
          if ((c4_i2 < 1) || (c4_i2 > 160)) {
            emlrtDynamicBoundsCheckR2012b(c4_i2, 1, 160, &c4_k_emlrtBCI, &c4_st);
          }

          c4_d3 = c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 * (c4_i2 - 1)) - 1];
          if (c4_d3 != 0.0) {
            c4_b_st.site = &c4_f_emlrtRSI;
            c4_e_q0 = c4_c;
            c4_e_q1 = 1;
            if ((c4_e_q1 < 0) && (c4_e_q0 > c4_e_q1 + MAX_int32_T)) {
              c4_e_qY = MAX_int32_T;
            } else if ((c4_e_q1 > 0) && (c4_e_q0 < c4_e_q1 + MIN_int32_T)) {
              c4_e_qY = MIN_int32_T;
            } else {
              c4_e_qY = c4_e_q0 - c4_e_q1;
            }

            c4_i6 = c4_e_qY;
            if ((c4_i6 < 1) || (c4_i6 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c4_i6, 1, 160, &c4_m_emlrtBCI,
                &c4_b_st);
            }

            c4_b_i = c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 * (c4_i6 - 1)) - 1];
            c4_j = c4_c_L[((int32_T)c4_b_r + 120 * (c4_c - 1)) - 1];
            c4_c_st.site = &c4_j_emlrtRSI;
            c4_e_i = c4_b_i;
            c4_d8 = c4_e_i;
            do {
              c4_exitg1 = 0;
              c4_i11 = (int32_T)(c4_d8 + 1.0);
              if ((c4_i11 < 1) || (c4_i11 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i11, 1, 9601, &c4_r_emlrtBCI,
                  &c4_c_st);
              }

              if (chartInstance->c4_P[c4_i11 - 1] < c4_d8) {
                c4_i16 = (int32_T)(c4_d8 + 1.0);
                if ((c4_i16 < 1) || (c4_i16 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i16, 1, 9601, &c4_s_emlrtBCI,
                    &c4_c_st);
                }

                c4_d8 = chartInstance->c4_P[c4_i16 - 1];
              } else {
                c4_exitg1 = 1;
              }
            } while (c4_exitg1 == 0);

            if (c4_b_i != c4_j) {
              c4_c_st.site = &c4_k_emlrtRSI;
              c4_h_i = c4_j;
              c4_rootj = c4_h_i;
              do {
                c4_exitg1 = 0;
                c4_i22 = (int32_T)(c4_rootj + 1.0);
                if ((c4_i22 < 1) || (c4_i22 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i22, 1, 9601, &c4_r_emlrtBCI,
                    &c4_c_st);
                }

                if (chartInstance->c4_P[c4_i22 - 1] < c4_rootj) {
                  c4_i30 = (int32_T)(c4_rootj + 1.0);
                  if ((c4_i30 < 1) || (c4_i30 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i30, 1, 9601,
                      &c4_s_emlrtBCI, &c4_c_st);
                  }

                  c4_rootj = chartInstance->c4_P[c4_i30 - 1];
                } else {
                  c4_exitg1 = 1;
                }
              } while (c4_exitg1 == 0);

              if (c4_d8 > c4_rootj) {
                c4_d8 = c4_rootj;
              }

              c4_c_st.site = &c4_l_emlrtRSI;
              c4_n_i = c4_j;
              c4_d_root = c4_d8;
              do {
                c4_exitg1 = 0;
                c4_i49 = (int32_T)(c4_n_i + 1.0);
                if ((c4_i49 < 1) || (c4_i49 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i49, 1, 9601, &c4_u_emlrtBCI,
                    &c4_c_st);
                }

                if (chartInstance->c4_P[c4_i49 - 1] < c4_n_i) {
                  c4_i56 = (int32_T)(c4_n_i + 1.0);
                  if ((c4_i56 < 1) || (c4_i56 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i56, 1, 9601,
                      &c4_v_emlrtBCI, &c4_c_st);
                  }

                  c4_h_j = chartInstance->c4_P[c4_i56 - 1];
                  c4_i64 = (int32_T)(c4_n_i + 1.0);
                  if ((c4_i64 < 1) || (c4_i64 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i64, 1, 9601,
                      &c4_g_emlrtBCI, &c4_c_st);
                  }

                  chartInstance->c4_P[c4_i64 - 1] = c4_d_root;
                  c4_n_i = c4_h_j;
                } else {
                  c4_exitg1 = 1;
                }
              } while (c4_exitg1 == 0);

              c4_i63 = (int32_T)(c4_n_i + 1.0);
              if ((c4_i63 < 1) || (c4_i63 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i63, 1, 9601, &c4_h_emlrtBCI,
                  &c4_c_st);
              }

              chartInstance->c4_P[c4_i63 - 1] = c4_d_root;
            }

            c4_c_st.site = &c4_m_emlrtRSI;
            c4_i_i = c4_b_i;
            c4_root = c4_d8;
            do {
              c4_exitg1 = 0;
              c4_i24 = (int32_T)(c4_i_i + 1.0);
              if ((c4_i24 < 1) || (c4_i24 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i24, 1, 9601, &c4_u_emlrtBCI,
                  &c4_c_st);
              }

              if (chartInstance->c4_P[c4_i24 - 1] < c4_i_i) {
                c4_i32 = (int32_T)(c4_i_i + 1.0);
                if ((c4_i32 < 1) || (c4_i32 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i32, 1, 9601, &c4_v_emlrtBCI,
                    &c4_c_st);
                }

                c4_d_j = chartInstance->c4_P[c4_i32 - 1];
                c4_i40 = (int32_T)(c4_i_i + 1.0);
                if ((c4_i40 < 1) || (c4_i40 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i40, 1, 9601, &c4_g_emlrtBCI,
                    &c4_c_st);
                }

                chartInstance->c4_P[c4_i40 - 1] = c4_root;
                c4_i_i = c4_d_j;
              } else {
                c4_exitg1 = 1;
              }
            } while (c4_exitg1 == 0);

            c4_i39 = (int32_T)(c4_i_i + 1.0);
            if ((c4_i39 < 1) || (c4_i39 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c4_i39, 1, 9601, &c4_h_emlrtBCI,
                &c4_c_st);
            }

            chartInstance->c4_P[c4_i39 - 1] = c4_root;
            c4_c_L[((int32_T)c4_b_r + 120 * (c4_c - 1)) - 1] = c4_d8;
          }
        }

        if (c4_b_r < 120.0) {
          c4_c_q0 = c4_c;
          c4_c_q1 = 1;
          if ((c4_c_q1 < 0) && (c4_c_q0 > c4_c_q1 + MAX_int32_T)) {
            c4_c_qY = MAX_int32_T;
          } else if ((c4_c_q1 > 0) && (c4_c_q0 < c4_c_q1 + MIN_int32_T)) {
            c4_c_qY = MIN_int32_T;
          } else {
            c4_c_qY = c4_c_q0 - c4_c_q1;
          }

          c4_i3 = c4_c_qY;
          if ((c4_i3 < 1) || (c4_i3 > 160)) {
            emlrtDynamicBoundsCheckR2012b(c4_i3, 1, 160, &c4_l_emlrtBCI, &c4_st);
          }

          c4_d4 = c4_c_L[((int32_T)(c4_b_r + 1.0) + 120 * (c4_i3 - 1)) - 1];
          if (c4_d4 != 0.0) {
            c4_b_st.site = &c4_g_emlrtRSI;
            c4_f_q0 = c4_c;
            c4_f_q1 = 1;
            if ((c4_f_q1 < 0) && (c4_f_q0 > c4_f_q1 + MAX_int32_T)) {
              c4_f_qY = MAX_int32_T;
            } else if ((c4_f_q1 > 0) && (c4_f_q0 < c4_f_q1 + MIN_int32_T)) {
              c4_f_qY = MIN_int32_T;
            } else {
              c4_f_qY = c4_f_q0 - c4_f_q1;
            }

            c4_i8 = c4_f_qY;
            if ((c4_i8 < 1) || (c4_i8 > 160)) {
              emlrtDynamicBoundsCheckR2012b(c4_i8, 1, 160, &c4_p_emlrtBCI,
                &c4_b_st);
            }

            c4_c_i = c4_c_L[((int32_T)(c4_b_r + 1.0) + 120 * (c4_i8 - 1)) - 1];
            c4_b_j = c4_c_L[((int32_T)c4_b_r + 120 * (c4_c - 1)) - 1];
            c4_c_st.site = &c4_j_emlrtRSI;
            c4_f_i = c4_c_i;
            c4_d9 = c4_f_i;
            do {
              c4_exitg1 = 0;
              c4_i12 = (int32_T)(c4_d9 + 1.0);
              if ((c4_i12 < 1) || (c4_i12 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i12, 1, 9601, &c4_r_emlrtBCI,
                  &c4_c_st);
              }

              if (chartInstance->c4_P[c4_i12 - 1] < c4_d9) {
                c4_i17 = (int32_T)(c4_d9 + 1.0);
                if ((c4_i17 < 1) || (c4_i17 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i17, 1, 9601, &c4_s_emlrtBCI,
                    &c4_c_st);
                }

                c4_d9 = chartInstance->c4_P[c4_i17 - 1];
              } else {
                c4_exitg1 = 1;
              }
            } while (c4_exitg1 == 0);

            if (c4_c_i != c4_b_j) {
              c4_c_st.site = &c4_k_emlrtRSI;
              c4_j_i = c4_b_j;
              c4_b_rootj = c4_j_i;
              do {
                c4_exitg1 = 0;
                c4_i26 = (int32_T)(c4_b_rootj + 1.0);
                if ((c4_i26 < 1) || (c4_i26 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i26, 1, 9601, &c4_r_emlrtBCI,
                    &c4_c_st);
                }

                if (chartInstance->c4_P[c4_i26 - 1] < c4_b_rootj) {
                  c4_i34 = (int32_T)(c4_b_rootj + 1.0);
                  if ((c4_i34 < 1) || (c4_i34 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i34, 1, 9601,
                      &c4_s_emlrtBCI, &c4_c_st);
                  }

                  c4_b_rootj = chartInstance->c4_P[c4_i34 - 1];
                } else {
                  c4_exitg1 = 1;
                }
              } while (c4_exitg1 == 0);

              if (c4_d9 > c4_b_rootj) {
                c4_d9 = c4_b_rootj;
              }

              c4_c_st.site = &c4_l_emlrtRSI;
              c4_o_i = c4_b_j;
              c4_e_root = c4_d9;
              do {
                c4_exitg1 = 0;
                c4_i52 = (int32_T)(c4_o_i + 1.0);
                if ((c4_i52 < 1) || (c4_i52 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i52, 1, 9601, &c4_u_emlrtBCI,
                    &c4_c_st);
                }

                if (chartInstance->c4_P[c4_i52 - 1] < c4_o_i) {
                  c4_i60 = (int32_T)(c4_o_i + 1.0);
                  if ((c4_i60 < 1) || (c4_i60 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i60, 1, 9601,
                      &c4_v_emlrtBCI, &c4_c_st);
                  }

                  c4_i_j = chartInstance->c4_P[c4_i60 - 1];
                  c4_i69 = (int32_T)(c4_o_i + 1.0);
                  if ((c4_i69 < 1) || (c4_i69 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i69, 1, 9601,
                      &c4_g_emlrtBCI, &c4_c_st);
                  }

                  chartInstance->c4_P[c4_i69 - 1] = c4_e_root;
                  c4_o_i = c4_i_j;
                } else {
                  c4_exitg1 = 1;
                }
              } while (c4_exitg1 == 0);

              c4_i66 = (int32_T)(c4_o_i + 1.0);
              if ((c4_i66 < 1) || (c4_i66 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i66, 1, 9601, &c4_h_emlrtBCI,
                  &c4_c_st);
              }

              chartInstance->c4_P[c4_i66 - 1] = c4_e_root;
            }

            c4_c_st.site = &c4_m_emlrtRSI;
            c4_l_i = c4_c_i;
            c4_b_root = c4_d9;
            do {
              c4_exitg1 = 0;
              c4_i28 = (int32_T)(c4_l_i + 1.0);
              if ((c4_i28 < 1) || (c4_i28 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i28, 1, 9601, &c4_u_emlrtBCI,
                  &c4_c_st);
              }

              if (chartInstance->c4_P[c4_i28 - 1] < c4_l_i) {
                c4_i36 = (int32_T)(c4_l_i + 1.0);
                if ((c4_i36 < 1) || (c4_i36 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i36, 1, 9601, &c4_v_emlrtBCI,
                    &c4_c_st);
                }

                c4_e_j = chartInstance->c4_P[c4_i36 - 1];
                c4_i43 = (int32_T)(c4_l_i + 1.0);
                if ((c4_i43 < 1) || (c4_i43 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i43, 1, 9601, &c4_g_emlrtBCI,
                    &c4_c_st);
                }

                chartInstance->c4_P[c4_i43 - 1] = c4_b_root;
                c4_l_i = c4_e_j;
              } else {
                c4_exitg1 = 1;
              }
            } while (c4_exitg1 == 0);

            c4_i41 = (int32_T)(c4_l_i + 1.0);
            if ((c4_i41 < 1) || (c4_i41 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c4_i41, 1, 9601, &c4_h_emlrtBCI,
                &c4_c_st);
            }

            chartInstance->c4_P[c4_i41 - 1] = c4_b_root;
            c4_c_L[((int32_T)c4_b_r + 120 * (c4_c - 1)) - 1] = c4_d9;
          }
        }

        c4_d_q0 = c4_c;
        c4_d_q1 = 1;
        if ((c4_d_q1 < 0) && (c4_d_q0 > c4_d_q1 + MAX_int32_T)) {
          c4_d_qY = MAX_int32_T;
        } else if ((c4_d_q1 > 0) && (c4_d_q0 < c4_d_q1 + MIN_int32_T)) {
          c4_d_qY = MIN_int32_T;
        } else {
          c4_d_qY = c4_d_q0 - c4_d_q1;
        }

        c4_i4 = c4_d_qY;
        if ((c4_i4 < 1) || (c4_i4 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c4_i4, 1, 160, &c4_o_emlrtBCI, &c4_st);
        }

        c4_d5 = c4_c_L[((int32_T)c4_b_r + 120 * (c4_i4 - 1)) - 1];
        if (c4_d5 != 0.0) {
          c4_b_st.site = &c4_h_emlrtRSI;
          c4_g_q0 = c4_c;
          c4_g_q1 = 1;
          if ((c4_g_q1 < 0) && (c4_g_q0 > c4_g_q1 + MAX_int32_T)) {
            c4_g_qY = MAX_int32_T;
          } else if ((c4_g_q1 > 0) && (c4_g_q0 < c4_g_q1 + MIN_int32_T)) {
            c4_g_qY = MIN_int32_T;
          } else {
            c4_g_qY = c4_g_q0 - c4_g_q1;
          }

          c4_i9 = c4_g_qY;
          if ((c4_i9 < 1) || (c4_i9 > 160)) {
            emlrtDynamicBoundsCheckR2012b(c4_i9, 1, 160, &c4_q_emlrtBCI,
              &c4_b_st);
          }

          c4_d_i = c4_c_L[((int32_T)c4_b_r + 120 * (c4_i9 - 1)) - 1];
          c4_c_j = c4_c_L[((int32_T)c4_b_r + 120 * (c4_c - 1)) - 1];
          c4_c_st.site = &c4_j_emlrtRSI;
          c4_g_i = c4_d_i;
          c4_d11 = c4_g_i;
          do {
            c4_exitg1 = 0;
            c4_i14 = (int32_T)(c4_d11 + 1.0);
            if ((c4_i14 < 1) || (c4_i14 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c4_i14, 1, 9601, &c4_r_emlrtBCI,
                &c4_c_st);
            }

            if (chartInstance->c4_P[c4_i14 - 1] < c4_d11) {
              c4_i19 = (int32_T)(c4_d11 + 1.0);
              if ((c4_i19 < 1) || (c4_i19 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i19, 1, 9601, &c4_s_emlrtBCI,
                  &c4_c_st);
              }

              c4_d11 = chartInstance->c4_P[c4_i19 - 1];
            } else {
              c4_exitg1 = 1;
            }
          } while (c4_exitg1 == 0);

          if (c4_d_i != c4_c_j) {
            c4_c_st.site = &c4_k_emlrtRSI;
            c4_k_i = c4_c_j;
            c4_c_rootj = c4_k_i;
            do {
              c4_exitg1 = 0;
              c4_i27 = (int32_T)(c4_c_rootj + 1.0);
              if ((c4_i27 < 1) || (c4_i27 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i27, 1, 9601, &c4_r_emlrtBCI,
                  &c4_c_st);
              }

              if (chartInstance->c4_P[c4_i27 - 1] < c4_c_rootj) {
                c4_i35 = (int32_T)(c4_c_rootj + 1.0);
                if ((c4_i35 < 1) || (c4_i35 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i35, 1, 9601, &c4_s_emlrtBCI,
                    &c4_c_st);
                }

                c4_c_rootj = chartInstance->c4_P[c4_i35 - 1];
              } else {
                c4_exitg1 = 1;
              }
            } while (c4_exitg1 == 0);

            if (c4_d11 > c4_c_rootj) {
              c4_d11 = c4_c_rootj;
            }

            c4_c_st.site = &c4_l_emlrtRSI;
            c4_p_i = c4_c_j;
            c4_f_root = c4_d11;
            do {
              c4_exitg1 = 0;
              c4_i55 = (int32_T)(c4_p_i + 1.0);
              if ((c4_i55 < 1) || (c4_i55 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i55, 1, 9601, &c4_u_emlrtBCI,
                  &c4_c_st);
              }

              if (chartInstance->c4_P[c4_i55 - 1] < c4_p_i) {
                c4_i62 = (int32_T)(c4_p_i + 1.0);
                if ((c4_i62 < 1) || (c4_i62 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i62, 1, 9601, &c4_v_emlrtBCI,
                    &c4_c_st);
                }

                c4_j_j = chartInstance->c4_P[c4_i62 - 1];
                c4_i70 = (int32_T)(c4_p_i + 1.0);
                if ((c4_i70 < 1) || (c4_i70 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i70, 1, 9601, &c4_g_emlrtBCI,
                    &c4_c_st);
                }

                chartInstance->c4_P[c4_i70 - 1] = c4_f_root;
                c4_p_i = c4_j_j;
              } else {
                c4_exitg1 = 1;
              }
            } while (c4_exitg1 == 0);

            c4_i68 = (int32_T)(c4_p_i + 1.0);
            if ((c4_i68 < 1) || (c4_i68 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c4_i68, 1, 9601, &c4_h_emlrtBCI,
                &c4_c_st);
            }

            chartInstance->c4_P[c4_i68 - 1] = c4_f_root;
          }

          c4_c_st.site = &c4_m_emlrtRSI;
          c4_m_i = c4_d_i;
          c4_c_root = c4_d11;
          do {
            c4_exitg1 = 0;
            c4_i29 = (int32_T)(c4_m_i + 1.0);
            if ((c4_i29 < 1) || (c4_i29 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c4_i29, 1, 9601, &c4_u_emlrtBCI,
                &c4_c_st);
            }

            if (chartInstance->c4_P[c4_i29 - 1] < c4_m_i) {
              c4_i38 = (int32_T)(c4_m_i + 1.0);
              if ((c4_i38 < 1) || (c4_i38 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i38, 1, 9601, &c4_v_emlrtBCI,
                  &c4_c_st);
              }

              c4_f_j = chartInstance->c4_P[c4_i38 - 1];
              c4_i46 = (int32_T)(c4_m_i + 1.0);
              if ((c4_i46 < 1) || (c4_i46 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i46, 1, 9601, &c4_g_emlrtBCI,
                  &c4_c_st);
              }

              chartInstance->c4_P[c4_i46 - 1] = c4_c_root;
              c4_m_i = c4_f_j;
            } else {
              c4_exitg1 = 1;
            }
          } while (c4_exitg1 == 0);

          c4_i42 = (int32_T)(c4_m_i + 1.0);
          if ((c4_i42 < 1) || (c4_i42 > 9601)) {
            emlrtDynamicBoundsCheckR2012b(c4_i42, 1, 9601, &c4_h_emlrtBCI,
              &c4_c_st);
          }

          chartInstance->c4_P[c4_i42 - 1] = c4_c_root;
          c4_c_L[((int32_T)c4_b_r + 120 * (c4_c - 1)) - 1] = c4_d11;
        }
      }
    }

    if ((c4_c < 1) || (c4_c > 168)) {
      emlrtDynamicBoundsCheckR2012b(c4_c, 1, 168, &c4_i_emlrtBCI, &c4_st);
    }

    c4_c = c4_chunksSizeAndLabels[c4_c - 1];
  }

  c4_b_numComponents = 1.0;
  c4_c = 1;
  while (c4_c <= 160) {
    c4_q0 = c4_c;
    c4_q1 = 1;
    if ((c4_q1 < 0) && (c4_q0 > c4_q1 + MAX_int32_T)) {
      c4_qY = MAX_int32_T;
    } else if ((c4_q1 > 0) && (c4_q0 < c4_q1 + MIN_int32_T)) {
      c4_qY = MIN_int32_T;
    } else {
      c4_qY = c4_q0 - c4_q1;
    }

    c4_f_x = c4_qY;
    c4_g_x = c4_f_x;
    c4_h_x = c4_g_x;
    c4_i_x = c4_h_x;
    c4_b_a = c4_i_x;
    c4_j_x = c4_b_a;
    c4_z = (real_T)c4_j_x / 2.0;
    c4_d2 = muDoubleScalarRound(c4_z);
    if (c4_d2 < 2.147483648E+9) {
      if (c4_d2 >= -2.147483648E+9) {
        c4_i5 = (int32_T)c4_d2;
      } else {
        c4_i5 = MIN_int32_T;
      }
    } else if (c4_d2 >= 2.147483648E+9) {
      c4_i5 = MAX_int32_T;
    } else {
      c4_i5 = 0;
    }

    c4_b_z = c4_i5;
    c4_m_x = c4_b_z;
    c4_c_a = c4_m_x;
    c4_i7 = (int64_T)c4_c_a * 60LL;
    if (c4_i7 > 2147483647LL) {
      c4_i7 = 2147483647LL;
    } else if (c4_i7 < -2147483648LL) {
      c4_i7 = -2147483648LL;
    }

    c4_b_y = (int32_T)c4_i7;
    c4_h_q0 = c4_b_y;
    c4_h_q1 = 1;
    if ((c4_h_q1 < 0) && (c4_h_q0 < MIN_int32_T - c4_h_q1)) {
      c4_h_qY = MIN_int32_T;
    } else if ((c4_h_q1 > 0) && (c4_h_q0 > MAX_int32_T - c4_h_q1)) {
      c4_h_qY = MAX_int32_T;
    } else {
      c4_h_qY = c4_h_q0 + c4_h_q1;
    }

    c4_stripeFirstLabel = c4_h_qY;
    c4_i_q0 = c4_stripeFirstLabel;
    c4_i_q1 = 1;
    if ((c4_i_q1 < 0) && (c4_i_q0 < MIN_int32_T - c4_i_q1)) {
      c4_i_qY = MIN_int32_T;
    } else if ((c4_i_q1 > 0) && (c4_i_q0 > MAX_int32_T - c4_i_q1)) {
      c4_i_qY = MAX_int32_T;
    } else {
      c4_i_qY = c4_i_q0 + c4_i_q1;
    }

    c4_i18 = c4_i_qY;
    c4_j_q0 = c4_c;
    c4_j_q1 = 1;
    if ((c4_j_q1 < 0) && (c4_j_q0 < MIN_int32_T - c4_j_q1)) {
      c4_j_qY = MIN_int32_T;
    } else if ((c4_j_q1 > 0) && (c4_j_q0 > MAX_int32_T - c4_j_q1)) {
      c4_j_qY = MAX_int32_T;
    } else {
      c4_j_qY = c4_j_q0 + c4_j_q1;
    }

    c4_i21 = c4_j_qY;
    if ((c4_i21 < 1) || (c4_i21 > 168)) {
      emlrtDynamicBoundsCheckR2012b(c4_i21, 1, 168, &c4_t_emlrtBCI, &c4_st);
    }

    c4_k_q0 = c4_stripeFirstLabel;
    c4_k_q1 = c4_chunksSizeAndLabels[c4_i21 - 1];
    if ((c4_k_q0 < 0) && (c4_k_q1 < MIN_int32_T - c4_k_q0)) {
      c4_k_qY = MIN_int32_T;
    } else if ((c4_k_q0 > 0) && (c4_k_q1 > MAX_int32_T - c4_k_q0)) {
      c4_k_qY = MAX_int32_T;
    } else {
      c4_k_qY = c4_k_q0 + c4_k_q1;
    }

    c4_i37 = c4_k_qY;
    c4_b_st.site = &c4_i_emlrtRSI;
    c4_e_a = c4_i18;
    c4_b_b = c4_i37;
    c4_f_a = c4_e_a;
    c4_c_b = c4_b_b;
    if (c4_f_a > c4_c_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_c_b > 2147483646);
    }

    if (c4_overflow) {
      c4_c_st.site = &c4_n_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
    }

    for (c4_q_i = c4_i18; c4_q_i <= c4_i37; c4_q_i++) {
      if ((c4_q_i < 1) || (c4_q_i > 9601)) {
        emlrtDynamicBoundsCheckR2012b(c4_q_i, 1, 9601, &c4_x_emlrtBCI, &c4_st);
      }

      c4_l_q0 = c4_q_i;
      c4_l_q1 = 1;
      if ((c4_l_q1 < 0) && (c4_l_q0 > c4_l_q1 + MAX_int32_T)) {
        c4_l_qY = MAX_int32_T;
      } else if ((c4_l_q1 > 0) && (c4_l_q0 < c4_l_q1 + MIN_int32_T)) {
        c4_l_qY = MIN_int32_T;
      } else {
        c4_l_qY = c4_l_q0 - c4_l_q1;
      }

      if (chartInstance->c4_P[c4_q_i - 1] < (real_T)c4_l_qY) {
        c4_i73 = (int32_T)(chartInstance->c4_P[c4_q_i - 1] + 1.0);
        if ((c4_i73 < 1) || (c4_i73 > 9601)) {
          emlrtDynamicBoundsCheckR2012b(c4_i73, 1, 9601, &c4_ab_emlrtBCI, &c4_st);
        }

        chartInstance->c4_P[c4_q_i - 1] = chartInstance->c4_P[c4_i73 - 1];
      } else {
        chartInstance->c4_P[c4_q_i - 1] = c4_b_numComponents;
        c4_b_numComponents++;
      }
    }

    if ((c4_c < 1) || (c4_c > 168)) {
      emlrtDynamicBoundsCheckR2012b(c4_c, 1, 168, &c4_w_emlrtBCI, &c4_st);
    }

    c4_c = c4_chunksSizeAndLabels[c4_c - 1];
  }

  c4_b_numComponents--;
  for (c4_c_c = 0; c4_c_c < 160; c4_c_c++) {
    c4_b_c = (real_T)c4_c_c + 1.0;
    for (c4_c_r = 0; c4_c_r < 120; c4_c_r++) {
      c4_b_r = (real_T)c4_c_r + 1.0;
      c4_i1 = (int32_T)(c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) -
                        1] + 1.0);
      if ((c4_i1 < 1) || (c4_i1 > 9601)) {
        emlrtDynamicBoundsCheckR2012b(c4_i1, 1, 9601, &c4_n_emlrtBCI, &c4_st);
      }

      c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
        chartInstance->c4_P[c4_i1 - 1];
    }
  }

  *c4_numComponents = c4_b_numComponents;
}

static void c4_check_forloop_overflow_error
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp)
{
  static char_T c4_cv[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  static char_T c4_cv1[5] = { 'i', 'n', 't', '3', '2' };

  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  (void)chartInstance;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 34), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 34),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv1, 10, 0U, 1, 0U, 2, 1, 5),
                false);
  sf_mex_call(c4_sp, &c4_emlrtMCI, "error", 0U, 2U, 14, c4_y, 14, sf_mex_call
              (c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call(c4_sp, NULL,
    "message", 1U, 2U, 14, c4_b_y, 14, c4_c_y)));
}

static void c4_validateConnectivity(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp)
{
  static real_T c4_B[6] = { 1.0, 4.0, 6.0, 8.0, 18.0, 26.0 };

  static real_T c4_dv[6] = { 1.0, 4.0, 6.0, 8.0, 18.0, 26.0 };

  static char_T c4_cv[12] = { 'm', 'u', 's', 't', 'B', 'e', 'M', 'e', 'm', 'b',
    'e', 'r' };

  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  real_T c4_b_b;
  real_T c4_b_varargin_2;
  real_T c4_b_x2;
  real_T c4_u;
  real_T c4_varargin_2;
  real_T c4_x;
  real_T c4_x2;
  int32_T c4_b_k;
  int32_T c4_idx;
  int32_T c4_k;
  int32_T c4_varargin_1;
  boolean_T c4_b_p;
  boolean_T c4_c_p;
  boolean_T c4_d_p;
  boolean_T c4_exitg1;
  boolean_T c4_p;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_st.site = &c4_o_emlrtRSI;
  c4_b_st.site = &c4_p_emlrtRSI;
  c4_p = true;
  c4_idx = 0;
  c4_k = 1;
  c4_exitg1 = false;
  while ((!c4_exitg1) && (c4_k - 1 < 6)) {
    c4_b_k = c4_k;
    c4_varargin_1 = c4_b_k - 1;
    c4_x = c4_dv[c4_varargin_1];
    c4_b_b = c4_x;
    c4_varargin_2 = c4_b_b;
    c4_b_varargin_2 = c4_varargin_2;
    c4_b_p = false;
    c4_x2 = c4_b_varargin_2;
    c4_c_p = true;
    c4_b_x2 = c4_x2;
    c4_d_p = (c4_b_x2 == 4.0);
    if (!c4_d_p) {
      c4_c_p = false;
    }

    if (c4_c_p) {
      c4_b_p = true;
    }

    if (c4_b_p) {
      c4_idx = c4_b_k;
      c4_exitg1 = true;
    } else {
      c4_k++;
    }
  }

  if (c4_idx == 0) {
    c4_p = false;
  }

  if (!c4_p) {
    c4_y = NULL;
    sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 12),
                  false);
    c4_u = 4.0;
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_u, 0, 0U, 0, 0U, 0), false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_B, 0, 0U, 1, 0U, 2, 1, 6),
                  false);
    c4_c_st.site = &c4_q_emlrtRSI;
    c4_feval(chartInstance, &c4_c_st, c4_y, c4_b_y, c4_c_y);
  }
}

static void c4_eml_float_colon(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, real_T c4_a, real_T c4_b_b, real_T
  c4_y_data[], int32_T c4_y_size[2])
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  real_T c4_a1;
  real_T c4_apnd;
  real_T c4_b1;
  real_T c4_b_a;
  real_T c4_b_x;
  real_T c4_b_y;
  real_T c4_c;
  real_T c4_c_a;
  real_T c4_c_b;
  real_T c4_c_x;
  real_T c4_c_y;
  real_T c4_cdiff;
  real_T c4_d_b;
  real_T c4_d_x;
  real_T c4_e_x;
  real_T c4_f_x;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_i_x;
  real_T c4_j_x;
  real_T c4_k_x;
  real_T c4_kd;
  real_T c4_ndbl;
  real_T c4_thresh;
  real_T c4_x;
  real_T c4_y;
  int32_T c4_b_k;
  int32_T c4_d_a;
  int32_T c4_d_y;
  int32_T c4_e_b;
  int32_T c4_f_b;
  int32_T c4_g_b;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_k;
  int32_T c4_n;
  int32_T c4_nm1;
  int32_T c4_nm1d2;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_b_a = c4_a;
  c4_c_b = c4_b_b;
  c4_a1 = c4_b_a;
  c4_x = (c4_c_b - c4_b_a) + 0.5;
  c4_b_x = c4_x;
  c4_ndbl = c4_b_x;
  c4_ndbl = muDoubleScalarFloor(c4_ndbl);
  c4_apnd = c4_b_a + c4_ndbl;
  c4_cdiff = c4_apnd - c4_c_b;
  c4_c_a = c4_b_a;
  c4_d_b = c4_c_b;
  c4_c_x = c4_c_a;
  c4_d_x = c4_c_x;
  c4_e_x = c4_d_x;
  c4_y = muDoubleScalarAbs(c4_e_x);
  c4_f_x = c4_d_b;
  c4_g_x = c4_f_x;
  c4_h_x = c4_g_x;
  c4_b_y = muDoubleScalarAbs(c4_h_x);
  c4_c = muDoubleScalarMax(c4_y, c4_b_y);
  c4_thresh = 4.4408920985006262E-16 * c4_c;
  c4_i_x = c4_cdiff;
  c4_j_x = c4_i_x;
  c4_k_x = c4_j_x;
  c4_c_y = muDoubleScalarAbs(c4_k_x);
  if (c4_c_y < c4_thresh) {
    c4_ndbl++;
    c4_b1 = c4_c_b;
  } else if (c4_cdiff > 0.0) {
    c4_b1 = c4_b_a + (c4_ndbl - 1.0);
  } else {
    c4_ndbl++;
    c4_b1 = c4_apnd;
  }

  c4_n = (int32_T)muDoubleScalarFloor(c4_ndbl) - 1;
  c4_y_size[0] = 1;
  c4_y_size[1] = c4_n + 1;
  c4_y_data[0] = c4_a1;
  c4_y_data[c4_n] = c4_b1;
  c4_nm1 = c4_n;
  c4_d_a = c4_nm1;
  c4_nm1d2 = (uint8_T)((uint32_T)(uint8_T)c4_d_a >> 1);
  c4_i = c4_nm1d2 - 1;
  c4_st.site = &c4_ib_emlrtRSI;
  c4_e_b = c4_i;
  c4_f_b = c4_e_b;
  if (c4_f_b < 1) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_f_b > 2147483646);
  }

  if (c4_overflow) {
    c4_b_st.site = &c4_n_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
  }

  c4_i1 = (uint8_T)c4_i;
  for (c4_k = 0; c4_k < c4_i1; c4_k++) {
    c4_b_k = c4_k + 1;
    c4_kd = (real_T)c4_b_k;
    c4_y_data[c4_b_k] = c4_a1 + c4_kd;
    c4_y_data[c4_n - c4_b_k] = c4_b1 - c4_kd;
  }

  c4_g_b = c4_nm1d2;
  c4_d_y = c4_g_b << 1;
  if (c4_d_y == c4_nm1) {
    c4_y_data[c4_nm1d2] = (c4_a1 + c4_b1) / 2.0;
  } else {
    c4_kd = (real_T)c4_nm1d2;
    c4_y_data[c4_nm1d2] = c4_a1 + c4_kd;
    c4_y_data[c4_nm1d2 + 1] = c4_b1 - c4_kd;
  }
}

static void c4_b_bwlabel(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, boolean_T c4_varargin_1[19200], real_T c4_c_L[19200],
  real_T *c4_numComponents)
{
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_st;
  int64_T c4_i;
  real_T c4_a;
  real_T c4_b_c;
  real_T c4_b_i;
  real_T c4_b_j;
  real_T c4_b_numComponents;
  real_T c4_b_r;
  real_T c4_b_root;
  real_T c4_b_rootj;
  real_T c4_b_thread;
  real_T c4_b_varargin_1;
  real_T c4_b_x;
  real_T c4_b_y;
  real_T c4_c_i;
  real_T c4_c_j;
  real_T c4_c_varargin_1;
  real_T c4_c_x;
  real_T c4_d;
  real_T c4_d1;
  real_T c4_d2;
  real_T c4_d3;
  real_T c4_d4;
  real_T c4_d5;
  real_T c4_d6;
  real_T c4_d7;
  real_T c4_d_a;
  real_T c4_d_i;
  real_T c4_d_j;
  real_T c4_d_x;
  real_T c4_e_i;
  real_T c4_e_x;
  real_T c4_f_i;
  real_T c4_f_x;
  real_T c4_firstLabel;
  real_T c4_h_x;
  real_T c4_j;
  real_T c4_label;
  real_T c4_m_x;
  real_T c4_minval;
  real_T c4_n_x;
  real_T c4_o_x;
  real_T c4_p_x;
  real_T c4_q_x;
  real_T c4_root;
  real_T c4_rootj;
  real_T c4_startC;
  real_T c4_x;
  real_T c4_z;
  int32_T c4_chunksSizeAndLabels[168];
  int32_T c4_b_a;
  int32_T c4_b_b;
  int32_T c4_b_q0;
  int32_T c4_b_q1;
  int32_T c4_b_qY;
  int32_T c4_b_z;
  int32_T c4_c;
  int32_T c4_c_a;
  int32_T c4_c_b;
  int32_T c4_c_c;
  int32_T c4_c_q0;
  int32_T c4_c_q1;
  int32_T c4_c_qY;
  int32_T c4_c_r;
  int32_T c4_c_y;
  int32_T c4_d_c;
  int32_T c4_d_q0;
  int32_T c4_d_q1;
  int32_T c4_d_qY;
  int32_T c4_d_r;
  int32_T c4_e_a;
  int32_T c4_e_q0;
  int32_T c4_e_q1;
  int32_T c4_e_qY;
  int32_T c4_exitg1;
  int32_T c4_f_a;
  int32_T c4_f_q0;
  int32_T c4_f_q1;
  int32_T c4_f_qY;
  int32_T c4_g_i;
  int32_T c4_g_q0;
  int32_T c4_g_q1;
  int32_T c4_g_qY;
  int32_T c4_g_x;
  int32_T c4_h_q0;
  int32_T c4_h_q1;
  int32_T c4_h_qY;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i36;
  int32_T c4_i37;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_x;
  int32_T c4_j_x;
  int32_T c4_k_x;
  int32_T c4_l_x;
  int32_T c4_q0;
  int32_T c4_q1;
  int32_T c4_qY;
  int32_T c4_r;
  int32_T c4_r_x;
  int32_T c4_stripeFirstLabel;
  int32_T c4_thread;
  int32_T c4_y;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_st.site = &c4_e_emlrtRSI;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  chartInstance->c4_b_P[0] = 0.0;
  for (c4_thread = 0; c4_thread < 8; c4_thread++) {
    c4_b_thread = (real_T)c4_thread;
    c4_b_c = c4_b_thread * 20.0 + 1.0;
    c4_b_varargin_1 = (c4_b_thread + 1.0) * 20.0 + 1.0;
    c4_x = c4_b_varargin_1;
    c4_b_x = c4_x;
    c4_c_x = c4_b_x;
    c4_a = c4_c_x;
    c4_d_x = c4_a;
    c4_e_x = c4_d_x;
    c4_minval = muDoubleScalarMin(c4_e_x, 161.0);
    c4_d1 = muDoubleScalarRound(c4_minval);
    if (c4_d1 < 2.147483648E+9) {
      if (c4_d1 >= -2.147483648E+9) {
        c4_i1 = (int32_T)c4_d1;
      } else {
        c4_i1 = MIN_int32_T;
      }
    } else if (c4_d1 >= 2.147483648E+9) {
      c4_i1 = MAX_int32_T;
    } else {
      c4_i1 = 0;
    }

    c4_chunksSizeAndLabels[(int32_T)c4_b_c - 1] = c4_i1;
    c4_f_x = (c4_b_c - 1.0) * 120.0 / 2.0;
    c4_h_x = c4_f_x;
    c4_b_y = c4_h_x;
    c4_b_y = muDoubleScalarCeil(c4_b_y);
    c4_label = c4_b_y + 1.0;
    c4_firstLabel = c4_label;
    c4_startC = c4_b_c;
    c4_d3 = c4_b_thread * 20.0 + 1.0;
    c4_c_varargin_1 = (c4_b_thread + 1.0) * 20.0;
    c4_m_x = c4_c_varargin_1;
    c4_n_x = c4_m_x;
    c4_o_x = c4_n_x;
    c4_d_a = c4_o_x;
    c4_p_x = c4_d_a;
    c4_q_x = c4_p_x;
    c4_d5 = muDoubleScalarMin(c4_q_x, 160.0);
    c4_i6 = (int32_T)(c4_d5 + (1.0 - c4_d3));
    for (c4_d_c = 0; c4_d_c < c4_i6; c4_d_c++) {
      c4_b_c = c4_d3 + (real_T)c4_d_c;
      for (c4_d_r = 0; c4_d_r < 120; c4_d_r++) {
        c4_b_r = (real_T)c4_d_r + 1.0;
        c4_i10 = (int32_T)c4_b_c;
        if ((c4_i10 < 1) || (c4_i10 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c4_i10, 1, 160, &c4_gc_emlrtBCI, &c4_st);
        }

        if (c4_varargin_1[((int32_T)c4_b_r + 120 * (c4_i10 - 1)) - 1]) {
          if ((c4_b_r > 1.0) && c4_varargin_1[((int32_T)(c4_b_r - 1.0) + 120 *
               ((int32_T)c4_b_c - 1)) - 1]) {
            if ((c4_b_c > c4_startC) && c4_varargin_1[((int32_T)c4_b_r + 120 *
                 ((int32_T)(c4_b_c - 1.0) - 1)) - 1]) {
              c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
                c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)(c4_b_c - 1.0) - 1)) -
                1];
              do {
                c4_exitg1 = 0;
                c4_i14 = (int32_T)(c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)
                  c4_b_c - 1)) - 1] + 1.0);
                if ((c4_i14 < 1) || (c4_i14 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i14, 1, 9601, &c4_kc_emlrtBCI,
                    &c4_st);
                }

                if (chartInstance->c4_b_P[c4_i14 - 1] < c4_c_L[((int32_T)c4_b_r
                     + 120 * ((int32_T)c4_b_c - 1)) - 1]) {
                  c4_i18 = (int32_T)(c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)
                    c4_b_c - 1)) - 1] + 1.0);
                  if ((c4_i18 < 1) || (c4_i18 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i18, 1, 9601,
                      &c4_lc_emlrtBCI, &c4_st);
                  }

                  c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
                    chartInstance->c4_b_P[c4_i18 - 1];
                } else {
                  c4_exitg1 = 1;
                }
              } while (c4_exitg1 == 0);

              if (c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)(c4_b_c - 1.0) - 1))
                  - 1] != c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 * ((int32_T)
                    c4_b_c - 1)) - 1]) {
                c4_b_rootj = c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 * ((int32_T)
                  c4_b_c - 1)) - 1];
                do {
                  c4_exitg1 = 0;
                  c4_i24 = (int32_T)(c4_b_rootj + 1.0);
                  if ((c4_i24 < 1) || (c4_i24 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i24, 1, 9601,
                      &c4_nc_emlrtBCI, &c4_st);
                  }

                  if (chartInstance->c4_b_P[c4_i24 - 1] < c4_b_rootj) {
                    c4_i27 = (int32_T)(c4_b_rootj + 1.0);
                    if ((c4_i27 < 1) || (c4_i27 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c4_i27, 1, 9601,
                        &c4_qc_emlrtBCI, &c4_st);
                    }

                    c4_b_rootj = chartInstance->c4_b_P[c4_i27 - 1];
                  } else {
                    c4_exitg1 = 1;
                  }
                } while (c4_exitg1 == 0);

                if (c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] >
                    c4_b_rootj) {
                  c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
                    c4_b_rootj;
                }

                do {
                  c4_exitg1 = 0;
                  c4_i33 = (int32_T)(c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 *
                    ((int32_T)c4_b_c - 1)) - 1] + 1.0);
                  if ((c4_i33 < 1) || (c4_i33 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i33, 1, 9601,
                      &c4_sc_emlrtBCI, &c4_st);
                  }

                  if (chartInstance->c4_b_P[c4_i33 - 1] < c4_c_L[((int32_T)
                       (c4_b_r - 1.0) + 120 * ((int32_T)c4_b_c - 1)) - 1]) {
                    c4_i34 = (int32_T)(c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 *
                      ((int32_T)c4_b_c - 1)) - 1] + 1.0);
                    if ((c4_i34 < 1) || (c4_i34 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c4_i34, 1, 9601,
                        &c4_uc_emlrtBCI, &c4_st);
                    }

                    c4_c_j = chartInstance->c4_b_P[c4_i34 - 1];
                    c4_i36 = (int32_T)(c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 *
                      ((int32_T)c4_b_c - 1)) - 1] + 1.0);
                    if ((c4_i36 < 1) || (c4_i36 > 9601)) {
                      emlrtDynamicBoundsCheckR2012b(c4_i36, 1, 9601,
                        &c4_vc_emlrtBCI, &c4_st);
                    }

                    chartInstance->c4_b_P[c4_i36 - 1] = c4_c_L[((int32_T)c4_b_r
                      + 120 * ((int32_T)c4_b_c - 1)) - 1];
                    c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 * ((int32_T)c4_b_c - 1))
                      - 1] = c4_c_j;
                  } else {
                    c4_exitg1 = 1;
                  }
                } while (c4_exitg1 == 0);

                c4_i35 = (int32_T)(c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 *
                  ((int32_T)c4_b_c - 1)) - 1] + 1.0);
                if ((c4_i35 < 1) || (c4_i35 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i35, 1, 9601, &c4_tc_emlrtBCI,
                    &c4_st);
                }

                chartInstance->c4_b_P[c4_i35 - 1] = c4_c_L[((int32_T)c4_b_r +
                  120 * ((int32_T)c4_b_c - 1)) - 1];
              }

              do {
                c4_exitg1 = 0;
                c4_i23 = (int32_T)(c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)
                  (c4_b_c - 1.0) - 1)) - 1] + 1.0);
                if ((c4_i23 < 1) || (c4_i23 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i23, 1, 9601, &c4_mc_emlrtBCI,
                    &c4_st);
                }

                if (chartInstance->c4_b_P[c4_i23 - 1] < c4_c_L[((int32_T)c4_b_r
                     + 120 * ((int32_T)(c4_b_c - 1.0) - 1)) - 1]) {
                  c4_i26 = (int32_T)(c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)
                    (c4_b_c - 1.0) - 1)) - 1] + 1.0);
                  if ((c4_i26 < 1) || (c4_i26 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i26, 1, 9601,
                      &c4_pc_emlrtBCI, &c4_st);
                  }

                  c4_c_j = chartInstance->c4_b_P[c4_i26 - 1];
                  c4_i30 = (int32_T)(c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)
                    (c4_b_c - 1.0) - 1)) - 1] + 1.0);
                  if ((c4_i30 < 1) || (c4_i30 > 9601)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i30, 1, 9601,
                      &c4_rc_emlrtBCI, &c4_st);
                  }

                  chartInstance->c4_b_P[c4_i30 - 1] = c4_c_L[((int32_T)c4_b_r +
                    120 * ((int32_T)c4_b_c - 1)) - 1];
                  c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)(c4_b_c - 1.0) - 1))
                    - 1] = c4_c_j;
                } else {
                  c4_exitg1 = 1;
                }
              } while (c4_exitg1 == 0);

              c4_i29 = (int32_T)(c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)
                (c4_b_c - 1.0) - 1)) - 1] + 1.0);
              if ((c4_i29 < 1) || (c4_i29 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i29, 1, 9601, &c4_oc_emlrtBCI,
                  &c4_st);
              }

              chartInstance->c4_b_P[c4_i29 - 1] = c4_c_L[((int32_T)c4_b_r + 120 *
                ((int32_T)c4_b_c - 1)) - 1];
            } else {
              c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
                c4_c_L[((int32_T)(c4_b_r - 1.0) + 120 * ((int32_T)c4_b_c - 1)) -
                1];
            }
          } else if ((c4_b_c > c4_startC) && c4_varargin_1[((int32_T)c4_b_r +
                      120 * ((int32_T)(c4_b_c - 1.0) - 1)) - 1]) {
            c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
              c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)(c4_b_c - 1.0) - 1)) - 1];
          } else {
            c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
              c4_label;
            c4_i12 = (int32_T)(c4_label + 1.0);
            if ((c4_i12 < 1) || (c4_i12 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c4_i12, 1, 9601, &c4_ac_emlrtBCI,
                &c4_st);
            }

            chartInstance->c4_b_P[c4_i12 - 1] = c4_label;
            c4_label++;
          }
        } else {
          c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] = 0.0;
        }
      }
    }

    c4_d7 = muDoubleScalarRound(c4_label - c4_firstLabel);
    if (c4_d7 < 2.147483648E+9) {
      if (c4_d7 >= -2.147483648E+9) {
        c4_i8 = (int32_T)c4_d7;
      } else {
        c4_i8 = MIN_int32_T;
      }
    } else if (c4_d7 >= 2.147483648E+9) {
      c4_i8 = MAX_int32_T;
    } else {
      c4_i8 = 0;
    }

    c4_chunksSizeAndLabels[(int32_T)(c4_startC + 1.0) - 1] = c4_i8;
  }

  c4_c = c4_chunksSizeAndLabels[0];
  while (c4_c <= 160) {
    for (c4_r = 0; c4_r < 120; c4_r++) {
      c4_b_r = (real_T)c4_r + 1.0;
      if ((c4_c < 1) || (c4_c > 160)) {
        emlrtDynamicBoundsCheckR2012b(c4_c, 1, 160, &c4_cc_emlrtBCI, &c4_st);
      }

      c4_d = c4_c_L[((int32_T)c4_b_r + 120 * (c4_c - 1)) - 1];
      if (c4_d != 0.0) {
        c4_b_q0 = c4_c;
        c4_b_q1 = 1;
        if ((c4_b_q1 < 0) && (c4_b_q0 > c4_b_q1 + MAX_int32_T)) {
          c4_b_qY = MAX_int32_T;
        } else if ((c4_b_q1 > 0) && (c4_b_q0 < c4_b_q1 + MIN_int32_T)) {
          c4_b_qY = MIN_int32_T;
        } else {
          c4_b_qY = c4_b_q0 - c4_b_q1;
        }

        c4_i3 = c4_b_qY;
        if ((c4_i3 < 1) || (c4_i3 > 160)) {
          emlrtDynamicBoundsCheckR2012b(c4_i3, 1, 160, &c4_dc_emlrtBCI, &c4_st);
        }

        c4_d2 = c4_c_L[((int32_T)c4_b_r + 120 * (c4_i3 - 1)) - 1];
        if (c4_d2 != 0.0) {
          c4_b_st.site = &c4_kb_emlrtRSI;
          c4_c_q0 = c4_c;
          c4_c_q1 = 1;
          if ((c4_c_q1 < 0) && (c4_c_q0 > c4_c_q1 + MAX_int32_T)) {
            c4_c_qY = MAX_int32_T;
          } else if ((c4_c_q1 > 0) && (c4_c_q0 < c4_c_q1 + MIN_int32_T)) {
            c4_c_qY = MIN_int32_T;
          } else {
            c4_c_qY = c4_c_q0 - c4_c_q1;
          }

          c4_i4 = c4_c_qY;
          if ((c4_i4 < 1) || (c4_i4 > 160)) {
            emlrtDynamicBoundsCheckR2012b(c4_i4, 1, 160, &c4_ec_emlrtBCI,
              &c4_b_st);
          }

          c4_b_i = c4_c_L[((int32_T)c4_b_r + 120 * (c4_i4 - 1)) - 1];
          c4_j = c4_c_L[((int32_T)c4_b_r + 120 * (c4_c - 1)) - 1];
          c4_c_st.site = &c4_j_emlrtRSI;
          c4_c_i = c4_b_i;
          c4_d6 = c4_c_i;
          do {
            c4_exitg1 = 0;
            c4_i7 = (int32_T)(c4_d6 + 1.0);
            if ((c4_i7 < 1) || (c4_i7 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c4_i7, 1, 9601, &c4_r_emlrtBCI,
                &c4_c_st);
            }

            if (chartInstance->c4_b_P[c4_i7 - 1] < c4_d6) {
              c4_i9 = (int32_T)(c4_d6 + 1.0);
              if ((c4_i9 < 1) || (c4_i9 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i9, 1, 9601, &c4_s_emlrtBCI,
                  &c4_c_st);
              }

              c4_d6 = chartInstance->c4_b_P[c4_i9 - 1];
            } else {
              c4_exitg1 = 1;
            }
          } while (c4_exitg1 == 0);

          if (c4_b_i != c4_j) {
            c4_c_st.site = &c4_k_emlrtRSI;
            c4_d_i = c4_j;
            c4_rootj = c4_d_i;
            do {
              c4_exitg1 = 0;
              c4_i13 = (int32_T)(c4_rootj + 1.0);
              if ((c4_i13 < 1) || (c4_i13 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i13, 1, 9601, &c4_r_emlrtBCI,
                  &c4_c_st);
              }

              if (chartInstance->c4_b_P[c4_i13 - 1] < c4_rootj) {
                c4_i17 = (int32_T)(c4_rootj + 1.0);
                if ((c4_i17 < 1) || (c4_i17 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i17, 1, 9601, &c4_s_emlrtBCI,
                    &c4_c_st);
                }

                c4_rootj = chartInstance->c4_b_P[c4_i17 - 1];
              } else {
                c4_exitg1 = 1;
              }
            } while (c4_exitg1 == 0);

            if (c4_d6 > c4_rootj) {
              c4_d6 = c4_rootj;
            }

            c4_c_st.site = &c4_l_emlrtRSI;
            c4_f_i = c4_j;
            c4_b_root = c4_d6;
            do {
              c4_exitg1 = 0;
              c4_i25 = (int32_T)(c4_f_i + 1.0);
              if ((c4_i25 < 1) || (c4_i25 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i25, 1, 9601, &c4_u_emlrtBCI,
                  &c4_c_st);
              }

              if (chartInstance->c4_b_P[c4_i25 - 1] < c4_f_i) {
                c4_i28 = (int32_T)(c4_f_i + 1.0);
                if ((c4_i28 < 1) || (c4_i28 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i28, 1, 9601, &c4_v_emlrtBCI,
                    &c4_c_st);
                }

                c4_d_j = chartInstance->c4_b_P[c4_i28 - 1];
                c4_i32 = (int32_T)(c4_f_i + 1.0);
                if ((c4_i32 < 1) || (c4_i32 > 9601)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i32, 1, 9601, &c4_g_emlrtBCI,
                    &c4_c_st);
                }

                chartInstance->c4_b_P[c4_i32 - 1] = c4_b_root;
                c4_f_i = c4_d_j;
              } else {
                c4_exitg1 = 1;
              }
            } while (c4_exitg1 == 0);

            c4_i31 = (int32_T)(c4_f_i + 1.0);
            if ((c4_i31 < 1) || (c4_i31 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c4_i31, 1, 9601, &c4_h_emlrtBCI,
                &c4_c_st);
            }

            chartInstance->c4_b_P[c4_i31 - 1] = c4_b_root;
          }

          c4_c_st.site = &c4_m_emlrtRSI;
          c4_e_i = c4_b_i;
          c4_root = c4_d6;
          do {
            c4_exitg1 = 0;
            c4_i15 = (int32_T)(c4_e_i + 1.0);
            if ((c4_i15 < 1) || (c4_i15 > 9601)) {
              emlrtDynamicBoundsCheckR2012b(c4_i15, 1, 9601, &c4_u_emlrtBCI,
                &c4_c_st);
            }

            if (chartInstance->c4_b_P[c4_i15 - 1] < c4_e_i) {
              c4_i19 = (int32_T)(c4_e_i + 1.0);
              if ((c4_i19 < 1) || (c4_i19 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i19, 1, 9601, &c4_v_emlrtBCI,
                  &c4_c_st);
              }

              c4_b_j = chartInstance->c4_b_P[c4_i19 - 1];
              c4_i21 = (int32_T)(c4_e_i + 1.0);
              if ((c4_i21 < 1) || (c4_i21 > 9601)) {
                emlrtDynamicBoundsCheckR2012b(c4_i21, 1, 9601, &c4_g_emlrtBCI,
                  &c4_c_st);
              }

              chartInstance->c4_b_P[c4_i21 - 1] = c4_root;
              c4_e_i = c4_b_j;
            } else {
              c4_exitg1 = 1;
            }
          } while (c4_exitg1 == 0);

          c4_i20 = (int32_T)(c4_e_i + 1.0);
          if ((c4_i20 < 1) || (c4_i20 > 9601)) {
            emlrtDynamicBoundsCheckR2012b(c4_i20, 1, 9601, &c4_h_emlrtBCI,
              &c4_c_st);
          }

          chartInstance->c4_b_P[c4_i20 - 1] = c4_root;
          c4_c_L[((int32_T)c4_b_r + 120 * (c4_c - 1)) - 1] = c4_d6;
        }
      }
    }

    if ((c4_c < 1) || (c4_c > 168)) {
      emlrtDynamicBoundsCheckR2012b(c4_c, 1, 168, &c4_bc_emlrtBCI, &c4_st);
    }

    c4_c = c4_chunksSizeAndLabels[c4_c - 1];
  }

  c4_b_numComponents = 1.0;
  c4_c = 1;
  while (c4_c <= 160) {
    c4_q0 = c4_c;
    c4_q1 = 1;
    if ((c4_q1 < 0) && (c4_q0 > c4_q1 + MAX_int32_T)) {
      c4_qY = MAX_int32_T;
    } else if ((c4_q1 > 0) && (c4_q0 < c4_q1 + MIN_int32_T)) {
      c4_qY = MIN_int32_T;
    } else {
      c4_qY = c4_q0 - c4_q1;
    }

    c4_b_a = c4_qY;
    c4_i = (int64_T)c4_b_a * 120LL;
    if (c4_i > 2147483647LL) {
      c4_i = 2147483647LL;
    } else if (c4_i < -2147483648LL) {
      c4_i = -2147483648LL;
    }

    c4_y = (int32_T)c4_i;
    c4_g_x = c4_y;
    c4_i_x = c4_g_x;
    c4_j_x = c4_i_x;
    c4_k_x = c4_j_x;
    c4_c_a = c4_k_x;
    c4_l_x = c4_c_a;
    c4_z = (real_T)c4_l_x / 2.0;
    c4_d4 = muDoubleScalarRound(c4_z);
    if (c4_d4 < 2.147483648E+9) {
      if (c4_d4 >= -2.147483648E+9) {
        c4_i5 = (int32_T)c4_d4;
      } else {
        c4_i5 = MIN_int32_T;
      }
    } else if (c4_d4 >= 2.147483648E+9) {
      c4_i5 = MAX_int32_T;
    } else {
      c4_i5 = 0;
    }

    c4_b_z = c4_i5;
    c4_r_x = c4_b_z;
    c4_c_y = c4_r_x;
    c4_d_q0 = c4_c_y;
    c4_d_q1 = 1;
    if ((c4_d_q1 < 0) && (c4_d_q0 < MIN_int32_T - c4_d_q1)) {
      c4_d_qY = MIN_int32_T;
    } else if ((c4_d_q1 > 0) && (c4_d_q0 > MAX_int32_T - c4_d_q1)) {
      c4_d_qY = MAX_int32_T;
    } else {
      c4_d_qY = c4_d_q0 + c4_d_q1;
    }

    c4_stripeFirstLabel = c4_d_qY;
    c4_e_q0 = c4_stripeFirstLabel;
    c4_e_q1 = 1;
    if ((c4_e_q1 < 0) && (c4_e_q0 < MIN_int32_T - c4_e_q1)) {
      c4_e_qY = MIN_int32_T;
    } else if ((c4_e_q1 > 0) && (c4_e_q0 > MAX_int32_T - c4_e_q1)) {
      c4_e_qY = MAX_int32_T;
    } else {
      c4_e_qY = c4_e_q0 + c4_e_q1;
    }

    c4_i11 = c4_e_qY;
    c4_f_q0 = c4_c;
    c4_f_q1 = 1;
    if ((c4_f_q1 < 0) && (c4_f_q0 < MIN_int32_T - c4_f_q1)) {
      c4_f_qY = MIN_int32_T;
    } else if ((c4_f_q1 > 0) && (c4_f_q0 > MAX_int32_T - c4_f_q1)) {
      c4_f_qY = MAX_int32_T;
    } else {
      c4_f_qY = c4_f_q0 + c4_f_q1;
    }

    c4_i16 = c4_f_qY;
    if ((c4_i16 < 1) || (c4_i16 > 168)) {
      emlrtDynamicBoundsCheckR2012b(c4_i16, 1, 168, &c4_fc_emlrtBCI, &c4_st);
    }

    c4_g_q0 = c4_stripeFirstLabel;
    c4_g_q1 = c4_chunksSizeAndLabels[c4_i16 - 1];
    if ((c4_g_q0 < 0) && (c4_g_q1 < MIN_int32_T - c4_g_q0)) {
      c4_g_qY = MIN_int32_T;
    } else if ((c4_g_q0 > 0) && (c4_g_q1 > MAX_int32_T - c4_g_q0)) {
      c4_g_qY = MAX_int32_T;
    } else {
      c4_g_qY = c4_g_q0 + c4_g_q1;
    }

    c4_i22 = c4_g_qY;
    c4_b_st.site = &c4_lb_emlrtRSI;
    c4_e_a = c4_i11;
    c4_b_b = c4_i22;
    c4_f_a = c4_e_a;
    c4_c_b = c4_b_b;
    if (c4_f_a > c4_c_b) {
      c4_overflow = false;
    } else {
      c4_overflow = (c4_c_b > 2147483646);
    }

    if (c4_overflow) {
      c4_c_st.site = &c4_n_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_c_st);
    }

    for (c4_g_i = c4_i11; c4_g_i <= c4_i22; c4_g_i++) {
      if ((c4_g_i < 1) || (c4_g_i > 9601)) {
        emlrtDynamicBoundsCheckR2012b(c4_g_i, 1, 9601, &c4_ic_emlrtBCI, &c4_st);
      }

      c4_h_q0 = c4_g_i;
      c4_h_q1 = 1;
      if ((c4_h_q1 < 0) && (c4_h_q0 > c4_h_q1 + MAX_int32_T)) {
        c4_h_qY = MAX_int32_T;
      } else if ((c4_h_q1 > 0) && (c4_h_q0 < c4_h_q1 + MIN_int32_T)) {
        c4_h_qY = MIN_int32_T;
      } else {
        c4_h_qY = c4_h_q0 - c4_h_q1;
      }

      if (chartInstance->c4_b_P[c4_g_i - 1] < (real_T)c4_h_qY) {
        c4_i37 = (int32_T)(chartInstance->c4_b_P[c4_g_i - 1] + 1.0);
        if ((c4_i37 < 1) || (c4_i37 > 9601)) {
          emlrtDynamicBoundsCheckR2012b(c4_i37, 1, 9601, &c4_jc_emlrtBCI, &c4_st);
        }

        chartInstance->c4_b_P[c4_g_i - 1] = chartInstance->c4_b_P[c4_i37 - 1];
      } else {
        chartInstance->c4_b_P[c4_g_i - 1] = c4_b_numComponents;
        c4_b_numComponents++;
      }
    }

    if ((c4_c < 1) || (c4_c > 168)) {
      emlrtDynamicBoundsCheckR2012b(c4_c, 1, 168, &c4_hc_emlrtBCI, &c4_st);
    }

    c4_c = c4_chunksSizeAndLabels[c4_c - 1];
  }

  c4_b_numComponents--;
  for (c4_c_c = 0; c4_c_c < 160; c4_c_c++) {
    c4_b_c = (real_T)c4_c_c + 1.0;
    for (c4_c_r = 0; c4_c_r < 120; c4_c_r++) {
      c4_b_r = (real_T)c4_c_r + 1.0;
      c4_i2 = (int32_T)(c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) -
                        1] + 1.0);
      if ((c4_i2 < 1) || (c4_i2 > 9601)) {
        emlrtDynamicBoundsCheckR2012b(c4_i2, 1, 9601, &c4_n_emlrtBCI, &c4_st);
      }

      c4_c_L[((int32_T)c4_b_r + 120 * ((int32_T)c4_b_c - 1)) - 1] =
        chartInstance->c4_b_P[c4_i2 - 1];
    }
  }

  *c4_numComponents = c4_b_numComponents;
}

static void c4_BoundaryFinderObjectHoles_findBoundaries
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_images_internal_coder_BoundaryFinderObjectHoles *c4_obj, real_T
   c4_cutoffL, real_T c4_holesN, c4_coder_array_cell_wrap_0 *c4_B)
{
  static int32_T c4_ndl4c[8] = { 1, 2, 3, 0, 0, 0, 0, 0 };

  static int32_T c4_ndl8c[8] = { 1, 2, 3, 4, 5, 6, 7, 0 };

  static int32_T c4_nsdl4c[8] = { 3, 0, 1, 2, 0, 0, 0, 0 };

  static int32_T c4_nsdl8c[8] = { 7, 7, 1, 1, 3, 3, 5, 5 };

  c4_coder_array_boolean_T c4_regionHasBeenTraced;
  c4_coder_array_cell_wrap_0 c4_r;
  c4_coder_array_int32_T c4_b_scratch;
  c4_coder_array_int32_T c4_scratch;
  c4_coder_array_real_T_2D c4_boundary;
  c4_images_internal_coder_BoundaryFinderObjectHoles *c4_b_obj;
  c4_images_internal_coder_BoundaryFinderObjectHoles *c4_c_obj;
  c4_images_internal_coder_BoundaryFinderObjectHoles *c4_d_obj;
  c4_images_internal_coder_BoundaryFinderObjectHoles *c4_e_obj;
  c4_images_internal_coder_BoundaryFinderObjectHoles *c4_f_obj;
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  real_T c4_b_conn;
  real_T c4_conn;
  real_T c4_numRegions;
  real_T c4_previousLabel;
  int32_T c4_iv[2];
  int32_T c4_M;
  int32_T c4_N;
  int32_T c4_a;
  int32_T c4_b_M;
  int32_T c4_b_a;
  int32_T c4_b_b;
  int32_T c4_b_currentPixel;
  int32_T c4_b_direction;
  int32_T c4_b_idx;
  int32_T c4_b_initDepartureDir;
  int32_T c4_b_k;
  int32_T c4_b_label;
  int32_T c4_b_loop_ub;
  int32_T c4_b_neighbor;
  int32_T c4_b_nextSearchDir;
  int32_T c4_b_numPixels;
  int32_T c4_b_r;
  int32_T c4_b_scratchLength;
  int32_T c4_c;
  int32_T c4_c_M;
  int32_T c4_c_b;
  int32_T c4_c_label;
  int32_T c4_c_loop_ub;
  int32_T c4_c_scratchLength;
  int32_T c4_currentPixel;
  int32_T c4_d_loop_ub;
  int32_T c4_d_scratchLength;
  int32_T c4_direction;
  int32_T c4_e_loop_ub;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i10;
  int32_T c4_i11;
  int32_T c4_i12;
  int32_T c4_i13;
  int32_T c4_i14;
  int32_T c4_i15;
  int32_T c4_i16;
  int32_T c4_i17;
  int32_T c4_i18;
  int32_T c4_i19;
  int32_T c4_i2;
  int32_T c4_i20;
  int32_T c4_i21;
  int32_T c4_i22;
  int32_T c4_i23;
  int32_T c4_i24;
  int32_T c4_i25;
  int32_T c4_i26;
  int32_T c4_i27;
  int32_T c4_i28;
  int32_T c4_i29;
  int32_T c4_i3;
  int32_T c4_i30;
  int32_T c4_i31;
  int32_T c4_i32;
  int32_T c4_i33;
  int32_T c4_i34;
  int32_T c4_i35;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_idx;
  int32_T c4_initDepartureDir;
  int32_T c4_k;
  int32_T c4_label;
  int32_T c4_linearIdx;
  int32_T c4_loop_ub;
  int32_T c4_neighbor;
  int32_T c4_nextSearchDir;
  int32_T c4_numPixels;
  int32_T c4_scratchLength;
  boolean_T c4_b_foundNextPixel;
  boolean_T c4_b_isDone;
  boolean_T c4_exitg1;
  boolean_T c4_foundNextPixel;
  boolean_T c4_guard1;
  boolean_T c4_isDone;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_M = c4_obj->numRows;
  c4_N = c4_obj->numCols - 1;
  c4_numRegions = c4_cutoffL + c4_holesN;
  if (c4_numRegions != (real_T)(int32_T)muDoubleScalarFloor(c4_numRegions)) {
    emlrtIntegerCheckR2012b(c4_numRegions, &c4_b_emlrtDCI, (emlrtConstCTX)c4_sp);
  }

  c4_iv[0] = (int32_T)c4_numRegions;
  c4_array_cell_wrap_0_Constructor1(chartInstance, &c4_r);
  c4_array_cell_wrap_0_SetSize(chartInstance, c4_sp, &c4_r, &c4_m_emlrtRTEI,
    c4_iv[0]);
  c4_st.site = &c4_vd_emlrtRSI;
  c4_array_cell_wrap_0_SetSize(chartInstance, &c4_st, c4_B, &c4_n_emlrtRTEI,
    c4_r.size[0]);
  c4_array_cell_wrap_0_Destructor1(chartInstance, &c4_r);
  c4_array_boolean_T_Constructor(chartInstance, &c4_regionHasBeenTraced);
  if (c4_numRegions != (real_T)(int32_T)muDoubleScalarFloor(c4_numRegions)) {
    emlrtIntegerCheckR2012b(c4_numRegions, &c4_c_emlrtDCI, (emlrtConstCTX)c4_sp);
  }

  c4_st.site = &c4_wd_emlrtRSI;
  c4_array_boolean_T_SetSize(chartInstance, &c4_st, &c4_regionHasBeenTraced,
    &c4_o_emlrtRTEI, (int32_T)c4_numRegions);
  if (c4_numRegions != (real_T)(int32_T)muDoubleScalarFloor(c4_numRegions)) {
    emlrtIntegerCheckR2012b(c4_numRegions, &c4_c_emlrtDCI, (emlrtConstCTX)c4_sp);
  }

  c4_loop_ub = (int32_T)c4_numRegions - 1;
  for (c4_i = 0; c4_i <= c4_loop_ub; c4_i++) {
    c4_regionHasBeenTraced.vector.data[c4_i] = false;
  }

  if (c4_numRegions > 0.0) {
    c4_st.site = &c4_rb_emlrtRSI;
    c4_b_obj = c4_obj;
    c4_b_obj->startMarker = -2.0;
    c4_b_obj->boundaryMarker = -3.0;
    c4_b_M = c4_b_obj->numRows;
    if (c4_b_obj->conn == 8.0) {
      c4_b_obj->neighborOffsets[0] = -1;
      c4_b_obj->neighborOffsets[1] = c4_b_M - 1;
      c4_b_obj->neighborOffsets[2] = c4_b_M;
      c4_b_obj->neighborOffsets[3] = c4_b_M + 1;
      c4_b_obj->neighborOffsets[4] = 1;
      c4_b_obj->neighborOffsets[5] = 1 - c4_b_M;
      c4_b_obj->neighborOffsets[6] = -c4_b_M;
      c4_b_obj->neighborOffsets[7] = -c4_b_M - 1;
      c4_b_obj->validationOffsets[0] = -1;
      c4_b_obj->validationOffsets[1] = c4_b_M;
      c4_b_obj->validationOffsets[2] = 1;
      c4_b_obj->validationOffsets[3] = -c4_b_M;
      c4_b_obj->validationOffsets[4] = 0;
      c4_b_obj->validationOffsets[5] = 0;
      c4_b_obj->validationOffsets[6] = 0;
      c4_b_obj->validationOffsets[7] = 0;
    } else {
      c4_b_obj->neighborOffsets[0] = -1;
      c4_b_obj->neighborOffsets[1] = c4_b_M;
      c4_b_obj->neighborOffsets[2] = 1;
      c4_b_obj->neighborOffsets[3] = -c4_b_M;
      c4_b_obj->neighborOffsets[4] = 0;
      c4_b_obj->neighborOffsets[5] = 0;
      c4_b_obj->neighborOffsets[6] = 0;
      c4_b_obj->neighborOffsets[7] = 0;
      c4_b_obj->validationOffsets[0] = -1;
      c4_b_obj->validationOffsets[1] = c4_b_M - 1;
      c4_b_obj->validationOffsets[2] = c4_b_M;
      c4_b_obj->validationOffsets[3] = c4_b_M + 1;
      c4_b_obj->validationOffsets[4] = 1;
      c4_b_obj->validationOffsets[5] = 1 - c4_b_M;
      c4_b_obj->validationOffsets[6] = -c4_b_M;
      c4_b_obj->validationOffsets[7] = -c4_b_M - 1;
    }

    if (c4_b_obj->conn == 8.0) {
      for (c4_i2 = 0; c4_i2 < 8; c4_i2++) {
        c4_b_obj->nextDirectionLut[c4_i2] = c4_ndl8c[c4_i2];
      }

      for (c4_i4 = 0; c4_i4 < 8; c4_i4++) {
        c4_b_obj->nextSearchDirectionLut[c4_i4] = c4_nsdl8c[c4_i4];
      }
    } else {
      for (c4_i1 = 0; c4_i1 < 8; c4_i1++) {
        c4_b_obj->nextDirectionLut[c4_i1] = c4_ndl4c[c4_i1];
      }

      for (c4_i3 = 0; c4_i3 < 8; c4_i3++) {
        c4_b_obj->nextSearchDirectionLut[c4_i3] = c4_nsdl4c[c4_i3];
      }
    }

    c4_st.site = &c4_sb_emlrtRSI;
    c4_c_obj = c4_obj;
    c4_c_obj->nextSearchDir = 1;
    c4_st.site = &c4_tb_emlrtRSI;
    c4_d_obj = c4_obj;
    c4_d_obj->startMarkerHoles = -2.0;
    c4_d_obj->boundaryMarkerHoles = -3.0;
    c4_c_M = c4_d_obj->numRows;
    if (c4_d_obj->ConnectivityHoles == 8.0) {
      c4_d_obj->neighborOffsetsHoles[0] = -1;
      c4_d_obj->neighborOffsetsHoles[1] = c4_c_M - 1;
      c4_d_obj->neighborOffsetsHoles[2] = c4_c_M;
      c4_d_obj->neighborOffsetsHoles[3] = c4_c_M + 1;
      c4_d_obj->neighborOffsetsHoles[4] = 1;
      c4_d_obj->neighborOffsetsHoles[5] = 1 - c4_c_M;
      c4_d_obj->neighborOffsetsHoles[6] = -c4_c_M;
      c4_d_obj->neighborOffsetsHoles[7] = -c4_c_M - 1;
      c4_d_obj->validationOffsetsHoles[0] = -1;
      c4_d_obj->validationOffsetsHoles[1] = c4_c_M;
      c4_d_obj->validationOffsetsHoles[2] = 1;
      c4_d_obj->validationOffsetsHoles[3] = -c4_c_M;
      c4_d_obj->validationOffsetsHoles[4] = 0;
      c4_d_obj->validationOffsetsHoles[5] = 0;
      c4_d_obj->validationOffsetsHoles[6] = 0;
      c4_d_obj->validationOffsetsHoles[7] = 0;
    } else {
      c4_d_obj->neighborOffsetsHoles[0] = -1;
      c4_d_obj->neighborOffsetsHoles[1] = c4_c_M;
      c4_d_obj->neighborOffsetsHoles[2] = 1;
      c4_d_obj->neighborOffsetsHoles[3] = -c4_c_M;
      c4_d_obj->neighborOffsetsHoles[4] = 0;
      c4_d_obj->neighborOffsetsHoles[5] = 0;
      c4_d_obj->neighborOffsetsHoles[6] = 0;
      c4_d_obj->neighborOffsetsHoles[7] = 0;
      c4_d_obj->validationOffsetsHoles[0] = -1;
      c4_d_obj->validationOffsetsHoles[1] = c4_c_M - 1;
      c4_d_obj->validationOffsetsHoles[2] = c4_c_M;
      c4_d_obj->validationOffsetsHoles[3] = c4_c_M + 1;
      c4_d_obj->validationOffsetsHoles[4] = 1;
      c4_d_obj->validationOffsetsHoles[5] = 1 - c4_c_M;
      c4_d_obj->validationOffsetsHoles[6] = -c4_c_M;
      c4_d_obj->validationOffsetsHoles[7] = -c4_c_M - 1;
    }

    if (c4_d_obj->ConnectivityHoles == 8.0) {
      for (c4_i6 = 0; c4_i6 < 8; c4_i6++) {
        c4_d_obj->nextDirectionLutHoles[c4_i6] = c4_ndl8c[c4_i6];
      }

      for (c4_i8 = 0; c4_i8 < 8; c4_i8++) {
        c4_d_obj->nextSearchDirectionLutHoles[c4_i8] = c4_nsdl8c[c4_i8];
      }
    } else {
      for (c4_i5 = 0; c4_i5 < 8; c4_i5++) {
        c4_d_obj->nextDirectionLutHoles[c4_i5] = c4_ndl4c[c4_i5];
      }

      for (c4_i7 = 0; c4_i7 < 8; c4_i7++) {
        c4_d_obj->nextSearchDirectionLutHoles[c4_i7] = c4_nsdl4c[c4_i7];
      }
    }

    c4_i9 = c4_N;
    c4_array_real_T_2D_Constructor(chartInstance, &c4_boundary);
    c4_array_int32_T_Constructor(chartInstance, &c4_scratch);
    c4_array_int32_T_Constructor(chartInstance, &c4_b_scratch);
    for (c4_c = 2; c4_c <= c4_i9; c4_c++) {
      c4_i10 = c4_M;
      for (c4_b_r = 2; c4_b_r < c4_i10; c4_b_r++) {
        c4_linearIdx = c4_M * (c4_c - 1) + c4_b_r;
        if ((c4_linearIdx < 1) || (c4_linearIdx > 19764)) {
          emlrtDynamicBoundsCheckR2012b(c4_linearIdx, 1, 19764, &c4_yc_emlrtBCI,
            (emlrtConstCTX)c4_sp);
        }

        c4_label = (int32_T)c4_obj->paddedLabelMatrix[c4_linearIdx - 1];
        c4_i11 = c4_linearIdx - 1;
        if ((c4_i11 < 1) || (c4_i11 > 19764)) {
          emlrtDynamicBoundsCheckR2012b(c4_i11, 1, 19764, &c4_ad_emlrtBCI,
            (emlrtConstCTX)c4_sp);
        }

        c4_previousLabel = c4_obj->paddedLabelMatrix[c4_i11 - 1];
        if ((c4_label > 0) && ((real_T)c4_label <= c4_cutoffL) &&
            ((c4_previousLabel == 0.0) || (c4_previousLabel > c4_cutoffL))) {
          c4_i12 = c4_regionHasBeenTraced.size[0];
          if ((c4_label < 1) || (c4_label > c4_i12)) {
            emlrtDynamicBoundsCheckR2012b(c4_label, 1, c4_i12, &c4_bd_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          if (!c4_regionHasBeenTraced.vector.data[c4_label - 1]) {
            c4_st.site = &c4_ub_emlrtRSI;
            c4_e_obj = c4_obj;
            c4_idx = c4_linearIdx;
            c4_conn = c4_obj->conn;
            c4_b_label = c4_label;
            c4_array_int32_T_SetSize(chartInstance, &c4_st, &c4_scratch,
              &c4_p_emlrtRTEI, 200);
            c4_scratchLength = 200;
            c4_scratch.vector.data[0] = c4_idx;
            c4_e_obj->paddedLabelMatrix[c4_idx - 1] = c4_e_obj->startMarker;
            c4_isDone = false;
            c4_numPixels = 2;
            c4_currentPixel = c4_idx - 1;
            c4_nextSearchDir = c4_e_obj->nextSearchDir;
            c4_initDepartureDir = -1;
            while (!c4_isDone) {
              c4_direction = c4_nextSearchDir;
              c4_foundNextPixel = false;
              c4_i15 = (int32_T)c4_conn;
              emlrtForLoopVectorCheckR2021a(1.0, 1.0, c4_conn, mxDOUBLE_CLASS,
                c4_i15, &c4_hb_emlrtRTEI, &c4_st);
              c4_k = 0;
              c4_guard1 = false;
              c4_exitg1 = false;
              while ((!c4_exitg1) && (c4_k <= c4_i15 - 1)) {
                c4_a = c4_currentPixel + 1;
                c4_i24 = c4_direction + 1;
                if ((c4_i24 < 1) || (c4_i24 > 8)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i24, 1, 8, &c4_ed_emlrtBCI,
                    &c4_st);
                }

                c4_b_b = c4_e_obj->neighborOffsets[c4_i24 - 1];
                c4_neighbor = c4_a + c4_b_b;
                if ((c4_neighbor < 1) || (c4_neighbor > 19764)) {
                  emlrtDynamicBoundsCheckR2012b(c4_neighbor, 1, 19764,
                    &c4_fd_emlrtBCI, &c4_st);
                }

                if ((c4_e_obj->paddedLabelMatrix[c4_neighbor - 1] == (real_T)
                     c4_b_label) || (c4_e_obj->paddedLabelMatrix[c4_neighbor - 1]
                                     == c4_e_obj->startMarker)) {
                  if ((c4_e_obj->paddedLabelMatrix[c4_currentPixel] ==
                       c4_e_obj->startMarker) && (c4_initDepartureDir == -1)) {
                    c4_initDepartureDir = c4_direction;
                    c4_guard1 = true;
                  } else if ((c4_e_obj->paddedLabelMatrix[c4_currentPixel] ==
                              c4_e_obj->startMarker) && (c4_initDepartureDir ==
                              c4_direction)) {
                    c4_isDone = true;
                    c4_foundNextPixel = true;
                    c4_e_obj->paddedLabelMatrix[c4_currentPixel] = (real_T)
                      c4_b_label;
                  } else {
                    c4_guard1 = true;
                  }

                  c4_exitg1 = true;
                } else {
                  c4_i31 = c4_direction + 1;
                  if ((c4_i31 < 1) || (c4_i31 > 8)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i31, 1, 8, &c4_id_emlrtBCI,
                      &c4_st);
                  }

                  c4_direction = c4_e_obj->nextDirectionLut[c4_i31 - 1];
                  c4_k++;
                  c4_guard1 = false;
                }
              }

              if (c4_guard1) {
                c4_i23 = c4_direction + 1;
                if ((c4_i23 < 1) || (c4_i23 > 8)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i23, 1, 8, &c4_kd_emlrtBCI,
                    &c4_st);
                }

                c4_nextSearchDir = c4_e_obj->nextSearchDirectionLut[c4_i23 - 1];
                c4_foundNextPixel = true;
                if (c4_scratchLength <= c4_numPixels) {
                  c4_b_st.site = &c4_wb_emlrtRSI;
                  c4_expandScratchSpace(chartInstance, &c4_b_st, &c4_scratch,
                                        c4_scratchLength, &c4_b_scratch,
                                        &c4_c_scratchLength);
                  c4_array_int32_T_SetSize(chartInstance, &c4_st, &c4_scratch,
                    &c4_s_emlrtRTEI, c4_b_scratch.size[0]);
                  c4_d_loop_ub = c4_b_scratch.size[0] - 1;
                  for (c4_i34 = 0; c4_i34 <= c4_d_loop_ub; c4_i34++) {
                    c4_scratch.vector.data[c4_i34] =
                      c4_b_scratch.vector.data[c4_i34];
                  }

                  c4_scratchLength = c4_c_scratchLength;
                }

                c4_i30 = c4_scratch.size[0];
                if ((c4_numPixels < 1) || (c4_numPixels > c4_i30)) {
                  emlrtDynamicBoundsCheckR2012b(c4_numPixels, 1, c4_i30,
                    &c4_md_emlrtBCI, &c4_st);
                }

                c4_scratch.vector.data[c4_numPixels - 1] = c4_neighbor;
                c4_numPixels++;
                if (c4_numPixels - 1 == MAX_int32_T) {
                  c4_isDone = true;
                } else {
                  c4_currentPixel = c4_neighbor - 1;
                }
              }

              if (!c4_foundNextPixel) {
                c4_numPixels = 3;
                c4_scratch.vector.data[1] = c4_scratch.vector.data[0];
                c4_isDone = true;
              }
            }

            c4_b_st.site = &c4_xb_emlrtRSI;
            c4_BoundaryFinder_copyCoordsToBuf(chartInstance, &c4_b_st, c4_e_obj,
              c4_numPixels - 1, &c4_scratch, &c4_boundary);
            c4_i14 = c4_B->size[0] - 1;
            c4_i16 = c4_label - 1;
            if ((c4_i16 < 0) || (c4_i16 > c4_i14)) {
              emlrtDynamicBoundsCheckR2012b(c4_i16, 0, c4_i14, &c4_wc_emlrtBCI,
                (emlrtConstCTX)c4_sp);
            }

            c4_i20 = c4_i16;
            c4_st.site = &c4_ud_emlrtRSI;
            c4_array_real_T_2D_SetSize(chartInstance, &c4_st, &c4_B->
              vector.data[c4_i20].f1, &c4_q_emlrtRTEI, c4_boundary.size[0], 2);
            c4_b_loop_ub = (c4_boundary.size[0] << 1) - 1;
            for (c4_i22 = 0; c4_i22 <= c4_b_loop_ub; c4_i22++) {
              c4_B->vector.data[c4_i20].f1.vector.data[c4_i22] =
                c4_boundary.vector.data[c4_i22];
            }

            c4_i28 = c4_regionHasBeenTraced.size[0];
            if ((c4_label < 1) || (c4_label > c4_i28)) {
              emlrtDynamicBoundsCheckR2012b(c4_label, 1, c4_i28, &c4_dd_emlrtBCI,
                (emlrtConstCTX)c4_sp);
            }

            c4_regionHasBeenTraced.vector.data[c4_label - 1] = true;
          }
        }

        if (((real_T)c4_label > c4_cutoffL) && (c4_previousLabel > 0.0) &&
            (c4_previousLabel <= c4_cutoffL)) {
          c4_i13 = c4_regionHasBeenTraced.size[0];
          if ((c4_label < 1) || (c4_label > c4_i13)) {
            emlrtDynamicBoundsCheckR2012b(c4_label, 1, c4_i13, &c4_cd_emlrtBCI,
              (emlrtConstCTX)c4_sp);
          }

          if (!c4_regionHasBeenTraced.vector.data[c4_label - 1]) {
            c4_st.site = &c4_vb_emlrtRSI;
            c4_f_obj = c4_obj;
            c4_b_idx = c4_linearIdx;
            c4_b_conn = c4_obj->ConnectivityHoles;
            c4_c_label = c4_label;
            c4_array_int32_T_SetSize(chartInstance, &c4_st, &c4_scratch,
              &c4_p_emlrtRTEI, 200);
            c4_b_scratchLength = 200;
            c4_scratch.vector.data[0] = c4_b_idx;
            c4_f_obj->paddedLabelMatrix[c4_b_idx - 1] = c4_f_obj->startMarker;
            c4_b_isDone = false;
            c4_b_numPixels = 2;
            c4_b_currentPixel = c4_b_idx - 1;
            c4_b_nextSearchDir = c4_f_obj->nextSearchDir;
            c4_b_initDepartureDir = -1;
            while (!c4_b_isDone) {
              c4_b_direction = c4_b_nextSearchDir;
              c4_b_foundNextPixel = false;
              c4_i18 = (int32_T)c4_b_conn;
              emlrtForLoopVectorCheckR2021a(1.0, 1.0, c4_b_conn, mxDOUBLE_CLASS,
                c4_i18, &c4_hb_emlrtRTEI, &c4_st);
              c4_b_k = 0;
              c4_guard1 = false;
              c4_exitg1 = false;
              while ((!c4_exitg1) && (c4_b_k <= c4_i18 - 1)) {
                c4_b_a = c4_b_currentPixel + 1;
                c4_i27 = c4_b_direction + 1;
                if ((c4_i27 < 1) || (c4_i27 > 8)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i27, 1, 8, &c4_hd_emlrtBCI,
                    &c4_st);
                }

                c4_c_b = c4_f_obj->neighborOffsetsHoles[c4_i27 - 1];
                c4_b_neighbor = c4_b_a + c4_c_b;
                if ((c4_b_neighbor < 1) || (c4_b_neighbor > 19764)) {
                  emlrtDynamicBoundsCheckR2012b(c4_b_neighbor, 1, 19764,
                    &c4_fd_emlrtBCI, &c4_st);
                }

                if ((c4_f_obj->paddedLabelMatrix[c4_b_neighbor - 1] == (real_T)
                     c4_c_label) || (c4_f_obj->paddedLabelMatrix[c4_b_neighbor -
                                     1] == c4_f_obj->startMarker)) {
                  if ((c4_f_obj->paddedLabelMatrix[c4_b_currentPixel] ==
                       c4_f_obj->startMarker) && (c4_b_initDepartureDir == -1))
                  {
                    c4_b_initDepartureDir = c4_b_direction;
                    c4_guard1 = true;
                  } else if ((c4_f_obj->paddedLabelMatrix[c4_b_currentPixel] ==
                              c4_f_obj->startMarker) && (c4_b_initDepartureDir ==
                              c4_b_direction)) {
                    c4_b_isDone = true;
                    c4_b_foundNextPixel = true;
                    c4_f_obj->paddedLabelMatrix[c4_b_currentPixel] = (real_T)
                      c4_c_label;
                  } else {
                    c4_guard1 = true;
                  }

                  c4_exitg1 = true;
                } else {
                  c4_i33 = c4_b_direction + 1;
                  if ((c4_i33 < 1) || (c4_i33 > 8)) {
                    emlrtDynamicBoundsCheckR2012b(c4_i33, 1, 8, &c4_jd_emlrtBCI,
                      &c4_st);
                  }

                  c4_b_direction = c4_f_obj->nextDirectionLutHoles[c4_i33 - 1];
                  c4_b_k++;
                  c4_guard1 = false;
                }
              }

              if (c4_guard1) {
                c4_i26 = c4_b_direction + 1;
                if ((c4_i26 < 1) || (c4_i26 > 8)) {
                  emlrtDynamicBoundsCheckR2012b(c4_i26, 1, 8, &c4_ld_emlrtBCI,
                    &c4_st);
                }

                c4_b_nextSearchDir = c4_f_obj->
                  nextSearchDirectionLutHoles[c4_i26 - 1];
                c4_b_foundNextPixel = true;
                if (c4_b_scratchLength <= c4_b_numPixels) {
                  c4_b_st.site = &c4_wb_emlrtRSI;
                  c4_expandScratchSpace(chartInstance, &c4_b_st, &c4_scratch,
                                        c4_b_scratchLength, &c4_b_scratch,
                                        &c4_d_scratchLength);
                  c4_array_int32_T_SetSize(chartInstance, &c4_st, &c4_scratch,
                    &c4_s_emlrtRTEI, c4_b_scratch.size[0]);
                  c4_e_loop_ub = c4_b_scratch.size[0] - 1;
                  for (c4_i35 = 0; c4_i35 <= c4_e_loop_ub; c4_i35++) {
                    c4_scratch.vector.data[c4_i35] =
                      c4_b_scratch.vector.data[c4_i35];
                  }

                  c4_b_scratchLength = c4_d_scratchLength;
                }

                c4_i32 = c4_scratch.size[0];
                if ((c4_b_numPixels < 1) || (c4_b_numPixels > c4_i32)) {
                  emlrtDynamicBoundsCheckR2012b(c4_b_numPixels, 1, c4_i32,
                    &c4_md_emlrtBCI, &c4_st);
                }

                c4_scratch.vector.data[c4_b_numPixels - 1] = c4_b_neighbor;
                c4_b_numPixels++;
                if (c4_b_numPixels - 1 == MAX_int32_T) {
                  c4_b_isDone = true;
                } else {
                  c4_b_currentPixel = c4_b_neighbor - 1;
                }
              }

              if (!c4_b_foundNextPixel) {
                c4_b_numPixels = 3;
                c4_scratch.vector.data[1] = c4_scratch.vector.data[0];
                c4_b_isDone = true;
              }
            }

            c4_b_st.site = &c4_xb_emlrtRSI;
            c4_BoundaryFinder_copyCoordsToBuf(chartInstance, &c4_b_st, c4_f_obj,
              c4_b_numPixels - 1, &c4_scratch, &c4_boundary);
            c4_i17 = c4_B->size[0] - 1;
            c4_i19 = c4_label - 1;
            if ((c4_i19 < 0) || (c4_i19 > c4_i17)) {
              emlrtDynamicBoundsCheckR2012b(c4_i19, 0, c4_i17, &c4_xc_emlrtBCI,
                (emlrtConstCTX)c4_sp);
            }

            c4_i21 = c4_i19;
            c4_st.site = &c4_td_emlrtRSI;
            c4_array_real_T_2D_SetSize(chartInstance, &c4_st, &c4_B->
              vector.data[c4_i21].f1, &c4_r_emlrtRTEI, c4_boundary.size[0], 2);
            c4_c_loop_ub = (c4_boundary.size[0] << 1) - 1;
            for (c4_i25 = 0; c4_i25 <= c4_c_loop_ub; c4_i25++) {
              c4_B->vector.data[c4_i21].f1.vector.data[c4_i25] =
                c4_boundary.vector.data[c4_i25];
            }

            c4_i29 = c4_regionHasBeenTraced.size[0];
            if ((c4_label < 1) || (c4_label > c4_i29)) {
              emlrtDynamicBoundsCheckR2012b(c4_label, 1, c4_i29, &c4_gd_emlrtBCI,
                (emlrtConstCTX)c4_sp);
            }

            c4_regionHasBeenTraced.vector.data[c4_label - 1] = true;
          }
        }
      }
    }

    c4_array_int32_T_Destructor(chartInstance, &c4_b_scratch);
    c4_array_int32_T_Destructor(chartInstance, &c4_scratch);
    c4_array_real_T_2D_Destructor(chartInstance, &c4_boundary);
  }

  c4_array_boolean_T_Destructor(chartInstance, &c4_regionHasBeenTraced);
}

static void c4_expandScratchSpace(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T *c4_scratchIn,
  int32_T c4_scratchLengthIn, c4_coder_array_int32_T *c4_scratch, int32_T
  *c4_scratchLength)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_b_scratchLength;
  int32_T c4_c_b;
  int32_T c4_d_b;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_k;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_b_b = c4_scratchLengthIn;
  c4_b_scratchLength = c4_b_b << 1;
  c4_st.site = &c4_xd_emlrtRSI;
  c4_array_int32_T_SetSize(chartInstance, &c4_st, c4_scratch, &c4_t_emlrtRTEI,
    c4_b_scratchLength);
  c4_st.site = &c4_yb_emlrtRSI;
  c4_c_b = c4_scratchLengthIn;
  c4_d_b = c4_c_b;
  if (c4_d_b < 1) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_d_b > 2147483646);
  }

  if (c4_overflow) {
    c4_b_st.site = &c4_n_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
  }

  for (c4_k = 0; c4_k < c4_scratchLengthIn; c4_k++) {
    c4_b_k = c4_k + 1;
    c4_i = c4_scratchIn->size[0];
    if ((c4_b_k < 1) || (c4_b_k > c4_i)) {
      emlrtDynamicBoundsCheckR2012b(c4_b_k, 1, c4_i, &c4_nd_emlrtBCI,
        (emlrtConstCTX)c4_sp);
    }

    c4_i1 = c4_scratch->size[0];
    if ((c4_b_k < 1) || (c4_b_k > c4_i1)) {
      emlrtDynamicBoundsCheckR2012b(c4_b_k, 1, c4_i1, &c4_od_emlrtBCI,
        (emlrtConstCTX)c4_sp);
    }

    c4_scratch->vector.data[c4_b_k - 1] = c4_scratchIn->vector.data[c4_b_k - 1];
  }

  *c4_scratchLength = c4_b_scratchLength;
}

static void c4_BoundaryFinder_copyCoordsToBuf
  (SFc4_flightControlSystemInstanceStruct *chartInstance, const emlrtStack
   *c4_sp, c4_images_internal_coder_BoundaryFinderObjectHoles *c4_obj, int32_T
   c4_numPixels, c4_coder_array_int32_T *c4_linearIndices,
   c4_coder_array_real_T_2D *c4_boundary)
{
  emlrtStack c4_b_st;
  emlrtStack c4_st;
  real_T c4_d;
  int32_T c4_a;
  int32_T c4_b_b;
  int32_T c4_b_k;
  int32_T c4_c_b;
  int32_T c4_col;
  int32_T c4_d_b;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_k;
  int32_T c4_row;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_d = (real_T)c4_numPixels;
  if (!(c4_d >= 0.0)) {
    emlrtNonNegativeCheckR2012b(c4_d, &c4_d_emlrtDCI, (emlrtConstCTX)c4_sp);
  }

  c4_st.site = &c4_sd_emlrtRSI;
  c4_array_real_T_2D_SetSize(chartInstance, &c4_st, c4_boundary, &c4_u_emlrtRTEI,
    (int32_T)muDoubleScalarFloor(c4_d), 2);
  c4_st.site = &c4_ac_emlrtRSI;
  c4_b_b = c4_numPixels;
  c4_c_b = c4_b_b;
  if (c4_c_b < 1) {
    c4_overflow = false;
  } else {
    c4_overflow = (c4_c_b > 2147483646);
  }

  if (c4_overflow) {
    c4_b_st.site = &c4_n_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_b_st);
  }

  for (c4_k = 0; c4_k < c4_numPixels; c4_k++) {
    c4_b_k = c4_k + 1;
    c4_i = c4_linearIndices->size[0];
    if ((c4_b_k < 1) || (c4_b_k > c4_i)) {
      emlrtDynamicBoundsCheckR2012b(c4_b_k, 1, c4_i, &c4_pd_emlrtBCI,
        (emlrtConstCTX)c4_sp);
    }

    c4_a = c4_linearIndices->vector.data[c4_b_k - 1];
    c4_d_b = c4_obj->numRows;
    c4_col = c4_div_s32_ndbzs(chartInstance, c4_a, c4_d_b, 0, 0U, 0, 0);
    c4_i1 = c4_linearIndices->size[0];
    if ((c4_b_k < 1) || (c4_b_k > c4_i1)) {
      emlrtDynamicBoundsCheckR2012b(c4_b_k, 1, c4_i1, &c4_qd_emlrtBCI,
        (emlrtConstCTX)c4_sp);
    }

    c4_row = c4_linearIndices->vector.data[c4_b_k - 1] - c4_col *
      c4_obj->numRows;
    c4_i2 = c4_boundary->size[0];
    if ((c4_b_k < 1) || (c4_b_k > c4_i2)) {
      emlrtDynamicBoundsCheckR2012b(c4_b_k, 1, c4_i2, &c4_rd_emlrtBCI,
        (emlrtConstCTX)c4_sp);
    }

    c4_boundary->vector.data[c4_b_k - 1] = (real_T)(c4_row - 1);
    c4_i3 = c4_boundary->size[0];
    if ((c4_b_k < 1) || (c4_b_k > c4_i3)) {
      emlrtDynamicBoundsCheckR2012b(c4_b_k, 1, c4_i3, &c4_sd_emlrtBCI,
        (emlrtConstCTX)c4_sp);
    }

    c4_boundary->vector.data[(c4_b_k + c4_boundary->size[0]) - 1] = (real_T)
      c4_col;
  }
}

static void c4_polyfit(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, c4_coder_array_real_T *c4_x, c4_coder_array_real_T
  *c4_y, real_T c4_p[2])
{
  static char_T c4_cv1[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E',
    'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

  static char_T c4_cv4[33] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'L', 'A', 'P', 'A', 'C', 'K', 'C', 'a', 'l', 'l', 'E',
    'r', 'r', 'o', 'r', 'I', 'n', 'f', 'o' };

  static char_T c4_cv[29] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'o', 'l',
    'y', 'f', 'i', 't', ':', 'X', 'Y', 'S', 'i', 'z', 'e', 'M', 'i', 's', 'm',
    'a', 't', 'c', 'h' };

  static char_T c4_cv3[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd', 'g',
    'e', 'q', 'p', '3' };

  static char_T c4_cv6[14] = { 'L', 'A', 'P', 'A', 'C', 'K', 'E', '_', 'd', 'o',
    'r', 'm', 'q', 'r' };

  static char_T c4_cv2[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'm',
    'e', 'm' };

  static char_T c4_cv5[12] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'n', 'o', 'm',
    'e', 'm' };

  ptrdiff_t c4_jpvt_t[2];
  ptrdiff_t c4_b_info_t;
  ptrdiff_t c4_b_lda_t;
  ptrdiff_t c4_info_t;
  ptrdiff_t c4_lda_t;
  ptrdiff_t c4_m_t;
  ptrdiff_t c4_n_t;
  ptrdiff_t c4_ncc_t;
  ptrdiff_t c4_nrc_t;
  ptrdiff_t c4_nrf_t;
  c4_coder_array_real_T c4_B;
  c4_coder_array_real_T_2D c4_V;
  emlrtStack c4_b_st;
  emlrtStack c4_c_st;
  emlrtStack c4_d_st;
  emlrtStack c4_e_st;
  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_g_y = NULL;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_k_y = NULL;
  const mxArray *c4_l_y = NULL;
  const mxArray *c4_m_y = NULL;
  const mxArray *c4_n_y = NULL;
  const mxArray *c4_r_y = NULL;
  const mxArray *c4_s_y = NULL;
  const mxArray *c4_t_y = NULL;
  const mxArray *c4_u_y = NULL;
  const mxArray *c4_v_y = NULL;
  const mxArray *c4_w_y = NULL;
  real_T c4_tau_data[2];
  real_T c4_b_k;
  real_T c4_b_x;
  real_T c4_c_b;
  real_T c4_c_x;
  real_T c4_d_x;
  real_T c4_d_y;
  real_T c4_e_x;
  real_T c4_e_y;
  real_T c4_f_x;
  real_T c4_f_y;
  real_T c4_g_x;
  real_T c4_h_x;
  real_T c4_i_y;
  real_T c4_j_y;
  real_T c4_n;
  real_T c4_o_y;
  real_T c4_p_y;
  real_T c4_q_y;
  real_T c4_scale;
  real_T c4_tol;
  real_T c4_varargin_2;
  real_T c4_z;
  int32_T c4_jpvt[2];
  int32_T c4_b_B[1];
  int32_T c4_tau[1];
  int32_T c4_tau_size[1];
  int32_T c4_assumedRank;
  int32_T c4_b_i;
  int32_T c4_b_info;
  int32_T c4_b_j;
  int32_T c4_b_loop_ub;
  int32_T c4_b_m;
  int32_T c4_b_ma;
  int32_T c4_b_minmn;
  int32_T c4_b_mn;
  int32_T c4_b_val;
  int32_T c4_c_i;
  int32_T c4_c_info;
  int32_T c4_c_j;
  int32_T c4_c_k;
  int32_T c4_c_loop_ub;
  int32_T c4_c_m;
  int32_T c4_d_b;
  int32_T c4_d_i;
  int32_T c4_d_info;
  int32_T c4_d_k;
  int32_T c4_d_m;
  int32_T c4_e_b;
  int32_T c4_e_i;
  int32_T c4_e_info;
  int32_T c4_e_k;
  int32_T c4_f_b;
  int32_T c4_f_i;
  int32_T c4_f_info;
  int32_T c4_f_k;
  int32_T c4_g_b;
  int32_T c4_g_k;
  int32_T c4_h_b;
  int32_T c4_h_k;
  int32_T c4_i;
  int32_T c4_i1;
  int32_T c4_i2;
  int32_T c4_i3;
  int32_T c4_i4;
  int32_T c4_i5;
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i_b;
  int32_T c4_i_k;
  int32_T c4_info;
  int32_T c4_j;
  int32_T c4_j_b;
  int32_T c4_j_k;
  int32_T c4_k;
  int32_T c4_k_b;
  int32_T c4_k_k;
  int32_T c4_l_b;
  int32_T c4_loop_ub;
  int32_T c4_m;
  int32_T c4_m_b;
  int32_T c4_ma;
  int32_T c4_maxmn;
  int32_T c4_minmana;
  int32_T c4_minmn;
  int32_T c4_mn;
  int32_T c4_pj;
  int32_T c4_rankA;
  int32_T c4_rr;
  int32_T c4_val;
  boolean_T c4_b1;
  boolean_T c4_b2;
  boolean_T c4_b_b;
  boolean_T c4_b_overflow;
  boolean_T c4_b_p;
  boolean_T c4_c_overflow;
  boolean_T c4_c_p;
  boolean_T c4_d_overflow;
  boolean_T c4_d_p;
  boolean_T c4_e_overflow;
  boolean_T c4_e_p;
  boolean_T c4_exitg1;
  boolean_T c4_f_p;
  boolean_T c4_g_p;
  boolean_T c4_overflow;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_b_st.prev = &c4_st;
  c4_b_st.tls = c4_st.tls;
  c4_c_st.prev = &c4_b_st;
  c4_c_st.tls = c4_b_st.tls;
  c4_d_st.prev = &c4_c_st;
  c4_d_st.tls = c4_c_st.tls;
  c4_e_st.prev = &c4_d_st;
  c4_e_st.tls = c4_d_st.tls;
  if (c4_x->size[0] != c4_y->size[0]) {
    c4_b_y = NULL;
    sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 29),
                  false);
    c4_c_y = NULL;
    sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 29),
                  false);
    sf_mex_call(c4_sp, &c4_b_emlrtMCI, "error", 0U, 2U, 14, c4_b_y, 14,
                sf_mex_call(c4_sp, NULL, "getString", 1U, 1U, 14, sf_mex_call
      (c4_sp, NULL, "message", 1U, 1U, 14, c4_c_y)));
  }

  c4_n = (real_T)c4_x->size[0];
  c4_array_real_T_2D_Constructor(chartInstance, &c4_V);
  c4_array_real_T_2D_SetSize(chartInstance, c4_sp, &c4_V, &c4_v_emlrtRTEI,
    (int32_T)c4_n, 2);
  c4_b_b = (c4_V.size[0] == 0);
  if (!c4_b_b) {
    c4_i = (int32_T)c4_n;
    for (c4_k = 0; c4_k < c4_i; c4_k++) {
      c4_b_k = (real_T)c4_k + 1.0;
      c4_V.vector.data[((int32_T)c4_b_k + c4_V.size[0]) - 1] = 1.0;
    }

    c4_i1 = (int32_T)c4_n;
    for (c4_c_k = 0; c4_c_k < c4_i1; c4_c_k++) {
      c4_b_k = (real_T)c4_c_k + 1.0;
      c4_V.vector.data[(int32_T)c4_b_k - 1] = c4_x->vector.data[(int32_T)c4_b_k
        - 1];
    }
  }

  c4_st.site = &c4_bc_emlrtRSI;
  c4_b_st.site = &c4_ec_emlrtRSI;
  c4_ma = c4_V.size[0];
  c4_c_st.site = &c4_hc_emlrtRSI;
  c4_m = c4_ma;
  c4_b_ma = c4_V.size[0];
  c4_minmana = muIntScalarMin_sint32(c4_b_ma, 2);
  c4_tau_size[0] = c4_minmana;
  c4_b1 = (c4_V.size[0] == 0);
  if (c4_b1 || (c4_m < 1)) {
    c4_tau[0] = c4_tau_size[0];
    c4_loop_ub = c4_tau[0] - 1;
    if (c4_loop_ub >= 0) {
      memset(&c4_tau_data[0], 0, (uint32_T)(c4_loop_ub + 1) * sizeof(real_T));
    }

    for (c4_d_k = 0; c4_d_k < 2; c4_d_k++) {
      c4_e_k = c4_d_k;
      c4_jpvt[c4_e_k] = c4_e_k + 1;
    }
  } else {
    for (c4_i2 = 0; c4_i2 < 2; c4_i2++) {
      c4_jpvt_t[c4_i2] = (ptrdiff_t)0;
    }

    c4_lda_t = (ptrdiff_t)c4_b_ma;
    c4_m_t = (ptrdiff_t)c4_m;
    c4_n_t = (ptrdiff_t)2;
    c4_info_t = LAPACKE_dgeqp3(102, c4_m_t, c4_n_t, &c4_V.vector.data[0],
      c4_lda_t, &c4_jpvt_t[0], &c4_tau_data[0]);
    c4_info = (int32_T)c4_info_t;
    c4_d_st.site = &c4_ic_emlrtRSI;
    c4_b_info = c4_info;
    c4_c_info = c4_b_info;
    c4_b_p = (c4_c_info != 0);
    if (c4_b_p) {
      c4_c_p = true;
      c4_val = c4_b_info;
      c4_d_p = false;
      if (c4_val == -4) {
        c4_d_p = true;
      }

      if (!c4_d_p) {
        if (c4_b_info == -1010) {
          c4_h_y = NULL;
          sf_mex_assign(&c4_h_y, sf_mex_create("y", c4_cv2, 10, 0U, 1, 0U, 2, 1,
            12), false);
          c4_l_y = NULL;
          sf_mex_assign(&c4_l_y, sf_mex_create("y", c4_cv2, 10, 0U, 1, 0U, 2, 1,
            12), false);
          sf_mex_call(&c4_d_st, &c4_c_emlrtMCI, "error", 0U, 2U, 14, c4_h_y, 14,
                      sf_mex_call(&c4_d_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_d_st, NULL, "message", 1U, 1U, 14, c4_l_y)));
        } else {
          c4_g_y = NULL;
          sf_mex_assign(&c4_g_y, sf_mex_create("y", c4_cv1, 10, 0U, 1, 0U, 2, 1,
            33), false);
          c4_k_y = NULL;
          sf_mex_assign(&c4_k_y, sf_mex_create("y", c4_cv1, 10, 0U, 1, 0U, 2, 1,
            33), false);
          c4_m_y = NULL;
          sf_mex_assign(&c4_m_y, sf_mex_create("y", c4_cv3, 10, 0U, 1, 0U, 2, 1,
            14), false);
          c4_n_y = NULL;
          sf_mex_assign(&c4_n_y, sf_mex_create("y", &c4_b_info, 6, 0U, 0, 0U, 0),
                        false);
          sf_mex_call(&c4_d_st, &c4_d_emlrtMCI, "error", 0U, 2U, 14, c4_g_y, 14,
                      sf_mex_call(&c4_d_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_d_st, NULL, "message", 1U, 3U, 14, c4_k_y, 14,
                        c4_m_y, 14, c4_n_y)));
        }
      }
    } else {
      c4_c_p = false;
    }

    if (c4_c_p) {
      for (c4_j = 0; c4_j < 2; c4_j++) {
        c4_b_j = c4_j;
        c4_d_st.site = &c4_jc_emlrtRSI;
        c4_e_b = c4_m;
        c4_g_b = c4_e_b;
        if (c4_g_b < 1) {
          c4_b_overflow = false;
        } else {
          c4_b_overflow = (c4_g_b > 2147483646);
        }

        if (c4_b_overflow) {
          c4_e_st.site = &c4_n_emlrtRSI;
          c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
        }

        for (c4_b_i = 0; c4_b_i < c4_m; c4_b_i++) {
          c4_c_i = c4_b_i;
          c4_V.vector.data[c4_b_j * c4_b_ma + c4_c_i] = rtNaN;
        }
      }

      c4_b_minmn = muIntScalarMin_sint32(c4_m, 2);
      c4_d_st.site = &c4_kc_emlrtRSI;
      c4_d_b = c4_b_minmn;
      c4_f_b = c4_d_b;
      if (c4_f_b < 1) {
        c4_overflow = false;
      } else {
        c4_overflow = (c4_f_b > 2147483646);
      }

      if (c4_overflow) {
        c4_e_st.site = &c4_n_emlrtRSI;
        c4_check_forloop_overflow_error(chartInstance, &c4_e_st);
      }

      c4_i3 = (uint8_T)c4_b_minmn;
      for (c4_g_k = 0; c4_g_k < c4_i3; c4_g_k++) {
        c4_e_k = c4_g_k;
        c4_tau_data[c4_e_k] = rtNaN;
      }

      c4_i5 = c4_b_minmn;
      for (c4_h_k = c4_i5 + 1; c4_h_k <= c4_minmana; c4_h_k++) {
        c4_tau_data[1] = 0.0;
      }

      for (c4_j_k = 0; c4_j_k < 2; c4_j_k++) {
        c4_e_k = c4_j_k;
        c4_jpvt[c4_e_k] = c4_e_k + 1;
      }
    } else {
      for (c4_f_k = 0; c4_f_k < 2; c4_f_k++) {
        c4_e_k = c4_f_k;
        c4_jpvt[c4_e_k] = (int32_T)c4_jpvt_t[c4_e_k];
      }
    }
  }

  c4_rr = 0;
  c4_b_m = c4_V.size[0];
  if (c4_b_m < 2) {
    c4_minmn = c4_b_m;
    c4_maxmn = 2;
  } else {
    c4_minmn = 2;
    c4_maxmn = c4_b_m;
  }

  if (c4_minmn > 0) {
    c4_varargin_2 = 2.2204460492503131E-15 * (real_T)c4_maxmn;
    c4_d_y = c4_varargin_2;
    c4_e_y = c4_d_y;
    c4_f_y = c4_e_y;
    c4_c_b = c4_f_y;
    c4_i_y = c4_c_b;
    c4_j_y = c4_i_y;
    c4_scale = muDoubleScalarMin(1.4901161193847656E-8, c4_j_y);
    c4_b_x = c4_V.vector.data[0];
    c4_c_x = c4_b_x;
    c4_d_x = c4_c_x;
    c4_o_y = muDoubleScalarAbs(c4_d_x);
    c4_tol = c4_scale * c4_o_y;
    c4_exitg1 = false;
    while ((!c4_exitg1) && (c4_rr < c4_minmn)) {
      c4_e_x = c4_V.vector.data[c4_rr + c4_V.size[0] * c4_rr];
      c4_f_x = c4_e_x;
      c4_g_x = c4_f_x;
      c4_p_y = muDoubleScalarAbs(c4_g_x);
      if (!(c4_p_y <= c4_tol)) {
        c4_rr++;
      } else {
        c4_exitg1 = true;
      }
    }
  }

  c4_b_st.site = &c4_fc_emlrtRSI;
  c4_assumedRank = 0;
  c4_c_m = c4_V.size[0];
  if (c4_c_m < 2) {
    c4_mn = c4_c_m;
  } else {
    c4_mn = 2;
  }

  if (c4_mn > 0) {
    c4_c_st.site = &c4_kd_emlrtRSI;
    c4_h_b = c4_mn;
    c4_i_b = c4_h_b;
    if (c4_i_b < 1) {
      c4_c_overflow = false;
    } else {
      c4_c_overflow = (c4_i_b > 2147483646);
    }

    if (c4_c_overflow) {
      c4_d_st.site = &c4_n_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
    }

    c4_i6 = (uint8_T)c4_mn;
    for (c4_i_k = 0; c4_i_k < c4_i6; c4_i_k++) {
      c4_k_k = c4_i_k;
      if (c4_V.vector.data[c4_k_k + c4_V.size[0] * c4_k_k] != 0.0) {
        c4_assumedRank++;
      }
    }
  }

  c4_b_st.site = &c4_gc_emlrtRSI;
  c4_array_real_T_Constructor(chartInstance, &c4_B);
  c4_array_real_T_SetSize(chartInstance, &c4_b_st, &c4_B, &c4_y_emlrtRTEI,
    c4_y->size[0]);
  c4_b_loop_ub = c4_y->size[0] - 1;
  for (c4_i4 = 0; c4_i4 <= c4_b_loop_ub; c4_i4++) {
    c4_B.vector.data[c4_i4] = c4_y->vector.data[c4_i4];
  }

  c4_rankA = c4_assumedRank;
  memset(&c4_p[0], 0, sizeof(real_T) << 1);
  c4_c_st.site = &c4_ld_emlrtRSI;
  c4_d_st.site = &c4_od_emlrtRSI;
  c4_d_m = c4_V.size[0];
  if (c4_d_m < 2) {
    c4_b_mn = c4_d_m;
  } else {
    c4_b_mn = 2;
  }

  c4_b2 = (c4_V.size[0] == 0);
  if ((!c4_b2) && (c4_B.size[0] != 0)) {
    c4_nrc_t = (ptrdiff_t)c4_B.size[0];
    c4_ncc_t = (ptrdiff_t)1;
    c4_nrf_t = (ptrdiff_t)c4_b_mn;
    c4_b_lda_t = (ptrdiff_t)c4_d_m;
    c4_b_info_t = LAPACKE_dormqr(102, 'L', 'T', c4_nrc_t, c4_ncc_t, c4_nrf_t,
      &c4_V.vector.data[0], c4_b_lda_t, &c4_tau_data[0], &c4_B.vector.data[0],
      c4_nrc_t);
    c4_d_info = (int32_T)c4_b_info_t;
    c4_e_st.site = &c4_pd_emlrtRSI;
    c4_e_info = c4_d_info;
    c4_f_info = c4_e_info;
    c4_e_p = (c4_f_info != 0);
    if (c4_e_p) {
      c4_f_p = true;
      c4_b_val = c4_e_info;
      c4_g_p = false;
      if (c4_b_val == -7) {
        c4_g_p = true;
      } else if (c4_b_val == -9) {
        c4_g_p = true;
      } else if (c4_b_val == -10) {
        c4_g_p = true;
      }

      if (!c4_g_p) {
        if (c4_e_info == -1010) {
          c4_s_y = NULL;
          sf_mex_assign(&c4_s_y, sf_mex_create("y", c4_cv5, 10, 0U, 1, 0U, 2, 1,
            12), false);
          c4_u_y = NULL;
          sf_mex_assign(&c4_u_y, sf_mex_create("y", c4_cv5, 10, 0U, 1, 0U, 2, 1,
            12), false);
          sf_mex_call(&c4_e_st, &c4_c_emlrtMCI, "error", 0U, 2U, 14, c4_s_y, 14,
                      sf_mex_call(&c4_e_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_e_st, NULL, "message", 1U, 1U, 14, c4_u_y)));
        } else {
          c4_r_y = NULL;
          sf_mex_assign(&c4_r_y, sf_mex_create("y", c4_cv4, 10, 0U, 1, 0U, 2, 1,
            33), false);
          c4_t_y = NULL;
          sf_mex_assign(&c4_t_y, sf_mex_create("y", c4_cv4, 10, 0U, 1, 0U, 2, 1,
            33), false);
          c4_v_y = NULL;
          sf_mex_assign(&c4_v_y, sf_mex_create("y", c4_cv6, 10, 0U, 1, 0U, 2, 1,
            14), false);
          c4_w_y = NULL;
          sf_mex_assign(&c4_w_y, sf_mex_create("y", &c4_e_info, 6, 0U, 0, 0U, 0),
                        false);
          sf_mex_call(&c4_e_st, &c4_d_emlrtMCI, "error", 0U, 2U, 14, c4_r_y, 14,
                      sf_mex_call(&c4_e_st, NULL, "getString", 1U, 1U, 14,
            sf_mex_call(&c4_e_st, NULL, "message", 1U, 3U, 14, c4_t_y, 14,
                        c4_v_y, 14, c4_w_y)));
        }
      }
    } else {
      c4_f_p = false;
    }

    if (c4_f_p) {
      c4_b_B[0] = c4_B.size[0];
      c4_array_real_T_SetSize(chartInstance, &c4_d_st, &c4_B, &c4_ab_emlrtRTEI,
        c4_b_B[0]);
      c4_c_loop_ub = c4_b_B[0] - 1;
      for (c4_i7 = 0; c4_i7 <= c4_c_loop_ub; c4_i7++) {
        c4_B.vector.data[c4_i7] = rtNaN;
      }
    }
  }

  c4_c_st.site = &c4_md_emlrtRSI;
  c4_j_b = c4_rankA;
  c4_k_b = c4_j_b;
  if (c4_k_b < 1) {
    c4_d_overflow = false;
  } else {
    c4_d_overflow = (c4_k_b > 2147483646);
  }

  if (c4_d_overflow) {
    c4_d_st.site = &c4_n_emlrtRSI;
    c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
  }

  for (c4_d_i = 0; c4_d_i < c4_rankA; c4_d_i++) {
    c4_e_i = c4_d_i;
    c4_p[c4_jpvt[c4_e_i] - 1] = c4_B.vector.data[c4_e_i];
  }

  c4_array_real_T_Destructor(chartInstance, &c4_B);
  for (c4_c_j = c4_rankA; c4_c_j >= 1; c4_c_j--) {
    c4_pj = c4_jpvt[c4_c_j - 1] - 1;
    c4_h_x = c4_p[c4_pj];
    c4_q_y = c4_V.vector.data[(c4_c_j + c4_V.size[0] * (c4_c_j - 1)) - 1];
    c4_z = c4_h_x / c4_q_y;
    c4_p[c4_pj] = c4_z;
    c4_i8 = c4_c_j - 1;
    c4_c_st.site = &c4_nd_emlrtRSI;
    c4_l_b = c4_i8;
    c4_m_b = c4_l_b;
    if (c4_m_b < 1) {
      c4_e_overflow = false;
    } else {
      c4_e_overflow = (c4_m_b > 2147483646);
    }

    if (c4_e_overflow) {
      c4_d_st.site = &c4_n_emlrtRSI;
      c4_check_forloop_overflow_error(chartInstance, &c4_d_st);
    }

    c4_i9 = (uint8_T)c4_i8;
    for (c4_f_i = 0; c4_f_i < c4_i9; c4_f_i++) {
      c4_p[c4_jpvt[0] - 1] -= c4_p[c4_pj] * c4_V.vector.data[c4_V.size[0] *
        (c4_c_j - 1)];
    }
  }

  c4_array_real_T_2D_Destructor(chartInstance, &c4_V);
  if (c4_x->size[0] <= 1) {
    c4_st.site = &c4_cc_emlrtRSI;
    c4_warning(chartInstance, &c4_st);
  } else if (c4_rr <= 1) {
    c4_st.site = &c4_dc_emlrtRSI;
    c4_b_warning(chartInstance, &c4_st);
  }
}

static void c4_warning(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp)
{
  static char_T c4_msgID[28] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'o',
    'l', 'y', 'f', 'i', 't', ':', 'P', 'o', 'l', 'y', 'N', 'o', 't', 'U', 'n',
    'i', 'q', 'u', 'e' };

  static char_T c4_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c4_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 7), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv1, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_msgID, 10, 0U, 1, 0U, 2, 1, 28),
                false);
  c4_st.site = &c4_rd_emlrtRSI;
  c4_c_feval(chartInstance, &c4_st, c4_y, c4_b_feval(chartInstance, &c4_st,
              c4_b_y, c4_c_y));
}

static void c4_b_warning(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp)
{
  static char_T c4_msgID[38] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'p', 'o',
    'l', 'y', 'f', 'i', 't', ':', 'R', 'e', 'p', 'e', 'a', 't', 'e', 'd', 'P',
    'o', 'i', 'n', 't', 's', 'O', 'r', 'R', 'e', 's', 'c', 'a', 'l', 'e' };

  static char_T c4_cv[7] = { 'w', 'a', 'r', 'n', 'i', 'n', 'g' };

  static char_T c4_cv1[7] = { 'm', 'e', 's', 's', 'a', 'g', 'e' };

  emlrtStack c4_st;
  const mxArray *c4_b_y = NULL;
  const mxArray *c4_c_y = NULL;
  const mxArray *c4_y = NULL;
  c4_st.prev = c4_sp;
  c4_st.tls = c4_sp->tls;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_cv, 10, 0U, 1, 0U, 2, 1, 7), false);
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_cv1, 10, 0U, 1, 0U, 2, 1, 7),
                false);
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_msgID, 10, 0U, 1, 0U, 2, 1, 38),
                false);
  c4_st.site = &c4_rd_emlrtRSI;
  c4_e_feval(chartInstance, &c4_st, c4_y, c4_d_feval(chartInstance, &c4_st,
              c4_b_y, c4_c_y));
}

const mxArray *sf_c4_flightControlSystem_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static real32_T c4_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_nullptr, const char_T *c4_identifier)
{
  emlrtMsgIdentifier c4_thisId;
  real32_T c4_y;
  c4_thisId.fIdentifier = (const char_T *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nullptr), &c4_thisId);
  sf_mex_destroy(&c4_nullptr);
  return c4_y;
}

static real32_T c4_b_emlrt_marshallIn(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real32_T c4_f;
  real32_T c4_y;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_f, 0, 1, 0U, 0, 0U, 0);
  c4_y = c4_f;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_feval(SFc4_flightControlSystemInstanceStruct *chartInstance,
                     const emlrtStack *c4_sp, const mxArray *c4_input0, const
                     mxArray *c4_input1, const mxArray *c4_input2)
{
  (void)chartInstance;
  sf_mex_call(c4_sp, NULL, "feval", 0U, 3U, 14, sf_mex_dup(c4_input0), 14,
              sf_mex_dup(c4_input1), 14, sf_mex_dup(c4_input2));
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  sf_mex_destroy(&c4_input2);
}

static const mxArray *c4_assert(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1)
{
  const mxArray *c4_m = NULL;
  (void)chartInstance;
  c4_m = NULL;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, NULL, "assert", 0U, 2U, 14, sf_mex_dup
    (c4_input0), 14, sf_mex_dup(c4_input1)), false);
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  return c4_m;
}

static const mxArray *c4_b_feval(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1)
{
  const mxArray *c4_m = NULL;
  (void)chartInstance;
  c4_m = NULL;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c4_input0), 14, sf_mex_dup(c4_input1)), false);
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  return c4_m;
}

static void c4_c_feval(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1)
{
  (void)chartInstance;
  sf_mex_call(c4_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c4_input0), 14,
              sf_mex_dup(c4_input1));
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
}

static const mxArray *c4_d_feval(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, const mxArray *c4_input0, const
  mxArray *c4_input1)
{
  const mxArray *c4_m = NULL;
  (void)chartInstance;
  c4_m = NULL;
  sf_mex_assign(&c4_m, sf_mex_call(c4_sp, NULL, "feval", 1U, 2U, 14, sf_mex_dup
    (c4_input0), 14, sf_mex_dup(c4_input1)), false);
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
  return c4_m;
}

static void c4_e_feval(SFc4_flightControlSystemInstanceStruct *chartInstance,
  const emlrtStack *c4_sp, const mxArray *c4_input0, const mxArray *c4_input1)
{
  (void)chartInstance;
  sf_mex_call(c4_sp, NULL, "feval", 0U, 2U, 14, sf_mex_dup(c4_input0), 14,
              sf_mex_dup(c4_input1));
  sf_mex_destroy(&c4_input0);
  sf_mex_destroy(&c4_input1);
}

static void c4_array_real_T_2D_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_real_T_2D
  *c4_coderArray, const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0, int32_T
  c4_size1)
{
  real_T *c4_newData;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  (void)chartInstance;
  c4_coderArray->size[0] = c4_size0;
  c4_coderArray->size[1] = c4_size1;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)(int32_T)
    emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)c4_coderArray->size[0],
                       c4_srcLocation, (void *)c4_sp), (size_t)(uint32_T)
    c4_coderArray->size[1], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_real_T_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_real_T *c4_coderArray,
  const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0)
{
  real_T *c4_newData;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  (void)chartInstance;
  c4_coderArray->size[0] = c4_size0;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c4_coderArray->size[0], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (real_T *)emlrtMallocMex(sizeof(real_T) * (uint32_T)
      c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof(real_T) * (uint32_T)
             c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_cell_wrap_0_SetSize(SFc4_flightControlSystemInstanceStruct *
  chartInstance, const emlrtStack *c4_sp, c4_coder_array_cell_wrap_0
  *c4_coderArray, const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0)
{
  c4_cell_wrap_0 *c4_newData;
  int32_T c4_b_i;
  int32_T c4_i;
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  c4_coderArray->size[0] = c4_size0;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c4_coderArray->size[0], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel < c4_coderArray->vector.numel) {
    for (c4_i = c4_newNumel; c4_i < c4_coderArray->vector.numel; c4_i++) {
      c4_array_cell_wrap_0_Destructor(chartInstance, &c4_coderArray->
        vector.data[c4_i]);
    }
  }

  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (c4_cell_wrap_0 *)emlrtMallocMex(sizeof(c4_cell_wrap_0) *
      (uint32_T)c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof(c4_cell_wrap_0) *
             (uint32_T)c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  for (c4_b_i = c4_coderArray->vector.numel; c4_b_i < c4_newNumel; c4_b_i++) {
    c4_array_cell_wrap_0_Constructor(chartInstance, &c4_coderArray->
      vector.data[c4_b_i]);
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_real_T_2D_Destructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_real_T_2D *c4_coderArray)
{
  (void)chartInstance;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static void c4_array_cell_wrap_0_Destructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance, c4_cell_wrap_0
   *c4_pStruct)
{
  c4_array_real_T_2D_Destructor(chartInstance, &c4_pStruct->f1);
}

static void c4_array_cell_wrap_0_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance, c4_cell_wrap_0
   *c4_pStruct)
{
  c4_array_real_T_2D_Constructor(chartInstance, &c4_pStruct->f1);
}

static void c4_array_real_T_2D_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_real_T_2D *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (real_T *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
  c4_coderArray->size[1] = 0;
}

static void c4_array_boolean_T_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_boolean_T
  *c4_coderArray, const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0)
{
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  boolean_T *c4_newData;
  (void)chartInstance;
  c4_coderArray->size[0] = c4_size0;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c4_coderArray->size[0], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (boolean_T *)emlrtMallocMex(sizeof(boolean_T) * (uint32_T)
      c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof(boolean_T)
             * (uint32_T)c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_int32_T_SetSize(SFc4_flightControlSystemInstanceStruct
  *chartInstance, const emlrtStack *c4_sp, c4_coder_array_int32_T *c4_coderArray,
  const emlrtRTEInfo *c4_srcLocation, int32_T c4_size0)
{
  int32_T c4_newCapacity;
  int32_T c4_newNumel;
  int32_T *c4_newData;
  (void)chartInstance;
  c4_coderArray->size[0] = c4_size0;
  c4_newNumel = (int32_T)emlrtSizeMulR2012b((size_t)1U, (size_t)(uint32_T)
    c4_coderArray->size[0], c4_srcLocation, (void *)c4_sp);
  if (c4_newNumel > c4_coderArray->vector.allocated) {
    c4_newCapacity = c4_coderArray->vector.allocated;
    if (c4_newCapacity < 16) {
      c4_newCapacity = 16;
    }

    while (c4_newCapacity < c4_newNumel) {
      if (c4_newCapacity > 1073741823) {
        c4_newCapacity = MAX_int32_T;
      } else {
        c4_newCapacity <<= 1;
      }
    }

    c4_newData = (int32_T *)emlrtMallocMex(sizeof(int32_T) * (uint32_T)
      c4_newCapacity);
    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if ((void *)c4_newData == NULL) {
      emlrtHeapAllocationErrorR2012b(c4_srcLocation, (void *)c4_sp);
    }

    if (c4_coderArray->vector.data != NULL) {
      memcpy(c4_newData, c4_coderArray->vector.data, sizeof(int32_T) * (uint32_T)
             c4_coderArray->vector.numel);
      if (c4_coderArray->vector.owner) {
        emlrtFreeMex(c4_coderArray->vector.data);
      }
    }

    c4_coderArray->vector.data = c4_newData;
    c4_coderArray->vector.allocated = c4_newCapacity;
    c4_coderArray->vector.owner = true;
  }

  c4_coderArray->vector.numel = c4_newNumel;
}

static void c4_array_cell_wrap_0_Constructor1
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_cell_wrap_0 *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (c4_cell_wrap_0 *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
}

static void c4_array_real_T_Constructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_real_T *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (real_T *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
}

static void c4_array_cell_wrap_0_Destructor1
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_cell_wrap_0 *c4_coderArray)
{
  int32_T c4_i;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data !=
       (c4_cell_wrap_0 *)NULL)) {
    for (c4_i = 0; c4_i < c4_coderArray->vector.numel; c4_i++) {
      c4_array_cell_wrap_0_Destructor(chartInstance, &c4_coderArray->
        vector.data[c4_i]);
    }

    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static void c4_array_real_T_Destructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_real_T *c4_coderArray)
{
  (void)chartInstance;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data != (real_T *)
       NULL)) {
    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static void c4_array_boolean_T_Constructor
  (SFc4_flightControlSystemInstanceStruct *chartInstance,
   c4_coder_array_boolean_T *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (boolean_T *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
}

static void c4_array_int32_T_Constructor(SFc4_flightControlSystemInstanceStruct *
  chartInstance, c4_coder_array_int32_T *c4_coderArray)
{
  (void)chartInstance;
  c4_coderArray->vector.data = (int32_T *)NULL;
  c4_coderArray->vector.numel = 0;
  c4_coderArray->vector.allocated = 0;
  c4_coderArray->vector.owner = true;
  c4_coderArray->size[0] = 0;
}

static void c4_array_boolean_T_Destructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_boolean_T *c4_coderArray)
{
  (void)chartInstance;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data != (boolean_T *)
       NULL)) {
    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static void c4_array_int32_T_Destructor(SFc4_flightControlSystemInstanceStruct
  *chartInstance, c4_coder_array_int32_T *c4_coderArray)
{
  (void)chartInstance;
  if (c4_coderArray->vector.owner && (c4_coderArray->vector.data != (int32_T *)
       NULL)) {
    emlrtFreeMex(c4_coderArray->vector.data);
  }
}

static int32_T c4_div_s32_ndbzs(SFc4_flightControlSystemInstanceStruct
  *chartInstance, int32_T c4_numerator, int32_T c4_denominator, int32_T
  c4_EMLOvCount_src_loc, uint32_T c4_ssid_src_loc, int32_T c4_offset_src_loc,
  int32_T c4_length_src_loc)
{
  int32_T c4_quotient;
  uint32_T c4_absDenominator;
  uint32_T c4_absNumerator;
  uint32_T c4_tempAbsQuotient;
  boolean_T c4_quotientNeedsNegation;
  (void)chartInstance;
  (void)c4_EMLOvCount_src_loc;
  (void)c4_ssid_src_loc;
  (void)c4_offset_src_loc;
  (void)c4_length_src_loc;
  if (c4_denominator == 0) {
    if (c4_numerator >= 0) {
      c4_quotient = MAX_int32_T;
    } else {
      c4_quotient = MIN_int32_T;
    }
  } else {
    if (c4_numerator < 0) {
      c4_absNumerator = ~(uint32_T)c4_numerator + 1U;
    } else {
      c4_absNumerator = (uint32_T)c4_numerator;
    }

    if (c4_denominator < 0) {
      c4_absDenominator = ~(uint32_T)c4_denominator + 1U;
    } else {
      c4_absDenominator = (uint32_T)c4_denominator;
    }

    c4_quotientNeedsNegation = ((c4_numerator < 0) != (c4_denominator < 0));
    c4_tempAbsQuotient = c4_absNumerator / c4_absDenominator;
    if (c4_quotientNeedsNegation) {
      c4_quotient = -(int32_T)c4_tempAbsQuotient;
    } else {
      c4_quotient = (int32_T)c4_tempAbsQuotient;
    }
  }

  return c4_quotient;
}

static void init_dsm_address_info(SFc4_flightControlSystemInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_flightControlSystemInstanceStruct
  *chartInstance)
{
  chartInstance->c4_covrtInstance = (CovrtStateflowInstance *)
    sfrtGetCovrtInstance(chartInstance->S);
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_path = (uint8_T (*)[19200])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_forward = (real32_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_right = (real32_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* SFunction Glue Code */
void sf_c4_flightControlSystem_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(137924332U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1882224083U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4123860616U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(95490263U);
}

mxArray *sf_c4_flightControlSystem_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,3);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.IppreconstructBuildable"));
  mxSetCell(mxcell3p, 1, mxCreateString("coder.internal.lapack.LAPACKApi"));
  mxSetCell(mxcell3p, 2, mxCreateString("coder.internal.blas.BLASApi"));
  return(mxcell3p);
}

mxArray *sf_c4_flightControlSystem_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("ippreconstruct_uint8");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c4_flightControlSystem_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c4_flightControlSystem(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  mxArray *mxVarInfo = sf_mex_decode(
    "eNpjYPT0ZQACPiB+wcjAwAakOYCYiQECWKF8RqgYI1ycBS6uAMQllQWpIPHiomTPFCCdl5gL5ie"
    "WVnjmpeWDzbdgQJjPhsV8RiTzOaHiEPDBnjL9Ig7o+lmw6GdH0i8A5aflF5UnFqWA3Q8Lp4Hzhw"
    "RR/mBF8weIX5SZnlECdT8IAAC7xRU/"
    );
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_flightControlSystem_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization(void)
{
  return "sVbxXRxvSaIgcZLeUo7JJ8";
}

static void sf_opaque_initialize_c4_flightControlSystem(void *chartInstanceVar)
{
  initialize_params_c4_flightControlSystem
    ((SFc4_flightControlSystemInstanceStruct*) chartInstanceVar);
  initialize_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_flightControlSystem(void *chartInstanceVar)
{
  enable_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c4_flightControlSystem(void *chartInstanceVar)
{
  disable_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c4_flightControlSystem(void *chartInstanceVar)
{
  sf_gateway_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_flightControlSystem(SimStruct*
  S)
{
  return get_sim_state_c4_flightControlSystem
    ((SFc4_flightControlSystemInstanceStruct *)sf_get_chart_instance_ptr(S));/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_flightControlSystem(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_cleanup_runtime_resources_c4_flightControlSystem(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_flightControlSystemInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_flightControlSystem_optimization_info();
    }

    mdl_cleanup_runtime_resources_c4_flightControlSystem
      ((SFc4_flightControlSystemInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_mdl_start_c4_flightControlSystem(void *chartInstanceVar)
{
  mdl_start_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
  if (chartInstanceVar) {
    sf_reset_warnings_ChartRunTimeInfo(((SFc4_flightControlSystemInstanceStruct*)
      chartInstanceVar)->S);
  }
}

static void sf_opaque_mdl_terminate_c4_flightControlSystem(void
  *chartInstanceVar)
{
  mdl_terminate_c4_flightControlSystem((SFc4_flightControlSystemInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_flightControlSystem(SimStruct *S)
{
  mdlProcessParamsCommon(S);
  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_flightControlSystem
      ((SFc4_flightControlSystemInstanceStruct*)sf_get_chart_instance_ptr(S));
  }
}

const char* sf_c4_flightControlSystem_get_post_codegen_info(void)
{
  int i;
  const char* encStrCodegen [21] = {
    "eNrdWN1u3EQUnl2lgaJSFQlBLpDoJRcgSguiF4g23R+6VUJW9Sag3pRZ+9geZTzjzs/+8Aq8AC/",
    "CHW/ALRcI8QBccgeXnPE6m8VZEo8XlIAlxzn2fnPO+Xz+xqQ12Cd43MTz9g4h23h9Gc82WRzXSr",
    "m1ci7ub5FPSnn4CiFhSpUZiFgS/yOUESQgAhvHbOaJFTYbUkUz3UCvoBk8BS25NUwKP+OZiEGBC",
    "HGBXCrjpVezzHImjvtWhE6z/iJlYRqk0vLoES5IowPB53+nN7dmiBq7TEFo+gCRSZW0SdrnNDmf",
    "BWWmnRTCY20zb640mMDmzlW9b7lhOYfeDMKB0IYiC/oCfwNDDXTMzDtCmA5O0DLLOaOiPtcp1QH",
    "kGB0GDvMI/x5Yg+zV1Iv6xkxQIxWjvJfxjovwmtghRzv3May5N88mM10Y2yRhInHsKpuBQP8xTm",
    "pwFXfkBBRN4EB45qDzrjcrXvAyLuvn4MCFZaMctNnirehG2EJvb4IM6YZ6+6HoUM61H3Yk8z2YA",
    "C/0d6mhDbAL/R5grVk0kkdUuSzwzCQr2AsLJbYjRcTqv+FJBVUU3M+xeNaAs8yFFERI89L05UIX",
    "xaTVRmYdTKPu3l5NfWexA2FAxTSE2rVPUaYBDS7iylNvxDQdc4dGlkzhZe0VQDSGEh1b0Z1KdYw",
    "c+xbZU65cJvihIUqgCwaKgtHD6D6i3Na0OdNY4Vx4HGqsWH56EevypxE4pGEKkesnjMM+aLeArl",
    "2fsY/sorcTZuZd0KFied1MshoibCSOpdE8h0NxLORU9JXMgnIiOCeuALBqUCWwLTzCtqTmfTS+n",
    "tUKXoxcZDUZzzJqOB272PgMBHYW56vrhDTErOoJHN3QoE2wAfsaW7vQTBscp+a9IgeiYh7dafnN",
    "o6+V8r1lLg30SOGbotiGBU5Ku+Ni2IMRy6C4EVCcKRZieTi9d8ip3uvt8/W28b9WQxzZEPd4Bbe",
    "1hp83VnC3Sjn88HnMWZK6ImyU5MEcec/O2nGjBt/r7K/iyBncKc8n13dW8K01esnKdZP383AF92",
    "pFz1YFt11y9vj37x50f37/+6++ef7DLz9uvbuJ/m/bfvF8s5TfOpnPlh1scqbIN40HfTSeffl0N",
    "gnoIAmf7cGh/PjJk/uL9X69IP/aFXtP7t/G02CBK+qlCgdRuddyMrWLPYBb//6KvdsX8HF9JZ4I",
    "+e3BZvjXH1bx6/h6qcKXk2OpplRFf4nfy/Njp5Yf1yp+OFm5GlDJw6te9y6rzl6mnXXqcKshrk3",
    "+vbr/T+I29c+3v/zXf3/nnHpAKr+/dYX9IOfUJ58546r59RPxmwPeLuVPl98AOinj0ZpdSPkYNw",
    "rxuqf/k/j+w5O/N0u55/grP2I+u7crKJ/jtmOxrStvD5X7frZ8pIDq9Xu7y+hDZM0cu67f36jkt",
    "5OnTERyqt/74O5Hdzfpa38CZQgJCg==",
    ""
  };

  static char newstr [1457] = "";
  newstr[0] = '\0';
  for (i = 0; i < 21; i++) {
    strcat(newstr, encStrCodegen[i]);
  }

  return newstr;
}

static void mdlSetWorkWidths_c4_flightControlSystem(SimStruct *S)
{
  const char* newstr = sf_c4_flightControlSystem_get_post_codegen_info();
  sf_set_work_widths(S, newstr);
  ssSetChecksum0(S,(1068889928U));
  ssSetChecksum1(S,(3157252676U));
  ssSetChecksum2(S,(3412036448U));
  ssSetChecksum3(S,(738514140U));
}

static void mdlRTW_c4_flightControlSystem(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlSetupRuntimeResources_c4_flightControlSystem(SimStruct *S)
{
  SFc4_flightControlSystemInstanceStruct *chartInstance;
  chartInstance = (SFc4_flightControlSystemInstanceStruct *)utMalloc(sizeof
    (SFc4_flightControlSystemInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_flightControlSystemInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c4_flightControlSystem;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_flightControlSystem;
  chartInstance->chartInfo.mdlStart = sf_opaque_mdl_start_c4_flightControlSystem;
  chartInstance->chartInfo.mdlTerminate =
    sf_opaque_mdl_terminate_c4_flightControlSystem;
  chartInstance->chartInfo.mdlCleanupRuntimeResources =
    sf_opaque_cleanup_runtime_resources_c4_flightControlSystem;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_flightControlSystem;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c4_flightControlSystem;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_flightControlSystem;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_flightControlSystem;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_flightControlSystem;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_flightControlSystem;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c4_flightControlSystem;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->S = S;
  chartInstance->chartInfo.dispatchToExportedFcn = NULL;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  mdl_setup_runtime_resources_c4_flightControlSystem(chartInstance);
}

void c4_flightControlSystem_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_SETUP_RUNTIME_RESOURCES:
    mdlSetupRuntimeResources_c4_flightControlSystem(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_flightControlSystem(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_flightControlSystem(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_flightControlSystem_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
