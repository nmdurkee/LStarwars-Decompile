/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x51d500; label: FUN_0051d500
 */

undefined4 FUN_0051d500(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = (uint)*(byte *)(in_ECX + 0x143) * 0x5c + *(int *)(*(int *)(in_ECX + 0x158) + 0x7c);
  if (*(char *)(iVar4 + 0x28) == '\0') {
    return 0;
  }
  uVar2 = 0;
  *(undefined4 *)(in_ECX + 0x1b4) = *(undefined4 *)(iVar4 + 4);
  *(undefined4 *)(in_ECX + 0x1b8) = *(undefined4 *)(iVar4 + 8);
  uVar1 = *(undefined4 *)(iVar4 + 0xc);
  *(undefined4 *)(in_ECX + 0x1c0) = 0;
  *(undefined4 *)(in_ECX + 0x1bc) = uVar1;
  fVar3 = *(float *)(iVar4 + 0x10) - 1.0;
  if (fVar3 <= 1.0) {
    fVar3 = 1.0;
  }
  *(float *)(in_ECX + 0x1c4) = fVar3;
  *(undefined4 *)(in_ECX + 0x1cc) = 0;
  *(undefined4 *)(in_ECX + 0x1d0) = 0;
  *(undefined4 *)(in_ECX + 0x1d4) = 0;
  *(undefined4 *)(in_ECX + 0x1d8) = 0;
  *(undefined4 *)(in_ECX + 0x1dc) = 0;
  *(undefined4 *)(in_ECX + 0x1e0) = 0;
  *(undefined4 *)(in_ECX + 0x1cc) = *(undefined4 *)(in_ECX + 0x158);
  *(undefined4 *)(in_ECX + 0x1d0) = **(undefined4 **)(iVar4 + 0x34);
  *(bool *)(in_ECX + 0x1d4) =
       *(char *)(**(int **)(iVar4 + 0x34) + 0x10) == *(char *)(in_ECX + 0x143);
  if (*(char *)(**(int **)(iVar4 + 0x34) + 0x10) != *(char *)(in_ECX + 0x143)) {
    uVar2 = 0x3f800000;
  }
  *(undefined4 *)(in_ECX + 0x1dc) = uVar2;
  return 1;
}

