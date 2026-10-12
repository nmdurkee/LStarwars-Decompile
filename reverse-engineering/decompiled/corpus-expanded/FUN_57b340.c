/* Ghidra pseudocode, not original source.
 * ev_be2e1b76976fde28c062f4f0fb6ba1ce818a6b2c78af6ba8f2a77520ff39bb32
 * Entry: 0x57b340; label: FUN_0057b340
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0057b340(undefined4 param_1)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (DAT_00951c08 < 4) {
    iVar4 = FUN_004f9e70(param_1);
    iVar3 = DAT_00951c4c;
    iVar5 = DAT_00951c08;
    *(int *)(DAT_00951c4c + 0x148 + DAT_00951c08 * 8) = iVar4;
    if (iVar4 != -1) {
      pfVar1 = (float *)(iVar3 + 0x144 + iVar5 * 8);
      iVar5 = FUN_004f9e70(param_1);
      *pfVar1 = (float)iVar5;
      fVar2 = *pfVar1;
      if (!NAN(fVar2) && 1.0 < fVar2 != (fVar2 == 1.0)) {
        DAT_00951c08 = DAT_00951c08 + 1;
      }
    }
  }
  return;
}

