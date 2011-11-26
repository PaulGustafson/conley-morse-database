// Prism.h
// Shaun Harker
// 9/26/11

#ifndef CHOMP_PRISM_H
#define CHOMP_PRISM_H

#include <iostream>
#include <vector>
#include "boost/serialization/serialization.hpp"
#include "boost/serialization/vector.hpp"
#include "boost/foreach.hpp"

/*********
 * Prism *
 *********/

typedef double Real;

class Prism {
public:
  std::vector < Real > lower_bounds;
  std::vector < Real > upper_bounds;
  Prism ( void ) {};
  Prism ( unsigned int size ) { lower_bounds . resize ( size );
                                upper_bounds . resize ( size ); }
  Prism ( unsigned int size, const Real & value ) 
  { lower_bounds . resize ( size, value );
    upper_bounds . resize ( size, value ); }
  Prism ( unsigned int size, const Real & lower_value, const Real & upper_value )
  { lower_bounds . resize ( size, lower_value );
    upper_bounds . resize ( size, upper_value ); }
  Prism ( unsigned int size, const std::vector<Real> & lower_values, const std::vector<Real> & upper_values )
  { lower_bounds = lower_values;
    upper_bounds = upper_values; }
  bool intersects ( const Prism & other ) const;
private: 
  friend class boost::serialization::access; 
  template<class Archive>
  void save(Archive & ar, const unsigned int version) const
  {
    unsigned int size = lower_bounds . size ();
    ar & size;
    BOOST_FOREACH ( Real x, lower_bounds ) ar & x;
    BOOST_FOREACH ( Real x, upper_bounds ) ar & x;
  }
  template<class Archive>
  void load(Archive & ar, const unsigned int version)
  {
    unsigned int size;
    ar & size;
    lower_bounds . resize ( size );
    upper_bounds . resize ( size );
    for ( unsigned int index = 0; index < size; ++ index ) {
      ar & lower_bounds [ index ];
    } /* for */
    for ( unsigned int index = 0; index < size; ++ index ) {
      ar & upper_bounds [ index ];
    } /* for */
    
  }
  BOOST_SERIALIZATION_SPLIT_MEMBER()
};

typedef Prism Prism; //compatibility

std::ostream & operator << ( std::ostream & output_stream, const Prism & print_me );


///////////// Definitions

// really bad temporary solution
#define TOL 1e-8 

inline bool Prism::intersects ( const Prism & other ) const {
  for ( unsigned int dimension_index = 0; 
        dimension_index < lower_bounds . size (); 
        ++ dimension_index ) {
    if ( upper_bounds [ dimension_index ] + TOL < 
         other . lower_bounds [ dimension_index ] ||
        other . upper_bounds [ dimension_index ] + TOL < 
        lower_bounds [ dimension_index ] ) {
      return false;
    } /* if */
  } /* for */
  return true;
}

inline std::ostream & operator << ( std::ostream & output_stream, const Prism & print_me ) {
  for ( unsigned int dimension_index = 0; dimension_index < print_me . lower_bounds . size (); ++ dimension_index ) {
    output_stream << "[" << print_me . lower_bounds [ dimension_index ] << ", " << print_me . upper_bounds [ dimension_index ] << "]";
    if ( dimension_index < print_me . lower_bounds . size () - 1 ) output_stream << "x";
  }
  return output_stream;
} 

#endif