/* Ghidra analysis pseudocode, not original source.
 * ev_cadbdcea344f284c720862a9d60fea326d89961e952df44594a2f8e4339e7270
 * Entry: 0x52d0d0; label: FUN_0052d0d0
 */

undefined4 FUN_0052d0d0(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uStack0000000c;
  
  if (((param_1 != 0) && (*(char **)(param_1 + 0x10) != (char *)0x0)) &&
     (**(char **)(param_1 + 0x10) != '\0')) {
    uStack0000000c = param_2;
    uVar1 = FUN_0051ad80();
    return uVar1;
  }
  return 0;
}

