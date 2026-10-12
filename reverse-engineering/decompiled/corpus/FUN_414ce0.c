/* Ghidra analysis pseudocode, not original source.
 * ev_c05bc3de3023c0a6cb52f4e362146021e78fd9035a9b4ae5f12ca5d880999daa
 * Entry: 0x414ce0; label: FUN_00414ce0
 */

void FUN_00414ce0(void)

{
  int in_EAX;
  
  if ((*(uint *)(*(int *)(*(int *)(in_EAX + 0x54) + 0x24) + 0x90) & 0x8000) != 0) {
    *(uint *)(in_EAX + 0x1f8) = *(uint *)(in_EAX + 0x1f8) | 0x20000;
    return;
  }
  *(uint *)(in_EAX + 0x1f8) = *(uint *)(in_EAX + 0x1f8) & 0xfffdffff;
  return;
}

