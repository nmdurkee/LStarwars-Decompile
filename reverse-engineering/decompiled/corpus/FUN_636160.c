/* Ghidra analysis pseudocode, not original source.
 * ev_4ddc17d0b5ae2dc444590ce1384da883f11f3d0f2dd8037fed9dcc825d4bbeec
 * Entry: 0x636160; label: FUN_00636160
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00636160(float param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar2 = 0;
  if (*(char *)(unaff_EDI + 0x58) == '\x01') {
    pfVar4 = (float *)(unaff_ESI + 0x24);
    do {
      if (*pfVar4 < param_1) {
        if (iVar2 != 2) {
          puVar1 = (undefined4 *)(unaff_ESI + 0x20);
          iVar3 = 2 - iVar2;
          do {
            puVar1[3] = puVar1[2];
            *puVar1 = puVar1[-1];
            puVar1 = puVar1 + -1;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        *(float *)(unaff_ESI + 0x24 + iVar2 * 4) = param_1;
        *(int *)(unaff_ESI + 0x18 + iVar2 * 4) = unaff_EDI;
        return;
      }
      iVar2 = iVar2 + 1;
      pfVar4 = pfVar4 + 1;
    } while (iVar2 < 3);
    _DAT_02913984 = 1;
    return;
  }
  pfVar4 = (float *)(unaff_ESI + 0xc);
  do {
    if (*pfVar4 < param_1) {
      if (iVar2 != 2) {
        puVar1 = (undefined4 *)(unaff_ESI + 0x10);
        iVar3 = 2 - iVar2;
        do {
          puVar1[1] = *puVar1;
          puVar1[-2] = puVar1[-3];
          puVar1 = puVar1 + -1;
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      *(float *)(unaff_ESI + 0xc + iVar2 * 4) = param_1;
      *(int *)(unaff_ESI + iVar2 * 4) = unaff_EDI;
      return;
    }
    iVar2 = iVar2 + 1;
    pfVar4 = pfVar4 + 1;
  } while (iVar2 < 3);
  _DAT_02913984 = 1;
  return;
}

