/* Ghidra analysis pseudocode, not original source.
 * ev_7bf4cf8279d8e200655baf4cbe0b44c1a6d004e84309270e7e1edaecfde67eb6
 * Entry: 0x5c7050; label: FUN_005c7050
 */

uint FUN_005c7050(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  
  iVar1 = *(int *)(in_ECX + 0x710);
  uVar3 = 0;
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      cVar2 = FUN_005c6dc0(param_1,param_2,iVar4);
      if (cVar2 != '\0') {
        uVar3 = uVar3 | 1 << ((byte)iVar4 & 0x1f);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  return uVar3;
}

