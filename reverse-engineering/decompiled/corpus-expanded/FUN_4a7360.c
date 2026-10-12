/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a7360; label: FUN_004a7360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a7360(void)

{
  char cVar1;
  short sVar2;
  float fVar3;
  uint uVar4;
  int in_ECX;
  
  uVar4 = *(uint *)(in_ECX + 0x7bc) >> 0xf & 1;
  if (uVar4 != 0) {
    if ((*(char *)(in_ECX + 0x7b8) == '\b') &&
       (*(int *)(*(int *)(*(int *)(in_ECX + 0x50) + 0xc) + 0x2d4) != 0)) {
      *(undefined2 *)(in_ECX + 0x42) = 0xb5;
      return;
    }
    if (*(int *)(*(int *)(*(int *)(in_ECX + 0x50) + 0xc) + 0x14) != 0) {
      *(undefined2 *)(in_ECX + 0x42) = 5;
      return;
    }
  }
  sVar2 = *(short *)(in_ECX + 0x7aa);
  *(short *)(in_ECX + 0x42) = sVar2;
  fVar3 = _DAT_007fc094;
  if (((uVar4 == 0) && (sVar2 != 0x49)) &&
     ((cVar1 = *(char *)(in_ECX + 0x7b8), cVar1 == '\0' ||
      ((((cVar1 == '\x01' || (cVar1 == '\x06')) || (cVar1 == '\a')) || (cVar1 == '\t')))))) {
    if (((*(char *)(in_ECX + 0x39) == '\0') && (*(short *)(in_ECX + 0x3e) == sVar2)) &&
       ((*(byte *)(in_ECX + 0x38) & 1) != 0)) {
      if (_DAT_007fc094 <= 0.0) {
        *(uint *)(in_ECX + 0x7bc) = *(uint *)(in_ECX + 0x7bc) | 0x8000;
      }
      else {
        *(float *)(in_ECX + 0xd2c) = _DAT_00925018 + *(float *)(in_ECX + 0xd2c);
      }
    }
    else {
      *(undefined4 *)(in_ECX + 0xd2c) = 0;
    }
    if (((0.0 < fVar3) && (fVar3 <= *(float *)(in_ECX + 0xd2c))) &&
       ((*(float *)(in_ECX + 0xda0) == 2e+06 || (0.35 < *(float *)(in_ECX + 0xda0))))) {
      *(uint *)(in_ECX + 0x7bc) = *(uint *)(in_ECX + 0x7bc) | 0x8000;
      return;
    }
  }
  return;
}

