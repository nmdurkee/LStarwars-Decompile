/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x62c350; label: FUN_0062c350
 */

uint FUN_0062c350(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = FUN_006e6b90();
  uVar3 = 0;
  if (0xffff < (int)uVar1) {
    uVar3 = uVar1 >> 0x10;
    uVar1 = uVar1 + uVar3 * -0x10000;
  }
  uVar2 = FUN_005b9e30();
  if (uVar2 >> 0x10 < uVar1) {
    uVar3 = uVar3 + 1;
  }
  return uVar3;
}

