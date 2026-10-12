/* Ghidra analysis pseudocode, not original source.
 * ev_7062545ad2ab2af07ec33b13480d196f765b27a757bdc9b0fea79766ea2b2f64
 * Entry: 0x4677d0; label: FUN_004677d0
 */

undefined4 FUN_004677d0(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (((*(uint *)(param_1 + 0xa0) & 0x100) != 0) && (*(short *)(param_2 + 0x106c) != -1)) {
    for (puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x28) + 0x18); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      if (*(short *)(puVar1[9] + 2) == *(short *)(param_2 + 0x106c)) {
        return 1;
      }
    }
  }
  return 0;
}

