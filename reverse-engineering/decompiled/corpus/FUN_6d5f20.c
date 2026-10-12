/* Ghidra analysis pseudocode, not original source.
 * ev_374b9498cac1f2764533d2b2425c9906eb7f8dc5d78a775ccd4080d89a8f30aa
 * Entry: 0x6d5f20; label: FUN_006d5f20
 */

uint FUN_006d5f20(uint param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  undefined1 local_4 [4];
  
  uVar3 = param_1;
  if (param_1 == 0) {
    if (param_2 == 0) {
      return 0xfffffffe;
    }
    uVar3 = 0;
    pbVar4 = (byte *)(DAT_02975144 + 0x67f1);
    while (((0x1f < uVar3 || (bVar1 = *pbVar4, (char)bVar1 < '\0')) ||
           ((param_2 & 1 << (bVar1 & 0x1f)) == 0))) {
      uVar3 = uVar3 + 1;
      pbVar4 = pbVar4 + 6;
      if (0x1f < (int)uVar3) {
        return 0xffffffff;
      }
    }
    if ((param_2 & ~(1 << (bVar1 & 0x1f))) != 0) {
      return 0xfffffffb;
    }
  }
  else {
    if (param_2 != 0) {
      return 0xfffffffd;
    }
    uVar5 = 0;
    do {
      iVar2 = FUN_006d4ef0(uVar5,local_4,local_8,&param_1,local_c);
      if (((iVar2 != 0) && (-1 < (int)param_1)) && ((uVar3 & 1 << ((byte)param_1 & 0x1f)) != 0)) {
        if ((uVar3 & ~(1 << ((byte)param_1 & 0x1f))) != 0) {
          return 0xfffffffc;
        }
        return uVar5;
      }
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < 0x20);
    uVar3 = 0xffffffff;
  }
  return uVar3;
}

