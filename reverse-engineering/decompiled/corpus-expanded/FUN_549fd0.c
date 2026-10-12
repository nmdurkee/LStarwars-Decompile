/* Ghidra pseudocode, not original source.
 * ev_ba19024e936acaebc8caa887b02629c3d2df1b51d473842281df89ce325ba5c8
 * Entry: 0x549fd0; label: FUN_00549fd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00549fd0(void)

{
  float fVar1;
  undefined *puVar2;
  int iVar3;
  float fVar4;
  
  iVar3 = FUN_0054fa60();
  puVar2 = PTR_DAT_008021b4;
  if (iVar3 < 0x8000) {
    fVar1 = -0.25;
  }
  else {
    fVar1 = 0.25;
  }
  fVar4 = ABS(fVar1);
  if (fVar4 <= *(float *)(PTR_DAT_008021b4 + 0x1c8)) {
    return;
  }
  *(float *)(PTR_DAT_008021b4 + 0x1cc) = fVar4;
  *(float *)(puVar2 + 0x1c8) = fVar4;
  if (0.0 <= fVar1) {
    puVar2[0x228] = 0;
    puVar2[0x229] = 2;
    return;
  }
  puVar2[0x228] = 1;
  puVar2[0x229] = 2;
  return;
}

