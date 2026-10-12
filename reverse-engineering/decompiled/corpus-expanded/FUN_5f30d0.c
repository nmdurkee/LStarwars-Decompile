/* Ghidra pseudocode, not original source.
 * ev_120f2dbe0ae7ec1f4fb84f9bb605c17bea6e5ad9085d38dd392f35fbf38da278
 * Entry: 0x5f30d0; label: FUN_005f30d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f30d0(undefined4 param_1,uint *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *param_2 + 0xf & 0xfffffff0;
  *param_2 = uVar2;
  iVar3 = FUN_004fd5d0(param_1,uVar2,*param_3 - uVar2);
  if (iVar3 == 0) {
    iVar3 = FUN_005c12e0(param_1);
  }
  piVar1 = (int *)*param_2;
  *param_2 = iVar3 + (int)piVar1;
  if (*piVar1 != 1) {
    FUN_005c12e0(param_1);
  }
  iVar3 = piVar1[1];
  piVar1[1] = (int)piVar1 - iVar3;
  iVar3 = FUN_005e9080(piVar1[2],(int)piVar1 - iVar3);
  piVar1[2] = iVar3;
  return;
}

