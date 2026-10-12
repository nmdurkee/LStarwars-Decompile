/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x49a5f0; label: FUN_0049a5f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049a5f0(int param_1)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float10 fVar6;
  int local_74;
  float local_70;
  undefined2 local_6c [2];
  undefined2 local_68 [2];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_4c [8];
  float local_44;
  undefined4 local_40 [12];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xefffffff;
  iVar2 = FUN_0056db40(param_1);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0xf1c) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0xf1c) = 0x3fa00000;
  }
  if ((*(short *)(param_1 + 0x1064) == DAT_007f191c) && ((*(uint *)(param_1 + 0xef4) & 0x200) != 0))
  {
    local_58 = 0x3f800000;
  }
  else {
    local_58 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x44);
  }
  *(undefined4 *)(param_1 + 0xf18) = 0;
  *(undefined4 *)(param_1 + 0xf20) = 0;
  if (*(char *)(param_1 + 0x7b5) == '+') {
    if (1.0 <= *(float *)(param_1 + 0xd98)) {
      *(undefined4 *)(param_1 + 0xf20) = 0;
      *(undefined4 *)(param_1 + 0xf18) = 0;
    }
    else {
      local_70 = (1.0 - *(float *)(param_1 + 0xd98)) * 0.0;
      *(float *)(param_1 + 0xf18) = local_70;
      *(float *)(param_1 + 0xf20) = local_70;
      if (*(char *)(param_1 + 0xe37) == '\x02') {
        local_70 = local_70 * 0.5;
        *(float *)(param_1 + 0xf18) = local_70;
        *(float *)(param_1 + 0xf20) = local_70;
      }
    }
    if (*(char *)(param_1 + 0xe37) == '\x02') {
      iVar2 = FUN_0054fa60(0);
      local_70 = (float)iVar2 * 1.5259022e-05 * 0.5;
      FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),local_70);
      iVar2 = *(int *)(*(int *)(*(int *)(PTR_DAT_00802c54 + 0x134) + 8) + 0x488);
      if ((iVar2 != -1) && (iVar3 = FUN_0062c350(0x42700000,_DAT_00925018), 0 < iVar3)) {
        local_64 = *(undefined4 *)(param_1 + 0x80);
        local_60 = *(undefined4 *)(param_1 + 0x220);
        local_5c = *(undefined4 *)(param_1 + 0x88);
        FUN_00684c90(iVar2,&local_64,iVar3,0,0);
      }
    }
  }
  pfVar1 = (float *)(param_1 + 0x68);
  fVar6 = (float10)FUN_0054fb40(*pfVar1,*(undefined4 *)(param_1 + 0xf18),local_58);
  *pfVar1 = (float)fVar6;
  fVar6 = (float10)FUN_0054fb40(*(undefined4 *)(param_1 + 0x70),*(undefined4 *)(param_1 + 0xf20),
                                local_58);
  *(float *)(param_1 + 0x70) = (float)fVar6;
  if ((*(int *)(PTR_DAT_00802c54 + 300) != 0) && (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af78))
  {
    FUN_004e25f0(param_1);
  }
  puVar4 = (undefined4 *)(param_1 + 0xb8);
  puVar5 = local_40;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  local_8 = 0;
  local_c = 0;
  local_10 = 0;
  *(undefined1 *)(param_1 + 0x107a) = 0;
  local_74 = FUN_005be2d0(*pfVar1,*(undefined4 *)(param_1 + 0x70));
  FUN_005b3620(local_4c,pfVar1,-local_74);
  FUN_00497f60();
  local_70 = (_DAT_00925018 * local_44) / *(float *)(param_1 + 0xac);
  FUN_006e6b90();
  FUN_00497e80();
  FUN_00497f60();
  FUN_005bf5e0(local_40,local_6c,&local_74,local_68);
  *(undefined2 *)(param_1 + 0x278) = local_6c[0];
  *(undefined2 *)(param_1 + 0x27a) = (undefined2)local_74;
  *(undefined2 *)(param_1 + 0x27c) = local_68[0];
  FUN_0056a5b0(PTR_DAT_00802c54,param_1);
  return;
}

