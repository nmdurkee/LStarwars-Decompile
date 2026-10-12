/* Ghidra analysis pseudocode, not original source.
 * ev_7899ebfae6ed5d770b9bee2927149d51290c957b7eb14b433099b39f075be2b3
 * Entry: 0x5d0b40; label: FUN_005d0b40
 */

undefined4 FUN_005d0b40(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if ((param_1 == 0) && (param_1 = DAT_009738b8, DAT_009738b8 == 0)) {
    return 0xffff;
  }
  uVar1 = FUN_005d0aa0(*(undefined4 *)(param_1 + 0x38),*(undefined4 *)(param_1 + 0x10),param_2);
  return uVar1;
}

