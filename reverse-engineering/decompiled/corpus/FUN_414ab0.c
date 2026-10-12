/* Ghidra analysis pseudocode, not original source.
 * ev_c05bc3de3023c0a6cb52f4e362146021e78fd9035a9b4ae5f12ca5d880999daa
 * Entry: 0x414ab0; label: FUN_00414ab0
 */

void FUN_00414ab0(int param_1,undefined4 param_2)

{
  *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) & 0xfff8ffff;
  *(undefined4 *)(param_1 + 0x1018) = param_2;
  return;
}

