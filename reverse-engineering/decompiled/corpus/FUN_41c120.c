/* Ghidra analysis pseudocode, not original source.
 * ev_89a904a8103c3776e41058e159de7e620834e65a686002d8c26783b6fdb015b0
 * Entry: 0x41c120; label: FUN_0041c120
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041c120(undefined4 *param_1,int param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  ushort uVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  byte bVar8;
  uint uVar9;
  undefined2 uVar10;
  int iVar11;
  undefined4 *puVar12;
  float local_c [3];
  
  iVar7 = (int)param_1;
  if (param_1 != (undefined4 *)0x0) {
    FUN_00498a40(param_1);
    FUN_004b6b80(param_1);
    if (param_2 != 0) {
      FUN_0041b0a0(param_1);
      FUN_0041af70(param_1);
      FUN_0055e4a0(param_1,1);
      FUN_0055e4e0((int)param_1 + 0x6c4);
      uVar3 = *(undefined1 *)(*(int *)(*(int *)((int)param_1 + 0x54) + 0x24) + 0xf4);
      *(undefined1 *)((int)param_1 + 0x107e) = uVar3;
      *(undefined1 *)((int)param_1 + 0x107f) = uVar3;
      *(undefined1 *)((int)param_1 + 0xe38) =
           *(undefined1 *)(*(int *)(*(int *)((int)param_1 + 0x54) + 0x24) + 0xf5);
      *(undefined1 *)((int)param_1 + 0xe39) = 4;
      iVar11 = (uint)*(byte *)((int)param_1 + 0x400) * 0xa4 + *(int *)(param_2 + 0x18);
      *(undefined1 *)((int)param_1 + 0x378) = *(undefined1 *)(iVar11 + 0x4c);
      if ((*(byte *)(iVar11 + 0x48) & 1) == 0) {
        *(uint *)((int)param_1 + 0x4b0) = *(uint *)((int)param_1 + 0x4b0) & 0xffffff7f;
      }
      else {
        *(uint *)((int)param_1 + 0x4b0) = *(uint *)((int)param_1 + 0x4b0) | 0x80;
      }
      *(uint *)((int)param_1 + 0x4b0) = *(uint *)((int)param_1 + 0x4b0) & 0xfffbffff;
      *(undefined4 *)((int)param_1 + 0x230) = *(undefined4 *)(iVar11 + 0x94);
      *(undefined4 *)((int)param_1 + 0x234) = *(undefined4 *)(iVar11 + 0x98);
      *(undefined4 *)((int)param_1 + 0x238) = *(undefined4 *)(iVar11 + 0x9c);
      *(undefined4 *)((int)param_1 + 0x23c) = *(undefined4 *)(iVar11 + 0xa0);
      local_c[0] = (float)((*(byte *)((int)param_1 + 0x411) + 1) / 2) * *(float *)(iVar11 + 0x5c);
      if ((*(byte *)((int)param_1 + 0x411) & 1) != 0) {
        local_c[0] = -local_c[0];
      }
      local_c[1] = 0.0;
      local_c[2] = (float)*(byte *)((int)param_1 + 0x412) * -*(float *)(iVar11 + 0x60);
      if ((*(int *)((int)param_1 + 0x4c4) == 0) || (*(int *)((int)param_1 + 0x478) == 0)) {
        uVar9 = *(uint *)(iVar11 + 0x2c);
        FUN_005b3620(local_c,local_c,uVar9);
        FUN_005b37d0((int)param_1 + 0x5c,local_c,iVar11 + 0x20);
        param_1 = (undefined4 *)(iVar11 + 0x30);
      }
      else {
        uVar9 = *(uint *)(*(int *)((int)param_1 + 0x478) + 0x1c);
        FUN_005b3620(local_c,local_c,uVar9);
        FUN_005b37d0((int)param_1 + 0x5c,local_c,*(int *)((int)param_1 + 0x478) + 0x10);
        iVar5 = *(int *)((int)param_1 + 0x478);
        *(undefined4 *)((int)param_1 + 0x478) = 0;
        param_1 = (undefined4 *)(iVar5 + 0x20);
      }
      puVar12 = (undefined4 *)(iVar7 + 0x5c);
      *(undefined4 *)(iVar7 + 0x80) = *puVar12;
      *(undefined4 *)(iVar7 + 0x84) = *(undefined4 *)(iVar7 + 0x60);
      *(undefined4 *)(iVar7 + 0x88) = *(undefined4 *)(iVar7 + 100);
      *(undefined4 *)(iVar7 + 0x98) = *puVar12;
      _DAT_0093d620 = *(undefined4 *)(iVar7 + 0x80);
      *(undefined4 *)(iVar7 + 0x9c) = *(undefined4 *)(iVar7 + 0x60);
      *(undefined4 *)(iVar7 + 0xa0) = *(undefined4 *)(iVar7 + 100);
      DAT_0093d624 = *(undefined4 *)(iVar7 + 0x84);
      DAT_0093d628 = *(undefined4 *)(iVar7 + 0x88);
      *(undefined4 *)(iVar7 + 0x8c) = *(undefined4 *)(iVar7 + 0x80);
      *(undefined4 *)(iVar7 + 0x90) = *(undefined4 *)(iVar7 + 0x84);
      *(undefined4 *)(iVar7 + 0x94) = *(undefined4 *)(iVar7 + 0x88);
      *(undefined4 *)(iVar7 + 0xdf8) = DAT_0093b0cc;
      *(undefined4 *)(iVar7 + 0xdfc) = DAT_0093b0d0;
      uVar6 = DAT_0093b0d4;
      *(undefined4 *)(iVar7 + 0xe00) = DAT_0093b0d4;
      *(undefined4 *)(iVar7 + 0x68) = *(undefined4 *)(iVar7 + 0xdf8);
      *(undefined4 *)(iVar7 + 0x6c) = *(undefined4 *)(iVar7 + 0xdfc);
      *(undefined4 *)(iVar7 + 0x70) = uVar6;
      FUN_005728a0(iVar7);
      FUN_00572660(iVar7,0);
      uVar10 = (undefined2)uVar9;
      *(undefined2 *)(iVar7 + 0x27a) = uVar10;
      *(undefined2 *)(iVar7 + 0x58) = uVar10;
      *(undefined2 *)(iVar7 + 0x5a) = uVar10;
      FUN_005b3710(iVar7 + 0xf30,0x3f800000,uVar9 & 0xffff);
      iVar5 = iVar7 + 0x2c8;
      FUN_0051a7c0(iVar5,*param_1);
      FUN_0051b890(iVar5,puVar12,param_1[1],*(undefined1 *)(param_1 + 2));
      *(undefined1 *)(iVar7 + 0x28b) = 0;
      FUN_00514640(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar5,iVar5,iVar11,iVar11 + 0x10,0,1,0
                   ,0);
      *(undefined2 *)(iVar7 + 0x3ec) = 0xffff;
      *(undefined1 *)(iVar7 + 0x404) = 0xff;
      *(undefined1 *)(iVar7 + 0x405) = 0;
      FUN_0052f800(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar7,iVar5,0xff,
                   (int)*(char *)(iVar7 + 0x281));
      iVar11 = iVar7 + 8;
      FUN_0062e650(iVar11,1);
      FUN_0062e6c0(*(undefined4 *)(iVar7 + 0x50),iVar11);
      *(undefined4 *)(iVar7 + 0x3d8) = 0;
      *(undefined4 *)(iVar7 + 0x1090) = 0;
      *(uint *)(iVar7 + 0x4b0) = *(uint *)(iVar7 + 0x4b0) & 0xfeffffff;
      *(undefined4 *)(iVar7 + 0x3cc) = *puVar12;
      *(undefined4 *)(iVar7 + 0x3d0) = *(undefined4 *)(iVar7 + 0x60);
      *(undefined4 *)(iVar7 + 0x3d4) = *(undefined4 *)(iVar7 + 100);
      *(undefined4 *)(iVar7 + 0x44c) = 0;
      *(undefined1 *)(iVar7 + 0x1086) = 0;
      *(undefined1 *)(iVar7 + 0x1087) = 0;
      FUN_0055d6a0(iVar7,1,1,0xffffffff,*(undefined4 *)(PTR_DAT_00802c54 + 0x13c));
      iVar5 = *(int *)(iVar7 + 0x40c);
      *(uint *)(iVar7 + 0x1fc) = *(uint *)(iVar7 + 0x1fc) | 0x1000;
      *(int *)(iVar7 + 0x4c4) = *(int *)(iVar7 + 0x4c4) + 1;
      *(undefined1 *)(iVar7 + 0x406) = 2;
      if (iVar5 != 0) {
        uVar9 = __allshl();
        puVar1 = (uint *)(iVar5 + 0x4c);
        *puVar1 = *puVar1 | uVar9;
        puVar2 = (undefined4 *)
                 ((uint)*(byte *)(iVar7 + 0x412) * 0x34 + 0x54 + *(int *)(iVar7 + 0x40c));
        bVar8 = __allshl();
        *(byte *)((int)puVar2 + 0x2d) = *(byte *)((int)puVar2 + 0x2d) | bVar8;
        if (*(char *)(iVar7 + 0x411) == '\0') {
          puVar2[6] = *puVar12;
          puVar2[7] = *(undefined4 *)(iVar7 + 0x60);
          puVar2[8] = *(undefined4 *)(iVar7 + 100);
          *puVar2 = *(undefined4 *)(iVar7 + 0x420);
          puVar2[1] = *(undefined4 *)(iVar7 + 0x424);
          puVar2[2] = *(undefined4 *)(iVar7 + 0x428);
          puVar2[3] = *(undefined4 *)(iVar7 + 0x42c);
          puVar2[4] = *(undefined4 *)(iVar7 + 0x430);
          puVar2[5] = *(undefined4 *)(iVar7 + 0x434);
          uVar4 = *(ushort *)(iVar7 + 0x27a);
          puVar2[0xc] = puVar2[0xc] & 0xfffffffd;
          puVar2[9] = (uint)uVar4;
          puVar2[10] = 0;
        }
      }
      *(undefined4 *)(iVar7 + 0x1b4) = *puVar12;
      *(undefined4 *)(iVar7 + 0x10bc) = *puVar12;
      *(undefined4 *)(iVar7 + 0x1b8) = *(undefined4 *)(iVar7 + 0x60);
      *(undefined4 *)(iVar7 + 0x10c0) = *(undefined4 *)(iVar7 + 0x60);
      *(undefined4 *)(iVar7 + 0x1bc) = *(undefined4 *)(iVar7 + 100);
      *(undefined4 *)(iVar7 + 0x10c4) = *(undefined4 *)(iVar7 + 100);
      if (((*(uint *)(*(int *)(iVar7 + 0x54) + 4) & 0x20000000) != 0) &&
         (*(int *)(*(int *)(*(int *)(iVar7 + 0x50) + 0xc) + 0x104) != 0)) {
        *(undefined4 *)(iVar7 + 0x77c) = 0x4e6e6b28;
        *(undefined1 *)(iVar7 + 0x7b5) = 0x17;
        *(undefined2 *)(iVar7 + 0x7aa) = 0x41;
        FUN_0062e650(iVar11,0x41);
      }
    }
  }
  return;
}

