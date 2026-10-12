/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55c8a0; label: FUN_0055c8a0
 */

void FUN_0055c8a0(void)

{
  if ((DAT_0093b2b4 != 0) && ((int)(uint)*(byte *)(DAT_0093b2b4 + 2) < (int)DAT_0093b30c)) {
    *(char *)(DAT_0093b2b4 + 2) = *(char *)(DAT_0093b2b4 + 2) + '\x01';
    if ((*(byte *)(DAT_0093b2b4 + 2) == DAT_0093b30c) && ((*(byte *)(DAT_0093b2b4 + 3) & 2) == 0)) {
      if (DAT_0093b348 != (code *)0x0) {
        (*DAT_0093b348)();
      }
      *(byte *)(DAT_0093b2b4 + 3) = *(byte *)(DAT_0093b2b4 + 3) | 2;
    }
  }
  return;
}

