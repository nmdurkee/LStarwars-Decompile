/* Ghidra pseudocode, not original source.
 * ev_e691f105e7e9df146417299401ecc100ef54520e911e9eb278e110fa7bbc9740
 * Entry: 0x4c6c70; label: FUN_004c6c70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c6c70(void)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  switch(DAT_008801ac) {
  case 0:
    iVar4 = DAT_008800c8 * 0x74 + DAT_0088047c;
    if ((*(uint *)(iVar4 + 100) <= DAT_0086e4dc) && (*(char *)(iVar4 + 99) != '\x01')) {
      return 1;
    }
    break;
  case 1:
    iVar4 = DAT_0087bdf8 * 0x74 + DAT_00880478;
    if (((*(uint *)(DAT_0087bdf8 * 0x74 + 100 + DAT_00880478) <= DAT_0086e4dc) &&
        (iVar2 = FUN_004c1050(), iVar2 != 0)) && (*(char *)(iVar4 + 99) != '\x01')) {
      return 1;
    }
    break;
  case 2:
    iVar4 = DAT_0087bf0c * 0x74 + DAT_00880480;
    if (*(uint *)(DAT_0087bf0c * 0x74 + 100 + DAT_00880480) <= DAT_0086e4dc) {
      uVar1 = *(ushort *)(iVar4 + 0x60);
      uVar3 = (uint)uVar1;
      if ((((uVar3 < 8) || ((&DAT_007f3da3)[uVar3 * 0x20] == -1)) ||
          ((&DAT_0086e0fa)[(char)(&DAT_007f3da3)[uVar3 * 0x20] * 0xc] != '\0')) &&
         ((((&DAT_0086e4c8)[(int)uVar3 >> 5] & 1 << ((byte)uVar1 & 0x1f)) == 0 &&
          (*(char *)(iVar4 + 99) != '\x01')))) {
        return 1;
      }
    }
    break;
  case 4:
    if ((*(uint *)(DAT_0087ffa4 * 0x74 + 100 + DAT_00880488) <= DAT_0086e4dc) &&
       ((float)(DAT_0087ffa4 * 0xe10) <= _DAT_0086e4e8)) {
      return 1;
    }
    break;
  case 5:
    iVar4 = FUN_0057e720(DAT_0087bee0);
    if (iVar4 != 0) {
      return 1;
    }
  }
  return 0;
}

