
#include "Utils/GaussianModel.h"

const GaussianModel GaussianModel::ZERO(0.0, 0.0);

GaussianModel::GaussianModel(double iMean,double iVariance):Mean(iMean),
    Variance(iVariance){

}
