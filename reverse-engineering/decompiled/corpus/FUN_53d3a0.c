/* Ghidra analysis pseudocode, not original source.
 * ev_d03c8c013d77d4b4815fe766df72f82b935735dde13e911b202c41b11099d6d0
 * Entry: 0x53d3a0; label: FUN_0053d3a0
 */

void FUN_0053d3a0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_004ef660(*(int *)(in_ECX + 0xc) + *(int *)(in_ECX + 4),param_1,1);
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 1;
  }
  return;
}

