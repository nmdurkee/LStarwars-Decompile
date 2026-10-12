/* Ghidra analysis pseudocode, not original source.
 * ev_40d9be8e3a3402c331433b8a2d08079ac53cd459e8d3bded6c92f46fa7f98a9b
 * Entry: 0x659810; label: FUN_00659810
 */

void FUN_00659810(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined1 local_c [12];
  
  FUN_005da860(local_c,DAT_02962114,DAT_02923194);
  uVar1 = FUN_005cf9c0(local_c);
  FUN_005b3800(&DAT_02930078 + param_1 * 0xc + DAT_02962010 * 0x2d4,param_2,uVar1);
  return;
}

