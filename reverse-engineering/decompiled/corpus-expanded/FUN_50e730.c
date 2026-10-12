/* Ghidra pseudocode, not original source.
 * ev_846633128d4cd55df9225f061f87b742b0c1598eeb1c7e5f9192575f77c77f04
 * Entry: 0x50e730; label: FUN_0050e730
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

