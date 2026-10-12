/* Ghidra pseudocode, not original source.
 * ev_6e12a0fbf5898bf57966e4401ca56b9d94fa9ac9209c3805722876eb5ad577ae
 * Entry: 0x4feaa0; label: FUN_004feaa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004feaa0(char *param_1)

{
  char cVar1;
  char *pcVar2;
  
  _sprintf(&DAT_00920de8," ");
  _vsprintf(&DAT_009205c0,param_1,&stack0x00000008);
  FUN_004f1e80(&DAT_00920de8,&DAT_009205c0);
  FUN_004f1e80(&DAT_00920de8,&DAT_0075ec50);
  if (DAT_0091f1b0 != (code *)0x0) {
    (*DAT_0091f1b0)(&DAT_00920de8);
  }
  FUN_006e0030(&DAT_02976078,&DAT_00758828,&DAT_00920de8);
  pcVar2 = &DAT_00920de8;
  cVar1 = DAT_00920de8;
  for (; (cVar1 != '\0' && (DAT_00921228 < 0x3ff)); DAT_00921228 = DAT_00921228 + 1) {
    (&DAT_009209e8)[DAT_00921228] = *pcVar2;
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
  }
  (&DAT_009209e8)[DAT_00921228] = 0;
  DAT_00921228 = DAT_00921228 + 1;
  return;
}

