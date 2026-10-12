/* Ghidra pseudocode, not original source.
 * ev_73d54611eb9c539f60191f4cc2589103d1525e4e98579cab30a489e0835b3840
 * Entry: 0x652450; label: FUN_00652450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00652450(int *param_1)

{
  int iVar1;
  int iVar2;
  
  DAT_02962028 = param_1;
  DAT_0296202c = 0;
  if (param_1 != (int *)0x0) {
    iVar2 = 0;
    iVar1 = *param_1;
    while (iVar1 != 0) {
      FUN_004f1ff0(iVar1);
      DAT_0296202c = DAT_0296202c + 1;
      iVar2 = iVar2 + 1;
      iVar1 = param_1[iVar2 * 7];
    }
  }
  return;
}

