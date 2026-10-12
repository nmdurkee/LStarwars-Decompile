/* Ghidra analysis pseudocode, not original source.
 * ev_c05bc3de3023c0a6cb52f4e362146021e78fd9035a9b4ae5f12ca5d880999daa
 * Entry: 0x415000; label: FUN_00415000
 */

void FUN_00415000(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x2c8);
  if (iVar1 != 0) {
    FUN_00514640(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),param_1 + 0x2c8,param_1 + 0x2c8,0,0,0,0,
                 iVar1,*(undefined4 *)(iVar1 + 0x38));
    *(undefined4 *)(param_1 + 0x32c) = 0;
  }
  return;
}

