/* Ghidra analysis pseudocode, not original source.
 * ev_def803aaf6df2de69fb7a62b9730926f531944633efe81a39820bd20d35cd513
 * Entry: 0x4c91e0; label: FUN_004c91e0
 */

bool FUN_004c91e0(int param_1)

{
  if ((*(short *)(param_1 + 0x1064) == DAT_007f1948) && (*(int *)(param_1 + 0xcd0) != 0)) {
    return *(char *)(param_1 + 0x280) == -1;
  }
  return false;
}

