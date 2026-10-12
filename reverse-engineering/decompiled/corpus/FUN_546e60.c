/* Ghidra analysis pseudocode, not original source.
 * ev_177857cb78ddb8ad13dc6718881af1dfaef05e8a3811f551bff9ab7ba98e27a8
 * Entry: 0x546e60; label: FUN_00546e60
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00546e60(void)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  short *psVar12;
  int iVar13;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar10 = 0;
  local_8 = 0;
  psVar12 = DAT_00924850;
  if (0 < DAT_0092484c) {
    do {
      if ((*psVar12 != 0) && (*(char *)((int)psVar12 + 0x1d) != '\0')) {
        fVar1 = *(float *)(psVar12 + 0x18);
        iVar11 = 0;
        _DAT_00924854 = psVar12;
        *(undefined1 *)(psVar12 + 0xe) = 0;
        fVar2 = *(float *)(psVar12 + 0x1a);
        iVar13 = *(int *)(psVar12 + 6);
        if (0 < psVar12[0xf]) {
          do {
            uVar3 = *(undefined4 *)(iVar13 + 0x2c);
            uVar4 = *(undefined4 *)(iVar13 + 0x3c);
            *(undefined4 *)(iVar13 + 0x3c) = 0x3f800000;
            fVar6 = *(float *)(iVar13 + 0x34) - DAT_0097371c;
            fVar8 = *(float *)(iVar13 + 0x30) - DAT_00973718;
            fVar7 = *(float *)(iVar13 + 0x38) - DAT_00973720;
            fVar6 = fVar7 * fVar7 + fVar8 * fVar8 + fVar6 * fVar6;
            if (fVar6 < fVar2 * fVar2) {
              if (fVar1 * fVar1 <= fVar6) {
                uVar5 = 0x2d2febff;
              }
              else {
                uVar5 = 0;
              }
              *(undefined4 *)(iVar13 + 0x2c) = uVar5;
              local_c = *(undefined4 *)(psVar12 + 2);
              local_4 = *(undefined4 *)(psVar12 + 4);
              iVar9 = FUN_005f33b0(&local_c,iVar13);
              if (iVar9 != 0) {
                *(undefined1 *)(psVar12 + 0xe) = 1;
              }
            }
            iVar11 = iVar11 + 1;
            *(undefined4 *)(iVar13 + 0x2c) = uVar3;
            *(undefined4 *)(iVar13 + 0x3c) = uVar4;
            iVar13 = iVar13 + 0x40;
          } while (iVar11 < psVar12[0xf]);
        }
      }
      iVar10 = iVar10 + 1;
      psVar12 = psVar12 + 0x26;
    } while (iVar10 < DAT_0092484c);
  }
  return;
}

