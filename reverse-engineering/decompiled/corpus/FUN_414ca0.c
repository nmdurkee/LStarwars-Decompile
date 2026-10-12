/* Ghidra analysis pseudocode, not original source.
 * ev_c05bc3de3023c0a6cb52f4e362146021e78fd9035a9b4ae5f12ca5d880999daa
 * Entry: 0x414ca0; label: FUN_00414ca0
 */

void FUN_00414ca0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x54);
  *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(iVar1 + 0x3c);
  *(undefined4 *)(param_1 + 0xffc) = *(undefined4 *)(iVar1 + 0x30);
  *(undefined4 *)(param_1 + 0xff0) = *(undefined4 *)(iVar1 + 0x34);
  *(undefined4 *)(param_1 + 0xff4) = *(undefined4 *)(iVar1 + 0x38);
  FUN_0055ccd0();
  return;
}

