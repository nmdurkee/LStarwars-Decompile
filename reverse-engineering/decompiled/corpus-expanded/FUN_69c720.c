/* Ghidra pseudocode, not original source.
 * ev_c022dfa5fb113afde7d6c0963a448fd7ba6a7635c8c31d639ad2eb654bc3de65
 * Entry: 0x69c720; label: FUN_0069c720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0069c720(int param_1,int param_2)

{
  int iVar1;
  float10 fVar2;
  double local_10;
  
  if (((*(int *)(param_1 + 0x58) < 2) || (*(int *)(param_1 + 4) == 0)) ||
     (*(int *)(param_1 + 0x34) <= param_2)) {
    return (float10)-131.0;
  }
  if (-1 < param_2) {
    return (float10)*(longlong *)(*(int *)(param_1 + 0x44) + 8 + param_2 * 0x10) /
           (float10)*(int *)(*(int *)(param_1 + 0x48) + 8 + param_2 * 0x20);
  }
  fVar2 = (float10)0;
  iVar1 = 0;
  if (*(int *)(param_1 + 0x34) < 1) {
    return fVar2;
  }
  do {
    local_10 = (double)fVar2;
    fVar2 = (float10)FUN_0069c720(param_1,iVar1);
    fVar2 = fVar2 + (float10)local_10;
    iVar1 = iVar1 + 1;
  } while (iVar1 < *(int *)(param_1 + 0x34));
  return fVar2;
}

