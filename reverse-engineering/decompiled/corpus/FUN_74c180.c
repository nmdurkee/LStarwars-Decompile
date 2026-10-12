/* Ghidra analysis pseudocode, not original source.
 * ev_d43409c1beaf04de5181c7e79b8ae898b4513b764b0aa0772119c8ac5b4cb60b
 * Entry: 0x74c180; label: FUN_0074c180
 */

void FUN_0074c180(void)

{
  int in_ECX;
  
  FUN_0074bbc0();
  *(int *)(in_ECX + 0x118) = *(int *)(in_ECX + 0x130 + *(int *)(in_ECX + 0x2c4) * 4) + 0xc;
  return;
}

