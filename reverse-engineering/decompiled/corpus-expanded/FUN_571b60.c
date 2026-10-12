/* Ghidra pseudocode, not original source.
 * ev_565248e81838fc57af25e3b2c05c11c2e8daf24aacbb3d036db872a2a4b2fd33
 * Entry: 0x571b60; label: FUN_00571b60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00571b60(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((((param_1 != 0) && (-1 < param_2)) && (param_2 < DAT_00950ff8)) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 8) + param_2 * 0x14), iVar1 != -1)) {
    FUN_0064b370(iVar1,param_3,1);
  }
  return;
}

