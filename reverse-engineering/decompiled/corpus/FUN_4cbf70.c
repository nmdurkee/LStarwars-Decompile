/* Ghidra analysis pseudocode, not original source.
 * ev_def803aaf6df2de69fb7a62b9730926f531944633efe81a39820bd20d35cd513
 * Entry: 0x4cbf70; label: FUN_004cbf70
 */

int FUN_004cbf70(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_004f8b10(param_1,"DBLJUMP");
  if (iVar1 == 0) {
    return 2;
  }
  iVar1 = FUN_004f8b10(param_1,"R2D2GLIDE");
  if (iVar1 == 0) {
    return 4;
  }
  iVar1 = FUN_004f8b10(param_1,"ZIPUP");
  if (iVar1 == 0) {
    return 8;
  }
  iVar1 = FUN_004f8b10(param_1,"USEHATCH");
  if (iVar1 == 0) {
    return 0x10;
  }
  iVar1 = FUN_004f8b10(param_1,"JARJARJUMP");
  if (iVar1 == 0) {
    return 0x20;
  }
  iVar1 = FUN_004f8b10(param_1,"HOVERTUBE");
  if (iVar1 == 0) {
    return 0x40;
  }
  iVar1 = FUN_004f8b10(param_1,"SWAMP");
  if (iVar1 == 0) {
    return 0x4000;
  }
  iVar1 = FUN_004f8b10(param_1,"TAKEOVER");
  if (iVar1 == 0) {
    return 0x8000;
  }
  iVar1 = FUN_004f8b10(param_1,"VEHICLE");
  if (iVar1 == 0) {
    return 0x10000;
  }
  iVar1 = FUN_004f8b10(param_1,"PARTY");
  if (iVar1 == 0) {
    return 0x20000;
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
  if (iVar1 == 0) {
    return 0x800;
  }
  iVar1 = FUN_004f8b10(param_1,"BLOCKAGE");
  if (iVar1 == 0) {
    return 0x40000;
  }
  iVar1 = FUN_004f8b10(param_1,&DAT_00751850);
  if (iVar1 == 0) {
    return 1;
  }
  iVar1 = FUN_004f8b10(param_1,"DONTTOGGLE");
  if (iVar1 == 0) {
    return 0x80000;
  }
  iVar1 = FUN_004f8b10(param_1,"FULLTERRAIN");
  return (-(uint)(iVar1 != 0) & 0xfff00000) + 0x100000;
}

