/* Ghidra pseudocode, not original source.
 * ev_5a6bf3c2990e6ac877664f285487eca7a15ac2a0f3d7c9cff5c7bd2adfae7eea
 * Entry: 0x4f6f00; label: FUN_004f6f00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004f6f00(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar1 = DAT_00800468;
  iVar2 = DAT_00800468 * 0x10;
  DAT_00800468 = DAT_00800468 + 1;
  uVar3 = FUN_004f6d10(param_1);
  *(undefined8 *)(&DAT_00918e68 + iVar1 * 4) = uVar3;
  *(undefined4 *)(iVar2 + 0x918e60) = param_2;
  (&DAT_00918e64)[iVar1 * 4] = (uint)(param_3 != 1) * 2 + -1;
  FUN_004f04b0(param_1,param_2);
  FUN_004f04b0(param_1,param_2);
  return;
}

