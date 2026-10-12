/* Ghidra analysis pseudocode, not original source.
 * ev_55017b0be5ecbbe7992f90db1bd4d4788b50f0daee2843c81c8d7e89602b0f77
 * Entry: 0x46c7d0; label: FUN_0046c7d0
 */

void FUN_0046c7d0(void)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  uint local_4;
  
  FUN_00475850(&local_4);
  iVar3 = DAT_00856c08;
  puVar2 = PTR_DAT_00802c54;
  iVar4 = 0;
  do {
    if (iVar4 == 7) {
      bVar5 = iVar3 != 0;
    }
    else {
      if (iVar3 == 0) {
        bVar5 = true;
        if (iVar4 == 6) {
          if ((*(int *)(puVar2 + 0x120) == -1) ||
             ((&DAT_0086e0fa)[*(int *)(puVar2 + 0x120) * 0xc] == '\0')) goto LAB_0046c84f;
        }
        else if (iVar4 == 4) {
          if (DAT_0093b2a8 == 0) {
LAB_0046c84f:
            if (((local_4 & 0x10) == 0) || ((iVar4 == 5 || (iVar4 == 9)))) goto LAB_0046c862;
          }
        }
        else if (((iVar4 != 9) || (*(int *)(puVar2 + 300) == 0)) ||
                ((*(ushort *)(*(int *)(puVar2 + 300) + 0x7a) & 0x100) == 0)) goto LAB_0046c84f;
      }
      bVar5 = false;
    }
LAB_0046c862:
    iVar1 = iVar4 * 0x38;
    (&DAT_007f8e07)[iVar1] = !bVar5;
    if (iVar4 == 6) {
      bVar5 = iVar3 != 0;
    }
    else if ((((iVar3 != 0) ||
              ((((bVar5 = true, iVar4 == 5 && (*(int *)(puVar2 + 0x120) != -1)) &&
                ((&DAT_0086e0fa)[*(int *)(puVar2 + 0x120) * 0xc] != '\0')) ||
               ((iVar4 == 3 && (DAT_0093b2a8 != 0)))))) ||
             ((iVar4 == 8 &&
              ((*(int *)(puVar2 + 300) != 0 &&
               ((*(ushort *)(*(int *)(puVar2 + 300) + 0x7a) & 0x100) != 0)))))) ||
            (((local_4 & 0x10) != 0 && ((iVar4 != 4 && (iVar4 != 8)))))) {
      bVar5 = false;
    }
    (&DAT_007f8e3f)[iVar1] = !bVar5;
    if (iVar4 == 5) {
      bVar5 = iVar3 != 0;
    }
    else if (((((iVar3 != 0) ||
               (((bVar5 = true, iVar4 == 4 && (*(int *)(puVar2 + 0x120) != -1)) &&
                ((&DAT_0086e0fa)[*(int *)(puVar2 + 0x120) * 0xc] != '\0')))) ||
              ((iVar4 == 2 && (DAT_0093b2a8 != 0)))) ||
             ((iVar4 == 7 &&
              ((*(int *)(puVar2 + 300) != 0 &&
               ((*(ushort *)(*(int *)(puVar2 + 300) + 0x7a) & 0x100) != 0)))))) ||
            (((local_4 & 0x10) != 0 && ((iVar4 != 3 && (iVar4 != 7)))))) {
      bVar5 = false;
    }
    (&DAT_007f8e77)[iVar1] = !bVar5;
    if (iVar4 == 4) {
      bVar5 = iVar3 != 0;
    }
    else if ((((iVar3 != 0) ||
              (((bVar5 = true, iVar4 == 3 && (*(int *)(puVar2 + 0x120) != -1)) &&
               ((&DAT_0086e0fa)[*(int *)(puVar2 + 0x120) * 0xc] != '\0')))) ||
             (((iVar4 == 1 && (DAT_0093b2a8 != 0)) ||
              ((iVar4 == 6 &&
               ((*(int *)(puVar2 + 300) != 0 &&
                ((*(ushort *)(*(int *)(puVar2 + 300) + 0x7a) & 0x100) != 0)))))))) ||
            (((local_4 & 0x10) != 0 && ((iVar4 != 2 && (iVar4 != 6)))))) {
      bVar5 = false;
    }
    (&DAT_007f8eaf)[iVar1] = !bVar5;
    if (iVar4 == 3) {
      bVar5 = iVar3 != 0;
    }
    else if ((((iVar3 != 0) ||
              ((((bVar5 = true, iVar4 == 2 && (*(int *)(puVar2 + 0x120) != -1)) &&
                ((&DAT_0086e0fa)[*(int *)(puVar2 + 0x120) * 0xc] != '\0')) ||
               ((iVar4 == 0 && (DAT_0093b2a8 != 0)))))) ||
             ((iVar4 == 5 &&
              ((*(int *)(puVar2 + 300) != 0 &&
               ((*(ushort *)(*(int *)(puVar2 + 300) + 0x7a) & 0x100) != 0)))))) ||
            (((local_4 & 0x10) != 0 && ((iVar4 != 1 && (iVar4 != 5)))))) {
      bVar5 = false;
    }
    iVar4 = iVar4 + 5;
    (&DAT_007f8ee7)[iVar1] = !bVar5;
    if (9 < iVar4) {
      return;
    }
  } while( true );
}

