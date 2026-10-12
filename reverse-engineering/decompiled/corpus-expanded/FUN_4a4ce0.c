/* Ghidra pseudocode, not original source.
 * ev_a85b3e4898e579c25a43afce2c9968e46b76c95f9b8b71b7b173505cf03a6bab
 * Entry: 0x4a4ce0; label: FUN_004a4ce0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a4ce0(undefined4 param_1,float param_2,float param_3,undefined4 param_4)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  undefined1 local_4c [12];
  undefined1 local_40 [64];
  
  iVar4 = (int)param_3;
  iVar2 = FUN_0055f450();
  if ((param_3 != -NAN) &&
     (iVar5 = (int)param_3 * 0x10, *(char *)(*(int *)(iVar2 + 0x2ac0) + 0xe + iVar5) != '\0')) {
    thunk_FUN_005d05b0();
    FUN_005b3800(&local_64,param_1,DAT_00925164 + 0x30);
    fVar6 = (float10)FUN_005c0240(local_5c * local_5c + local_64 * local_64 + local_60 * local_60);
    fVar1 = (float)fVar6;
    FUN_005b3b30(&local_64,&local_64);
    param_3 = fVar1 - 0.2;
    if (param_3 <= param_2) {
      if (fVar1 < 0.2) {
        param_3 = 0.0;
      }
    }
    else {
      param_3 = param_2;
    }
    FUN_005b3830(&local_64,&local_64,param_3);
    FUN_005b3800(local_4c,param_1,&local_64);
    if (param_3 == 0.0) {
      local_50 = param_2;
    }
    else {
      local_50 = (param_2 * (fVar1 - param_3)) / fVar1;
    }
    local_58 = local_50;
    local_54 = local_50;
    FUN_005b45a0(local_40,&local_58);
    FUN_005b7d30(_DAT_0092505c,0x41a00000);
    FUN_00498040();
    FUN_005b5700(local_40,local_40,PTR_DAT_008021b4 + 0xb8);
    FUN_005b4900(local_40,local_4c);
    FUN_005ff7a0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + iVar5,local_40,param_4);
    iVar4 = (iVar4 + 1) * 0x10;
    if (*(char *)(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + 0xe + iVar4) != '\0') {
      FUN_005b45a0(local_40,&local_58);
      FUN_005b7d30(_DAT_0092505c,0x4186374c);
      uVar3 = FUN_00498040();
      FUN_005b5700(uVar3,uVar3,PTR_DAT_008021b4 + 0xb8);
      FUN_005b4900(local_40,local_4c);
      FUN_005ff7a0(*(int *)(PTR_DAT_00802c54 + 0x2ac0) + iVar4,local_40,param_4);
    }
    FUN_00596920(0);
  }
  return;
}

