/* Ghidra pseudocode, not original source.
 * ev_f56492005d3db2572965d416e35be25a43fb24333701b400d47d471ee6ec09ab
 * Entry: 0x470940; label: FUN_00470940
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00470940(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  float10 fVar7;
  float10 extraout_ST0;
  float10 extraout_ST1;
  undefined4 *local_41d8;
  undefined4 local_41d4;
  float local_41d0;
  undefined4 local_41cc;
  float local_41c8;
  undefined4 local_41c4 [12];
  undefined4 local_4194;
  float local_4190;
  undefined4 local_418c;
  undefined1 local_4184 [64];
  undefined1 local_4144 [324];
  undefined1 local_4000 [16380];
  undefined4 uStack_4;
  
  uStack_4 = 0x47094a;
  iVar1 = *(int *)(param_1 + 0x46ec);
  local_41d8 = (undefined4 *)0x0;
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x4b0) == 0) {
      iVar3 = FUN_005cfd60(iVar1 + 0x4fc);
      if (iVar3 == 0) {
        return;
      }
    }
    else {
      if (((*(byte *)(iVar1 + 0x559) & 1) == 0) || (*(int *)(*(int *)(iVar1 + 0x4b0) + 0x14) == 0))
      {
        local_41d8 = (undefined4 *)(iVar1 + 0x48c);
      }
      else {
        local_41d8 = (undefined4 *)(iVar1 + 0x70);
      }
      FUN_00636010(local_4144,1);
      FUN_006371d0(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ab4),local_4144,local_41d8,0,0xffffffff,
                   0x3f800000);
      FUN_006363b0(local_4144);
    }
    puVar2 = (undefined4 *)FUN_005d0330(iVar1 + 0x4fc);
    iVar3 = *(int *)(param_1 + 0x128);
    puVar6 = local_41c4;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar6 = puVar6 + 1;
    }
    if (iVar3 == DAT_0087b178) {
      fVar7 = (float10)FUN_005bed80(PTR_DAT_008021b4 + 0x11c,&local_4194,0);
      local_41c8 = (float)fVar7;
      if (local_41c8 < 2.0) {
        iVar3 = FUN_006e6b90();
        local_4190 = (float)((extraout_ST1 -
                             ((float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] + extraout_ST1) *
                             extraout_ST0) * (float10)1.25 + (float10)local_4190);
      }
    }
    if (*(float *)(iVar1 + 0x540) != 2e+06) {
      if ((((*(byte *)(iVar1 + 0x559) & 0x10) != 0) && (DAT_00804934 != 0)) &&
         ((*(int *)(iVar1 + 0x4b0) == 0 ||
          (*(int *)(*(int *)(*(int *)(iVar1 + 0x4b0) + 4) + 0x19c) == 0)))) {
        local_41d4 = *(undefined4 *)(iVar1 + 0x48c);
        local_41d0 = *(float *)(iVar1 + 0x540) + 0.005;
        if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b224) {
          local_41d0 = local_41d0 + 0.005;
        }
        local_41cc = *(undefined4 *)(iVar1 + 0x494);
        iVar3 = FUN_005cfac0(iVar1 + 0x508);
        if (iVar3 == 0) {
          FUN_005fee80(&local_41d4,*(undefined4 *)(iVar1 + 0x538),0x80,
                       *(undefined2 *)(iVar1 + 0x548),0,*(undefined2 *)(iVar1 + 0x54a));
        }
        else {
          FUN_00470050();
          FUN_004700f0();
          FUN_005b4900(local_4184,&local_41d4);
          FUN_005f33b0(iVar1 + 0x508,local_4184);
        }
      }
      if (*(float *)(iVar1 + 0x54c) != 2e+06) {
        FUN_005505a0(local_41c4,*(undefined4 *)(iVar1 + 0x54c),
                     *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),local_4184);
      }
    }
    if (*(short **)(iVar1 + 0x4b0) == (short *)0x0) {
      if (*(float *)(iVar1 + 0x54c) != 2e+06) {
        FUN_005f33b0(iVar1 + 0x4fc,local_4184);
      }
    }
    else {
      *(byte *)(iVar1 + 0x559) = *(byte *)(iVar1 + 0x559) & 0xfe;
      PTR_FUN_0080fb94 = *(undefined **)(**(short **)(iVar1 + 0x4b0) * 0x120 + DAT_0093b284);
      if ((*(byte *)(iVar1 + 0x559) & 0x10) == 0) {
        *(undefined1 *)(*(int *)(*(int *)(iVar1 + 0x4b0) + 4) + 0x1a0) = 1;
        thunk_FUN_005d05b0();
      }
      else {
        *(undefined1 *)(*(int *)(*(int *)(iVar1 + 0x4b0) + 4) + 0x1a0) = 0;
        FUN_00596920(0);
      }
      if (*(float *)(iVar1 + 0x54c) == 2e+06) {
        puVar5 = (undefined1 *)0x0;
      }
      else {
        puVar5 = local_4184;
      }
      iVar3 = FUN_0062fbf0(*(short **)(iVar1 + 0x4b0),
                           **(short **)(iVar1 + 0x4b0) * 0x4c + DAT_0093b274,iVar1 + 0x4b4,
                           local_41c4,0,puVar5,0,iVar1 + 0x40,0,0xffff,0,0,DAT_0093b328,
                           _DAT_00925018,local_4000,0,*(undefined4 *)(PTR_DAT_00802c54 + 0x134));
      if (iVar3 != 0) {
        *(byte *)(iVar1 + 0x559) = *(byte *)(iVar1 + 0x559) | 1;
      }
      if ((*(byte *)(iVar1 + 0x559) & 0x10) != 0) {
        thunk_FUN_005d05b0();
      }
      *(undefined1 *)(*(int *)(*(int *)(iVar1 + 0x4b0) + 4) + 0x1a0) = 0;
    }
    if ((*(int *)(iVar1 + 0x52c) != 0) && (local_41d8 != (undefined4 *)0x0)) {
      puVar2 = (undefined4 *)(iVar1 + 0x440);
      puVar6 = local_41c4;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar6 = puVar6 + 1;
      }
      local_4194 = *local_41d8;
      local_418c = local_41d8[2];
      local_4190 = *(float *)(iVar1 + 0x544) + (float)local_41d8[1];
      FUN_005f33b0(*(int *)(*(int *)(iVar1 + 0x52c) + 0xa4) + 0x30,local_41c4);
      if ((*(float *)(iVar1 + 0x54c) != 2e+06) &&
         (iVar3 = FUN_00550490(local_41c4,2,*(undefined4 *)(iVar1 + 0x54c),
                               *(undefined4 *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xc0),local_4184
                              ), iVar3 != 0)) {
        FUN_005f33b0(*(int *)(*(int *)(iVar1 + 0x52c) + 0xa4) + 0x30,local_4184);
      }
    }
  }
  return;
}

