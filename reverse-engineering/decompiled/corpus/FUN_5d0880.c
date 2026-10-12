/* Ghidra analysis pseudocode, not original source.
 * ev_7899ebfae6ed5d770b9bee2927149d51290c957b7eb14b433099b39f075be2b3
 * Entry: 0x5d0880; label: FUN_005d0880
 */

void FUN_005d0880(undefined4 param_1)

{
  if (DAT_009738cc < 0x10) {
    *(undefined4 *)(&DAT_0096d870 + DAT_009738cc * 4) = DAT_009738c4;
    DAT_009738cc = DAT_009738cc + 1;
    DAT_009738c4 = param_1;
    return;
  }
  DAT_009738c4 = param_1;
  return;
}

