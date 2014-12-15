#ifndef RHHH_RHHALLOCHOLDER_HPP_INCLUDED
#define RHHH_RHHALLOCHOLDER_HPP_INCLUDED

#include <boost/interprocess/allocators/allocator.hpp>
#include <boost/interprocess/allocators/node_allocator.hpp>
#include <boost/interprocess/managed_mapped_file.hpp>
#include "RHHCommon.hpp"
#include "RHHStatic.hpp"

namespace RHH {

  namespace bip = boost::interprocess;

  /// Memory size (Byte) = capacity * (  1  /// property block
  ///                                  + 8  /// key block
  ///                                  + 1) /// value block
  ///                                  + 8   /// next pointer
  enum {
    capacityNormalArray1 = 2ULL,
    capacityNormalArray2 = 4ULL,
    capacityNormalArray3 = 8ULL,
    capacityRHHStatic_1 = 8ULL,
    capacityRHHStatic_2 = 16ULL,
    capacityRHHStatic_3 = 32ULL,
    capacityRHHStatic_4 = 64ULL,
    capacityRHHStatic_5 = 128ULL,
    capacityRHHStatic_6 = 256ULL,
    capacityRHHStatic_7 = 512ULL,
    capacityRHHStatic_8 = 1024ULL,
    capacityRHHStatic_9 = 2048ULL,
    capacityRHHStatic_10 = 4096ULL,
    capacityRHHStatic_11 = 8192ULL,
    capacityRHHStatic_12 = 16384ULL,
    capacityRHHStatic_13 = 32768ULL,
    capacityRHHStatic_14 = 65536ULL,
    capacityRHHStatic_15 = 131072ULL,
    capacityRHHStatic_16 = 262144ULL,
    capacityRHHStatic_17 = 524288ULL
  };

  typedef RHHStatic<uint64_t, NoValueType, capacityRHHStatic_1> RHHStaticNoVal_1;
  typedef RHHStatic<uint64_t, NoValueType, capacityRHHStatic_2> RHHStaticNoVal_2;
  typedef RHHStatic<uint64_t, NoValueType, capacityRHHStatic_3> RHHStaticNoVal_3;
  typedef RHHStatic<uint64_t, NoValueType, capacityRHHStatic_4> RHHStaticNoVal_4;
  typedef RHHStatic<uint64_t, NoValueType, capacityRHHStatic_5> RHHStaticNoVal_5;
  typedef RHHStatic<uint64_t, NoValueType, capacityRHHStatic_6> RHHStaticNoVal_6;
  typedef RHHStatic<uint64_t, NoValueType, capacityRHHStatic_7> RHHStaticNoVal_7;
  typedef RHHStatic<uint64_t, NoValueType, capacityRHHStatic_8> RHHStaticNoVal_8;
  typedef RHHStatic<uint64_t, NoValueType, capacityRHHStatic_9> RHHStaticNoVal_9;
  typedef RHHStatic<uint64_t, NoValueType, capacityRHHStatic_10> RHHStaticNoVal_10;
  typedef RHHStatic<uint64_t, NoValueType, capacityRHHStatic_11> RHHStaticNoVal_11;
  typedef RHHStatic<uint64_t, NoValueType, capacityRHHStatic_12> RHHStaticNoVal_12;
  typedef RHHStatic<uint64_t, NoValueType, capacityRHHStatic_13> RHHStaticNoVal_13;
  typedef RHHStatic<uint64_t, NoValueType, capacityRHHStatic_14> RHHStaticNoVal_14;
  typedef RHHStatic<uint64_t, NoValueType, capacityRHHStatic_15> RHHStaticNoVal_15;
  typedef RHHStatic<uint64_t, NoValueType, capacityRHHStatic_16> RHHStaticNoVal_16;
  typedef RHHStatic<uint64_t, NoValueType, capacityRHHStatic_17> RHHStaticNoVal_17;


