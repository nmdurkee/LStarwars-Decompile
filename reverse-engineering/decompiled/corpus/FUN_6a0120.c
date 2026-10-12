/* Ghidra analysis pseudocode, not original source.
 * ev_82e7b7710cce4f59c14fa183879226b2bf4ae3fcf6b271436ad9d0f6108f076a
 * Entry: 0x6a0120; label: FUN_006a0120
 */

undefined4 FUN_006a0120(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0x1c) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x1c) + param_2 * 4);
  }
  return 0xffffffff;
}

