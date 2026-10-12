/* Ghidra analysis pseudocode, not original source.
 * ev_49f26c3128d8416ab7d2a78e52c78c067d57c30a907ee8cca08757c1961064c2
 * Entry: 0x60dbe0; label: FUN_0060dbe0
 */

void FUN_0060dbe0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  FUN_005e5d20();
  if (DAT_02974d1c < 2) {
    uVar1 = FUN_0060d9b0(2,&DAT_00766c50,&DAT_00766ef0);
    *(undefined4 *)(in_ECX + 0x24) = uVar1;
    uVar1 = FUN_0060d9b0(2,&DAT_00767198,&DAT_00766ef0);
    *(undefined4 *)(in_ECX + 0x2c) = uVar1;
    uVar1 = FUN_0060d9b0(2,&DAT_00766c50,&DAT_00767068);
    *(undefined4 *)(in_ECX + 0x148) = uVar1;
    uVar1 = FUN_0060d9b0(2,&DAT_00767198,&DAT_00767068);
    *(undefined4 *)(in_ECX + 0x150) = 0;
    *(undefined4 *)(in_ECX + 0x154) = 1;
    *(undefined4 *)(in_ECX + 0x158) = 2;
    *(undefined4 *)(in_ECX + 0x15c) = 3;
  }
  else {
    uVar1 = FUN_0060d9b0(2,&DAT_007662f0,&DAT_00766590);
    *(undefined4 *)(in_ECX + 0x24) = uVar1;
    uVar1 = FUN_0060d9b0(2,&DAT_00766838,&DAT_00766590);
    *(undefined4 *)(in_ECX + 0x2c) = uVar1;
    uVar1 = FUN_0060d9b0(2,&DAT_007662f0,&DAT_00766708);
    *(undefined4 *)(in_ECX + 0x148) = uVar1;
    uVar1 = FUN_0060d9b0(2,&DAT_00766838,&DAT_00766708);
    *(undefined4 *)(in_ECX + 0x150) = 0x82;
    *(undefined4 *)(in_ECX + 0x154) = 0x88;
    *(undefined4 *)(in_ECX + 0x158) = 0x89;
    *(undefined4 *)(in_ECX + 0x15c) = 0x8a;
  }
  *(undefined4 *)(in_ECX + 0x14c) = uVar1;
  uVar1 = FUN_00605a10();
  *(undefined4 *)(in_ECX + 0x144) = uVar1;
  return;
}

