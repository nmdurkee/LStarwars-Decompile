/* Ghidra pseudocode, not original source.
 * ev_7cce3243898a12dda79e95a496780a4d79cb1010b8a976b902fd46336e9989b6
 * Entry: 0x4d74f0; label: FUN_004d74f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d74f0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (param_2 != 0) {
    *(undefined2 *)(iVar1 + 0x62) = 0;
    *(ushort *)(iVar1 + 0x68) = *(ushort *)(iVar1 + 0x68) | 0x40;
    return;
  }
  *(ushort *)(iVar1 + 0x68) = *(ushort *)(iVar1 + 0x68) & 0xffbf;
  return;
}

