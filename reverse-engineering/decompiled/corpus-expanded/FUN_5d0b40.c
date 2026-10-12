/* Ghidra pseudocode, not original source.
 * ev_80f10280a68e27d1163faa95206013e039612dceeee316e4395f60ba03bc283c
 * Entry: 0x5d0b40; label: FUN_005d0b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

