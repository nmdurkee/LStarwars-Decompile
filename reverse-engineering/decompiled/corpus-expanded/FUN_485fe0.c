/* Ghidra pseudocode, not original source.
 * ev_77fef26266fe5967585df020e38eccd49263e70128ef006db684616fa6a4691c
 * Entry: 0x485fe0; label: FUN_00485fe0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00485fe0(int param_1,float param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  float local_20c;
  float local_208;
  undefined1 local_204 [256];
  undefined1 local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_20c;
  local_208 = _DAT_007fa4f4 * param_2;
  if (*(float *)(param_1 + 0x60) == 0.0) {
    uVar1 = *(undefined4 *)(DAT_00926c20 + DAT_00880714 * 4);
    uVar2 = 0xff;
    uVar3 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(DAT_00926c20 + DAT_008806fc * 4);
    uVar2 = 0;
    uVar3 = 0xff;
  }
  local_20c = local_208 + 0.15;
  FUN_0050d910(uVar1,0,local_20c,0x3f800000,0x3f333333,0x3f333333,0x3f333333,0,uVar2,uVar3,0,
               0x3fd9999a,1,0,0,param_3 & 0xff);
  if (*(float *)(param_1 + 0x60) == 0.0) {
    local_20c = *(float *)(param_1 + 100);
  }
  else {
    local_20c = *(float *)(param_1 + 0x60);
  }
  FUN_0054bbc0(local_20c,1,1,1,local_204);
  local_20c = local_208 + 0.0;
  FUN_0050c780(local_204,0,local_20c,0x3f800000,0x3f333333,0x3f333333,0x3f333333,0,0xff,0xff,0xff,
               param_3);
  FUN_0054bbc0(*(undefined4 *)(param_1 + 0x5c),1,1,1,local_204);
  FUN_004f1f10(local_104,&DAT_00755d74);
  FUN_004f1e80(local_104,local_204);
  FUN_004f1e80(local_104,&DAT_00755d70);
  local_20c = local_208 - 0.15;
  FUN_0050c780(local_104,0,local_20c,0x3f800000,0x3f333333,0x3f333333,0x3f333333,0,0xff,0xff,0xff,
               param_3 >> 1 & 0x7f);
  __security_check_cookie(local_4 ^ (uint)&local_20c);
  return;
}

