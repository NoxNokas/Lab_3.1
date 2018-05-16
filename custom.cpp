//---------------------------------------------------------------------------

#include "custom.h"
#include <math.h>

#include "array.h"
//---------------------------------------------------------------------------
// ������ ���������� (��������� ������� 1)

const long double TArenstorfModel::m  = 0.012277471;

TArenstorfModel::TArenstorfModel() : TModel()
{
    X0.resize(4);
    X0[0] = 0.994;
    X0[1] = 0;
    X0[2] = 0;
    X0[3] = -2.0015851063790825224053786222;
}

//---------------------------------------------------------------------------

void TArenstorfModel::getRight( const TVector& X, long double t, TVector& Y )
{
    Y.resize(4);
    D1 = pow( pow( X[0] + m, 2 ) + pow( X[1], 2 ), 1.5 );
    D2 = pow( pow( X[0] + m - 1, 2 ) + pow( X[1], 2 ), 1.5 );
    Y[0] = X[2];
    Y[1] = X[3];
    Y[2] = X[0] + 2 * X[3] - (1 - m)*(X[0] + m) / D1 - m * (X[0] + m - 1) / D2;
    Y[3] = X[1] - 2 * X[2] - (1 - m)*X[1] / D1 - m * X[1] / D2;
}

//---------------------------------------------------------------------------
// ������ ���������� (��������� ������� 2)

TArenstorfModel2::TArenstorfModel2() : TArenstorfModel()
{
    X0.resize(4);
    X0[0] = 0.994;
    X0[1] = 0;
    X0[2] = 0;
    X0[3] = -2.0317326295573368357302057924;
}
//---------------------------------------------------------------------------

/* �������������� �������� */

const double MathPendulum::g = 9.81;

MathPendulum::MathPendulum() : TModel()
{
    /*	����� ����	*/
    l = 1;

    /*	�����	*/
    m = 1;

    /*	����������� ������������������ - ��������� ������� � �������	*/
    dE = 0.8;

    X0.resize(2);

    /*	���� ����������	*/
    X0[0] = 0.5236;

    /*	������� �������� */
    X0[1] = 0;
}



/* �������������� ��������: ����� ���������� ������ ����� ����������������� ���������	*/

void MathPendulum::getRight( const TVector& X, long double t, TVector& Y )
{
    extern int pendulum_mod;

    Y.resize(3);

    Y[0] = X[1];

    /*	��������� �������������� ������� */

    if (pendulum_mod == 1)
    {
        Y[1] = -(g/l)*sin(X[0]);
    }

    /*	�������� �������������� �������	*/

    else if (pendulum_mod == 2)
    {
        Y[1] = -g/l*sin(X[0])-(dE*X[1]);
    }
}




//---------------------------------------------------------------------------
/* ��������� ��������	*/

const double SpringPendulum::g = 9.81;

SpringPendulum::SpringPendulum() : TModel()
{
    /*	����������� ��������� �������	*/
    k = 1;

    /*	�����	*/
    m = 1;

    /*	����������� ������ ����������	*/
    mu2 = 0.015;

    /*	����������� ������� ������	*/
    mu1 = 0.4;

    X0.resize(2);

    /*	��������� ���������� �������	*/
    X0[0] = 2;

    /*	��������� ��������	*/
    X0[1] = 0;
}



/* ��������� ��������: ����� ���������� ������ ����� ���������	*/

void SpringPendulum::getRight( const TVector& X, long double t, TVector& Y )
{
    extern int pendulum_mod;

    Y.resize(2);

    Y[0] = X[1];

    /*	��������� ��������� �������	*/
    if (pendulum_mod == 3)
    {
        Y[1] = -((k*X[0])/m);
    }

    /*	�������� ��������� ������� � ������� ��������	*/
    else if (pendulum_mod == 4)
    {
        Y[1] = -((k*X[0])/m)-((mu1*X[1])/m);
    }

    /*	�������� ��������� ������� � ������� ����������	*/
    else if (pendulum_mod == 5)
    {
        if ( X[1] > 0 )
        {
            mu2 = -0.015;
        }
        else if ( X[1] < 0 )
        {
            mu2 = 0.015;
        }
        else
        {
            mu2 = 0;
        }

        Y[1] = (mu2*g)-(k*X[0]/m);
    }
}
