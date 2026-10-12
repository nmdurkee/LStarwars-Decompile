/* Ghidra analysis pseudocode, not original source.
 * ev_2bdbbe329da9ea38d1a43ba98d87f55aefaa8a75bec4fa8a7bfad8e968716318
 * Entry: 0x442060; label: FUN_00442060
 */

char FUN_00442060(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_004f8b10(param_2,"DEACTIVATED");
  if (iVar1 == 0) {
    return '\x17';
  }
  iVar1 = FUN_004f8b10(param_2,"FORCEDBACK");
  if (iVar1 == 0) {
    return '\"';
  }
  iVar1 = FUN_004f8b10(param_2,&DAT_00757628);
  if (iVar1 == 0) {
    return '8';
  }
  iVar1 = FUN_004f8b10(param_2,&DAT_00757624);
  if (iVar1 == 0) {
    return '?';
  }
  iVar1 = FUN_004f8b10(param_2,"FORCEPUSHED");
  if (iVar1 == 0) {
    return '\x1c';
  }
  iVar1 = FUN_004f8b10(param_2,"FORCEPUSH");
  if (iVar1 == 0) {
    return '\x1b';
  }
  iVar1 = FUN_004f8b10(param_2,"GETIN");
  if (iVar1 == 0) {
    return '<';
  }
  iVar1 = FUN_004f8b10(param_2,"BALLOONING");
  if (iVar1 == 0) {
    return ']';
  }
  iVar1 = FUN_004f8b10(param_2,"STUNNED");
  if (iVar1 == 0) {
    return 'Z';
  }
  iVar1 = FUN_004f8b10(param_2,"FLOAT");
  if (iVar1 == 0) {
    return 'K';
  }
  iVar1 = FUN_004f8b10(param_2,"GRAPPLE");
  return (-(iVar1 != 0) & 0x1eU) + 0x46;
}

