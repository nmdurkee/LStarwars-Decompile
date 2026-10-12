/* Ghidra pseudocode, not original source.
 * ev_c022dfa5fb113afde7d6c0963a448fd7ba6a7635c8c31d639ad2eb654bc3de65
 * Entry: 0x69c600; label: FUN_0069c600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069c600(int param_1,int param_2)

{
  while( true ) {
    while (*(int *)(param_1 + 0x34) <= param_2) {
      param_2 = *(int *)(param_1 + 0x34) + -1;
    }
    if (*(int *)(param_1 + 4) != 0) break;
    if (param_2 < 0) goto LAB_0069c62c;
    param_2 = -1;
  }
  if (-1 < param_2) {
    return *(undefined4 *)(*(int *)(param_1 + 0x40) + param_2 * 4);
  }
LAB_0069c62c:
  return *(undefined4 *)(param_1 + 0x5c);
}

