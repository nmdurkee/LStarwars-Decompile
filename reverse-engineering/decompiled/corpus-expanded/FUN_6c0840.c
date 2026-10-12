/* Ghidra pseudocode, not original source.
 * ev_caa872c778113341e1df0ccd71c86dbd4a603da626237a6695cd46c57da8fb02
 * Entry: 0x6c0840; label: FUN_006c0840
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006c0840(void)

{
  int *in_ECX;
  undefined4 uStack00000008;
  
  uStack00000008 = 0;
                    /* WARNING: Could not recover jumptable at 0x006c0857. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x14))();
  return;
}

