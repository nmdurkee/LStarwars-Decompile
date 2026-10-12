/* Ghidra pseudocode, not original source.
 * ev_d41a9e73f582863d0d1c8c52ad55b427a61509ce0f65a786388b60a63b819da3
 * Entry: 0x5407d0; label: FUN_005407d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005407d0(undefined4 *param_1,int param_2,undefined4 param_3,int *param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  float fVar3;
  float fVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  short *psVar8;
  int iVar9;
  float10 fVar10;
  float10 fVar11;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  undefined1 local_30 [12];
  undefined1 local_24 [12];
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  local_6c = *param_1;
  local_64 = param_1[2];
  iVar7 = *(char *)(param_2 + 1) * 0x13c + *param_4;
  local_68 = 0;
  puVar5 = *(undefined4 **)(*(int *)(iVar7 + 4) + 8);
  if ((*(byte *)(iVar7 + 0x68) & 1) == 0) {
    iVar9 = *(int *)(iVar7 + 0x10);
  }
  else {
    iVar9 = *(int *)(iVar7 + 8);
  }
  puVar6 = *(undefined4 **)(iVar9 + 8);
  local_9c = *puVar5;
  local_94 = puVar5[2];
  local_60 = *puVar6;
  local_58 = puVar6[2];
  local_5c = 0;
  local_98 = 0;
  puVar1 = (undefined4 *)
           (*(int *)(*(short **)(iVar7 + 4) + 4) + -0xc + **(short **)(iVar7 + 4) * 0xc);
  if ((*(byte *)(iVar7 + 0x68) & 1) == 0) {
    psVar8 = *(short **)(iVar7 + 0x10);
  }
  else {
    psVar8 = *(short **)(iVar7 + 8);
  }
  puVar2 = (undefined4 *)(*(int *)(psVar8 + 4) + -0xc + *psVar8 * 0xc);
  local_90 = *puVar1;
  local_88 = puVar1[2];
  local_54 = *puVar2;
  local_4c = puVar2[2];
  local_50 = 0;
  local_8c = 0;
  fVar10 = (float10)FUN_0053de40(param_1,puVar5,puVar6);
  fVar3 = (float)fVar10;
  FUN_005b3800(local_24,&local_6c,&local_9c);
  fVar10 = (float10)FUN_005c0db0(local_24);
  fVar10 = (float10)FUN_005c0240(ABS((float)fVar10) * ABS((float)fVar10) - fVar3 * fVar3);
  FUN_005b3800(&local_78,&local_60,&local_9c);
  local_74 = 0.0;
  fVar11 = (float10)FUN_005c0db0(&local_78);
  local_40 = (float)((float10)(float)fVar10 / fVar11);
  local_48 = local_40 * local_78;
  local_44 = local_40 * local_74;
  local_40 = local_40 * local_70;
  FUN_005b37d0(local_18,&local_9c,&local_48);
  fVar10 = (float10)FUN_0053de40(param_1,puVar1,puVar2);
  fVar4 = (float)fVar10;
  FUN_005b3800(local_30,&local_6c,&local_90);
  fVar10 = (float10)FUN_005c0db0(local_30);
  fVar10 = (float10)FUN_005c0240(ABS((float)fVar10) * ABS((float)fVar10) - fVar4 * fVar4);
  FUN_005b3800(&local_84,&local_54,&local_90);
  local_80 = 0.0;
  fVar11 = (float10)FUN_005c0db0(&local_84);
  local_34 = (float)((float10)(float)fVar10 / fVar11);
  local_3c = local_34 * local_84;
  local_38 = local_80 * local_34;
  local_34 = local_34 * local_7c;
  FUN_005b37d0(local_c,&local_90,&local_3c);
  if (fVar3 < fVar4) {
    return (float10)fVar3;
  }
  return (float10)fVar4;
}

