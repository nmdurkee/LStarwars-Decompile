/* Ghidra analysis pseudocode, not original source.
 * ev_07efd457ec9a37501bdb802bda98d4fdf679445de954c80baf7ce8f2bb24f771
 * Entry: 0x6d37d0; label: FUN_006d37d0
 */

void FUN_006d37d0(void)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  short *psVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = 0;
  psVar3 = (short *)(in_ECX + 0x635e);
  iVar5 = 4;
  do {
    iVar4 = 8;
    do {
      uVar2 = uVar1 * 2 + 1;
      if (-1 < (int)uVar1) {
        uVar2 = uVar1 * 2;
      }
      uVar2 = (int)psVar3[-2] ^ uVar2 ^ 0x12345678;
      uVar1 = uVar2 * 2 + 1;
      if (-1 < (int)uVar2) {
        uVar1 = uVar2 * 2;
      }
      uVar2 = *(byte *)(psVar3 + -3) ^ uVar1 ^ 0x12345678;
      uVar1 = uVar2 * 2 + 1;
      if (-1 < (int)uVar2) {
        uVar1 = uVar2 * 2;
      }
      uVar2 = (int)*psVar3 ^ uVar1 ^ 0x12345678;
      uVar1 = uVar2 * 2 + 1;
      if (-1 < (int)uVar2) {
        uVar1 = uVar2 * 2;
      }
      uVar2 = *(byte *)(psVar3 + -1) ^ uVar1 ^ 0x12345678;
      uVar1 = uVar2 * 2 + 1;
      if (-1 < (int)uVar2) {
        uVar1 = uVar2 * 2;
      }
      uVar2 = (int)psVar3[2] ^ uVar1 ^ 0x12345678;
      uVar1 = uVar2 * 2 + 1;
      if (-1 < (int)uVar2) {
        uVar1 = uVar2 * 2;
      }
      uVar2 = *(byte *)(psVar3 + 1) ^ uVar1 ^ 0x12345678;
      uVar1 = uVar2 * 2 + 1;
      if (-1 < (int)uVar2) {
        uVar1 = uVar2 * 2;
      }
      uVar2 = (int)psVar3[4] ^ uVar1 ^ 0x12345678;
      uVar1 = uVar2 * 2 + 1;
      if (-1 < (int)uVar2) {
        uVar1 = uVar2 * 2;
      }
      uVar1 = *(byte *)(psVar3 + 3) ^ uVar1 ^ 0x12345678;
      psVar3 = psVar3 + 8;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return;
}

