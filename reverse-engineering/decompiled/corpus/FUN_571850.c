/* Ghidra analysis pseudocode, not original source.
 * ev_f7d91f236b6f78f4ea8add50dcf127a99c92e4ff6e0b09a45204423ea42edd2e
 * Entry: 0x571850; label: FUN_00571850
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

