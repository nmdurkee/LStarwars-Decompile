/* Ghidra analysis pseudocode, not original source.
 * ev_3ab0ab4bdd8dc8a455ed322812c7dbab6fd6000ce0d7a9019575e9409bf5a2c0
 * Entry: 0x4b38e0; label: FUN_004b38e0
 */

void FUN_004b38e0(int param_1)

{
  undefined4 uVar1;
  
  FUN_00427b40(param_1);
  FUN_0049be00(param_1);
  if ((*(byte *)(param_1 + 0xe20) & 0x20) == 0) {
    if (*(char *)(param_1 + 0x7b5) == '\x17') {
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x28);
    }
    FUN_004abac0(param_1,0,uVar1,0x41000000,0);
    FUN_0056d8c0(param_1,PTR_DAT_00802c54);
    FUN_004b0c80();
    FUN_004a6c30(*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_0080227c,
                 *(uint *)(*(int *)(param_1 + 0xca4) + 4) & DAT_0080227c,0x3f400000,1);
    if ((0.0 < *(float *)(*(int *)(param_1 + 0xca4) + 0x28)) &&
       (*(char *)(param_1 + 0x7b5) != '\x17')) {
      FUN_005478a0((int)*(short *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0xe2),param_1 + 0x80,
                   0,0);
    }
    FUN_004a8640(*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_00802280);
    FUN_0056a5b0(PTR_DAT_00802c54,param_1);
  }
  return;
}

