/* Ghidra analysis pseudocode, not original source.
 * ev_7aab14e0333828c3f97507d2210eedd59fd790849ff0958821514dbec2d3feea
 * Entry: 0x4817e0; label: FUN_004817e0
 */

int FUN_004817e0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f8b10(param_1,"DBLJUMP");
  if (iVar1 == 0) {
    return 2;
  }
  iVar1 = FUN_004f8b10(param_1,"BIGJUMP");
  if (iVar1 == 0) {
    return 4;
  }
  iVar1 = FUN_004f8b10(param_1,&DAT_00751850);
  if (iVar1 == 0) {
    return 1;
  }
  iVar1 = FUN_004f8b10(param_1,"GRAPPLE");
  if (iVar1 == 0) {
    return 8;
  }
  iVar1 = FUN_004f8b10(param_1,"CLIMB");
  if (iVar1 == 0) {
    return 0x10;
  }
  iVar1 = FUN_004f8b10(param_1,"NO_DEST_CHECK");
  if (iVar1 == 0) {
    return 0x20;
  }
  iVar1 = FUN_004f8b10(param_1,"JUMP_NOW");
  if (iVar1 == 0) {
    return 0x40;
  }
  iVar1 = FUN_004f8b10(param_1,"DONT_JUMP_NOW");
  if (iVar1 == 0) {
    return 0x80;
  }
  iVar1 = FUN_004f8b10(param_1,"FORGOODIES");
  if (iVar1 == 0) {
    return 0x100;
  }
  iVar1 = FUN_004f8b10(param_1,"FORBADDIES");
  if (iVar1 == 0) {
    return 0x200;
  }
  iVar1 = FUN_004f8b10(param_1,"OBSTACLE");
  if (iVar1 == 0) {
    return 0x20000000;
  }
  iVar1 = FUN_004f8b10(param_1,"WHIPSWING");
  return (-(uint)(iVar1 != 0) & 0xfffffc00) + 0x400;
}

