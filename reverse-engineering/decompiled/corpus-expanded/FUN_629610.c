/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x629610; label: FUN_00629610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00629610(int param_1,int param_2,float *param_3,float *param_4,float *param_5,byte *param_6
                 )

{
  int iVar1;
  int iVar2;
  float *extraout_ECX;
  int extraout_EDX;
  int iVar3;
  float *pfVar4;
  float *local_108;
  undefined1 local_104 [256];
  uint local_4;
  
  iVar3 = DAT_02900a50;
  local_4 = DAT_00829570 ^ (uint)&local_108;
  local_108 = param_5;
  if (*(int *)(DAT_02900a50 + 0x40) == 0) {
    iVar2 = *(int *)(param_1 + 0x3c);
    iVar1 = param_1;
    while (iVar2 != 0) {
      iVar1 = *(int *)(iVar1 + 0x3c);
      iVar2 = *(int *)(iVar1 + 0x3c);
    }
    *(int *)(DAT_02900a50 + 0x40) = iVar1;
    *(int *)(iVar1 + 0x3c) = iVar3;
    FUN_006271a0();
    iVar3 = extraout_EDX;
  }
  if (param_2 == 0) {
    *(int *)(iVar3 + 0x14) = *(int *)(param_1 + 0x14) + 10;
    iVar2 = *(int *)(param_1 + 0x18);
  }
  else {
    *(int *)(iVar3 + 0x14) = *(int *)(param_2 + 0x1c) + 10;
    iVar2 = *(int *)(param_2 + 0x20);
  }
  *(int *)(iVar3 + 0x18) = iVar2 + 10;
  iVar2 = (DAT_00973904 - *(int *)(iVar3 + 0x20)) + -0x14;
  if (*(int *)(iVar3 + 0x18) <= iVar2) {
    iVar2 = *(int *)(iVar3 + 0x18);
  }
  *(int *)(iVar3 + 0x18) = iVar2;
  iVar3 = DAT_029110ac;
  DAT_02912130 = param_6;
  DAT_02912e48 = &DAT_02912e54;
  pfVar4 = local_108;
  if (param_6 != (byte *)0x0) {
    param_3 = &DAT_02912e58;
    param_4 = &DAT_02910c88;
    DAT_02912e58 = (float)*param_6 / 255.0;
    DAT_02910c88 = (float)param_6[1] / 255.0;
    DAT_02900a64 = (float)param_6[2] / 255.0;
    local_108 = (float *)(uint)param_6[3];
    _DAT_02912e54 = (float)(int)local_108 / 255.0;
    pfVar4 = &DAT_02900a64;
  }
  DAT_02900a60 = pfVar4;
  DAT_02910c98 = param_3;
  DAT_02912e4c = param_4;
  FUN_00618000(*param_3,*param_4,*pfVar4,DAT_029110ac + 0x5c);
  *(float *)(iVar3 + 0x4c) = *extraout_ECX / 360.0;
  *(undefined4 *)(iVar3 + 0x50) = *(undefined4 *)(iVar3 + 0x5c);
  FUN_004f2740(local_104,"R:%1.2f G:%1.2f B:%1.2f",(double)*param_3,(double)*param_4,(double)*pfVar4
              );
  FUN_00619430(DAT_02910c90,local_104);
  __security_check_cookie(local_4 ^ (uint)&local_108);
  return;
}

