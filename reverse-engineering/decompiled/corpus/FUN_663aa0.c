/* Ghidra analysis pseudocode, not original source.
 * ev_280130a43e77cd6b8822caba528fd01ad8a7c5be61051c42bd6bb5c51ef00c77
 * Entry: 0x663aa0; label: FUN_00663aa0
 */

void FUN_00663aa0(undefined4 param_1,int param_2)

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
  DAT_0292fc6c = FUN_00619250(0x46,0x46,0xb4,0xfa,DAT_02912e80,&LAB_00663a80,"Message");
  if (DAT_0292fc6c != 0) {
    uVar1 = FUN_00627a80(1,&local_10,0,0,0,param_1);
    FUN_00618e10(DAT_0292fc6c,uVar1);
    FUN_006279b0();
    *(int *)(DAT_0292fc6c + 0x14) = *(int *)(unaff_ESI + 0x14) + 10;
    *(int *)(DAT_0292fc6c + 0x18) = *(int *)(unaff_ESI + 0x18) + 0x28;
  }
  return;
}

