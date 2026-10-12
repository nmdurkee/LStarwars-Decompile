/* Ghidra pseudocode, not original source.
 * ev_05124c72947cda01ab4e957767046c74785846b11639cb0e1fa6987dbeab6c6e
 * Entry: 0x6e56a0; label: FUN_006e56a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e56a0(undefined4 param_1,undefined4 param_2)

{
  _DAT_0297bea0 = (**(code **)(*DAT_029765cc + 0xb0))(DAT_029765cc,param_1,param_2);
  return;
}

