/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5da3b0; label: FUN_005da3b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005da3b0(int param_1,undefined4 *param_2,undefined4 param_3,short param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((*(int *)(param_1 + 0x6c) != 0) && ((int)param_4 != *(int *)(param_1 + 0xe0))) {
    iVar1 = *(int *)(param_1 + 0xdc);
    iVar4 = 0;
    if (0 < iVar1) {
      piVar3 = (int *)(param_1 + 0x9c);
      do {
        iVar2 = *piVar3;
        if ((iVar2 != 0) && (*(short *)(iVar2 + 0x9e) == param_4)) {
          local_10 = *param_2;
          local_c = param_2[1];
          local_8 = param_2[2];
          local_4 = param_3;
          iVar2 = FUN_005d94a0(&local_10,iVar2);
          if (iVar2 != 0) {
            return iVar2;
          }
        }
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar4 < iVar1);
    }
    return 0;
  }
  return 1;
}

