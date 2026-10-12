/* Ghidra pseudocode, not original source.
 * ev_05124c72947cda01ab4e957767046c74785846b11639cb0e1fa6987dbeab6c6e
 * Entry: 0x6e5630; label: FUN_006e5630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e5630(uint param_1,int param_2)

{
  if ((DAT_008282b4 != '\0') && (param_1 < 5)) {
    if (*(int *)(&DAT_0297bec0 + param_1 * 4) == param_2) {
      return;
    }
    *(int *)(&DAT_0297bec0 + param_1 * 4) = param_2;
  }
  _DAT_0297bea0 = (**(code **)(*DAT_029765cc + 0x104))(DAT_029765cc,param_1,param_2);
  return;
}

