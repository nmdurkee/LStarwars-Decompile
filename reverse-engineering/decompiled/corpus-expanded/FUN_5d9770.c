/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5d9770; label: FUN_005d9770
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005d9770(float *param_1,float *param_2,int param_3)

{
  float *pfVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(short *)(param_3 + 0x9c)) {
    pfVar1 = *(float **)(param_3 + 0x80);
    do {
      if (pfVar1[2] * param_1[2] + pfVar1[1] * param_1[1] + *param_1 * *pfVar1 + pfVar1[3] <
          -(param_2[2] * ABS(pfVar1[2]) + *param_2 * ABS(*pfVar1) + param_2[1] * ABS(pfVar1[1]))) {
        return 0;
      }
      iVar2 = iVar2 + 1;
      pfVar1 = pfVar1 + 4;
    } while (iVar2 < *(short *)(param_3 + 0x9c));
  }
  return 1;
}

