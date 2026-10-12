/* Ghidra analysis pseudocode, not original source.
 * ev_4a4bd67d6afd5c9569b182b6d27082f0bf05f4f4620e9437cf0e48e464abf09d
 * Entry: 0x512f60; label: FUN_00512f60
 */

void FUN_00512f60(int *param_1)

{
  int *piVar1;
  short *psVar2;
  short sVar3;
  
  sVar3 = 0;
  DAT_00922228 = param_1;
  if (*param_1 != 0) {
    psVar2 = (short *)((int)param_1 + 10);
    do {
      *psVar2 = sVar3;
      *(undefined1 *)((int)psVar2 + -1) = 1;
      sVar3 = sVar3 + 1;
      piVar1 = (int *)(psVar2 + 1);
      psVar2 = psVar2 + 6;
    } while (*piVar1 != 0);
  }
  sVar3 = 0;
  if (PTR_DAT_008019c0 != (undefined *)0x0) {
    psVar2 = &DAT_008019ca;
    do {
      *psVar2 = sVar3;
      *(undefined1 *)((int)psVar2 + -1) = 0;
      sVar3 = sVar3 + 1;
      piVar1 = (int *)(psVar2 + 1);
      psVar2 = psVar2 + 6;
    } while (*piVar1 != 0);
  }
  return;
}

