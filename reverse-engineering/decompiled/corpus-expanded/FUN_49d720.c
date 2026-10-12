/* Ghidra pseudocode, not original source.
 * ev_e036c7439cd20116919e592c8e070cde3540a7375a0b02133844a56e359aaeed
 * Entry: 0x49d720; label: FUN_0049d720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049d720(int param_1)

{
  char cVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  
  if (*(char *)(param_1 + 0x7b5) == 'O') {
    if (((((*(char *)(param_1 + 0x281) == '\0') && (*(float *)(param_1 + 0x21c) != 2e+06)) &&
         (*(float *)(param_1 + 0x1e0) < *(float *)(param_1 + 0x17c) - *(float *)(param_1 + 0x21c)))
        && (((*(uint *)(*(int *)(param_1 + 0xca4) + 4) & DAT_0080227c) != 0 &&
            (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x84) != 0)))) &&
       (iVar3 = FUN_005624d0(param_1,_DAT_00802da0), iVar3 != 0)) {
      FUN_0062e650(param_1 + 8,0xffffffff);
      FUN_0062e690(param_1 + 2000,0xffffffff);
      return;
    }
    *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) | 0x1000;
    if ((*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + *(short *)(param_1 + 0x7aa) * 4) == 0)
       || (iVar3 = FUN_0062f150(param_1 + 8,(int)*(short *)(param_1 + 0x7aa),1,0), iVar3 != 0)) {
      *(float *)(param_1 + 0x77c) = *(float *)(param_1 + 0x77c) + _DAT_00925018;
      if (*(char *)(param_1 + 0x281) != '\0') {
        *(undefined1 *)(param_1 + 0x7b5) = 0xff;
        return;
      }
      if ((*(uint *)(*(int *)(param_1 + 0xca4) + 4) & DAT_00802278) == 0) {
        fVar2 = *(float *)(param_1 + 0x784) - _DAT_00925018;
        *(float *)(param_1 + 0x784) = fVar2;
        if (fVar2 <= 0.0) {
          FUN_00561d20(param_1);
          return;
        }
      }
      else if (*(float *)(param_1 + 0x784) < 0.1) {
        *(undefined4 *)(param_1 + 0x784) = 0x3dcccccd;
        return;
      }
    }
  }
  else {
    uVar4 = *(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x94) >> 6 & 1;
    if (((((*(byte *)(*(int *)(param_1 + 0x54) + 4) & 0x40) == 0) &&
         ((uVar4 != 0 ||
          ((*(int *)(param_1 + 0xcbc) != 0 &&
           ((*(byte *)(*(int *)(param_1 + 0xcbc) + 0xc) & 2) != 0)))))) &&
        ((*(uint *)(*(int *)(param_1 + 0xca4) + 8) & DAT_00802278) != 0)) &&
       (((*(char *)(param_1 + 0x281) == '\0' &&
         ((uVar4 != 0 || (iVar3 = FUN_0062f150(param_1 + 8,5,1,0), iVar3 != 0)))) &&
        (((cVar1 = *(char *)(param_1 + 0x7b5), cVar1 == -1 || (cVar1 == '\x11')) ||
         ((cVar1 == '\0' && ((uVar4 != 0 || ((*(uint *)(param_1 + 0x7bc) & 0x8000) != 0)))))))))) {
      FUN_0049d6d0(param_1);
    }
  }
  return;
}

