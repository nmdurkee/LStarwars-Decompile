/* Ghidra pseudocode, not original source.
 * ev_ab45728ea6dd43502824c472d7f84a4237b6985bbd98dd18e4509cbe0b313452
 * Entry: 0x698010; label: FUN_00698010
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00698010(void)

{
  int iVar1;
  int *in_EAX;
  int *in_EDX;
  
  iVar1 = DAT_00810dd4;
  if (DAT_00810dd4 != 0x4000) {
    if (in_EAX != (int *)0x0) {
      *in_EAX = *in_EAX * DAT_00810dd4 >> 0xf;
    }
    if (in_EDX != (int *)0x0) {
      *in_EDX = *in_EDX * iVar1 >> 0xf;
    }
  }
  return;
}

