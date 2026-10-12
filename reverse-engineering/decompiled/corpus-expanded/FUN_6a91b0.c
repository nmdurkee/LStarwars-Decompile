/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a91b0; label: FUN_006a91b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a91b0(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0xc) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x14) + param_2 * 4);
  }
  return 0xffffffff;
}

