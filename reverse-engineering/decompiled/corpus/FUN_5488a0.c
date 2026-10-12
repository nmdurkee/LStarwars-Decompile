/* Ghidra analysis pseudocode, not original source.
 * ev_5937183d084659f3cd2a7a2e71fd5c7a233dbdbc790437ca60456b8bfcc76022
 * Entry: 0x5488a0; label: FUN_005488a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005488a0(void)

{
  char cVar1;
  float *pfVar2;
  int iVar3;
  
  pfVar2 = (float *)&DAT_00924afc;
  iVar3 = 0x20;
  do {
    cVar1 = *(char *)((int)pfVar2 + -2);
    if (cVar1 == '\x01') {
LAB_005488c5:
      if (*pfVar2 <= 0.0) {
        *(undefined1 *)((int)pfVar2 + -2) = 2;
      }
      else {
        *pfVar2 = *pfVar2 - _DAT_00925018;
      }
    }
    else if (cVar1 == '\x02') {
      FUN_00681e90((int)*(short *)(pfVar2 + -1),pfVar2[2]);
      *(char *)((int)pfVar2 + -1) = *(char *)((int)pfVar2 + -1) + -1;
      if (*(char *)((int)pfVar2 + -1) < '\x01') {
        pfVar2[-1] = 0.0;
        *pfVar2 = 0.0;
        pfVar2[1] = 0.0;
        pfVar2[2] = 0.0;
        *(undefined1 *)((int)pfVar2 + -2) = 0;
      }
      else {
        *(undefined1 *)((int)pfVar2 + -2) = 3;
        *pfVar2 = pfVar2[1];
      }
    }
    else if (cVar1 == '\x03') goto LAB_005488c5;
    pfVar2 = pfVar2 + 4;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      return;
    }
  } while( true );
}

