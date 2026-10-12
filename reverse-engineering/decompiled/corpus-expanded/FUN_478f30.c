/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x478f30; label: FUN_00478f30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00478f30(float param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  double dVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  undefined *puVar7;
  undefined4 uVar8;
  int iVar9;
  undefined2 in_FPUControlWord;
  float local_90;
  double local_8c;
  char local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_90;
  local_8c = (double)(param_1 * 128.0);
  iVar9 = param_2 * 0x9c + DAT_00951354;
  uVar4 = FUN_006e6b90();
  if ((DAT_0087b02c == 0) || (*(byte *)(DAT_0087b02c + 0x7c) != param_2)) {
    FUN_0050d910(*(undefined4 *)(DAT_00926c20 + *(short *)(iVar9 + 0x78) * 4),0,_DAT_007f92ec,
                 0x3f800000,_DAT_007f92f0,_DAT_007f92f0,_DAT_007f92f0,0,DAT_007f92f4,DAT_007f92f8,
                 DAT_00879b1c,0x3fd9999a,1,0,0,uVar4);
    uVar1 = *(ushort *)(iVar9 + 0x7a);
    if ((uVar1 & 0x10) == 0) {
      if ((&DAT_0086e0f5)[param_2 * 0xc] != '\0') {
        if ((uVar1 & 0x800) == 0) {
          local_90 = _DAT_007f92ec + 0.05;
          FUN_00478d20(0xd3,0,local_90,param_1,0xffffffff,0xffffffff);
          __security_check_cookie(local_4 ^ (uint)&local_90);
          return;
        }
        goto LAB_0047902e;
      }
    }
    else {
      iVar2 = param_2 * 0xc;
      if (((&DAT_0086e0f5)[iVar2] == '\0') || ((uVar1 & 4) != 0)) {
        if ((*(char *)(iVar9 + 0x87) != -1) && (((byte)uVar1 & 0x14) == 0x10)) {
          _sprintf(local_84,"%s %i",*(undefined4 *)(DAT_00926c20 + DAT_00880690 * 4),
                   *(char *)(iVar9 + 0x87) + 1);
          FUN_0050d910(local_84,0,_DAT_007f92e4,0x3f800000,_DAT_007f92e8,_DAT_007f92e8,_DAT_007f92e8
                       ,0,DAT_007f92f4,DAT_007f92f8,DAT_00879b1c,0x3fd9999a,1,0,0,uVar4);
        }
      }
      else {
        FUN_0059b840((int)*(char *)(iVar9 + 0x86),param_2,&DAT_0086e0f4);
        if (DAT_0093b314 == 0) {
          iVar5 = FUN_006e6b90(0x3f800000,0x3f800000,0);
          local_90 = (_DAT_00805270 + _DAT_007f92e4) - _DAT_00805278;
          FUN_004b86f0(*(undefined4 *)(PTR_DAT_007fa200 + 4),local_90,100,100,
                       (&DAT_029899a0)[iVar5 >> 1 & 0x7fff]);
          if (((&DAT_0086e0f6)[iVar2] != '\0') ||
             (puVar7 = &DAT_00759770, (&DAT_0086e0f7)[iVar2] != '\0')) {
            puVar7 = &DAT_00758804;
          }
          FUN_004f1f10(local_84,puVar7);
          local_90 = (float)CONCAT22(local_90._2_2_,in_FPUControlWord);
          dVar3 = ROUND(local_8c);
          local_8c = (double)CONCAT44((int)((ulonglong)local_8c >> 0x20),(int)dVar3);
          FUN_0050c780(local_84,*(undefined4 *)(PTR_DAT_007fa200 + 4),_DAT_007f92e4,0x3f800000,
                       _DAT_00805274,_DAT_00805274,_DAT_00805274,0,0xff,0,0x7f,(int)dVar3 & 0xff);
        }
        else {
          iVar5 = FUN_006e6b90();
          uVar6 = iVar5 >> 1 & 0x7fff;
          local_90 = (_DAT_00805270 + _DAT_007f92e4) - _DAT_00805278;
          FUN_004b86f0(*(undefined4 *)(PTR_DAT_007fa200 + 4),local_90,100,100,(&DAT_029899a0)[uVar6]
                       ,0x3f800000,0x3f800000,0);
          puVar7 = &DAT_00758804;
          if ((&DAT_0086e0f6)[iVar2] == '\0') {
            puVar7 = &DAT_00759770;
          }
          FUN_004f1f10(local_84,puVar7);
          FUN_0050c780(local_84,*(undefined4 *)(PTR_DAT_007fa200 + 4),_DAT_007f92e4,0x3f800000,
                       _DAT_00805274,_DAT_00805274,_DAT_00805274,0,0xff,0,0x7f,uVar4);
          uVar8 = FUN_006e6b90();
          local_90 = _DAT_007f9310 + _DAT_007f92e4;
          FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_00880884 * 4),
                       *(undefined4 *)(PTR_DAT_007fa200 + 4),local_90,0x3f800000,_DAT_007f9314,
                       _DAT_007f9314,_DAT_007f9314,0,DAT_007f931c,DAT_007f9320,DAT_007f9324,
                       _DAT_007f9318,1,0,0,uVar8);
          local_90 = (_DAT_00805270 + _DAT_007f92e4) - _DAT_00805278;
          FUN_004b86f0(*(undefined4 *)(PTR_DAT_007fa200 + 0x10),local_90,100,100,
                       (&DAT_029899a0)[uVar6],0x3f800000,0x3f800000,0);
          puVar7 = &DAT_00758804;
          if ((&DAT_0086e0f7)[iVar2] == '\0') {
            puVar7 = &DAT_00759770;
          }
          FUN_004f1f10(local_84,puVar7);
          FUN_0050c780(local_84,*(undefined4 *)(PTR_DAT_007fa200 + 0x10),_DAT_007f92e4,0x3f800000,
                       _DAT_00805274,_DAT_00805274,_DAT_00805274,0,0xff,0,0x7f,uVar4);
          uVar4 = FUN_006e6b90();
          local_90 = _DAT_007f9310 + _DAT_007f92e4;
          FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_00880888 * 4),
                       *(undefined4 *)(PTR_DAT_007fa200 + 0x10),local_90,0x3f800000,_DAT_007f9314,
                       _DAT_007f9314,_DAT_007f9314,0,DAT_007f931c,DAT_007f9320,DAT_007f9324,
                       _DAT_007f9318,1,0,0,uVar4);
        }
        if ((*(byte *)(iVar9 + 0x7a) & 0x10) != 0) {
          FUN_00478b00(*(undefined4 *)PTR_DAT_007fa200,_DAT_007f92e4,10,param_1);
        }
        FUN_00478d20(0xd2,*(undefined4 *)(PTR_DAT_007fa200 + 8),_DAT_007f92e4,param_1,
                     (&DAT_0086e0fa)[iVar2],1);
        FUN_00478d20(0xd3,*(undefined4 *)(PTR_DAT_007fa200 + 0xc),_DAT_007f92e4,param_1,DAT_00956258
                     ,DAT_0095625c);
        DAT_00879b70 = 1;
        FUN_00478b00(*(undefined4 *)(PTR_DAT_007fa200 + 0x14),_DAT_007f92e4,DAT_00956288,param_1);
      }
    }
  }
  else {
    FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_008807c8 * 4),0,_DAT_007f92ec,0x3f800000,
                 _DAT_007f92f0,_DAT_007f92f0,_DAT_007f92f0,0,DAT_007f92f4,DAT_007f92f8,DAT_00879b1c,
                 0x3fd9999a,1,0,0,uVar4);
    if (DAT_0086e4e5 != '\0') {
LAB_0047902e:
      local_90 = _DAT_007f92ec - 0.05;
      FUN_00478d20(0xfb,0,local_90,param_1,0xffffffff,0xffffffff);
      __security_check_cookie(local_4 ^ (uint)&local_90);
      return;
    }
  }
  __security_check_cookie(local_4 ^ (uint)&local_90);
  return;
}

