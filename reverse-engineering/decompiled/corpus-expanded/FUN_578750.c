/* Ghidra pseudocode, not original source.
 * ev_01c84f1d9d20bf940b93d5cccd5d039a55498943f529f614c2585109312f1f15
 * Entry: 0x578750; label: FUN_00578750
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void * FUN_00578750(undefined4 param_1)

{
  _memset(DAT_009519f4,0,0x80);
  _memset(DAT_009519ec,0,0x80);
  _DAT_00951b70 = 0;
  _DAT_009519f0 = param_1;
  return DAT_009519f4;
}

