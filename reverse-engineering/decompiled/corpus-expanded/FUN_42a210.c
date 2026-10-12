/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x42a210; label: FUN_0042a210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042a210(float *param_1)

{
  int iVar1;
  
  if (PTR_DAT_00802c54 != (undefined *)0x0) {
    iVar1 = *(int *)(PTR_DAT_00802c54 + 0x128);
    if (iVar1 == DAT_00951b88) {
      *param_1 = *param_1 * _DAT_0087b6d4;
      return;
    }
    if ((iVar1 == DAT_00951b9c) && (DAT_009562b4 == 3)) {
      *param_1 = *param_1 * _DAT_009562b8;
      return;
    }
    if (((*(uint *)(iVar1 + 100) & 0x400) != 0) &&
       (((DAT_0087a6dc != '\0' && (*(int *)(DAT_0087a74c + 0xc) == 0xc)) &&
        ((DAT_0087a6d8 & 0x1000) == 0)))) {
      if (*(float *)(DAT_0087a74c + 0x18) < 0.5) {
        *param_1 = 1.0 - (*(float *)(DAT_0087a74c + 0x18) + *(float *)(DAT_0087a74c + 0x18));
        return;
      }
      *param_1 = 0.0;
      return;
    }
  }
  iVar1 = FUN_00574e20();
  if ((iVar1 == 0xf) && (DAT_00879514 == 4)) {
    if (_DAT_0087959c < 0.5) {
      *param_1 = 1.0 - (_DAT_0087959c + _DAT_0087959c);
      return;
    }
    *param_1 = 0.0;
  }
  return;
}

