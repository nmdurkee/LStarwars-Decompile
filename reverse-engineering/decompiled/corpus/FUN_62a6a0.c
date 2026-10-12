/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x62a6a0; label: FUN_0062a6a0
 */

undefined2 FUN_0062a6a0(int param_1,int param_2)

{
  if ((param_2 != -1) && (*(int *)(*(int *)(param_1 + 0xc) + param_2 * 4) != 0)) {
    return *(undefined2 *)(*(int *)(*(int *)(param_1 + 8) + param_2 * 4) + 0x48);
  }
  return 0;
}

