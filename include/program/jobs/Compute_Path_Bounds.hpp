/*
 *  Compute_Path_Bounds.h
 */

#ifndef _CMDP_COMPUTE_PATH_BOUNDS_HPP_
#define _CMDP_COMPUTE_PATH_BOUNDS_HPP_


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
  const std::map < Conley_Morse_Graph const * , long > & through_path_bound ) {

  // not yet implemented: Masaki

} /* Compute_Path_Bounds */


#endif