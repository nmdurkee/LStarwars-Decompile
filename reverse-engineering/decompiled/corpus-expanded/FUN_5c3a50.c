/* Ghidra pseudocode, not original source.
 * ev_0482cf9cbac4014c2cc66ca9c1732d06d5723bc39accc7934085547e48d62c38
 * Entry: 0x5c3a50; label: FUN_005c3a50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c3a50(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  
  FUN_005f8bf0(param_3);
  FUN_005c2760();
  iVar1 = FUN_005f7c40(param_1);
  iVar2 = FUN_005f7c50(param_1);
  iVar3 = FUN_005f8ae0(param_3);
  if (iVar3 == iVar1) {
    iVar1 = FUN_005f8b10(param_3);
    uVar5 = 1;
    if (iVar1 == iVar2) goto LAB_005c3aa1;
  }
  uVar5 = 2;
LAB_005c3aa1:
  FUN_005f7d00(param_1,uVar5,uVar5,0);
  FUN_005f7d00(param_2,uVar5,uVar5,0);
  if (param_1 != 0) {
    piVar4 = (int *)FUN_005f8460(param_1);
    if ((DAT_0097f9b8 != *piVar4) || (DAT_0097f9bc != piVar4[1])) {
      uVar5 = FUN_005f8460(param_1);
      FUN_005fa540(0,uVar5);
    }
  }
  FUN_005f8550(param_1,0);
  if (param_2 != 0) {
    piVar4 = (int *)FUN_005f8460(param_2);
    if ((DAT_0097f9e0 != *piVar4) || (DAT_0097f9e4 != piVar4[1])) {
      uVar5 = FUN_005f8460(param_2);
      FUN_005fa540(5,uVar5);
    }
  }
  FUN_005f8550(param_2,5);
  FUN_006e5340(0x16,1);
  FUN_006e5340(0xf,0);
  FUN_006e5340(0x1b,0);
  FUN_006e5340(7,1);
  FUN_006e5340(0xe,1);
  FUN_006e5340(0x17,8);
  FUN_005fb550();
  FUN_006e5340(0x16,1);
  FUN_006e5340(0xf,0);
  FUN_006e5340(0x1b,0);
  FUN_006e5340(7,0);
  FUN_006e5340(0xa8,0xf);
  return;
}

