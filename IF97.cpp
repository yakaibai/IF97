/*
Based on IAPW IF97
Code by Yakai Bai
footballses@163.com
2023
*/
#include"IF97Base.h"
#include"IF97.h"
namespace IF97{
    int Dis_pT(long double p,long double T)
    {
        if((T>=273.15)&&(T<=623.15)&&(p>=p_4T(T))&&(p<=100))
            return 1;
        else 
            if(
                ((T>=273.15)&&(T<=623.15)&&(p>=0)&&(p<=p_4T(T)))||
                ((T>=623.15)&&(T<=863.15)&&(p>=0)&&(p<=p_23T(T)))||
                ((T>=863.15)&&(T<=1073.15)&&(p>=0)&&(p<=100))
                )
                return 2;
            else
                if((T>=623.15)&&(T<=T_23p(p))&&(p>=p_23T(T))&&(p<=100))
                    return 3;
                else
                    if((T>=1073.15)&&(T<=2273.15)&&(p>=0)&&(p<=50))
                        return 5;
                    else
                        return -1;
    }
    ////饱和气体的设置计算
    double p_satT(double T)
    {
        if((T>=273.15)&&(T<=647.096))
            return p_4T(T);
        else 
            return -1;
    }
    double T_satp(double p)
    {
        if((p>=611.213e-6)&&(p<=22.064))
            return T_4p(p);
        else
            return -1;
    }
    double IsSat(double p,double T)
    {
        if(abs(p-p_satT(T))<eps)
            return 1;
        else 
            return -1;
    }
    ///焓值
    double h_satp_s(double p)
    {
        double T=T_4p(p);
        double h;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                h=h_2pT(p,T);
            else
                h=h_3rhoT(rho_3p_sat(p),T);
        }
        else
            return -1;
        return h;
    }
    double h_satp_l(double p)
    {
        double T=T_4p(p);
        double h;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                h=h_1pT(p,T);
            else
                h=h_3rhoT(rho_3pT(p,T),T);
        }
        else
            return -1;
        return h;
    }
    double h_satT_s(double T)
    {
        double p=p_4T(T);
        double h;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                h=h_2pT(p,T);
            else
                h=h_3rhoT(rho_3p_sat(p),T);
        }
        else
            return -1;
        return h;
    }
    double h_satT_l(double T)
    {
        double p=p_4T(T);
        double h;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                h=h_1pT(p,T);
            else
                h=h_3rhoT(rho_3pT(p,T),T);
        }
        else
            return -1;
        return h;
    }

    /////熵值
    double s_satp_s(double p)
    {
        double T=T_4p(p);
        double s;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                s=s_2pT(p,T);
            else
                s=s_3rhoT(rho_3p_sat(p),T);
        }
        else
            return -1;
        return s;
    }
    double s_satp_l(double p)
    {
        double T=T_4p(p);
        double s;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                s=s_1pT(p,T);
            else
                s=s_3rhoT(rho_3pT(p,T),T);
        }
        else
            return -1;
        return s;
    }
    double s_satT_s(double T)
    {
        double p=p_4T(T);
        double s;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                s=s_2pT(p,T);
            else
                s=s_3rhoT(rho_3p_sat(p),T);
        }
        else
            return -1;
        return s;
    }
    double s_satT_l(double T)
    {
        double p=p_4T(T);
        double s;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                s=s_1pT(p,T);
            else
                s=s_3rhoT(rho_3pT(p,T),T);
        }
        else
            return -1;
        return s;
    }
    /////内能值
    double u_satp_s(double p)
    {
        double T=T_4p(p);
        double u;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                u=u_2pT(p,T);
            else
                u=u_3rhoT(rho_3p_sat(p),T);
        }
        else
            return -1;
        return u;
    }
    double u_satp_l(double p)
    {
        double T=T_4p(p);
        double u;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                u=u_1pT(p,T);
            else
                u=u_3rhoT(rho_3pT(p,T),T);
        }
        else
            return -1;
        return u;
    }
    double u_satT_s(double T)
    {
        double p=p_4T(T);
        double u;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                u=u_2pT(p,T);
            else
                u=u_3rhoT(rho_3p_sat(p),T);
        }
        else
            return -1;
        return u;
    }
    double u_satT_l(double T)
    {
        double p=p_4T(T);
        double u;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                u=u_1pT(p,T);
            else
                u=u_3rhoT(rho_3pT(p,T),T);
        }
        else
            return -1;
        return u;
    }
    /////比容值
    double v_satp_s(double p)
    {
        double T=T_4p(p);
        double v;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                v=v_2pT(p,T);
            else
                v=1/rho_3p_sat(p);
        }
        else
            return -1;
        return v;
    }
    double v_satp_l(double p)
    {
        double T=T_4p(p);
        double v;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                v=v_1pT(p,T);
            else
                v=1/rho_3pT(p,T);
        }
        else
            return -1;
        return v;
    }
    double v_satT_s(double T)
    {
        double p=p_4T(T);
        double v;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                v=v_2pT(p,T);
            else
                v=1/rho_3p_sat(p);
        }
        else
            return -1;
        return v;
    }
    double v_satT_l(double T)
    {
        double p=p_4T(T);
        double v;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                v=v_1pT(p,T);
            else
                v=1/rho_3pT(p,T);
        }
        else
            return -1;
        return v;
    }

    /////等压比热容值
    double cp_satp_s(double p)
    {
        double T=T_4p(p);
        double cp;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                cp=cp_2pT(p,T);
            else
                cp=cp_3rhoT(rho_3p_sat(p),T);
        }
        else
            return -1;
        return cp;
    }
    double cp_satp_l(double p)
    {
        double T=T_4p(p);
        double cp;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                cp=cp_1pT(p,T);
            else
                cp=cp_3rhoT(rho_3pT(p,T),T);
        }
        else
            return -1;
        return cp;
    }
    double cp_satT_s(double T)
    {
        double p=p_4T(T);
        double cp;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                cp=cp_2pT(p,T);
            else
                cp=cp_3rhoT(rho_3p_sat(p),T);
        }
        else
            return -1;
        return cp;
    }
    double cp_satT_l(double T)
    {
        double p=p_4T(T);
        double cp;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                cp=cp_1pT(p,T);
            else
                cp=cp_3rhoT(rho_3pT(p,T),T);
        }
        else
            return -1;
        return cp;
    }
    /////等容比热容值
    double cv_satp_s(double p)
    {
        double T=T_4p(p);
        double cv;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                cv=cv_2pT(p,T);
            else
                cv=cv_3rhoT(rho_3p_sat(p),T);
        }
        else
            return -1;
        return cv;
    }
    double cv_satp_l(double p)
    {
        double T=T_4p(p);
        double cv;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                cv=cv_1pT(p,T);
            else
                cv=cv_3rhoT(rho_3pT(p,T),T);
        }
        else
            return -1;
        return cv;
    }
    double cv_satT_s(double T)
    {
        double p=p_4T(T);
        double cv;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                cv=cv_2pT(p,T);
            else
                cv=cv_3rhoT(rho_3p_sat(p),T);
        }
        else
            return -1;
        return cv;
    }
    double cv_satT_l(double T)
    {
        double p=p_4T(T);
        double cv;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                cv=cv_1pT(p,T);
            else
                cv=cv_3rhoT(rho_3pT(p,T),T);
        }
        else
            return -1;
        return cv;
    }
    /////声速值
    double w_satp_s(double p)
    {
        double T=T_4p(p);
        double w;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                w=w_2pT(p,T);
            else
                w=w_3rhoT(rho_3p_sat(p),T);
        }
        else
            return -1;
        return w;
    }
    double w_satp_l(double p)
    {
        double T=T_4p(p);
        double w;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                w=w_1pT(p,T);
            else
                w=w_3rhoT(rho_3pT(p,T),T);
        }
        else
            return -1;
        return w;
    }
    double w_satT_s(double T)
    {
        double p=p_4T(T);
        double w;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                w=w_2pT(p,T);
            else
                w=w_3rhoT(rho_3p_sat(p),T);
        }
        else
            return -1;
        return w;
    }
    double w_satT_l(double T)
    {
        double p=p_4T(T);
        double w;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
                w=w_1pT(p,T);
            else
                w=w_3rhoT(rho_3pT(p,T),T);
        }
        else
            return -1;
        return w;
    }
    //////////////////////////////////
    ////////////////////////////
    ///////////////////////////
    ////三区的总体ji算
    double T_3ph(double p,double h)
    {
        if((h<=h_3abp(p)&&p>=22.064)||(p<=22.064&&h<=h_satp_l(p)))
            return T_3aph(p,h);
        else
            return T_3bph(p,h);
    }
    double v_3ph(double p,double h)
    {
        if((h<=h_3abp(p)&&p>=22.064)||(p<=22.064&&h<=h_satp_l(p)))
            return v_3aph(p,h);
        else
            return v_3bph(p,h);
    }
    double T_3ps(double p,double s)
    {
        if((s<=4.41202148223476&&p>=22.064)||(p<=22.064&&s<=s_satp_l(p)))
            return T_3aps(p,s);
        else
            return T_3bps(p,s);
    }
    double v_3ps(double p,double s)
    {
        if((s<=4.41202148223476&&p>=22.064)||(p<=22.064&&s<=s_satp_l(p)))
            return v_3aps(p,s);
        else
            return v_3bps(p,s);
    }
    ////根据给定的p,T计算h,s,v,u,cp,cv,w,Gamr
    double h_pT(double p,double T)
    {
        switch(Dis_pT(p,T))
        {
        case 1:
            return h_1pT(p,T);
        case 2:
            return h_2pT(p,T);
        case 3:
            return h_3pT(p,T);
        case 5:
            return h_5pT(p,T);
        default:
            return -1;
        }
    }
    double s_pT(double p,double T)
    {
        switch(Dis_pT(p,T))
        {
        case 1:
            return s_1pT(p,T);
        case 2:
            return s_2pT(p,T);
        case 3:
            return s_3pT(p,T);
        case 5:
            return s_5pT(p,T);
        default:
            return -1;
        }
    }
    double v_pT(double p,double T)
    {
        switch(Dis_pT(p,T))
        {
        case 1:
            return v_1pT(p,T);
        case 2:
            return v_2pT(p,T);
        case 3:
            return v_3pT(p,T);
        case 5:
            return v_5pT(p,T);
        default:
            return -1;
        }
    }
    double u_pT(double p,double T)
    {
        switch(Dis_pT(p,T))
        {
        case 1:
            return u_1pT(p,T);
        case 2:
            return u_2pT(p,T);
        case 3:
            return u_3pT(p,T);
        case 5:
            return u_5pT(p,T);
        default:
            return -1;
        }
    }
    double cp_pT(double p,double T)
    {
        switch(Dis_pT(p,T))
        {
        case 1:
            return cp_1pT(p,T);
        case 2:
            return cp_2pT(p,T);
        case 3:
            return cp_3pT(p,T);
        case 5:
            return cp_5pT(p,T);
        default:
            return -1;
        }
    }
    double cv_pT(double p,double T)
    {
        switch(Dis_pT(p,T))
        {
        case 1:
            return cv_1pT(p,T);
        case 2:
            return cv_2pT(p,T);
        case 3:
            return cv_3pT(p,T);
        case 5:
            return cv_5pT(p,T);
        default:
            return -1;
        }
    }
    double w_pT(double p,double T)
    {
        switch(Dis_pT(p,T))
        {
        case 1:
            return w_1pT(p,T);
        case 2:
            return w_2pT(p,T);
        case 3:
            return w_3pT(p,T);
        case 5:
            return w_5pT(p,T);
        default:
            return -1;
        }
    }


    ////根据给定的v,T计算h,s,p,u,cp,cv,w,Gamr
    ////目标函数FvT
    double FvTp(double p,double T,double v)
    {
        return v_pT(p,T)-v;
    }
    ///压力值
    double p_vT(double v,double T)
    {

        if(T<273.15||v<v_pT(100,T)||(T>1073.15&&v<v_pT(50,T))||T>2273.15)
            return -1;
        if(T<=647.096&&T>=273.15)
        {
            double vs=v_satT_s(T),vl=v_satT_l(T);
            if(v>=vl&&v<=vs)
                return p_satT(T);
        }		
        if(T>=623.15&&v<=v_2pT(p_23T(T),T))
            {
                double p3=p_3rhoT(1/v,T);
                return p3;
            }
        double step=0.1;
        double bs=2;
        double p1=0.0001,p2=p1+step;
        double pm;
        int i=0;
        double	F1=FvTp(p1,T,v);
        double	F2=FvTp(p2,T,v);
        double Fm;
        while(F1*F2>0)
        {		
            p1=p2;
            step=step*bs;
            p2+=step;
            F1=FvTp(p1,T,v);
            F2=FvTp(p2,T,v);
        }
        while(abs((p2-p1)/p2)>=err)
        {
            pm=(p1+p2)/2;
            Fm=FvTp(pm,T,v);
            if(F1*Fm<=0)
                p2=pm;
            else
                p1=pm;
            F1=FvTp(p1,T,v);
            F2=FvTp(p2,T,v);
        }
        return p2;
    }
    ////焓值
    double h_vT(double v,double T)
    {
        if(T<273.15||v<v_pT(100,T)||(T>1073.15&&v<v_pT(50,T))||T>2273.15)
            return -1;
        if(T<=647.096&&T>=273.15)
        {
            double vs=v_satT_s(T),vl=v_satT_l(T);
            if(v>=vl&&v<=vs)
            {
                double x=(v-vl)/(vs-vl);
                double hs=h_satT_s(T),hl=h_satT_l(T);
                double h=(hs-hl)*x+hl;
                return h;
            }
        }
        if(T>=623.15&&v<=v_2pT(p_23T(T),T))
            {
                double h3=h_3rhoT(1/v,T);
                return h3;
            }
        return h_pT(p_vT(v,T),T);
    }
    ///熵值
    double s_vT(double v,double T)
    {
        if(T<273.15||v<v_pT(100,T)||(T>1073.15&&v<v_pT(50,T))||T>2273.15)
            return -1;
        if(T<=647.096&&T>=273.15)
        {
            double vs=v_satT_s(T),vl=v_satT_l(T);
            if(v>=vl&&v<=vs)
            {
                double x=(v-vl)/(vs-vl);
                double ss=s_satT_s(T),sl=s_satT_l(T);
                double s=(ss-sl)*x+sl;
                return s;
            }
        }
        if(T>=623.15&&v<=v_2pT(p_23T(T),T))
            {
                double s3=s_3rhoT(1/v,T);
                return s3;
            }
        return s_pT(p_vT(v,T),T);
    }
    ////比内能
    double u_vT(double v,double T)
    {
        if(T<273.15||v<v_pT(100,T)||(T>1073.15&&v<v_pT(50,T))||T>2273.15)
            return -1;
        if(T<=647.096&&T>=273.15)
        {
            double vs=v_satT_s(T),vl=v_satT_l(T);
            if(v>=vl&&v<=vs)
            {
                double x=(v-vl)/(vs-vl);
                double us=u_satT_s(T),ul=u_satT_l(T);
                double u=(us-ul)*x+ul;
                return u;
            }
        }
        if(T>=623.15&&v<=v_2pT(p_23T(T),T))
            {
                double u3=u_3rhoT(1/v,T);
                return u3;
            }
        return u_pT(p_vT(v,T),T);
    }
    ////定压比热容
    double cp_vT(double v,double T)
    {
        if(T<273.15||v<v_pT(100,T)||(T>1073.15&&v<v_pT(50,T))||T>2273.15)
            return -1;
        if(T<=647.096&&T>=273.15)
        {
            double vs=v_satT_s(T),vl=v_satT_l(T);
            if(v>=vl&&v<=vs)
            {
                double x=(v-vl)/(vs-vl);
                double cps=cp_satT_s(T),cpl=cp_satT_l(T);
                double cp=(cps-cpl)*x+cpl;
                return cp;
            }
        }
        if(T>=623.15&&v<=v_2pT(p_23T(T),T))
            {
                double cp3=cp_3rhoT(1/v,T);
                return cp3;
            }
        return cp_pT(p_vT(v,T),T);
    }
    ////定容比热容
    double cv_vT(double v,double T)
    {
        if(T<273.15||v<v_pT(100,T)||(T>1073.15&&v<v_pT(50,T))||T>2273.15)
            return -1;
        if(T<=647.096&&T>=273.15)
        {
            double vs=v_satT_s(T),vl=v_satT_l(T);
            if(v>=vl&&v<=vs)
            {
                double x=(v-vl)/(vs-vl);
                double cvs=cv_satT_s(T),cvl=cv_satT_l(T);
                double cv=(cvs-cvl)*x+cvl;
                return cv;
            }
        }
        if(T>=623.15&&v<=v_2pT(p_23T(T),T))
            {
                double cv3=cv_3rhoT(1/v,T);
                return cv3;
            }
        return cv_pT(p_vT(v,T),T);
    }
    ////声速
    double w_vT(double v,double T)
    {
        if(T<273.15||v<v_pT(100,T)||(T>1073.15&&v<v_pT(50,T))||T>2273.15)
            return -1;
        if(T<=647.096&&T>=273.15)
        {
            double vs=v_satT_s(T),vl=v_satT_l(T);
            if(v>=vl&&v<=vs)
            {
                double x=(v-vl)/(vs-vl);
                double ws=w_satT_s(T),wl=w_satT_l(T);
                double w=(ws-wl)*x+wl;
                return w;
            }
        }
        if(T>=623.15&&v<=v_2pT(p_23T(T),T))
            {
                double w3=w_3rhoT(1/v,T);
                return w3;
            }
        return w_pT(p_vT(v,T),T);
    }
    ////干度
    double x_vT(double v,double T)
    {
        double x=-1;
        if(T<=647.096&&T>=273.15)
        {
            double vs=v_satT_s(T),vl=v_satT_l(T);
            if(v>=vl&&v<=vs)
                x=(v-vl)/(vs-vl);
        }
        return x;
    }
    ///////////////////////////////////////////////////////////
    /////////由h，T推出全部值
    ////////////////////////
    ////目标函数FhTp
    double FhTp(double p,double T,double h)
    {
        return h_pT(p,T)-h;
    }
    double F3rho(double rho,double T,double h)
    {
        return h_3rhoT(rho,T)-h;
    }
    double rho_3hT(double h,double T)
    {
        double step=0.1;
        double bs=2;
        double rho1=100,rho2=rho1+step;
        double rhom;
        double	F1=F3rho(rho1,T,h);
        double	F2=F3rho(rho2,T,h);
        double Fm;
        while(F1*F2>0)
        {		
            rho1=rho2;
            step=step*bs;
            rho2+=step;
            F1=F3rho(rho1,T,h);
            F2=F3rho(rho2,T,h);
        }
        while(abs((rho2-rho1)/rho2)>=err)
        {
            rhom=(rho1+rho2)/2;
            Fm=F3rho(rhom,T,h);
            if(F1*Fm<=0)
                rho2=rhom;
            else
                rho1=rhom;
            F1=F3rho(rho1,T,h);
            F2=F3rho(rho2,T,h);
        }
        return rho2;
    }
    ///压力值
    void p_hT(double h,double T,double &p0,double &p00)
    {
        p0=-1;
        double step;
        double bs;
        double p1,p2;
        double pm;
        int i;
        double	F1;
        double	F2;
        double Fm;
        double H1=h_pT(100,T);
        double H0=h_pT(611e-6,T);
        if(T<273.15||(h<H1&&T>647.096)||(T>1073.15&&h<h_pT(50,T))||T>2273.15||(h>H0))
        {
            p00=-1;
            return;
        }
        if(T<=647.096&&T>=273.15)
        {
            double hs=h_satT_s(T),hl=h_satT_l(T);
            double ps=p_satT(T);
            if(T<=613.15)
            {
                double Fb0=ps;
                double Fb1=100;
                double Fbb0=0.382*(Fb1-Fb0)+Fb0;
                double Fbb1=0.618*(Fb1-Fb0)+Fb0;
                double Hbb0=h_pT(Fbb0,T);
                double Hbb1=h_pT(Fbb1,T);
                while(abs((Fbb0-Fbb1)/Fbb1)>=err)
                {
            
                    if(Hbb0>Hbb1)
                    {
                        Fb0=Fbb0;
                        Fbb0=Fbb1;
                        Fbb1=0.618*(Fb1-Fb0)+Fb0;
                    }
                    else
                    {
                        Fb1=Fbb1;
                        Fbb1=Fbb0;
                        Fbb0=0.382*(Fb1-Fb0)+Fb0;
                    }
                    Hbb0=h_pT(Fbb0,T);
                    Hbb1=h_pT(Fbb1,T);
                }
                if(h<Hbb1)
                {
                    p00=-1;
                    return;
                }
                else 
                    if(h<=H1&&Fbb1<=100)
                    {	
                        step=0.01;
                        bs=1.5;
                        p1=Fbb1,p2=p1+step;
                        i=0;
                        F1=FhTp(p1,T,h);
                        F2=FhTp(p2,T,h);
                        while(F1*F2>0)
                        {			
                            p1=p2;
                            step=step*bs;
                            p2+=step;
                            F1=FhTp(p1,T,h);
                            F2=FhTp(p2,T,h);	
                        }		
                        while(abs((p2-p1)/p2)>=err)
                        {
                        pm=(p1+p2)/2;
                        Fm=FhTp(pm,T,h);
                        if(F1*Fm<=0)
                            p2=pm;
                        else
                            p1=pm;
                            F1=FhTp(p1,T,h);
                            F2=FhTp(p2,T,h);
                        }
                        p0=p2;
                    }
            }
            else
                if(h<H1)
                {
                    p00=-1;
                    return;
                }							
            if(h>=hl&&h<=hs)
            {
                p00=ps;
                return;
            }
        }

        if(T>=623.15&&h<=h_2pT(p_23T(T),T))
        {
            double p3=p_3rhoT(rho_3hT(h,T),T);
            p00=p3;
            return;
        }
                
        step=0.1;
        bs=2;
        p1=0.0001,p2=p1+step;	
        i=0;
        F1=FhTp(p1,T,h);
        F2=FhTp(p2,T,h);
        while(F1*F2>0)
        {		
            p1=p2;
            step=step*bs;
            p2+=step;
            F1=FhTp(p1,T,h);
            F2=FhTp(p2,T,h);
        }
        while(abs((p2-p1)/p2)>=err)
        {
            pm=(p1+p2)/2;
            Fm=FhTp(pm,T,h);
            if(F1*Fm<=0)
                p2=pm;
            else
                p1=pm;
            F1=FhTp(p1,T,h);
            F2=FhTp(p2,T,h);
        }
        p00=p2;
        return;
    }
    ///比容值
    void v_hT(double h,double T,double &v0,double &v00)
    {
        v0=-1;
        double p1,p2;
        double H1=h_pT(100,T);
        double H0=h_pT(611e-6,T);
        if(T<273.15||(h<H1&&T>647.096)||(T>1073.15&&h<h_pT(50,T))||T>2273.15||(h>H0))
        {
            v00=-1;
            return;
        }
        p_hT(h,T,p1,p2);
        if(p2==-1)
        {
            v00=-1;
            return;
        }
        if(T<=647.096&&T>=273.15)
        {
            if(T<=613.15)
            {
                if(p1!=-1)
                    v0=v_pT(p1,T);
            }
            double hs=h_satT_s(T),hl=h_satT_l(T);
            if(h>=hl&&h<=hs)
            {
                double vs=v_satT_s(T),vl=v_satT_l(T);
                double	x=(h-hl)/(hs-hl);
                v00=vl+(vs-vl)*x;
                return;
            }
        }
        if(T>=623.15&&h<=h_2pT(p_23T(T),T))
        {
            double v3=1/rho_3hT(h,T);
            v00=v3;
            return;
        }
        v00=v_pT(p2,T);
        return;
    }
    //熵值
    void s_hT(double h,double T,double &s0,double &s00)
    {
        s0=-1;
        double p1,p2;
        double H1=h_pT(100,T);
        double H0=h_pT(611e-6,T);
        if(T<273.15||(h<H1&&T>647.096)||(T>1073.15&&h<h_pT(50,T))||T>2273.15||(h>H0))
        {
            s00=-1;
            return;
        }
        p_hT(h,T,p1,p2);
        if(p2==-1)
        {
            s00=-1;
            return;
        }
        if(T<=647.096&&T>=273.15)
        {
            if(T<=613.15)
            {
                if(p1!=-1)
                    s0=s_pT(p1,T);
            }
            double hs=h_satT_s(T),hl=h_satT_l(T);
            if(h>=hl&&h<=hs)
            {
                double ss=s_satT_s(T),sl=s_satT_l(T);
                double	x=(h-hl)/(hs-hl);
                s00=sl+(ss-sl)*x;
                return;
            }
        }
        if(T>=623.15&&h<=h_2pT(p_23T(T),T))
        {
            double s3=s_3rhoT(rho_3hT(h,T),T);
            s00=s3;
            return;
        }
        s00=s_pT(p2,T);
        return;
    }
    ///比内能
    void u_hT(double h,double T,double &u0,double &u00)
    {
        u0=-1;
        double p1,p2;
        double H1=h_pT(100,T);
        double H0=h_pT(611e-6,T);
        if(T<273.15||(h<H1&&T>647.096)||(T>1073.15&&h<h_pT(50,T))||T>2273.15||(h>H0))
        {
            u00=-1;
            return;
        }
        p_hT(h,T,p1,p2);
        if(p2==-1)
        {
            u00=-1;
            return;
        }
        if(T<=647.096&&T>=273.15)
        {
            if(T<=613.15)
            {
                if(p1!=-1)
                    u0=u_pT(p1,T);
            }
            double hs=h_satT_s(T),hl=h_satT_l(T);
            if(h>=hl&&h<=hs)
            {
                double us=u_satT_s(T),ul=u_satT_l(T);
                double	x=(h-hl)/(hs-hl);
                u00=ul+(us-ul)*x;
                return;
            }
        }
        if(T>=623.15&&h<=h_2pT(p_23T(T),T))
        {
            double u3=u_3rhoT(rho_3hT(h,T),T);
            u00=u3;
            return;
        }
        u00=u_pT(p2,T);
        return;
    }
    ///定压比热容
    void cp_hT(double h,double T,double &cp0,double &cp00)
    {
        cp0=-1;
        double p1,p2;
        double H1=h_pT(100,T);
        double H0=h_pT(611e-6,T);
        if(T<273.15||(h<H1&&T>647.096)||(T>1073.15&&h<h_pT(50,T))||T>2273.15||(h>H0))
        {
            cp00=-1;
            return;
        }
        p_hT(h,T,p1,p2);
        if(p2==-1)
        {
            cp00=-1;
            return;
        }
        if(T<=647.096&&T>=273.15)
        {
            if(T<=613.15)
            {
                if(p1!=-1)
                    cp0=cp_pT(p1,T);
            }
            double hs=h_satT_s(T),hl=h_satT_l(T);
            if(h>=hl&&h<=hs)
            {
                double cps=cp_satT_s(T),cpl=cp_satT_l(T);
                double	x=(h-hl)/(hs-hl);
                cp00=cpl+(cps-cpl)*x;
                return;
            }
        }
        if(T>=623.15&&h<=h_2pT(p_23T(T),T))
        {
            double cp3=cp_3rhoT(rho_3hT(h,T),T);
            cp00=cp3;
            return;
        }
        cp00=cp_pT(p2,T);
        return;
    }
    ////定容比热容
    void cv_hT(double h,double T,double &cv0,double &cv00)
    {
        cv0=-1;
        double p1,p2;
        double H1=h_pT(100,T);
        double H0=h_pT(611e-6,T);
        if(T<273.15||(h<H1&&T>647.096)||(T>1073.15&&h<h_pT(50,T))||T>2273.15||(h>H0))
        {
            cv00=-1;
            return;
        }
        p_hT(h,T,p1,p2);
        if(p2==-1)
        {
            cv00=-1;
            return;
        }
        if(T<=647.096&&T>=273.15)
        {
            if(T<=613.15)
            {
                if(p1!=-1)
                    cv0=cv_pT(p1,T);
            }
            double hs=h_satT_s(T),hl=h_satT_l(T);
            if(h>=hl&&h<=hs)
            {
                double cvs=cv_satT_s(T),cvl=cv_satT_l(T);
                double	x=(h-hl)/(hs-hl);
                cv00=cvl+(cvs-cvl)*x;
                return;
            }
        }
        if(T>=623.15&&h<=h_2pT(p_23T(T),T))
        {
            double cv3=cv_3rhoT(rho_3hT(h,T),T);
            cv00=cv3;
            return;
        }
        cv00=cv_pT(p2,T);
        return;
    }
    ///声速
    void w_hT(double h,double T,double &w0,double &w00)
    {
        w0=-1;
        double p1,p2;
        double H1=h_pT(100,T);
        double H0=h_pT(611e-6,T);
        if(T<273.15||(h<H1&&T>647.096)||(T>1073.15&&h<h_pT(50,T))||T>2273.15||(h>H0))
        {
            w00=-1;
            return;
        }
        p_hT(h,T,p1,p2);
        if(p2==-1)
        {
            w00=-1;
            return;
        }
        if(T<=647.096&&T>=273.15)
        {
            if(T<=613.15)
            {
                if(p1!=-1)
                    w0=w_pT(p1,T);
            }
            double hs=h_satT_s(T),hl=h_satT_l(T);
            if(h>=hl&&h<=hs)
            {
                double ws=w_satT_s(T),wl=w_satT_l(T);
                double	x=(h-hl)/(hs-hl);
                w00=wl+(ws-wl)*x;
                return;
            }
        }
        if(T>=623.15&&h<=h_2pT(p_23T(T),T))
        {
            double w3=w_3rhoT(rho_3hT(h,T),T);
            w00=w3;
            return;
        }
        w00=w_pT(p2,T);
        return;
    }
    ////干度
    void x_hT(double h,double T,double &x0,double &x00)
    {
        x0=-1,x00=-1;
        if(T<=647.096&&T>=273.15)
        {
            double hs=h_satT_s(T),hl=h_satT_l(T);
            if(h>=hl&&h<=hs)
            {
                x00=(h-hl)/(hs-hl);
                return;
            }
        }
        return;
    }
    /////////////////////////////
    /////通过s,T值计算其他参数
    /////////////////////////////////
    ////目标函数FsTp
    double FsTp(double p,double T,double s)
    {
        return s_pT(p,T)-s;
    }
    double F3rhos(double rho,double T,double s)
    {
        return s_3rhoT(rho,T)-s;
    }
    double rho_3sT(double s,double T)
    {
        double step=0.1;
        double bs=2;
        double rho1=100,rho2=rho1+step;
        double rhom;
        double	F1=F3rhos(rho1,T,s);
        double	F2=F3rhos(rho2,T,s);
        double Fm;
        while(F1*F2>0)
        {		
            rho1=rho2;
            step=step*bs;
            rho2+=step;
            F1=F3rhos(rho1,T,s);
            F2=F3rhos(rho2,T,s);
        }
        while(abs((rho2-rho1)/rho2)>=err)
        {
            rhom=(rho1+rho2)/2;
            Fm=F3rhos(rhom,T,s);
            if(F1*Fm<=0)
                rho2=rhom;
            else
                rho1=rhom;
            F1=F3rhos(rho1,T,s);
            F2=F3rhos(rho2,T,s);
        }
        return rho2;
    }
    //压力值
    double p_sT(double s,double T)
    {

        if(T<273.15||s<s_pT(100,T)||(T>1073.15&&s<s_pT(50,T))||T>2273.15)
            return -1;
        if(T<=647.096&&T>=273.15)
        {
            double ss=s_satT_s(T),sl=s_satT_l(T);
            if(s>=sl&&s<=ss)
                return p_satT(T);
        }		
        if(T>=623.15&&s<=s_2pT(p_23T(T),T))
        {
            double p3=p_3rhoT(rho_3sT(s,T),T);
            return p3;
        }
        double step=0.1;
        double bs=2;
        double p1=0.0001,p2=p1+step;
        double pm;
        int i=0;
        double	F1=FsTp(p1,T,s);
        double	F2=FsTp(p2,T,s);
        double Fm;
        while(F1*F2>0)
        {		
            p1=p2;
            step=step*bs;
            p2+=step;
            F1=FsTp(p1,T,s);
            F2=FsTp(p2,T,s);
        }
        while(abs((p2-p1)/p2)>=err)
        {
            pm=(p1+p2)/2;
            Fm=FsTp(pm,T,s);
            if(F1*Fm<=0)
                p2=pm;
            else
                p1=pm;
            F1=FsTp(p1,T,s);
            F2=FsTp(p2,T,s);
        }
        return p2;
    }
    //焓值
    double h_sT(double s,double T)
    {

        if(T<273.15||s<s_pT(100,T)||(T>1073.15&&s<s_pT(50,T))||T>2273.15)
            return -1;
        if(T<=647.096&&T>=273.15)
        {
            double ss=s_satT_s(T),sl=s_satT_l(T);
            if(s>=sl&&s<=ss)
            {
                double hs=h_satT_s(T),hl=h_satT_l(T);
                double x=(s-sl)/(ss-sl);
                double h=hl+x*(hs-hl);
                return h;
            }
        }		
        if(T>=623.15&&s<=s_2pT(p_23T(T),T))
        {
            double h3=h_3rhoT(rho_3sT(s,T),T);
            return h3;
        }
        double h2=h_pT(p_sT(s,T),T);
        return h2;
    }
    //比容
    double v_sT(double s,double T)
    {

        if(T<273.15||s<s_pT(100,T)||(T>1073.15&&s<s_pT(50,T))||T>2273.15)
            return -1;
        if(T<=647.096&&T>=273.15)
        {
            double ss=s_satT_s(T),sl=s_satT_l(T);
            if(s>=sl&&s<=ss)
            {
                double vs=v_satT_s(T),vl=v_satT_l(T);
                double x=(s-sl)/(ss-sl);
                double v=vl+x*(vs-vl);
                return v;
            }
        }		
        if(T>=623.15&&s<=s_2pT(p_23T(T),T))
        {
            double v3=1/rho_3sT(s,T);
            return v3;
        }
        double v2=v_pT(p_sT(s,T),T);
        return v2;
    }
    //比内能值
    double u_sT(double s,double T)
    {

        if(T<273.15||s<s_pT(100,T)||(T>1073.15&&s<s_pT(50,T))||T>2273.15)
            return -1;
        if(T<=647.096&&T>=273.15)
        {
            double ss=s_satT_s(T),sl=s_satT_l(T);
            if(s>=sl&&s<=ss)
            {
                double us=u_satT_s(T),ul=u_satT_l(T);
                double x=(s-sl)/(ss-sl);
                double u=ul+x*(us-ul);
                return u;
            }
        }		
        if(T>=623.15&&s<=s_2pT(p_23T(T),T))
        {
            double u3=u_3rhoT(rho_3sT(s,T),T);
            return u3;
        }
        double u2=u_pT(p_sT(s,T),T);
        return u2;
    }
    //等压比热容值
    double cp_sT(double s,double T)
    {

        if(T<273.15||s<s_pT(100,T)||(T>1073.15&&s<s_pT(50,T))||T>2273.15)
            return -1;
        if(T<=647.096&&T>=273.15)
        {
            double ss=s_satT_s(T),sl=s_satT_l(T);
            if(s>=sl&&s<=ss)
            {
                double cps=cp_satT_s(T),cpl=cp_satT_l(T);
                double x=(s-sl)/(ss-sl);
                double cp=cpl+x*(cps-cpl);
                return cp;
            }
        }		
        if(T>=623.15&&s<=s_2pT(p_23T(T),T))
        {
            double cp3=cp_3rhoT(rho_3sT(s,T),T);
            return cp3;
        }
        double cp2=cp_pT(p_sT(s,T),T);
        return cp2;
    }
    //等容比热容值
    double cv_sT(double s,double T)
    {

        if(T<273.15||s<s_pT(100,T)||(T>1073.15&&s<s_pT(50,T))||T>2273.15)
            return -1;
        if(T<=647.096&&T>=273.15)
        {
            double ss=s_satT_s(T),sl=s_satT_l(T);
            if(s>=sl&&s<=ss)
            {
                double cvs=cv_satT_s(T),cvl=cp_satT_l(T);
                double x=(s-sl)/(ss-sl);
                double cv=cvl+x*(cvs-cvl);
                return cv;
            }
        }		
        if(T>=623.15&&s<=s_2pT(p_23T(T),T))
        {
            double cv3=cv_3rhoT(rho_3sT(s,T),T);
            return cv3;
        }
        double cv2=cv_pT(p_sT(s,T),T);
        return cv2;
    }
    //声速值
    double w_sT(double s,double T)
    {

        if(T<273.15||s<s_pT(100,T)||(T>1073.15&&s<s_pT(50,T))||T>2273.15)
            return -1;
        if(T<=647.096&&T>=273.15)
        {
            double ss=s_satT_s(T),sl=s_satT_l(T);
            if(s>=sl&&s<=ss)
            {
                double ws=w_satT_s(T),wl=w_satT_l(T);
                double x=(s-sl)/(ss-sl);
                double w=wl+x*(ws-wl);
                return w;
            }
        }		
        if(T>=623.15&&s<=s_2pT(p_23T(T),T))
        {
            double w3=w_3rhoT(rho_3sT(s,T),T);
            return w3;
        }
        double w2=w_pT(p_sT(s,T),T);
        return w2;
    }
    ////干度
    double x_sT(double s,double T)
    {
        double x=-1;
        if(T<=647.096&&T>=273.15)
        {
            double ss=s_satT_s(T),sl=s_satT_l(T);
            if(s>=sl&&s<=ss)
                x=(s-sl)/(ss-sl);
        }
        return x;
    }
    /////////////////////////////////////////
    /////////根据x,T计算其他值
    /////////////////////////////////////////
    double p_xT(double x,double T)
    {
        double p=-1;
        if(T<=647.096&&T>=273.15)
            p=p_satT(T);
        return p;
    }
    double v_xT(double x,double T)
    {
        double v=-1;
        if(T<=647.096&&T>=273.15)
        { 
            double vs=v_satT_s(T),vl=v_satT_l(T);
            v=vl+(vs-vl)*x;
        }
        return v;
    }
    double h_xT(double x,double T)
    {
        double h=-1;
        if(T<=647.096&&T>=273.15)
        { 
            double hs=h_satT_s(T),hl=h_satT_l(T);
            h=hl+(hs-hl)*x;
        }
        return h;
    }
    double s_xT(double x,double T)
    {
        double s=-1;
        if(T<=647.096&&T>=273.15)
        { 
            double ss=s_satT_s(T),sl=s_satT_l(T);
            s=sl+(ss-sl)*x;
        }
        return s;
    }
    double u_xT(double x,double T)
    {
        double u=-1;
        if(T<=647.096&&T>=273.15)
        { 
            double us=u_satT_s(T),ul=u_satT_l(T);
            u=ul+(us-ul)*x;
        }
        return u;
    }
    double cp_xT(double x,double T)
    {
        double cp=-1;
        if(T<=647.096&&T>=273.15)
        { 
            double cps=cp_satT_s(T),cpl=h_satT_l(T);
            cp=cpl+(cps-cpl)*x;
        }
        return cp;
    }
    double cv_xT(double x,double T)
    {
        double cv=-1;
        if(T<=647.096&&T>=273.15)
        { 
            double cvs=cv_satT_s(T),cvl=v_satT_l(T);
            cv=cvl+(cvs-cvl)*x;
        }
        return cv;
    }
    double w_xT(double x,double T)
    {
        double w=-1;
        if(T<=647.096&&T>=273.15)
        { 
            double ws=w_satT_s(T),wl=w_satT_l(T);
            w=wl+(ws-wl)*x;
        }
        return w;
    }
    ///////////////////////////////////////////
    /////////////////////////////////////////////
    ///以上为所有与T相关的计算，下面为与p相关的计算
    ////////////////////////////////////////////////
    ////////////////////////////////////////////////
    ///////////////根据p,v计算其他值
    double FpvT(double p,double T,double v)
    {
        return v_pT(p,T)-v;
    }
    double F3rhopT(double rho,double p,double T)
    {
        return p_3rhoT(rho,T)-p;
    }
    double T_3rhop(double rho,double p)
    {
        double step=0.1;
        double bs=1.3;
        double T1=623.15,T2=T1+step,Tm;	
        double F1=F3rhopT(rho,p,T1);
        double F2=F3rhopT(rho,p,T2);
        double Fm;
        while(F1*F2>0)
        {		
            T1=T2;
            step=step*bs;
            T2+=step;
            F1=F3rhopT(rho,p,T1);
            F2=F3rhopT(rho,p,T2);
        }
        while(abs((T2-T1)/T2)>=err)
        {
            Tm=(T1+T2)/2;
            Fm=F3rhopT(rho,p,Tm);
            if(F1*Fm<=0)
                T2=Tm;
            else
                T1=Tm;
            F1=F3rhopT(rho,p,T1);
            F2=F3rhopT(rho,p,T2);
        }
        return T2;
    }
        

    //温度值
    double T_pv(double p,double v)
    {
        
        if(p<611e-6||p>100||(v>v_pT(p,1073.15)&&p>50)||(v>v_pT(p,2273.15)&&p<=50&&p>611e-6)||v<v_pT(p,273.15))
            return -1;

        if(p<=22.064&&p>=611e-6)
        {
            double vs=v_satp_s(p),vl=v_satp_l(p);
            if(v>=vl&&v<=vs)
                return T_satp(p);
        }	

        if(v>=v_pT(p,623.15)&&v<=v_2pT(p,T_23p(p)))
            {
                double T3=T_3rhop(1/v,p);
                return T3;
            }
        double T1=900,T2=500,T;
        double	F1=FpvT(p,T1,v);
        double	F2=FpvT(p,T2,v);
        while(abs((T2-T1)/T2)>=err)
        {
            T=T2-F2/(F2-F1)*(T2-T1);
            T1=T2;
            T2=T;
            F1=FpvT(p,T1,v);
            F2=FpvT(p,T2,v);
        }
        return T2;
    }
    ///焓值
    double h_pv(double p,double v)
    {
        if((p<611e-6)||(p>100)||(v>v_pT(p,1073.15)&&p>50)||(v>v_pT(p,2273.15)&&p<=50&&p>611e-6)||(v<v_pT(p,273.15)))
            return -1;
        
        if(p<=22.064&&p>=611e-6)
        {
            double vs=v_satp_s(p),vl=v_satp_l(p);
            if(v>=vl&&v<=vs)
            {
                double hs=h_satp_s(p),hl=h_satp_l(p);
                double x=(v-vl)/(vs-vl);
                double h=hl+(hs-hl)*x;
                return h;
            }
        }	
        if(v>=v_pT(p,623.15)&&v<=v_2pT(p,T_23p(p)))
            {
                double h3=h_3rhoT(1/v,T_3rhop(1/v,p));
                return h3;
            }
        double h2=h_pT(p,T_pv(p,v));
        return h2;
    }
    ///熵值
    double s_pv(double p,double v)
    {
        if(p<611e-6||p>100||(v>v_pT(p,1073.15)&&p>50)||(v>v_pT(p,2273.15)&&p<=50&&p>611e-6)||(v<v_pT(p,273.15)))
            return -1;

        if(p<=22.064&&p>=611e-6)
        {
            double vs=v_satp_s(p),vl=v_satp_l(p);
            if(v>=vl&&v<=vs)
            {
                double ss=s_satp_s(p),sl=s_satp_l(p);
                double x=(v-vl)/(vs-vl);
                double s=sl+(ss-sl)*x;
                return s;
            }
        }	
        if(v>=v_pT(p,623.15)&&v<=v_2pT(p,T_23p(p)))
        {
            double s3=s_3rhoT(1/v,T_3rhop(1/v,p));
            return s3;
        }
        double s2=s_pT(p,T_pv(p,v));
        return s2;
    }
    ///比内能值
    double u_pv(double p,double v)
    {
        if(p<611e-6||p>100||(v>v_pT(p,1073.15)&&p>50)||(v>v_pT(p,2273.15)&&p<=50&&p>611e-6)||v<v_pT(p,273.15))
            return -1;

        if(p<=22.064&&p>=611e-6)
        {
            double vs=v_satp_s(p),vl=v_satp_l(p);
            if(v>=vl&&v<=vs)
            {
                double us=u_satp_s(p),ul=u_satp_l(p);
                double x=(v-vl)/(vs-vl);
                double u=ul+(us-ul)*x;
                return u;
            }
        }	
        if(v>=v_pT(p,623.15)&&v<=v_2pT(p,T_23p(p)))
            {
                double u3=u_3rhoT(1/v,T_3rhop(1/v,p));
                return u3;
            }
        double u2=u_pT(p,T_pv(p,v));
        return u2;
    }
    ///等压比热容值
    double cp_pv(double p,double v)
    {
        if(p<611e-6||p>100||(v>v_pT(p,1073.15)&&p>50)||(v>v_pT(p,2273.15)&&p<=50&&p>611e-6)||v<v_pT(p,273.15))
            return -1;

        if(p<=22.064&&p>=611e-6)
        {
            double vs=v_satp_s(p),vl=v_satp_l(p);
            if(v>=vl&&v<=vs)
            {
                double cps=cp_satp_s(p),cpl=cp_satp_l(p);
                double x=(v-vl)/(vs-vl);
                double cp=cpl+(cps-cpl)*x;
                return cp;
            }
        }	
        if(v>=v_pT(p,623.15)&&v<=v_2pT(p,T_23p(p)))
            {
                double cp3=cp_3rhoT(1/v,T_3rhop(1/v,p));
                return cp3;
            }
        double cp2=cp_pT(p,T_pv(p,v));
        return cp2;
    }
    ///等容比热容值
    double cv_pv(double p,double v)
    {
        if(p<611e-6||p>100||(v>v_pT(p,1073.15)&&p>50)||(v>v_pT(p,2273.15)&&p<=50&&p>611e-6)||v<v_pT(p,273.15))
            return -1;

        if(p<=22.064&&p>=611e-6)
        {
            double vs=v_satp_s(p),vl=v_satp_l(p);
            if(v>=vl&&v<=vs)
            {
                double cvs=cv_satp_s(p),cvl=cv_satp_l(p);
                double x=(v-vl)/(vs-vl);
                double cv=cvl+(cvs-cvl)*x;
                return cv;
            }
        }	
        if(v>=v_pT(p,623.15)&&v<=v_2pT(p,T_23p(p)))
            {
                double cv3=cv_3rhoT(1/v,T_3rhop(1/v,p));
                return cv3;
            }
        double cv2=cv_pT(p,T_pv(p,v));
        return cv2;
    }
    ///声速值
    double w_pv(double p,double v)
    {
        if(p<611e-6||p>100||(v>v_pT(p,1073.15)&&p>50)||(v>v_pT(p,2273.15)&&p<=50&&p>611e-6)||v<v_pT(p,273.15))
            return -1;

        if(p<=22.064&&p>=611e-6)
        {
            double vs=v_satp_s(p),vl=v_satp_l(p);
            if(v>=vl&&v<=vs)
            {
                double ws=w_satp_s(p),wl=w_satp_l(p);
                double x=(v-vl)/(vs-vl);
                double w=wl+(ws-wl)*x;
                return w;
            }
        }	
        if(v>=v_pT(p,623.15)&&v<=v_2pT(p,T_23p(p)))
            {
                double w3=w_3rhoT(1/v,T_3rhop(1/v,p));
                return w3;
            }
        double w2=w_pT(p,T_pv(p,v));
        return w2;
    }
    ////干度值
    double x_pv(double p,double v)
    {
        double x=-1;
        if(p<=22.064&&p>=611e-6)
        {
            double vs=v_satp_s(p),vl=v_satp_l(p);
            if(v>=vl&&v<=vs)
                x=(v-vl)/(vs-vl);
        }
        return x;
    }
    //////////////////////////////////////////////
    ///根据p,h计算其他值
    /////////////////////////////////////////////////


    /////计算温度T
    double T_ph(double p,double h)
    {
        if(p<611e-6||p>100||(h>h_pT(p,1073.15)&&p>50)||(h>h_pT(p,2273.15)&&p<=50&&p>611e-6)||h<h_pT(p,273.15))
            return -1;	

            if(p<=22.064&&p>=611e-6)
            {
                double hs=h_satp_s(p),hl=h_satp_l(p);
                if(h>=hl&&h<=hs)
                    return T_satp(p);
            } 
            if((p>=22.064&&h<=h_pT(p,623.15))||(p<=22.064&&h<=h_satp_l(p)))
                return T_1ph(p,h);
            else
                if(h<=h_2pT(p,T_23p(p)))
                    return T_3ph(p,h);
                else
                    if(h<=h_pT(p,1073.15))
                        return T_2ph(p,h);
                    else
                        return T_5ph(p,h);
        
    }
    ////比容
    double v_ph(double p,double h)
    {
        if(p<611e-6||p>100||(h>h_pT(p,1073.15)&&p>50)||(h>h_pT(p,2273.15)&&p<=50&&p>611e-6)||h<h_pT(p,273.15))
            return -1;	

            if(p<=22.064&&p>=611e-6)
            {
                double hs=h_satp_s(p),hl=h_satp_l(p);
                if(h>=hl&&h<=hs)
                {
                    double vs=v_satp_s(p),vl=v_satp_l(p);
                    double x=(h-hl)/(hs-hl);
                    double v=vl+(vs-vl)*x;
                    return v;
                }
            } 
            if((p>=22.064&&h<=h_pT(p,623.15))||(p<=22.064&&h<=h_satp_l(p)))
                return v_1pT(p,T_1ph(p,h));
            else
                if(h<=h_2pT(p,T_23p(p)))
                    return v_3ph(p,h);
                else
                    if(h<=h_pT(p,1073.15))
                        return v_2pT(p,T_2ph(p,h));
                    else
                        return v_5pT(p,T_5ph(p,h));
        
    }
    //比熵
    double s_ph(double p,double h)
    {
        if(p<611e-6||p>100||(h>h_pT(p,1073.15)&&p>50)||(h>h_pT(p,2273.15)&&p<=50&&p>611e-6)||h<h_pT(p,273.15))
            return -1;	

            if(p<=22.064&&p>=611e-6)
            {
                double hs=h_satp_s(p),hl=h_satp_l(p);
                if(h>=hl&&h<=hs)
                {
                    double ss=s_satp_s(p),sl=s_satp_l(p);
                    double x=(h-hl)/(hs-hl);
                    double s=sl+(ss-sl)*x;
                    return s;
                }
            } 
            if((p>=22.064&&h<=h_pT(p,623.15))||(p<=22.064&&h<=h_satp_l(p)))
                return s_1pT(p,T_1ph(p,h));
            else
                if(h<=h_2pT(p,T_23p(p)))
                    return s_3pT(p,T_3ph(p,h));
                else
                    if(h<=h_pT(p,1073.15))
                        return s_3rhoT(1/v_3ph(p,h),T_3ph(p,h));
                    else
                        return s_5pT(p,T_5ph(p,h));
        
    }
    //内能
    double u_ph(double p,double h)
    {
        if(p<611e-6||p>100||(h>h_pT(p,1073.15)&&p>50)||(h>h_pT(p,2273.15)&&p<=50&&p>611e-6)||h<h_pT(p,273.15))
            return -1;	

            if(p<=22.064&&p>=611e-6)
            {
                double hs=h_satp_s(p),hl=h_satp_l(p);
                if(h>=hl&&h<=hs)
                {
                    double us=u_satp_s(p),ul=u_satp_l(p);
                    double x=(h-hl)/(hs-hl);
                    double u=ul+(us-ul)*x;
                    return u;
                }
            } 
            if((p>=22.064&&h<=h_pT(p,623.15))||(p<=22.064&&h<=h_satp_l(p)))
                return u_1pT(p,T_1ph(p,h));
            else
                if(h<=h_2pT(p,T_23p(p)))
                    return u_3rhoT(1/v_3ph(p,h),T_3ph(p,h));
                else
                    if(h<=h_pT(p,1073.15))
                        return u_2pT(p,T_2ph(p,h));
                    else
                        return u_5pT(p,T_5ph(p,h));
        
    }
    //定压比热
    double cp_ph(double p,double h)
    {
        if(p<611e-6||p>100||(h>h_pT(p,1073.15)&&p>50)||(h>h_pT(p,2273.15)&&p<=50&&p>611e-6)||h<h_pT(p,273.15))
            return -1;	

            if(p<=22.064&&p>=611e-6)
            {
                double hs=h_satp_s(p),hl=h_satp_l(p);
                if(h>=hl&&h<=hs)
                {
                    double cps=cp_satp_s(p),cpl=cp_satp_l(p);
                    double x=(h-hl)/(hs-hl);
                    double cp=cpl+(cps-cpl)*x;
                    return cp;
                }
            } 
            if((p>=22.064&&h<=h_pT(p,623.15))||(p<=22.064&&h<=h_satp_l(p)))
                return cp_1pT(p,T_1ph(p,h));
            else
                if(h<=h_2pT(p,T_23p(p)))
                    return cp_3rhoT(1/v_3ph(p,h),T_3ph(p,h));
                else
                    if(h<=h_pT(p,1073.15))
                        return cp_2pT(p,T_2ph(p,h));
                    else
                        return cp_5pT(p,T_5ph(p,h));
        
    }
    //定容比热
    double cv_ph(double p,double h)
    {
        if(p<611e-6||p>100||(h>h_pT(p,1073.15)&&p>50)||(h>h_pT(p,2273.15)&&p<=50&&p>611e-6)||h<h_pT(p,273.15))
            return -1;	

            if(p<=22.064&&p>=611e-6)
            {
                double hs=h_satp_s(p),hl=h_satp_l(p);
                if(h>=hl&&h<=hs)
                {
                    double cvs=cv_satp_s(p),cvl=cv_satp_l(p);
                    double x=(h-hl)/(hs-hl);
                    double cv=cvl+(cvs-cvl)*x;
                    return cv;
                }
            } 
            if((p>=22.064&&h<=h_pT(p,623.15))||(p<=22.064&&h<=h_satp_l(p)))
                return cv_1pT(p,T_1ph(p,h));
            else
                if(h<=h_2pT(p,T_23p(p)))
                    return cv_3rhoT(1/v_3ph(p,h),T_3ph(p,h));
                else
                    if(h<=h_pT(p,1073.15))
                        return cv_2pT(p,T_2ph(p,h));
                    else
                        return cv_5pT(p,T_5ph(p,h));
        
    }
    //声速
    double w_ph(double p,double h)
    {
        if(p<611e-6||p>100||(h>h_pT(p,1073.15)&&p>50)||(h>h_pT(p,2273.15)&&p<=50&&p>611e-6)||h<h_pT(p,273.15))
            return -1;	

            if(p<=22.064&&p>=611e-6)
            {
                double hs=h_satp_s(p),hl=h_satp_l(p);
                if(h>=hl&&h<=hs)
                {
                    double ws=w_satp_s(p),wl=w_satp_l(p);
                    double x=(h-hl)/(hs-hl);
                    double w=wl+(ws-wl)*x;
                    return w;
                }
            } 
            if((p>=22.064&&h<=h_pT(p,623.15))||(p<=22.064&&h<=h_satp_l(p)))
                return w_1pT(p,T_1ph(p,h));
            else
                if(h<=h_2pT(p,T_23p(p)))
                    return w_3rhoT(1/v_3ph(p,h),T_3ph(p,h));
                else
                    if(h<=h_pT(p,1073.15))
                        return w_2pT(p,T_2ph(p,h));
                    else
                        return w_5pT(p,T_5ph(p,h));
        
    }
    ///干度
    double x_ph(double p,double h)
    {
        double x=-1;
        if(p<=22.064&&p>=611e-6)
            {
                double hs=h_satp_s(p),hl=h_satp_l(p);
                if(h>=hl&&h<=hs)
                {
                    double ws=w_satp_s(p),wl=w_satp_l(p);
                    x=(h-hl)/(hs-hl);
                }
            } 
        return x;
    }
    /////////////////////////////////////////////
    /////根据p,s计算其他值
    /////////////////////////////////
    ///温度
    double T_ps(double p,double s)
    {
        if(p<611e-6||p>100||(s>s_pT(p,1073.15)&&p>50)||(s>s_pT(p,2273.15)&&p<=50&&p>611e-6)||s<s_pT(p,273.15))
            return -1;	

            if(p<=22.064&&p>=611e-6)
            {
                double ss=s_satp_s(p),sl=s_satp_l(p);
                if(s>=sl&&s<=ss)
                    return T_satp(p);
            } 
            if((p>=22.064&&s<=s_pT(p,623.15))||(p<=22.064&&s<=s_satp_l(p)))
                return T_1ps(p,s);
            else
                if(s<=s_2pT(p,T_23p(p)))
                    return T_3ps(p,s);
                else
                    if(s<=s_pT(p,1073.15))
                        return T_2ps(p,s);
                    else
                        return T_5ps(p,s);
        
    }
    ////比容
    double v_ps(double p,double s)
    {
        if(p<611e-6||p>100||(s>s_pT(p,1073.15)&&p>50)||(s>s_pT(p,2273.15)&&p<=50&&p>611e-6)||s<s_pT(p,273.15))
            return -1;	

            if(p<=22.064&&p>=611e-6)
            {
                double ss=s_satp_s(p),sl=s_satp_l(p);
                if(s>=sl&&s<=ss)
                {
                    double x=(s-sl)/(ss-sl);
                    double vs=v_satp_s(p),vl=v_satp_l(p);
                    double v=vl+(vs-vl)*x;
                    return v;
                }
            } 
            if((p>=22.064&&s<=s_pT(p,623.15))||(p<=22.064&&s<=s_satp_l(p)))
                return v_1pT(p,T_1ps(p,s));
            else
                if(s<=s_2pT(p,T_23p(p)))
                    return v_3ps(p,s);
                else
                    if(s<=s_pT(p,1073.15))
                        return v_2pT(p,T_2ps(p,s));
                    else
                        return v_5pT(p,T_5ps(p,s));
        
    }
    ////焓值
    double h_ps(double p,double s)
    {
        if(p<611e-6||p>100||(s>s_pT(p,1073.15)&&p>50)||(s>s_pT(p,2273.15)&&p<=50&&p>611e-6)||s<s_pT(p,273.15))
            return -1;	

            if(p<=22.064&&p>=611e-6)
            {
                double ss=s_satp_s(p),sl=s_satp_l(p);
                if(s>=sl&&s<=ss)
                {
                    double x=(s-sl)/(ss-sl);
                    double hs=h_satp_s(p),hl=h_satp_l(p);
                    double h=hl+(hs-hl)*x;
                    return h;
                }
            } 
            if((p>=22.064&&s<=s_pT(p,623.15))||(p<=22.064&&s<=s_satp_l(p)))
                return h_1pT(p,T_1ps(p,s));
            else
                if(s<=s_2pT(p,T_23p(p)))
                    return h_3rhoT(1/v_3ps(p,s),T_3ps(p,s));
                else
                    if(s<=s_pT(p,1073.15))
                        return h_2pT(p,T_2ps(p,s));
                    else
                        return h_5pT(p,T_5ps(p,s));
        
    }
    ////内能
    double u_ps(double p,double s)
    {
        if(p<611e-6||p>100||(s>s_pT(p,1073.15)&&p>50)||(s>s_pT(p,2273.15)&&p<=50&&p>611e-6)||s<s_pT(p,273.15))
            return -1;	

            if(p<=22.064&&p>=611e-6)
            {
                double ss=s_satp_s(p),sl=s_satp_l(p);
                if(s>=sl&&s<=ss)
                {
                    double x=(s-sl)/(ss-sl);
                    double us=u_satp_s(p),ul=u_satp_l(p);
                    double u=ul+(us-ul)*x;
                    return u;
                }
            } 
            if((p>=22.064&&s<=s_pT(p,623.15))||(p<=22.064&&s<=s_satp_l(p)))
                return u_1pT(p,T_1ps(p,s));
            else
                if(s<=s_2pT(p,T_23p(p)))
                    return u_3rhoT(1/v_3ps(p,s),T_3ps(p,s));
                else
                    if(s<=s_pT(p,1073.15))
                        return u_2pT(p,T_2ps(p,s));
                    else
                        return u_5pT(p,T_5ps(p,s));
        
    }
    ////等压比热容
    double cp_ps(double p,double s)
    {
        if(p<611e-6||p>100||(s>s_pT(p,1073.15)&&p>50)||(s>s_pT(p,2273.15)&&p<=50&&p>611e-6)||s<s_pT(p,273.15))
            return -1;	

            if(p<=22.064&&p>=611e-6)
            {
                double ss=s_satp_s(p),sl=s_satp_l(p);
                if(s>=sl&&s<=ss)
                {
                    double x=(s-sl)/(ss-sl);
                    double cps=cp_satp_s(p),cpl=cp_satp_l(p);
                    double cp=cpl+(cps-cpl)*x;
                    return cp;
                }
            } 
            if((p>=22.064&&s<=s_pT(p,623.15))||(p<=22.064&&s<=s_satp_l(p)))
                return cp_1pT(p,T_1ps(p,s));
            else
                if(s<=s_2pT(p,T_23p(p)))
                    return cp_3rhoT(1/v_3ps(p,s),T_3ps(p,s));
                else
                    if(s<=s_pT(p,1073.15))
                        return cp_2pT(p,T_2ps(p,s));
                    else
                        return cp_5pT(p,T_5ps(p,s));
        
    }
    ////等容比热容
    double cv_ps(double p,double s)
    {
        if(p<611e-6||p>100||(s>s_pT(p,1073.15)&&p>50)||(s>s_pT(p,2273.15)&&p<=50&&p>611e-6)||s<s_pT(p,273.15))
            return -1;	

            if(p<=22.064&&p>=611e-6)
            {
                double ss=s_satp_s(p),sl=s_satp_l(p);
                if(s>=sl&&s<=ss)
                {
                    double x=(s-sl)/(ss-sl);
                    double cvs=cv_satp_s(p),cvl=cv_satp_l(p);
                    double cv=cvl+(cvs-cvl)*x;
                    return cv;
                }
            } 
            if((p>=22.064&&s<=s_pT(p,623.15))||(p<=22.064&&s<=s_satp_l(p)))
                return cv_1pT(p,T_1ps(p,s));
            else
                if(s<=s_2pT(p,T_23p(p)))
                    return cv_3rhoT(1/v_3ps(p,s),T_3ps(p,s));
                else
                    if(s<=s_pT(p,1073.15))
                        return cv_2pT(p,T_2ps(p,s));
                    else
                        return cv_5pT(p,T_5ps(p,s));
        
    }
    ////声速
    double w_ps(double p,double s)
    {
        if(p<611e-6||p>100||(s>s_pT(p,1073.15)&&p>50)||(s>s_pT(p,2273.15)&&p<=50&&p>611e-6)||s<s_pT(p,273.15))
            return -1;	

            if(p<=22.064&&p>=611e-6)
            {
                double ss=s_satp_s(p),sl=s_satp_l(p);
                if(s>=sl&&s<=ss)
                {
                    double x=(s-sl)/(ss-sl);
                    double ws=w_satp_s(p),wl=w_satp_l(p);
                    double w=wl+(ws-wl)*x;
                    return w;
                }
            } 
            if((p>=22.064&&s<=s_pT(p,623.15))||(p<=22.064&&s<=s_satp_l(p)))
                return w_1pT(p,T_1ps(p,s));
            else
                if(s<=s_2pT(p,T_23p(p)))
                    return w_3rhoT(1/v_3ps(p,s),T_3ps(p,s));
                else
                    if(s<=s_pT(p,1073.15))
                        return w_2pT(p,T_2ps(p,s));
                    else
                        return w_5pT(p,T_5ps(p,s));
        
    }
    ////////干度
    double x_ps(double p,double s)
    {
        double x=-1;
        if(p<=22.064&&p>=611e-6)
            {
                double ss=s_satp_s(p),sl=s_satp_l(p);
                if(s>=sl&&s<=ss)
                    double x=(s-sl)/(ss-sl);
            } 
        return x;
    }
    ////////////////////////////////////////
    ///////////////////////////////////////
    /////////////////////////////////////
    ////根据p,x写出其他参数
    /////温度
    double T_px(double p,double x)
    {
        double T=-1;
        if(p<=22.064&&p>=611e-6&&x>=0&&x<=1)
            T=T_satp(p);
        return T;
    }
    double v_px(double p,double x)
    {
        double v=-1;
        if(p<=22.064&&p>=611e-6&&x>=0&&x<=1)
        {
            double vs=v_satp_s(p),vl=v_satp_l(p);
            v=vl+(vs-vl)*x;	
        } 
        return v;
    }
    double h_px(double p,double x)
    {
        double h=-1;
        if(p<=22.064&&p>=611e-6&&x>=0&&x<=1)
        {
            double hs=h_satp_s(p),hl=h_satp_l(p);
            h=hl+(hs-hl)*x;	
        } 
        return h;
    }
    double s_px(double p,double x)
    {
        double s=-1;
        if(p<=22.064&&p>=611e-6&&x>=0&&x<=1)
        {
            double ss=s_satp_s(p),sl=s_satp_l(p);
            s=sl+(ss-sl)*x;	
        } 
        return s;
    }
    double u_px(double p,double x)
    {
        double u=-1;
        if(p<=22.064&&p>=611e-6&&x>=0&&x<=1)
        {
            double us=u_satp_s(p),ul=u_satp_l(p);
            u=ul+(us-ul)*x;	
        } 
        return u;
    }
    double cp_px(double p,double x)
    {
        double cp=-1;
        if(p<=22.064&&p>=611e-6&&x>=0&&x<=1)
        {
            double cps=cp_satp_s(p),cpl=cp_satp_l(p);
            cp=cpl+(cps-cpl)*x;	
        } 
        return cp;
    }
    double cv_px(double p,double x)
    {
        double cv=-1;
        if(p<=22.064&&p>=611e-6&&x>=0&&x<=1)
        {
            double cvs=cv_satp_s(p),cvl=cv_satp_l(p);
            cv=cvl+(cvs-cvl)*x;	
        } 
        return cv;
    }
    double w_px(double p,double x)
    {
        double w=-1;
        if(p<=22.064&&p>=611e-6&&x>=0&&x<=1)
        {
            double ws=w_satp_s(p),wl=w_satp_l(p);
            w=wl+(ws-wl)*x;	
        } 
        return w;
    }

    double T_1hs(double h,double s)
    {
        return T_1ph(p_1hs(h,s),h);
    }


    double p_2hs(double h,double s)
    {
        if(h>=h_2abs(s))
            return p_2chs(h,s);
        else 
            if(h>=4)
                return p_2bhs(h,s);
            else 
                return p_2ahs(h,s);
    }
    double T_2hs(double h,double s)
    {
        return T_2ph(p_2hs(h,s),h);
    }

    ///////////////
    ///3区
    double FpTs(double p,double s)
    {
        return s_2pT(p,T_23p(p))-s;
    }
    double p_23s1(double s)
    {
        double p1=22.064;
        double p2=22.1,p;
        double F1=FpTs(p1,s);
        double F2=FpTs(p2,s);
        while(abs((p2-p1)/p2)>=err)
        {
            p=p2-F2/(F2-F1)*(p2-p1);
            p1=p2;
            p2=p;
            F1=FpTs(p1,s);
            F2=FpTs(p2,s);
        }
        return p2;
    }	
    double p_23s2(double s)
    {
        double p1=60;
        double p2=60.1,p;
        double F1=FpTs(p1,s);
        double F2=FpTs(p2,s);
        while(abs((p2-p1)/p2)>=err)
        {
            p=p2-F2/(F2-F1)*(p2-p1);
            p1=p2;
            p2=p;
            F1=FpTs(p1,s);
            F2=FpTs(p2,s);
        }
        return p2;
    }	
    double h_23s1(double s)
    {
        double ps=p_23s1(s);
        return h_2pT(ps,T_23p(ps));
    }
    double h_23s2(double s)
    {
        double ps=p_23s2(s);
        return h_2pT(ps,T_23p(ps));
    }
    double F31hsrhoT(double s,double rho,double T)
    {
        return s_3rhoT(rho,T)-s;
    }
    double F31hsrhoTrho(double s,double rho,double T)
    {
        double tt=647.096/T;
        double h3rhot=him_3rhot(rho,T);
        double h3rho=him_3rho(rho,T);
        double srho=R*(tt*h3rhot-h3rho);
        return srho;
    }
    double F31hsrhoTT(double s,double rho,double T)
    {
        double tt=647.096/T;
        double h3tt=him_3tt(rho,T);
        double sT=R*(tt*h3tt);
        return sT;
    }
    double F32hsrhoT(double h,double rho,double T)
    {
        return h_3rhoT(rho,T)-h;
    }
    double F32hsrhoTrho(double h,double rho,double T)
    {
        double tt=647.096/T;
        double rr=rho/322;
        double h3rhor=him_3rhor(rho,T);
        double h3rhot=him_3rhot(rho,T);
        double h3rho=him_3rho(rho,T);
        double hrho=R*T*(tt*h3rhot+rr*h3rhor+h3rho);
        return hrho;
    }
    double F32hsrhoTT(double h,double rho,double T)
    {
        double tt=647.096/T;
        double rr=rho/322;
        double h3rhot=him_3rhot(rho,T);
        double h3tt=him_3tt(rho,T);
        double h3t=him_3t(rho,T);
        double h3rho=him_3rho(rho,T);
        double ht=R*T*(tt*h3tt+h3t+rr*h3rhot)-647.096/tt/tt*R*(tt*h3t+rr*h3rho);
        return ht;
    }
    void rhoT_3hs(double h,double s,double &rhox,double &Tx)
    {
        double rho1=358;
        double rr=rho1/322;
        double T1=674;
        double tt=647.096/T1;
        double F111=F31hsrhoT(s,rho1,T1);
        double A00=F31hsrhoTrho(s,rho1,T1);
        double A01=F31hsrhoTT(s,rho1,T1);
        double F211=F32hsrhoT(h,rho1,T1);
        double A10=F32hsrhoTrho(h,rho1,T1);
        double A11=F32hsrhoTT(h,rho1,T1);
        while(abs(F111)>=(err)||abs(F211)>=(err))
        {
            rr=rr+(-F111*A11+F211*A01)/(A00*A11-A10*A01);
            tt=tt+(-F211*A00+F111*A10)/(A00*A11-A10*A01);
            rho1=rr*322;
            T1=647.096/tt;
            F111=F31hsrhoT(s,rho1,T1);
            A00=F31hsrhoTrho(s,rho1,T1);
            A01=F31hsrhoTT(s,rho1,T1);
            F211=F32hsrhoT(h,rho1,T1);
            A10=F32hsrhoTrho(h,rho1,T1);
            A11=F32hsrhoTT(h,rho1,T1);
        }
        rhox=rho1;
        Tx=T1;
    }
    /////////////////
    ////4区
    double Fsat1(double s,double p)
    {
        return s_satp_l(p)-s;
    }
    double h_sats_l(double s)
    {
        double p0=5;
        double p1=6,p;
        double F0=Fsat1(s,p0);
        double F1=Fsat1(s,p1);
        while(abs((p1-p0)/p1)>=err)
        {
            p=p1-F1/(F1-F0)*(p1-p0);
            p0=p1;
            p1=p;
            F0=Fsat1(s,p0);
            F1=Fsat1(s,p1);
        }
        return h_satp_l(p1);
    }
    double Fsat2(double s,double p)
    {
        return s_satp_s(p)-s;
    }
    double h_sats_s(double s)
    {
        double p0=0.0011;
        double p1=0.001,p;
        double F0=Fsat2(s,p0);
        double F1=Fsat2(s,p1);
        while(abs((p1-p0)/p1)>=err)
        {
            p=p1-F1/(F1-F0)*(p1-p0);
            p0=p1;
            p1=p;
            F0=Fsat2(s,p0);
            F1=Fsat2(s,p1);
        }
        return h_satp_s(p1);
    }
    double h_sats(double s)
    {
        if(s>=4.41202148223476)
            return h_sats_s(s);
        else 
            return h_sats_l(s);
    }

    double F4hsp(double h,double s,double p)
    {
        double hl=h_satp_l(p),hs=h_satp_s(p);
        double sl=s_satp_l(p),ss=s_satp_s(p);
        double x=(h-hl)/(hs-hl);
        double sx=sl+(ss-sl)*x;
        return sx-s;
    }
    double p_4hs(double h,double s)
    {
        double p0=0.001;
        double p1=0.00111,p;
        double F0=F4hsp(h,s,p0);
        double F1=F4hsp(h,s,p1);
        while(abs((p1-p0)/p1)>=err)
        {
            p=p1-F1/(F1-F0)*(p1-p0);
            p0=p1;
            p1=p;
            F0=F4hsp(h,s,p0);
            F1=F4hsp(h,s,p1);
        }
        return p1;
    }
    ///////////////
    ///5区
    double F51hspT(double s,double p,double T)
    {
        return s_5pT(p,T)-s;
    }
    double F51hspTp(double s,double p,double T)
    {
        double tt=1000/T;
        double go5p=go_5p(p,T);
        double gr5p=gr_5p(p,T);
        double go5pt=go_5pt(p,T);
        double gr5pt=gr_5pt(p,T);
        double sp=R*(tt*(go5pt+gr5pt)-(go5p+gr5p));
        return sp;
    }
    double F51hspTT(double s,double p,double T)
    {
        double tt=1000/T;
        double go5tt=go_5tt(p,T);
        double gr5tt=gr_5tt(p,T);
        double st=R*tt*(go5tt+gr5tt);
        return st;
    }
    double F52hspT(double h,double p,double T)
    {
        return h_5pT(p,T)-h;
    }
    double F52hspTp(double h,double p,double T)
    {
        double tt=1000/T;
        double go5pt=go_5pt(p,T);
        double gr5pt=gr_5pt(p,T);
        double hp=R*T*tt*(go5pt+gr5pt);
        return hp;
    }
    double F52hspTT(double h,double p,double T)
    {
        double tt=1000/T;
        double go5tt=go_5tt(p,T);
        double gr5tt=gr_5tt(p,T);
        double ht=R*T*tt*(go5tt+gr5tt);
        return ht;
    }
    void pT_5hs(double h,double s,double &px,double &Tx)
    {
        double p1=611e-6;
        double pp=p1;
        double T1=1200;
        double tt=1000/T1;
        double F111=F51hspT(s,p1,T1);
        double A00=F51hspTp(s,p1,T1);
        double A01=F51hspTT(s,p1,T1);
        double F211=F52hspT(h,p1,T1);
        double A10=F52hspTp(h,p1,T1);
        double A11=F52hspTT(h,p1,T1);
        while(abs(F111)>=(err)||abs(F211)>=(err))
        {
            pp=pp+(-F111*A11+F211*A01)/(A00*A11-A10*A01);
            tt=tt+(-F211*A00+F111*A10)/(A00*A11-A10*A01);
            p1=pp;
            T1=1000/tt;
            F111=F51hspT(s,p1,T1);
            A00=F51hspTp(s,p1,T1);
            A01=F51hspTT(s,p1,T1);
            F211=F52hspT(h,p1,T1);
            A10=F52hspTp(h,p1,T1);
            A11=F52hspTT(h,p1,T1);
        }
        px=p1;
        Tx=T1;
    }
    ////////////////温度
    double T_hs(double h,double s)
    {
        double T,r;
        if(s<-0.00858229||s>13.9051||(((h<h_ps(611e-6,s)&&s>=9.15592&&s<=13.9051)||(h<=h_sT(s,273.15)&&s>=-0.00858229&&s<9.15592))||((h>h_ps(100,s)&&s<=6.04048)||(h>h_sT(s,800+273.15)&&s>6.04048&&s<=6.52264)||(s>6.52264&&s<=8.66887&&h>=h_ps(50,s))||(h>=h_sT(s,2273.15)&&s>8.66887&&s<=13.9051))))
            return -1;
        if(s>0&&s<9.156&&h<=h_sats(s))
            return T_satp(p_4hs(h,s));
        else
            if(h<=h_sT(s,623.15))
                return T_1hs(h,s);
            else
                if(s<=5.047||(s<=5.097969&&(h<=h_23s1(s)||h>=h_23s2(s)))||(s<=5.261&&h>=h_23s1(s)))
                {
                    rhoT_3hs(h,s,r,T);
                    return T;
                }

                else
                    if(h<=h_sT(s,1073.15))
                        return T_2hs(h,s);
                    else
                    {
                        pT_5hs(h,s,r,T);
                        return T;
                    }
    }
    ////////////////////
    //压力
    double p_hs(double h,double s)
    {
        double T,r;
        if(s<-0.00858229||s>13.9051||(((h<h_ps(611e-6,s)&&s>=9.15592&&s<=13.9051)||(h<=h_sT(s,273.15)&&s>=-0.00858229&&s<9.15592))||((h>h_ps(100,s)&&s<=6.04048)||(h>h_sT(s,800+273.15)&&s>6.04048&&s<=6.52264)||(s>6.52264&&s<=8.66887&&h>=h_ps(50,s))||(h>=h_sT(s,2273.15)&&s>8.66887&&s<=13.9051))))
            return -1;
        if(s>0&&s<9.156&&h<=h_sats(s))
            return p_4hs(h,s);
        else
            if(h<=h_sT(s,623.15))
                return p_1hs(h,s);
            else
                if(s<=5.047||(s<=5.097969&&(h<=h_23s1(s)||h>=h_23s2(s)))||(s<=5.261&&h>=h_23s1(s)))
                {
                    rhoT_3hs(h,s,r,T);
                    return p_3rhoT(r,T);
                }

                else
                    if(h<=h_sT(s,1073.15))
                        return p_2hs(h,s);
                    else
                    {
                        pT_5hs(h,s,r,T);
                        return r;
                    }
    }
    ///////////////////
    ////比容
    double v_hs(double h,double s)
    {
        double T,r;
        if(s<-0.00858229||s>13.9051||(((h<h_ps(611e-6,s)&&s>=9.15592&&s<=13.9051)||(h<=h_sT(s,273.15)&&s>=-0.00858229&&s<9.15592))||((h>h_ps(100,s)&&s<=6.04048)||(h>h_sT(s,800+273.15)&&s>6.04048&&s<=6.52264)||(s>6.52264&&s<=8.66887&&h>=h_ps(50,s))||(h>=h_sT(s,2273.15)&&s>8.66887&&s<=13.9051))))
            return -1;
        if(s>0&&s<9.156&&h<=h_sats(s))
        {
            double pxs=p_4hs(h,s);
            double hl=h_satp_l(pxs),hs=h_satp_s(pxs);
            double x=(h-hl)/(hs-hl);
            double vl=v_satp_l(pxs),vs=v_satp_s(pxs);
            double v=vl+(vs-vl)*x;
            return v;
        }
        else
            if(h<=h_sT(s,623.15))
                return v_1pT(p_1hs(h,s),T_1hs(h,s));
            else
                if(s<=5.047||(s<=5.097969&&(h<=h_23s1(s)||h>=h_23s2(s)))||(s<=5.261&&h>=h_23s1(s)))
                {
                    rhoT_3hs(h,s,r,T);
                    return 1/r;
                }

                else
                    if(h<=h_sT(s,1073.15))
                        return v_2pT(p_2hs(h,s),T_2hs(h,s));
                    else
                    {
                        pT_5hs(h,s,r,T);
                        return v_5pT(r,T);
                    }
    }
    ////////////////////
    ///比内能
    double u_hs(double h,double s)
    {
        double T,r;
        if(s<-0.00858229||s>13.9051||(((h<h_ps(611e-6,s)&&s>=9.15592&&s<=13.9051)||(h<=h_sT(s,273.15)&&s>=-0.00858229&&s<9.15592))||((h>h_ps(100,s)&&s<=6.04048)||(h>h_sT(s,800+273.15)&&s>6.04048&&s<=6.52264)||(s>6.52264&&s<=8.66887&&h>=h_ps(50,s))||(h>=h_sT(s,2273.15)&&s>8.66887&&s<=13.9051))))
            return -1;
        if(s>0&&s<9.156&&h<=h_sats(s))
        {
            double pxs=p_4hs(h,s);
            double hl=h_satp_l(pxs),hs=h_satp_s(pxs);
            double x=(h-hl)/(hs-hl);
            double ul=u_satp_l(pxs),us=u_satp_s(pxs);
            double u=ul+(us-ul)*x;
            return u;
        }
        else
            if(h<=h_sT(s,623.15))
                return u_1pT(p_1hs(h,s),T_1hs(h,s));
            else
                if(s<=5.047||(s<=5.097969&&(h<=h_23s1(s)||h>=h_23s2(s)))||(s<=5.261&&h>=h_23s1(s)))
                {
                    rhoT_3hs(h,s,r,T);
                    return u_3rhoT(r,T);
                }

                else
                    if(h<=h_sT(s,1073.15))
                        return u_2pT(p_2hs(h,s),T_2hs(h,s));
                    else
                    {
                        pT_5hs(h,s,r,T);
                        return u_5pT(r,T);
                    }
    }
    //等压比热
    double cp_hs(double h,double s)
    {
        double T,r;
        if(s<-0.00858229||s>13.9051||(((h<h_ps(611e-6,s)&&s>=9.15592&&s<=13.9051)||(h<=h_sT(s,273.15)&&s>=-0.00858229&&s<9.15592))||((h>h_ps(100,s)&&s<=6.04048)||(h>h_sT(s,800+273.15)&&s>6.04048&&s<=6.52264)||(s>6.52264&&s<=8.66887&&h>=h_ps(50,s))||(h>=h_sT(s,2273.15)&&s>8.66887&&s<=13.9051))))
            return -1;
        if(s>0&&s<9.156&&h<=h_sats(s))
        {
            double pxs=p_4hs(h,s);
            double hl=h_satp_l(pxs),hs=h_satp_s(pxs);
            double x=(h-hl)/(hs-hl);
            double cpl=cp_satp_l(pxs),cps=cp_satp_s(pxs);
            double cp=cpl+(cps-cpl)*x;
            return cp;
        }
        else
            if(h<=h_sT(s,623.15))
                return cp_1pT(p_1hs(h,s),T_1hs(h,s));
            else
                if(s<=5.047||(s<=5.097969&&(h<=h_23s1(s)||h>=h_23s2(s)))||(s<=5.261&&h>=h_23s1(s)))
                {
                    rhoT_3hs(h,s,r,T);
                    return cp_3rhoT(r,T);
                }

                else
                    if(h<=h_sT(s,1073.15))
                        return cp_2pT(p_2hs(h,s),T_2hs(h,s));
                    else
                    {
                        pT_5hs(h,s,r,T);
                        return cp_5pT(r,T);
                    }
    }
    //等容比热
    double cv_hs(double h,double s)
    {
        double T,r;
        if(s<-0.00858229||s>13.9051||(((h<h_ps(611e-6,s)&&s>=9.15592&&s<=13.9051)||(h<=h_sT(s,273.15)&&s>=-0.00858229&&s<9.15592))||((h>h_ps(100,s)&&s<=6.04048)||(h>h_sT(s,800+273.15)&&s>6.04048&&s<=6.52264)||(s>6.52264&&s<=8.66887&&h>=h_ps(50,s))||(h>=h_sT(s,2273.15)&&s>8.66887&&s<=13.9051))))
            return -1;
        if(s>0&&s<9.156&&h<=h_sats(s))
        {
            double pxs=p_4hs(h,s);
            double hl=h_satp_l(pxs),hs=h_satp_s(pxs);
            double x=(h-hl)/(hs-hl);
            double cvl=cv_satp_l(pxs),cvs=cv_satp_s(pxs);
            double cv=cvl+(cvs-cvl)*x;
            return cv;
        }
        else
            if(h<=h_sT(s,623.15))
                return cv_1pT(p_1hs(h,s),T_1hs(h,s));
            else
                if(s<=5.047||(s<=5.097969&&(h<=h_23s1(s)||h>=h_23s2(s)))||(s<=5.261&&h>=h_23s1(s)))
                {
                    rhoT_3hs(h,s,r,T);
                    return cv_3rhoT(r,T);
                }

                else
                    if(h<=h_sT(s,1073.15))
                        return cv_2pT(p_2hs(h,s),T_2hs(h,s));
                    else
                    {
                        pT_5hs(h,s,r,T);
                        return cv_5pT(r,T);
                    }
    }
    //声速
    double w_hs(double h,double s)
    {
        double T,r;
        if(s<-0.00858228709262||s>13.9051167039||(((h<h_ps(611e-6,s)&&s>=9.15592081137&&s<=13.9051)||(h<=h_sT(s,273.15)&&s>=-0.00858228709262&&s<9.15592081137))||((h>h_ps(100,s)&&s<=6.04048367171)||(h>h_sT(s,800+273.15)&&s>6.04048367171&&s<=6.52264231228)||(s>6.52264231228&&s<=8.66886626516&&h>=h_ps(50,s))||(h>=h_sT(s,2273.15)&&s>8.66886626516&&s<=13.9051167039))))
            return -1;
        if(s>0&&s<9.156&&h<=h_sats(s))
        {
            double pxs=p_4hs(h,s);
            double hl=h_satp_l(pxs),hs=h_satp_s(pxs);
            double x=(h-hl)/(hs-hl);
            double wl=w_satp_l(pxs),ws=w_satp_s(pxs);
            double w=wl+(ws-wl)*x;
            return w;
        }
        else
            if(h<=h_sT(s,623.15))
                return w_1pT(p_1hs(h,s),T_1hs(h,s));
            else
                if(s<=5.047||(s<=5.097969&&(h<=h_23s1(s)||h>=h_23s2(s)))||(s<=5.261&&h>=h_23s1(s)))
                {
                    rhoT_3hs(h,s,r,T);
                    return w_3rhoT(r,T);
                }

                else
                    if(h<=h_sT(s,1073.15))
                        return w_2pT(p_2hs(h,s),T_2hs(h,s));
                    else
                    {
                        pT_5hs(h,s,r,T);
                        return w_5pT(r,T);
                    }
    }
    /////干度
    double x_hs(double h,double s)
    {
        double x=-1;
        if(s>0&&s<9.156&&h<=h_sats(s))
        {
            double pxs=p_4hs(h,s);
            double hl=h_satp_l(pxs),hs=h_satp_s(pxs);
            x=(h-hl)/(hs-hl);
        }
        return x;
    }
    /////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////
    /////根据h,v求解其他值
    ////1区
    double FpT_h(double p,double T,double h)
    {
        return h_1pT(p,T)-h;
    }
    double FpT_hp(double p,double T,double h)
    {
        double tt=1386/T;
        double gpt=g_1pt(p,T);
        double hp=T*R*tt*gpt;
        return hp;
    }
    double FpT_ht(double p,double T,double h)
    {
        double tt=1386/T;
        double gtt=g_1tt(p,T);
        double ht=T*R*tt*gtt;
        return ht;
    }
    double FpT_v(double p,double T,double v)
    {
        return v_1pT(p,T)-v;
    }
    double FpT_vp(double p,double T,double v)
    {
        double pp=p/16.53;
        double gpp=g_1pp(p,T);
        double vp=R*T*pp*gpp/p/1000;
        return vp;
    }
    double FpT_vt(double p,double T,double v)
    {
        double pp=p/16.53;
        double tt=1386/T;
        double gp=g_1p(p,T);
        double gpt=g_1pt(p,T);
        double vt=R*pp/p*(-1386/tt/tt*gp+1386/tt*gpt)/1000;
        return vt;
    }
    void pT_1hv(double h,double v,double &p,double &T)
    {
        double p0=50;
        double T0=473.15;
        double pp=p0/16.53;
        double tt=1386/T0;
        double Fh=FpT_h(p0,T0,h);
        double Fhp=FpT_hp(p0,T0,h);
        double FhT=FpT_ht(p0,T0,h);
        double Fv=FpT_v(p0,T0,v);
        double Fvp=FpT_vp(p0,T0,v);
        double FvT=FpT_vt(p0,T0,v);
        while(abs(Fh)>=err||abs(Fv)*100>=err)
        {
            pp=pp+(-Fh*FvT+Fv*FhT)/(Fhp*FvT-FhT*Fvp);
            tt=tt+(-Fv*Fhp+Fh*Fvp)/(Fhp*FvT-FhT*Fvp);
            p0=pp*16.53;
            T0=1386/tt;
            Fh=FpT_h(p0,T0,h);
            Fhp=FpT_hp(p0,T0,h);
            FhT=FpT_ht(p0,T0,h);
            Fv=FpT_v(p0,T0,v);
            Fvp=FpT_vp(p0,T0,v);
            FvT=FpT_vt(p0,T0,v);
        }
        p=p0;
        T=T0;
    }
    //////////////////
    //2区
    double FpT_h2(double p,double T,double h)
    {
        return h_2pT(p,T)-h;
    }
    double FpT_h2p(double p,double T,double h)
    {
        double tt=540/T;
        double gopt=go_2pt(p,T);
        double gtpt=gt_2pt(p,T);
        double hp=R*T*(gopt+gtpt)*tt;
        return hp;
    }
    double FpT_h2t(double p,double T,double h)
    {
        double tt=540/T;
        double gott=go_2tt(p,T);
        double gttt=gt_2tt(p,T);
        double ht=R*T*(gott+gttt)*tt;
        return ht;
    }
    double FpT_v2(double p,double T,double v)
    {
        return v_2pT(p,T)-v;
    }
    double FpT_v2p(double p,double T,double v)
    {
        double pp=p;
        double tt=540/T;
        double gopp=go_2pp(p,T);
        double gtpp=gt_2pp(p,T);
        double vp=pp*(gopp+gtpp)*R*T/p/1000;
        return vp;
    }
    double FpT_v2t(double p,double T,double v)
    {
        double pp=p;
        double tt=540/T;
        double gopt=go_2pt(p,T);
        double gtpt=gt_2pt(p,T);
        double gop=go_2p(p,T);
        double gtp=gt_2p(p,T);
        double vt=pp*((gopt+gtpt)*T-540/tt/tt*(gop+gtp))*R/p/1000;
        return vt;
    }
    void pT_2hv(double h,double v,double &p,double &T)
    {
        double p0=0.001;
        double T0=700;
        double pp=p0;
        double tt=540/T0;
        double Fh=FpT_h2(p0,T0,h);
        double Fhp=FpT_h2p(p0,T0,h);
        double FhT=FpT_h2t(p0,T0,h);
        double Fv=FpT_v2(p0,T0,v);
        double Fvp=FpT_v2p(p0,T0,v);
        double FvT=FpT_v2t(p0,T0,v);
        while(abs(Fh)>=err||abs(Fv)>=err)
        {
            pp=pp+(-Fh*FvT+Fv*FhT)/(Fhp*FvT-FhT*Fvp);
            tt=tt+(-Fv*Fhp+Fh*Fvp)/(Fhp*FvT-FhT*Fvp);
            p0=pp;
            T0=540/tt;
            Fh=FpT_h2(p0,T0,h);
            Fhp=FpT_h2p(p0,T0,h);
            FhT=FpT_h2t(p0,T0,h);
            Fv=FpT_v2(p0,T0,v);
            Fvp=FpT_v2p(p0,T0,v);
            FvT=FpT_v2t(p0,T0,v);
        }
        p=p0;
        T=T0;
    }
    double F23pvx(double p,double v)
    {
        return v_2pT(p,T_23p(p))-v;
    }
    double p_23v(double v) 
    {
        double p1=30;
        double p2=29,p;
        double F1=F23pvx(p1,v);
        double F2=F23pvx(p2,v);
        while(abs((p2-p1)/p2)>=err)
        {
            p=p2-F2/(F2-F1)*(p2-p1);
            p1=p2;
            p2=p;
            F1=F23pvx(p1,v);
            F2=F23pvx(p2,v);
        }
        return p2;
    }
    double h_23v(double v)
    {
        double p=p_23v(v);
        return h_2pT(p,T_23p(p));
    }
    ////////////////////////
    ///3区
    double T_3hv(double h,double v)
    {
        double T1=650,T2=660,T;
        double F1=h_3rhoT(1/v,T1)-h;
        double F2=h_3rhoT(1/v,T2)-h;
        while(abs((T2-T1)/T2)>=err)
        {
            T=T2-F2/(F2-F1)*(T2-T1);
            T1=T2;
            T2=T;
            F1=h_3rhoT(1/v,T1)-h;
            F2=h_3rhoT(1/v,T2)-h;
        }
        return T2;
    }
    /////////////////
    ////4区
    double Fsatv(double v,double p)
    {
        return v_satp_l(p)-v;
    }
    double h_satv_l1(double v)
    {
        double p0=612e-6;
        double p1=813e-6,p;
        double F0=Fsatv(v,p0);
        double F1=Fsatv(v,p1);
            
        while(abs((p1-p0)/p1)>=err)
        {	
            p=p1-F1/(F1-F0)*(p1-p0);
            p0=p1;
            p1=p;
            F0=Fsatv(v,p0);
            F1=Fsatv(v,p1);
        }
        return h_satp_l(p1);
    }
    double h_satv_l2(double v)
    {
        double p0=813e-6;
        double p1=1,p;
        if(v>=0.0019)
        {
            p0=19;
            p1=20;
        }
        double F0=Fsatv(v,p0);
        double F1=Fsatv(v,p1);	
        while(abs((p1-p0)/p1)>=err)
        {	
            p=p1-F1/(F1-F0)*(p1-p0);
            p0=p1;
            p1=p;
            F0=Fsatv(v,p0);
            F1=Fsatv(v,p1);
        }
        return h_satp_l(p1);
    }
    double Fsatv0(double v,double p)
    {
        return v_satp_s(p)-v;
    }
    double h_satv_s(double v)
    {
        double p0=0.0011;
        double p1=0.001,p;

        double F0=Fsatv0(v,p0);
        double F1=Fsatv0(v,p1);
        while(abs((p1-p0)/p1)>=err)
        {
            p=p1-F1/(F1-F0)*(p1-p0);
            p0=p1;
            p1=p;
            F0=Fsatv0(v,p0);
            F1=Fsatv0(v,p1);
        }
        return h_satp_s(p1);
    }
    double h_satv(double v)
    {
        if(v<=0.00310386368752925)
            return h_satv_l2(v);
        else 
            return h_satv_s(v);
    }
    double F4hvp(double h,double v,double p)
    {
        double hl=h_satp_l(p),hs=h_satp_s(p);
        double vl=v_satp_l(p),vs=v_satp_s(p);
        double x=(h-hl)/(hs-hl);
        double vx=vl+(vs-vl)*x;
        return vx-v;
    }
    double p_4hv(double h,double v)
    {
        double p0=0.001;
        double p1=0.00111,p;
        double F0=F4hvp(h,v,p0);
        double F1=F4hvp(h,v,p1);
        while(abs((p1-p0)/p1)>=err)
        {
            p=p1-F1/(F1-F0)*(p1-p0);
            p0=p1;
            p1=p;
            F0=F4hvp(h,v,p0);
            F1=F4hvp(h,v,p1);
        }
        return p1;
    }
    ////////////
    //5区
    double F53hspT(double v,double p,double T)
    {
        return v_5pT(p,T)-v;
    }
    double F53hspTp(double v,double p,double T)
    {
        double pp=p;
        double go5pp=go_5pp(p,T);
        double gr5pp=gr_5pp(p,T);
        double vp=R*T*pp/p*(go5pp+gr5pp)/1000;
        return vp;
    }
    double F53hspTT(double v,double p,double T)
    {
        double tt=1000/T;
        double go5p=go_5p(p,T);
        double gr5p=gr_5p(p,T);
        double go5pt=go_5pt(p,T);
        double gr5pt=gr_5pt(p,T);
        double vt=R*T*(go5pt+gr5pt)/1000-R/tt/tt*(go5p+gr5p);
        return vt;
    }
    void pT_5hv(double h,double v,double &px,double &Tx)
    {
        double p1=611e-6;
        double pp=p1;
        double T1=1200;
        double tt=1000/T1;
        double F111=F53hspT(v,p1,T1);
        double A00=F53hspTp(v,p1,T1);
        double A01=F53hspTT(v,p1,T1);
        double F211=F52hspT(h,p1,T1);
        double A10=F52hspTp(h,p1,T1);
        double A11=F52hspTT(h,p1,T1);
        while(abs(F111)>=(err)||abs(F211)>=(err))
        {
            pp=pp+(-F111*A11+F211*A01)/(A00*A11-A10*A01);
            tt=tt+(-F211*A00+F111*A10)/(A00*A11-A10*A01);
            p1=pp;
            T1=1000/tt;
            F111=F53hspT(v,p1,T1);
            A00=F53hspTp(v,p1,T1);
            A01=F53hspTT(v,p1,T1);
            F211=F52hspT(h,p1,T1);
            A10=F52hspTp(h,p1,T1);
            A11=F52hspTT(h,p1,T1);

        }
        px=p1;
        Tx=T1;
    }
    ///压力
    double p_hv(double h,double v)
    {
        double px,Tx;
        if(v>1717.05091351||v<0.000956686939149||(v>=0.000956686939149&&v<=0.00433550765325&&h>h_pv(100,v))||(v>0.00433550765325&&v<=0.00907413302907&&h>h_vT(v,1073.15))||(v>=0.00907413302907&&v<=0.0214633996483&&h>h_pv(50,v))||(v>=0.0214633996483&&v<=1717.05091351&&h>h_vT(v,2273.15))||(v>=206.21151503&&v<=1717.05091351&&h<h_pv(611e-6,v))||(v<=206.21151503&&v>=0.000956686939149&&h<h_vT(v,273.15)))
            return -1;
        if((v<=0.00100020577362017&&h<=h_satv_l2(v)&&h>=h_satv_l1(v))||h<=h_satv(v))
            return p_4hv(h,v);
        else
            if(v<=0.00174007534199888&&h<=h_vT(v,623.15))
            {
                pT_1hv(h,v,px,Tx);
                return px;
            }
            else 
                if(h<=h_23v(v))
                {						
                    return p_3rhoT(1/v,T_3hv(h,v));
                }
                else
                    if(h<=h_vT(v,1073.15))
                    {
                        
                        pT_2hv(h,v,px,Tx);
                        return px;
                    }
                    else
                    {
                        pT_5hv(h,v,px,Tx);
                        return px;
                    }
    }
    //温度
    double T_hv(double h,double v)
    {
        double px,Tx;
        if(v>1717.05091351||v<0.000956686939149||(v>=0.000956686939149&&v<=0.00433550765325&&h>h_pv(100,v))||(v>0.00433550765325&&v<=0.00907413302907&&h>h_vT(v,1073.15))||(v>=0.00907413302907&&v<=0.0214633996483&&h>h_pv(50,v))||(v>=0.0214633996483&&v<=1717.05091351&&h>h_vT(v,2273.15))||(v>=206.21151503&&v<=1717.05091351&&h<h_pv(611e-6,v))||(v<=206.21151503&&v>=0.000956686939149&&h<h_vT(v,273.15)))
            return -1;
        if((v<=0.00100020577362017&&h<=h_satv_l2(v)&&h>=h_satv_l1(v))||h<=h_satv(v))
            return T_satp(p_4hv(h,v));
        else
            if(v<=0.00174007534199888&&h<=h_vT(v,623.15))
            {
                pT_1hv(h,v,px,Tx);
                return Tx;
            }
            else 
                if(h<=h_23v(v))
                {						
                    return T_3hv(h,v);
                }
                else
                    if(h<=h_vT(v,1073.15))
                    {
                        
                        pT_2hv(h,v,px,Tx);
                        return Tx;
                    }
                    else
                    {
                        pT_5hv(h,v,px,Tx);
                        return Tx;
                    }
    }
    //熵值
    double s_hv(double h,double v)
    {
        double px,Tx;
        if(v>1717.05091351||v<0.000956686939149||(v>=0.000956686939149&&v<=0.00433550765325&&h>h_pv(100,v))||(v>0.00433550765325&&v<=0.00907413302907&&h>h_vT(v,1073.15))||(v>=0.00907413302907&&v<=0.0214633996483&&h>h_pv(50,v))||(v>=0.0214633996483&&v<=1717.05091351&&h>h_vT(v,2273.15))||(v>=206.21151503&&v<=1717.05091351&&h<h_pv(611e-6,v))||(v<=206.21151503&&v>=0.000956686939149&&h<h_vT(v,273.15)))
            return -1;
        if((v<=0.00100020577362017&&h<=h_satv_l2(v)&&h>=h_satv_l1(v))||h<=h_satv(v))
        {
            px=p_4hv(h,v);
            double hl=h_satp_l(px),hs=h_satp_s(px);
            double x=(h-hl)/(hs-hl);
            double sl=s_satp_l(px),ss=s_satp_s(px);
            return sl+(ss-sl)*x;
        }
        else
            if(v<=0.00174007534199888&&h<=h_vT(v,623.15))
            {
                pT_1hv(h,v,px,Tx);
                return s_1pT(px,Tx);
            }
            else 
                if(h<=h_23v(v))					
                    return s_3rhoT(1/v,T_3hv(h,v));
                else
                    if(h<=h_vT(v,1073.15))
                    {
                        pT_2hv(h,v,px,Tx);
                        return s_2pT(px,Tx);
                    }
                    else
                    {
                        pT_5hv(h,v,px,Tx);
                        return s_2pT(px,Tx);
                    }
    }
    ////比内能
    double u_hv(double h,double v)
    {
        double px,Tx;
        if(v>1717.05091351||v<0.000956686939149||(v>=0.000956686939149&&v<=0.00433550765325&&h>h_pv(100,v))||(v>0.00433550765325&&v<=0.00907413302907&&h>h_vT(v,1073.15))||(v>=0.00907413302907&&v<=0.0214633996483&&h>h_pv(50,v))||(v>=0.0214633996483&&v<=1717.05091351&&h>h_vT(v,2273.15))||(v>=206.21151503&&v<=1717.05091351&&h<h_pv(611e-6,v))||(v<=206.21151503&&v>=0.000956686939149&&h<h_vT(v,273.15)))
            return -1;
        if((v<=0.00100020577362017&&h<=h_satv_l2(v)&&h>=h_satv_l1(v))||h<=h_satv(v))
        {
            px=p_4hv(h,v);
            double hl=h_satp_l(px),hs=h_satp_s(px);
            double x=(h-hl)/(hs-hl);
            double ul=u_satp_l(px),us=u_satp_s(px);
            return ul+(us-ul)*x;
        }
        else
            if(v<=0.00174007534199888&&h<=h_vT(v,623.15))
            {
                pT_1hv(h,v,px,Tx);
                return u_1pT(px,Tx);
            }
            else 
                if(h<=h_23v(v))					
                    return u_3rhoT(1/v,T_3hv(h,v));
                else
                    if(h<=h_vT(v,1073.15))
                    {
                        pT_2hv(h,v,px,Tx);
                        return u_2pT(px,Tx);
                    }
                    else
                    {
                        pT_5hv(h,v,px,Tx);
                        return u_2pT(px,Tx);
                    }
    }
    ////等压比热容
    double cp_hv(double h,double v)
    {
        double px,Tx;
        if(v>1717.05091351||v<0.000956686939149||(v>=0.000956686939149&&v<=0.00433550765325&&h>h_pv(100,v))||(v>0.00433550765325&&v<=0.00907413302907&&h>h_vT(v,1073.15))||(v>=0.00907413302907&&v<=0.0214633996483&&h>h_pv(50,v))||(v>=0.0214633996483&&v<=1717.05091351&&h>h_vT(v,2273.15))||(v>=206.21151503&&v<=1717.05091351&&h<h_pv(611e-6,v))||(v<=206.21151503&&v>=0.000956686939149&&h<h_vT(v,273.15)))
            return -1;
        if((v<=0.00100020577362017&&h<=h_satv_l2(v)&&h>=h_satv_l1(v))||h<=h_satv(v))
        {
            px=p_4hv(h,v);
            double hl=h_satp_l(px),hs=h_satp_s(px);
            double x=(h-hl)/(hs-hl);
            double cpl=cp_satp_l(px),cps=cp_satp_s(px);
            return cpl+(cps-cpl)*x;
        }
        else
            if(v<=0.00174007534199888&&h<=h_vT(v,623.15))
            {
                pT_1hv(h,v,px,Tx);
                return cp_1pT(px,Tx);
            }
            else 
                if(h<=h_23v(v))					
                    return cp_3rhoT(1/v,T_3hv(h,v));
                else
                    if(h<=h_vT(v,1073.15))
                    {
                        pT_2hv(h,v,px,Tx);
                        return cp_2pT(px,Tx);
                    }
                    else
                    {
                        pT_5hv(h,v,px,Tx);
                        return cp_2pT(px,Tx);
                    }
    }
    ////等容比热容
    double cv_hv(double h,double v)
    {
        double px,Tx;
        if(v>1717.05091351||v<0.000956686939149||(v>=0.000956686939149&&v<=0.00433550765325&&h>h_pv(100,v))||(v>0.00433550765325&&v<=0.00907413302907&&h>h_vT(v,1073.15))||(v>=0.00907413302907&&v<=0.0214633996483&&h>h_pv(50,v))||(v>=0.0214633996483&&v<=1717.05091351&&h>h_vT(v,2273.15))||(v>=206.21151503&&v<=1717.05091351&&h<h_pv(611e-6,v))||(v<=206.21151503&&v>=0.000956686939149&&h<h_vT(v,273.15)))
            return -1;
        if((v<=0.00100020577362017&&h<=h_satv_l2(v)&&h>=h_satv_l1(v))||h<=h_satv(v))
        {
            px=p_4hv(h,v);
            double hl=h_satp_l(px),hs=h_satp_s(px);
            double x=(h-hl)/(hs-hl);
            double cvl=cv_satp_l(px),cvs=cv_satp_s(px);
            return cvl+(cvs-cvl)*x;
        }
        else
            if(v<=0.00174007534199888&&h<=h_vT(v,623.15))
            {
                pT_1hv(h,v,px,Tx);
                return cv_1pT(px,Tx);
            }
            else 
                if(h<=h_23v(v))					
                    return cv_3rhoT(1/v,T_3hv(h,v));
                else
                    if(h<=h_vT(v,1073.15))
                    {
                        pT_2hv(h,v,px,Tx);
                        return cv_2pT(px,Tx);
                    }
                    else
                    {
                        pT_5hv(h,v,px,Tx);
                        return cv_2pT(px,Tx);
                    }
    }
    ////声速
    double w_hv(double h,double v)
    {
        double px,Tx;
        if(v>1717.05091351||v<0.000956686939149||(v>=0.000956686939149&&v<=0.00433550765325&&h>h_pv(100,v))||(v>0.00433550765325&&v<=0.00907413302907&&h>h_vT(v,1073.15))||(v>=0.00907413302907&&v<=0.0214633996483&&h>h_pv(50,v))||(v>=0.0214633996483&&v<=1717.05091351&&h>h_vT(v,2273.15))||(v>=206.21151503&&v<=1717.05091351&&h<h_pv(611e-6,v))||(v<=206.21151503&&v>=0.000956686939149&&h<h_vT(v,273.15)))
            return -1;
        if((v<=0.00100020577362017&&h<=h_satv_l2(v)&&h>=h_satv_l1(v))||h<=h_satv(v))
        {
            px=p_4hv(h,v);
            double hl=h_satp_l(px),hs=h_satp_s(px);
            double x=(h-hl)/(hs-hl);
            double wl=w_satp_l(px),ws=w_satp_s(px);
            return wl+(ws-wl)*x;
        }
        else
            if(v<=0.00174007534199888&&h<=h_vT(v,623.15))
            {
                pT_1hv(h,v,px,Tx);
                return w_1pT(px,Tx);
            }
            else 
                if(h<=h_23v(v))					
                    return w_3rhoT(1/v,T_3hv(h,v));
                else
                    if(h<=h_vT(v,1073.15))
                    {
                        pT_2hv(h,v,px,Tx);
                        return w_2pT(px,Tx);
                    }
                    else
                    {
                        pT_5hv(h,v,px,Tx);
                        return w_2pT(px,Tx);
                    }
    }
    ////干度
    double x_hv(double h,double v)
    {
        if(v>1717.05091351||v<0.000956686939149||(v>=0.000956686939149&&v<=0.00433550765325&&h>h_pv(100,v))||(v>0.00433550765325&&v<=0.00907413302907&&h>h_vT(v,1073.15))||(v>=0.00907413302907&&v<=0.0214633996483&&h>h_pv(50,v))||(v>=0.0214633996483&&v<=1717.05091351&&h>h_vT(v,2273.15))||(v>=206.21151503&&v<=1717.05091351&&h<h_pv(611e-6,v))||(v<=206.21151503&&v>=0.000956686939149&&h<h_vT(v,273.15)))
            return -1;
        double x=-1;
        if((v<=0.00100020577362017&&h<=h_satv_l2(v)&&h>=h_satv_l1(v))||h<=h_satv(v))
        {
            double px=p_4hv(h,v);
            double hl=h_satp_l(px),hs=h_satp_s(px);
            x=(h-hl)/(hs-hl);
        }
        return x;
    }
    ///////////////////////////////////////////////////////////////////////
    ////////////////通过h,x求出其他值


    double Fxhp(double x,double h,double p)
    {
        double hl=h_satp_l(p),hs=h_satp_s(p);
        double xx=(h-hl)/(hs-hl);
        return xx-x;
    }
    void p_hx(double h,double x,double &px,double &py)
    {	
        px=-1;
        py=-1;
        double gd=(sqrt(5)-1)/2;
        double hmin,hmax;
        double pmin,pmax;
        double xx=612e-6,y=22.064;
        double p0=xx,p1=y;
        double p00,p10;
        double F0=h_px(p0,x),F1=h_px(p1,x),F00,F10;
        double hxx=F0,hy=F1;
        if(F0>F1)
        {
            hmin=F1;
            pmin=p1;
            hmax=F0;
            pmax=p0;
        }
        else
        {
            hmin=F0;
            pmin=p0;
            hmax=F1;
            pmax=p1;
        }
        if(x>=0.4825)
        {
            p00=p0+0.382*(p1-p0),p10=p0+0.618*(p1-p0);
            F00=h_px(p00,x),F10=h_px(p10,x);	
            while(abs((p1-p0)/p1)>=1e-10)
            {
                if(F00<F10)
                {
                    p0=p00;
                    F0=F00;
                    p00=p10;
                    F00=F10;
                    p10=p0+gd*(p1-p0);
                    F10=h_px(p10,x);
                }
                else
                {
                    p1=p10;
                    F1=F10;
                    p10=p00;
                    F10=F00;
                    p00=p0+(1-gd)*(p1-p0);
                    F00=h_px(p00,x);
                }
            }
            pmax=p0;
            hmax=F0;
            if(h<hmin||h>hmax)
                return;
            if(h>=hy)
            {
                double pn1=pmax,pn2=y,pn,Fn;
                double Fn1=Fxhp(x,h,pn1);
                double	Fn2=Fxhp(x,h,pn2);
                while(abs((pn2-pn1)/pn2)>=err)
                {
                    pn=(pn1+pn2)/2;
                    Fn=Fxhp(x,h,pn);
                    if(Fn*Fn1<0)
                    {
                        pn2=pn;
                        Fn2=Fn;
                    }
                    else
                    {
                        pn1=pn;
                        Fn1=Fn;
                    }
                }
                py=pn2;
            }
        }
        if(h<hmin||h>hmax)
            return;
        if(h>=hxx)
        {
            double pm1=0.000611213,pm2=pmax,pm,Fm;
            double	Fm1=Fxhp(x,h,pm1);
            double	Fm2=Fxhp(x,h,pm2);
            while(abs((pm2-pm1)/pm2)>=err)
            {
                pm=(pm2+pm1)/2;
                Fm=Fxhp(x,h,pm);
                if(Fm*Fm1<0)
                {
                    pm2=pm;
                    Fm2=Fm;
                }
                else
                {
                    pm1=pm;
                    Fm1=Fm;
                }	
            }
            px=pm2;
            return;
        }
        return;
    }
    void T_hx(double h,double x,double &Tx,double &Ty)
    {
        double p1,p2;
        p_hx(h,x,p1,p2);
        if(p1==-1)
            Tx=-1;
        else
            Tx=T_satp(p1);
        if(p2==-1)
            Ty=-1;
        else
            Ty=T_satp(p2);
        return;
    }
    void v_hx(double h,double x,double &vx,double &vy)
    {
        double p1,p2;
        p_hx(h,x,p1,p2);
        if(p1==-1)
            vx=-1;
        else
        {
            double vl=v_satp_l(p1),vs=v_satp_s(p1);
            vx=vl+(vs-vl)*x;
        }
        if(p2==-1)
            vy=-1;
        else
        {
            double vl=v_satp_l(p2),vs=v_satp_s(p2);
            vy=vl+(vs-vl)*x;
        }
        return;
    }
    void s_hx(double h,double x,double &sx,double &sy)
    {
        double p1,p2;
        p_hx(h,x,p1,p2);
        if(p1==-1)
            sx=-1;
        else
        {
            double sl=s_satp_l(p1),ss=s_satp_s(p1);
            sx=sl+(ss-sl)*x;
        }
        if(p2==-1)
            sy=-1;
        else
        {
            double sl=s_satp_l(p2),ss=s_satp_s(p2);
            sy=sl+(ss-sl)*x;
        }
        return;
    }
    void u_hx(double h,double x,double &ux,double &uy)
    {
        double p1,p2;
        p_hx(h,x,p1,p2);
        if(p1==-1)
            ux=-1;
        else
        {
            double ul=u_satp_l(p1),us=u_satp_s(p1);
            ux=ul+(us-ul)*x;
        }
        if(p2==-1)
            uy=-1;
        else
        {
            double ul=u_satp_l(p2),us=u_satp_s(p2);
            uy=ul+(us-ul)*x;
        }
        return;
    }
    void cp_hx(double h,double x,double &cpx,double &cpy)
    {
        double p1,p2;
        p_hx(h,x,p1,p2);
        if(p1==-1)
            cpx=-1;
        else
        {
            double cpl=cp_satp_l(p1),cps=cp_satp_s(p1);
            cpx=cpl+(cps-cpl)*x;
        }
        if(p2==-1)
            cpy=-1;
        else
        {
            double cpl=cp_satp_l(p2),cps=cp_satp_s(p2);
            cpy=cpl+(cps-cpl)*x;
        }
        return;
    }
    void cv_hx(double h,double x,double &cvx,double &cvy)
    {
        double p1,p2;
        p_hx(h,x,p1,p2);
        if(p1==-1)
            cvx=-1;
        else
        {
            double cvl=cv_satp_l(p1),cvs=cv_satp_s(p1);
            cvx=cvl+(cvs-cvl)*x;
        }
        if(p2==-1)
            cvy=-1;
        else
        {
            double cvl=cv_satp_l(p2),cvs=cv_satp_s(p2);
            cvy=cvl+(cvs-cvl)*x;
        }
        return;
    }
    void w_hx(double h,double x,double &wx,double &wy)
    {
        double p1,p2;
        p_hx(h,x,p1,p2);
        if(p1==-1)
            wx=-1;
        else
        {
            double wl=w_satp_l(p1),ws=w_satp_s(p1);
            wx=wl+(ws-wl)*x;
        }
        if(p2==-1)
            wy=-1;
        else
        {
            double wl=w_satp_l(p2),ws=w_satp_s(p2);
            wy=wl+(ws-wl)*x;
        }
        return;
    }
    /////////////////////////////////////
    ///通过v,s计算其他值
    double F11hspT(double s,double p,double T)
    {
        return s_1pT(p,T)-s;

    }
    double F11hspTp(double s,double p,double T)
    {
        double tt=1386/T;
        double gpt=g_1pt(p,T);
        double gp=g_1p(p,T);
        double sp=R*(tt*gpt-gp);
        return sp;

    }
    double F11hspTT(double s,double p,double T)
    {
        double tt=1386/T;
        double gtt=g_1tt(p,T);
        double gt=g_1t(p,T);
        double sT=R*tt*gtt;
        return sT;
    }
    void pT_1vs(double v,double s,double &p,double &T)
    {
        double p0;
        double T0=400;
        if(v>7)
            p0=0.025;
        else
            if(v>0.25)
                p0=1.4;
            else
                if(v>0.025)
                    p0=12;
                else
                    p0=50;
        double pp=p0/16.53;
        double tt=1386/T0;
        double Fv=FpT_v(p0,T0,v);
        double Fvp=FpT_vp(p0,T0,v);
        double FvT=FpT_vt(p0,T0,v);
        double Fs=F11hspT(s,p0,T0);
        double Fsp=F11hspTp(s,p0,T0);
        double FsT=F11hspTT(s,p0,T0);
        while(abs(Fs)>=err||abs(Fv)*100>=err)
        {
            pp=pp+(-Fv*FsT+Fs*FvT)/(Fvp*FsT-FvT*Fsp);
            tt=tt+(-Fs*Fvp+Fv*Fsp)/(Fvp*FsT-FvT*Fsp);
            p0=pp*16.53;
            T0=1386/tt;

            Fv=FpT_v(p0,T0,v);
            Fvp=FpT_vp(p0,T0,v);
            FvT=FpT_vt(p0,T0,v);
            Fs=F11hspT(s,p0,T0);
            Fsp=F11hspTp(s,p0,T0);
            FsT=F11hspTT(s,p0,T0);
        }
        p=p0;
        T=T0;
    }
    //////////////////
    //2区
    double F21hspT(double s,double p,double T)
    {
        return s_2pT(p,T)-s;

    }
    double F21hspTp(double s,double p,double T)
    {
        double pp=p;
        double tt=540/T;
        double gopt=go_2pt(p,T);
        double gtpt=gt_2pt(p,T);
        double gop=go_2p(p,T);
        double gtp=gt_2p(p,T);
        double sp=R*(tt*(gopt+gtpt)-(gop+gtp));
        return sp;
    }
    double F21hspTT(double s,double p,double T)
    {
        double pp=p;
        double tt=540/T;
        double got=go_2t(p,T);
        double gtt=gt_2t(p,T);
        double gott=go_2tt(p,T);
        double gttt=gt_2tt(p,T);
        double sT=R*((got+gtt)+tt*(gott+gttt)-(got+gtt));
        return sT;
    }
    void pT_2vs(double v,double s,double &p,double &T)
    {
        double p0=5;
        double T0=700;
        if(v>=0.06)
            p0=0.001;
        double pp=p0;
        double tt=540/T0;
        double Fv=FpT_v2(p0,T0,v);
        double Fvp=FpT_v2p(p0,T0,v);
        double FvT=FpT_v2t(p0,T0,v);
        double Fs=F21hspT(s,p0,T0);
        double Fsp=F21hspTp(s,p0,T0);
        double FsT=F21hspTT(s,p0,T0);
        
        while(abs(Fv)>=err||abs(Fs)>=err)
        {
            pp=pp+(-Fv*FsT+Fs*FvT)/(Fvp*FsT-FvT*Fsp);
            tt=tt+(-Fs*Fvp+Fv*Fsp)/(Fvp*FsT-FvT*Fsp);
            p0=pp;
            T0=540/tt;
            Fv=FpT_v2(p0,T0,v);
            Fvp=FpT_v2p(p0,T0,v);
            FvT=FpT_v2t(p0,T0,v);
            Fs=F21hspT(s,p0,T0);
            Fsp=F21hspTp(s,p0,T0);
            FsT=F21hspTT(s,p0,T0);
        }
        p=p0;
        T=T0;
    }
    double s_23v(double v)
    {
        double p=p_23v(v);
        return s_2pT(p,T_23p(p));
    }
    ////////////////////////
    ///3区
    double T_3vs(double v,double s)
    {
        double T1=650,T2=660,T;
        double F1=s_3rhoT(1/v,T1)-s;
        double F2=s_3rhoT(1/v,T2)-s;
        while(abs((T2-T1)/T2)>=err)
        {
            T=T2-F2/(F2-F1)*(T2-T1);
            T1=T2;
            T2=T;
            F1=s_3rhoT(1/v,T1)-s;
            F2=s_3rhoT(1/v,T2)-s;
        }
        return T2;
    }
    /////////////////
    ////4区
    double s_satv_l1(double v)
    {
        double p0=612e-6;
        double p1=813e-6,p;
        double F0=Fsatv(v,p0);
        double F1=Fsatv(v,p1);
            
        while(abs((p1-p0)/p1)>=err)
        {	
            p=p1-F1/(F1-F0)*(p1-p0);
            p0=p1;
            p1=p;
            F0=Fsatv(v,p0);
            F1=Fsatv(v,p1);
        }
        return s_satp_l(p1);
    }
    double s_satv_l2(double v)
    {
        double p0=813e-6;
        double p1=1,p;
        if(v>=2.5)
        {
            p0=813e-6;
            p1=0.08;
        }
        else
            if(v>=0.02)
            {
                p0=16;
                p1=21;
            }
            else
                if(v>=0.003)
                {
                    p0=48;
                    p1=52;
                }
                else
                {
                    p0=70;
                    p1=80;
                }
        double F0=Fsatv(v,p0);
        double F1=Fsatv(v,p1);	
        while(abs((p1-p0)/p1)>=err)
        {	
            p=p1-F1/(F1-F0)*(p1-p0);
            p0=p1;
            p1=p;
            F0=Fsatv(v,p0);
            F1=Fsatv(v,p1);
        }
        return s_satp_l(p1);
    }
    double s_satv_s(double v)
    {
        double p0=0.0011;
        double p1=0.001,p;

        double F0=Fsatv0(v,p0);
        double F1=Fsatv0(v,p1);
        while(abs((p1-p0)/p1)>=err)
        {
            p=p1-F1/(F1-F0)*(p1-p0);
            p0=p1;
            p1=p;
            F0=Fsatv0(v,p0);
            F1=Fsatv0(v,p1);
        }
        return s_satp_s(p1);
    }
    double s_satv(double v)
    {
        
        if(v<=0.00310386368752925)
            return s_satv_l2(v);
        else 
            return s_satv_s(v);
    }
    double F4vsp(double v,double s,double p)
    {
        double sl=s_satp_l(p),ss=s_satp_s(p);
        double vl=v_satp_l(p),vs=v_satp_s(p);
        double x=(s-sl)/(ss-sl);
        double vx=vl+(vs-vl)*x;
        return vx-v;
    }
    double p_4vs(double v,double s)
    {
        double p0=0.001;
        double p1=0.00111,p;
        double F0=F4vsp(v,s,p0);
        double F1=F4vsp(v,s,p1);
        while(abs((p1-p0)/p1)>=err)
        {
            p=p1-F1/(F1-F0)*(p1-p0);
            p0=p1;
            p1=p;
            F0=F4vsp(v,s,p0);
            F1=F4vsp(v,s,p1);
        }
        return p1;
    }
    ////////////
    //5区
    void pT_5vs(double v,double s,double &px,double &Tx)
    {
        double p1=611e-6;
        double pp=p1;
        double T1=1200;
        double tt=1000/T1;
        double F111=F53hspT(v,p1,T1);
        double A00=F53hspTp(v,p1,T1);
        double A01=F53hspTT(v,p1,T1);
        double F211=F51hspT(s,p1,T1);
        double A10=F51hspTp(s,p1,T1);
        double A11=F51hspTT(s,p1,T1);
        while(abs(F111)>=(err)||abs(F211)>=(err))
        {
            pp=pp+(-F111*A11+F211*A01)/(A00*A11-A10*A01);
            tt=tt+(-F211*A00+F111*A10)/(A00*A11-A10*A01);
            p1=pp;
            T1=1000/tt;
            F111=F53hspT(v,p1,T1);
            A00=F53hspTp(v,p1,T1);
            A01=F53hspTT(v,p1,T1);
            F211=F51hspT(s,p1,T1);
            A10=F51hspTp(s,p1,T1);
            A11=F51hspTT(s,p1,T1);
        }
        px=p1;
        Tx=T1;
    }
    double T_vs(double v,double s)
    {
        double Tx,px;
        if(v>1717.05091351||v<0.000956686939149||(v>=0.000956686939149&&v<=0.00433550765325&&s>s_pv(100,v))||(v>0.00433550765325&&v<=0.00907413302907&&s>s_vT(v,1073.15))||(v>=0.00907413302907&&v<=0.0214633996483&&s>s_pv(50,v))||(v>=0.0214633996483&&v<=1717.05091351&&s>s_vT(v,2273.15))||(v>=206.21151503&&v<=1717.05091351&&s<s_pv(611e-6,v))||(v<=206.21151503&&v>=0.000956686939149&&s<s_vT(v,273.15)))
            return -1;
        if((v<=0.00100020577362017&&s<=s_satv_l2(v)&&s>=s_satv_l1(v))||s<=s_satv(v))
        {
            
            return T_satp(p_4vs(v,s));
        }
        else
            if(v<=0.00174007534199888&&s<=s_vT(v,623.15))
            {
                pT_1vs(v,s,px,Tx);
                return Tx;
            }
            else 	
                if(s<=s_23v(v))
                {			
                
                    return T_3vs(v,s);
                }
                else
                    if(s<=s_vT(v,1073.15))
                    {
                    
                        pT_2vs(v,s,px,Tx);
                        return Tx;
                    }
                    else
                    {
                        pT_5vs(v,s,px,Tx);
                        return Tx;
                    }
            
    }
    //压力
    double p_vs(double v,double s)
    {
        double Tx,px;
        if(v>1717.05091351||v<0.000956686939149||(v>=0.000956686939149&&v<=0.00433550765325&&s>s_pv(100,v))||(v>0.00433550765325&&v<=0.00907413302907&&s>s_vT(v,1073.15))||(v>=0.00907413302907&&v<=0.0214633996483&&s>s_pv(50,v))||(v>=0.0214633996483&&v<=1717.05091351&&s>s_vT(v,2273.15))||(v>=206.21151503&&v<=1717.05091351&&s<s_pv(611e-6,v))||(v<=206.21151503&&v>=0.000956686939149&&s<s_vT(v,273.15)))
            return -1;
        if((v<=0.00100020577362017&&s<=s_satv_l2(v)&&s>=s_satv_l1(v))||s<=s_satv(v))
        {
            
            return p_4vs(v,s);
        }
        else
            if(v<=0.00174007534199888&&s<=s_vT(v,623.15))
            {
                pT_1vs(v,s,px,Tx);
                return px;
            }
            else 	
                if(s<=s_23v(v))		
                    return p_3rhoT(1/v,T_3vs(v,s));
                else
                    if(s<=s_vT(v,1073.15))
                    {
                        pT_2vs(v,s,px,Tx);
                        return px;
                    }
                    else
                    {
                        pT_5vs(v,s,px,Tx);
                        return px;
                    }
    }
    //焓值
    double h_vs(double v,double s)
    {
        double Tx,px;
        if(v>1717.05091351||v<0.000956686939149||(v>=0.000956686939149&&v<=0.00433550765325&&s>s_pv(100,v))||(v>0.00433550765325&&v<=0.00907413302907&&s>s_vT(v,1073.15))||(v>=0.00907413302907&&v<=0.0214633996483&&s>s_pv(50,v))||(v>=0.0214633996483&&v<=1717.05091351&&s>s_vT(v,2273.15))||(v>=206.21151503&&v<=1717.05091351&&s<s_pv(611e-6,v))||(v<=206.21151503&&v>=0.000956686939149&&s<s_vT(v,273.15)))
            return -1;
        if((v<=0.00100020577362017&&s<=s_satv_l2(v)&&s>=s_satv_l1(v))||s<=s_satv(v))
        {
            double p=p_4vs(v,s);
            double vl=v_satp_l(p),vs=v_satp_s(p);
            double hl=h_satp_l(p),hs=h_satp_s(p);
            double x=(v-vl)/(vs-vl);
            double h=hl+(hs-hl)*x;
            return h;
        }
        else
            if(v<=0.00174007534199888&&s<=s_vT(v,623.15))
            {
                pT_1vs(v,s,px,Tx);
                return h_1pT(px,Tx);
            }
            else 	
                if(s<=s_23v(v))		
                    return h_3rhoT(1/v,T_3vs(v,s));
                else
                    if(s<=s_vT(v,1073.15))
                    {
                        pT_2vs(v,s,px,Tx);
                        return h_2pT(px,Tx);
                    }
                    else
                    {
                        pT_5vs(v,s,px,Tx);
                        return h_5pT(px,Tx);
                    }
    }
    //内能
    double u_vs(double v,double s)
    {
        double Tx,px;
        if(v>1717.05091351||v<0.000956686939149||(v>=0.000956686939149&&v<=0.00433550765325&&s>s_pv(100,v))||(v>0.00433550765325&&v<=0.00907413302907&&s>s_vT(v,1073.15))||(v>=0.00907413302907&&v<=0.0214633996483&&s>s_pv(50,v))||(v>=0.0214633996483&&v<=1717.05091351&&s>s_vT(v,2273.15))||(v>=206.21151503&&v<=1717.05091351&&s<s_pv(611e-6,v))||(v<=206.21151503&&v>=0.000956686939149&&s<s_vT(v,273.15)))
            return -1;
        if((v<=0.00100020577362017&&s<=s_satv_l2(v)&&s>=s_satv_l1(v))||s<=s_satv(v))
        {
            double p=p_4vs(v,s);
            double vl=v_satp_l(p),vs=v_satp_s(p);
            double ul=u_satp_l(p),us=u_satp_s(p);
            double x=(v-vl)/(vs-vl);
            double u=ul+(us-ul)*x;
            return u;
        }
        else
            if(v<=0.00174007534199888&&s<=s_vT(v,623.15))
            {
                pT_1vs(v,s,px,Tx);
                return u_1pT(px,Tx);
            }
            else 	
                if(s<=s_23v(v))		
                    return u_3rhoT(1/v,T_3vs(v,s));
                else
                    if(s<=s_vT(v,1073.15))
                    {
                        pT_2vs(v,s,px,Tx);
                        return u_2pT(px,Tx);
                    }
                    else
                    {
                        pT_5vs(v,s,px,Tx);
                        return u_5pT(px,Tx);
                    }
    }
    //等压比热
    double cp_vs(double v,double s)
    {
        double Tx,px;
        if(v>1717.05091351||v<0.000956686939149||(v>=0.000956686939149&&v<=0.00433550765325&&s>s_pv(100,v))||(v>0.00433550765325&&v<=0.00907413302907&&s>s_vT(v,1073.15))||(v>=0.00907413302907&&v<=0.0214633996483&&s>s_pv(50,v))||(v>=0.0214633996483&&v<=1717.05091351&&s>s_vT(v,2273.15))||(v>=206.21151503&&v<=1717.05091351&&s<s_pv(611e-6,v))||(v<=206.21151503&&v>=0.000956686939149&&s<s_vT(v,273.15)))
            return -1;
        if((v<=0.00100020577362017&&s<=s_satv_l2(v)&&s>=s_satv_l1(v))||s<=s_satv(v))
        {
            double p=p_4vs(v,s);
            double vl=v_satp_l(p),vs=v_satp_s(p);
            double cpl=cp_satp_l(p),cps=cp_satp_s(p);
            double x=(v-vl)/(vs-vl);
            double cp=cpl+(cps-cpl)*x;
            return cp;
        }
        else
            if(v<=0.00174007534199888&&s<=s_vT(v,623.15))
            {
                pT_1vs(v,s,px,Tx);
                return cp_1pT(px,Tx);
            }
            else 	
                if(s<=s_23v(v))		
                    return cp_3rhoT(1/v,T_3vs(v,s));
                else
                    if(s<=s_vT(v,1073.15))
                    {
                        pT_2vs(v,s,px,Tx);
                        return cp_2pT(px,Tx);
                    }
                    else
                    {
                        pT_5vs(v,s,px,Tx);
                        return cp_5pT(px,Tx);
                    }
    }
    //等容比热
    double cv_vs(double v,double s)
    {
        double Tx,px;
        if(v>1717.05091351||v<0.000956686939149||(v>=0.000956686939149&&v<=0.00433550765325&&s>s_pv(100,v))||(v>0.00433550765325&&v<=0.00907413302907&&s>s_vT(v,1073.15))||(v>=0.00907413302907&&v<=0.0214633996483&&s>s_pv(50,v))||(v>=0.0214633996483&&v<=1717.05091351&&s>s_vT(v,2273.15))||(v>=206.21151503&&v<=1717.05091351&&s<s_pv(611e-6,v))||(v<=206.21151503&&v>=0.000956686939149&&s<s_vT(v,273.15)))
            return -1;
        if((v<=0.00100020577362017&&s<=s_satv_l2(v)&&s>=s_satv_l1(v))||s<=s_satv(v))
        {
            double p=p_4vs(v,s);
            double vl=v_satp_l(p),vs=v_satp_s(p);
            double cvl=cv_satp_l(p),cvs=cv_satp_s(p);
            double x=(v-vl)/(vs-vl);
            double cv=cvl+(cvs-cvl)*x;
            return cv;
        }
        else
            if(v<=0.00174007534199888&&s<=s_vT(v,623.15))
            {
                pT_1vs(v,s,px,Tx);
                return cv_1pT(px,Tx);
            }
            else 	
                if(s<=s_23v(v))		
                    return cv_3rhoT(1/v,T_3vs(v,s));
                else
                    if(s<=s_vT(v,1073.15))
                    {
                        pT_2vs(v,s,px,Tx);
                        return cv_2pT(px,Tx);
                    }
                    else
                    {
                        pT_5vs(v,s,px,Tx);
                        return cv_5pT(px,Tx);
                    }
    }
    //声速
    double w_vs(double v,double s)
    {
        double Tx,px;
        if(v>1717.05091351||v<0.000956686939149||(v>=0.000956686939149&&v<=0.00433550765325&&s>s_pv(100,v))||(v>0.00433550765325&&v<=0.00907413302907&&s>s_vT(v,1073.15))||(v>=0.00907413302907&&v<=0.0214633996483&&s>s_pv(50,v))||(v>=0.0214633996483&&v<=1717.05091351&&s>s_vT(v,2273.15))||(v>=206.21151503&&v<=1717.05091351&&s<s_pv(611e-6,v))||(v<=206.21151503&&v>=0.000956686939149&&s<s_vT(v,273.15)))
            return -1;
        if((v<=0.00100020577362017&&s<=s_satv_l2(v)&&s>=s_satv_l1(v))||s<=s_satv(v))
        {
            double p=p_4vs(v,s);
            double vl=v_satp_l(p),vs=v_satp_s(p);
            double wl=w_satp_l(p),ws=w_satp_s(p);
            double x=(v-vl)/(vs-vl);
            double w=wl+(ws-wl)*x;
            return w;
        }
        else
            if(v<=0.00174007534199888&&s<=s_vT(v,623.15))
            {
                pT_1vs(v,s,px,Tx);
                return w_1pT(px,Tx);
            }
            else 	
                if(s<=s_23v(v))		
                    return w_3rhoT(1/v,T_3vs(v,s));
                else
                    if(s<=s_vT(v,1073.15))
                    {
                        pT_2vs(v,s,px,Tx);
                        return w_2pT(px,Tx);
                    }
                    else
                    {
                        pT_5vs(v,s,px,Tx);
                        return w_5pT(px,Tx);
                    }
    }
    //干度
    double x_vs(double v,double s)
    {
        double x=-1;
        if((v<=0.00100020577362017&&s<=s_satv_l2(v)&&s>=s_satv_l1(v))||s<=s_satv(v))
        {
            double p=p_4vs(v,s);
            double vl=v_satp_l(p),vs=v_satp_s(p);
            x=(v-vl)/(vs-vl);
        }
        return x;
    }
    ////////////////////////////////////////////////////
    ////根据v,x计算其他
    double FTvx(double v,double x,double T)
    {
        double vl=v_satT_l(T),vs=v_satT_s(T);
        double vx=vl+(vs-vl)*x;
        return vx-v;
    }
    void T_vx(double v,double x,double &Trea,double &Tred)
    {
        Trea=-1,Tred=-1;
        if(x>1||x<0)
            return;
        double gd=(sqrt(5)-1)/2;
        double Tx=273.15,Ty=647.096,Txx,Tyy;
        double vx=v_xT(x,Tx),vy=v_xT(x,Ty),vxx,vyy;
        double vmx,vmn,Tmx,Tmn;
        if(vx>vy)
        {
            vmx=vx;
            Tmx=Tx;
            vmn=vy;
            Tmn=Ty;
        }
        else
        {
            vmx=vy;
            Tmx=Ty;
            vmn=vx;
            Tmn=Tx;
        }
        vxx=vx,vyy=vy,Txx=Tx,Tyy=Ty;
        if(x<=0.491695243011044)
        {
            double Tl=Tx+(1-gd)*(Ty-Tx);
            double Tr=Tx+gd*(Ty-Tx);
            double	vl=v_xT(x,Tl),vr=v_xT(x,Tr);
            while(abs((Ty-Tx)/Ty)>=err)
            {
                if(vl>vr)
                {
                    vx=vl;
                    Tx=Tl;
                    vl=vr;
                    Tl=Tr;
                    Tr=Tx+0.618*(Ty-Tx);
                    vr=v_xT(x,Tr);
                }
                else
                {
                    vy=vr;
                    Ty=Tr;
                    vr=vl;
                    Tr=Tl;
                    Tl=Tx+0.382*(Ty-Tx);
                    vl=v_xT(x,Tl);
                }
            }
            vmn=vy;
            Tmn=Ty;
            if(v>vmn&&v<=vyy)
            {
                double T1=Tyy,T2=Tmn,Tm;
                double F1=FTvx(v,x,T1),F2=FTvx(v,x,T2),Fm;
                while(F2*F1<=0&&(abs((T1-T2)/T1)>1e-10))
                {
                    Tm=(T2+T1)/2l;
                    Fm=FTvx(v,x,Tm);
                    if(Fm*F1<0)
                    {
                        T2=Tm;
                        F2=Fm;
                    }
                    else
                    {
                        T1=Tm;
                        F1=Fm;
                    }
                }
                Tred=T1;
            }
        }
        if(v<vmn||v>vxx)
            return;
        double T11=Tmn,T22=Txx,Tmm;
        double F11=FTvx(v,x,T11),F22=FTvx(v,x,T22),Fmm;
        while(F22*F11<0)
        {
            Tmm=(T11+T22)/2;
            Fmm=FTvx(v,x,Tmm);
            if(Fmm*F11<=0&&(abs((T11-T22)/T11)>1e-10))
            {
                T22=Tmm;
                F22=Fmm;
            }
            else
            {
                T11=Tmm;
                F11=Fmm;
            }
        }
        Trea=T11;
        return;
    }
    void p_vx(double v,double x,double &p1,double &p2)
    {
        double T1,T2;
        p1=-1,p2=-1;
        T_vx(v,x,T1,T2);
        if(T1!=-1)
            p1=p_satT(T1);
        if(T2!=-1)
            p2=p_satT(T2);
        return;
    }
    void h_vx(double v,double x,double &h1,double &h2)
    {
        double T1,T2;
        h1=-1,h2=-1;
        T_vx(v,x,T1,T2);
        if(T1!=-1)
        {
            double hl=h_satT_l(T1),hs=h_satT_s(T1);
            h1=hl+(hs-hl)*x;
        }
        if(T2!=-1)
        {
            double hl=h_satT_l(T2),hs=h_satT_s(T2);
            h2=hl+(hs-hl)*x;
        }
        return;
    }
    void s_vx(double v,double x,double &s1,double &s2)
    {
        double T1,T2;
        s1=-1,s2=-1;
        T_vx(v,x,T1,T2);
        if(T1!=-1)
        {
            double sl=s_satT_l(T1),ss=s_satT_s(T1);
            s1=sl+(ss-sl)*x;
        }
        if(T2!=-1)
        {
            double sl=s_satT_l(T2),ss=s_satT_s(T2);
            s2=sl+(ss-sl)*x;
        }
        return;
    }
    void u_vx(double v,double x,double &u1,double &u2)
    {
        double T1,T2;
        u1=-1,u2=-1;
        T_vx(v,x,T1,T2);
        if(T1!=-1)
        {
            double ul=u_satT_l(T1),us=u_satT_s(T1);
            u1=ul+(us-ul)*x;
        }
        if(T2!=-1)
        {
            double ul=u_satT_l(T2),us=u_satT_s(T2);
            u2=ul+(us-ul)*x;
        }
        return;
    }
    void cp_vx(double v,double x,double &cp1,double &cp2)
    {
        double T1,T2;
        cp1=-1,cp2=-1;
        T_vx(v,x,T1,T2);
        if(T1!=-1)
        {
            double cpl=cp_satT_l(T1),cps=cp_satT_s(T1);
            cp1=cpl+(cps-cpl)*x;
        }
        if(T2!=-1)
        {
            double cpl=cp_satT_l(T2),cps=cp_satT_s(T2);
            cp2=cpl+(cps-cpl)*x;
        }
        return;
    }
    void cv_vx(double v,double x,double &cv1,double &cv2)
    {
        double T1,T2;
        cv1=-1,cv2=-1;
        T_vx(v,x,T1,T2);
        if(T1!=-1)
        {
            double cvl=cv_satT_l(T1),cvs=cv_satT_s(T1);
            cv1=cvl+(cvs-cvl)*x;
        }
        if(T2!=-1)
        {
            double cvl=cv_satT_l(T2),cvs=cv_satT_s(T2);
            cv2=cvl+(cvs-cvl)*x;
        }
        return;
    }
    void w_vx(double v,double x,double &w1,double &w2)
    {
        double T1,T2;
        w1=-1,w2=-1;
        T_vx(v,x,T1,T2);
        if(T1!=-1)
        {
            double wl=w_satT_l(T1),ws=w_satT_s(T1);
            w1=wl+(ws-wl)*x;
        }
        if(T2!=-1)
        {
            double wl=w_satT_l(T2),ws=w_satT_s(T2);
            w2=wl+(ws-wl)*x;
        }
        return;
    }
    //////////////////////////////////////////////
    ////根据x,s确定其他值
    double FTsx(double s,double x,double T)
    {
        double sl=s_satT_l(T),ss=s_satT_s(T);
        double sx=sl+(ss-sl)*x;
        return sx-s;
    }
    void T_sx(double s,double x,double &Tsx,double &Txs,double &Tll)
    {
        Tsx=-1,Txs=-1,Tll=-1;
        bool mn=false,mx=false;
        if(x>1||x<0)
            return;
        double gd=(sqrt(5)-1)/2;
        double Tx=273.15,Tm=511,Ty=647.096,Txx,Tyy,Tmm;
        double sx=s_xT(x,Tx),sm=s_xT(x,Tm),sy=s_xT(x,Ty),sxx,syy,smm;
        double smx,smn,Tmx,Tmn;
        sxx=sx,syy=sy,smm=sm,Txx=Tx,Tyy=Ty,Tmm=Tm;
        if(x>0.3657247&&x<0.565588196715)
        {
            double Tl=Tx+(1-gd)*(Tm-Tx);
            double Tr=Tx+gd*(Tm-Tx);
            double	sl=s_xT(x,Tl),sr=s_xT(x,Tr);
            while(abs((Tm-Tx)/Tm)>=err)
            {
                if(sl>sr)
                {
                    sx=sl;
                    Tx=Tl;
                    sl=sr;
                    Tl=Tr;
                    Tr=Tx+gd*(Tm-Tx);
                    sr=s_xT(x,Tr);
                }
                else
                {
                    sm=sr;
                    Tm=Tr;
                    sr=sl;
                    Tr=Tl;
                    Tl=Tx+(1-gd)*(Tm-Tx);
                    sl=s_xT(x,Tl);
                }
            }
            smn=sm;
            Tmn=Tm;
            mn=true;
        }
        if(x>0.419888&&x<0.565588196715)
        {
            double Tl=Ty+(1-gd)*(Tm-Ty);
            double Tr=Ty+gd*(Tm-Ty);
            double	sl=s_xT(x,Tl),sr=s_xT(x,Tr);
            while(abs((Ty-Tm)/Ty)>=err)
            {
                if(sl<sr)
                {
                    sy=sl;
                    Ty=Tl;
                    sl=sr;
                    Tl=Tr;
                    Tr=Ty+gd*(Tm-Ty);
                    sr=s_xT(x,Tr);
                }
                else
                {
                    sm=sr;
                    Tm=Tr;
                    sr=sl;
                    Tr=Tl;
                    Tl=Ty+(1-gd)*(Tm-Ty);
                    sl=s_xT(x,Tl);
                }
            }
            smx=sm;
            Tmx=Tm;
            mx=true;
        }
        if(mn&&(!mx))
        {
            if(s>=smn)
            {
                if(s<=sxx)
                {
                    double T1=Tmn,T2=Txx,Tm;
                    double F1=FTsx(s,x,T1),F2=FTsx(s,x,T2),Fm;
                    while((F2*F1<=0)&&abs((T1-T2)/T1)>=err)
                    {
                        Tm=(T1+T2)/2;
                        Fm=FTsx(s,x,Tm);
                        if(F1*Fm<0)
                        {
                            T2=Tm;
                            F2=Fm;
                        }
                        else
                        {
                            T1=Tm;
                            F1=Fm;
                        }
                    }
                    Tll=T1;
                }
                if(s<=syy)
                {
                    double T1=Tmn,T2=Tyy,Tm;
                    double F1=FTsx(s,x,T1),F2=FTsx(s,x,T2),Fm;
                    while((F2*F1<=0)&&abs((T1-T2)/T1)>=err)
                    {
                        Tm=(T1+T2)/2;
                        Fm=FTsx(s,x,Tm);
                        if(F1*Fm<0)
                        {
                            T2=Tm;
                            F2=Fm;
                        }
                        else
                        {
                            T1=Tm;
                            F1=Fm;
                        }
                    }
                    Tsx=T1;
                }
            }
            return;
        }
        if(mn&&mx)
        {
            if(s>=smn)
            {
                if(s<=sxx)
                {
                    double T1=Tmn,T2=Txx,Tm;
                    double F1=FTsx(s,x,T1),F2=FTsx(s,x,T2),Fm;
                    while((F2*F1<=0)&&abs((T1-T2)/T1)>=err)
                    {
                        Tm=(T1+T2)/2;
                        Fm=FTsx(s,x,Tm);
                        if(F1*Fm<0)
                        {
                            T2=Tm;
                            F2=Fm;
                        }
                        else
                        {
                            T1=Tm;
                            F1=Fm;
                        }
                    }
                    Tll=T1;
                }
                if(s<=smx)
                {
                    double T1=Tmn,T2=Tmx,Tm;
                    double F1=FTsx(s,x,T1),F2=FTsx(s,x,T2),Fm;
                    while((F2*F1<=0)&&abs((T1-T2)/T1)>=err)
                    {
                        Tm=(T1+T2)/2;
                        Fm=FTsx(s,x,Tm);
                        if(F1*Fm<0)
                        {
                            T2=Tm;
                            F2=Fm;
                        }
                        else
                        {
                            T1=Tm;
                            F1=Fm;
                        }
                    }
                    Txs=T1;
                }
            }
            if(s<smx&&s>syy)
            {	
                double T1=Tyy,T2=Tmx,Tm;
                double F1=FTsx(s,x,T1),F2=FTsx(s,x,T2),Fm;
                while((F2*F1<=0)&&abs((T1-T2)/T1)>=err)
                {
                    Tm=(T1+T2)/2;
                    Fm=FTsx(s,x,Tm);
                    if(F1*Fm<0)
                    {
                        T2=Tm;
                        F2=Fm;
                    }
                    else
                    {
                        T1=Tm;
                        F1=Fm;
                    }
                }
                Tsx=T1;
            }
            return;
        }
        if(sxx>syy)
        {
            Tmx=Txx;
            smx=sxx;
            Tmn=Tyy;
            smn=syy;
        }
        else
        {
            Tmx=Tyy;
            smx=syy;
            Tmn=Txx;
            smn=sxx;
        }
        if(s>=smn&&s<=smx)
        {
            double T1=Tmn,T2=Tmx,Tm;
            double F1=FTsx(s,x,T1),F2=FTsx(s,x,T2),Fm;
            while(F1*F2<=0&&abs((T2-T1)/T2)>=err)
            {
                Tm=(T1+T2)/2;
                Fm=FTsx(s,x,Tm);
                if(Fm*F1<0)
                {
                    T2=Tm;
                    F2=Fm;
                }
                else
                {
                    F1=Fm;
                    T1=Tm;
                }
            }
            Tsx=T1;
            return;
        }
        return;
    }
    ///压力
    void p_sx(double s,double x,double &p1,double &p2,double &p3)
    {
        p1=-1,p2=-1,p3=-1;
        double T1,T2,T3;
        T_sx(s,x,T1,T2,T3);
        if(T1!=-1)
            p1=p_satT(T1);
        if(T2!=-1)
            p2=p_satT(T2);
        if(T3!=-1)
            p3=p_satT(T3);
        return;
    }
    ///比容
    void v_sx(double s,double x,double &v1,double &v2,double &v3)
    {
        v1=-1,v2=-1,v3=-1;
        double T1,T2,T3;
        T_sx(s,x,T1,T2,T3);
        if(T1!=-1)
        {
            double vl=v_satT_l(T1),vs=v_satT_s(T1);
            v1=vl+(vs-vl)*x;
        }
        if(T2!=-1)
        {
            double vl=v_satT_l(T2),vs=v_satT_s(T2);
            v2=vl+(vs-vl)*x;
        }
        if(T3!=-1)
        {
            double vl=v_satT_l(T3),vs=v_satT_s(T3);
            v3=vl+(vs-vl)*x;
        }
        return;
    }
    ////焓值
    void h_sx(double s,double x,double &h1,double &h2,double &h3)
    {
        h1=-1,h2=-1,h3=-1;
        double T1,T2,T3;
        T_sx(s,x,T1,T2,T3);
        if(T1!=-1)
        {
            double hl=h_satT_l(T1),hs=h_satT_s(T1);
            h1=hl+(hs-hl)*x;
        }
        if(T2!=-1)
        {
            double hl=h_satT_l(T2),hs=h_satT_s(T2);
            h2=hl+(hs-hl)*x;
        }
        if(T3!=-1)
        {
            double hl=h_satT_l(T3),hs=h_satT_s(T3);
            h3=hl+(hs-hl)*x;
        }
        return;
    }
    ////内能
    void u_sx(double s,double x,double &u1,double &u2,double &u3)
    {
        u1=-1,u2=-1,u3=-1;
        double T1,T2,T3;
        T_sx(s,x,T1,T2,T3);
        if(T1!=-1)
        {
            double ul=u_satT_l(T1),us=u_satT_s(T1);
            u1=ul+(us-ul)*x;
        }
        if(T2!=-1)
        {
            double ul=u_satT_l(T2),us=u_satT_s(T2);
            u2=ul+(us-ul)*x;
        }
        if(T3!=-1)
        {
            double ul=u_satT_l(T3),us=u_satT_s(T3);
            u3=ul+(us-ul)*x;
        }
        return;
    }
    ////等压比热容
    void cp_sx(double s,double x,double &cp1,double &cp2,double &cp3)
    {
        cp1=-1,cp2=-1,cp3=-1;
        double T1,T2,T3;
        T_sx(s,x,T1,T2,T3);
        if(T1!=-1)
        {
            double cpl=cp_satT_l(T1),cps=cp_satT_s(T1);
            cp1=cpl+(cps-cpl)*x;
        }
        if(T2!=-1)
        {
            double cpl=cp_satT_l(T2),cps=cp_satT_s(T2);
            cp2=cpl+(cps-cpl)*x;
        }
        if(T3!=-1)
        {
            double cpl=cp_satT_l(T3),cps=cp_satT_s(T3);
            cp3=cpl+(cps-cpl)*x;
        }
        return;
    }
    ////等容比热容
    void cv_sx(double s,double x,double &cv1,double &cv2,double &cv3)
    {
        cv1=-1,cv2=-1,cv3=-1;
        double T1,T2,T3;
        T_sx(s,x,T1,T2,T3);
        if(T1!=-1)
        {
            double cvl=cv_satT_l(T1),cvs=cv_satT_s(T1);
            cv1=cvl+(cvs-cvl)*x;
        }
        if(T2!=-1)
        {
            double cvl=cv_satT_l(T2),cvs=cv_satT_s(T2);
            cv2=cvl+(cvs-cvl)*x;
        }
        if(T3!=-1)
        {
            double cvl=cv_satT_l(T3),cvs=cv_satT_s(T3);
            cv3=cvl+(cvs-cvl)*x;
        }
        return;
    }
    ////声速
    void w_sx(double s,double x,double &w1,double &w2,double &w3)
    {
        w1=-1,w2=-1,w3=-1;
        double T1,T2,T3;
        T_sx(s,x,T1,T2,T3);
        if(T1!=-1)
        {
            double wl=w_satT_l(T1),ws=w_satT_s(T1);
            w1=wl+(ws-wl)*x;
        }
        if(T2!=-1)
        {
            double wl=w_satT_l(T2),ws=w_satT_s(T2);
            w2=wl+(ws-wl)*x;
        }
        if(T3!=-1)
        {
            double wl=w_satT_l(T3),ws=w_satT_s(T3);
            w3=wl+(ws-wl)*x;
        }
        return;
    }

    double Atr_rhoT(double rho,double T)
    {
        double	rr=rho/317.763;
        double tt=647.226/T;
        double n_0[4]={1,0.978197,0.579829,-0.202354};
        double n_1[19]={0.5132047,0.3205656,-0.7782567,0.1885447,0.2151778,0.7317883,0.1241044e1,0.1476783e1,-0.2818107,-0.1070786e1,-0.1263184e1,0.1778064,0.460504,0.2340379,-0.4924179,-0.4176610e-1,0.1600435,-0.1578386e-1,-0.3629481e-2};
        double I_1[19]={0,0,0,0,1,1,1,1,2,2,2,3,3,3,3,4,4,5,6};
        double J_1[19]={0,1,4,5,0,1,2,3,0,1,2,0,1,2,3,0,3,1,3};
        double atr1=0,atr2=0;
        int i;
        for(i=0;i<4;i++)
            atr1+=n_0[i]*pow(tt,i);
        atr1*=sqrt(tt);
        atr1=1/atr1;
        for(i=0;i<19;i++)
            atr2+=n_1[i]*pow((rr-1),I_1[i])*pow((tt-1),J_1[i]);
        atr2*=rr;
        atr2=exp(atr2);
        double atr=atr1*atr2*55.071e-6;
        return atr;
    }
    ////导热系数
    double lmd_satT_l(double T)
    {
        double p=p_4T(T);
        double lmd,lmd0,lmd1;
        double A,B;
        double rr,rho;
        double tt=647.226/T;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
            {
                rho=1/v_1pT(p,T);
                rr=rho/317.763;
                double n_0[4]={1,6.978267,2.599096,-0.998254};
                double n_1[6][5]={{0.13293046e1,0.17018363e1,0.52246158e1,0.87127675e1,-0.18525999e1},{-0.40452437,-0.22156845e1,-0.10124111e2,-0.95000611e1,0.93404690},{0.24409490,0.16511057e1,0.49874687e1,0.43786606e1,0},{0.18660751e-1,-0.76736002,-0.27297694,-0.91783782,0},{-0.12961068,0.37283344,-0.43083393,0,0},{0.44809953e-1,-0.1120316,0.13333849,0,0}};
                lmd0=0;
                int i;
                for(i=0;i<4;i++)
                    lmd0+=n_0[i]*pow(tt,i);
                lmd0*=sqrt(tt);
                lmd0=1/lmd0;
                lmd1=0;
                int j;
                for(i=0;i<6;i++)
                {
                    for(j=0;j<5;j++)
                        lmd1+=n_1[i][j]*pow((tt-1),j)*pow((rr-1),i);
                }
                lmd1*=rr;
                lmd1=exp(lmd1);
                A=pow(16.53/22.115*1386/647.226*v_1t(p,T)/v_1p(p,T)*tt*tt,2);
                B=pow((-22.115/16.53*317.763*rr*rr*rr*v_1p(p,T)),0.4678);

            }
            else
            {
                rho=rho_3pT(p,T);
                rr=rho/317.763;
                double n_0[4]={1,6.978267,2.599096,-0.998254};
                double n_1[6][5]={{0.13293046e1,0.17018363e1,0.52246158e1,0.87127675e1,-0.18525999e1},{-0.40452437,-0.22156845e1,-0.10124111e2,-0.95000611e1,0.93404690},{0.24409490,0.16511057e1,0.49874687e1,0.43786606e1,0},{0.18660751e-1,-0.76736002,-0.27297694,-0.91783782,0},{-0.12961068,0.37283344,-0.43083393,0,0},{0.44809953e-1,-0.1120316,0.13333849,0,0}};
                lmd0=0;
                int i;
                for(i=0;i<4;i++)
                    lmd0+=n_0[i]*pow(tt,i);
                lmd0*=sqrt(tt);
                lmd0=1/lmd0;
                lmd1=0;
                int j;
                for(i=0;i<6;i++)
                {
                    for(j=0;j<5;j++)
                        lmd1+=n_1[i][j]*pow((tt-1),j)*pow((rr-1),i);
                }
                lmd1*=rr;
                lmd1=exp(lmd1);
                A=pow(1/22.115*647.096/647.226*p_3t(rho,T)*tt*tt,2);
                B=pow((322/317.763*22.115*rr*1/p_3rho(rho,T)),0.4678);
            }
        }
        else
            return -1;
        lmd=0.0013848/Atr_rhoT(rho,T)*(55.071e-6)*pow(tt*rr,-2)*A*B*pow(rr,0.5)*exp(-18.66*pow((1/tt-1),2)-pow((rr-1),4));
        return (lmd0*lmd1+lmd)*0.4945;
    }
    double lmd_satT_s(double T)
    {
        double p=p_4T(T);
        double lmd,lmd0,lmd1;
        double A,B;
        double rr,rho;
        double tt=647.226/T;
        if(T>=273.15&&T<=647.096)
        {
            if(T<=623.15)
            {
                rho=1/v_2pT(p,T);
                rr=rho/317.763;
                double n_0[4]={1,6.978267,2.599096,-0.998254};
                double n_1[6][5]={{0.13293046e1,0.17018363e1,0.52246158e1,0.87127675e1,-0.18525999e1},{-0.40452437,-0.22156845e1,-0.10124111e2,-0.95000611e1,0.93404690},{0.24409490,0.16511057e1,0.49874687e1,0.43786606e1,0},{0.18660751e-1,-0.76736002,-0.27297694,-0.91783782,0},{-0.12961068,0.37283344,-0.43083393,0,0},{0.44809953e-1,-0.1120316,0.13333849,0,0}};
                lmd0=0;
                int i;
                for(i=0;i<4;i++)
                    lmd0+=n_0[i]*pow(tt,i);
                lmd0*=sqrt(tt);
                lmd0=1/lmd0;
                lmd1=0;
                int j;
                for(i=0;i<6;i++)
                {
                    for(j=0;j<5;j++)
                        lmd1+=n_1[i][j]*pow((tt-1),j)*pow((rr-1),i);
                }
                lmd1*=rr;
                lmd1=exp(lmd1);
                A=pow(1/22.115*540/647.226*v_2t(p,T)/v_2p(p,T)*tt*tt,2);
                B=pow((-22.115/1*317.763*rr*rr*rr*v_2p(p,T)),0.4678);
            }
            else
            {
                rho=rho_3T_sat(T);
                rr=rho/317.763;
                double n_0[4]={1,6.978267,2.599096,-0.998254};
                double n_1[6][5]={{0.13293046e1,0.17018363e1,0.52246158e1,0.87127675e1,-0.18525999e1},{-0.40452437,-0.22156845e1,-0.10124111e2,-0.95000611e1,0.93404690},{0.24409490,0.16511057e1,0.49874687e1,0.43786606e1,0},{0.18660751e-1,-0.76736002,-0.27297694,-0.91783782,0},{-0.12961068,0.37283344,-0.43083393,0,0},{0.44809953e-1,-0.1120316,0.13333849,0,0}};
                lmd0=0;
                int i;
                for(i=0;i<4;i++)
                    lmd0+=n_0[i]*pow(tt,i);
                lmd0*=sqrt(tt);
                lmd0=1/lmd0;
                lmd1=0;
                int j;
                for(i=0;i<6;i++)
                {
                    for(j=0;j<5;j++)
                        lmd1+=n_1[i][j]*pow((tt-1),j)*pow((rr-1),i);
                }
                lmd1*=rr;
                lmd1=exp(lmd1);
                A=pow(1/22.115*647.096/647.226*p_3t(rho,T)*tt*tt,2);
                B=pow((322/317.763*22.115*rr*1/p_3rho(rho,T)),0.4678);
            }
        }
        else
            return -1;
        lmd=0.0013848/Atr_rhoT(rho,T)*(55.071e-6)*pow(tt*rr,-2)*A*B*pow(rr,0.5)*exp(-18.66*pow((1/tt-1),2)-pow((rr-1),4));
        return (lmd0*lmd1+lmd)*0.4945;
    }
    double Lmd_rhoT(double rho,double T)
    {
        double rr=rho/317.763;
        double tt=647.226/T;
        double p=p_vT(1/rho,T);
        double n_0[4]={1,6.978267,2.599096,-0.998254};
        double n_1[6][5]={{0.13293046e1,0.17018363e1,0.52246158e1,0.87127675e1,-0.18525999e1},{-0.40452437,-0.22156845e1,-0.10124111e2,-0.95000611e1,0.93404690},{0.24409490,0.16511057e1,0.49874687e1,0.43786606e1,0},{0.18660751e-1,-0.76736002,-0.27297694,-0.91783782,0},{-0.12961068,0.37283344,-0.43083393,0,0},{0.44809953e-1,-0.1120316,0.13333849,0,0}};
        double lmd0=0;
        int i;
        for(i=0;i<4;i++)
            lmd0+=n_0[i]*pow(tt,i);
        lmd0*=sqrt(tt);
        lmd0=1/lmd0;
        double lmd1=0;
        int j;
        for(i=0;i<6;i++)
        {
            for(j=0;j<5;j++)
                lmd1+=n_1[i][j]*pow((tt-1),j)*pow((rr-1),i);
        }
        lmd1*=rr;
        lmd1=exp(lmd1);
        double lmd2=0;
        double A,B;
        double v=1/rho;
        if(T>=273.15&&T<=647.096&&v<v_satT_s(T)&&v>v_satT_l(T))
        {
            double vs=v_satT_s(T),vl=v_satT_l(T);
            double x=(v-vl)/(vs-vl);
            double lmds=lmd_satT_s(T),lmdl=lmd_satT_l(T);
            return lmdl+(lmds-lmdl)*x;
        }
        if((T>=273.15)&&(T<=623.15)&&(p>=p_4T(T))&&(p<=100))
        {
            A=pow(16.53/22.115*1386/647.226*v_1t(p,T)/v_1p(p,T)*tt*tt,2);
            B=pow((-22.115/16.53*317.763*rr*rr*rr*v_1p(p,T)),0.4678);
        }
        else 
            if(((T>=273.15)&&(T<=623.15)&&(p>=0)&&(p<=p_4T(T)))||((T>=623.15)&&(T<=863.15)&&(p>=0)&&(p<=p_23T(T)))||((T>=863.15)&&(T<=1073.15)&&(p>=0)&&(p<=100)))
            {
                A=pow(1/22.115*540/647.226*v_2t(p,T)/v_2p(p,T)*tt*tt,2);
                B=pow((-22.115/1*317.763*rr*rr*rr*v_2p(p,T)),0.4678);
            }
            else
                if((T>=623.15)&&(T<=T_23p(p))&&(p>=p_23T(T))&&(p<=100))
                {
                    A=pow(1/22.115*647.096/647.226*p_3t(rho,T)*tt*tt,2);
                    B=pow((322/317.763*22.115*rr*1/p_3rho(rho,T)),0.4678);
                }
                else
                    return -1;
        lmd2=0.0013848/Atr_rhoT(rho,T)*(55.071e-6)*pow(tt*rr,-2)*A*B*pow(rr,0.5)*exp(-18.66*pow((1/tt-1),2)-pow((rr-1),4));
        double lmd=(lmd0*lmd1+lmd2)*0.4945;
        return lmd;
    }
    /////表面张力
    double Sgm_T(double T)
    {
        double tht=T/647.096;
        double sgm=235.8*pow((1-tht),1.256)*(1-0.625*(1-tht));
        return sgm;
    }
    /////介电常数
    double Ecs_rhoT(double rho,double T)
    {
        double rr=rho/322,tt=647.096/T,k=1.380658e-23,Na=6.0221367e23,a=1.636e-40,ecs0=8.854187817e-12,miu=6.138e-30,M=18.015257;
        double I[12]={1,1,1,2,3,3,4,5,6,7,10,0};
        double J[12]={0.25,1,2.5,1.5,1.5,2.5,2,2,5,0.5,10,0};
        double n[12]={0.978224486826,-0.957771379375,0.237511794148,0.714692244396,-0.298217036956,-0.108863472196,0.949327488264e-1,-0.980469816509e-2,0.165167634970e-4,0.937359795772e-4,-0.123179218720e-9,0.196096504426e-2};
        double g=0;
        int i;
        for(i=0;i<11;i++)
            g+=n[i]*pow(rr,I[i])*pow(tt,J[i]);
        g+=(1+n[11]*rr*pow((T/228-1),-1.2));
        double A=1000*Na*pow(miu,2)*rho*g/M/ecs0/k/T;
        double B=1000*Na*a*rho/3/M/ecs0;
        double ecs=(1+A+5*B+sqrt(9+2*A+18*B+A*A+10*A*B+9*B*B))/(4-4*B);
        return ecs;
    }
    //////折射率
    double n_rhoTL(double rho,double T,double Lamd)
    {
        double rr=rho/1000;
        double tht=T/273.15;
        double L=Lamd/0.589;
        double n[8]={0.244257733,0.974634476e-2,-0.373234996e-2,0.268678472e-3,0.158920570e-2,0.245934259e-2,0.900704920,-0.166626219e-1};
        double A=rr*(n[0]+n[1]*rr+n[2]*tht+n[3]*L*L*tht+n[4]*pow(L,-2)+n[5]/(L*L-pow(0.229202,2))+n[6]/(L*L-pow(5.432937,2))+n[7]*rr*rr);
        return sqrt((2*A+1)/(1-A));
    }
}