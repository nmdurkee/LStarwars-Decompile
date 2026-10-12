/* Ghidra pseudocode, not original source.
 * ev_ab45728ea6dd43502824c472d7f84a4237b6985bbd98dd18e4509cbe0b313452
 * Entry: 0x696c50; label: FUN_00696c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00696c50(void)

{
  void *in_ECX;
  
  _memset(in_ECX,0,0xda8);
  if (DAT_02972c08 == 0) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_02962b90);
    DAT_02972c08 = 1;
  }
  return;
}

