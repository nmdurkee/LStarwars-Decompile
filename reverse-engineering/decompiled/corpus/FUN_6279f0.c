/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x6279f0; label: FUN_006279f0
 */

undefined4 FUN_006279f0(int param_1)

{
  if (*(int *)(param_1 + 0x40) != 0) {
    if (*(int *)(param_1 + 0x3c) != 0) {
      FUN_006279f0(*(int *)(param_1 + 0x3c));
    }
    if (param_1 == DAT_02912eac) {
      DAT_02912eac = *(int *)(param_1 + 0x40);
    }
    *(undefined4 *)(*(int *)(param_1 + 0x40) + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x40) = 0;
    return 1;
  }
  if (DAT_02912f30 != 0) {
    if (DAT_02912eb4 != 0) {
      if (*(int *)(DAT_02912eb4 + 0x3c) == 0) {
        DAT_02912eac = DAT_02912eb4;
        return 0;
      }
      DAT_02912eac = FUN_0061f070();
      return 0;
    }
    DAT_02912eac = 0;
  }
  return 0;
}

