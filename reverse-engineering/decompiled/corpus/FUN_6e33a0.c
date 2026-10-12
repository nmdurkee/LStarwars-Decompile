/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e33a0; label: FUN_006e33a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e33a0(void)

{
  int in_ECX;
  int iVar1;
  
  if (*(int *)(in_ECX + 0x638) == 0) {
    iVar1 = 0;
    do {
      if (iVar1 == 0) {
        if (*(int *)(in_ECX + 0x6c4) == 0) {
          FUN_006e2880(0,*(undefined4 *)(in_ECX + 0x6b0));
          *(undefined4 *)(in_ECX + 0x6e8) = *(undefined4 *)(in_ECX + 0x6b0);
        }
        else {
          FUN_006e2880(0,*(int *)(in_ECX + 0x6c4));
          *(undefined4 *)(in_ECX + 0x6e8) = *(undefined4 *)(in_ECX + 0x6c4);
        }
      }
      else if (((iVar1 < 1) || (2 < iVar1)) ||
              (((DAT_008264b8 == '\0' || (DAT_008264b0 != 2)) &&
               ((DAT_008264c4 == '\0' || (DAT_008264bc != 2)))))) {
        FUN_006e2880(iVar1,0);
      }
      else {
        FUN_006e2880(iVar1,*(undefined4 *)(in_ECX + 0x6c4 + iVar1 * 4));
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 != 4);
    (**(code **)(**(int **)(in_ECX + 4) + 0x9c))
              (*(int **)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x6ec));
  }
  else {
    FUN_006e2880(0,*(undefined4 *)(in_ECX + 0x6b0));
    *(undefined4 *)(in_ECX + 0x6e8) = *(undefined4 *)(in_ECX + 0x6b0);
    (**(code **)(**(int **)(in_ECX + 4) + 0x9c))
              (*(int **)(in_ECX + 4),*(undefined4 *)(in_ECX + 0x6ec));
  }
  DAT_00973900 = *(int *)(in_ECX + 0x138);
  DAT_00973904 = *(int *)(in_ECX + 0x13c);
  _DAT_0080202c = DAT_00973900 / 2;
  _DAT_00802030 = DAT_00973904 / 2;
  FUN_006e2510();
  return;
}

