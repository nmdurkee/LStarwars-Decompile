/* Ghidra pseudocode, not original source.
 * ev_76542f68f87d7c8d0966794efacf0e34fd9d23b5b5d54cd2bf4b2d5954a88cd4
 * Entry: 0x60aff0; label: FUN_0060aff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0060aff0(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  byte bVar9;
  int local_3c;
  int local_38;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  int iStack_1c;
  char cStack_18;
  int *piStack_14;
  short sStack_4;
  
  _DAT_02857274 = _DAT_02857274 + _DAT_0297dbfc;
  local_3c = -1;
  DAT_0080e1a8 = 0xef00;
  DAT_0080e1ac = 0x800;
  FUN_006dfd30(1);
  FUN_006df300();
  FUN_006e5630(0,0);
  FUN_006e5630(1,0);
  FUN_006e5630(2,0);
  FUN_006e5630(3,0);
  FUN_006e5590(0,0,0,0);
  FUN_006e5590(1,0,0,0);
  FUN_006e5590(2,0,0,0);
  FUN_006e5590(3,0,0,0);
  FUN_00741640(0);
  FUN_005ffc30();
  FUN_005f0d70();
  FUN_005fd450();
  FUN_005d8440(0xffffffff,0);
  FUN_005dece0();
  FUN_005d8400(0xffffffff,4,"CPU_QUEUE_DRAW");
  iVar6 = 0;
  if (0 < DAT_0097389c) {
    iVar8 = 0;
    do {
      if (0x7f < iVar8) break;
      FUN_00741300(0x4e,iVar6,iVar8 + DAT_009738a0);
      iVar6 = iVar6 + 1;
      iVar8 = iVar8 + 0x10;
    } while (iVar6 < DAT_0097389c);
  }
  FUN_007412e0(0x3f,&DAT_02857274);
  FUN_006dfa20();
  FUN_005c31f0();
  if (0 < DAT_0095fbb8) {
    piVar7 = &DAT_00964148;
    iVar6 = 0;
    do {
      if (DAT_008264b8 == '\0') {
        *piVar7 = 0;
      }
      if (DAT_008264c4 == '\0') {
        piVar7[-4] = 0;
      }
      if (DAT_008264c6 == '\0') {
        piVar7[0x4c] = 0;
      }
      if (((((*piVar7 != 0) && (iVar8 = FUN_005c32c0(4), iVar8 != 0)) ||
           ((piVar7[0x15] != 0 && (iVar8 = FUN_005c32c0(8), iVar8 != 0)))) ||
          ((piVar7[-4] != 0 && (iVar8 = FUN_005c32c0(0x20), iVar8 != 0)))) ||
         ((piVar7[0x4c] != 0 && (iVar8 = FUN_005c32c0(0x80), iVar8 != 0)))) {
        local_3c = iVar6;
      }
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 0x86;
    } while (iVar6 < DAT_0095fbb8);
    if (local_3c != -1) {
      FUN_005f8bf0(DAT_02854bc8);
    }
  }
  local_38 = 0;
  if (0 < DAT_0095fbb8) {
    piVar7 = &DAT_00964128;
    do {
      bVar3 = false;
      DAT_02854bb0 = piVar7[-5];
      local_2c = (float)DAT_00973900;
      local_28 = (float)DAT_00973904;
      uVar1 = *(undefined4 *)(&DAT_028492f0 + (uint)(local_3c <= local_38) * 4);
      local_24 = 1.0 / local_2c;
      local_20 = 1.0 / local_28;
      if (*piVar7 != 0) {
        iVar6 = piVar7[1];
        iVar8 = FUN_005c6bb0(iVar6);
        if (iVar8 != 0) {
          if (piVar7[-0xe] != -1) {
            FUN_005c6d20(iVar6,piVar7[2],piVar7[-0xe]);
          }
          if (piVar7[2] == 0) {
            FUN_005c3640(iVar6);
          }
        }
        piVar7[-0xe] = -1;
      }
      if (piVar7[0x1d] != 0) {
        FUN_005c32c0(8);
      }
      if ((piVar7[8] != 0) && (iVar6 = FUN_005c32c0(4), iVar6 != 0)) {
        FUN_005c32d0(4);
        FUN_005c36e0(piVar7 + 8);
        piVar7[8] = 0;
        bVar3 = true;
      }
      if (piVar7[4] != 0) {
        FUN_005c32d0(0x20);
        FUN_005c36b0(piVar7 + 4);
        piVar7[4] = 0;
        bVar3 = true;
      }
      if (piVar7[0x54] != 0) {
        FUN_005c32d0(0x80);
        FUN_005c37d0(piVar7 + 0x54);
        bVar3 = true;
      }
      if (local_3c < local_38) {
        FUN_006dfd70();
      }
      else {
        FUN_006dfd80();
      }
      FUN_007412e0(0x3e,&local_2c);
      uVar2 = piVar7[-0xc];
      if (uVar2 != 0) {
        FUN_006e5340(7,1);
        FUN_006e5340(0xe,1);
        FUN_006e5340(0x34,1);
        bVar9 = (uVar2 & 0x100) != 0;
        if ((uVar2 & 0x200) != 0) {
          bVar9 = bVar9 | 2;
        }
        if ((uVar2 & 0x1800) != 0) {
          bVar9 = bVar9 | 4;
        }
        uVar2 = piVar7[-0xb];
        piVar7[-0xb] = uVar2 | 0xff000000;
        FUN_006e45e0(0,0,bVar9,
                     ((((int)(uVar2 | 0xff000000) >> 0x18) * 0x100 + (uVar2 & 0xff)) * 0x100 +
                     ((uVar2 & 0xff00) >> 8)) * 0x100 + ((uVar2 & 0xff0000) >> 0x10),piVar7[-10],
                     0x60);
        FUN_006e5340(0x34,0);
      }
      if (piVar7[-0xe] != -1) {
        D3DPERF_BeginEvent(0xffffffff,L"3D render");
        FUN_005f02e0(piVar7[-0xe]);
        D3DPERF_EndEvent();
      }
      if (bVar3) {
        FUN_006dfd90();
        FUN_00741640(0);
        FUN_005e6a80(uVar1);
        FUN_00741640(0);
        FUN_006dfa20();
      }
      if (((piVar7[0x77] != 0) &&
          (iVar6 = FUN_005e5310(piVar7[0x77]), (uint)((iVar6 + -0x2855050) / 0x30) < 0x10)) &&
         (iVar6 = *(int *)(iVar6 + 0x28), iVar6 != 0)) {
        iVar8 = FUN_005e52d0(piVar7[0x77]);
        iVar5 = FUN_005e52f0(piVar7[0x77]);
        if ((iVar8 == DAT_00973900) && (iVar5 == DAT_00973904)) {
          cVar4 = '\0';
        }
        else {
          cVar4 = '\x01';
        }
        FUN_006069a0();
        FUN_005fb870(iVar6,0,0);
        FUN_006e2320(&iStack_1c,cVar4 + '\x01',0);
        if ((iStack_1c == 0) || (*(int *)(iStack_1c + 0x28) == 0)) {
          if (piStack_14 != (int *)0x0) {
            (**(code **)(*piStack_14 + 8))(piStack_14);
            goto LAB_0060b4ca;
          }
        }
        else {
LAB_0060b4ca:
          piStack_14 = (int *)0x0;
        }
        if ((iStack_1c != 0) && (cStack_18 != '\0')) {
          FUN_005f7b40(iStack_1c);
        }
        (&DAT_00986a88)[sStack_4] = 0;
      }
      local_38 = local_38 + 1;
      piVar7 = piVar7 + 0x86;
    } while (local_38 < DAT_0095fbb8);
  }
  DAT_0095fbb8 = 0;
  FUN_005decd0();
  FUN_005c3200();
  FUN_005d8440(0xffffffff,4);
  FUN_005ded40();
  FUN_005dfab0();
  DAT_009736e0 = &DAT_0097c1ac;
  DAT_00971578 = DAT_02854b88;
  if (DAT_00973910 == 0) {
    DAT_0097390c = DAT_0097390c + 1;
  }
  if (DAT_02854ce4 != (code *)0x0) {
    (*DAT_02854ce4)();
  }
  FUN_005f39e0(0);
  FUN_006e4a10();
  FUN_006d9610();
  FUN_006dfd40(param_1,1);
  FUN_006df310();
  FUN_005d8370(0xffffffff,0);
  FUN_005d8400(0xffffffff,0,&DAT_0076a8b4);
  return 1;
}

