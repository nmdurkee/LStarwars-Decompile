/* Ghidra pseudocode, not original source.
 * ev_565248e81838fc57af25e3b2c05c11c2e8daf24aacbb3d036db872a2a4b2fd33
 * Entry: 0x571850; label: FUN_00571850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00571850(int *param_1)

{
  int iVar1;
  
  DAT_00950ff8 = 0;
  DAT_00950ffc = param_1;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    DAT_00950ff8 = 0;
    while (iVar1 != 0) {
      param_1 = param_1 + 1;
      DAT_00950ff8 = DAT_00950ff8 + 1;
      iVar1 = *param_1;
    }
  }
  return;
}

