/* Ghidra pseudocode, not original source.
 * ev_4c4127be7d58e8981fbef62e7b9304e5f7a8f47caff33366593b2d257bcf3f12
 * Entry: 0x59f0e0; label: FUN_0059f0e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_0059f0e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_2a08;
  undefined1 local_2a04 [10752];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_2a08;
  DAT_009562f8 = local_2a04;
  local_2a08 = param_3;
  puVar6 = (undefined4 *)0x0;
  DAT_0095634c = 0;
  DAT_00956418 = param_4;
  DAT_0095641c = param_5;
  DAT_00956424 = 0;
  iVar3 = FUN_004fa5f0(param_3,0);
  if (iVar3 != 0) {
    iVar4 = FUN_004fc750(iVar3);
    if (iVar4 != 0) {
      FUN_004f10e0(iVar4,&PTR_s_FlowBox_0080558c);
      iVar5 = FUN_004fc5b0(iVar4);
      while (iVar5 != 0) {
        FUN_004f7fb0(iVar4);
        FUN_004fa020(iVar4);
        iVar5 = FUN_004fc5b0(iVar4);
      }
      FUN_004f12e0(iVar4);
    }
    if ((DAT_00956424 != 0) && (iVar4 = FUN_004fc750(iVar3), iVar4 != 0)) {
      puVar6 = (undefined4 *)FUN_00559610(DAT_00956418,DAT_0095641c,0x10);
      iVar5 = DAT_00956424;
      uVar1 = DAT_00956418;
      if (puVar6 != (undefined4 *)0x0) {
        puVar6[1] = DAT_00956424;
        uVar2 = DAT_0095641c;
        *puVar6 = param_2;
        DAT_00956428 = FUN_00559610(uVar1,uVar2,iVar5 << 5);
        puVar6[2] = DAT_00956428;
        DAT_00956420 = puVar6;
        FUN_004f10e0(iVar4,&PTR_s_FlowBox_0080559c);
        iVar5 = FUN_004fc5b0(iVar4);
        while (iVar5 != 0) {
          FUN_004f7fb0(iVar4);
          FUN_004fa020(iVar4);
          iVar5 = FUN_004fc5b0(iVar4);
        }
      }
      FUN_004f12e0(iVar4);
      if (DAT_00956424 != 0) {
        FUN_0059d760(local_2a08);
      }
    }
    FUN_004f99e0(iVar3);
  }
  DAT_00956418 = 0;
  DAT_0095641c = 0;
  DAT_00956420 = (undefined4 *)0x0;
  DAT_00956428 = 0;
  if (puVar6 != (undefined4 *)0x0) {
    *(undefined1 *)((int)puVar6 + 0xd) = 1;
  }
  __security_check_cookie(local_4 ^ (uint)&local_2a08);
  return;
}

