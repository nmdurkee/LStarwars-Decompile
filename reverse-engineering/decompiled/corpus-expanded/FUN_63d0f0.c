/* Ghidra pseudocode, not original source.
 * ev_0e84ad542db3be7599677a500db2c2fcd5f6f463504cd13a52c31f7d7facbfa7
 * Entry: 0x63d0f0; label: FUN_0063d0f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x0063d44d) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063d0f0(void)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined *puVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar12;
  undefined8 uVar11;
  undefined8 uVar13;
  char *local_68 [25];
  
  local_68[0] = "INVALID";
  local_68[1] = "AMBIENT";
  local_68[2] = "POINT";
  local_68[3] = "POINT FLICKER";
  local_68[4] = "DIRECTIONAL";
  local_68[5] = "CAMDIR";
  local_68[6] = "POINT BLEND";
  local_68[7] = "ANTILIGHT";
  local_68[8] = "JON FLICKER";
  local_68[9] = "ALSO INVALID";
  FUN_005d0fb0();
  uVar13 = CONCAT44(_DAT_0080fe00,_DAT_0080fe00);
  uVar12 = DAT_009738b8;
  FUN_005d0fe0();
  uVar11 = CONCAT44(uVar12,0x80ffffff);
  uVar12 = DAT_009738b8;
  FUN_005d1060();
  FUN_005d0e80(DAT_009738b8,uVar12,uVar11,uVar13);
  iVar3 = FUN_006e6b90();
  if (DAT_029139dc != 0) {
    FUN_005f35e0();
    iVar9 = 0;
    iVar8 = iVar3 + 0x200;
    iVar10 = 0;
    do {
      FUN_005d0fb0();
      FUN_005f35e0(DAT_009738b8,0x1540,iVar8,0x10,"%02d - %02d - %02d : %02d",iVar9,
                   *(undefined1 *)(iVar10 + 0x5c + DAT_0291389c),
                   (int)*(char *)(iVar10 + 0x7d + DAT_0291389c),
                   (int)*(char *)(iVar10 + 0x7e + DAT_0291389c));
      iVar10 = iVar10 + 0x8c;
      iVar8 = iVar8 + iVar3;
      iVar9 = iVar9 + 1;
    } while (iVar10 < 0x578);
  }
  if (DAT_02913818 != 0) {
    FUN_005d0fb0();
    iVar8 = 0;
    if (0 < DAT_0080fe14) {
      iVar9 = 0x200;
      do {
        FUN_005f35e0(DAT_009738b8,0x2580,iVar9,0x20,"%s = %.2f",
                     *(undefined4 *)(PTR_PTR_0080fe10 + iVar8 * 4),
                     (double)*(float *)(PTR_DAT_0080fe0c + iVar8 * 4));
        iVar8 = iVar8 + 1;
        iVar9 = iVar9 + iVar3;
      } while (iVar8 < DAT_0080fe14);
    }
  }
  if (DAT_02913824 == (float *)0x0) {
    FUN_005db880(0x80,0x200 - iVar3,0x1040,(iVar3 * 4) / 2,0x20404040,DAT_029135f4);
    FUN_005d0fb0(DAT_009738b8);
    FUN_005f35e0(DAT_009738b8,0x280,0x200,0x10,"RTL Editor");
    FUN_005f35e0();
    FUN_005f35e0(DAT_009738b8,0x280,iVar3 * 2 + 0x200,0x10,"POS: %.03f %.03f %.03f",
                 (double)DAT_029134a4,(double)DAT_029134a8,(double)DAT_029134ac);
    goto LAB_0063d867;
  }
  iVar8 = 8;
  if (*(short *)(DAT_02913824 + 0x1a) != 0) {
    iVar8 = 9;
  }
  if ((*(char *)(DAT_02913824 + 0x16) == '\x05') && (*(short *)((int)DAT_02913824 + 0x5e) != 0)) {
    iVar8 = iVar8 + 1;
  }
  if (*(short *)(DAT_02913824 + 0x18) != 0) {
    iVar8 = iVar8 + 1;
  }
  if (*(char *)(DAT_02913824 + 0x1e) != '\0') {
    iVar8 = iVar8 + 1;
  }
  if (DAT_029139bc != 0) {
    iVar8 = iVar8 + 1;
  }
  FUN_005db880(0x80,0x200 - iVar3,0x1040,(iVar8 + 1) * iVar3 * 2 >> 1,0x20404040,DAT_029135f4);
  FUN_005d0fb0(DAT_009738b8);
  if (DAT_02913818 == 0) {
    FUN_005f35e0(DAT_009738b8,0x280,0x200,0x10,"RTL Editor %d/%d",
                 ((int)DAT_02913824 + (-4 - DAT_0291389c)) / 0x8c,0x80);
  }
  else {
    FUN_005f35e0(DAT_009738b8,0x280,0x200,0x10,"RTL Editor %d/%d (Parent %d)",
                 ((int)DAT_02913824 + (-4 - DAT_0291389c)) / 0x8c,0x80,
                 ((DAT_02913818 - DAT_0291389c) + -4) / 0x8c);
  }
  iVar8 = iVar3 * 2 + 0x200;
  FUN_005f35e0();
  FUN_005f35e0(DAT_009738b8,0x280,iVar8,0x10,"POS: %.03f %.03f %.03f",(double)*DAT_02913824,
               (double)DAT_02913824[1],(double)DAT_02913824[2]);
  bVar1 = *(byte *)(DAT_02913824 + 0x16);
  iVar8 = iVar8 + iVar3;
  if ((bVar1 < 10) && (bVar1 < 10)) {
    uVar4 = (uint)bVar1;
  }
  else {
    uVar4 = 9;
  }
  FUN_005f35e0(DAT_009738b8,0x280,iVar8,0x10,"TYPE: %s",local_68[uVar4]);
  iVar8 = iVar8 + iVar3;
  FUN_005f35e0(DAT_009738b8,0x280,iVar8,0x10,"RADIUS: %.03f",(double)DAT_02913824[0xf]);
  iVar8 = iVar8 + iVar3;
  FUN_005f35e0(DAT_009738b8,0x280,iVar8,0x10,"FALL OFF: %.03f",(double)DAT_02913824[0x10]);
  iVar8 = iVar8 + iVar3;
  FUN_005f35e0(DAT_009738b8,0x280,iVar8,0x10,"MULTIPLIER: %.0f",(double)DAT_02913824[0x1b]);
  iVar8 = iVar8 + iVar3;
  puVar5 = &DAT_0076bb0c;
  if ((*(byte *)((int)DAT_02913824 + 0x59) & 2) == 0) {
    puVar5 = &DAT_0076bb08;
  }
  FUN_005f35e0(DAT_009738b8,0x280,iVar8,0x10,"CAST SHADOW: %s",puVar5);
  iVar8 = iVar8 + iVar3;
  puVar5 = &DAT_0076bb0c;
  if ((*(byte *)((int)DAT_02913824 + 0x59) & 4) == 0) {
    puVar5 = &DAT_0076bb08;
  }
  FUN_005f35e0(DAT_009738b8,0x280,iVar8,0x10,"SPECULAR: %s",puVar5);
  iVar8 = iVar8 + iVar3;
  if (*(short *)(DAT_02913824 + 0x1a) != 0) {
    FUN_005f35e0(DAT_009738b8,0x280,iVar8,0x10,"USER ID: (%d)%s",
                 (uint)*(ushort *)(DAT_02913824 + 0x1a),
                 (&PTR_s_NO_ID_0080fe60)[*(ushort *)(DAT_02913824 + 0x1a)]);
    iVar8 = iVar8 + iVar3;
  }
  if ((*(char *)((int)DAT_02913824 + 0x7a) != -1) || (*(char *)((int)DAT_02913824 + 0x79) == -1)) {
    iVar9 = (int)*(char *)((int)DAT_02913824 + 0x7b);
    iVar6 = DAT_0080fe14 + -1;
    iVar10 = iVar6;
    if (iVar9 <= iVar6) {
      iVar10 = iVar9;
    }
    if (iVar10 < 0) {
      iVar9 = 0;
    }
    else if (iVar6 < iVar9) {
      iVar9 = iVar6;
    }
    FUN_005f35e0(DAT_009738b8,0x280,iVar8,0x10,"MODIFIER: %s",
                 *(undefined4 *)(PTR_PTR_0080fe10 + iVar9 * 4));
    iVar8 = iVar8 + iVar3;
  }
  if ((*(char *)(DAT_02913824 + 0x16) == '\x05') && (*(short *)((int)DAT_02913824 + 0x5e) != 0)) {
    FUN_005f35e0();
    iVar8 = iVar8 + iVar3;
  }
  if (*(short *)(DAT_02913824 + 0x18) != 0) {
    FUN_005f35e0();
    iVar8 = iVar8 + iVar3;
  }
  if (*(char *)(DAT_02913824 + 0x1e) != '\0') {
    FUN_005f35e0(DAT_009738b8,0x280,iVar8,0x10,"GROUP ID: (%d)",*(char *)(DAT_02913824 + 0x1e));
    iVar8 = iVar8 + iVar3;
  }
  if (*(char *)((int)DAT_02913824 + 0x79) == -1) {
LAB_0063d6dd:
    if (*(char *)((int)DAT_02913824 + 0x7a) != -1) goto LAB_0063d6e3;
  }
  else {
    if (*(char *)((int)DAT_02913824 + 0x7a) == -1) {
      iVar9 = 0;
      cVar2 = *(char *)((int)DAT_02913824 + 0x79);
      pfVar7 = DAT_02913824;
      while (cVar2 != -1) {
        pfVar7 = (float *)(cVar2 * 0x8c + (int)pfVar7[0x1f]);
        iVar9 = iVar9 + 1;
        cVar2 = *(char *)((int)pfVar7 + 0x79);
      }
      FUN_005f35e0(DAT_009738b8,0x280,iVar8,0x10,"[HAS %d ALTERNATE SETTINGS]",iVar9);
      iVar8 = iVar8 + iVar3;
      goto LAB_0063d6dd;
    }
LAB_0063d6e3:
    iVar3 = 0;
    cVar2 = *(char *)((int)DAT_02913824 + 0x7a);
    pfVar7 = DAT_02913824;
    while (cVar2 != -1) {
      pfVar7 = (float *)(cVar2 * 0x8c + 4 + DAT_0291389c);
      iVar3 = iVar3 + 1;
      cVar2 = *(char *)((int)pfVar7 + 0x7a);
    }
    iVar9 = 0;
    for (cVar2 = *(char *)((int)pfVar7 + 0x79); cVar2 != -1;
        cVar2 = *(char *)(cVar2 * 0x8c + DAT_0291389c + 0x7d)) {
      iVar9 = iVar9 + 1;
    }
    FUN_005f35e0(DAT_009738b8,0x280,iVar8,0x10,"[ALTERNATE SETTING %d/%d]",iVar3,iVar9);
  }
  if ((DAT_029139bc != 0) && (_DAT_0080ff38 * 0.5 < _DAT_029139d8)) {
    FUN_005f35e0();
  }
LAB_0063d867:
  if (DAT_029139c0 != 0) {
    FUN_005f35e0(DAT_009738b8,DAT_00973900 << 4,0x200,0x10,"UNDO %d/%d/%d",DAT_029139c4,DAT_029139c8
                 ,DAT_029139c0);
  }
  FUN_0063cff0();
  return;
}