  ///  =========================================================================== ///
  ///                             Allocator Holder
  ///  =========================================================================== ///
  class AllocatorsHolder
  {
  public:
    typedef bip::managed_mapped_file  mapped_t;
    typedef mapped_t::segment_manager segment_manager_t;
    explicit AllocatorsHolder(segment_manager_t* segment_manager)
    : allocator_rhh_noval_1(segment_manager)
    , allocator_rhh_noval_2(segment_manager)
    , allocator_rhh_noval_3(segment_manager)
    , allocator_rhh_noval_4(segment_manager)
    , allocator_rhh_noval_5(segment_manager)
    , allocator_rhh_noval_6(segment_manager)
    , allocator_rhh_noval_7(segment_manager)
    , allocator_rhh_noval_8(segment_manager)
    , allocator_rhh_noval_9(segment_manager)
    , allocator_rhh_noval_10(segment_manager)
    , allocator_rhh_noval_11(segment_manager)
    , allocator_rhh_noval_12(segment_manager)
    , allocator_rhh_noval_13(segment_manager)
    , allocator_rhh_noval_14(segment_manager)
    , allocator_rhh_noval_15(segment_manager)
    , allocator_rhh_noval_16(segment_manager)
    , allocator_rhh_noval_17(segment_manager)
    , allocator_normalarray(segment_manager)
    , allocator_raw(segment_manager)
    { }


  /// size = capacity * (1 + 8 + 1) + 8
  /// probedistance = 1 byte, key = 8 byte, value block = 1 byte
  bip::node_allocator<RHHStaticNoVal_1, segment_manager_t,  47>  allocator_rhh_noval_1;
  bip::node_allocator<RHHStaticNoVal_2, segment_manager_t,  24>  allocator_rhh_noval_2;
  bip::node_allocator<RHHStaticNoVal_3, segment_manager_t,  12>  allocator_rhh_noval_3;
  bip::node_allocator<RHHStaticNoVal_4, segment_manager_t,   6>  allocator_rhh_noval_4;
  bip::node_allocator<RHHStaticNoVal_5, segment_manager_t,   3>  allocator_rhh_noval_5;
  bip::node_allocator<RHHStaticNoVal_6, segment_manager_t,   1>  allocator_rhh_noval_6;
  bip::node_allocator<RHHStaticNoVal_7, segment_manager_t,   1>  allocator_rhh_noval_7;
  bip::node_allocator<RHHStaticNoVal_8, segment_manager_t,   1>  allocator_rhh_noval_8;
  bip::node_allocator<RHHStaticNoVal_9, segment_manager_t,   1>  allocator_rhh_noval_9;
  bip::node_allocator<RHHStaticNoVal_10, segment_manager_t,  1>  allocator_rhh_noval_10;
  bip::node_allocator<RHHStaticNoVal_11, segment_manager_t,  1>  allocator_rhh_noval_11;
  bip::node_allocator<RHHStaticNoVal_12, segment_manager_t,  1>  allocator_rhh_noval_12;
  bip::node_allocator<RHHStaticNoVal_13, segment_manager_t,  1>  allocator_rhh_noval_13;
  bip::node_allocator<RHHStaticNoVal_14, segment_manager_t,  1>  allocator_rhh_noval_14;
  bip::node_allocator<RHHStaticNoVal_15, segment_manager_t,  1>  allocator_rhh_noval_15;
  bip::node_allocator<RHHStaticNoVal_16, segment_manager_t,  1>  allocator_rhh_noval_16;
  bip::node_allocator<RHHStaticNoVal_17, segment_manager_t,  1>  allocator_rhh_noval_17;
  bip::node_allocator<uint64_t, segment_manager_t, 512> allocator_normalarray;
  bip::allocator<unsigned char, segment_manager_t> allocator_raw;

  private:
    // static inline uint64_t cal_next_highest_power_of_2(uint64_t x)
    // {
    //   --x;
    //   x != x >> 1ULL;
    //   x != x >> 2ULL;
    //   x != x >> 4ULL;
    //   x != x >> 8ULL;
    //   x != x >> 16ULL;
    //   x != x >> 32ULL;
    //   return ++x;
    // }

  };
}

#endif