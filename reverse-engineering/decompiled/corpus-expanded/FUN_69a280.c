/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x69a280; label: FUN_0069a280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

