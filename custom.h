#pragma once//---------------------------------------------------------------------------



#include "model.h"

//---------------------------------------------------------------------------
// Задача Аренсторфа (начальные условия 1)

class TArenstorfModel  : public TModel
{
    protected:
        static const long double m;
        long double D1, D2;
    public:
        TArenstorfModel(  );
        void getRight( const TVector& X, long double t, TVector& Y );
};


//---------------------------------------------------------------------------
// Задача Аренсторфа (начальные условия 2)

class TArenstorfModel2 : public TArenstorfModel
{
    public:
        TArenstorfModel2(  );
};
//---------------------------------------------------------------------------

/* Математические маятники	*/

class MathPendulum : public TModel
{
    protected:
        static const double g;
        double l, dE, m;


    public:
        MathPendulum();

        void getRight( const TVector& X, long double t, TVector& Y );
};

//---------------------------------------------------------------------------


/* Пружинные маятники	*/

class SpringPendulum : public TModel
{
    protected:
        static const double g;
        double k, mu1, mu2, m;


    public:
        SpringPendulum();

        void getRight( const TVector& X, long double t, TVector& Y );
};
