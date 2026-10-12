/* Ghidra pseudocode, not original source.
 * ev_120f2dbe0ae7ec1f4fb84f9bb605c17bea6e5ad9085d38dd392f35fbf38da278
 * Entry: 0x5f3270; label: FUN_005f3270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

