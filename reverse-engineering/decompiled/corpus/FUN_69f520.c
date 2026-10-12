/* Ghidra analysis pseudocode, not original source.
 * ev_b895f0b91b7c4ad7f1227b00c98fbe4266a0aaacaad6e08a0ea882306f876365
 * Entry: 0x69f520; label: FUN_0069f520
 */

undefined4 FUN_0069f520(int param_1,int param_2)

{
  param_2 = *(int *)(param_1 + 8) + param_2;
  if (*(int *)(param_1 + 4) < param_2) {
    return 0xffffffff;
  }
  *(int *)(param_1 + 8) = param_2;
  return 0;
}

