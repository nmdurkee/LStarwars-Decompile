/* Ghidra analysis pseudocode, not original source.
 * ev_9e834adbd1be5074ad62417c72633ab4044f13767a5707860f49455a6f85e9eb
 * Entry: 0x407d00; label: FUN_00407d00
 */

int FUN_00407d00(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f8b10(param_1,&DAT_00751850);
  if (iVar1 == 0) {
    return 1;
  }
  iVar1 = FUN_004f8b10(param_1,"COMBATROLL");
  if (iVar1 == 0) {
    return 2;
  }
  iVar1 = FUN_004f8b10(param_1,"BATGLIDE");
  if (iVar1 == 0) {
    return 4;
  }
  iVar1 = FUN_004f8b10(param_1,"GRAPPLE");
  if (iVar1 == 0) {
    return 8;
  }
  iVar1 = FUN_004f8b10(param_1,"USEHATCH");
  if (iVar1 == 0) {
    return 0x10;
  }
  iVar1 = FUN_004f8b10(param_1,"HOVERTUBE");
  if (iVar1 == 0) {
    return 0x40;
  }
  iVar1 = FUN_004f8b10(param_1,"FORGOODIES");
  if (iVar1 == 0) {
    return 0x80;
  }
  iVar1 = FUN_004f8b10(param_1,"FORBADDIES");
  if (iVar1 == 0) {
    return 0x100;
  }
  iVar1 = FUN_004f8b10(param_1,"OBSTACLE");
  if (iVar1 == 0) {
    return 0x20000000;
  }
  iVar1 = FUN_004f8b10(param_1,"JUMP_NOW");
  if (iVar1 == 0) {
    return 0x400;
  }
  iVar1 = FUN_004f8b10(param_1,"DONT_JUMP_NOW");
  return (-(uint)(iVar1 != 0) & 0xfffff800) + 0x800;
}

