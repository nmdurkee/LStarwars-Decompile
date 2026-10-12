/* Ghidra pseudocode, not original source.
 * ev_c022dfa5fb113afde7d6c0963a448fd7ba6a7635c8c31d639ad2eb654bc3de65
 * Entry: 0x69d760; label: FUN_0069d760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined8 FUN_0069d760(int param_1)

{
  if (*(int *)(param_1 + 0x58) < 2) {
    return 0xffffffffffffff7d;
  }
  return *(undefined8 *)(param_1 + 0x50);
}

