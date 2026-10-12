/* Ghidra pseudocode, not original source.
 * ev_ad94bec40fb329b942d4f858c664032de23cf17ab2243631134a23feb763d3d7
 * Entry: 0x55c820; label: FUN_0055c820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

