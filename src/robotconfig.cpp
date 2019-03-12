#include"robotconfig.h"
#include"stdio.h"
#include<math.h>
#include<array>

using namespace CONFIG;



double t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17;
double t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32;
double t33, t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47;
double t48, t49, t50, t51, t52, t53, t54, t55, t56, t57, t58, t59, t60, t61, t62;
double t63, t64, t65, t66, t67, t68, t69, t70, t71, t72, t73, t74, t75, t76, t77;
double A0[6][6], B0[4][4];
double dTheta[6];
double MC1, MC2, MC3;
robotconfig::robotconfig()
    {

	     
    }


 void robotJacobian(std::array<double, 6> &q)
        {
	 double t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15, t16, t17;
	 double t18, t19, t20, t21, t22, t23, t24, t25, t26, t27, t28, t29, t30, t31, t32;
	 double t33, t34, t35, t36, t37, t38, t39, t40, t41, t42, t43, t44, t45, t46, t47;
	 double t48, t49, t50, t51, t52, t53, t54, t55, t56, t57, t58, t59, t60, t61, t62;
	 double t63, t64, t65, t66, t67, t68, t69, t70, t71, t72, t73, t74, t75, t76, t77;
            double q1, q2, q3, q4, q5, q6;
			
            q1 = q[0]  * DirectionFlag[0] + JointOffset[0] + ZeroOffset[0];
            q2 = q[1]  * DirectionFlag[1] + JointOffset[1] + ZeroOffset[1];
            q3 = q[2]  * DirectionFlag[2] + JointOffset[2] + ZeroOffset[2];
            q4 = q[3]  * DirectionFlag[3] + JointOffset[3] + ZeroOffset[3];
            q5 = q[4]  * DirectionFlag[4] + JointOffset[4] + ZeroOffset[4];
            q6 = q[5]  * DirectionFlag[5] + JointOffset[5] + ZeroOffset[5]; 
            
            MC1 = EndPoint[0]; MC2 = EndPoint[1]; MC3 = EndPoint[2];

            for (int i = 0; i < 6; i++)
                for (int j = 0; j < 6; j++)
                    A0[i][j] = 0;

            

            t2 = cos(q6);
            t3 = sin(q6);
            t4 = cos(q5);
            t5 = sin(q5);
            t6 = MC1 * t2;
            t14 = MC2 * t3;
            t7 = t6 - t14;
            t8 = sin(q4);
            t9 = MC2 * t2;
            t10 = MC1 * t3;
            t11 = t9 + t10;
            t12 = cos(q4);
            t13 = MC3 * t5;
            t22 = t4 * t7;
            t15 = t13 - t22;
            t16 = cos(q3);
            t17 = MC3 * t4;
            t18 = t5 * t7;
            t19 = d4 + t17 + t18;
            t20 = sin(q3);
            t21 = t8 * t11;
            t23 = t12 * t15;
            t24 = -a4 + t21 + t23;
            t25 = cos(q1);
            t26 = sin(q2);
            t27 = t19 * t20;
            t28 = t16 * t24;
            t29 = -a3 + t27 + t28;
            t30 = cos(q2);
            t31 = t16 * t19;
            t33 = t20 * t24;
            t32 = t31 - t33;
            t34 = sin(q1);
            t35 = t8 * t15;
            t36 = t17 + t18;
            t37 = t7 * t8;
            t38 = t4 * t11 * t12;
            t39 = t37 + t38;
            t51 = t11 * t12;
            t40 = t35 - t51;
            t41 = t29 * t30;
            t42 = t26 * t32;
            t43 = -a2 + t41 + t42;
            t44 = t26 * t29;
            t46 = t30 * t32;
            t45 = t44 - t46;
            t47 = t27 + t28;
            t48 = t21 + t23;
            t49 = q2 + q3;
            t50 = cos(t49);
            t52 = t15 * t20;
            t68 = t12 * t16 * t36;
            t53 = t52 - t68;
            t54 = t30 * t53;
            t55 = t15 * t16;
            t56 = t12 * t20 * t36;
            t57 = t55 + t56;
            t58 = t26 * t57;
            t59 = t54 + t58;
            t60 = t16 * t39;
            t69 = t5 * t11 * t20;
            t61 = t60 - t69;
            t62 = t20 * t39;
            t63 = t5 * t11 * t16;
            t64 = t62 + t63;
            t65 = t26 * t64;
            t66 = t7 * t12;
            t67 = t66 - t4 * t8 * t11;
            t70 = sin(t49);
            A0[0][0] = -t25 * t40 + t34 * t43;
            A0[0][1] = t25 * t45;
            A0[0][2] = -t25 * (t30 * t32 - t26 * t47);
            A0[0][3] = -t34 * t48 + t25 * t40 * t50;
            A0[0][4] = t25 * t59 - t8 * t34 * t36;
            A0[0][5] = t34 * t67 + t25 * (t65 - t30 * t61);
            A0[1][0] = -t25 * t43 - t34 * t40;
            A0[1][1] = t34 * t45;
            A0[1][2] = -t34 * (t46 - t26 * t47);
            A0[1][3] = t25 * t48 + t34 * t50 * (t35 - t51);
            A0[1][4] = t34 * t59 + t8 * t25 * t36;
            A0[1][5] = -t25 * t67 + t34 * (t65 - t30 * t61);
            A0[2][1] = t41 + t42;
            A0[2][2] = t42 + t30 * t47;
            A0[2][3] = -t40 * t70;
            A0[2][4] = -t26 * t53 + t30 * t57;
            A0[2][5] = t26 * t61 + t30 * t64;
            A0[3][1] = -t34;
            A0[3][2] = -t34;
            A0[3][3] = -t25 * t70;
            A0[3][4] = -t12 * t34 + t8 * t25 * t50;
            A0[3][5] = -t5 * (t8 * t34 + t12 * t25 * t50) - t4 * t25 * t70;
            A0[4][1] = t25;
            A0[4][2] = t25;
            A0[4][3] = -t34 * t70;
            A0[4][4] = t12 * t25 + t8 * t34 * t50;
            A0[4][5] = t5 * (t8 * t25 - t12 * t34 * t50) - t4 * t34 * t70;
            A0[5][0] = 1.0;
            A0[5][3] = -t50;
            A0[5][4] = -t8 * t70;
            A0[5][5] = -t4 * t50 + t5 * t12 * t70;
 
        }


