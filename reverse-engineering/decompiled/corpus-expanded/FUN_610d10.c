/* Ghidra pseudocode, not original source.
 * ev_08b01c57e23761db39961ff885ea8d3cae9c908a4b5feb85ed876c23ab277753
 * Entry: 0x610d10; label: FUN_00610d10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00610d10(undefined4 param_1,float param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  float fVar2;
  undefined4 uVar3;
  int in_ECX;
  float10 fVar4;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_94;
  FUN_0060f850(param_1,param_2,param_3,param_4,param_5);
  FUN_005d0a40();
  FUN_005d0880(2);
  uVar3 = DAT_009738b8;
  fVar4 = (float10)FUN_005d0e80();
  local_8c = (float)fVar4;
  FUN_005d1060(uVar3,0x80808080);
  FUN_005d0fe0();
  local_94 = local_8c + param_2 + local_8c + local_8c + local_8c + local_8c;
  local_90 = local_8c + local_94;
  FUN_005eabb0(uVar3,param_1,local_90,0);
  FUN_004f2740(local_84,"Pack Ratio %.3f%%",(double)*(float *)(in_ECX + 0x230));
  FUN_005f3510(uVar3,local_84);
  local_90 = local_90 + local_8c;
  iVar1 = *(int *)(in_ECX + 0x10);
  local_94 = 0.0;
  local_88 = 0.0;
  if (iVar1 != 0) {
    local_94 = (float)*(int *)(in_ECX + 0x220);
    if (*(int *)(in_ECX + 0x220) < 0) {
      local_94 = local_94 + 4.2949673e+09;
    }
    fVar2 = (float)iVar1;
    if (iVar1 < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    local_94 = local_94 / fVar2;
  }
  iVar1 = *(int *)(in_ECX + 0x14);
  if (iVar1 != 0) {
    local_88 = (float)*(int *)(in_ECX + 0x224);
    if (*(int *)(in_ECX + 0x224) < 0) {
      local_88 = local_88 + 4.2949673e+09;
    }
    fVar2 = (float)iVar1;
    if (iVar1 < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
    local_88 = local_88 / fVar2;
  }
  FUN_005eabb0(uVar3,param_1,local_90,0);
  FUN_004f2740(local_84,"Pack Time %.2f : %.2f",(double)local_94,(double)local_88);
  FUN_005f3510(uVar3,local_84);
  local_90 = local_90 + local_8c;
  FUN_005eabb0(uVar3,param_1,local_90,0);
  FUN_004f2740(local_84,"Ave Packet %.1f",(double)*(float *)(in_ECX + 0x234));
  FUN_005f3510(uVar3,local_84);
  local_90 = local_90 + local_8c;
  FUN_005eabb0(uVar3,param_1,local_90,0);
  FUN_004f2740(local_84,"Split Packets %d",*(undefined4 *)(in_ECX + 0x228));
  FUN_005f3510(uVar3,local_84);
  local_94 = local_90 + local_8c;
  FUN_005eabb0(uVar3,param_1,local_94,0);
  FUN_004f2740(local_84,"Held Packets %d",*(undefined4 *)(in_ECX + 0x22c));
  FUN_005f3510(uVar3,local_84);
  FUN_005d08c0();
  FUN_005d0a70();
  __security_check_cookie(local_4 ^ (uint)&local_94);
  return;
}

