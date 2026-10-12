/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ad2f0; label: FUN_005ad2f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005ad2f0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (param_2 == 0) {
    if ((*(ushort *)(iVar1 + 0x13a) & 0x30) != 0) {
      return 1;
    }
  }
  else if (param_2 == 1) {
    if ((*(byte *)(iVar1 + 0x13a) & 0x80) != 0) {
      return 1;
    }
  }
  else if ((param_2 == 2) && (*(byte *)(iVar1 + 0x131) <= *(byte *)(iVar1 + 0x132))) {
    return 1;
  }
  return 0;
}

