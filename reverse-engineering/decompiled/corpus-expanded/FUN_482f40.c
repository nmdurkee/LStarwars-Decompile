/* Ghidra pseudocode, not original source.
 * ev_6d95b912f1db8f5f9ae5a1d448774b8e294221a9d492d15be8ca5acea434db46
 * Entry: 0x482f40; label: FUN_00482f40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00482f40(undefined4 param_1,undefined2 param_2,float param_3,float param_4,
                 undefined4 param_5,undefined4 param_6,int param_7)

{
  undefined4 uVar1;
  float10 fVar2;
  float fVar3;
  float fVar4;
  float local_420 [5];
  float local_40c;
  undefined4 local_408;
  undefined1 local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_420;
  local_420[1] = 0.0;
  local_420[2] = 0.0;
  local_420[3] = 800.0;
  local_420[4] = _DAT_007fa4dc * param_3;
  local_40c = _DAT_007fa4e0 * param_4;
  local_408 = 0;
  FUN_005d0ee0(0x3f99999a,0x3f99999a);
  FUN_005b44e0(&DAT_0087a780);
  FUN_005b45f0(&DAT_0087a780,0);
  FUN_005b4f70(&DAT_0087a780,0);
  FUN_005b5160(&DAT_0087a780,param_2);
  FUN_005b4900(&DAT_0087a780,local_420 + 1);
  FUN_005b4900(&DAT_0087a780,local_420 + 4);
  uVar1 = FUN_005d6170();
  FUN_005b5430(&DAT_0087a780,&DAT_0087a780,uVar1);
  FUN_005d0fb0(DAT_00921e9c);
  FUN_005d1030(DAT_00921e9c,&DAT_0087a780);
  FUN_005d0880(4);
  FUN_005d0940(4);
  FUN_005d1060(DAT_00921e9c,param_6);
  FUN_005d0fe0(DAT_00921e9c,param_5,param_5);
  FUN_0050c100(param_1,local_404);
  if (param_7 == 2) {
    fVar2 = (float10)FUN_005d0e80(DAT_00921e9c,0);
    fVar4 = (float)(-fVar2 * (float10)0.5);
    fVar3 = 0.0;
    local_420[0] = fVar4;
  }
  else if (param_7 == 8) {
    fVar2 = (float10)FUN_005d0e80(DAT_00921e9c,0);
    fVar4 = (float)(-fVar2 * (float10)0.5);
    local_420[0] = fVar4;
    fVar2 = (float10)FUN_005d0c50(DAT_00921e9c,local_404,fVar4);
    fVar3 = (float)-fVar2;
  }
  else {
    fVar2 = (float10)FUN_005d0e80(DAT_00921e9c,0);
    fVar4 = (float)(-fVar2 * (float10)0.5);
    local_420[0] = fVar4;
    fVar2 = (float10)FUN_005d0c50(DAT_00921e9c,local_404,fVar4);
    fVar3 = (float)(-fVar2 * (float10)0.5);
    local_420[0] = fVar3;
  }
  FUN_005eabb0(DAT_00921e9c,fVar3,fVar4);
  FUN_005f34e0(DAT_00921e9c,local_404);
  FUN_005d08c0();
  FUN_005d0940(3);
  __security_check_cookie(local_4 ^ (uint)local_420);
  return;
}

