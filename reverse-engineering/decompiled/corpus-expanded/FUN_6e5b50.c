/* Ghidra pseudocode, not original source.
 * ev_05124c72947cda01ab4e957767046c74785846b11639cb0e1fa6987dbeab6c6e
 * Entry: 0x6e5b50; label: FUN_006e5b50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e5b50(int *param_1)

{
  _DAT_0297bea0 = (**(code **)(*param_1 + 8))(param_1);
  return;
}

