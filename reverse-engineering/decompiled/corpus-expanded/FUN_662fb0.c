/* Ghidra pseudocode, not original source.
 * ev_48e8314641b8677069cf0b2f56163e168ef7ac8043ee4515292faa1f02998c89
 * Entry: 0x662fb0; label: FUN_00662fb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00662fb0(undefined4 param_1,int param_2)

{
  float fVar1;
  int iVar2;
  
  if ((DAT_029231a8 != -1) && ((&DAT_02924b60)[DAT_029231a8 * 0x16] != -1)) {
    iVar2 = *(int *)(DAT_0296209c +
                    *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4)
                    * 4);
    fVar1 = *(float *)(param_2 + 0x54);
    *(float *)(iVar2 + 0x34) = fVar1;
    if (*(float *)(iVar2 + 0x38) < fVar1) {
      *(float *)(iVar2 + 0x38) = fVar1;
      return;
    }
  }
  return;
}

