/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5a97c0; label: FUN_005a97c0
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