std::array<double, 6> robotconfig::jointIncrement(std::array<double, 6> & q, std::array<double, 6> & dX)
        {
	       std::array<double, 6> dTheta;
	       robotJacobian(q);
		   

            //Matrix<double> pJ = Jacobian.PseudoInverse();
            //Matrix<double> dXM = DenseMatrix.OfArray(dX);//dX:6*1;
            //Matrix<double> dTM = pinvJ * dXM;

            //for (int i = 0; i < 6; i++)
               // dTheta[i] = dTM[i,0];

			
                return dTheta;
        }
		
		void robotTransform(std::array<double, 6> &q)
        {
            double q1, q2, q3, q4, q5, q6;

            q1 = q[0] * ConRad * DirectionFlag[0] + JointOffset[0] + ZeroOffset[0];
            q2 = q[1] * ConRad * DirectionFlag[1] + JointOffset[1] + ZeroOffset[1];
            q3 = q[2] * ConRad * DirectionFlag[2] + JointOffset[2] + ZeroOffset[2];
            q4 = q[3] * ConRad * DirectionFlag[3] + JointOffset[3] + ZeroOffset[3];
            q5 = q[4] * ConRad * DirectionFlag[4] + JointOffset[4] + ZeroOffset[4];
            q6 = q[5] * ConRad * DirectionFlag[5] + JointOffset[5] + ZeroOffset[5];

            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 4; j++)
                    B0[i][j] = 0;

			double DF = EndSensor[2];
            t2 = sin(q1);
            t3 = sin(q4);
            t4 = q2 + q3;
            t5 = cos(t4);
            t6 = cos(q1);
            t7 = cos(q4);
            t8 = cos(q6);
            t9 = t2 * t7;
            t10 = t9 - t3 * t5 * t6;
            t11 = sin(q6);
            t12 = cos(q5);
            t13 = t2 * t3;
            t14 = t5 * t6 * t7;
            t15 = t13 + t14;
            t16 = t12 * t15;
            t17 = sin(t4);
            t18 = sin(q5);
            t19 = t16 - t6 * t17 * t18;
            t20 = t6 * t7;
            t21 = t2 * t3 * t5;
            t22 = t20 + t21;
            t23 = t3 * t6;
            t28 = t2 * t5 * t7;
            t24 = t23 - t28;
            t25 = t12 * t24;
            t26 = t2 * t17 * t18;
            t27 = t25 + t26;
            t29 = t18 * t24;
            t30 = t29 - t2 * t12 * t17;
            t31 = a4 * t5;
            t32 = cos(q2);
            t33 = a3 * t32;
            t34 = a2 + t31 + t33 - d4 * t17;
            t35 = t5 * t18;
            t36 = t7 * t12 * t17;
            t37 = t35 + t36;
            t38 = t7 * t17 * t18;
            B0[0][0] = t10 * t11 + t8 * t19;
            B0[0][1] = t8 * t10 - t11 * t19;
            B0[0][2] = -t15 * t18 - t6 * t12 * t17;
            B0[0][3] = -DF * (t15 * t18 + t6 * t12 * t17) + t6 * t34;
            B0[1][0] = -t11 * t22 - t8 * t27;
            B0[1][1] = -t8 * t22 + t11 * t27;
            B0[1][2] = t30;
            B0[1][3] = DF * t30 + t2 * t34;
            B0[2][0] = -t8 * t37 + t3 * t11 * t17;
            B0[2][1] = t11 * t37 + t3 * t8 * t17;
            B0[2][2] = t38 - t5 * t12;
            B0[2][3] = -a4 * t17 - d4 * t5 - a3 * sin(q2) + DF * (t38 - t5 * t12);
            B0[3][3] = 1.0;
        }


		std::array<double, 3> crossVector(std::array<double, 3> &a, std::array<double, 3> &b)
		{
			std::array<double, 3> c;
			c[0] = a[1] * b[2] - b[1] * a[2];
			c[1] = -(a[0] * b[2] - b[0] * a[2]);
			c[2] = a[0] * b[1] - b[0] * a[1];
			return c;
		}
		std::array<double, 6> robotconfig::forceTransform(std::array<double, 6> &q, std::array<double, 3> &f, std::array<double, 3> &m)
        {
            robotTransform(q);
			std::array<double, 6> NewFrameF;

			std::array<double, 3> n={ B0[0][0], B0[0][1], B0[0][2] };
			std::array<double, 3> o={ B0[1][0], B0[1][1], B0[1][2] };
			std::array<double, 3> a={ B0[2][0], B0[2][1], B0[2][2] };
			std::array<double, 3> p={ B0[0][3], B0[1][3], B0[2][3] };

            NewFrameF[0] = n[0] * f[0] + n[1] * f[1] + n[2] * f[2];
            NewFrameF[1] = o[0] * f[0] + o[1] * f[1] + o[2] * f[2];
            NewFrameF[2] = a[0] * f[0] + a[1] * f[1] + a[2] * f[2];

			std::array<double, 3> crossFP;
            crossFP = crossVector(f, p);
            for (int i = 0; i < 3; i++)
                crossFP[i] = crossFP[i] + m[i];

            NewFrameF[3] = n[0] * crossFP[0] + n[1] * crossFP[1] + n[2] * crossFP[2];
            NewFrameF[4] = o[0] * crossFP[0] + o[1] * crossFP[1] + o[2] * crossFP[2];
            NewFrameF[5] = a[0] * crossFP[0] + a[1] * crossFP[1] + a[2] * crossFP[2];

            return NewFrameF;

        }



