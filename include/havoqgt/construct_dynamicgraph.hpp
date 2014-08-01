/*
 * Copyright (c) 2013, Lawrence Livermore National Security, LLC.
 * Produced at the Lawrence Livermore National Laboratory.
 * Written by Roger Pearce <rpearce@llnl.gov>.
 * LLNL-CODE-644630.
 * All rights reserved.
 *
 * This file is part of HavoqGT, Version 0.1.
 * For details, see https://computation.llnl.gov/casc/dcca-pub/dcca/Downloads.html
 *
 * Please also read this link – Our Notice and GNU Lesser General Public License.
 *   http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License (as published by the Free
 * Software Foundation) version 2.1 dated February 1999.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the IMPLIED WARRANTY OF MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE. See the terms and conditions of the GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * OUR NOTICE AND TERMS AND CONDITIONS OF THE GNU GENERAL PUBLIC LICENSE
 *
 * Our Preamble Notice
 *
 * A. This notice is required to be provided under our contract with the
 * U.S. Department of Energy (DOE). This work was produced at the Lawrence
 * Livermore National Laboratory under Contract No. DE-AC52-07NA27344 with the DOE.
 *
 * B. Neither the United States Government nor Lawrence Livermore National
 * Security, LLC nor any of their employees, makes any warranty, express or
 * implied, or assumes any liability or responsibility for the accuracy,
 * completeness, or usefulness of any information, apparatus, product, or process
 * disclosed, or represents that its use would not infringe privately-owned rights.
 *
 * C. Also, reference herein to any specific commercial products, process, or
 * services by trade name, trademark, manufacturer or otherwise does not
 * necessarily constitute or imply its endorsement, recommendation, or favoring by
 * the United States Government or Lawrence Livermore National Security, LLC. The
 * views and opinions of authors expressed herein do not necessarily state or
 * reflect those of the United States Government or Lawrence Livermore National
 * Security, LLC, and shall not be used for advertising or product endorsement
 * purposes.
 *
 */

#ifndef HAVOQGT_MPI_CONSTRUCT_DYNAMICGRAPH_VEC_HPP_INCLUDED
#define HAVOQGT_MPI_CONSTRUCT_DYNAMICGRAPH_VEC_HPP_INCLUDED

#include <havoqgt/mpi.hpp>
//#include <havoqgt/distributed_edge_list.hpp>
#include <havoqgt/detail/iterator.hpp>

#include <boost/unordered_set.hpp>
#include <boost/unordered_map.hpp>
#include <boost/container/map.hpp>
#include <boost/interprocess/containers/map.hpp>
#include <stdint.h>
#include <utility>
#include <limits>

#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/containers/vector.hpp>
#include <boost/interprocess/managed_mapped_file.hpp>


namespace havoqgt {
  namespace mpi {


class IOInfo {
 public:
  IOInfo();
  void init();
  void reset_baseline();
  void get_status(int &r, int &w);
  void log_diff(bool final);

 private:
  int read_previous_mb_;
  int written_previous_mb_;
  int read_total_mb_;
  int written_total_mb_;
};


namespace bip = boost::interprocess;
template <typename SegementManager>
class construct_dynamicgraph {
 public:

  template<typename T>
  using SegmentAllocator = bip::allocator<T, SegementManager>;

  // ---------  Data Structures ------------ //
  typedef bip::vector<uint64_t, SegmentAllocator<uint64_t>> uint64_vector_t;
  typedef bip::vector<uint64_vector_t, SegmentAllocator<uint64_vector_t> > adjacency_matrix_vec_vec__t;
  typedef std::pair<const uint64_t, uint64_vector_t> map_value_t;
  typedef boost::unordered_map<uint64_t, uint64_vector_t, boost::hash<uint64_t>, std::equal_to<uint64_t>, SegmentAllocator<map_value_t>> adjacency_matrix_map_vec__t;



  //--  Constructors -- //
  ///set segment allocator to data structures wihtout data resize.
  construct_dynamicgraph(const SegmentAllocator<void>& seg_allocator, const int mode);


  /// add edges vector-vector adjacency-matrix
  template <typename ManagedMappedFile, typename Container>
  void add_edges_adjacency_matrix(ManagedMappedFile& asdf, const SegmentAllocator<void>& seg_allocator, Container& edges);

  void print_profile();



  static const int kUseVecVecMatrix;
  static const int kUseMapVecMatrix;


 private:

  /// add edges vector-vector adjacency-matrix
  template <typename ManagedMappedFile, typename Container>
  void add_edges_adjacency_matrix_vector_vector(ManagedMappedFile& asdf, const SegmentAllocator<void>& seg_allocator, Container& edges);

  /// add edges unsorted_map-vector adjacency-matrix
  template <typename ManagedMappedFile, typename Container>
  void add_edges_adjacency_matrix_map_vector(ManagedMappedFile& asdf, const SegmentAllocator<void>& seg_allocator, Container& edges);




  adjacency_matrix_vec_vec__t adjacency_matrix_vec_vec_;
  adjacency_matrix_map_vec__t adjacency_matrix_map_vec_;
  const int data_structure_type_;

  IOInfo io_info_;
  double total_exectution_time_;
};



/// Frees the container of edges
template <typename Container>
void free_edge_container(Container &edges) {};


template<>
void free_edge_container<std::vector<std::pair<uint64_t, uint64_t> > >(std::vector<std::pair<uint64_t, uint64_t> > &edges){
  std::vector< std::pair<uint64_t, uint64_t> >empty(0);
  edges.swap(empty);
};


} // namespace mpi
} // namespace havoqgt

#include <havoqgt/impl/construct_dynamicgraph.ipp>

#endif //HAVOQGT_MPI_CONSTRUCT_DYNAMICGRAPH_VEC_HPP_INCLUDED