/* Ghidra pseudocode, not original source.
 * ev_ec6de10755bbe4e6e32c4c75cfe39a8ef4339c5a6ad10c9ef5357c0f43b1bab3
 * Entry: 0x6bd3b0; label: FUN_006bd3b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

