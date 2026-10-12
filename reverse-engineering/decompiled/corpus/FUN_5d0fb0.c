/* Ghidra analysis pseudocode, not original source.
 * ev_7899ebfae6ed5d770b9bee2927149d51290c957b7eb14b433099b39f075be2b3
 * Entry: 0x5d0fb0; label: FUN_005d0fb0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d0fb0(int param_1)

{
  if ((param_1 != 0) || (param_1 = DAT_009738b8, DAT_009738b8 != 0)) {
    _DAT_009738b4 = *(undefined4 *)(param_1 + 0x1c);
    *(undefined4 *)(param_1 + 0x20) = 1;
  }
  return;
}

