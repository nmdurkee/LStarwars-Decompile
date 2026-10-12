/* Ghidra analysis pseudocode, not original source.
 * ev_45ac563217612fbe2426642b00b9c96cf69ca1c78f087433beffcbe1e9bd0306
 * Entry: 0x528af0; label: FUN_00528af0
 */

undefined4 FUN_00528af0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((((DAT_00921f50 & 0x400) != 0) && (*(int *)(DAT_009238e4 + 0x371b0) != 0)) &&
     (*(char *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x5a) != *(char *)(param_1 + 0x5a))) {
    uVar1 = 0;
  }
  return uVar1;
}

