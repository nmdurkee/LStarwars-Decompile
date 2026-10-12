/* Ghidra pseudocode, not original source.
 * ev_80f10280a68e27d1163faa95206013e039612dceeee316e4395f60ba03bc283c
 * Entry: 0x5d0a40; label: FUN_005d0a40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d0a40(void)

{
  if (DAT_009738c8 < 0x10) {
    *(undefined4 *)(&DAT_00963dc0 + DAT_009738c8 * 4) = DAT_009738c0;
    DAT_009738c8 = DAT_009738c8 + 1;
  }
  FUN_005d0940();
  return;
}

