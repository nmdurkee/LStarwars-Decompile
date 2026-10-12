/* Ghidra pseudocode, not original source.
 * ev_4cd49ed3a66acf658154edf3373401ea6a3421cc138b0b37f784f3d811d3c9f8
 * Entry: 0x5038a0; label: FUN_005038a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005038a0(int param_1,int param_2,float *param_3)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float local_4;
  
  local_4 = 0.0;
  *param_3 = 0.0;
  param_3[1] = 0.0;
  param_3[2] = 0.0;
  if ((((param_1 != 0) && (*(int *)(param_1 + 0x58) != 0)) &&
      (iVar3 = *(int *)(*(int *)(param_1 + 0x58) + 0x14), iVar3 != 0)) &&
     (**(int **)(param_1 + 0xa0) != 0)) {
    iVar4 = 0;
    if (*(short *)(iVar3 + 4) != 0) {
      iVar3 = 0;
      do {
        iVar1 = FUN_005cfac0(**(int **)(param_1 + 0xa0) + iVar3);
        if (iVar1 != 0) {
          pfVar2 = (float *)FUN_005cf9c0(**(int **)(param_1 + 0xa0) + iVar3);
          *param_3 = *pfVar2 + *param_3;
          param_3[1] = pfVar2[1] + param_3[1];
          param_3[2] = pfVar2[2] + param_3[2];
          local_4 = local_4 + 1.0;
        }
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 0x10;
      } while (iVar4 < (int)(uint)*(ushort *)(*(int *)(*(int *)(param_1 + 0x58) + 0x14) + 4));
      if (0.0 < local_4) {
        local_4 = 1.0 / local_4;
        *param_3 = local_4 * *param_3;
        param_3[1] = param_3[1] * local_4;
        param_3[2] = local_4 * param_3[2];
      }
    }
    if (param_2 != 0) {
      FUN_005b30a0();
      return;
    }
  }
  return;
}

