
#ifndef GAUSSIANMODEL_H
#define GAUSSIANMODEL_H

//TODO: Add a radian attribute and make a converter from deg to rad

class GaussianModel
{
public:
    GaussianModel(double iMean = 0.0f, double iFloat = 0.0f);

    double Mean;
    double Variance;

    static const GaussianModel ZERO;
};



#endif
