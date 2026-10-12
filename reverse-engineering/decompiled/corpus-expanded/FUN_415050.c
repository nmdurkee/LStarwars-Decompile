/* Ghidra pseudocode, not original source.
 * ev_c5aa9bb8cc1ea02955c57ce11c44cd7d2d7b8bb5b9f56b563e0c53fc6061ed49
 * Entry: 0x415050; label: FUN_00415050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00415050(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) != '\0') ||
     (iVar3 = 0x76, (*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x80) == 0)) {
    iVar3 = 0x19;
  }
  if ((*(int *)(param_1 + 0xcc0) != 0) && (*(char *)(*(int *)(param_1 + 0xcc0) + 0x7d) != '\0')) {
    return 0x97;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x50) + 0xc);
  if (((*(int *)(iVar1 + 4) != 0) && (*(int *)(iVar1 + iVar3 * 4) == 0)) ||
     (((iVar2 = *(int *)(iVar1 + iVar3 * 4), iVar2 == 0 || (*(int *)(iVar1 + 4) != 0)) &&
      ((((*(byte *)(param_1 + 0xe22) & 1) == 0 && (*(char *)(param_1 + 0xe33) != '\x01')) ||
       (iVar2 == 0)))))) {
    iVar3 = 1;
  }
  return iVar3;
}

