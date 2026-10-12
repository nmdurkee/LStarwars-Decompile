/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6ce4a0; label: FUN_006ce4a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006ce4a0(void)

{
  int in_ECX;
  
  if (*(float *)(in_ECX + 0x48) < _DAT_0081fa00) {
    FUN_006c7660();
    return;
  }
  FUN_006c7730();
  return;
}

