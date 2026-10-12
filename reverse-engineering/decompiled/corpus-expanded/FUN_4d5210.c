/* Ghidra pseudocode, not original source.
 * ev_49baf35693289c9b209f5eaac5bb5c67719489504b9157070dca4e7dc617b8b0
 * Entry: 0x4d5210; label: FUN_004d5210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d5210(undefined4 param_1,float param_2,undefined4 param_3)

{
  undefined4 uVar1;
  float10 fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  undefined1 local_4c [12];
  undefined1 local_40 [64];
  
  FUN_005b3800(&local_64,param_1,DAT_00925164 + 0x30);
  fVar2 = (float10)FUN_005c0240(local_5c * local_5c + local_64 * local_64 + local_60 * local_60);
  fVar3 = (float)fVar2;
  fVar5 = fVar3;
  FUN_005b3b30(&local_64,&local_64);
  fVar4 = param_2;
  if ((fVar3 - 0.2 <= param_2) && (fVar4 = fVar3 - 0.2, fVar3 < 0.2)) {
    fVar4 = 0.0;
  }
  FUN_005b3830(&local_64,&local_64,fVar4);
  FUN_005b3800(local_4c,param_1,&local_64);
  if (fVar4 != 0.0) {
    param_2 = ((fVar5 - fVar4) / fVar5) * param_2;
  }
  local_58 = param_2;
  local_54 = param_2;
  local_50 = param_2;
  if (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x49e) != '\0') {
    FUN_005b45a0(local_40,&local_58);
    fVar2 = (float10)FUN_005b7d30(_DAT_0092505c,0x40e9eb85);
    iVar6 = (int)ROUND((fVar2 / (float10)7.309999942779541) * (float10)65536.0);
    uVar1 = FUN_004d4ce0();
    FUN_005b5700(uVar1,uVar1,PTR_DAT_008021b4 + 0xb8);
    FUN_005b4900(local_40,local_4c);
    FUN_005ff7a0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x490,local_40,param_3,fVar4,iVar6);
  }
  if (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x4ae) != '\0') {
    FUN_005b45a0(local_40,&local_58);
    fVar2 = (float10)FUN_005b7d30(_DAT_0092505c,0x411e0000);
    iVar6 = (int)ROUND((fVar2 / (float10)9.875) * (float10)65536.0);
    uVar1 = FUN_004d4ce0();
    FUN_005b5700(uVar1,uVar1,PTR_DAT_008021b4 + 0xb8);
    FUN_005b4900(local_40,local_4c);
    FUN_005ff7a0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0x4a0,local_40,param_3,fVar4,iVar6);
  }
  return;
}

