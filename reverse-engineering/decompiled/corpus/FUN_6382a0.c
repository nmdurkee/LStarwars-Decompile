/* Ghidra analysis pseudocode, not original source.
 * ev_b2f72df0dabe11c9bc7c22be1245d6bb58dcd22f440da2427165c0dad76f7a14
 * Entry: 0x6382a0; label: FUN_006382a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006382a0(void)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  
  FUN_005d0a40(1);
  FUN_005d0fe0(DAT_009738b8,_DAT_0080fe00,_DAT_0080fe00);
  iVar1 = DAT_02913838;
  *(byte *)(DAT_02913838 + 0x11) = *(byte *)(DAT_02913838 + 0x11) | 2;
  iVar2 = DAT_029138bc;
  *(byte *)(DAT_029138bc + 0x11) = *(byte *)(DAT_029138bc + 0x11) | 2;
  *(byte *)(DAT_029138b8 + 0x11) = *(byte *)(DAT_029138b8 + 0x11) | 2;
  iVar7 = DAT_029137cc;
  *(byte *)(DAT_029137cc + 0x11) =
       *(byte *)(DAT_029137cc + 0x11) ^
       ((DAT_02913778 == '\0') * '\x02' ^ *(byte *)(DAT_029137cc + 0x11)) & 2;
  iVar9 = DAT_0291382c;
  if ((DAT_02913778 == '\0') || (DAT_02913824 == 0)) {
    cVar3 = '\x01';
  }
  else {
    cVar3 = '\0';
  }
  *(byte *)(DAT_0291382c + 0x11) =
       *(byte *)(DAT_0291382c + 0x11) ^ (cVar3 * '\x02' ^ *(byte *)(DAT_0291382c + 0x11)) & 2;
  if (DAT_02913824 == 0) {
    *(byte *)(DAT_02913540 + 0x11) = *(byte *)(DAT_02913540 + 0x11) | 2;
  }
  else if (*(char *)(DAT_02913824 + 0x78) == '\0') {
    *(byte *)(DAT_02913540 + 0x11) = *(byte *)(DAT_02913540 + 0x11) | 2;
  }
  else {
    *(byte *)(DAT_02913540 + 0x11) = *(byte *)(DAT_02913540 + 0x11) & 0xfd;
  }
  if (DAT_02913824 == 0) goto LAB_006386ba;
  *(byte *)(iVar1 + 0x11) = *(byte *)(iVar1 + 0x11) & 0xfd;
  *(byte *)(iVar2 + 0x11) = *(byte *)(iVar2 + 0x11) & 0xfd;
  if ((*(char *)(DAT_02913824 + 0x79) == -1) || (*(char *)(DAT_02913824 + 0x7a) != -1)) {
    *(byte *)(DAT_02913890 + 0x11) = *(byte *)(DAT_02913890 + 0x11) & 0xfd;
  }
  else {
    *(byte *)(DAT_02913890 + 0x11) = *(byte *)(DAT_02913890 + 0x11) | 2;
  }
  switch(*(undefined1 *)(DAT_02913824 + 0x58)) {
  case 1:
    FUN_006193e0(DAT_02913810,DAT_029137b4);
    break;
  case 2:
    uVar4 = DAT_029137c0;
    goto LAB_006383c4;
  case 3:
    uVar4 = DAT_029134a0;
    goto LAB_006383db;
  case 4:
    FUN_006193e0(DAT_02913810,DAT_029134b8);
    break;
  case 5:
    uVar4 = DAT_02913530;
LAB_006383c4:
    FUN_006193e0(DAT_02913810,uVar4);
    break;
  case 6:
    uVar4 = DAT_0291363c;
LAB_006383db:
    FUN_006193e0(DAT_02913810,uVar4);
    uVar4 = DAT_02913638;
LAB_00638445:
    iVar7 = DAT_029138b8;
    *(byte *)(DAT_029138b8 + 0x11) = *(byte *)(DAT_029138b8 + 0x11) & 0xfd;
    *(undefined4 *)(iVar7 + 0xc) = uVar4;
    break;
  case 7:
    FUN_006193e0(DAT_02913810,DAT_02913550);
    break;
  case 8:
    FUN_006193e0(DAT_02913810,DAT_029134e4);
    uVar4 = DAT_029134d8;
    goto LAB_00638445;
  }
  *(byte *)(DAT_029134b4 + 0x11) =
       *(byte *)(DAT_029134b4 + 0x11) ^
       (*(byte *)(DAT_02913824 + 0x59) >> 1 ^ *(byte *)(DAT_029134b4 + 0x11)) & 1;
  *(byte *)(DAT_0291354c + 0x11) =
       *(byte *)(DAT_0291354c + 0x11) ^
       (*(byte *)(DAT_02913824 + 0x59) >> 2 ^ *(byte *)(DAT_0291354c + 0x11)) & 1;
  iVar7 = (int)*(char *)(DAT_02913824 + 0x7b);
  if (DAT_0080fe14 + -1 < (int)*(char *)(DAT_02913824 + 0x7b)) {
    iVar7 = DAT_0080fe14 + -1;
  }
  FUN_006193e0(DAT_02913830,(&DAT_02913698)[iVar7]);
  iVar7 = 0;
  do {
    if ((((uint)*(ushort *)(DAT_02913824 + 0x5e) & 1 << ((byte)iVar7 & 0x1f)) != 0) !=
        (bool)(*(byte *)((&DAT_029137d0)[iVar7] + 0x11) & 1)) {
      FUN_006193e0(DAT_02913554,(&DAT_029137d0)[iVar7]);
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x10);
  iVar7 = 0;
  do {
    if ((((uint)*(ushort *)(DAT_02913824 + 0x60) & 1 << ((byte)iVar7 & 0x1f)) != 0) !=
        (bool)(*(byte *)((&DAT_02913850)[iVar7] + 0x11) & 1)) {
      FUN_006193e0(DAT_0291381c,(&DAT_02913850)[iVar7]);
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0x10);
  uVar8 = 0;
  do {
    if (uVar8 == *(ushort *)(DAT_02913824 + 0x68)) {
      FUN_006193e0(DAT_029137bc,(&DAT_029135f8)[uVar8]);
    }
    uVar8 = uVar8 + 1;
  } while ((int)uVar8 < 0x10);
  FUN_0061d810(DAT_0291383c,*(undefined4 *)(DAT_02913824 + 0x6c),0,0);
  FUN_0061d810(DAT_02913844,(float)*(byte *)(DAT_02913824 + 0x78),0,0);
  FUN_0061d810(DAT_029134d0,*(undefined4 *)(DAT_02913824 + 0x44),0,0);
  FUN_0061d810(DAT_029134cc,*(undefined4 *)(DAT_02913824 + 0x48),0,0);
  FUN_0061d810(DAT_029134f4,*(undefined4 *)(DAT_02913824 + 0x4c),0,0);
  FUN_0061d810(DAT_02913498,*(undefined4 *)(DAT_02913824 + 0x50),0,0);
  FUN_0061d810(DAT_02913848,*(undefined4 *)(DAT_02913824 + 0x44),0,0);
  FUN_0061d810(DAT_0291371c,*(undefined4 *)(DAT_02913824 + 0x48),0,0);
  FUN_0061d810(DAT_02913898,*(undefined4 *)(DAT_02913824 + 0x4c),0,0);
  iVar9 = DAT_0291382c;
  iVar7 = DAT_029137cc;
LAB_006386ba:
  if (DAT_02913778 != '\0') {
    uVar8 = FUN_006e6b90();
    uVar5 = FUN_006e6b90();
    uVar6 = FUN_006e6b90();
    *(uint *)(iVar7 + 0x30) = ((uVar8 & 0xff | 0xffff8000) << 8 | uVar5 & 0xff) << 8 | uVar6 & 0xff;
    uVar8 = FUN_006e6b90();
    uVar5 = FUN_006e6b90();
    uVar6 = FUN_006e6b90();
    *(uint *)(iVar9 + 0x30) = ((uVar8 & 0xff | 0xffff8000) << 8 | uVar5 & 0xff) << 8 | uVar6 & 0xff;
  }
  *(byte *)(DAT_02913640 + 0x11) = *(byte *)(DAT_02913640 + 0x11) | 2;
  *(byte *)(DAT_02913644 + 0x11) =
       *(byte *)(DAT_02913644 + 0x11) ^
       ((DAT_0291365c == 0) * '\x02' ^ *(byte *)(DAT_02913644 + 0x11)) & 2;
  if ((DAT_0291365c == 0) || (DAT_02913814 == (undefined4 *)0x0)) {
    cVar3 = '\x01';
  }
  else {
    cVar3 = '\0';
  }
  *(byte *)(DAT_029134c0 + 0x11) =
       *(byte *)(DAT_029134c0 + 0x11) ^ (cVar3 * '\x02' ^ *(byte *)(DAT_029134c0 + 0x11)) & 2;
  *(byte *)(DAT_02913840 + 0x11) = *(byte *)(DAT_02913840 + 0x11) | 2;
  if (DAT_02913814 != (undefined4 *)0x0) {
    FUN_0061d810(DAT_029138a0,(float)*(byte *)((int)DAT_02913814 + 0xb),0,0);
    FUN_0061d810(DAT_029138a8,DAT_02913814[0xb],0,0);
    FUN_0061d810(DAT_02913718,DAT_02913814[0xf],0,0);
    FUN_0061d810(DAT_02913544,DAT_02913814[0xc],0,0);
    FUN_0061d810(DAT_029134ec,DAT_02913814[0xd],0,0);
    FUN_0061d810(DAT_029134f0,*DAT_02913814,0,0);
    FUN_0061d810(DAT_029138a4,DAT_02913814[1],0,0);
    FUN_0061d810(DAT_029138c4,(float)*(byte *)(DAT_02913814 + 6) / 10.0,0,0);
    FUN_0061d810(DAT_02913828,(float)*(byte *)((int)DAT_02913814 + 0x13),0,0);
    FUN_0061d810(DAT_029138c8,(float)(int)DAT_02913814[3] * 0.0078125,0,0);
    *(byte *)(DAT_02913840 + 0x11) = *(byte *)(DAT_02913840 + 0x11) & 0xfd;
    *(byte *)(DAT_02913640 + 0x11) = *(byte *)(DAT_02913640 + 0x11) & 0xfd;
  }
  iVar7 = 0;
  if (0 < DAT_0080fe14) {
    do {
      FUN_0061d810((&DAT_029138d0)[iVar7],*(undefined4 *)(PTR_DAT_0080fe0c + iVar7 * 4),0,0);
      iVar7 = iVar7 + 1;
    } while (iVar7 < DAT_0080fe14);
  }
  FUN_005d0a70();
  return;
}

