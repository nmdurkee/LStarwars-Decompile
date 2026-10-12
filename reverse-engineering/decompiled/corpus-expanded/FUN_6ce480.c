/* Ghidra pseudocode, not original source.
 * ev_9b11381a0c0b3e4dd58bf4ee610de1a55b8174f7034ba55ce3625dcac2ea44f3
 * Entry: 0x6ce480; label: FUN_006ce480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006ce480(void)

{
  int iVar1;
  int in_ECX;
  int *extraout_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x2c);
  while (iVar1 != 0) {
    FUN_006ce2b0();
    iVar1 = *extraout_ECX;
  }
  return;
}

