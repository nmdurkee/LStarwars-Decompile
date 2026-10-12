/* Ghidra pseudocode, not original source.
 * ev_724cabe4f5fc1a17992688438315818e84a5f5e3e3395d254642ecf9571b826a
 * Entry: 0x5a97c0; label: FUN_005a97c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a97c0(void)

{
  float fVar1;
  float fVar2;
  byte bVar3;
  int in_EDX;
  
  fVar1 = *(float *)(in_EDX + 8);
  fVar2 = 1.0 / (float)*(byte *)(in_EDX + 3);
  if ((!NAN(fVar2) && !NAN(fVar1)) && fVar2 < fVar1 != (fVar2 == fVar1)) {
    bVar3 = *(byte *)(in_EDX + 1);
    bVar3 = ((bVar3 & 0xfc) + 4 ^ bVar3) & 0xc ^ bVar3;
    *(byte *)(in_EDX + 1) = bVar3;
    if (0xc < (bVar3 & 0xc)) {
      *(byte *)(in_EDX + 1) = bVar3 & 0xf3;
    }
    *(undefined4 *)(in_EDX + 8) = 0;
  }
  *(float *)(in_EDX + 8) = _DAT_00925018 + *(float *)(in_EDX + 8);
  return;
}

