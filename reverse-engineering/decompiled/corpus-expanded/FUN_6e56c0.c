/* Ghidra pseudocode, not original source.
 * ev_05124c72947cda01ab4e957767046c74785846b11639cb0e1fa6987dbeab6c6e
 * Entry: 0x6e56c0; label: FUN_006e56c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e56c0(int param_1)

{
  if (DAT_008282b4 != '\0') {
    if (DAT_0297bea8 == param_1) {
      return;
    }
    DAT_0297bea8 = param_1;
  }
  _DAT_0297bea0 = (**(code **)(*DAT_029765cc + 0x15c))(DAT_029765cc,param_1);
  return;
}

