/* Ghidra analysis pseudocode, not original source.
 * ev_6696c20a63c48b02c48d5a5db7e1958972e2427aa057f5485eee4f348cd6e250
 * Entry: 0x5c2940; label: FUN_005c2940
 */

void FUN_005c2940(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar2 = param_1;
  iVar3 = FUN_005f7c40(param_1);
  iVar4 = FUN_005f7c50(param_1);
  if (*(char *)(in_ECX + 0x88) == '\0') {
    if (*(char *)(in_ECX + 0x89) == '\0') {
      return;
    }
    iVar3 = *(int *)(in_ECX + 100);
  }
  else {
    param_1 = iVar3;
    if (iVar4 <= iVar3) {
      param_1 = iVar4;
    }
    FUN_005be790((float)param_1);
    iVar3 = FUN_006e6b90();
    iVar3 = -6 - iVar3;
  }
  FUN_0060a830(uVar2,1,uVar2,2,1,iVar3,1,0x3f800000,DAT_00973814);
  if (*(char *)(in_ECX + 0x89) != '\0') {
    iVar3 = *(int *)(in_ECX + 0x68);
    if (0.0 <= *(float *)(iVar3 + 0x24)) {
      local_10 = 0x3f800000;
      if (*(float *)(iVar3 + 0x24) <= 1.0) {
        local_10 = *(undefined4 *)(iVar3 + 0x24);
      }
    }
    else {
      local_10 = 0;
    }
    local_c = 0;
    local_8 = 0;
    local_4 = 0;
    FUN_005c2760();
    FUN_006e5750(0xae,&local_10,1);
    FUN_006e5750(0xaf,&DAT_0080beb0,1);
    FUN_0060c2e0(*(undefined4 *)(in_ECX + 0x5c),0,uVar2,*(undefined4 *)(in_ECX + 100),
                 *(undefined4 *)(in_ECX + 0x50),0);
    iVar3 = FUN_006e6b90();
    if (0 < iVar3) {
      FUN_0060a830(*(undefined4 *)(in_ECX + 0x5c),0,*(undefined4 *)(in_ECX + 0x5c),0,iVar3,1,1,
                   0x3f800000,DAT_00973814);
    }
    fVar1 = *(float *)(*(int *)(in_ECX + 0x68) + 0x1c) - (float)iVar3;
    if (0.0 < fVar1) {
      FUN_0060a830(*(undefined4 *)(in_ECX + 0x5c),0,*(undefined4 *)(in_ECX + 0x5c),0,1,1,1,fVar1,
                   DAT_00973814);
      return;
    }
  }
  return;
}

