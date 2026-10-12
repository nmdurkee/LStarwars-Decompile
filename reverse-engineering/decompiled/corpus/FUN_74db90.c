/* Ghidra analysis pseudocode, not original source.
 * ev_7c321bc51ff35622de6c5d479df857df6f5bf01a82339419049d6b39c5416ee3
 * Entry: 0x74db90; label: FUN_0074db90
 */

void FUN_0074db90(void)

{
  undefined1 *in_ECX;
  
  *(undefined4 *)(in_ECX + 0x104) = 0;
  *(undefined4 *)(in_ECX + 0x108) = 0;
  *(undefined4 *)(in_ECX + 0x10c) = 0;
  FUN_0074ad30();
  FUN_00748430(0x1000,1);
  *in_ECX = 0;
  *(undefined4 *)(in_ECX + 0x114) = 0;
  *(undefined4 *)(in_ECX + 0x118) = 0;
  in_ECX[0x120] = 0;
  *(undefined4 *)(in_ECX + 0x11c) = 0;
  _memset(in_ECX + 0x134,0,400);
  *(undefined4 *)(in_ECX + 0x2c4) = 0;
  _memset(in_ECX + 0x2c8,0,400);
  *(undefined4 *)(in_ECX + 0x458) = 0;
  return;
}

