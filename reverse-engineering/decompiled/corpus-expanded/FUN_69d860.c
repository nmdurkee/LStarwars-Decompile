/* Ghidra pseudocode, not original source.
 * ev_c022dfa5fb113afde7d6c0963a448fd7ba6a7635c8c31d639ad2eb654bc3de65
 * Entry: 0x69d860; label: FUN_0069d860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0069d860(int param_1,int param_2)

{
  if (*(int *)(param_1 + 4) != 0) {
    if (param_2 < 0) {
      if (*(int *)(param_1 + 0x58) < 3) goto LAB_0069d88a;
      param_2 = *(int *)(param_1 + 0x60);
    }
    else if (*(int *)(param_1 + 0x34) <= param_2) {
      return 0;
    }
    return param_2 * 0x20 + *(int *)(param_1 + 0x48);
  }
LAB_0069d88a:
  return *(int *)(param_1 + 0x48);
}

