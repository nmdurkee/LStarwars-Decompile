/* Ghidra analysis pseudocode, not original source.
 * ev_9f32143acc641fc8c09d2d2f6cbbcb37d8d4315dda9a3c3d8b53f1525d5ab059
 * Entry: 0x4ec420; label: FUN_004ec420
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ec420(void)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  undefined *puVar6;
  float10 fVar7;
  undefined *puVar8;
  int local_8;
  
  local_8 = 0;
  if ('\0' < DAT_0088aaac) {
    puVar5 = &DAT_0088a794;
    do {
      puVar6 = puVar5 + -0xc0;
      FUN_005cfc00(puVar6,0);
      FUN_005cfc00(puVar5,0);
      puVar8 = puVar5 + 0xc0;
      FUN_005cfc00(puVar8,0);
      FUN_005cfc00(puVar5 + 0x180,0);
      puVar1 = puVar5 + 0x240;
      FUN_005cfc00(puVar1,0);
      if (DAT_00951b50 == 0) {
        *DAT_0088a628 = _DAT_0088aab8;
      }
      else {
        fVar7 = (float10)FUN_0054fb40(_DAT_0088aab8,*DAT_0088a628,0x41000000);
        _DAT_0088aab8 = (float)fVar7;
      }
      uVar2 = 1 << ((byte)local_8 & 0x1f);
      if ((uVar2 & (int)*(short *)(DAT_0088a628 + 1)) == 0) {
        if ((uVar2 & (int)*(short *)((int)DAT_0088a628 + 6)) != 0) {
          FUN_005cfc00(puVar5,1);
          iVar3 = FUN_005cf9e0(puVar5);
          puVar8 = puVar5;
          goto joined_r0x004ec521;
        }
        if ((uVar2 & (int)*(short *)(DAT_0088a628 + 2)) != 0) {
          FUN_005cfc00(puVar8,1);
          iVar3 = FUN_005cf9e0(puVar8);
joined_r0x004ec573:
          if (iVar3 == 0) goto LAB_004ec588;
          goto LAB_004ec577;
        }
        if ((uVar2 & (int)*(short *)((int)DAT_0088a628 + 10)) != 0) {
          puVar6 = puVar5 + 0x180;
          goto LAB_004ec4e9;
        }
        if ((uVar2 & (int)*(short *)(DAT_0088a628 + 3)) != 0) {
          FUN_005cfc00(puVar1,1);
          iVar3 = FUN_005cf9e0(puVar1);
          puVar8 = puVar1;
          goto joined_r0x004ec573;
        }
      }
      else {
LAB_004ec4e9:
        FUN_005cfc00(puVar6,1);
        iVar3 = FUN_005cf9e0(puVar6);
        puVar8 = puVar6;
joined_r0x004ec521:
        if (iVar3 != 0) {
LAB_004ec577:
          *(float *)(iVar3 + 4) = _DAT_0088aab8;
          FUN_005ea5d0(puVar8,iVar3);
        }
      }
LAB_004ec588:
      iVar3 = FUN_005cf9e0(&DAT_0087aae4);
      if (iVar3 != 0) {
        *(float *)(iVar3 + 4) = _DAT_008002e4 + _DAT_0088aab8;
        FUN_005ea5d0(&DAT_0087aae4,iVar3);
      }
      if ((uVar2 & (int)*(short *)((int)DAT_0088a628 + 0xe)) != 0) {
        iVar3 = FUN_005d0330(puVar5 + 0x180);
        FUN_00681f40("Kam_DiscoFloorPanelOn",iVar3 + 0x30);
      }
      local_8 = local_8 + 1;
      puVar5 = puVar5 + 0xc;
    } while (local_8 < DAT_0088aaac);
  }
  if (*(char *)(DAT_0088a628 + 4) == '\0') {
    FUN_004bccc0("Speaker2","Speaker21",0);
    FUN_004bccc0("Speaker1","Speaker11",0);
    FUN_004bccc0("decks","decks",0);
    *(undefined2 *)((int)DAT_0088a628 + 0x12) = 0;
  }
  else {
    FUN_005ab050(DAT_0095df4c,"DiscoComplete",0x3f800000,DAT_0088aac4);
    FUN_004bccc0("Speaker2","Speaker21",1);
    FUN_004bccc0("Speaker1","Speaker11",1);
    FUN_004bccc0("decks","decks",1);
    if (DAT_0088a62c != (undefined4 *)0x0) {
      FUN_00557960(*DAT_0088a62c);
    }
    iVar3 = FUN_005cfac0(&DAT_0088a678);
    if (iVar3 != 0) {
      FUN_005cfc00(&DAT_0088a678,1);
    }
    iVar3 = FUN_005cfac0(&DAT_0088a684);
    if (iVar3 != 0) {
      FUN_005cfc00(&DAT_0088a684,1);
    }
    iVar3 = FUN_005cfac0(&DAT_0088a6a8);
    if ((iVar3 != 0) && (iVar3 = FUN_005d0420(&DAT_0088a6a8), iVar3 != 0)) {
      *(uint *)(iVar3 + 0x50) = *(uint *)(iVar3 + 0x50) | 1;
    }
    iVar3 = FUN_005cfac0(&DAT_0088a6b4);
    if ((iVar3 != 0) && (iVar3 = FUN_005cfac0(&DAT_0088a6c0), iVar3 != 0)) {
      iVar3 = FUN_005d0420(&DAT_0088a6b4);
      if (iVar3 != 0) {
        *(uint *)(iVar3 + 0x50) = *(uint *)(iVar3 + 0x50) | 1;
      }
      iVar3 = FUN_005d0420(&DAT_0088a6c0);
      if (iVar3 != 0) {
        *(uint *)(iVar3 + 0x50) = *(uint *)(iVar3 + 0x50) | 1;
      }
    }
    if (*(short *)((int)DAT_0088a628 + 0x12) == 0) {
      uVar4 = FUN_005cf9e0(&DAT_0088a6d4);
      FUN_00681f40("Kam_DiscoFloorPanelDone",uVar4);
      *(undefined2 *)((int)DAT_0088a628 + 0x12) = 1;
      return;
    }
  }
  return;
}

