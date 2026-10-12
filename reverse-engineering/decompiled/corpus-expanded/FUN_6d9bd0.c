/* Ghidra pseudocode, not original source.
 * ev_901c6aaecd0b47868ef1d3f758584dfae83b8347f4e0d529523c41e91b06b177
 * Entry: 0x6d9bd0; label: FUN_006d9bd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d9bd0(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_004f1f10(in_ECX + 0x5d3a,"KeyboardMouse1");
  *(undefined4 *)(in_ECX + 0x5d0c) = 1;
  *(undefined4 *)(in_ECX + 0x5d14) = 1;
  *(undefined1 *)(in_ECX + 0x5d36) = 1;
  *(undefined1 *)(in_ECX + 0x5d39) = 1;
  *(undefined2 *)(in_ECX + 0x5d24) = 0xff;
  iVar1 = FUN_006d43e0(3,10,*(undefined4 *)(in_ECX + 0x6604));
  if ((iVar1 != 0) || (iVar1 = FUN_006d43e0(3,10,0xffffffff), iVar1 != 0)) {
    FUN_006d45f0(iVar1,10,(int)*(short *)(iVar1 + 0x5e),0,0);
  }
  *(undefined4 *)(in_ECX + 0x5e8c) = DAT_029765a4;
  FUN_004f1f10(in_ECX + 0x5eb6,"Keyboard1");
  *(undefined4 *)(in_ECX + 0x5e88) = 3;
  *(undefined4 *)(in_ECX + 0x5e90) = 3;
  *(undefined1 *)(in_ECX + 0x5eb2) = 1;
  *(undefined1 *)(in_ECX + 0x5eb5) = 1;
  *(undefined2 *)(in_ECX + 0x5ea0) = 0xff;
  iVar1 = FUN_006d43e0(3,0xb,*(undefined4 *)(in_ECX + 0x6604));
  if ((iVar1 != 0) || (iVar1 = FUN_006d43e0(3,0xb,0xffffffff), iVar1 != 0)) {
    FUN_006d45f0(iVar1,0xb,(int)*(short *)(iVar1 + 0x5e),0,0);
  }
  FUN_004f1f10(in_ECX + 0x6032,"KeyboardMouse2");
  *(undefined4 *)(in_ECX + 0x6004) = 2;
  *(undefined4 *)(in_ECX + 0x600c) = 2;
  *(undefined1 *)(in_ECX + 0x602e) = 1;
  *(undefined1 *)(in_ECX + 0x6031) = 1;
  *(undefined2 *)(in_ECX + 0x601c) = 0xff;
  iVar1 = FUN_006d43e0(3,0xc,*(undefined4 *)(in_ECX + 0x6604));
  if ((iVar1 != 0) || (iVar1 = FUN_006d43e0(3,0xc,0xffffffff), iVar1 != 0)) {
    FUN_006d45f0(iVar1,0xc,(int)*(short *)(iVar1 + 0x5e),0,0);
  }
  *(undefined4 *)(in_ECX + 0x6184) = DAT_029765a4;
  FUN_004f1f10(in_ECX + 0x61ae,"Keyboard2");
  *(undefined4 *)(in_ECX + 0x6180) = 4;
  *(undefined4 *)(in_ECX + 0x6188) = 4;
  *(undefined1 *)(in_ECX + 0x61aa) = 1;
  *(undefined1 *)(in_ECX + 0x61ad) = 1;
  *(undefined2 *)(in_ECX + 0x6198) = 0xff;
  iVar1 = FUN_006d43e0(3,0xd,*(undefined4 *)(in_ECX + 0x6604));
  if ((iVar1 == 0) && (iVar1 = FUN_006d43e0(3,0xd,0xffffffff), iVar1 == 0)) {
    return;
  }
  FUN_006d45f0(iVar1,0xd,(int)*(short *)(iVar1 + 0x5e),0,0);
  return;
}

