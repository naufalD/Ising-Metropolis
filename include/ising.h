#ifndef ISING_H
#define ISING_H

#include <vector>

using std::vector;

class Ising
{
public:
    Ising(int sizeX, int sizeY, double J, double temp);
private:
    void m_update();
    double m_boltzmann(double E);
    double m_getEnergy();

    vector<bool> m_space;
    int m_sizeX;
    int m_sizeY;
    double m_J;
    double m_temp;
    double m_energy;

};

#endif // ISING_H
