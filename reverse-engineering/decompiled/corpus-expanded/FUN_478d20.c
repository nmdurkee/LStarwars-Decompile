/* Ghidra pseudocode, not original source.
 * ev_d7259de4d528e446adcf31e3fd20dda0be8e8c3eebc020039674bf2429a30a4e
 * Entry: 0x478d20; label: FUN_00478d20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00478d20(int param_1,undefined4 param_2,float param_3,float param_4,int param_5,int param_6
                 )

{
  float fVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  float10 fVar5;
  undefined1 auStack_30 [4];
  float local_2c;
  uint local_28;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_30;
  fVar5 = (float10)FUN_005b7d30(_DAT_00925028,0x40800000);
  local_28 = (uint)ROUND(fVar5 * (float10)0.25 * (float10)65536.0);
  uVar4 = local_28 & 0xffff;
  iVar2 = FUN_006e6b90();
  fVar1 = (float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] * _DAT_007fc320;
  local_28 = (uint)ROUND((float)(&DAT_029899a0)[(int)(uVar4 * 2) >> 1 & 0x7fff] * -1820.0);
  local_2c = (_DAT_00805270 + param_3) - _DAT_00805278;
  FUN_00552d10(param_2,local_2c,0x3f800000,fVar1,fVar1,fVar1,-0x38e - (short)local_28,uVar4,0,
               param_1 * 0x10 + *(int *)(PTR_DAT_00802c54 + 0x2ac0),2);
  if ((-1 < param_5) && (-1 < param_6)) {
    if (param_6 == 1) {
      puVar3 = &DAT_00758804;
      if (param_5 != 1) {
        puVar3 = &DAT_00759770;
      }
      FUN_004f1f10(local_24,puVar3);
    }
    else {
      _sprintf(local_24,"%i/%i",param_5,param_6);
    }
    local_2c = _DAT_00805274 * _DAT_007f930c;
    FUN_0050c780(local_24,param_2,param_3,0x3f800000,local_2c,_DAT_00805274,_DAT_00805274,0,0xff,0,
                 0x7f,(int)ROUND(param_4 * 128.0) & 0xff);
  }
  __security_check_cookie(local_4 ^ (uint)auStack_30);
  return;
}

