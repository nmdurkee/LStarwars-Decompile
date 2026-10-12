/* Ghidra pseudocode, not original source.
 * ev_713fd5a551a5a644e53628cf932656c6d009da906ec29e05de784cd201c28f1f
 * Entry: 0x65ceb0; label: FUN_0065ceb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

