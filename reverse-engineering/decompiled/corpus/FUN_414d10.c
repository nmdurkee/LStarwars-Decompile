/* Ghidra analysis pseudocode, not original source.
 * ev_c05bc3de3023c0a6cb52f4e362146021e78fd9035a9b4ae5f12ca5d880999daa
 * Entry: 0x414d10; label: FUN_00414d10
 */

void FUN_00414d10(int param_1,char param_2)

{
  *(char *)(param_1 + 0x107f) = param_2;
  if ((int)(uint)*(byte *)(param_1 + 0x107e) < (int)param_2) {
    *(byte *)(param_1 + 0x107f) = *(byte *)(param_1 + 0x107e);
  }
  return;
}

