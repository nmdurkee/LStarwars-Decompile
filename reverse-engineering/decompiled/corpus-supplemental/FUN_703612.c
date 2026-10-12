/* Ghidra pseudocode, not original source.
 * ev_659eea1dc00a859f9d32b97d98369d0a367714cfb07a93b4448bfffc51247c8f
 * Entry: 0x703612; label: FUN_00703612
 * Boundary hypotheses: reports/native-supplemental-entry-inspection.json.
 */

undefined4 FUN_00703612(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xc);
  if (iVar1 != 0) {
    return CONCAT31((int3)((uint)iVar1 >> 8),*(undefined1 *)(*(int *)(in_ECX + 8) + -1 + iVar1));
  }
  return 0;
}

