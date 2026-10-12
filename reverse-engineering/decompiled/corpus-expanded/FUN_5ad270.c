/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ad270; label: FUN_005ad270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ad270(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_4 != (int *)0x0) && ((short)param_4[2] != 0)) {
    iVar3 = 0;
    iVar2 = 0;
    do {
      iVar1 = FUN_004f1ff0(iVar3 + 8 + *param_4);
      if (iVar1 != 0) {
        FUN_00559ee0(param_1,param_2,0,*param_4 + iVar3);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x13c;
    } while (iVar2 < (int)(uint)*(ushort *)(param_4 + 2));
  }
  return;
}

