/* Ghidra analysis pseudocode, not original source.
 * ev_7062545ad2ab2af07ec33b13480d196f765b27a757bdc9b0fea79766ea2b2f64
 * Entry: 0x467890; label: FUN_00467890
 */

undefined4 FUN_00467890(int param_1)

{
  int iVar1;
  
  if ((((*(uint *)(param_1 + 0x74) & 2) == 0) &&
      ((*(float *)(param_1 + 0x4c) <= 0.0 || ((*(uint *)(param_1 + 0xa0) & 0x2000) != 0)))) &&
     (((*(uint *)(param_1 + 0x74) & 0x40) == 0 || ((*(uint *)(param_1 + 0xa0) & 0x800) != 0)))) {
    iVar1 = *(int *)(param_1 + 0x28);
    if (iVar1 != 0) {
      if ((*(byte *)(param_1 + 0xa0) & 0x40) == 0) {
        if (*(int *)(iVar1 + 0xc) != 2) {
          return 0;
        }
      }
      else if (*(int *)(iVar1 + 0xc) != 0) {
        return 0;
      }
    }
    return 1;
  }
  return 0;
}

