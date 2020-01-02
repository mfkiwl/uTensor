#include "gtest/gtest.h"
#include "arenaAllocator.hpp"
#include "context.hpp"
#include "RamTensor.hpp"

#include <iostream>
using std::cout;
using std::endl;

using namespace uTensor;

void setup_context(){
  localCircularArenaAllocator<256> meta_allocator;
  localCircularArenaAllocator<256> ram_allocator;
  Context::set_metadata_allocator(&meta_allocator);
  Context::set_ram_data_allocator(&ram_allocator);
}

TEST(RAM_Tensor, constructor) {
  //setup_context();
  localCircularArenaAllocator<256> meta_allocator;
  localCircularArenaAllocator<256> ram_allocator;
  Context::set_metadata_allocator(&meta_allocator);
  Context::set_ram_data_allocator(&ram_allocator);
  RamTensor r({10, 10}, u8);
}

TEST(RAM_Tensor, read_write_u8) {
  ///setup_context();
  localCircularArenaAllocator<256> meta_allocator;
  localCircularArenaAllocator<256> ram_allocator;
  Context::set_metadata_allocator(&meta_allocator);
  Context::set_ram_data_allocator(&ram_allocator);
  RamTensor r({10, 10}, u8);
  r(2,2) = (uint8_t) 5;
}