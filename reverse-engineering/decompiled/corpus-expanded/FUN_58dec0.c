/* Ghidra pseudocode, not original source.
 * ev_9931c233bc23f2b366e36cd20edde6ea49582f2b0a176997d8924d6b396dfde7
 * Entry: 0x58dec0; label: FUN_0058dec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0058dec0(int param_1)

{
  float fVar1;
  float10 fVar2;
  
  if (*(char *)(param_1 + 0xe33) == '\x01') {
    fVar2 = (float10)FUN_0054fad0(*(undefined4 *)(param_1 + 0xd3c),0x3f800000,
                                  *(float *)(param_1 + 0xd40) * _DAT_00925018);
    fVar1 = (float)fVar2;
    *(float *)(param_1 + 0xd3c) = fVar1;
    if (!NAN(fVar1) && 1.0 < fVar1 != (fVar1 == 1.0)) {
      *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) | 0x10000;
      *(undefined1 *)(param_1 + 0xe33) = 0;
    }
  }
  else if (*(char *)(param_1 + 0xe33) == '\x02') {
    fVar2 = (float10)FUN_0054fad0(*(undefined4 *)(param_1 + 0xd3c),0,
                                  *(float *)(param_1 + 0xd40) * _DAT_00925018);
    *(float *)(param_1 + 0xd3c) = (float)fVar2;
    if ((float)fVar2 <= 0.0) {
      *(uint *)(param_1 + 0xe20) = *(uint *)(param_1 + 0xe20) & 0xfffeffff;
      *(undefined1 *)(param_1 + 0xe33) = 0;
      return;
    }
  }
  return;
}

