/* Ghidra pseudocode, not original source.
 * ev_01c84f1d9d20bf940b93d5cccd5d039a55498943f529f614c2585109312f1f15
 * Entry: 0x577710; label: FUN_00577710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00577710(void)

{
  if (DAT_00951882 == '\0') {
    DAT_009518e0 = 0;
    DAT_009518e4 = 0;
    DAT_009518e8 = _DAT_00951888;
    FUN_005b35a0(&DAT_009518e0,&DAT_009518e0,DAT_0095188c);
    FUN_005b3620(&DAT_009518e0,&DAT_009518e0,DAT_0095188e);
    DAT_009514dc = DAT_00951890;
    FUN_005b37d0(&DAT_009518e0,&DAT_009518e0,&DAT_009518d4);
  }
  return;
}

