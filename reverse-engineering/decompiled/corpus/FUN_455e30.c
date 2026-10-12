/* Ghidra analysis pseudocode, not original source.
 * ev_8c5b0e575cc3a77a31b08f4844e5d8b5ee6e8018ce9d45deeeec0b9133723e57
 * Entry: 0x455e30; label: FUN_00455e30
 */

undefined4 FUN_00455e30(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 != 0) && (*(undefined4 **)(param_3 + 0xd0) != (undefined4 *)0x0)) {
    FUN_0049d540(**(undefined4 **)(param_3 + 0xd0));
  }
  return 1;
}

