/* Ghidra pseudocode, not original source.
 * ev_ba19024e936acaebc8caa887b02629c3d2df1b51d473842281df89ce325ba5c8
 * Entry: 0x549f10; label: FUN_00549f10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00549f10(void)

{
  undefined *puVar1;
  int iVar2;
  float fVar3;
  char cVar4;
  float local_4;
  
  if (DAT_00951288 == 0) {
    local_4 = -0.2;
  }
  else {
    local_4 = -0.3;
  }
  iVar2 = FUN_0054fa60();
  if (iVar2 < 0x8000) {
    local_4 = -local_4;
  }
  iVar2 = FUN_0054fa60();
  puVar1 = PTR_DAT_008021b4;
  cVar4 = ((char)(iVar2 / 0x5556) + (char)(iVar2 >> 0x1f)) -
          (char)((longlong)iVar2 * 0x2fffa001 >> 0x3f);
  fVar3 = ABS(local_4);
  if (fVar3 <= *(float *)(PTR_DAT_008021b4 + 0x1c8)) {
    return;
  }
  *(float *)(PTR_DAT_008021b4 + 0x1cc) = fVar3;
  *(float *)(puVar1 + 0x1c8) = fVar3;
  if (0.0 <= local_4) {
    puVar1[0x228] = 0;
    puVar1[0x229] = cVar4;
    return;
  }
  puVar1[0x228] = 1;
  puVar1[0x229] = cVar4;
  return;
}

