/* Ghidra pseudocode, not original source.
 * ev_70591197c926ebc674651557d03c19c52d1cbc8417e398ad949c9ada842aa1a9
 * Entry: 0x4c1630; label: FUN_004c1630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c1630(int param_1)

{
  undefined4 *puVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined2 *puVar8;
  short *psVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  undefined **ppuVar14;
  undefined4 uVar15;
  int local_8;
  
  iVar4 = param_1 + 0x108;
  iVar11 = param_1 + 0x104;
  DAT_00880478 = FUN_00552670(iVar11,iVar4,0x2d50);
  DAT_0088047c = FUN_00552670(iVar11,iVar4,0x1d00);
  DAT_00880480 = FUN_00552670(iVar11,iVar4,0x1d00);
  DAT_00880484 = FUN_00552670(iVar11,iVar4,0x1d00);
  DAT_00880488 = FUN_00552670(iVar11,iVar4,0x658);
  if ((((DAT_00880478 != 0) && (DAT_0088047c != 0)) && (DAT_00880480 != 0)) &&
     ((DAT_00880484 != 0 && (DAT_00880488 != 0)))) {
    DAT_0087bffa = 0;
    FUN_004f1f10(&DAT_0087bf98,&DAT_0075ce8c);
    FUN_004f1f10(&DAT_0087bfd8,&DAT_00753aa4);
    FUN_005cf5b0(DAT_00924880,&DAT_0087c000,&DAT_00753aa4,1);
    DAT_0087c06e = 1;
    DAT_0087c00c = 0;
    DAT_0087c04c = 0;
    _DAT_0087c074 = 0;
    _DAT_0087c078 = 0;
    _DAT_0087c07c = 0;
    DAT_0087c0e2 = 2;
    FUN_004f1f10(&DAT_0087c080,"Extra");
    FUN_004f1f10(&DAT_0087c0c0,"tool_box");
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0087c0e8,"tool_box",1);
    DAT_0087c156 = 3;
    FUN_004f1f10(&DAT_0087c0f4,&DAT_0075ce70);
    FUN_004f1f10(&DAT_0087c134,"shop_question");
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0087c15c,"shop_question",1);
    DAT_0087c1ca = 4;
    FUN_004f1f10(&DAT_0087c168,"Gold Bricks");
    FUN_004f1f10(&DAT_0087c1a8,"gold_brick");
    FUN_005cf5b0(DAT_00924880,&DAT_0087c1d0,"gold_brick",1);
    DAT_0087c23e = 5;
    FUN_004f1f10(&DAT_0087c1dc,"Cut Scenes");
    FUN_004f1f10(&DAT_0087c21c,&DAT_0075ce44);
    FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&DAT_0087c244,
                 &PTR_s_er_Compiler_9_19_949_1104_00766d4f_0x17_0075ce40,1);
    DAT_0087c56c = 0;
    DAT_00880008 = 0;
    _memset(&DAT_008801d0,0,0x240);
    iVar4 = 0;
    iVar11 = 0;
    DAT_008800d8 = 0;
    param_1 = 0;
    if (DAT_00855efe != 0) {
      local_8 = 0;
      do {
        if (0xaef < local_8) break;
        psVar9 = (short *)(DAT_00855ef8 + local_8);
        if (psVar9 != (short *)0x0) {
          sVar2 = *psVar9;
          *(undefined1 *)(iVar4 * 0x74 + 0x62 + DAT_00880478) = 1;
          *(undefined1 *)(DAT_008800d8 * 0x74 + 99 + DAT_00880478) = 0;
          iVar4 = DAT_008800d8;
          uVar5 = __allshl();
          if ((uVar5 & (&DAT_0086e4a8)[(int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5]) != 0) {
            *(undefined1 *)(iVar4 * 0x74 + 99 + DAT_00880478) = 1;
            iVar4 = DAT_008800d8;
          }
          iVar7 = *(int *)(sVar2 * 0x4c + DAT_0093b274);
          if (iVar7 == -1) {
            uVar6 = *(undefined4 *)(sVar2 * 0x4c + DAT_0093b274 + 0xc);
          }
          else {
            uVar6 = *(undefined4 *)(DAT_00926c20 + iVar7 * 4);
          }
          FUN_004f1f10(iVar4 * 0x74 + DAT_00880478,uVar6);
          puVar12 = (undefined4 *)(DAT_008800d8 * 0x74 + 0x68 + DAT_00880478);
          *puVar12 = 0;
          puVar12[1] = 0;
          puVar12[2] = 0;
          if (iVar11 < 0x90) {
            uVar6 = FUN_00650430(psVar9 + 6);
            (&DAT_008801d0)[iVar11] = uVar6;
            iVar11 = iVar11 + 1;
          }
          iVar4 = DAT_008800d8 + 1;
          DAT_008800d8 = iVar4;
        }
        param_1 = param_1 + 1;
        local_8 = local_8 + 0x1c;
      } while (param_1 < (int)(uint)DAT_00855efe);
    }
    iVar4 = 0;
    FUN_004c15e0();
    ppuVar14 = &PTR_s_MZY419_007f3da8;
    DAT_0087c56c = iVar11;
    do {
      if (iVar11 < 0x90) {
        uVar6 = FUN_00650430(*ppuVar14);
        (&DAT_008801d0)[iVar11] = uVar6;
        iVar11 = iVar11 + 1;
      }
      ppuVar14 = ppuVar14 + 8;
    } while ((int)ppuVar14 < 0x7f4328);
    DAT_00880008 = iVar11;
    FUN_005cf5b0(DAT_00924880,&DAT_0087c25c,"icon_back_neutral",1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0087bb88,"info_blank",1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0087bef0,"fmv_blank",1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0087c250,"shop_film1",1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0087c4fc,"shop_film1b",1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_008800e8,"tool_blank",1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0087c520,"code_blank",1);
    FUN_005cf5b0(DAT_00924880,&DAT_0087c560,"question_icon",1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_008801b0,"shop_arrow1",1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0087c478,"shop_arrow2",1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_0087bb78,"shop_arrow3",1);
    FUN_005cf5b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),&DAT_008801a0,"shop_arrow4",1);
    FUN_005cfc00(&DAT_008801b0,0);
    FUN_005cfc00(&DAT_0087c478,0);
    FUN_005cfc00(&DAT_0087bb78,0);
    FUN_005cfc00(&DAT_008801a0,0);
    FUN_004c1390();
    FUN_004c1510();
    if (0 < DAT_00880150) {
      iVar11 = 0;
      puVar12 = &DAT_0087bbc8;
      do {
        iVar7 = FUN_00576480((int)(short)(&DAT_007fcb18)[iVar4]);
        *(undefined1 *)(iVar11 + 0x62 + DAT_0088047c) = 0;
        *(short *)(iVar11 + 0x60 + DAT_0088047c) = (short)iVar4;
        if (iVar7 == 0) {
          uVar6 = 0;
        }
        else {
          uVar6 = *(undefined4 *)(iVar7 + 4);
        }
        *(undefined4 *)(iVar11 + 100 + DAT_0088047c) = uVar6;
        *(undefined1 *)(iVar11 + 99 + DAT_0088047c) = 0;
        uVar5 = __allshl();
        if ((uVar5 & (&DAT_0086e49c)[(int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5]) != 0) {
          *(undefined1 *)(iVar11 + 99 + DAT_0088047c) = 1;
        }
        if (*(int *)(iVar11 + 100 + DAT_0088047c) == 0) {
          *(undefined1 *)(iVar11 + 99 + DAT_0088047c) = 1;
        }
        puVar1 = (undefined4 *)(iVar11 + 0x68 + DAT_0088047c);
        *puVar1 = *puVar12;
        puVar1[1] = puVar12[1];
        iVar4 = iVar4 + 1;
        puVar1[2] = puVar12[2];
        puVar12 = puVar12 + 3;
        iVar11 = iVar11 + 0x74;
      } while (iVar4 < DAT_00880150);
    }
    _DAT_0087bf90 = FUN_005d0690(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),"shop_cam");
    if (_DAT_0087bf90 == 0) {
      DAT_0087ffec = 0;
      DAT_0087bf94 = 0;
    }
    else {
      DAT_0087ffec = *(undefined4 *)(_DAT_0087bf90 + 8);
      DAT_0087bf94 = *(int *)(_DAT_0087bf90 + 8) + 0xc;
    }
    FUN_004c11c0();
    uVar10 = DAT_00880470;
    uVar15 = DAT_0088046c;
    uVar13 = DAT_00880468;
    uVar6 = DAT_00880464;
    iVar4 = DAT_008800d8;
    _DAT_0087be60 = DAT_00880420;
    _DAT_0087be68 = DAT_00880428;
    _DAT_0087be64 = DAT_00880424;
    _DAT_0087be70 = DAT_00880430;
    _DAT_0087be6c = DAT_0088042c;
    _DAT_0087be78 = DAT_00880438;
    _DAT_0087be74 = DAT_00880434;
    _DAT_0087be80 = DAT_00880440;
    _DAT_0087be7c = DAT_0088043c;
    _DAT_0087be88 = DAT_00880448;
    _DAT_0087be84 = DAT_00880444;
    _DAT_0087be90 = DAT_00880450;
    _DAT_0087be8c = DAT_0088044c;
    _DAT_0087be98 = DAT_00880458;
    _DAT_0087be94 = DAT_00880454;
    _DAT_0087bea0 = DAT_00880460;
    param_1 = 0;
    _DAT_0087be9c = DAT_0088045c;
    _DAT_0087bea4 = DAT_00880464;
    _DAT_0087bea8 = DAT_00880468;
    _DAT_0087beac = DAT_0088046c;
    _DAT_0087beb0 = DAT_00880470;
    do {
      iVar11 = iVar4 + -3 + param_1;
      param_1 = param_1 + 1;
      *(int *)(&DAT_0087bde8 + param_1 * 4) = iVar11 % iVar4;
      iVar11 = DAT_00880150;
    } while (param_1 < 7);
    if (0 < DAT_00880150) {
      _DAT_0087bd98 = DAT_00880420;
      _DAT_0087bd9c = DAT_00880424;
      _DAT_0087bda0 = DAT_00880428;
      _DAT_0087bda4 = DAT_0088042c;
      _DAT_0087bda8 = DAT_00880430;
      _DAT_0087bdac = DAT_00880434;
      _DAT_0087bdb0 = DAT_00880438;
      _DAT_0087bdb4 = DAT_0088043c;
      _DAT_0087bdb8 = DAT_00880440;
      _DAT_0087bdbc = DAT_00880444;
      _DAT_0087bdc0 = DAT_00880448;
      _DAT_0087bdc4 = DAT_0088044c;
      _DAT_0087bdc8 = DAT_00880450;
      _DAT_0087bdcc = DAT_00880454;
      _DAT_0087bdd0 = DAT_00880458;
      _DAT_0087bdd4 = DAT_0088045c;
      param_1 = 0;
      _DAT_0087bdd8 = DAT_00880460;
      _DAT_0087bddc = uVar6;
      _DAT_0087bde0 = uVar13;
      _DAT_0087bde4 = uVar15;
      _DAT_0087bde8 = uVar10;
      do {
        iVar4 = iVar11 + -3 + param_1;
        param_1 = param_1 + 1;
        (&DAT_008800b8)[param_1] = iVar4 % iVar11;
      } while (param_1 < 7);
    }
    iVar4 = DAT_0087bbc0;
    if (0 < DAT_0087bbc0) {
      _DAT_0087bf38 = DAT_00880420;
      _DAT_0087bf3c = DAT_00880424;
      _DAT_0087bf40 = DAT_00880428;
      _DAT_0087bf44 = DAT_0088042c;
      _DAT_0087bf48 = DAT_00880430;
      _DAT_0087bf4c = DAT_00880434;
      _DAT_0087bf50 = DAT_00880438;
      _DAT_0087bf54 = DAT_0088043c;
      _DAT_0087bf58 = DAT_00880440;
      _DAT_0087bf5c = DAT_00880444;
      _DAT_0087bf60 = DAT_00880448;
      _DAT_0087bf64 = DAT_0088044c;
      _DAT_0087bf68 = DAT_00880450;
      _DAT_0087bf6c = DAT_00880454;
      _DAT_0087bf70 = DAT_00880458;
      _DAT_0087bf74 = DAT_0088045c;
      param_1 = 0;
      _DAT_0087bf78 = DAT_00880460;
      _DAT_0087bf7c = uVar6;
      _DAT_0087bf80 = uVar13;
      _DAT_0087bf84 = uVar15;
      _DAT_0087bf88 = uVar10;
      do {
        iVar11 = iVar4 + -3 + param_1;
        param_1 = param_1 + 1;
        (&DAT_0087befc)[param_1] = iVar11 % iVar4;
      } while (param_1 < 7);
    }
    iVar4 = 0;
    param_1 = 10000;
    if (0 < DAT_0093b310) {
      iVar11 = 0;
      do {
        *(undefined1 *)(iVar11 + 0x62 + DAT_00880488) = 4;
        *(short *)(iVar11 + 0x60 + DAT_00880488) = (short)iVar4;
        *(int *)(iVar11 + 100 + DAT_00880488) = param_1;
        puVar12 = (undefined4 *)(iVar11 + 0x68 + DAT_00880488);
        *puVar12 = DAT_0087c1d0;
        puVar12[1] = DAT_0087c1d4;
        puVar12[2] = DAT_0087c1d8;
        *(undefined1 *)(iVar11 + 99 + DAT_00880488) = 0;
        uVar5 = __allshl();
        if ((uVar5 & (&DAT_0086e4c0)[(int)(iVar4 + (iVar4 >> 0x1f & 0x1fU)) >> 5]) != 0) {
          *(undefined1 *)(iVar11 + 99 + DAT_00880488) = 1;
        }
        param_1 = param_1 + 5000;
        iVar4 = iVar4 + 1;
        iVar11 = iVar11 + 0x74;
        uVar10 = DAT_00880470;
        uVar6 = DAT_00880464;
        uVar13 = DAT_00880468;
        uVar15 = DAT_0088046c;
      } while (iVar4 < DAT_0093b310);
    }
    _DAT_0087c488 = DAT_00880420;
    _DAT_0087c48c = DAT_00880424;
    _DAT_0087c490 = DAT_00880428;
    _DAT_0087c494 = DAT_0088042c;
    _DAT_0087c498 = DAT_00880430;
    _DAT_0087c49c = DAT_00880434;
    _DAT_0087c4a0 = DAT_00880438;
    _DAT_0087c4a4 = DAT_0088043c;
    _DAT_0087c4a8 = DAT_00880440;
    _DAT_0087c4ac = DAT_00880444;
    _DAT_0087c4b0 = DAT_00880448;
    _DAT_0087c4b4 = DAT_0088044c;
    _DAT_0087c4b8 = DAT_00880450;
    _DAT_0087c4bc = DAT_00880454;
    _DAT_0087c4c0 = DAT_00880458;
    _DAT_0087c4c4 = DAT_0088045c;
    param_1 = 0;
    _DAT_0087c4c8 = DAT_00880460;
    _DAT_0087c4cc = uVar6;
    _DAT_0087c4d0 = uVar13;
    _DAT_0087c4d4 = uVar15;
    _DAT_0087c4d8 = uVar10;
    do {
      iVar4 = param_1 + 0xb;
      param_1 = param_1 + 1;
      *(int *)(&DAT_0087ff94 + param_1 * 4) = iVar4 % 0xe;
    } while (param_1 < 7);
    iVar4 = 0;
    DAT_007fcb68 = DAT_0087ff90;
    if (0 < DAT_0087ff90) {
      puVar8 = &DAT_0087c5d8;
      do {
        if (0x87ffd7 < (int)puVar8) break;
        *(undefined4 *)(puVar8 + 4) = DAT_0087c244;
        *(undefined4 *)(puVar8 + 6) = DAT_0087c248;
        uVar3 = DAT_0087c24c;
        *puVar8 = (short)iVar4;
        *(undefined1 *)(puVar8 + 1) = 5;
        *(undefined4 *)(puVar8 + 2) = 0;
        *(undefined4 *)(puVar8 + 8) = uVar3;
        *(undefined1 *)((int)puVar8 + 3) = 0;
        iVar4 = iVar4 + 1;
        puVar8 = puVar8 + 0x3a;
      } while (iVar4 < DAT_007fcb68);
    }
    if (DAT_008800b8 == 0) {
      if (0 < DAT_007fcb68) {
        _DAT_0087be08 = DAT_00880420;
        _DAT_0087be0c = DAT_00880424;
        _DAT_0087be10 = DAT_00880428;
        _DAT_0087be14 = DAT_0088042c;
        _DAT_0087be18 = DAT_00880430;
        _DAT_0087be1c = DAT_00880434;
        _DAT_0087be20 = DAT_00880438;
        _DAT_0087be24 = DAT_0088043c;
        _DAT_0087be28 = DAT_00880440;
        _DAT_0087be2c = DAT_00880444;
        _DAT_0087be30 = DAT_00880448;
        _DAT_0087be34 = DAT_0088044c;
        _DAT_0087be38 = DAT_00880450;
        _DAT_0087be3c = DAT_00880454;
        _DAT_0087be40 = DAT_00880458;
        _DAT_0087be44 = DAT_0088045c;
        _DAT_0087be48 = DAT_00880460;
        iVar4 = 0;
        _DAT_0087be4c = uVar6;
        _DAT_0087be50 = uVar13;
        _DAT_0087be54 = uVar15;
        _DAT_0087be58 = uVar10;
        do {
          iVar11 = DAT_007fcb68 + -3 + iVar4;
          iVar4 = iVar4 + 1;
          *(int *)(&DAT_0087bed0 + iVar4 * 4) = iVar11 % DAT_007fcb68;
        } while (iVar4 < 7);
      }
      DAT_008801ac = 0;
    }
    else {
      DAT_008801ac = DAT_0087ffe4;
    }
    _DAT_0087bb74 = 0;
    _DAT_0087bbb0 = 0x3ecccccd;
    _DAT_0087c4dc = 0x3f800000;
    _DAT_008801bc = 0x3fb33333;
    _DAT_008801cc = 0x3fb33333;
    _DAT_0087bed0 = 0x3f800000;
    _DAT_0087bb70 = 0x3f800000;
    DAT_0087fff0 = _DAT_007fcb74;
    _DAT_0087c548 = _DAT_007fcb74;
    DAT_0087fff4 = _DAT_007fcb7c;
    _DAT_0087c54c = _DAT_007fcb7c;
    DAT_0087fff8 = _DAT_007fcb78;
    _DAT_0087c550 = _DAT_007fcb78;
    DAT_0087fffc = _DAT_007fcb80;
    _DAT_0087c554 = _DAT_007fcb80;
    DAT_00880000 = _DAT_007fcb84;
    _DAT_0087c558 = _DAT_007fcb84;
    DAT_00880004 = _DAT_007fcb88;
    _DAT_0087c55c = _DAT_007fcb88;
    _DAT_0087ffcc = _DAT_007fcb8c * _DAT_007fcb74;
    _DAT_0087ffd0 = _DAT_007fcb90 * _DAT_007fcb7c;
    _DAT_0087ffd4 = _DAT_007fcb94 * _DAT_007fcb78;
    _DAT_0087ffd8 = _DAT_007fcb98 * _DAT_007fcb80;
    _DAT_0087ffdc = _DAT_007fcb9c * _DAT_007fcb84;
    _DAT_0087ffe0 = _DAT_007fcba0 * _DAT_007fcb88;
    _DAT_0087ff78 = _DAT_007fcba4;
    _DAT_0087ff7c = _DAT_007fcba8;
    _DAT_0087ff80 = _DAT_007fcbac;
    _DAT_0087ff84 = _DAT_007fcbb0;
    _DAT_0087ff88 = _DAT_007fcbb4;
    _DAT_0087ff8c = _DAT_007fcbb8;
    DAT_0087c508 = 0;
    DAT_0087c50c = 0;
    DAT_0087c510 = 0xbba3d70a;
    _DAT_0087bf1c = 0;
    DAT_0087c514 = 0;
    DAT_0087c518 = 0xbc23d70a;
    DAT_0087c51c = 0;
    _DAT_0087bb94 = _DAT_007fcbbc;
    _DAT_0087bf20 = 0;
    _DAT_0087bb98 = _DAT_007fcbc0;
    _DAT_0087bf2c = 0xbc23d70a;
    _DAT_0087bbb8 = 0x3d4ccccd;
    _DAT_0087bf24 = 0xbba3d70a;
    _DAT_008800a4 = 0x3ca3d70a;
    _DAT_0087bf28 = 0;
    _DAT_00880410 = 0x3ca3d70a;
    _DAT_0087bf30 = 0;
    _DAT_00880418 = 0x3ca3d70a;
    _DAT_00880414 = 0x3d4ccccd;
    DAT_0087ffb4 = _DAT_0087ffd8 * 0.8;
    DAT_0087beb8 = _DAT_007fcb80 * 0.8;
    _DAT_0087bebc = DAT_0087beb8;
    _DAT_0087bec0 = DAT_0087beb8;
    _DAT_0087bec4 = DAT_0087beb8;
    _DAT_0087bec8 = DAT_0087beb8;
    _DAT_0087becc = DAT_0087beb8;
    DAT_0087c52c = DAT_0087beb8;
    DAT_0087c530 = DAT_0087beb8;
    _DAT_0087c534 = DAT_0087beb8;
    _DAT_0087c538 = DAT_0087beb8;
    _DAT_0087c53c = DAT_0087beb8;
    _DAT_0087c540 = DAT_0087beb8;
    _DAT_0087ffb8 = DAT_0087ffb4;
    _DAT_0087ffbc = DAT_0087ffb4;
    _DAT_0087ffc0 = DAT_0087ffb4;
    _DAT_0087ffc4 = DAT_0087ffb4;
    _DAT_0087ffc8 = DAT_0087ffb4;
    DAT_0088049c = FUN_0057e700();
  }
  return;
}

