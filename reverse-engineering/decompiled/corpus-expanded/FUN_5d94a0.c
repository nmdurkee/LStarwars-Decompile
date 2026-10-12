/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5d94a0; label: FUN_005d94a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_005d94a0(float *param_1,int param_2)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = (int)*(short *)(param_2 + 0x9c);
  iVar4 = 0;
  iVar3 = 0;
  if (0 < iVar5) {
    pfVar2 = *(float **)(param_2 + 0x80);
    do {
      fVar1 = pfVar2[2] * param_1[2] + *pfVar2 * *param_1 + pfVar2[1] * param_1[1] + pfVar2[3];
      if (fVar1 < -param_1[3]) {
        return '\0';
      }
      if (param_1[3] < fVar1) {
        iVar4 = iVar4 + 1;
      }
      iVar3 = iVar3 + 1;
      pfVar2 = pfVar2 + 4;
    } while (iVar3 < iVar5);
  }
  fVar1 = param_1[2] * _DAT_00963f80 + *param_1 * _DAT_00963f78 + param_1[1] * _DAT_00963f7c +
          _DAT_00963f84;
  if (fVar1 < -param_1[3]) {
    return '\0';
  }
  if (param_1[3] < fVar1) {
    iVar4 = iVar4 + 1;
  }
  return (iVar4 != iVar5 + 1) + '\x01';
}

