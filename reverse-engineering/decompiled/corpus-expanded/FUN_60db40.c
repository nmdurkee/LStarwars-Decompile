/* Ghidra pseudocode, not original source.
 * ev_e349fb5d4996fa1cecd3bcddaaa967a101a71b87d72fe496b907a3d03e81288d
 * Entry: 0x60db40; label: FUN_0060db40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060db40(void)

{
  FUN_005f2580();
  DAT_009737fc = FUN_0060d9b0(2,&DAT_00765708,&DAT_007657b0);
  _DAT_00973808 = 0;
  DAT_00973810 = 0;
  if (1 < DAT_02974d1c) {
    DAT_00973814 = FUN_0060d9b0(2,&DAT_00765860,&DAT_00765ac0);
    DAT_00973818 = FUN_0060d9b0(2,&DAT_00765cb8,&DAT_00765da8);
  }
  DAT_02854c24 = FUN_0060d9b0(2,&DAT_00765f48,&DAT_007660e8);
  DAT_02854c28 = FUN_0060d9b0(2,&DAT_00765e58,&DAT_00765da8);
  return;
}

