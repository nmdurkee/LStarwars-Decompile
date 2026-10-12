/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x61a870; label: FUN_0061a870
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061a870(int param_1,int *param_2)

{
  int iVar1;
  
  if ((int *)param_2[1] == (int *)0x0) {
    *(int *)(param_1 + 0x4c) = *param_2;
  }
  else {
    *(int *)param_2[1] = *param_2;
  }
  if (*param_2 != 0) {
    *(int *)(*param_2 + 4) = param_2[1];
    iVar1 = *param_2;
    if (iVar1 != 0) goto LAB_0061a8a0;
  }
  iVar1 = param_2[1];
LAB_0061a8a0:
  *(int *)(param_1 + 0x50) = iVar1;
  FUN_004ef280(param_2,"d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0xa70);
  return;
}

