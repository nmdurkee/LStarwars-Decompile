/* Ghidra pseudocode, not original source.
 * ev_ab45728ea6dd43502824c472d7f84a4237b6985bbd98dd18e4509cbe0b313452
 * Entry: 0x696c10; label: FUN_00696c10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00696c10(void)

{
  uint in_EAX;
  int iVar1;
  int in_ECX;
  
  iVar1 = ((in_EAX ^ (int)in_EAX >> 0x1f) - ((int)in_EAX >> 0x1f)) * in_ECX;
  return (((int)(iVar1 + (iVar1 >> 0x1f & 0xfffU)) >> 0xc) * 0x30) / (in_ECX / 1000);
}

