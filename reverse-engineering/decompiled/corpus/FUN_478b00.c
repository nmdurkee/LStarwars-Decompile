/* Ghidra analysis pseudocode, not original source.
 * ev_89b7b842136f36149785ae3176f422ef77993aed8671c7148cbe0781c54fcb17
 * Entry: 0x478b00; label: FUN_00478b00
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00478b00(undefined4 param_1,float param_2,int param_3,float param_4)

{
  float fVar1;
  undefined *puVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  bool bVar5;
  float10 fVar6;
  undefined1 auStack_90 [4];
  float local_8c;
  float local_88;
  char local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_90;
  bVar5 = DAT_00879b70 != 0;
  DAT_00879b70 = 0;
  if (param_3 == 1) {
    puVar2 = &DAT_00758804;
    if (in_ECX != 1) {
      puVar2 = &DAT_00759770;
    }
    FUN_004f1f10(local_84,puVar2);
  }
  else {
    _sprintf(local_84,"%i/%i");
  }
  local_8c = _DAT_00805274 * _DAT_007f930c;
  FUN_0050c780(local_84,param_1,param_2,0x3f800000,local_8c,_DAT_00805274,_DAT_00805274,0,0xff,0,
               0x7f,(int)ROUND(param_4 * 128.0) & 0xff);
  fVar6 = (float10)FUN_005b7d30(_DAT_00925028,0x40800000);
  local_8c = (float)(int)ROUND(fVar6 * (float10)0.25 * (float10)65536.0);
  uVar4 = (uint)local_8c & 0xffff;
  iVar3 = FUN_006e6b90();
  fVar1 = (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff] * _DAT_0080526c;
  local_8c = (float)(int)ROUND((float)(&DAT_029899a0)[(int)(uVar4 * 2) >> 1 & 0x7fff] * 1820.0);
  local_88 = (_DAT_00805270 + param_2) - _DAT_00805278;
  FUN_00552d10(param_1,local_88,0x3f800000,fVar1,fVar1,fVar1,(uint)local_8c & 0xffff,uVar4,0,
               (bVar5 + 0xce) * 0x10 + *(int *)(PTR_DAT_00802c54 + 0x2ac0),2);
  __security_check_cookie(local_4 ^ (uint)auStack_90);
  return;
}

