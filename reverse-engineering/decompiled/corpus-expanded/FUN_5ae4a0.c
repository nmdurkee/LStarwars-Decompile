/* Ghidra pseudocode, not original source.
 * ev_61672b8aee088191725705707427e6d28989067365c008b5a0fbb4fab739a1ee
 * Entry: 0x5ae4a0; label: FUN_005ae4a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_005ae4a0(int *param_1,uint param_2,byte param_3)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    return false;
  }
  iVar1 = *param_1;
  if (iVar1 == 0) {
    return false;
  }
  if ((param_3 & 1) != 0) {
    return (*(byte *)(iVar1 + 0x24) & 1) != param_2;
  }
  if (param_2 != 0) {
    FUN_005a1030(*(undefined4 *)(iVar1 + 0x20),0xbf800000,1);
    *(byte *)(iVar1 + 0x24) = *(byte *)(iVar1 + 0x24) | 1;
    return true;
  }
  FUN_005a1030(*(undefined4 *)(iVar1 + 0x20),0x3f800000,1);
  *(byte *)(iVar1 + 0x24) = *(byte *)(iVar1 + 0x24) & 0xfe;
  return true;
}

