/* Ghidra pseudocode, not original source.
 * ev_1103904689436dd579d46533c258b0710963d6b5b648a9f295784d5cea761bb8
 * Entry: 0x634dd0; label: FUN_00634dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00634dd0(void)

{
  int in_ECX;
  
  DAT_0291389c = FUN_005958a0();
  if (DAT_0291389c == 0) {
    DAT_0291389c = *(int *)(in_ECX + 8);
  }
  *(undefined4 *)(DAT_0291389c + 0x4f84) = 0;
  return;
}

