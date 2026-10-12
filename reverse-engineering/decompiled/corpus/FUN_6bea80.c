/* Ghidra analysis pseudocode, not original source.
 * ev_c9fa25cc79717ad47e0beb6e0964d9456c9021d00a3c9a64cb36b68ef15e0051
 * Entry: 0x6bea80; label: FUN_006bea80
 */

void FUN_006bea80(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_00625150(in_ECX + 4,&DAT_0081f9a0,0,&LAB_006bc900,0x3f800000,0x42480000,
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

