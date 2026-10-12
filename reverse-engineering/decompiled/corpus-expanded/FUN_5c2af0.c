/* Ghidra pseudocode, not original source.
 * ev_dfa41b6c39560a6d4e303a9a42849e633890ea31aa955743b15917c3077a3c9c
 * Entry: 0x5c2af0; label: FUN_005c2af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005c2af0(int param_1)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  float local_118;
  float local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined1 local_c8 [4];
  undefined1 local_c4 [4];
  undefined1 local_c0 [64];
  undefined1 local_80 [64];
  undefined1 local_40 [64];
  
  FUN_005c2760();
  if (*(char *)(in_ECX + 0x88) != '\0') {
    FUN_005bfe80(&DAT_0280d820,local_c8,local_c4,&local_120,&local_11c);
    local_11c = local_11c / (local_11c - local_120);
    fVar1 = *(float *)(in_ECX + 0x70) * *(float *)(in_ECX + 0x74);
    local_124 = *(float *)(in_ECX + 0x78) * fVar1;
    fVar2 = *(float *)(in_ECX + 0x78) - *(float *)(in_ECX + 0x74);
    local_128 = local_11c * local_120 * fVar2;
    local_118 = local_124 / local_128;
    local_114 = fVar1 / fVar2 - (local_124 * local_11c) / local_128;
    local_110 = *(undefined4 *)(in_ECX + 0x7c);
    local_10c = 0;
    FUN_006e5750(0x83,&local_118,1);
  }
  if (*(char *)(in_ECX + 0x8a) != '\0') {
    local_108 = 0x3f000000;
    local_104 = 0;
    local_100 = 0;
    local_fc = 0;
    local_f8 = 0;
    local_f4 = 0xbf000000;
    local_f0 = 0;
    local_ec = 0;
    local_e8 = 0;
    local_e4 = 0;
    local_e0 = 0x3f800000;
    local_cc = 0x3f800000;
    local_dc = 0;
    local_d0 = 0;
    local_d8 = 0x3f000000;
    local_d4 = 0x3f000000;
    FUN_005b5e90(local_40,&local_108);
    FUN_005b5e90(local_80,in_ECX + 0x90);
    FUN_005c1240(local_c0,local_40,local_80);
    FUN_005c1240(local_c0,local_c0,in_ECX + 0xd0);
    FUN_005c1240(local_c0,local_c0,&local_108);
    FUN_005b59a0(local_c0,local_c0);
    FUN_006e52e0(0x84,local_c0,4);
  }
  if ((*(char *)(in_ECX + 0x88) != '\0') || (*(char *)(in_ECX + 0x8a) != '\0')) {
    FUN_005f7c60(*(undefined4 *)(in_ECX + 0x54),0,&local_128,&local_124);
    FUN_005f7d00(param_1,2,2,0);
    if ((param_1 != 0) &&
       ((piVar3 = (int *)FUN_005f8460(param_1), DAT_0097f9c8 != *piVar3 ||
        (DAT_0097f9cc != piVar3[1])))) {
      uVar4 = FUN_005f8460(param_1);
      FUN_005fa540(2,uVar4);
    }
    FUN_005f8550(param_1,2);
    FUN_00605b60(*(undefined4 *)(in_ECX + 0x58),0,*(undefined4 *)(in_ECX + 0x54),0);
    FUN_005f8bf0(*(undefined4 *)(in_ECX + 0x58));
    FUN_005fa2f0(0,0,local_128,local_124);
    FUN_005fb550();
    FUN_005f8bb0(1);
    if (0 < *(int *)(in_ECX + 0x80)) {
      FUN_0060a830(*(undefined4 *)(in_ECX + 0x54),0,*(undefined4 *)(in_ECX + 0x54),1,
                   *(int *)(in_ECX + 0x80),1,1,_DAT_0080bec0,*(undefined4 *)(in_ECX + 0x48));
    }
  }
  return;
}

