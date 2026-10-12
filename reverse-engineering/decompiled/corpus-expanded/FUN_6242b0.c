/* Ghidra pseudocode, not original source.
 * ev_d2141175d7fdb31f80696454dffb563fb6f914ee7c013e44c78745164b884694
 * Entry: 0x6242b0; label: FUN_006242b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006242b0(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_474 [28];
  int local_458;
  int local_454;
  undefined4 *local_450;
  int local_44c;
  undefined1 local_448 [512];
  undefined1 local_248 [516];
  uint local_44;
  
  local_44 = DAT_00829570 ^ (uint)auStack_474;
  puVar1 = (undefined4 *)*param_1;
  iVar3 = 0;
  local_450 = param_1;
  local_458 = 0;
  local_454 = 0;
  local_44c = 0;
  FUN_0061ebc0();
  FUN_005d0a40(1);
  FUN_005d0fe0(DAT_02912b38,_DAT_0080f558,_DAT_0080f55c);
  if (param_1[0xd] != 0) {
    FUN_005d0d60(DAT_02912b38,param_1[0xd]);
    iVar3 = FUN_006e6b90();
    iVar3 = iVar3 >> 4;
    if (0 < iVar3) {
      local_458 = iVar3;
    }
  }
  do {
    if (puVar1 == (undefined4 *)0x0) {
      FUN_005d0e80();
      iVar3 = FUN_006e6b90();
      iVar3 = (iVar3 >> 3) + local_44c + local_454;
      if (local_458 < iVar3) {
        local_458 = iVar3;
      }
      for (puVar1 = (undefined4 *)*param_1; puVar1 != (undefined4 *)0x0;
          puVar1 = (undefined4 *)*puVar1) {
        if (puVar1[2] == 0x11) {
          local_450 = (undefined4 *)(local_454 + 1);
          puVar1[0x15] = (float)(int)local_450;
        }
      }
      param_1[7] = local_458 + param_2;
      FUN_005d0a70();
      for (iVar3 = param_1[1]; iVar3 != 0; iVar3 = *(int *)(iVar3 + 4)) {
        if (*(int *)(iVar3 + 8) == 0x13) {
          FUN_0061eb60();
        }
      }
      __security_check_cookie(local_44 ^ (uint)auStack_474);
      return;
    }
    switch(puVar1[2]) {
    case 1:
      FUN_005d0e80();
      iVar3 = FUN_006e6b90();
      iVar3 = (iVar3 >> 3) * 10;
      break;
    case 2:
    case 3:
      if (puVar1[9] != 0) {
        FUN_005d0e80();
        iVar3 = FUN_006e6b90();
        FUN_005d0d60(DAT_02912b38);
        iVar2 = FUN_006e6b90();
        iVar3 = (iVar2 >> 4) + (iVar3 >> 3);
        param_1 = local_450;
      }
      break;
    default:
      if (puVar1[9] != 0) {
        FUN_005d0d60();
        goto LAB_006244a0;
      }
      break;
    case 6:
      FUN_004f1f10(local_448,puVar1[9]);
      FUN_004f1e80(local_448,puVar1[0x19]);
      FUN_004f2740(local_248,local_448);
      FUN_005d0d60(DAT_02912b38,local_248);
LAB_006244a0:
      iVar3 = FUN_006e6b90();
      iVar3 = iVar3 >> 4;
      break;
    case 0x11:
      if (puVar1[9] == 0) {
        iVar3 = 0x1e;
      }
      else {
        FUN_005d0d60(DAT_02912b38,puVar1[9]);
        iVar3 = FUN_006e6b90();
        iVar3 = iVar3 >> 4;
      }
      if (local_454 < iVar3) {
        local_454 = iVar3;
      }
      if (puVar1[0x19] == 0) {
        iVar3 = 0x1e;
      }
      else {
        FUN_005d0d60(DAT_02912b38,puVar1[0x19]);
        iVar3 = FUN_006e6b90();
        iVar3 = iVar3 >> 4;
      }
      if (local_44c < iVar3) {
        local_44c = iVar3;
      }
    }
    if (local_458 < iVar3) {
      local_458 = iVar3;
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}

