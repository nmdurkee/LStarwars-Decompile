/* Ghidra analysis pseudocode, not original source.
 * ev_5c5e85395afb46ea48eeeced9462a622408ed7e413dd4eac1252ab90af09b35e
 * Entry: 0x4a85e0; label: FUN_004a85e0
 */

void FUN_004a85e0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  bool bVar3;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0x50) + 0xc);
  bVar3 = piVar1[3] == 0;
  if (*piVar1 == 0) {
    if (!bVar3) {
      *(undefined2 *)(in_ECX + 0x42) = 3;
      return;
    }
  }
  else {
    if ((bVar3) ||
       (iVar2 = *(int *)(*(int *)(in_ECX + 0x54) + 0x24),
       *(float *)(*(int *)(in_ECX + 0xca4) + 0x28) <=
       (*(float *)(iVar2 + 0x1c) + *(float *)(iVar2 + 0x18)) * 0.5)) {
      *(undefined2 *)(in_ECX + 0x42) = 0;
      return;
    }
    *(undefined2 *)(in_ECX + 0x42) = 3;
  }
  return;
}

