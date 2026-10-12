/* Ghidra pseudocode, not original source.
 * ev_77fef26266fe5967585df020e38eccd49263e70128ef006db684616fa6a4691c
 * Entry: 0x4857d0; label: FUN_004857d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004857d0(void)

{
  int iVar1;
  undefined4 uVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 **ppuVar7;
  float local_150;
  int local_14c;
  undefined4 local_148;
  float local_144;
  undefined4 local_140;
  int local_13c;
  undefined4 local_138;
  float local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 *local_120 [4];
  undefined4 local_110;
  undefined4 local_108;
  undefined4 local_104;
  float local_100;
  short local_fa;
  int local_f8;
  uint local_f4;
  undefined1 *local_e0;
  code *local_d8;
  char local_d4;
  undefined1 local_d2;
  undefined4 *local_d0 [7];
  undefined4 local_b4;
  undefined4 local_ac;
  undefined4 local_a4;
  undefined4 local_44;
  undefined *local_3c;
  
  local_150 = 0.0;
  local_12c = 0;
  _DAT_0087a260 = DAT_00805038;
  local_128 = _DAT_007fc310;
  _DAT_0087a264 = DAT_0080503c;
  local_124 = 0x3f800000;
  _DAT_0087a268 = DAT_00805040;
  _DAT_0087a284 = DAT_0080505c;
  _DAT_0087a288 = DAT_00805060;
  _DAT_0087a28c = DAT_00805064;
  _DAT_0087a26c = DAT_00805044;
  _DAT_0087a270 = DAT_00805048;
  _DAT_0087a274 = DAT_0080504c;
  _DAT_0087a290 = DAT_00805068;
  _DAT_0087a294 = DAT_0080506c;
  _DAT_0087a298 = DAT_00805070;
  _DAT_0087a278 = DAT_00805050;
  _DAT_0087a27c = DAT_00805054;
  _DAT_0087a280 = DAT_00805058;
  _DAT_0087a29c = DAT_00805074;
  _DAT_0087a2a0 = DAT_00805078;
  _DAT_0087a2a4 = DAT_0080507c;
  _DAT_0087a2a8 = DAT_00805080;
  _DAT_0087a2ac = DAT_00805084;
  _DAT_0087a2b0 = DAT_00805088;
  puVar5 = &DAT_0087a330;
  do {
    if (puVar5[0x11] != 0) {
      local_130 = 0;
      local_138 = 0;
      iVar1 = FUN_0054fa60();
      local_134 = (float)iVar1 * 1.5259022e-05 * 0.25 + 0.25;
      uVar2 = FUN_0054fa60();
      FUN_005b3690(&local_138,&local_138,uVar2);
      uVar2 = puVar5[0x10];
      puVar6 = &DAT_00810210;
      ppuVar7 = local_d0;
      for (iVar1 = 0x32; iVar1 != 0; iVar1 = iVar1 + -1) {
        *ppuVar7 = (undefined4 *)*puVar6;
        puVar6 = puVar6 + 1;
        ppuVar7 = ppuVar7 + 1;
      }
      local_b4 = 0;
      local_44 = _DAT_00925018;
      local_d0[2] = &local_138;
      local_3c = &DAT_0087a1e8;
      local_a4 = 0x480;
      local_d0[0] = puVar5;
      local_ac = uVar2;
      FUN_0064d270(local_d0);
      local_14c = 5;
      do {
        local_148 = 0;
        local_13c = FUN_0054fa60();
        local_144 = (float)local_13c * 1.5259022e-05 * 0.1;
        local_140 = 0x3f800000;
        uVar2 = FUN_0054fa60();
        FUN_005b3690(&local_148,&local_148,uVar2);
        puVar6 = &DAT_00802cd8;
        ppuVar7 = local_120;
        for (iVar1 = 0x14; iVar1 != 0; iVar1 = iVar1 + -1) {
          *ppuVar7 = (undefined4 *)*puVar6;
          puVar6 = puVar6 + 1;
          ppuVar7 = ppuVar7 + 1;
        }
        local_110 = 0x3f400000;
        local_120[1] = &local_148;
        iVar1 = FUN_0054fa60();
        local_d4 = (char)((int)(iVar1 + (iVar1 >> 0x1f & 0x7fffU)) >> 0xf);
        local_120[2] = &local_12c;
        local_12c = *(undefined4 *)(&DAT_0087b9ac + local_d4 * 4);
        local_110 = _DAT_007fc368;
        local_fa = DAT_007f8e78;
        local_f8 = DAT_007f8e78 * 0x10 + *(int *)(PTR_DAT_00802c54 + 0x2ac0);
        local_f4 = (uint)DAT_007f8e7a;
        local_104 = _DAT_008033a8;
        local_100 = local_150;
        local_108 = 0x112d;
        local_d2 = 1;
        local_d8 = FUN_0046af20;
        local_e0 = &LAB_0046af00;
        FUN_00560b60(local_120);
        if (local_150 == 0.0) {
          iVar4 = 1;
          iVar1 = 0;
          pbVar3 = &DAT_0087a65c;
          do {
            if ((&DAT_0087a6cc)[iVar1] != '\0') {
              if (*(float *)(pbVar3 + -4) < 0.0) {
                pbVar3[-0xffffffff00000004] = 0;
                pbVar3[-0xffffffff00000003] = 0;
                pbVar3[-0xffffffff00000002] = 0;
                pbVar3[-0xffffffff00000001] = 0;
              }
              if ((0 < iVar4) && (iVar4 = iVar4 + 1, (int)(uint)*pbVar3 < iVar4)) {
                *pbVar3 = (byte)iVar4;
              }
            }
            iVar1 = iVar1 + 1;
            pbVar3 = pbVar3 + 0x14;
          } while (iVar1 < 2);
          FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x38,&local_148);
        }
        local_14c = local_14c + -1;
        local_150 = local_150 + 0.1;
      } while (local_14c != 0);
    }
    puVar5 = puVar5 + 0x12;
  } while ((int)puVar5 < 0x87a600);
  FUN_00595720(0x3f800000);
  return;
}

