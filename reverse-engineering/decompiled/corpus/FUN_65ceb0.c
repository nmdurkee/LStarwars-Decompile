/* Ghidra analysis pseudocode, not original source.
 * ev_72b4c015fc5ea067bd8ff7b23618dfd066d3174eed64a8765571f91528d681aa
 * Entry: 0x65ceb0; label: FUN_0065ceb0
 */

void FUN_0065ceb0(undefined4 param_1)

{
  char *pcVar1;
  char cVar2;
  
  FUN_0065ce60(param_1);
  pcVar1 = &DAT_02947db4;
  do {
    cVar2 = (char)param_1;
    if (*pcVar1 == cVar2) {
      *pcVar1 = -1;
      DAT_02962974 = DAT_02962974 + -1;
    }
    pcVar1 = pcVar1 + 0x44;
  } while ((int)pcVar1 < 0x2948eb4);
  (&DAT_029211c8)[cVar2] = 0;
  *(undefined4 *)(&DAT_0292fc3c + cVar2 * 4) = 0;
  return;
}

