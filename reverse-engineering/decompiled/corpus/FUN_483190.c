/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x483190; label: FUN_00483190
 */

void FUN_00483190(undefined4 param_1,undefined4 param_2,float param_3,float param_4,
                 undefined2 param_5,float param_6,undefined4 param_7,float param_8)

{
  undefined4 uVar1;
  int iVar2;
  float10 fVar3;
  float local_108;
  double local_104;
  float local_fc;
  float local_f8;
  double local_f4;
  float local_ec;
  float local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined1 local_d4 [64];
  char local_94 [16];
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_108;
  local_e0 = 0;
  local_dc = 0;
  local_d8 = 0x44480000;
  local_ec = param_3 * 400.0;
  local_e8 = param_4 * 250.0;
  local_e4 = 0;
  FUN_005d0ee0(0x3f99999a,0x3f99999a);
  FUN_005b44e0(local_d4);
  FUN_005b45f0(local_d4,0);
  FUN_005b4f70(local_d4,0);
  FUN_005b5160(local_d4,param_5);
  FUN_005b4900(local_d4,&local_e0);
  FUN_005b4900(local_d4,&local_ec);
  uVar1 = FUN_005d6170();
  FUN_005b5430(local_d4,local_d4,uVar1);
  FUN_005d0fb0(DAT_00921e9c);
  FUN_005d1030(DAT_00921e9c,local_d4);
  FUN_005d0880(4);
  FUN_005d0940(4);
  FUN_005d1060(DAT_00921e9c,param_7);
  FUN_005d0fe0(DAT_00921e9c,param_6,param_6);
  _sprintf(local_94,"%i/%i",param_1,param_2);
  FUN_0050c100(local_94,local_84);
  fVar3 = (float10)FUN_005d0c50(DAT_00921e9c,local_84);
  local_108 = (float)fVar3;
  fVar3 = (float10)FUN_005d0e80(DAT_00921e9c);
  local_104 = (double)CONCAT44(local_104._4_4_,-local_108 * 0.5);
  FUN_005eabb0(DAT_00921e9c,-local_108 * 0.5,-(float)fVar3 * 0.5,0);
  if (param_8 <= 0.0) {
    _sprintf(local_94,"%i",param_1);
    FUN_0050c100(local_94,local_84);
    FUN_005f34e0(DAT_00921e9c,local_84);
    _sprintf(local_94,(char *)&PTR_LAB_007598f4,param_2);
    FUN_0050c100(local_94,local_84);
    FUN_005f34e0(DAT_00921e9c,local_84);
  }
  else {
    iVar2 = FUN_006e6b90();
    local_f8 = (1.0 - (1.0 - ((float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] + 1.0) * 0.5)) * 0.5;
    local_fc = (param_6 + 0.5) - local_f8;
    local_f8 = (param_6 - 0.5) + local_f8;
    _sprintf(local_94,(char *)&PTR_LAB_007598f4,param_2);
    FUN_0050c100(local_94,local_84);
    local_f4 = (double)(local_108 * 0.5);
    local_104 = (double)local_108;
    fVar3 = (float10)FUN_005d0c50(DAT_00921e9c,local_84);
    local_108 = (float)(((float10)local_104 - fVar3) - (float10)local_f4);
    fVar3 = (float10)FUN_005d0e80(DAT_00921e9c,0);
    local_104._0_4_ = (float)(-fVar3 * (float10)0.5);
    FUN_005eabb0(DAT_00921e9c,local_108,(float)(-fVar3 * (float10)0.5));
    FUN_005f34e0(DAT_00921e9c,local_84);
    _sprintf(local_94,"%i",param_1);
    FUN_0050c100(local_94,local_84);
    fVar3 = (float10)FUN_005d0c50(DAT_00921e9c,local_84);
    local_104 = (double)CONCAT44(local_104._4_4_,(float)fVar3);
    FUN_005d0fe0(DAT_00921e9c,local_fc,local_fc);
    local_f4 = (double)(local_104._0_4_ * 0.5 - (float)local_f4);
    fVar3 = (float10)FUN_005d0c50(DAT_00921e9c,local_84);
    local_108 = (float)((float10)local_f4 - fVar3 * (float10)0.5);
    fVar3 = (float10)FUN_005d0e80(DAT_00921e9c,0);
    local_fc = (float)(-fVar3 * (float10)0.5);
    FUN_005eabb0(DAT_00921e9c,local_108,local_fc);
    FUN_005f34e0(DAT_00921e9c,local_84);
    FUN_005d0fe0(DAT_00921e9c,local_f8,local_f8);
    fVar3 = (float10)FUN_005d0c50(DAT_00921e9c,local_84);
    local_108 = (float)((float10)local_f4 - fVar3 * (float10)0.5);
    fVar3 = (float10)FUN_005d0e80(DAT_00921e9c,0);
    local_f8 = (float)(-fVar3 * (float10)0.5);
    FUN_005eabb0(DAT_00921e9c,local_108,local_f8);
    FUN_005f34e0(DAT_00921e9c,local_84);
  }
  FUN_005d08c0();
  FUN_005d0940(3);
  __security_check_cookie(local_4 ^ (uint)&local_108);
  return;
}

