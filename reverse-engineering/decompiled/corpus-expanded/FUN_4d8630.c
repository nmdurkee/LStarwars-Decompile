/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d8630; label: FUN_004d8630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d8630(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  char cVar9;
  float *pfVar10;
  int iVar11;
  int iVar12;
  float *pfVar13;
  float10 fVar14;
  float local_58;
  float local_54;
  float local_50;
  undefined4 local_4c;
  undefined4 local_48;
  float local_44;
  undefined1 local_40 [64];
  
  cVar9 = (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0a0) + '(';
  iVar6 = FUN_005806a0(cVar9,PTR_DAT_00802c54);
  iVar11 = 0;
  if (0 < DAT_00882414) {
    pfVar13 = (float *)&DAT_00882924;
    pfVar10 = (float *)&DAT_00882920;
    iVar7 = DAT_0093d7f0;
    iVar12 = DAT_0093d7f4;
    fVar2 = _DAT_007ffcd8;
    fVar3 = _DAT_007ffcd4;
    fVar4 = _DAT_007ffcd0;
    do {
      bVar5 = false;
      if (((iVar7 != 0) && ((*(uint *)(iVar7 + 0x1fc) & 1) != 0)) &&
         ((*(uint *)(iVar7 + 0x1fc) & 0x1000) != 0)) {
        local_58 = *(float *)(iVar7 + 0x80) - pfVar13[-4];
        local_50 = *(float *)(iVar7 + 0x88) - pfVar13[-2];
        fVar1 = local_58 * local_58 + local_50 * local_50;
        if ((fVar1 < fVar2 * fVar2) && (bVar5 = true, fVar1 < fVar3 * fVar3)) {
          *pfVar13 = fVar4;
        }
      }
      if (((iVar12 != 0) && ((*(uint *)(iVar12 + 0x1fc) & 1) != 0)) &&
         ((*(uint *)(iVar12 + 0x1fc) & 0x1000) != 0)) {
        local_58 = *(float *)(iVar12 + 0x80) - pfVar13[-4];
        local_50 = *(float *)(iVar12 + 0x88) - pfVar13[-2];
        fVar1 = local_58 * local_58 + local_50 * local_50;
        if ((fVar1 < fVar2 * fVar2) && (bVar5 = true, fVar1 < fVar3 * fVar3)) {
          *pfVar13 = fVar4;
        }
      }
      fVar1 = *pfVar10 + _DAT_00925018;
      *pfVar10 = fVar1;
      if ((bVar5) && (_DAT_007ffccc < fVar1 != (_DAT_007ffccc == fVar1))) {
        *pfVar10 = 0.0;
        if (*pfVar13 <= 0.0) {
          local_4c = 0;
          local_48 = 0;
          fVar14 = (float10)FUN_005b9dd0();
          local_44 = (float)(fVar14 * (float10)_DAT_007ffcd4);
          uVar8 = FUN_005b9e30();
          FUN_005b3620(&local_4c,&local_4c,uVar8);
          FUN_005b37d0(&local_4c,&local_4c,pfVar10 + -3);
        }
        else {
          if (DAT_0093d814 == 0) {
            DAT_00882a98 = 0;
LAB_004d87e6:
            iVar7 = DAT_0093d810;
          }
          else {
            DAT_00882a98 = (uint)(DAT_00882a98 == 0);
            iVar7 = DAT_0093d814;
            if (DAT_00882a98 == 0) goto LAB_004d87e6;
          }
          FUN_00550250(pfVar13 + -7,iVar7 + 0x80,iVar7 + 0x68,*(undefined4 *)(iVar6 + 0x10),
                       &local_4c,0);
          FUN_005b37d0(&local_4c,&local_4c,pfVar13 + -7);
          fVar2 = *pfVar13 - _DAT_00925018;
          *pfVar13 = fVar2;
          if (fVar2 < 0.0) {
            *pfVar13 = 0.0;
          }
        }
        fVar14 = (float10)FUN_005becc0(&local_4c,pfVar10 + -6,&local_58);
        DAT_0093b0c8 = FUN_005be2d0(local_58,local_50);
        DAT_0092b0c4 = FUN_005be2d0(-local_54,(float)fVar14);
        FUN_005b45f0(local_40,DAT_0092b0c4);
        FUN_005b4f70(local_40,DAT_0093b0c8);
        FUN_00582e70(0,pfVar10 + -6,local_40,cVar9,0);
        iVar7 = DAT_0093d7f0;
        iVar12 = DAT_0093d7f4;
        fVar3 = _DAT_007ffcd4;
        fVar2 = _DAT_007ffcd8;
        fVar4 = _DAT_007ffcd0;
      }
      iVar11 = iVar11 + 1;
      pfVar10 = pfVar10 + 8;
      pfVar13 = pfVar13 + 8;
    } while (iVar11 < DAT_00882414);
  }
  return;
}

