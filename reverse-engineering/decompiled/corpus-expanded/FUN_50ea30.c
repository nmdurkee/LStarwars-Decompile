/* Ghidra pseudocode, not original source.
 * ev_846633128d4cd55df9225f061f87b742b0c1598eeb1c7e5f9192575f77c77f04
 * Entry: 0x50ea30; label: FUN_0050ea30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0050ea30(int param_1,char *param_2,float param_3,float param_4,undefined4 param_5,
                 float param_6,float param_7,byte param_8,undefined4 param_9,undefined4 *param_10,
                 int param_11)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  float10 fVar5;
  float local_44c;
  float local_448;
  undefined4 local_444 [16];
  undefined1 local_404 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_44c;
  if ((((param_2 != (char *)0x0) && (*param_2 != '\0')) && (DAT_00921d24 == 0)) &&
     ((param_1 != 0 || (param_1 = DAT_00921e9c, DAT_00921e9c != 0)))) {
    FUN_005d0880(4);
    FUN_005d0a40(4);
    FUN_005d0fb0(param_1);
    FUN_0050e980(param_1,param_2,local_404);
    local_44c = _DAT_008015c0 * param_6;
    FUN_005d0fe0(param_1,local_44c,_DAT_008015c0 * param_7);
    fVar5 = (float10)FUN_005d0c50(param_1,local_404);
    local_44c = (float)fVar5;
    fVar5 = (float10)FUN_005d0e80(param_1);
    local_448 = (float)fVar5;
    fVar1 = local_448 * 0.5;
    param_4 = param_4 - fVar1;
    if ((param_8 & 4) == 0) {
      if ((param_8 & 1) != 0) {
        param_4 = param_4 + fVar1;
      }
    }
    else {
      param_4 = param_4 - fVar1;
    }
    if ((param_8 & 2) == 0) {
      if ((param_8 & 8) == 0) {
        param_3 = param_3 - local_44c * 0.5;
      }
      else {
        param_3 = param_3 - local_44c;
      }
    }
    if (param_11 == 0) {
      puVar4 = local_444;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = *param_10;
        param_10 = param_10 + 1;
        puVar4 = puVar4 + 1;
      }
    }
    else {
      uVar2 = FUN_005d6170();
      FUN_005b5430(local_444,param_10,uVar2);
    }
    FUN_005d1030(param_1,local_444);
    FUN_005d1060(param_1,param_9);
    FUN_005d08f0(param_1,0x40000000);
    FUN_005eabb0(param_1,param_3,param_4,param_5);
    FUN_005f34e0(param_1,local_404);
    FUN_005d0a70();
    FUN_005d08c0();
  }
  __security_check_cookie(local_4 ^ (uint)&local_44c);
  return;
}

