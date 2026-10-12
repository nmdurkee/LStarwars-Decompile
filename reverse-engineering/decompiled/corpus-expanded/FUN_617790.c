/* Ghidra pseudocode, not original source.
 * ev_ba7a9618f888afc2863998e575e15f7bc8eb2f6059973cd43d7cc73ea2be055a
 * Entry: 0x617790; label: FUN_00617790
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00617790(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  int *piVar3;
  
  if (in_ECX != in_ECX + 0x580) {
    piVar3 = in_ECX + 0x2b;
    do {
      if (*piVar3 != 0) {
        iVar2 = piVar3[-3];
        if (iVar2 != 0) {
          if (*(uint *)(iVar2 + 0x4b0) < 2) {
            *(undefined4 *)(iVar2 + 0x4b0) = 0;
          }
          else {
            *(uint *)(iVar2 + 0x4b0) = *(uint *)(iVar2 + 0x4b0) - 1;
          }
        }
        *piVar3 = 0;
      }
      piVar1 = piVar3 + 1;
      piVar3 = piVar3 + 0x2c;
    } while (piVar1 != in_ECX + 0x580);
  }
  return;
}

