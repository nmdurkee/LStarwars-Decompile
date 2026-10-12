/* Ghidra pseudocode, not original source.
 * ev_1545e5b34141c1614daa034024a98821bd7642306100b3a505193274c33334db
 * Entry: 0x4e3590; label: FUN_004e3590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e3590(void)

{
  undefined4 uVar1;
  
  _DAT_008895ac = 0;
  DAT_00889608 = 0;
  uVar1 = FUN_0056a9d0("ball_blowup_null");
  DAT_008000a8 = FUN_0056aa40(PTR_DAT_00802c54,uVar1);
  return;
}

