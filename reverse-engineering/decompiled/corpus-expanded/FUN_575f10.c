/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x575f10; label: FUN_00575f10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00575f10(int param_1)

{
  if ((param_1 != 0) && (param_1 != DAT_0095142c)) {
    FUN_004f1f10(&DAT_009513b8,param_1);
    FUN_00575820();
    DAT_0095142c = param_1;
    DAT_009513b0 = param_1;
  }
  return;
}

