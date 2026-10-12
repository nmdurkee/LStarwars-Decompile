/* Ghidra pseudocode, not original source.
 * ev_8d7f18048ef2880fb529f575b466097bafe0da5dbea7c232731940988e33188f
 * Entry: 0x5985b0; label: FUN_005985b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005985b0(int param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float10 fVar8;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined4 local_40 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  uVar1 = (undefined1)DAT_00802878;
  *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffffffbf;
  *(undefined1 *)(param_1 + 0x7b5) = uVar1;
  *(undefined1 *)(param_1 + 0x7b8) = 0;
  *(int *)(param_1 + 0x798) = param_2;
  if (((param_3 == 0) && (DAT_00804c9c != -1)) &&
     (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + DAT_00804c9c * 4) != 0)) {
    *(undefined1 *)(param_1 + 0x7b3) = 0;
    iVar5 = (int)DAT_00804c9c;
    *(short *)(param_1 + 0x7aa) = DAT_00804c9c;
    fVar8 = (float10)FUN_0062e040((int)*(short *)(param_1 + 0x1064),iVar5,0,0,1);
    *(float *)(param_1 + 0x77c) = (float)fVar8;
    if ((float)fVar8 <= 0.0) {
      *(undefined4 *)(param_1 + 0x77c) = 0x3f000000;
    }
    uVar2 = FUN_005be2d0(*(float *)(param_2 + 0x4c) - *(float *)(param_1 + 0x80),
                         *(float *)(param_2 + 0x54) - *(float *)(param_1 + 0x88));
    *(undefined2 *)(param_1 + 0x5a) = uVar2;
  }
  else {
    *(undefined1 *)(param_1 + 0x7b3) = 2;
    uVar2 = DAT_00804ca0;
    *(undefined4 *)(param_1 + 0x77c) = 0;
    *(undefined2 *)(param_1 + 0x7aa) = uVar2;
    if (param_3 == 0) {
      FUN_00567800(param_2,0,7,0xffffffff,0,1);
    }
  }
  if (DAT_008051d0 == 0) {
    puVar6 = *(undefined4 **)(param_1 + 0x798);
    puVar7 = local_40;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    FUN_005b4f70(local_40,0x8000 - (uint)*(ushort *)(param_1 + 0x5a));
    *(undefined4 *)(param_1 + 0x778) = 0x3f000000;
    *(undefined4 *)(param_1 + 0x748) = local_40[0];
    *(undefined4 *)(param_1 + 0x74c) = local_40[1];
    *(undefined4 *)(param_1 + 0x750) = local_40[2];
    *(undefined4 *)(param_1 + 0x754) = local_30;
    *(undefined4 *)(param_1 + 0x758) = local_2c;
    *(undefined4 *)(param_1 + 0x75c) = local_28;
    *(undefined4 *)(param_1 + 0x760) = local_20;
    *(undefined4 *)(param_1 + 0x764) = local_1c;
    *(undefined4 *)(param_1 + 0x768) = local_18;
    return;
  }
  FUN_005d0130(*(int *)(*(int *)(param_1 + 0x798) + 0xa4) + 0x30,&local_58,&local_4c);
  sVar3 = FUN_005be2d0(*(undefined4 *)(*(int *)(param_1 + 0x798) + 0x20),
                       *(undefined4 *)(*(int *)(param_1 + 0x798) + 0x28));
  uVar4 = FUN_00550040(*(undefined2 *)(param_1 + 0x5a),sVar3);
  *(undefined4 *)(param_1 + 0x748) = 0;
  iVar5 = (uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f);
  *(float *)(param_1 + 0x74c) = -local_54;
  if (iVar5 < 0x2000) {
    *(undefined2 *)(param_1 + 0x7a6) = 0;
  }
  else {
    if (0x6000 < iVar5) {
      *(undefined2 *)(param_1 + 0x7a6) = 0x8000;
      goto LAB_0059879c;
    }
    if ((int)uVar4 < 0) {
      *(undefined2 *)(param_1 + 0x7a6) = 0xc000;
      local_44 = local_4c;
      goto LAB_0059879c;
    }
    *(undefined2 *)(param_1 + 0x7a6) = 0x4000;
    local_50 = local_58;
  }
  local_44 = -local_50;
LAB_0059879c:
  *(float *)(param_1 + 0x750) = local_44;
  *(undefined4 *)(param_1 + 0x754) = 0;
  *(short *)(param_1 + 0x5a) = sVar3 - *(short *)(param_1 + 0x7a6);
  *(float *)(param_1 + 0x758) = (local_48 - local_54) * 0.5 + -local_54;
  *(undefined4 *)(param_1 + 0x75c) = *(undefined4 *)(param_1 + 0x750);
  *(undefined4 *)(param_1 + 0x778) = 0x3f000000;
  return;
}

