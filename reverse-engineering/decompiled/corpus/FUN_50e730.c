/* Ghidra analysis pseudocode, not original source.
 * ev_6dd3c36930770dc91587d8e9f0315de295532c3384b93e99878ade04445159cc
 * Entry: 0x50e730; label: FUN_0050e730
 */

void FUN_0050e730(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  
  bVar2 = *(byte *)(param_1 + param_2);
  do {
    if (bVar2 == 0x20) {
      cVar1 = *(char *)(param_1 + 1 + param_2);
      if ((((cVar1 != '!') && (cVar1 != '?')) && (cVar1 != ';')) && (cVar1 != ':')) {
        return;
      }
    }
    else if ((bVar2 == 0) || ((bVar2 == 0x5c && (*(char *)(param_1 + 1 + param_2) == 'n')))) {
      return;
    }
    bVar2 = *(byte *)(param_1 + 1 + param_2);
    while ((param_2 = param_2 + 1, 0x7f < bVar2 && (bVar2 < 0xc0))) {
      bVar2 = *(byte *)(param_1 + 1 + param_2);
    }
  } while( true );
}

