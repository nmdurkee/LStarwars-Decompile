/* Ghidra pseudocode, not original source.
 * ev_c5aa9bb8cc1ea02955c57ce11c44cd7d2d7b8bb5b9f56b563e0c53fc6061ed49
 * Entry: 0x414ce0; label: FUN_00414ce0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

