/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55f3e0; label: FUN_0055f3e0
 */

void FUN_0055f3e0(int param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  
  if (((param_1 != 0) && (*(int *)(in_ECX + 0x808) == 0)) &&
     (iVar2 = 0, 0 < *(int *)(in_ECX + 0x70c))) {
    puVar1 = (undefined4 *)(in_ECX + 0x2b8);
    do {
      *puVar1 = puVar1[-1];
      puVar1[0x11] = puVar1[0x10];
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 0xe0;
    } while (iVar2 < *(int *)(in_ECX + 0x70c));
  }
  *(int *)(in_ECX + 0x808) = param_1;
  return;
}

