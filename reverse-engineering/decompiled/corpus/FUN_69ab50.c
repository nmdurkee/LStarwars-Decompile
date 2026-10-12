/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x69ab50; label: FUN_0069ab50
 */

int FUN_0069ab50(float param_1)

{
  ushort uVar1;
  int iVar2;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x40) == '\0') {
    iVar2 = FUN_0069a280(param_1);
    return iVar2;
  }
  FUN_004ffaa0(DAT_02973a00);
  if (*(int *)(in_ECX + 0x318) == 0) {
    FUN_004ffac0(DAT_02973a00);
    return -1;
  }
  FUN_0069d560(in_ECX + 0x48,(double)param_1);
  iVar2 = FUN_0069d760(in_ECX + 0x48);
  uVar1 = *(ushort *)(in_ECX + 0x32c);
  FUN_004ffac0(DAT_02973a00);
  return iVar2 * (uint)uVar1;
}

