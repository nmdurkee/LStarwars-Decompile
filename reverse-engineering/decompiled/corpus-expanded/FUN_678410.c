/* Ghidra pseudocode, not original source.
 * ev_ea7efa1563e3e8089df6b32d8c4fce6d2180bcae0d447e350c78ef2ad3ca8169
 * Entry: 0x678410; label: FUN_00678410
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00678410(void)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float10 fVar4;
  
  FUN_006783a0();
  iVar3 = DAT_0292186c;
  switch(*(undefined1 *)(DAT_0292186c + 0x88)) {
  case 1:
  case 0x11:
    goto switchD_00678437_caseD_1;
  case 2:
  case 3:
  case 0x12:
  case 0x13:
    break;
  case 4:
  case 0x14:
    _DAT_02921258 = _DAT_02921258 | 4;
    break;
  default:
    return;
  }
  pfVar1 = (float *)(DAT_0292186c + 0xa8);
  FUN_0066f9a0(pfVar1,pfVar1);
  if ((*(byte *)(iVar3 + 0x88) & 0x10) == 0) {
    *pfVar1 = *pfVar1 * *(float *)(iVar3 + 0x58);
    *(float *)(iVar3 + 0xac) = *(float *)(iVar3 + 0x58) * *(float *)(iVar3 + 0xac);
    *(float *)(iVar3 + 0xb0) = *(float *)(iVar3 + 0xb0) * *(float *)(iVar3 + 0x58);
  }
switchD_00678437_caseD_1:
  if (*(float *)(iVar3 + 0x5c) != 1.0) {
    fVar4 = (float10)FUN_005c0240(*(float *)(iVar3 + 0x68) *
                                  *(float *)(iVar3 + 0xac) * *(float *)(iVar3 + 0xac) +
                                  *(float *)(iVar3 + 0xa8) * *(float *)(iVar3 + 0xa8) +
                                  *(float *)(iVar3 + 0xb0) * *(float *)(iVar3 + 0xb0));
    iVar3 = DAT_0292186c;
    if ((float)fVar4 == 0.0) {
      fVar2 = 0.0;
    }
    else {
      fVar2 = 1.0 / (float)fVar4;
    }
    *(float *)(DAT_0292186c + 0xb4) = fVar2 * *(float *)(DAT_0292186c + 0xa8);
    *(float *)(iVar3 + 0xb8) = *(float *)(iVar3 + 0xac) * *(float *)(iVar3 + 100) * fVar2;
    *(float *)(iVar3 + 0xbc) = fVar2 * *(float *)(iVar3 + 0xb0);
    return;
  }
  *(undefined4 *)(iVar3 + 0xb4) = *(undefined4 *)(iVar3 + 0xa8);
  *(undefined4 *)(iVar3 + 0xb8) = *(undefined4 *)(iVar3 + 0xac);
  *(undefined4 *)(iVar3 + 0xbc) = *(undefined4 *)(iVar3 + 0xb0);
  return;
}

