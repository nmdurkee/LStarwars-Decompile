/* Ghidra pseudocode, not original source.
 * ev_dfc36d2b541ec0d46ba2179b7939a25d003ccbe30d4bab0c10c333595f465d14
 * Entry: 0x6582f0; label: FUN_006582f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006582f0(int param_1)

{
  int iVar1;
  
  if (((-1 < param_1) && (param_1 < DAT_02962098)) && (*(int *)(DAT_0296209c + param_1 * 4) != 0)) {
    iVar1 = *(int *)(DAT_0296209c + param_1 * 4);
    return (float10)(*(float *)(iVar1 + 0x20) + *(float *)(iVar1 + 0x1c) + *(float *)(iVar1 + 0x24)
                    + *(float *)(iVar1 + 0x28));
  }
  return (float10)0;
}

