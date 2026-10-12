/* Ghidra analysis pseudocode, not original source.
 * ev_9ea77467f72f0a730098339cc8760ef11d2ea4126d873e77c8bb761228bbcc9d
 * Entry: 0x4cfb30; label: FUN_004cfb30
 */

void FUN_004cfb30(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xd4) != 0) {
      FUN_004399e0(*(int *)(param_1 + 0xd4),param_1 + 0x30);
    }
    uVar3 = 0x200;
    if ((*(int *)(param_1 + 0xd4) != 0) &&
       ((*(byte *)(*(int *)(param_1 + 0xd4) + 0x1fc) & 0x80) != 0)) {
      iVar2 = FUN_0056e160(0x17);
      if (iVar2 != 0) {
        uVar3 = 0x1200;
      }
    }
    iVar2 = FUN_00426de0(param_1 + 0x30,uVar3);
    if (((iVar2 != 0) && (*(int *)(param_1 + 0xd4) != 0)) &&
       ((cVar1 = *(char *)(*(int *)(param_1 + 0xd4) + 0x280), cVar1 == '\0' || (cVar1 == '\x01'))))
    {
      *(char *)(iVar2 + 0x33) = cVar1;
    }
  }
  return;
}

