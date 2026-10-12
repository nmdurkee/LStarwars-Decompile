/* Ghidra pseudocode, not original source.
 * ev_6ff60c7644817ef8ef03e73cfdcec4dc91928e5367edba007261837c31d60754
 * Entry: 0x4b3240; label: FUN_004b3240
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b3240(int param_1)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  
  FUN_00427b40(param_1);
  if ((*(byte *)(param_1 + 0xe20) & 0x20) == 0) {
    FUN_004abac0(param_1,0,0,0,0);
    if (((PTR_DAT_00802c54 != (undefined *)0x0) &&
        (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af78)) && (1.0 < *(float *)(param_1 + 0x6c))) {
      *(undefined4 *)(param_1 + 0x6c) = 0x3f800000;
    }
    if (*(short *)(param_1 + 0x27e) == -1) {
      if (*(uint *)(param_1 + 0x1f0) != 0 || *(uint *)(param_1 + 500) != 0) {
        uVar2 = *(uint *)(DAT_0093d810 + 0x1e8);
        uVar3 = *(uint *)(DAT_0093d810 + 0x1ec);
        if (DAT_0093d814 != 0) {
          uVar2 = uVar2 | *(uint *)(DAT_0093d814 + 0x1e8);
          uVar3 = uVar3 | *(uint *)(DAT_0093d814 + 0x1ec);
        }
        if ((~uVar2 & *(uint *)(param_1 + 0x1f0)) != 0 || (~uVar3 & *(uint *)(param_1 + 500)) != 0)
        {
          FUN_004364e0(param_1,2,0);
        }
      }
    }
    else {
      FUN_004364e0(param_1,2,0);
    }
    if ((*(char *)(param_1 + 0x7b5) == '4') &&
       (fVar1 = *(float *)(param_1 + 0x77c) + _DAT_00925018, *(float *)(param_1 + 0x77c) = fVar1,
       10.0 < fVar1)) {
      FUN_004364e0(param_1,2,1);
    }
  }
  return;
}

