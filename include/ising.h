#ifndef ISING_H
#define ISING_H

#include <vector>

using std::vector;

class Ising
{
public:
    Ising(int sizeX, int sizeY, double J, double temp);
    bool getPoint(int X, int Y);
    double getEnergy();
    double getMagnetization();
    void updateSpace();

private:
    double m_boltzmann(double E);
    void m_setEnergy();
    double m_getEnergyComp(int index);
    void m_setMagnetization();

    vector<bool> m_space;
    int m_sizeX;
    int m_sizeY;
    double m_J;
    double m_temp;
    double m_energy;
    double m_magnetization;

};

#endif // ISING_H
