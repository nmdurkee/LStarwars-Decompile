/* Ghidra analysis pseudocode, not original source.
 * ev_82de32114f0a758998fb1b139028178946084d97602e6dd81f3d90db1eb3e6aa
 * Entry: 0x5af650; label: FUN_005af650
 */

void FUN_005af650(void)

{
  int in_EAX;
  int in_ECX;
  
  if (in_ECX == 0) {
    *(undefined4 *)(in_EAX + 0x34) = 0;
  }
  else {
    if (in_ECX == 1) {
      *(undefined4 *)(in_EAX + 0x34) = 1;
      *(undefined4 *)(in_EAX + 0x10) = 0x40000000;
      *(undefined4 *)(in_EAX + 0x14) = 0x3dcccccd;
      *(undefined4 *)(in_EAX + 0x18) = 0x3a03126f;
      *(undefined4 *)(in_EAX + 0x1c) = 0x3c23d70a;
      *(undefined4 *)(in_EAX + 0x20) = 0x40c00000;
      *(undefined4 *)(in_EAX + 0x24) = 0x3fa66666;
      *(undefined4 *)(in_EAX + 0x28) = 0;
      *(undefined4 *)(in_EAX + 0x2c) = 0x3f400000;
      *(undefined4 *)(in_EAX + 0x30) = 0xc0000000;
      return;
    }
    if (in_ECX == 2) {
      *(undefined4 *)(in_EAX + 0x34) = 2;
      *(undefined4 *)(in_EAX + 0x10) = 0x40000000;
      *(undefined4 *)(in_EAX + 0x14) = 0x3dcccccd;
      *(undefined4 *)(in_EAX + 0x18) = 0x3a03126f;
      *(undefined4 *)(in_EAX + 0x1c) = 0x3c23d70a;
      *(undefined4 *)(in_EAX + 0x20) = 0x41c80000;
      *(undefined4 *)(in_EAX + 0x24) = 0x3f000000;
      *(undefined4 *)(in_EAX + 0x28) = 0;
      *(undefined4 *)(in_EAX + 0x2c) = 0x3f000000;
      *(undefined4 *)(in_EAX + 0x30) = 0xc1700000;
      return;
    }
  }
  return;
}

