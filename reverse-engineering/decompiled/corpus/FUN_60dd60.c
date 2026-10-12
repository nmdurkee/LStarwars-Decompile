/* Ghidra analysis pseudocode, not original source.
 * ev_49f26c3128d8416ab7d2a78e52c78c067d57c30a907ee8cca08757c1961064c2
 * Entry: 0x60dd60; label: FUN_0060dd60
 */

void FUN_0060dd60(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  FUN_005c4d40();
  if (1 < DAT_02974d1c) {
    uVar1 = FUN_0060d9b0(2,&DAT_00768df8,&DAT_007690c8);
    *(undefined4 *)(in_ECX + 0x3c) = 0x80;
    *(undefined4 *)(in_ECX + 0xc) = uVar1;
    return;
  }
  uVar1 = FUN_0060d9b0(2,&DAT_007692d8,&DAT_00769598);
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0xc) = uVar1;
  return;
}

