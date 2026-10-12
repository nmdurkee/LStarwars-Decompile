/* Ghidra analysis pseudocode, not original source.
 * ev_c05bc3de3023c0a6cb52f4e362146021e78fd9035a9b4ae5f12ca5d880999daa
 * Entry: 0x414c50; label: FUN_00414c50
 */

void FUN_00414c50(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_0058a900(0);
  if ((iVar1 == 0) && (param_1 != 0)) {
    iVar1 = FUN_00440120(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),param_1);
    if ((iVar1 != 0) && ((DAT_0093b2a4 == 0 || ((*(uint *)(iVar1 + 0x1f8) & 0x400) != 0)))) {
      FUN_00414bb0();
      return;
    }
  }
  return;
}

