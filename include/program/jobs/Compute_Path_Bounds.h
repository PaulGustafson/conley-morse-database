/*
 *  Compute_Path_Bounds.h
 */

#ifndef _CMDP_COMPUTE_PATH_BOUNDS_
#define _CMDP_COMPUTE_PATH_BOUNDS_

#include <map>


/// Computes strict upper bounds on the lengths of connecting orbits
/// between the Morse sets in the final Morse decomposition.
/// The provided data structure for path bounds is initially empty.
/// The provided Conley-Morse graph contains all the edges for which
/// there is a chance of the existence of a connection (in other words,
/// some edges may be missing, which means that we don't need to compute
/// the bound for these edges).
/// For the Morse sets in this data structure, the original Morse
/// decompositions are provided, from which they were taken,
/// and the corresponding Morse set is also indicated.
/// For each Morse set, its decomposition is provided whenever the Morse set
/// was actually subdivided.
/// For each Morse set, the coarser Conley-Morse graph is provided
/// as well as the corresponding set, if the Morse set is in a subdivision
/// of some other Morse set.
/// The bounds for path lengths, computed with graph algorithms, are also provided.
template < class Conley_Morse_Graph >
void Compute_Path_Bounds ( std::map < typename Conley_Morse_Graph::Edge , long > * path_bounds ,
  const Conley_Morse_Graph & conley_morse_graph ,
  const std::map < typename Conley_Morse_Graph::Vertex , Conley_Morse_Graph const * > & original_cmg ,
  const std::map < typename Conley_Morse_Graph::Vertex , typename Conley_Morse_Graph::Vertex > & original_set ,
  const std::map < std::pair < Conley_Morse_Graph const * , typename Conley_Morse_Graph::Vertex > , Conley_Morse_Graph const * > & finer_cmg ,
  const std::map < Conley_Morse_Graph const * , Conley_Morse_Graph const * > & coarser_cmg ,
  const std::map < Conley_Morse_Graph const * , typename Conley_Morse_Graph::Vertex > & coarser_set ,
  const std::map < Conley_Morse_Graph const * , std::map < typename Conley_Morse_Graph::Vertex , long > > & exit_path_bounds ,
  const std::map < Conley_Morse_Graph const * , std::map < typename Conley_Morse_Graph::Vertex , long > > & entrance_path_bounds ,
  const std::map < Conley_Morse_Graph const * , std::map < typename Conley_Morse_Graph::Edge , long > > & path_bounds ,
  const std::map < Conley_Morse_Graph const * , long > & through_path_bound );


#ifndef _DO_NOT_INCLUDE_HPP_
#include "program/jobs/Compute_Path_Bounds.hpp"
#endif

#endif