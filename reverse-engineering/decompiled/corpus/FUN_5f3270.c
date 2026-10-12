/* Ghidra analysis pseudocode, not original source.
 * ev_d2450bc109eaeb7c56e41eff2a553a3360ea1f4e9492b44c9e06060604e12c53
 * Entry: 0x5f3270; label: FUN_005f3270
 */

uint FUN_005f3270(undefined4 param_1,uint *param_2,uint *param_3,uint *param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *param_2 + 0xf & 0xfffffff0;
  *param_2 = uVar2;
  iVar3 = FUN_004fd5d0(param_1,uVar2,*param_3 - uVar2);
  if (iVar3 == 0) {
    iVar3 = FUN_004eff30();
    if (iVar3 == -1) {
      *param_2 = *param_3;
    }
    FUN_005c12f0(param_1);
    *param_4 = 0;
    return 0;
  }
  bVar1 = 0x414e4934 < *(int *)(*param_2 + 4);
  if (bVar1) {
    uVar2 = FUN_004f4f40(*param_2);
    *param_2 = uVar2;
  }
  *param_4 = *param_2;
  *param_2 = *param_2 + iVar3;
  if (bVar1) {
    return *param_4;
  }
  uVar2 = FUN_005f3140(iVar3,param_4);
  return uVar2;
}

