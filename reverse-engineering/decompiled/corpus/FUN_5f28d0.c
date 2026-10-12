/* Ghidra analysis pseudocode, not original source.
 * ev_d2450bc109eaeb7c56e41eff2a553a3360ea1f4e9492b44c9e06060604e12c53
 * Entry: 0x5f28d0; label: FUN_005f28d0
 */

void FUN_005f28d0(undefined4 *param_1)

{
  float fVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float10 fVar5;
  float local_550;
  float local_54c;
  float local_548;
  float local_544;
  undefined8 local_540;
  float local_538;
  float local_530;
  float local_52c;
  float local_528;
  undefined4 local_524;
  float local_520;
  float local_51c;
  float local_518;
  float local_514;
  float local_510;
  float local_50c;
  float local_508;
  float local_504;
  undefined4 *local_500;
  float local_4fc;
  float local_4f8;
  float local_4f4;
  float local_4f0;
  float local_4ec;
  float local_4e8;
  float local_4e0;
  float local_4dc;
  float local_4d8;
  undefined4 local_4cc;
  undefined4 local_4c8;
  undefined4 local_4c4;
  float local_4c0;
  float local_4bc;
  float local_4b8;
  undefined4 local_4b4;
  undefined4 local_4b0;
  undefined4 local_4ac;
  undefined4 local_4a8;
  undefined4 local_4a4;
  undefined4 local_4a0;
  undefined4 local_49c;
  undefined4 local_498;
  undefined4 local_494;
  undefined4 local_490;
  undefined4 local_48c;
  undefined4 local_488;
  undefined4 local_484;
  undefined4 local_480;
  undefined4 local_47c;
  undefined4 local_478;
  undefined4 local_474;
  undefined4 local_470;
  undefined4 local_46c;
  undefined4 local_468;
  undefined4 local_464;
  undefined4 local_460;
  undefined4 local_45c;
  undefined4 local_458;
  undefined4 local_454;
  undefined4 local_450;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  undefined4 local_440;
  undefined4 local_43c;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_428;
  undefined4 local_424;
  undefined4 local_420;
  undefined4 local_41c;
  undefined4 local_418;
  undefined4 local_414;
  undefined4 local_410;
  undefined4 local_40c;
  undefined4 local_408;
  undefined4 local_404;
  undefined4 local_400;
  undefined4 local_3fc;
  undefined4 local_3f8;
  undefined4 local_3f4;
  undefined4 local_3f0;
  undefined4 local_3ec;
  undefined1 local_3e4 [4];
  undefined1 local_3e0 [4];
  float local_3dc [3];
  undefined1 local_3d0 [32];
  float local_3b0;
  float local_3ac;
  float local_3a8;
  undefined4 local_3a0;
  undefined4 local_39c;
  undefined4 local_398;
  float local_390;
  float local_38c;
  float local_388;
  float local_310;
  float local_30c;
  float local_308;
  undefined4 local_304;
  float local_300;
  float local_2fc;
  float local_2f8;
  undefined4 local_2f4;
  undefined1 local_2f0 [32];
  float local_2d0;
  float local_2cc;
  float local_2c8;
  undefined4 local_2b0 [16];
  undefined4 local_270 [16];
  undefined1 local_230 [64];
  undefined4 local_1f0 [16];
  undefined1 local_1b0 [64];
  undefined1 local_170 [64];
  float local_130 [40];
  undefined1 local_90 [64];
  undefined1 local_50 [76];
  
  local_500 = param_1 + 0x20;
  puVar3 = param_1;
  puVar4 = local_2b0;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  puVar3 = &DAT_0097ac80;
  puVar4 = local_1f0;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_005c1240(local_170,local_2b0,param_1 + 0x10);
  FUN_005b5e90(local_270,local_170);
  FUN_005b5a40(local_2f0,local_2b0);
  FUN_005b5a40(local_3d0,local_1f0);
  local_520 = local_2d0;
  local_51c = local_2cc;
  local_50c = local_3b0;
  local_518 = local_2c8;
  local_508 = local_3ac;
  local_504 = local_3a8;
  FUN_005e8c60(&local_520,&local_50c,&local_4b0,local_50);
  FUN_005e5a80(&local_390,param_1 + 0x48,8);
  local_310 = local_390 + *(float *)(in_ECX + 0x770) * 200.0;
  iVar2 = 0;
  local_30c = local_38c + *(float *)(in_ECX + 0x774) * 200.0;
  local_308 = local_388 + *(float *)(in_ECX + 0x778) * 200.0;
  local_304 = local_524;
  local_300 = local_390 - *(float *)(in_ECX + 0x770) * 200.0;
  local_2fc = local_38c - *(float *)(in_ECX + 0x774) * 200.0;
  local_2f8 = local_388 - *(float *)(in_ECX + 0x778) * 200.0;
  local_2f4 = local_524;
  local_540._0_4_ = 3.4028235e+38;
  local_540._4_4_ = 3.4028235e+38;
  local_538 = 3.4028235e+38;
  local_530 = -3.4028235e+38;
  local_52c = -3.4028235e+38;
  local_528 = -3.4028235e+38;
  do {
    local_470 = local_4b0;
    local_46c = local_4ac;
    local_468 = local_4a8;
    local_464 = local_4a4;
    local_460 = local_4a0;
    local_45c = local_49c;
    local_458 = local_498;
    local_454 = local_494;
    local_450 = local_490;
    local_44c = local_48c;
    local_448 = local_488;
    local_444 = local_484;
    local_440 = local_480;
    local_43c = local_47c;
    local_438 = local_478;
    local_434 = local_474;
    FUN_005b3110(&local_4c0,(int)&local_390 + iVar2,&local_470);
    *(float *)((int)local_130 + iVar2) = local_4c0;
    *(float *)((int)local_130 + iVar2 + 4) = local_4bc;
    *(float *)((int)local_130 + iVar2 + 8) = local_4b8;
    *(undefined4 *)((int)local_130 + iVar2 + 0xc) = local_4b4;
    if (local_538 <= local_4b8) {
      local_548 = local_538;
    }
    else {
      local_548 = local_4b8;
    }
    if (local_540._4_4_ <= local_4bc) {
      local_544 = local_540._4_4_;
    }
    else {
      local_544 = local_4bc;
    }
    if ((float)local_540 <= local_4c0) {
      local_550 = (float)local_540;
    }
    else {
      local_550 = local_4c0;
    }
    local_4f0 = local_550;
    local_4ec = local_544;
    local_4e8 = local_548;
    local_540._0_4_ = local_550;
    local_540._4_4_ = local_544;
    local_538 = local_548;
    local_54c = local_528;
    if (local_528 < local_4b8) {
      local_54c = local_4b8;
    }
    local_550 = local_52c;
    if (local_52c < local_4bc) {
      local_550 = local_4bc;
    }
    if (local_530 < local_4c0) {
      local_530 = local_4c0;
    }
    iVar2 = iVar2 + 0x10;
    local_52c = local_550;
    local_528 = local_54c;
    local_4e0 = local_530;
    local_4dc = local_550;
    local_4d8 = local_54c;
  } while (iVar2 < 0xa0);
  FUN_005bfe80(&DAT_00978440,local_3e4,local_3e0,&local_514,&local_510);
  local_510 = local_54c - local_548;
  local_540 = (double)local_510;
  local_54c = ABS(local_504 * local_518 + local_520 * local_50c + local_508 * local_51c);
  fVar5 = (float10)FUN_005c0240(local_514 * local_510);
  fVar1 = ((float)param_1[0x44] * (float)(fVar5 + (float10)local_514)) / (1.0 - local_54c);
  local_4cc = local_3a0;
  local_4c8 = local_39c;
  local_4c4 = local_398;
  FUN_005b3110(local_3dc,&local_4cc,&local_4b0);
  local_51c = (local_550 + local_544) * 0.5;
  local_518 = local_548 - fVar1;
  local_4fc = -local_3dc[0];
  local_4f8 = -local_51c;
  local_4f4 = -local_518;
  FUN_005c73d0(&local_4fc,fVar1,&local_548,&local_54c,&local_550,&local_544);
  FUN_005b4500(local_90,&local_4fc);
  FUN_005b7890(local_1b0,local_548,local_54c,local_550,local_544,fVar1,(float)local_540 + fVar1);
  local_428 = 0x3f800000;
  local_424 = 0;
  local_420 = 0;
  local_41c = 0;
  local_418 = 0;
  local_414 = 0;
  local_410 = 0xbf800000;
  local_40c = 0;
  local_408 = 0;
  local_400 = 0;
  local_3fc = 0;
  local_3f8 = 0;
  local_3f4 = 0;
  local_3f0 = 0;
  local_404 = 0x3f800000;
  local_3ec = 0x3f800000;
  FUN_005c1240(&local_470,&local_4b0,local_90);
  FUN_005c1240(local_230,&local_470,local_1b0);
  FUN_005c1240(local_270,local_230,&local_428);
  puVar3 = local_270;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *local_500 = *puVar3;
    puVar3 = puVar3 + 1;
    local_500 = local_500 + 1;
  }
  return;
}

