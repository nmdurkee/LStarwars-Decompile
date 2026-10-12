/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55c820; label: FUN_0055c820
 */

void FUN_0055c820(short param_1)

{
  if ((DAT_0093b2b4 != (ushort *)0x0) && ((int)(uint)*DAT_0093b2b4 < DAT_0093b2b8)) {
    *DAT_0093b2b4 = *DAT_0093b2b4 + param_1;
    if (DAT_0093b2b8 <= (int)(uint)*DAT_0093b2b4) {
      *DAT_0093b2b4 = (ushort)DAT_0093b2b8;
      if ((*(byte *)((int)DAT_0093b2b4 + 3) & 1) == 0) {
        if (DAT_0093b344 != (code *)0x0) {
          (*DAT_0093b344)();
        }
        *(byte *)((int)DAT_0093b2b4 + 3) = *(byte *)((int)DAT_0093b2b4 + 3) | 1;
      }
    }
  }
  return;
}

