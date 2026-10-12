/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a7cb0; label: FUN_004a7cb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a7cb0(void)

{
  short sVar1;
  int in_ECX;
  
  sVar1 = *(short *)(in_ECX + 0x42);
  if ((sVar1 != 5) &&
     (((*(byte *)(*(int *)(in_ECX + 0x54) + 4) & 0x20) == 0 ||
      (((sVar1 != 0x28 && (sVar1 != 0x4b)) && (sVar1 != 0x4c)))))) {
    *(undefined4 *)(in_ECX + 0xdac) = 0;
    return;
  }
  *(float *)(in_ECX + 0xdac) = *(float *)(in_ECX + 0xdac) + _DAT_00925018;
  return;
}

