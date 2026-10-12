/* Ghidra pseudocode, not original source.
 * ev_5297a07726b91b44a37fb2d5f8434cfe859173f36b4cfd633cbfa32546391649
 * Entry: 0x5958b0; label: FUN_005958b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005958b0(void)

{
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  FUN_00595110(&DAT_00806588,&local_c);
  _DAT_009716e8 = DAT_0095e5c8;
  _DAT_009716ec = DAT_0095e5cc;
  _DAT_009716f0 = DAT_0095e5d0;
  FUN_005fca90(&DAT_0095e5c8);
  return;
}

