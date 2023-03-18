/*
Based on IAPW IF97
Code by Yakai Bai
footballses@163.com
2023
*/
#include"IF97Export.h"

namespace IF97{
    ////Ranges
    IF97INT Dis_pT(long double p,long double T);

    ////Saturation
    IF97DOUBLE p_satT(double T);
    IF97DOUBLE T_satp(double p);

    IF97DOUBLE IsSat(double p,double T);

    //Enthalpy
    IF97DOUBLE h_satp_s(double p);
    IF97DOUBLE h_satp_l(double p);

    IF97DOUBLE h_satT_s(double T);
    IF97DOUBLE h_satT_l(double T);

    //Entropy
    IF97DOUBLE s_satp_s(double p);
    IF97DOUBLE s_satp_l(double p);
    IF97DOUBLE s_satT_s(double T);
    IF97DOUBLE s_satT_l(double T);

    //Internal Energy
    IF97DOUBLE u_satp_s(double p);
    IF97DOUBLE u_satp_l(double p);

    IF97DOUBLE u_satT_s(double T);
    IF97DOUBLE u_satT_l(double T);

    //Specific volume
    IF97DOUBLE v_satp_s(double p);
    IF97DOUBLE v_satp_l(double p);
    IF97DOUBLE v_satT_s(double T);
    IF97DOUBLE v_satT_l(double T);

    //ISO pressure thermal capacity
    IF97DOUBLE cp_satp_s(double p);
    IF97DOUBLE cp_satp_l(double p);

    IF97DOUBLE cp_satT_s(double T);
    IF97DOUBLE cp_satT_l(double T);

    //ISO volume thermal capacity
    IF97DOUBLE cv_satp_s(double p);
    IF97DOUBLE cv_satp_l(double p);
    IF97DOUBLE cv_satT_s(double T);
    IF97DOUBLE cv_satT_l(double T);

    //Speed of sound
    IF97DOUBLE w_satp_s(double p);
    IF97DOUBLE w_satp_l(double p);
    IF97DOUBLE w_satT_s(double T);
    IF97DOUBLE w_satT_l(double T);
///////////////////////////////////////////////
    ////p,T-->h,s,v,u,cp,cv,w,Gamr
    IF97DOUBLE h_pT(double p,double T);
    IF97DOUBLE s_pT(double p,double T);
    IF97DOUBLE v_pT(double p,double T);
    IF97DOUBLE u_pT(double p,double T);
    IF97DOUBLE cp_pT(double p,double T);
    IF97DOUBLE cv_pT(double p,double T);
    IF97DOUBLE w_pT(double p,double T);

    ////v,T-->h,s,p,u,cp,cv,w,Gamr
    IF97DOUBLE p_vT(double v,double T);
    IF97DOUBLE h_vT(double v,double T);
    IF97DOUBLE s_vT(double v,double T);
    IF97DOUBLE u_vT(double v,double T);
    IF97DOUBLE cp_vT(double v,double T);
    IF97DOUBLE cv_vT(double v,double T);
    IF97DOUBLE w_vT(double v,double T);
    IF97DOUBLE x_vT(double v,double T);

    /////From h,T to all
    IF97VOID p_hT(double h,double T,double &p0,double &p00);
    IF97VOID v_hT(double h,double T,double &v0,double &v00);
    IF97VOID s_hT(double h,double T,double &s0,double &s00);
    IF97VOID u_hT(double h,double T,double &u0,double &u00);
    IF97VOID cp_hT(double h,double T,double &cp0,double &cp00);
    IF97VOID cv_hT(double h,double T,double &cv0,double &cv00);
    IF97VOID w_hT(double h,double T,double &w0,double &w00);
    IF97VOID x_hT(double h,double T,double &x0,double &x00);

    ////From s,T
    IF97DOUBLE p_sT(double s,double T);
    IF97DOUBLE h_sT(double s,double T);
    IF97DOUBLE v_sT(double s,double T);
    IF97DOUBLE u_sT(double s,double T);
    IF97DOUBLE cp_sT(double s,double T);
    IF97DOUBLE cv_sT(double s,double T);
    IF97DOUBLE w_sT(double s,double T);
    IF97DOUBLE x_sT(double s,double T);

    ////From x,T
    IF97DOUBLE p_xT(double x,double T);
    IF97DOUBLE v_xT(double x,double T);
    IF97DOUBLE h_xT(double x,double T);
    IF97DOUBLE s_xT(double x,double T);
    IF97DOUBLE u_xT(double x,double T);
    IF97DOUBLE cp_xT(double x,double T);
    IF97DOUBLE cv_xT(double x,double T);
    IF97DOUBLE w_xT(double x,double T);

    ////From p,v
    IF97DOUBLE T_pv(double p,double v);
    IF97DOUBLE h_pv(double p,double v);
    IF97DOUBLE s_pv(double p,double v);
    IF97DOUBLE u_pv(double p,double v);
    IF97DOUBLE cp_pv(double p,double v);
    IF97DOUBLE cv_pv(double p,double v);
    IF97DOUBLE w_pv(double p,double v);
    IF97DOUBLE x_pv(double p,double v);

    ////From p,h
    IF97DOUBLE T_ph(double p,double h);
    IF97DOUBLE v_ph(double p,double h);
    IF97DOUBLE s_ph(double p,double h);
    IF97DOUBLE u_ph(double p,double h);
    IF97DOUBLE cp_ph(double p,double h);
    IF97DOUBLE cv_ph(double p,double h);
    IF97DOUBLE w_ph(double p,double h);
    IF97DOUBLE x_ph(double p,double h);

