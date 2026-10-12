/* Ghidra analysis pseudocode, not original source.
 * ev_89c39211f1406cd3750c6bdd67b17168ccea6fd0f0f78c69056da202eee2c473
 * Entry: 0x55cdf0; label: FUN_0055cdf0
 */

undefined4 FUN_0055cdf0(int param_1)

{
  if (((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) &&
     ((*(int *)(param_1 + 0xcd0) == 0 ||
      ((*(byte *)(*(int *)(param_1 + 0xcd0) + 0x1fc) & 0x80) == 0)))) {
    return 0;
  }
  return 1;
}

