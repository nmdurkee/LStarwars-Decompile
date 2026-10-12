/* Ghidra pseudocode, not original source.
 * ev_9dff45b5f0eb52bcd65f8627f4ae852e719fa42162b45a2265e4036e2ee04965
 * Entry: 0x74db90; label: FUN_0074db90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

