/* Ghidra pseudocode, not original source.
 * ev_05124c72947cda01ab4e957767046c74785846b11639cb0e1fa6987dbeab6c6e
 * Entry: 0x6e5bd0; label: FUN_006e5bd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e5bd0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int *param_5)

{
  _DAT_0297bea0 = (**(code **)(*param_5 + 0x2c))(param_5,param_1,param_2,param_3,param_4);
  return;
}

