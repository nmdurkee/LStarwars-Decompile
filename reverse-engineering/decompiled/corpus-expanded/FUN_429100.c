/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x429100; label: FUN_00429100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

