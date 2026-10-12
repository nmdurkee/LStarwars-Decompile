/* Ghidra analysis pseudocode, not original source.
 * ev_7899ebfae6ed5d770b9bee2927149d51290c957b7eb14b433099b39f075be2b3
 * Entry: 0x5d0a40; label: FUN_005d0a40
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

