#include "include/ising.h"

Ising::Ising(int sizeX, int sizeY, double J, double temp) {
    m_space = vector<bool>(sizeX*sizeY, 1);
    m_sizeX = sizeX;
    m_sizeY = sizeY;
    m_J = J;
    m_temp = temp;
    m_energy = m_getEnergy();
}

double Ising::m_boltzmann(double E){
    return exp(-(E-m_energy)/(m_temp*1.38*pow(10, -23)));
}

double Ising::m_getEnergy(){
    float energy {0};
    for (int j {0}; j<m_sizeY;++j){
        for (int i {0}; i<m_sizeX;++i){
            float spinCurr {0};

            if (m_space[i*m_sizeX+j*m_sizeY] == 1) spinCurr = 0.5;
            else spinCurr = -0.5;

            if (i!=0){
                if (m_space[(i-1)*m_sizeX+j*m_sizeY]==1) energy += spinCurr*0.5;
                else energy+= spinCurr*-0.5;
            }
            if (i!=m_sizeX-1){
                if (m_space[(i+1)*m_sizeX+j*m_sizeY]==1) energy += spinCurr*0.5;
                else energy+= spinCurr*-0.5;
            }
            if (j!=0){
                if (m_space[i*m_sizeX+(j-1)*m_sizeY]==1) energy += spinCurr*0.5;
                else energy+= spinCurr*-0.5;
            }
            if (j!=m_sizeY-1){
                if (m_space[i*m_sizeX+(j+1)*m_sizeY]==1) energy += spinCurr*0.5;
                else energy+= spinCurr*-0.5;
            }

        }
    }

    return energy;
}

void Ising::m_update(){
    int rand1 {0};
    int energyTemp {0};

    rand1 = arc4random() / pow(2,32)*m_sizeX*m_sizeY;

    if (m_space[rand1] == 1) m_space[rand1] = 0;
    else m_space[rand1] = 1;

    energyTemp = m_getEnergy();

    if (energyTemp <= m_energy) m_energy = energyTemp;
    else{
        double rand2 {arc4random()/pow(2,32)};
        if (m_boltzmann(energyTemp)>=rand2) m_energy = energyTemp;
        else{
            if (m_space[rand1] == 1) m_space[rand1] = 0;
            else m_space[rand1] = 1;
        }
    }
}
