/* Ghidra analysis pseudocode, not original source.
 * ev_ac6eb4b39bdf1aa97860dd7a32d700b8b6252d0c8ecf493d0278bc767f8ce849
 * Entry: 0x58b3b0; label: FUN_0058b3b0
 */

void FUN_0058b3b0(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_005cfac0(param_1);
  if ((iVar1 != 0) && (DAT_00955568 < 0x10)) {
    (&DAT_009553e8)[DAT_00955568 * 6] = param_1;
    (&DAT_009553fc)[DAT_00955568 * 0xc] = param_2;
    FUN_005d0260(param_1,&DAT_009553ec + DAT_00955568 * 6,&DAT_009553f8 + DAT_00955568 * 6);
    uVar2 = FUN_005d0330(param_1);
    FUN_005b30a0(&DAT_009553ec + DAT_00955568 * 6,&DAT_009553ec + DAT_00955568 * 6,uVar2);
    DAT_00955568 = DAT_00955568 + 1;
  }
  return;
}

