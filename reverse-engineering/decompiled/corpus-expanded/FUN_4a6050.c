/* Ghidra pseudocode, not original source.
 * ev_a85b3e4898e579c25a43afce2c9968e46b76c95f9b8b71b7b173505cf03a6bab
 * Entry: 0x4a6050; label: FUN_004a6050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004a6050(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x28c) != '\0') {
    iVar1 = *(int *)(*(int *)(param_1 + 0x54) + 0x24);
    iVar2 = (int)*(char *)(iVar1 + 0xfc);
    if (((iVar2 != -1) && (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar2 * 4) != 0)) ||
       ((iVar2 = (int)*(char *)(iVar1 + 0xf8), iVar2 != -1 &&
        (*(int *)(*(int *)(param_1 + 0x50) + 0x14 + iVar2 * 4) != 0)))) {
      return iVar2 * 0x40 + 0x834 + param_1;
    }
  }
  return param_1 + 0x80;
}

