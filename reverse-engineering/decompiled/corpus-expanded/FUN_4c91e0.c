/* Ghidra pseudocode, not original source.
 * ev_f6678a28cc19d550655313a6a6f4f7bb8e44fc9612bb24799d4de398af21bc4a
 * Entry: 0x4c91e0; label: FUN_004c91e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_004c91e0(int param_1)

{
  if ((*(short *)(param_1 + 0x1064) == DAT_007f1948) && (*(int *)(param_1 + 0xcd0) != 0)) {
    return *(char *)(param_1 + 0x280) == -1;
  }
  return false;
}

