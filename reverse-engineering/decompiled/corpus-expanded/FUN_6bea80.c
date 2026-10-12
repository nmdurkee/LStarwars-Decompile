/* Ghidra pseudocode, not original source.
 * ev_7b6a9e0312bc8ed55bc8db18c390e5e94b6441153fc53fcf4106026d09190a6c
 * Entry: 0x6bea80; label: FUN_006bea80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006bea80(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_00625150(in_ECX + 4,&DAT_0081f9a0,0,FUN_006bc900,0x3f800000,0x42480000,
                       *(undefined4 *)(in_ECX + 4),"Cursor Radius");
  FUN_00618e10(param_1,uVar1);
  uVar1 = FUN_00627b80((byte *)(in_ECX + 8),&DAT_0081f9a0,*(undefined4 *)(in_ECX + 8),0,
                       &LAB_006bc950,"Snap Terrain");
  FUN_00618e10(param_1,uVar1);
  *(byte *)(DAT_02900c84 + 0x11) =
       *(byte *)(DAT_02900c84 + 0x11) ^ (*(byte *)(in_ECX + 8) ^ *(byte *)(DAT_02900c84 + 0x11)) & 1
  ;
  return;
}

