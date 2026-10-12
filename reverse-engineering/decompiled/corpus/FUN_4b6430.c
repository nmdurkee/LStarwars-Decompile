/* Ghidra analysis pseudocode, not original source.
 * ev_3ab0ab4bdd8dc8a455ed322812c7dbab6fd6000ce0d7a9019575e9409bf5a2c0
 * Entry: 0x4b6430; label: FUN_004b6430
 */

void FUN_004b6430(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xca4);
  FUN_0058d8b0(param_1);
  FUN_00427b40(param_1);
  if (*(undefined1 **)(param_1 + 0xcc4) != (undefined1 *)0x0) {
    **(undefined1 **)(param_1 + 0xcc4) = 0;
  }
  if ((*(byte *)(param_1 + 0xe20) & 0x20) == 0) {
    FUN_004abac0(param_1,0,0,0,0);
    FUN_0049c080(param_1);
    FUN_004b0c80();
    iVar1 = FUN_004b3d40(param_1,*(uint *)(iVar1 + 8) & DAT_0080227c,0,0,0,0);
    if (iVar1 != 0) {
      *(bool *)(param_1 + 0xe3a) = *(char *)(param_1 + 0xe3a) == '\0';
    }
    FUN_004a82a0(param_1,0);
    FUN_0058cef0(param_1);
    iVar1 = FUN_0062f1a0(param_1 + 8);
    if (((iVar1 == 0) && (*(char *)(param_1 + 0x7b5) != '\x17')) &&
       (*(char *)(param_1 + 0x7b5) != 'A')) {
      FUN_005478a0((int)*(short *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xe2),param_1 + 0x80,
                   0,0);
    }
    FUN_0056a5b0(PTR_DAT_00802c54,param_1);
  }
  return;
}

