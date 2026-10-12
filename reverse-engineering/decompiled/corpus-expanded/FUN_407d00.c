/* Ghidra pseudocode, not original source.
 * ev_c99ba83a21253fbea00a1b2af974464e548d813850fcca855330552d9e62c3cd
 * Entry: 0x407d00; label: FUN_00407d00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

