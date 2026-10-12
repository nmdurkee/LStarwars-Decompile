/* Ghidra analysis pseudocode, not original source.
 * ev_82de32114f0a758998fb1b139028178946084d97602e6dd81f3d90db1eb3e6aa
 * Entry: 0x5b0400; label: FUN_005b0400
 */

void FUN_005b0400(int param_1,undefined4 param_2,float param_3)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x50fc)) {
    iVar4 = 0;
    do {
      fVar1 = *(float *)(*(int *)(param_1 + 0x50f8) + iVar4);
      pfVar2 = (float *)(*(int *)(param_1 + 0x50f8) + iVar4);
      if (0.0 < fVar1 != (fVar1 == 0.0)) {
        *pfVar2 = *pfVar2 - param_3;
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x1c;
    } while (iVar3 < *(int *)(param_1 + 0x50fc));
  }
  return;
}

