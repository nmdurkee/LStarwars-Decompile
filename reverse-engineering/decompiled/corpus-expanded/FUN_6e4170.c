/* Ghidra pseudocode, not original source.
 * ev_bed396bb9d0ac343cc12a945b22dca9b47e381958104004b469ab6f75949f391
 * Entry: 0x6e4170; label: FUN_006e4170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e4170(void)

{
  int in_ECX;
  
  DAT_0280d384 = 0;
  DAT_00986eb4 = 0xffffffff;
  _DAT_0080e194 = 0xffffffff;
  (**(code **)(**(int **)(in_ECX + 4) + 0xa4))(*(int **)(in_ECX + 4));
  FUN_006e34d0();
  return;
}

