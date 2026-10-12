/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x429100; label: FUN_00429100
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00429100(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xdc) != 0) {
    if (DAT_00951288 != 0) {
      _DAT_0087b94c = _DAT_008033a8 + 1.0;
      return;
    }
    if (*(char *)(param_1 + 0xfe) == '\x01') {
      FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),0x38,param_1 + 0x7c);
      if ((*(int *)(PTR_DAT_00802c54 + 300) != 0) &&
         ((*(ushort *)(*(int *)(PTR_DAT_00802c54 + 300) + 0x7a) & 0x100) != 0)) {
        iVar1 = FUN_0054fa60();
        *(float *)(param_1 + 0x94) =
             ((float)iVar1 * 1.5259022e-05 * 0.2 - 0.1) + *(float *)(param_1 + 0x94);
        iVar1 = FUN_0054fa60();
        *(float *)(param_1 + 0x98) =
             ((float)iVar1 * 1.5259022e-05 * 0.2 - 0.1) + *(float *)(param_1 + 0x98);
        iVar1 = FUN_0054fa60();
        *(undefined1 *)(param_1 + 0xf9) = 0;
        *(float *)(param_1 + 0x9c) =
             ((float)iVar1 * 1.5259022e-05 * 0.2 - 0.1) + *(float *)(param_1 + 0x9c);
      }
    }
  }
  return;
}

