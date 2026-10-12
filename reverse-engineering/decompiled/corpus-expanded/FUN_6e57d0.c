/* Ghidra pseudocode, not original source.
 * ev_05124c72947cda01ab4e957767046c74785846b11639cb0e1fa6987dbeab6c6e
 * Entry: 0x6e57d0; label: FUN_006e57d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006e57d0(undefined4 param_1)

{
  if (DAT_029765cc != (int *)0x0) {
    FUN_006df300();
    _DAT_0297bea0 = (**(code **)(*DAT_029765cc + 0x30))(DAT_029765cc,param_1);
    FUN_006df310();
  }
  return 0;
}

