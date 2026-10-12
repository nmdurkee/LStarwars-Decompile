/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43bed0; label: FUN_0043bed0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0043bed0(byte param_1)

{
  if ((param_1 != 0xff) && (DAT_00951374 != 0)) {
    return (int)*(short *)(DAT_00951374 + (uint)param_1 * 4);
  }
  return -1;
}

