/* Ghidra pseudocode, not original source.
 * ev_1545e5b34141c1614daa034024a98821bd7642306100b3a505193274c33334db
 * Entry: 0x4e3120; label: FUN_004e3120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e3120(void)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  bool bVar7;
  
  DAT_008895f8 = 0;
  iVar3 = FUN_005cfac0(&DAT_008895b0);
  iVar1 = DAT_0088958c;
  iVar4 = DAT_00889584;
  if (((iVar3 != 0) && (DAT_00889584 != 0)) && (DAT_0088958c != 0)) {
    if (DAT_00951b50 == 0) {
      bVar7 = -1 < DAT_0080009c;
      *(undefined4 *)(DAT_0088958c + 0x28) = 0;
      fVar2 = _DAT_00800094;
      if (((bVar7) && (DAT_0087a96c != (int *)0x0)) &&
         ((*DAT_0087a96c != 0 && ((*(byte *)(*DAT_0087a96c + 0x62) & 2) != 0)))) {
        *(uint *)(iVar4 + 0x50) = *(uint *)(iVar4 + 0x50) | 1;
        DAT_0080009c = -1;
        *(float *)(iVar4 + 0x40) = -fVar2;
      }
      if (((*(byte *)(iVar4 + 0x50) & 1) != 0) && (DAT_008894cc != -1)) {
        if (0.0 <= (float)DAT_0080009c) {
          DAT_008895f8 = 1;
          *(undefined4 *)(iVar1 + 0x28) = 0x3f800000;
        }
        iVar4 = FUN_005cf9e0(&DAT_008895b0);
        piVar6 = &DAT_0093d7f0;
        do {
          iVar1 = *piVar6;
          if (((iVar1 != 0) && (*(char *)(iVar1 + 0x28b) == '\0')) &&
             ((*(short *)(iVar1 + 0x27e) == DAT_008894cc ||
              (*(float *)(iVar4 + 8) < *(float *)(iVar1 + 0x88))))) {
            FUN_00438230(0,iVar1,0xffffffff,0,0,1);
            FUN_004364e0(iVar1,2,0);
            if ((-1 < DAT_0080009c) && (_DAT_0087a830 == 0.0)) {
              _DAT_0087a830 = _DAT_008000a0;
            }
          }
          piVar6 = piVar6 + 1;
        } while ((int)piVar6 < 0x93d810);
        iVar4 = DAT_00889584;
        if (((0.0 < _DAT_0087a830) &&
            (_DAT_0087a830 = _DAT_0087a830 - _DAT_00925018, _DAT_0087a830 <= 0.0)) &&
           (_DAT_0087a830 = 0.0, DAT_00856c08 != 3)) {
          FUN_0057a620(0,0,1);
          iVar4 = DAT_00889584;
        }
      }
    }
    if ((*(byte *)(iVar4 + 0x50) & 1) != 0) {
      uVar5 = FUN_005cf9e0(&DAT_008895b0);
      FUN_00681f40("Cru_HugeWallMoveLp",uVar5);
      iVar4 = DAT_00889584;
    }
    _DAT_00800098 = *(undefined4 *)(iVar4 + 0x4c);
    if (DAT_00951b50 != 0) {
      *(undefined4 *)(iVar4 + 0x4c) = *DAT_008894c8;
      *(undefined4 *)(iVar4 + 0x40) = DAT_008894c8[1];
      *(uint *)(iVar4 + 0x50) =
           *(uint *)(iVar4 + 0x50) ^ (DAT_008894c8[2] ^ *(uint *)(iVar4 + 0x50)) & 1;
    }
  }
  return;
}

