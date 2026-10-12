/* Ghidra pseudocode, not original source.
 * ev_ba3680c91cc7668ea4367646649a520903a061e5f40eaeec700e4023a7d0b71b
 * Entry: 0x413510; label: FUN_00413510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00413510(float *param_1,float *param_2,undefined4 param_3,int param_4)

{
  float *pfVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int extraout_EDX;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  puVar4 = (undefined4 *)FUN_004115f0();
  if (puVar4 != (undefined4 *)0x0) {
    puVar4[0x19a] = 1;
    puVar4[0x19d] = 0;
    FUN_0040e870();
    puVar7 = (undefined4 *)(PTR_DAT_008021b4 + 0xb8);
    puVar8 = puVar4;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    puVar4[0xc] = *param_1;
    puVar4[0xd] = param_1[1];
    puVar4[0xe] = param_1[2];
    puVar4[0xf] = param_1[3];
    uVar3 = _DAT_007f120c;
    if (param_4 == extraout_EDX) {
      puVar4[0x19b] = 1;
    }
    else {
      puVar4[0x19b] = extraout_EDX;
      FUN_005b5060(puVar4,0x8000);
      uVar3 = _DAT_007f12fc;
    }
    puVar4[0x19f] = uVar3;
    pfVar1 = (float *)(puVar4 + 0x18c);
    *pfVar1 = *param_2 - *param_1;
    puVar4[0x18d] = param_2[1] - param_1[1];
    puVar4[0x18e] = param_2[2] - param_1[2];
    FUN_005b3b30(pfVar1,pfVar1);
    puVar4[399] = 0x3f800000;
    fVar2 = (float)puVar4[0x19f];
    *pfVar1 = fVar2 * *pfVar1;
    puVar4[0x18d] = (float)puVar4[0x18d] * fVar2;
    puVar4[0x18e] = fVar2 * (float)puVar4[0x18e];
    puVar4[0x19e] = param_3;
    local_20 = 0xc0a00000;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    uVar5 = FUN_0054fa60();
    uVar5 = uVar5 & 0xffff;
    iVar6 = FUN_0054fa60();
    puVar7 = puVar4 + 0x54;
    local_28 = 5;
    do {
      FUN_005b3690(puVar7 + -0x28,&local_20,(int)(short)uVar5);
      uVar5 = uVar5 + (iVar6 / 0x15 + 0x2666U & 0xffff);
      puVar7[-8] = 0x40000000;
      *puVar7 = 1;
      puVar7[-0x10] = puVar4;
      puVar7[-1] = 1;
      puVar7[2] = 0;
      puVar7[-0xf] = 0;
      *(undefined2 *)((int)puVar7 + -0x12) = 0x36;
      *(undefined2 *)(puVar7 + -5) = 1;
      puVar7 = puVar7 + 0x4c;
      local_28 = local_28 + -1;
    } while (local_28 != 0);
  }
  return;
}

