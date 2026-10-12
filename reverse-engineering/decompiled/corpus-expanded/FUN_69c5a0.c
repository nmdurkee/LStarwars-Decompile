/* Ghidra pseudocode, not original source.
 * ev_c022dfa5fb113afde7d6c0963a448fd7ba6a7635c8c31d639ad2eb654bc3de65
 * Entry: 0x69c5a0; label: FUN_0069c5a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069c5a0(int param_1)

{
  undefined4 uVar1;
  float10 extraout_ST0;
  
  if (*(int *)(param_1 + 0x58) < 2) {
    return 0xffffff7d;
  }
  if (*(double *)(param_1 + 0x70) == 0.0) {
    return 0xffffffff;
  }
  uVar1 = FUN_006e6b90();
  *(double *)(param_1 + 0x68) = (double)extraout_ST0;
  *(double *)(param_1 + 0x70) = (double)extraout_ST0;
  return uVar1;
}

