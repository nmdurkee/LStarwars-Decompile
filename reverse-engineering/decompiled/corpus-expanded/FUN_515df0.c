/* Ghidra pseudocode, not original source.
 * ev_cd85811e73cbe502a6d015fc1f20588fa81ce6efb8852e42609516c9f2c20483
 * Entry: 0x515df0; label: FUN_00515df0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_00515df0(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 local_c [2];
  undefined4 local_4;
  
  FUN_005b3800(local_c,param_1,param_2);
  iVar1 = FUN_005be2d0(local_c[0],local_4);
  uVar2 = iVar1 - param_3 & 0xffff;
  if (0x7fff < uVar2) {
    uVar2 = uVar2 - 0x10000;
  }
  return (int)((uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f)) < (param_4 * 0x8000) / 0x168;
}

