#ifndef SimTotem_RPDigiProducer_RP_ENERGY_DEPOSIT_UNIT_H
#define SimTotem_RPDigiProducer_RP_ENERGY_DEPOSIT_UNIT_H

#include "DataFormats/GeometryVector/interface/LocalPoint.h"
#include "DataFormats/GeometryVector/interface/LocalVector.h"

/**
 * Class which allows to "follow" an elementary charge in the silicon.
 * It basically defines a quantum of energy, with a position.
 */
class RPEnergyDepositUnit{
 public:
  RPEnergyDepositUnit(): _energy(0),_position(0,0,0){}
  RPEnergyDepositUnit(double energy, double x, double y, double z):
    _energy(energy),_position(x,y,z){}
  RPEnergyDepositUnit(double energy, const Local3DPoint &position):
    _energy(energy),_position(position){}
  inline double X() const{return _position.x();}
  inline double Y() const{return _position.y();}
  inline double Z() const{return _position.z();}
  inline double & Energy() { return _energy;}
  inline double Energy() const { return _energy;}
  inline Local3DPoint Position() const { return _position;}
  inline Local3DPoint& Position() { return _position;}
  
 private:
  double _energy;
  Local3DPoint _position;
};


#endif  //SimTotem_RPDigiProducer_RP_ENERGY_DEPOSIT_UNIT_H
