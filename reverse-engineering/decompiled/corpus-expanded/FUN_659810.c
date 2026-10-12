/* Ghidra pseudocode, not original source.
 * ev_04b6c5fb0da19ab46b9dcd6e2bf7aaf6621f6765e7317b7c56ac1531caca2973
 * Entry: 0x659810; label: FUN_00659810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

