/* Ghidra pseudocode, not original source.
 * ev_fb6cd954323bef10c706b5185a175772da5bd325e62fab563c9169acbcfebd41
 * Entry: 0x6154f0; label: FUN_006154f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_006154f0(int *param_1,undefined4 param_2,int *param_3,int *param_4)

{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  undefined1 *puStack_2878;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 auStack_284c [4];
  undefined1 *local_2848;
  undefined1 *local_2844;
  undefined1 *local_2840;
  undefined **appuStack_283c [2];
  undefined4 uStack_2834;
  undefined1 *puStack_281c;
  undefined1 local_2804 [256];
  undefined1 local_2704 [4844];
  undefined1 auStack_1418 [20];
  undefined1 local_1404 [5076];
  uint uStack_30;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)auStack_284c;
  _memset(local_2804,0,0x1400);
  puStack_2878 = (undefined1 *)0x61554d;
  _memset(local_1404,0,0x1400);
  local_2848 = local_2804;
  local_2844 = local_2704;
  puVar3 = local_1404;
  local_2840 = local_2848;
  (**(code **)*param_1)();
  FUN_006c0780();
  uStack_2834 = 2;
  appuStack_283c[0] = &PTR_FUN_0076ac0c;
  puStack_2878 = (undefined1 *)0x6155a7;
  FUN_0053d5d0();
  puStack_281c = auStack_284c;
  puVar2 = &stack0xffffd7a0;
  puStack_2878 = &stack0xffffd7a4;
  iVar4 = 0x10;
  DAT_02900a38 = 1;
  (**(code **)(*param_1 + 4))(appuStack_283c,0,param_2,auStack_1418);
  DAT_02900a38 = 0;
  *param_3 = (int)puVar3 - (int)puVar2;
  if (iVar4 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = unaff_ESI - unaff_EDI;
  }
  *param_4 = iVar1;
  if (iVar4 != 0) {
    if (*(uint *)(iVar4 + 0x4b0) < 2) {
      *(undefined4 *)(iVar4 + 0x4b0) = 0;
    }
    else {
      *(uint *)(iVar4 + 0x4b0) = *(uint *)(iVar4 + 0x4b0) - 1;
    }
  }
  __security_check_cookie(uStack_30 ^ (uint)&puStack_2878);
  return;
}

