#include "include/ising.h"

Ising::Ising(int sizeX, int sizeY, double J, double temp) {
    m_space.resize(sizeX*sizeY);
    std::fill(begin(m_space), end(m_space), true);
    m_sizeX = sizeX;
    m_sizeY = sizeY;

    // for (int j {0}; j<sizeY;++j){
    //     for (int i {0}; i<sizeX;++i){
    //         double tempRand {arc4random()/pow(2,32)};
    //         if (tempRand<0.4) m_space[i*m_sizeX + j] = 1;
    //         else m_space[i*m_sizeX + j]=0;
    //     }
    // }


    m_J = J;
    m_temp = temp;
    m_energy = m_getEnergy();
}

bool Ising::getPoint(int X, int Y){
    return m_space[X*m_sizeX+Y];
}

double Ising::getEnergy(){
    return m_energy;
}

void Ising::updateSpace(){
    for (int i {0}; i<1000;++i){
        int rand1 {0};
        int energyTemp {0};

        rand1 = arc4random() / (pow(2,32)-1)*((m_sizeX)*(m_sizeY)-1);

        if (m_space[rand1] == 1) m_space[rand1] = 0;
        else m_space[rand1] = 1;

        energyTemp = m_getEnergyComp(rand1);

        if (energyTemp > 0) continue;
        else{
            double rand2 {arc4random()/pow(2,32)};
            if (rand2<m_boltzmann(energyTemp)) continue;
            else{
                if (m_space[rand1] == 1) m_space[rand1] = 0;
                else m_space[rand1] = 1;
            }
        }
    }
    m_energy = m_getEnergy();
}


double Ising::m_boltzmann(double E){
    return exp(2*E/(m_temp));
}

double Ising::m_getEnergy(){
    float energy {0};
    for (int j {0}; j<m_sizeY;++j){
        for (int i {0}; i<m_sizeX;++i){
            float spinCurr {0};
            float energyTemp {0};

            if (m_space[i*m_sizeX+j] == 1) spinCurr = 0.5;
            else spinCurr = -0.5;

            if (i!=0){
                if (m_space[(i-1)*m_sizeX+j]==1) energyTemp += 0.5;
                else energyTemp += -0.5;

            }
            else{
                if (m_space[m_sizeX-1+j]==1) energyTemp += 0.5;
                else energyTemp+= -0.5;
            }

            if (i!=m_sizeX-1){
                if (m_space[(i+1)*m_sizeX+j]==1) energyTemp += 0.5;
                else energyTemp+= -0.5;

            }
            else{
                if (m_space[j]==1) energyTemp += 0.5;
                else energyTemp+= -0.5;
            }

            if (j!=0){
                if (m_space[i*m_sizeX+(j-1)]==1) energyTemp += 0.5;
                else energyTemp+= -0.5;
            }
            else{
                if (m_space[i*m_sizeX+(m_sizeY-1)]==1) energyTemp += 0.5;
                else energyTemp+= -0.5;
            }

            if (j!=m_sizeY-1){
                if (m_space[i*m_sizeX+(j+1)]==1) energyTemp += 0.5;
                else energyTemp+= -0.5;
            }
            else{
                if (m_space[i*m_sizeX]==1) energyTemp += 0.5;
                else energyTemp+= -0.5;
            }
            energy += energyTemp*spinCurr;
        }
    }

    return -m_J*energy;
}

double Ising::m_getEnergyComp(int index){
    int j = index%m_sizeX;
    int i = (index-j)/m_sizeX;
    float energyTemp {0};
    float spinCurr {0};

    if (m_space[i*m_sizeX+j] == 1) spinCurr = 1;
    else spinCurr = -1;

    if (i!=0){
        if (m_space[(i-1)*m_sizeX+j]==1) energyTemp += 1;
        else energyTemp += -1;

    }
    else{
        if (m_space[m_sizeX-1+j]==1) energyTemp += 1;
        else energyTemp+= -1;
    }

    if (i!=m_sizeX-1){
        if (m_space[(i+1)*m_sizeX+j]==1) energyTemp += 1;
        else energyTemp+= -1;

    }
    else{
        if (m_space[j]==1) energyTemp += 1;
        else energyTemp+= -1;
    }

    if (j!=0){
        if (m_space[i*m_sizeX+(j-1)]==1) energyTemp += 1;
        else energyTemp+= -1;
    }
    else{
        if (m_space[i*m_sizeX+(m_sizeY-1)]==1) energyTemp += 1;
        else energyTemp+= -1;
    }

    if (j!=m_sizeY-1){
        if (m_space[i*m_sizeX+(j+1)]==1) energyTemp += 1;
        else energyTemp+= -1;
    }
    else{
        if (m_space[i*m_sizeX]==1) energyTemp += 1;
        else energyTemp+= -1;
    }
    return -m_J*energyTemp*spinCurr;
}
