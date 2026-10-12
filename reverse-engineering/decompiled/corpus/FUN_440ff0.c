/* Ghidra analysis pseudocode, not original source.
 * ev_21419941ff706dc36400096798d0e4206b179ad86627ccdd195989c68e36c002
 * Entry: 0x440ff0; label: FUN_00440ff0
 */

undefined4 FUN_00440ff0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_007f8cc4,param_2);
  if (puVar1 != (undefined4 *)0x0) {
    return *puVar1;
  }
  return 0;
}

