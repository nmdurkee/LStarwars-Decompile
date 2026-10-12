/* Ghidra pseudocode, not original source.
 * ev_ad94bec40fb329b942d4f858c664032de23cf17ab2243631134a23feb763d3d7
 * Entry: 0x55c8a0; label: FUN_0055c8a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

