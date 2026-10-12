/* Ghidra pseudocode, not original source.
 * ev_05124c72947cda01ab4e957767046c74785846b11639cb0e1fa6987dbeab6c6e
 * Entry: 0x6e5590; label: FUN_006e5590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e5590(int param_1,int param_2,int param_3,int param_4)

{
  if (DAT_008282b4 != '\0') {
    if ((((DAT_0297beb0 == param_2) && (DAT_0297beb4 == param_4)) && (DAT_0297beb8 == param_1)) &&
       (DAT_0297bebc == param_3)) {
      return;
    }
    DAT_0297beb0 = param_2;
    DAT_0297beb8 = param_1;
    DAT_0297beb4 = param_4;
    DAT_0297bebc = param_3;
  }
  _DAT_0297bea0 = (**(code **)(*DAT_029765cc + 400))(DAT_029765cc,param_1,param_2,param_3,param_4);
  return;
}