    ////From p,s
    IF97DOUBLE T_ps(double p,double s);
    IF97DOUBLE v_ps(double p,double s);
    IF97DOUBLE h_ps(double p,double s);
    IF97DOUBLE u_ps(double p,double s);
    IF97DOUBLE cp_ps(double p,double s);
    IF97DOUBLE cv_ps(double p,double s);
    IF97DOUBLE w_ps(double p,double s);
    IF97DOUBLE x_ps(double p,double s);

    ////From p,x
    IF97DOUBLE T_px(double p,double x);
    IF97DOUBLE v_px(double p,double x);
    IF97DOUBLE h_px(double p,double x);
    IF97DOUBLE s_px(double p,double x);
    IF97DOUBLE u_px(double p,double x);
    IF97DOUBLE cp_px(double p,double x);
    IF97DOUBLE cv_px(double p,double x);
    IF97DOUBLE w_px(double p,double x);

    /////////////////
    ////Saturation
    IF97DOUBLE h_sats_l(double s);
    IF97DOUBLE h_sats_s(double s);
    IF97DOUBLE h_sats(double s);

    ////From h,s
    IF97DOUBLE T_hs(double h,double s);
    IF97DOUBLE p_hs(double h,double s);
    IF97DOUBLE v_hs(double h,double s);
    IF97DOUBLE u_hs(double h,double s);
    IF97DOUBLE cp_hs(double h,double s);
    IF97DOUBLE cv_hs(double h,double s);
    IF97DOUBLE w_hs(double h,double s);
    IF97DOUBLE x_hs(double h,double s);

    ////From h,v
    IF97DOUBLE p_hv(double h,double v);
    IF97DOUBLE T_hv(double h,double v);
    IF97DOUBLE s_hv(double h,double v);
    IF97DOUBLE u_hv(double h,double v);
    IF97DOUBLE cp_hv(double h,double v);
    IF97DOUBLE cv_hv(double h,double v);
    IF97DOUBLE w_hv(double h,double v);
    IF97DOUBLE x_hv(double h,double v);

    ////From h,x
    IF97VOID p_hx(double h,double x,double &px,double &py);
    IF97VOID T_hx(double h,double x,double &Tx,double &Ty);
    IF97VOID v_hx(double h,double x,double &vx,double &vy);
    IF97VOID s_hx(double h,double x,double &sx,double &sy);
    IF97VOID u_hx(double h,double x,double &ux,double &uy);
    IF97VOID cp_hx(double h,double x,double &cpx,double &cpy);
    IF97VOID cv_hx(double h,double x,double &cvx,double &cvy);
    IF97VOID w_hx(double h,double x,double &wx,double &wy);

    ////From v,s
    IF97DOUBLE h_satv_s(double v);
    IF97DOUBLE h_satv(double v);
    IF97DOUBLE s_satv_s(double v);
    IF97DOUBLE s_satv(double v);

    IF97DOUBLE T_vs(double v,double s);
    IF97DOUBLE p_vs(double v,double s);
    IF97DOUBLE h_vs(double v,double s);
    IF97DOUBLE u_vs(double v,double s);
    IF97DOUBLE cp_vs(double v,double s);
    IF97DOUBLE cv_vs(double v,double s);
    IF97DOUBLE w_vs(double v,double s);
    IF97DOUBLE x_vs(double v,double s);

    ////From v,x to all
    IF97VOID T_vx(double v,double x,double &Trea,double &Tred);
    IF97VOID p_vx(double v,double x,double &p1,double &p2);
    IF97VOID h_vx(double v,double x,double &h1,double &h2);
    IF97VOID s_vx(double v,double x,double &s1,double &s2);
    IF97VOID u_vx(double v,double x,double &u1,double &u2);
    IF97VOID cp_vx(double v,double x,double &cp1,double &cp2);
    IF97VOID cv_vx(double v,double x,double &cv1,double &cv2);
    IF97VOID w_vx(double v,double x,double &w1,double &w2);

    ////From x,s
    IF97VOID T_sx(double s,double x,double &Tsx,double &Txs,double &Tll);
    IF97VOID p_sx(double s,double x,double &p1,double &p2,double &p3);
    IF97VOID v_sx(double s,double x,double &v1,double &v2,double &v3);
    IF97VOID h_sx(double s,double x,double &h1,double &h2,double &h3);
    IF97VOID u_sx(double s,double x,double &u1,double &u2,double &u3);
    IF97VOID cp_sx(double s,double x,double &cp1,double &cp2,double &cp3);
    IF97VOID cv_sx(double s,double x,double &cv1,double &cv2,double &cv3);
    IF97VOID w_sx(double s,double x,double &w1,double &w2,double &w3);
    
    ////Other properties
    IF97DOUBLE Atr_rhoT(double rho,double T);

    IF97DOUBLE lmd_satT_l(double T);
    IF97DOUBLE lmd_satT_s(double T);

    IF97DOUBLE Lmd_rhoT(double rho,double T);
    IF97DOUBLE Sgm_T(double T);
    IF97DOUBLE Ecs_rhoT(double rho,double T);
    IF97DOUBLE n_rhoTL(double rho,double T,double Lamd);
}