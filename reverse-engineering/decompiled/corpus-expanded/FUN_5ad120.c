/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ad120; label: FUN_005ad120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005ad120(int *param_1,undefined4 param_2,undefined4 param_3,float *param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  int local_8;
  
  piVar2 = param_1;
  iVar4 = 0;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  piVar1 = param_1 + 2;
  param_1 = (int *)0x4e6e6b28;
  iVar3 = *piVar2;
  local_8 = 0;
  if ((short)*piVar1 != 0) {
    do {
      if (((*(ushort *)(iVar3 + 0x13a) & 4) != 0) && ((*(ushort *)(iVar3 + 0x13a) & 2) != 0)) {
        fVar5 = (float10)FUN_005b3c50(param_2,iVar3 + 0x24,0);
        if ((float)fVar5 < (float)param_1) {
          param_1 = (int *)(float)fVar5;
          local_8 = iVar3;
        }
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x13c;
    } while (iVar4 < (int)(uint)*(ushort *)(piVar2 + 2));
  }
  if (param_4 != (float *)0x0) {
    *param_4 = (float)param_1;
  }
  return local_8;
}

