/* Ghidra analysis pseudocode, not original source.
 * ev_023debdfa9c039acf518a8e1f05c99a974f400faccf57ad72851f9420ef75a11
 * Entry: 0x4409b0; label: FUN_004409b0
 */

undefined4 FUN_004409b0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00802644,param_2);
  if (puVar1 != (undefined4 *)0x0) {
    return *puVar1;
  }
  return 0;
}

