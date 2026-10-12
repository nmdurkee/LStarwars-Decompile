/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4ea8e0; label: FUN_004ea8e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_004ea8e0(int param_1)

{
  char cVar1;
  
  if ((param_1 != 0) && ((cVar1 = *(char *)(param_1 + 0x280), cVar1 == '\0' || (cVar1 == '\x01'))))
  {
    if (*(float *)(&DAT_0088a648 + cVar1 * 4) < 0.0) {
      *(undefined4 *)(&DAT_0088a648 + cVar1 * 4) = 0;
    }
    return (float10)((3.0 - *(float *)(&DAT_0088a648 + *(char *)(param_1 + 0x280) * 4)) / 3.0);
  }
  return (float10)1;
}

