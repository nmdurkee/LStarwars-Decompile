/* Ghidra pseudocode, not original source.
 * ev_7cce3243898a12dda79e95a496780a4d79cb1010b8a976b902fd46336e9989b6
 * Entry: 0x4d5ab0; label: FUN_004d5ab0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_004d5ab0(int *param_1,uint param_2,byte param_3)

{
  int iVar1;
  
  if ((param_1 == (int *)0x0) || (iVar1 = *param_1, iVar1 == 0)) {
    return false;
  }
  if ((param_3 & 1) != 0) {
    return param_2 != *(ushort *)(iVar1 + 0x62);
  }
  if (param_2 != 0) {
    *(undefined2 *)(iVar1 + 0x62) = 1;
    *(ushort *)(iVar1 + 0x68) = *(ushort *)(iVar1 + 0x68) & 0xffbf;
    return true;
  }
  *(ushort *)(iVar1 + 0x68) = *(ushort *)(iVar1 + 0x68) | 0x40;
  *(undefined2 *)(iVar1 + 0x62) = 0;
  return true;
}

