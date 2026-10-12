/* Ghidra pseudocode, not original source.
 * ev_e6f703959aeb52fdf2ce751bd65c36cac7164cfc40610a61221749966f801066
 * Entry: 0x5d2840; label: FUN_005d2840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005d2840(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_004fa5f0(param_1,0);
  if (iVar1 != 0) {
    uVar2 = FUN_005d26d0(iVar1,param_2,param_3,param_4);
    FUN_004f99e0(iVar1);
  }
  return uVar2;
}

