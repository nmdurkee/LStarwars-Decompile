/* Ghidra pseudocode, not original source.
 * ev_71ce34dfbc3e25ecc670a7014d4d5fe50c303635112430d697820e3c5a49cfb6
 * Entry: 0x5bc370; label: FUN_005bc370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bc370(undefined1 *param_1)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *param_1 = 1;
  *(undefined4 *)(param_1 + 0x24) = 0;
  param_1[1] = 2;
  *(undefined4 *)(param_1 + 8) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x28) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x44) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x48) = 0x3f800000;
  *(undefined4 *)(param_1 + 0x4c) = 0x41200000;
  *(undefined4 *)(param_1 + 0x50) = 0x41200000;
  return;
}

