/* Ghidra analysis pseudocode, not original source.
 * ev_d881831d71d8ed35fa38d5b5eaee7ca2bcae4cde952964886fd1c7ddf43d442a
 * Entry: 0x4de9d0; label: FUN_004de9d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004de9d0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_1 != 0) {
    iVar1 = 0;
    if (0 < DAT_00888ed2) {
      piVar2 = &DAT_00888be4;
      do {
        if (*piVar2 == param_1) {
          (&DAT_00888be4)[iVar1 * 0x18] = 0;
          iVar1 = (int)DAT_00888ed2;
          if (0 < iVar1) {
            piVar2 = &DAT_00888be4;
            do {
              if (*piVar2 != 0) {
                iVar3 = iVar3 + 1;
              }
              piVar2 = piVar2 + 0x18;
              iVar1 = iVar1 + -1;
            } while (iVar1 != 0);
            if (iVar3 != 0) {
              return;
            }
          }
          DAT_00888ed2 = 0;
          return;
        }
        iVar1 = iVar1 + 1;
        piVar2 = piVar2 + 0x18;
      } while (iVar1 < DAT_00888ed2);
    }
    iVar3 = 0;
    if (0 < DAT_00888ed0) {
      piVar2 = &DAT_00882be4;
      while (*piVar2 != param_1) {
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 0x18;
        if (DAT_00888ed0 <= iVar3) {
          return;
        }
      }
      iVar1 = 0;
      do {
        if (((int)(short)(&DAT_00888f94)[iVar1] == (&DAT_00882be0)[iVar3 * 0x18]) &&
           ((&DAT_00888fa0)[iVar1] == '\0')) {
          (&DAT_00888fa0)[iVar1] = 1;
          _DAT_00888fac = 0;
          break;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < 6);
      (&DAT_00882be4)[iVar3 * 0x18] = 0;
      (&DAT_00882c2c)[iVar3 * 0x18] = (&DAT_00882c2c)[iVar3 * 0x18] & 0xffffffe7 | 1;
      FUN_004de2a0();
    }
  }
  return;
}

