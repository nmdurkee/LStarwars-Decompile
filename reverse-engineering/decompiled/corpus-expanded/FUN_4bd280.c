/* Ghidra pseudocode, not original source.
 * ev_ec63a0996326cf703ee2b3a6fc0e0cae7d47cd208787877e90138bc554ba8dc2
 * Entry: 0x4bd280; label: FUN_004bd280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bd280(int param_1)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 extraout_ST0;
  float10 extraout_ST1;
  
  if (((param_1 != 0) && (iVar4 = *(int *)(param_1 + 0x50b0), iVar4 != 0)) &&
     (iVar5 = 0, 0 < *(int *)(param_1 + 0x50b4))) {
    do {
      if (((*(char *)(iVar4 + 0xa3) == '\x02') && (*(float *)(iVar4 + 0xb4) < 1.0)) &&
         (fVar1 = *(float *)(iVar4 + 0xb4) + _DAT_00925018, *(float *)(iVar4 + 0xb4) = fVar1,
         1.0 <= fVar1)) {
        *(byte *)(iVar4 + 0xa2) = *(byte *)(iVar4 + 0xa2) | 4;
        *(undefined4 *)(iVar4 + 0xb4) = 0x3f800000;
      }
      if (0.0 < *(float *)(iVar4 + 0xb4)) {
        fVar1 = *(float *)(iVar4 + 0xb4);
        if (NAN(fVar1) || 1.0 < fVar1 == (fVar1 == 1.0)) {
          iVar3 = FUN_006e6b90();
          uVar2 = (int)ROUND(extraout_ST0 *
                             (extraout_ST1 -
                             ((float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] + extraout_ST1) *
                             (float10)0.5)) & 0xffff;
        }
        else {
          uVar2 = 0x4000;
        }
      }
      else {
        uVar2 = 0;
      }
      FUN_004bce60(uVar2);
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0xc0;
    } while (iVar5 < *(int *)(param_1 + 0x50b4));
  }
  return;
}

