/* Ghidra analysis pseudocode, not original source.
 * ev_7899ebfae6ed5d770b9bee2927149d51290c957b7eb14b433099b39f075be2b3
 * Entry: 0x5d0530; label: FUN_005d0530
 */

undefined4 FUN_005d0530(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = DAT_00806ccc;
  if (param_1 == 0) {
    DAT_00806ccc = 0xffffffff;
    return uVar1;
  }
  DAT_00806ccc = param_2;
  return uVar1;
}

