/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43c090; label: FUN_0043c090
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0043c090(int param_1)

{
  short sVar1;
  
  if (param_1 != -1) {
    sVar1 = *(short *)(*(int *)(DAT_029130e4 + 0x1c) + param_1 * 2);
    if (sVar1 != -1) {
      return *(undefined4 *)(sVar1 * 0x54 + 4 + *(int *)(DAT_029130e4 + 0x18));
    }
  }
  return 0;
}

