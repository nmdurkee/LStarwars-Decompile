/* Ghidra pseudocode, not original source.
 * ev_ab45728ea6dd43502824c472d7f84a4237b6985bbd98dd18e4509cbe0b313452
 * Entry: 0x696c90; label: FUN_00696c90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00696c90(int param_1)

{
  int *piVar1;
  int in_ECX;
  
  EnterCriticalSection((LPCRITICAL_SECTION)&DAT_02972bcc);
  param_1 = param_1 * 0x40c;
  if (*(int *)(param_1 + *(int *)(in_ECX + 0xd0c)) != 0) {
    piVar1 = *(int **)(param_1 + *(int *)(in_ECX + 0xd0c));
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + *(int *)(in_ECX + 0xd0c)) = 0;
  }
  *(undefined4 *)(param_1 + *(int *)(in_ECX + 0xd0c)) = 0;
  *(undefined1 *)(param_1 + 0x404 + *(int *)(in_ECX + 0xd0c)) = 0;
                    /* WARNING: Could not recover jumptable at 0x00696cf7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_02972bcc);
  return;
}

