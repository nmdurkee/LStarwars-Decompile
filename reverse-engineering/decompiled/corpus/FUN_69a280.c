/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x69a280; label: FUN_0069a280
 */

int FUN_0069a280(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  
  uVar1 = *(ushort *)(in_ECX + 0x24);
  iVar3 = FUN_006e6b90();
  iVar4 = *(int *)(in_ECX + 0x30);
  *(int *)(in_ECX + 0x34) = iVar3;
  iVar5 = iVar4;
  if (iVar3 <= iVar4) {
    iVar5 = iVar3;
  }
  iVar2 = *(int *)(in_ECX + 0x2c);
  if (iVar5 < iVar2) {
    *(int *)(in_ECX + 0x34) = iVar2;
    return (uint)uVar1 * iVar2;
  }
  if (iVar3 <= iVar4) {
    iVar4 = iVar3;
  }
  *(int *)(in_ECX + 0x34) = iVar4;
  return (uint)uVar1 * iVar4;
}

