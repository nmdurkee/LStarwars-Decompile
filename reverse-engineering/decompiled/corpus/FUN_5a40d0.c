/* Ghidra analysis pseudocode, not original source.
 * ev_0b4f3bc8b4a39fc427a7fcc8ed3e1304ee3926d0e45102a57071cb05acfa7baa
 * Entry: 0x5a40d0; label: FUN_005a40d0
 */

void FUN_005a40d0(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  
  if (DAT_0095da40 != (int *)0x0) {
    do {
      piVar3 = DAT_0095da40;
      iVar1 = piVar3[2];
      while (iVar1 != 0) {
        piVar2 = (int *)piVar3[2];
        if ((undefined4 *)piVar2[1] == (undefined4 *)0x0) {
          piVar3[2] = *piVar2;
        }
        else {
          *(undefined4 *)piVar2[1] = *piVar2;
        }
        if (*piVar2 != 0) {
          *(int *)(*piVar2 + 4) = piVar2[1];
        }
        *piVar2 = (int)DAT_0095da38;
        DAT_0095da38 = piVar2;
        iVar1 = piVar3[2];
      }
      if ((int *)piVar3[1] == (int *)0x0) {
        DAT_0095da40 = (int *)*piVar3;
      }
      else {
        *(int *)piVar3[1] = *piVar3;
        DAT_0095da40 = piVar3;
      }
      if (*piVar3 != 0) {
        *(int *)(*piVar3 + 4) = piVar3[1];
      }
      *piVar3 = (int)DAT_0095da3c;
      DAT_0095da3c = piVar3;
    } while (DAT_0095da40 != (int *)0x0);
    DAT_0095da40 = (int *)0x0;
  }
  return;
}

