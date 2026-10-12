/* Ghidra analysis pseudocode, not original source.
 * ev_c620959d101751dfad3e645b6324ffe52b1a2e87d0642b2a26c15ecb61f6256d
 * Entry: 0x6bd3b0; label: FUN_006bd3b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006bd3b0(undefined4 param_1)

{
  float fVar1;
  undefined4 uVar2;
  int in_ECX;
  
  fVar1 = _DAT_0081f9b4 * _DAT_0081f9d8;
  FUN_006ba6a0(1);
  uVar2 = DAT_0081f9bc;
  if (*(int *)(in_ECX + 0x14) == 0) {
    uVar2 = 0xff808080;
  }
  FUN_006ba970(param_1,fVar1,uVar2,0x20);
  uVar2 = DAT_0081f9c0;
  if (*(int *)(in_ECX + 0x14) == 0) {
    uVar2 = 0xff808080;
  }
  FUN_006baa80(param_1,fVar1,uVar2,0x20);
  uVar2 = DAT_0081f9c4;
  if (*(int *)(in_ECX + 0x14) == 0) {
    uVar2 = 0xff808080;
  }
  FUN_006bab90(param_1,fVar1,uVar2,0x20);
  if (DAT_02973a60 != 0) {
    if ((DAT_02973a60 == 2) || (DAT_02973a60 == 3)) {
      FUN_006009c0();
    }
    DAT_02973a60 = 0;
  }
  if ((*(int *)(in_ECX + 0x70) != *(int *)(in_ECX + 0x74)) && (*(int *)(in_ECX + 0x18) != 0)) {
    FUN_006ba6a0(1);
    FUN_006bb430(param_1,fVar1,*(int *)(in_ECX + 0x18) + -1,*(undefined4 *)(in_ECX + 0x70),
                 *(undefined4 *)(in_ECX + 0x74),0x80808080,0x20);
    if (DAT_02973a60 != 0) {
      if ((DAT_02973a60 == 2) || (DAT_02973a60 == 3)) {
        FUN_006009c0();
      }
      DAT_02973a60 = 0;
    }
  }
  return;
}

