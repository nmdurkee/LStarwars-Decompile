/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c73c0; label: FUN_006c73c0
 */

void FUN_006c73c0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  undefined4 *puVar3;
  
  iVar2 = *in_ECX;
  while( true ) {
    if (iVar2 == 0) {
      iVar2 = FUN_00633440(0x18,1);
      if ((iVar2 != 0) && (iVar2 = FUN_006c7290(), iVar2 != 0)) {
        iVar1 = *(int *)(iVar2 + 0x10);
        *(int *)(iVar2 + 0x10) = iVar1 + 1;
        puVar3 = (undefined4 *)(iVar1 * 0x10 + *(int *)(iVar2 + 0x14));
        *puVar3 = *param_1;
        puVar3[1] = param_1[1];
        puVar3[2] = param_1[2];
        puVar3[3] = param_1[3];
        *(undefined4 *)(iVar2 + 4) = 0;
        *(int *)(iVar2 + 8) = in_ECX[1];
        if (in_ECX[1] != 0) {
          *(int *)(in_ECX[1] + 4) = iVar2;
        }
        in_ECX[1] = iVar2;
        if (*in_ECX == 0) {
          *in_ECX = iVar2;
        }
        in_ECX[2] = in_ECX[2] + 1;
      }
      return;
    }
    iVar1 = *(int *)(iVar2 + 0x10);
    if (iVar1 < *(int *)(iVar2 + 0xc)) break;
    iVar2 = *(int *)(iVar2 + 4);
  }
  puVar3 = (undefined4 *)(iVar1 * 0x10 + *(int *)(iVar2 + 0x14));
  *(int *)(iVar2 + 0x10) = iVar1 + 1;
  *puVar3 = *param_1;
  puVar3[1] = param_1[1];
  puVar3[2] = param_1[2];
  puVar3[3] = param_1[3];
  return;
}

