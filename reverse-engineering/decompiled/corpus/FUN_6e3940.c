/* Ghidra analysis pseudocode, not original source.
 * ev_14516b90afd78e4126f0b3f4a370dbc2a5912f8e0102dea09dbec3c8384d0f78
 * Entry: 0x6e3940; label: FUN_006e3940
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e3940(void)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  int iVar7;
  undefined4 *in_ECX;
  uint uVar8;
  int unaff_EBX;
  int *piVar9;
  undefined4 *puVar10;
  char *pcVar11;
  undefined4 uVar12;
  char cVar13;
  
  FUN_006df300();
  in_ECX[0x19c] = in_ECX[0x188];
  *(bool *)((int)in_ECX + 0x66e) = in_ECX[0x56] == 1;
  *(undefined2 *)(in_ECX + 0x19f) = *(undefined2 *)(in_ECX + 0x1b9);
  in_ECX[0x19e] = in_ECX[0x18e];
  *(undefined1 *)(in_ECX + 0x19d) = *(undefined1 *)(in_ECX + 0x18d);
  in_ECX[0x1a0] = DAT_00826494;
  (**(code **)(*(int *)*in_ECX + 0x38))();
  in_ECX[0x55] = DAT_00924864;
  in_ECX[0x56] = (uint)*(byte *)(in_ECX + 0x197);
  in_ECX[0x57] = 1;
  in_ECX[0x59] = 2;
  in_ECX[0x54] = 1;
  in_ECX[0x58] = 0x4b;
  if ((*(char *)(in_ECX + 0x199) != '\0') && ((*(byte *)(in_ECX + 7) & 1) == 0)) {
    *(undefined1 *)(in_ECX + 0x199) = 0;
  }
  *(undefined1 *)(in_ECX + 0x18d) = *(undefined1 *)(in_ECX + 0x199);
  in_ECX[0x51] = 2;
  in_ECX[0x5b] = 1;
  if ((*(byte *)(in_ECX + 0x197) != 0) && (unaff_EBX != 0)) {
    uVar6 = DAT_00826484;
    if ((int)DAT_00826484 < 0) {
      uVar6 = (uint)(DAT_02976bd0 - DAT_0082647c) >> 1;
    }
    uVar8 = DAT_00826488;
    if ((int)DAT_00826488 < 0) {
      uVar8 = (uint)(DAT_02976bd4 - DAT_00826480) >> 1;
    }
    MoveWindow(DAT_00924864,uVar6,uVar8,DAT_0082647c,DAT_00826480,1);
  }
  iVar7 = (**(code **)(*DAT_029765c8 + 0x24))(DAT_029765c8);
  if (iVar7 < 0) {
    in_ECX[0x50] = *(undefined4 *)(in_ECX[0x198] * 0x10 + 0xc + in_ECX[0x187]);
  }
  else {
    in_ECX[0x50] = 0x15;
  }
  puVar10 = (undefined4 *)(in_ECX[0x198] * 0x10 + in_ECX[0x187]);
  in_ECX[0x4e] = *puVar10;
  in_ECX[0x4f] = puVar10[1];
  in_ECX[0x5a] = puVar10[2];
  if (in_ECX[0x56] != 0) {
    in_ECX[0x5a] = 0;
  }
  in_ECX[0x17d] = 0;
  if (*(char *)(in_ECX + 0x17e) == '\0') {
    in_ECX[0x17d] = 0x10;
  }
  if (*(char *)((int)in_ECX + 0x5fa) != '\0') {
    in_ECX[0x17d] = in_ECX[0x17d] | 4;
  }
  if (*(char *)(in_ECX + 0x17e) == '\0') {
    if ((uint)in_ECX[0x33] < 0xfffe0101) {
      if ((in_ECX[9] & 0x10000) == 0) goto LAB_006e3b51;
      in_ECX[0x17d] = in_ECX[0x17d] | 0x80;
    }
    else {
      in_ECX[0x17d] = in_ECX[0x17d] | 0x40;
    }
  }
  else {
LAB_006e3b51:
    in_ECX[0x17d] = in_ECX[0x17d] | 0x20;
  }
  uVar12 = 0;
  in_ECX[0x17c] = 1;
  in_ECX[0x68] = 0;
  (**(code **)(*(int *)*in_ECX + 0x14))((int *)*in_ECX,0,0,in_ECX + 0x69);
  FUN_006e66b0();
  if (*(char *)(in_ECX + 399) == '\0') {
    puVar10 = &DAT_00828230;
    piVar9 = in_ECX + 400;
    do {
      uVar6 = 0;
      uVar8 = 0;
      bVar3 = true;
      iVar7 = (**(code **)(*(int *)*in_ECX + 0x2c))
                        ((int *)*in_ECX,in_ECX[0x68],in_ECX[0x17c],in_ECX[0x50],in_ECX[0x56],
                         *puVar10,&stack0xffffffcc);
      if ((iVar7 < 0) ||
         (iVar7 = (**(code **)(*(int *)*in_ECX + 0x2c))
                            ((int *)*in_ECX,in_ECX[0x68],in_ECX[0x17c],in_ECX[0x58],in_ECX[0x56],
                             *puVar10,&stack0xffffffc4), iVar7 < 0)) {
        bVar3 = false;
      }
      if (uVar6 <= uVar8) {
        uVar6 = uVar8;
      }
      if ((uVar6 == 0) || (!bVar3)) {
        iVar7 = -1;
      }
      else {
        iVar7 = uVar6 - 1;
      }
      *piVar9 = iVar7;
      puVar10 = puVar10 + 1;
      piVar9 = piVar9 + 1;
    } while (puVar10 != (undefined4 *)&DAT_00828244);
    in_ECX[400] = 0;
    in_ECX[0x196] = 0;
    *(undefined1 *)(in_ECX + 399) = 1;
  }
  cVar13 = (char)((uint)uVar12 >> 0x18);
  if (*(char *)(in_ECX + 399) == '\0') {
LAB_006e3c91:
    in_ECX[0x18e] = 0;
  }
  else if (in_ECX[in_ECX[0x19a] + 400] == -1) {
    if ((*(char *)(in_ECX + 399) == '\0') || (in_ECX[in_ECX[0x18e] + 400] == -1)) goto LAB_006e3c91;
  }
  else {
    in_ECX[0x18e] = in_ECX[0x19a];
  }
  in_ECX[0x52] = (&DAT_00828230)[in_ECX[0x18e]];
  piVar9 = in_ECX + 1;
  in_ECX[0x53] = in_ECX[in_ECX[0x18e] + 400] & ((int)in_ECX[in_ECX[0x18e] + 400] < 0) - 1;
  if (*piVar9 != 0) {
    if (DAT_00827610 != 0) {
      iVar7 = FUN_006e5850();
      if (iVar7 < 0) {
        if (iVar7 != -0x7789f7d9) {
          if (iVar7 == -0x7789f798) {
            if (DAT_0297be98 != (code *)0x0) {
              (*DAT_0297be98)(in_ECX + 0x4e);
            }
            goto LAB_006e3f12;
          }
          if (iVar7 == -0x7789f797) {
            FUN_006e4a40();
            FUN_006df0e0(0);
            iVar7 = (**(code **)(*(int *)*piVar9 + 0x40))((int *)*piVar9,in_ECX + 0x4e);
            if (-1 < iVar7) {
              FUN_006dfe20(0);
            }
            goto LAB_006e3f12;
          }
        }
        SendMessageA(DAT_00924864,0x10,0,0);
      }
      else {
        FUN_006e4a40();
        FUN_006df0e0(1);
        (**(code **)(*(int *)*piVar9 + 0x40))((int *)*piVar9,in_ECX + 0x4e);
        DAT_00973900 = in_ECX[0x4e];
        DAT_00973904 = in_ECX[0x4f];
        _DAT_0080202c = DAT_00973900 / 2;
        _DAT_00802030 = DAT_00973904 / 2;
        FUN_006dfe20(1);
      }
    }
    goto LAB_006e3f12;
  }
  piVar1 = in_ECX + 0x4e;
  _DAT_0297bea0 =
       (**(code **)(*DAT_029765c8 + 0x40))
                 (DAT_029765c8,in_ECX[0x68],in_ECX[0x17c],in_ECX[0x55],in_ECX[0x17d],piVar1,piVar9);
  cVar13 = (char)((uint)uVar12 >> 0x18);
  for (iVar7 = 0xf; (_DAT_0297bea0 < 0 && (cVar13 = (char)((uint)uVar12 >> 0x18), iVar7 != 0));
      iVar7 = iVar7 + -1) {
    Sleep(500);
    _DAT_0297bea0 =
         (**(code **)(*DAT_029765c8 + 0x40))
                   (DAT_029765c8,in_ECX[0x68],in_ECX[0x17c],in_ECX[0x55],in_ECX[0x17d],piVar1,piVar9
                   );
    cVar13 = (char)((uint)uVar12 >> 0x18);
  }
  if (*piVar9 == 0) {
    *piVar1 = 0x280;
    in_ECX[0x4f] = 0x1e0;
    in_ECX[0x5a] = 0x3c;
    _DAT_0297bea0 =
         (**(code **)(*(int *)*in_ECX + 0x40))
                   ((int *)*in_ECX,in_ECX[0x68],in_ECX[0x17c],in_ECX[0x55],in_ECX[0x17d],piVar1,
                    piVar9);
    if (*piVar9 == 0) {
      if (_DAT_0297bea0 == -0x7789fe84) {
        pcVar11 = "Out of Video Memory. Application will now exit";
      }
      else if (_DAT_0297bea0 == -0x7789f798) {
        pcVar11 = "Lost d3d device. Application will now exit";
      }
      else {
        if (_DAT_0297bea0 != -0x7789f796) {
          FUN_006e0080(&DAT_02976078,
                       "Failed to create d3d device. Application will now exit.\nError = 0x%x",
                       _DAT_0297bea0);
          goto LAB_006e3df5;
        }
        pcVar11 = "d3d device unavailable. Application will now exit";
      }
      FUN_006e0080(&DAT_02976078,pcVar11);
    }
  }
LAB_006e3df5:
  DAT_00973900 = *piVar1;
  _DAT_0080202c = DAT_00973900 / 2;
  DAT_00973904 = in_ECX[0x4f];
  _DAT_00802030 = DAT_00973904 / 2;
LAB_006e3f12:
  in_ECX[0x18e] = 0;
  iVar7 = 0;
  do {
    if ((&DAT_00828230)[iVar7] == in_ECX[0x52]) {
      in_ECX[0x18e] = iVar7;
      break;
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 != 5);
  iVar7 = in_ECX[0x4f];
  iVar2 = in_ECX[0x4e];
  DAT_0297dbd0 = FUN_006e1d00(iVar2,iVar7);
  fVar4 = (float)iVar2;
  in_ECX[0x18b] = DAT_0297dbd0;
  if (iVar2 < 0) {
    fVar4 = fVar4 + 4.2949673e+09;
  }
  fVar5 = (float)iVar7;
  if (iVar7 < 0) {
    fVar5 = fVar5 + 4.2949673e+09;
  }
  in_ECX[0x18c] = fVar4 / fVar5;
  if (DAT_00826494 != 3) {
    DAT_0297dbd0 = DAT_00826494;
  }
  if (in_ECX[0x56] == 0) {
    uVar12 = in_ECX[0x5a];
  }
  else {
    uVar12 = *(undefined4 *)(in_ECX[0x198] * 0x10 + 8 + in_ECX[0x187]);
  }
  uVar12 = FUN_006e1b70(in_ECX[0x4e],in_ECX[0x4f],uVar12);
  in_ECX[0x188] = uVar12;
  (**(code **)(*(int *)*piVar9 + 0x1c))((int *)*piVar9,in_ECX + 2);
  if (cVar13 != '\0') {
    FUN_006e2d20();
  }
  FUN_006e3650();
  FUN_006e45e0(0,0,1,0,0x3f800000,0);
  uVar12 = (**(code **)(*(int *)*piVar9 + 0x44))((int *)*piVar9,0,0,0,0);
  in_ECX[0x17f] = uVar12;
  iVar7 = 0;
  do {
    FUN_006e54e0(iVar7,5,2);
    FUN_006e54e0(iVar7,6,2);
    FUN_006e54e0(iVar7,7,2);
    iVar7 = iVar7 + 1;
  } while (iVar7 != 8);
  if (DAT_02974d1c == 0) {
    FUN_006e5570(0);
  }
  FUN_006e5340(0xa1,in_ECX[0x18e] != 0);
  in_ECX[0x1bc] = 0;
  in_ECX[0x1bd] = 0;
  in_ECX[0x1be] = 0;
  in_ECX[0x1bf] = 0;
  FUN_006daef0(DAT_00973900);
  FUN_006daf00(DAT_00973904);
  if (in_ECX[0x56] == 0) {
    FUN_006daf50(in_ECX[0x5a]);
  }
  FUN_006daf60(in_ECX[0x18e]);
  FUN_006db1c0();
  in_ECX[0x62] = 0;
  in_ECX[99] = 0;
  in_ECX[100] = DAT_00973900;
  iVar7 = DAT_00973904;
  in_ECX[0x66] = 0;
  in_ECX[0x67] = 0x3f800000;
  in_ECX[0x65] = iVar7;
  *(bool *)(in_ECX + 0x197) = in_ECX[0x56] == 1;
  in_ECX[0x198] = in_ECX[0x188];
  *(undefined1 *)(in_ECX + 0x199) = *(undefined1 *)(in_ECX + 0x18d);
  in_ECX[0x19a] = in_ECX[0x18e];
  *(undefined2 *)(in_ECX + 0x19b) = *(undefined2 *)(in_ECX + 0x1b9);
  FUN_006df310();
  return;
}

