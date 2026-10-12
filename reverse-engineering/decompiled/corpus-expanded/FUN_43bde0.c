/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43bde0; label: FUN_0043bde0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0043bde0(byte param_1)

{
  short sVar1;
  
  if (((param_1 != 0xff) && (DAT_00951374 != 0)) &&
     (sVar1 = *(short *)(DAT_00951374 + (uint)param_1 * 4), sVar1 != -1)) {
    return *(undefined4 *)(sVar1 * 0x4c + 0xc + *(int *)(DAT_029130e4 + 0x20));
  }
  return 0;
}

