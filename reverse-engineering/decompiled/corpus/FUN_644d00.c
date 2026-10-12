/* Ghidra analysis pseudocode, not original source.
 * ev_9b402c9e9507e171b8c16fab1dff2f919b44cba00aab1d6e0da1cdd21bc5614e
 * Entry: 0x644d00; label: FUN_00644d00
 */

void FUN_00644d00(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int unaff_ESI;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0x800000c0;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  local_4 = 0x80404040;
  if (param_2 == 1) {
    local_10 = 0x8000c000;
  }
  DAT_0291f710 = FUN_00619250(0x46,0x46,300,0xfa,DAT_02912e80,&LAB_00644ce0,"Message");
  if (DAT_0291f710 != 0) {
    uVar1 = FUN_00627a80(1,&local_10,0,0,0,param_1);
    FUN_00618e10(DAT_0291f710,uVar1);
    FUN_006279b0();
    *(int *)(DAT_0291f710 + 0x14) = *(int *)(unaff_ESI + 0x14) + 10;
    *(int *)(DAT_0291f710 + 0x18) = *(int *)(unaff_ESI + 0x18) + 0x28;
  }
  return;
}

