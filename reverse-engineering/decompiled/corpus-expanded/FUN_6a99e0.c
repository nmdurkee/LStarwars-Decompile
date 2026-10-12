/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a99e0; label: FUN_006a99e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006a99e0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (0 < *(int *)(param_1 + 8)) {
    iVar1 = FUN_006a98d0(param_1,param_2);
    if (-1 < iVar1) {
      return *(undefined4 *)(*(int *)(param_1 + 0x18) + iVar1 * 4);
    }
  }
  return 0xffffffff;
}

