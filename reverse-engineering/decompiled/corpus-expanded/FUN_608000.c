/* Ghidra pseudocode, not original source.
 * ev_deacb65ff86bfd262c36c7125baff66f7c0e4faab911474243066d5360a0fd29
 * Entry: 0x608000; label: FUN_00608000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00608000(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  bool bVar6;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [64];
  
  iVar1 = FUN_00741620((int)*(short *)(param_1 + 500));
  _DAT_00991da4 = param_1;
  DAT_02854c20 = param_1;
  DAT_00986eb4 = 0xffffffff;
  _DAT_0080e194 = 0xffffffff;
  if ((*(uint *)(param_1 + 0x1f0) & 0x100000) == 0) {
    if ((*(uint *)(param_1 + 0x1f0) & 0x200000) == 0) {
      if (*(int *)(param_1 + 0x3c) == 0) {
        if (iVar1 == 0) {
          FUN_00741640(0);
          FUN_006e56c0(DAT_02854d44);
          FUN_005fa0a0();
        }
        else {
          FUN_00742730(iVar1,param_1);
          FUN_00741640(iVar1);
          FUN_006e56c0(*(undefined4 *)(param_1 + 700));
        }
      }
      else if (iVar1 == 0) {
        FUN_005f7490();
        FUN_00741640(0);
      }
      else {
        FUN_00742730(iVar1,param_1);
        FUN_00741640(iVar1);
        FUN_006e56c0(*(undefined4 *)(param_1 + 700));
        if (DAT_02854bb0 != 0) {
          FUN_006e5290(0);
        }
      }
      goto LAB_006082f0;
    }
    FUN_00742730(iVar1,param_1);
    FUN_00741640(0);
    FUN_006e5700(0);
    FUN_006e5290(0);
    DAT_02854c18 = 0;
    DAT_02854c1c = 0;
    FUN_006e56c0(DAT_02854d40);
    FUN_005fa0a0();
    if (DAT_02974d1c != 4) {
      FUN_005b59a0(local_40,&DAT_0097e230);
      FUN_006e5750(0,local_40,4);
      FUN_005b59a0(local_40,&DAT_00986eb8);
      FUN_006e5750(0xc,local_40,4);
      FUN_006e5750(0x30,&DAT_0082cab8,1);
    }
    FUN_006e52e0(0,&DAT_0082ca5c,1);
  }
  else {
    FUN_006e5700(0);
    FUN_006e5290(0);
    DAT_02854c18 = 0;
    DAT_02854c1c = 0;
    FUN_00741640(0);
    FUN_006e56c0(DAT_02854d3c);
    FUN_005fa0a0();
    if ((DAT_008264c7 == '\0') || (DAT_02974d1c != 4)) {
      FUN_005b59a0(local_40,&DAT_0097e230);
      FUN_006e5750(0,local_40,4);
      FUN_005b59a0(local_40,&DAT_00986eb8);
      FUN_006e5750(0xc,local_40,4);
      FUN_006e5750(0x30,&DAT_0082cab8,1);
    }
    FUN_006e52e0(0,&DAT_0082ca5c,1);
    if (*(char *)(param_1 + 0x99) == -0x69) {
      puVar2 = (undefined4 *)FUN_005c37f0(0xffffffff);
      if (puVar2 == (undefined4 *)0x0) {
        uVar5 = 0;
      }
      else {
        uVar5 = *puVar2;
      }
      FUN_006e5630(0,uVar5);
      FUN_006e54e0(0,1,3);
      FUN_006e54e0(0,2,3);
      FUN_006e54e0(0,7,0);
      iVar3 = FUN_005e5310(DAT_02854d48);
      FUN_006e5630(1,*(undefined4 *)(iVar3 + 0x24));
      goto LAB_006082f0;
    }
  }
  if (*(int *)(param_1 + 0xb8) != 0) {
    iVar3 = FUN_005e5310(*(int *)(param_1 + 0xb8));
    FUN_006e5630(0,*(undefined4 *)(iVar3 + 0x24));
  }
LAB_006082f0:
  iVar3 = 0;
  DAT_02854d50 = 0;
  FUN_00601360(param_1);
  bVar6 = (*(byte *)(iVar1 + 0x4d4) & 6) == 0;
  FUN_006e2810(bVar6,bVar6,1);
  uVar4 = (~*(uint *)(iVar1 + 0x4d4) & 8) >> 3;
  FUN_006e2810(uVar4,uVar4,3);
  if ((DAT_02974d1c != 4) && (iVar1 = FUN_00741610(), iVar1 != 0)) {
    iVar1 = FUN_00741610();
    if ((iVar1 != 0) && (iVar1 = FUN_00741610(), -1 < *(short *)(iVar1 + 0x3d0))) {
      do {
        local_50 = 0x3f800000;
        local_4c = 0x3f800000;
        local_48 = 0x3f800000;
        local_44 = 0x3f800000;
        FUN_00741300(0x4f,iVar3,&local_50);
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x20);
    }
    if (DAT_0097389c != 0) {
      iVar1 = DAT_0097389c;
      if (7 < DAT_0097389c) {
        iVar1 = 8;
      }
      uVar5 = FUN_00741610(0x4e,0,iVar1,DAT_009738a0);
      FUN_00744060(uVar5);
    }
  }
  return;
}

